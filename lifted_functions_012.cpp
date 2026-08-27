#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static int sfera_cp1251_is_russian_vowel_or_sign(uint8_t value) { switch (value) { case UINT8_C(0xF3): case UINT8_C(0xE5): case UINT8_C(0xFB): case UINT8_C(0xE0): case UINT8_C(0xEE): case UINT8_C(0xFD): case UINT8_C(0xFF): case UINT8_C(0xE8): case UINT8_C(0xFE): case UINT8_C(0xFC): case UINT8_C(0xFA): return 1; default: return 0; } }
static int sfera_identifier_char_is_keyboard_ambiguous(uint8_t value) { switch (value) { case UINT8_C(0xE5): case 'e': case UINT8_C(0xF3): case 'y': case UINT8_C(0xEA): case 'k': case UINT8_C(0xE3): case 'r': case UINT8_C(0xE7): case '3': case UINT8_C(0xF5): case 'x': case UINT8_C(0xE8): case 'u': case UINT8_C(0xEE): case '0': case 'o': case UINT8_C(0xF0): case 'p': case UINT8_C(0xF1): case 'c': case UINT8_C(0xE0): case 'a': case UINT8_C(0xF2): case 'm': case 'E': case UINT8_C(0xC5): case UINT8_C(0xD3): case 'Y': case 'K': case UINT8_C(0xCA): case UINT8_C(0xC7): case 'X': case UINT8_C(0xD5): case 'O': case UINT8_C(0xCE): case UINT8_C(0xD0): case 'P': case 'C': case UINT8_C(0xD1): case 'A': case UINT8_C(0xC0): return 1; default: return 0; } }
static void sfera_apply_character_alias_group(uint32_t* table, const char* group) { const uint32_t canonical = (uint8_t)group[0]; for (uint32_t alias_index = 1u; group[alias_index] != 0; ++alias_index) { const uint32_t alias = (uint8_t)group[alias_index]; for (uint32_t index = 0u; index < kMaterialFilterCharCount; ++index) { if (table[index] == alias) { table[index] = canonical; } } } }
static float sfera_grass_jitter_x(uint32_t index) { switch (index) { case 0u: return 6.24f; case 1u: return 2.21f; case 2u: return 2.21f; default: return 6.24f; } }
static float sfera_grass_jitter_y(uint32_t index) { switch (index) { case 0u: return 3.73f; case 1u: return 1.17f; case 2u: return 5.60f; default: return 7.15f; } }
__declspec(noinline) void sfera_sub_00477FB0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26;
 bool sub_pred[3]; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4;
    bool lift_cmp[1];
    cpu->esp -= 0x4E4u;
    sub_pred[0] = (uint32_t)(g_sfera_recovered_static_runtime.scene_state_09) == 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_shadow_runtime.manager;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    if (sub_pred[0]) goto label_00077FF3;
    if (cpu->esi == g_sfera_world_objects.controlled_object_handle) goto label_00077FF3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477FEEu)); sfera_sub_00460D50(cpu, LIFT_CODE_TOKEN_VA(0x477FEEu));
    g_sfera_recovered_static_runtime.scene_state_09 = cpu->eax;
label_00077FF3:
    if ((int32_t)cpu->esi >= 0) goto label_00078001;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78001u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x78001u));
label_00078001:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00078015;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78015u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x78015u));
label_00078015:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_000781EE;
label_00078025:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478038u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x478038u));
    g_sfera_world_render_runtime.active_model = cpu->eax;
    sub_pred[1] = *(uint8_t*)(cpu->esi + 0x141u) == 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if (sub_pred[1]) goto label_00079092;
    cpu->ebp = cpu->esi;
    cpu->edx = cpu->ebp + 0x14u;
    cpu->ebp += 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_character_frame_matrix.m[0][0]);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478066u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x478066u));
    x87_p0 = 0.0;
    std::memmove((void*)((uintptr_t)&g_sfera_character_rotation_matrix.m[0][0]),(void*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][0]),64u);
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[2][3]) = x87_p0;
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[1][3]) = x87_p0;
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[0][3]) = x87_p0; 
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = cpu->esp + 0x90u;
    cpu->edi += 0xE8u;
    *(uint32_t*)(cpu->esp + 0x14u) = 8u;
label_000780A4:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4780C0u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x4780C0u));
    cpu->edi += 0xCu;
    cpu->esi += 0xCu;
    if ((--*(uint32_t*)(cpu->esp + 0x14u)) != 0u) goto label_000780A4;
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0x94u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4780DFu)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x4780DFu));
    g_sfera_client_main_scalar_runtime.mode_01 = cpu->eax;
    if (cpu->eax == 0u) goto label_00079092;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4780F7u)); sfera_sub_0045F060(cpu, LIFT_CODE_TOKEN_VA(0x4780F7u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.lighting_enabled) = 0u;
    *(float*)(cpu->esp + 0x78u) = ((((double)*(float*)(cpu->ebp))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    *(float*)(cpu->esp + 0x7Cu) = ((((double)*(float*)(cpu->ebp + 4u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    *(float*)(cpu->esp + 0x80u) = ((((double)*(float*)(cpu->ebp + 8u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
    x87_p0 = (double)*(float*)(cpu->esp + 0x7Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x78u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x80u);
    x87_p3 = (double)*(float*)(cpu->esi + 0x194u);
    *(double*)(cpu->esp + 0x48u) = x87_p3;
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = (*(double*)(cpu->esp + 0x48u)) / (x87_p0);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x1A8u)));
     value_0 = x87_p0; if (!((value_0)<(0.20000000298023224))) goto label_00078188;
    (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.lighting_enabled) = 1u;
label_00078188:
    x87_p0 = 1.0;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->eax = g_sfera_view_spatial_runtime.basis[3].z.u32;
    *(float*)(cpu->esp + 0x18u) = x87_p0;
    x87_p1 = (double)*(float*)(cpu->esi + 0x34u);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    x87_p2 = (double)-1.0f;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_cmp[0]=x87_p2!=x87_p1;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    cpu->eax = g_sfera_view_spatial_runtime.position_offset.z.u32;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    cpu->ecx = g_sfera_view_spatial_runtime.position_offset.x.u32;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.position_offset.y.u32;
    x87_p1 = (double)0.009999999776482582f;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
     value_1 = x87_p1; value_2 = x87_p0; if (lift_cmp[0]) goto label_00078240;
    *(float*)(cpu->esi + 0x34u) = value_2;
    goto label_0007829C;
label_000781EE:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00078025;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47820Au)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47820Au));
    if (cpu->eax != 0u) goto label_00078213;
    cpu->eax = (uintptr_t)"<none>";
label_00078213:
    lift_push32(cpu, 0x273Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xFCu;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47822Bu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xF0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78240u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x78240u));
label_00078240:
    *(float*)(cpu->esp + 0x14u) = (double)0.0007999999797903001f;
    if (!((value_1)>(((double)*(float*)(cpu->esi + 0x34u))))) goto label_0007825E;
    *(float*)(cpu->esp + 0x14u) = (double)7.999999797903001e-05f;
label_0007825E:
    *(float*)(cpu->esp + 0x10u) = ((((double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.lighting_state)))))) * (((double)*(float*)(cpu->esp + 0x14u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
     value_3 = x87_p0; if (!((value_3)<(value_2))) goto label_0007828A;
    x87_p0 = (double)*(float*)(cpu->esi + 0x34u);
    x87_p1 = 1.0;
    x87_p0 = x87_p1 - x87_p0; 
    value_4 = value_3 * x87_p0; 
    value_5 = (value_4) + (((double)*(float*)(cpu->esi + 0x34u)));
    *(float*)(cpu->esi + 0x34u) = value_5; 
     goto label_00078293;
label_0007828A:
    *(float*)(cpu->esi + 0x34u) = value_2;
label_00078293:
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->esi + 0x34u);
label_0007829C:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x);
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x) = x87_p1; 
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y);
    x87_p1 = (x87_p1) * (x87_p0);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y) = x87_p1; 
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z);
    x87_p1 = (x87_p1) * (x87_p0);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z) = x87_p1; 
     value_6 = x87_p0; if (!((value_6)<(value_1))) goto label_00078361;
    *(float*)(cpu->esp + 0x78u) = value_2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    value_7 = 0.0;
    g_sfera_view_spatial_runtime.position_offset.x.u32 = cpu->ecx;
    *(float*)(cpu->esp + 0x7Cu) = value_7;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(float*)(cpu->esp + 0x84u) = value_7; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x84u);
    g_sfera_view_spatial_runtime.position_offset.y.u32 = cpu->edx;
    g_sfera_view_spatial_runtime.position_offset.z.u32 = cpu->eax;
    value_8 = (double)*(float*)(cpu->esi + 0x14u);
    value_9 = (value_8) + (1.1693706972350526);
    cpu->edx = (uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z;
    cpu->ecx = (uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x;
    *(float*)(cpu->esp + 0x14u) = value_9; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478335u)); sfera_sub_0044E140(cpu, LIFT_CODE_TOKEN_VA(0x478335u));
    *(float*)(cpu->esp + 0x10u) = ((45.0) - ((((((double)*(float*)(cpu->esp + 0x18u))) * (4500.0)))));
    value_10 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x) = value_10;
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y) = value_10;
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z) = value_10; 
     goto label_00078363;
label_00078361:
label_00078363:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    x87_p0 = -x87_p0;
    *(float*)(cpu->esp + 0x78u) = x87_p0; 
    cpu->esp -= 0xCu;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_p0 = -x87_p0;
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    *(float*)(cpu->esp + 0x88u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    x87_p0 = -x87_p0;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(float*)(cpu->esp + 0x8Cu) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x88u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x98u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4783D3u)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x4783D3u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4783DAu)); sfera_sub_00468750(cpu, LIFT_CODE_TOKEN_VA(0x4783DAu));
    if (cpu->edi == g_sfera_world_objects.controlled_object_handle) goto label_00078611;
    if (*(uint8_t*)(cpu->ebx + 0xA0u) >= 4u) goto label_00078611;
    { const double lift_right=(double)*(float*)(cpu->esi + 0x148u); const double lift_left=1.0; if (lift_left!=lift_right) goto label_00078611; }
    x87_p0 = (double)50.0f;
    cpu->eax = 0u;
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_03 <= (int32_t)cpu->eax) goto label_000785D9;
    cpu->edi = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][4];
label_00078430:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if (*(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) == 0u) goto label_00078501;
    { const double lift_right=(double)*(float*)(cpu->edi); const double lift_left=(double)*(float*)(cpu->esi + 0xCu); if (lift_left<lift_right) goto label_00078501; }
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->edi + 0xFFFFFFFCu))) - (((double)*(float*)(cpu->ebp))));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->edi))) - (((double)*(float*)(cpu->ebp + 4u))));
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->edi + 4u))) - (((double)*(float*)(cpu->ebp + 8u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x24u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u); x87_p1 = x87_p0;
    x87_p2 = 0.0;
     value_11 = x87_p2; value_12 = x87_p1; value_13 = x87_p0; if ((value_11)==(value_12)) goto label_000784FF;
    if (!((value_13)<(15.0))) goto label_000784FF;
    if (!(((double)*(float*)(cpu->esp + 0x1Cu))>(value_13))) goto label_000784FF;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x1Cu) = value_13; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = cpu->edi + 0xFFFFFFFCu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->eax;
     goto label_00078501;
label_000784FF:
label_00078501:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->eax;
    cpu->edi += 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00078430;
    if (*(uint32_t*)(cpu->esp + 0x14u) == 0u) goto label_000785D9;
    sub_pred[2] = (uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) == 0u;
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p1 = x87_p0;
    x87_p2 = 1.0;
    x87_p1 = x87_p2 / x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x84u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x10u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x84u) = x87_p2; 
    x87_p2 = x87_p1;
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->esp + 0x88u)));
    *(float*)(cpu->esp + 0x88u) = x87_p2; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esp + 0x8Cu)));
    *(float*)(cpu->esp + 0x8Cu) = x87_p1; 
    x87_p0 = (x87_p0) / (15.0);
    x87_p0 = (x87_p0) + (0.20000000298023224);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    if (!sub_pred[2]) goto label_000785C2;
    x87_p0 = (double)0.25f;
    x87_p1 = (double)g_sfera_graphics_runtime.environment_factor;
     value_14 = x87_p1; value_15 = x87_p0; if (!((value_14)>=(value_15))) goto label_000785C0;
    if (!((value_14)<=(0.8299999833106995))) goto label_000785C2;
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = (double)g_sfera_graphics_runtime.view_scale;
     value_16 = x87_p1; value_17 = x87_p0; if (!((value_16)>(value_17))) goto label_000785C0;
    *(float*)(cpu->esp + 0x1Cu) = value_16; 
     goto label_000785C2;
label_000785C0:
label_000785C2:
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x88u;
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x785D9u)); sfera_sub_0048C860(cpu, LIFT_CODE_TOKEN_RVA(0x785D9u));
label_000785D9:
    if (g_sfera_view_spatial_runtime.alternate_projection == 0u) goto label_00078611;
    if (*(uint32_t*)(cpu->esp + 0x14u) != 0u) goto label_00078611;
    x87_p0 = 0.0;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x7Cu) = x87_p0;
    cpu->edx = cpu->esp + 0x7Cu;
    x87_p1 = 1.0;
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp + 0x80u) = x87_p1;
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x84u) = x87_p1; 
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78611u)); sfera_sub_0048C860(cpu, LIFT_CODE_TOKEN_RVA(0x78611u));
label_00078611:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x40u);
    cpu->ecx = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478623u)); sfera_sub_00454FF0(cpu, LIFT_CODE_TOKEN_VA(0x478623u));
    cpu->eax = g_sfera_scene_vector_runtime.transform_scratch.x.u32;
    *(uint32_t*)(cpu->esi + 0x190u) = cpu->eax;
    cpu->ecx = g_sfera_scene_vector_runtime.transform_scratch.y.u32;
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->ecx;
    cpu->edx = g_sfera_scene_vector_runtime.transform_scratch.z.u32;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->edx;
    cpu->eax = g_sfera_scene_vector_runtime.frame_101_position.x.u32;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    cpu->ecx = g_sfera_scene_vector_runtime.frame_101_position.y.u32;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ecx;
    cpu->edx = g_sfera_scene_vector_runtime.frame_101_position.z.u32;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->edx;
    if (cpu->eax == g_sfera_world_objects.controlled_object_handle) goto label_00078829;
    if (*(uint8_t*)(cpu->ebx + 0xA0u) >= 4u) goto label_00078829;
    { const double lift_right=(double)*(float*)(cpu->esi + 0x148u); const double lift_left=1.0; if (lift_left!=lift_right) goto label_00078829; }
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (((uint32_t)(g_sfera_world_objects.object_handles.capacity) != 1u) && ((int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) >= (int32_t)(1u))) goto label_000786BB;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x786BBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x786BBu));
label_000786BB:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(float*)(cpu->esp + 0x78u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->ebp))));
    *(float*)(cpu->esp + 0x7Cu) = ((((double)*(float*)(cpu->eax + 0xCu))) - (((double)*(float*)(cpu->ebp + 4u))));
    *(float*)(cpu->esp + 0x80u) = ((((double)*(float*)(cpu->eax + 0x10u))) - (((double)*(float*)(cpu->ebp + 8u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x7Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x78u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x80u);
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x18u) = (double)(1.0);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p1 = 15.0;
     value_18 = x87_p1; value_19 = x87_p0; if (!((value_18)<(value_19))) goto label_00078769;
    value_20 = value_19 - value_18; 
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    *(float*)(cpu->esp + 0x10u) = value_20; 
    value_21 = (double)*(float*)(cpu->esp + 0x10u);
    value_22 = (value_21) / (30.0);
    value_23 = 1.0;
    value_24 = value_23 - value_22; 
    *(float*)(cpu->esp + 0x18u) = value_24; 
    value_25 = 0.0;
     if (!((value_25)>(((double)*(float*)(cpu->esp + 0x18u))))) goto label_0007876B;
    *(float*)(cpu->esp + 0x18u) = value_25; 
     goto label_0007876D;
label_00078769:
label_0007876B:
label_0007876D:
    x87_p0 = (double)*(float*)(cpu->edi + 0x1B4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478780u)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x478780u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xB0u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xACu);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB4u);
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->eax;
    x87_p0 = (double)*(float*)(cpu->esp + 0x7Cu);
    x87_p0 = fabs(x87_p0);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->edx;
    *(float*)(cpu->esp + 0x48u) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ecx;
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x48u);
    x87_p0 = (double)*(float*)((uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp");
     value_26 = x87_p0; if (!((value_26)>(((double)*(float*)(cpu->esp + 0x14u))))) goto label_000787CA;
    *(float*)(cpu->esp + 0x14u) = value_26; 
     goto label_000787CC;
label_000787CA:
label_000787CC:
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::acos(x87_p0);
    *(float*)(cpu->esp + 0x48u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x48u);
    x87_p0 = std::tan(x87_p0);
    *(float*)(cpu->esp + 0x48u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p1 = (double)*(float*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->edx);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->esi + 0x80u)));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    x87_p0 = x87_p0 * x87_p1; 
    *(float*)(cpu->esp + 0x50u) = x87_p0; 
    *(float*)(cpu->edi + 0x1B4u) = ((1.4900000095367432) / ((((((double)*(float*)(cpu->edi + 0x1B4u))) + (((double)*(float*)(cpu->esp + 0x50u)))))));
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78829u)); sfera_sub_0048CA90(cpu, LIFT_CODE_TOKEN_RVA(0x78829u));
label_00078829:
    { const double lift_right=(double)*(float*)(cpu->esi + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_00078858; }
    x87_p0 = (double)*(float*)(cpu->esi + 0x148u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478849u)); sfera_sub_00450AB0(cpu, LIFT_CODE_TOKEN_VA(0x478849u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78858u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_RVA(0x78858u));
label_00078858:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1E0u);
    cpu->eax = cpu->edi + 0x1D4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47886Cu)); sfera_sub_0044EF20(cpu, LIFT_CODE_TOKEN_VA(0x47886Cu));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x30u) <= (int32_t)cpu->eax) goto label_00078C2E;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
label_00078883:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x34u);
    cpu->esi += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint8_t*)(cpu->esi);
    cpu->edi&=0x7Fu;
    if (((cpu->edi)&0x80000000u)==0u) goto label_000788A0;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x788A0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x788A0u));
label_000788A0:
    if ((int32_t)(cpu->edi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.model_matrices.capacity))) goto label_000788B4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x788B4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x788B4u));
label_000788B4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    cpu->edi <<= 6u;
    cpu->edi += g_sfera_scene_array_runtime.model_matrices.data;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) >> 7u));
    cpu->eax = cpu->edi;
    if ((cpu->edx & 0xFFu) != *(uint8_t*)(void*)&g_sfera_main_command_state_runtime.lighting_enabled) goto label_00078C0F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x3Cu);
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->ecx &= 0x7Fu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xACu);
    cpu->ecx = *(uint8_t*)(cpu->ecx + cpu->edx + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    if (cpu->edx != g_sfera_world_objects.controlled_object_handle) goto label_00078908;
    if (cpu->ecx == 0x66u) goto label_00078C0F;
    if (cpu->ecx == 0x67u) goto label_00078C0F;
label_00078908:
    x87_p0 = (double)*(float*)(cpu->eax);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x90u) = x87_p0; 
    *(float*)(cpu->esp + 0x94u) = (double)*(float*)(cpu->eax + 0x10u);
    *(float*)(cpu->esp + 0x98u) = (double)*(float*)(cpu->eax + 0x20u);
    *(float*)(cpu->esp + 0x9Cu) = (double)*(float*)(cpu->eax + 0x30u);
    *(float*)(cpu->esp + 0xA0u) = (double)*(float*)(cpu->eax + 4u);
    *(float*)(cpu->esp + 0xA4u) = (double)*(float*)(cpu->eax + 0x14u);
    *(float*)(cpu->esp + 0xA8u) = (double)*(float*)(cpu->eax + 0x24u);
    *(float*)(cpu->esp + 0xACu) = (double)*(float*)(cpu->eax + 0x34u);
    *(float*)(cpu->esp + 0xB0u) = (double)*(float*)(cpu->eax + 8u);
    *(float*)(cpu->esp + 0xB4u) = (double)*(float*)(cpu->eax + 0x18u);
    *(float*)(cpu->esp + 0xB8u) = (double)*(float*)(cpu->eax + 0x28u);
    *(float*)(cpu->esp + 0xBCu) = (double)*(float*)(cpu->eax + 0x38u);
    *(float*)(cpu->esp + 0xC0u) = (double)*(float*)(cpu->eax + 0xCu);
    *(float*)(cpu->esp + 0xC4u) = (double)*(float*)(cpu->eax + 0x1Cu);
    *(float*)(cpu->esp + 0xC8u) = (double)*(float*)(cpu->eax + 0x2Cu);
    x87_p0 = (double)*(float*)(cpu->eax + 0x3Cu);
    cpu->eax = cpu->esp + 0x90u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0xD0u) = x87_p0; 
    lift_push32(cpu, 0x100u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4789BFu)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x4789BFu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4789D4u)); sfera_sub_0048D170(cpu, LIFT_CODE_TOKEN_VA(0x4789D4u));
    cpu->edi = *(uint16_t*)(cpu->esi + 2u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x88u);
    cpu->edi += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    x87_p0 = (double)*(float*)(cpu->edi + 0x68u);
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.basis[2].x.f32));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    x87_p0 = (double)*(float*)(cpu->edi + 0x6Cu);
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.basis[2].y.f32));
    cpu->ebp = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    x87_p0 = (double)*(float*)(cpu->edi + 0x70u);
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.basis[2].z.f32));
    cpu->ebx = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    if ((int32_t)cpu->ebp <= (int32_t)0xFFu) goto label_00078A1F;
    cpu->ebp = 0xFFu;
label_00078A1F:
    if ((int32_t)cpu->ebx <= (int32_t)0xFFu) goto label_00078A2C;
    cpu->ebx = 0xFFu;
label_00078A2C:
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_00078A38;
    cpu->eax = 0xFFu;
label_00078A38:
    cpu->ebp|=0xFFFFFF00u;
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp|=cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->edx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x8Bu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478A5Fu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x478A5Fu));
    cpu->eax = *(uint16_t*)(cpu->esi + 2u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    cpu->ecx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edx + 0x144u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = cpu->eax + (cpu->ecx * 2u);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x18u) == cpu->edi) goto label_00078AA7;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478A8Eu)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x478A8Eu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478A9Cu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x478A9Cu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478AA3u)); sfera_sub_0049A4B0(cpu, LIFT_CODE_TOKEN_VA(0x478AA3u));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
label_00078AA7:
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478AB0u)); sfera_sub_0044EFE0(cpu, LIFT_CODE_TOKEN_VA(0x478AB0u));
    cpu->ecx = *(uint16_t*)(cpu->esi + 8u);
    cpu->edx = g_sfera_world_render_runtime.active_model;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x24u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 8u);
    cpu->ecx = cpu->edx + (cpu->ecx * 4u);
    cpu->edi = 0u;
    cpu->edx = 0u;
    if ((cpu->edi & 0xFFFFu) >= *(uint16_t*)(cpu->esi + 0xAu)) goto label_00078B0E;
    cpu->eax += 0x1Cu;
label_00078AD0:
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0xFFFFFFE4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFE8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFECu) = cpu->edi;
    *(float*)(cpu->eax + 0xFFFFFFFCu) = (double)*(float*)(cpu->ecx + 0x18u);
    ++cpu->edx;
    x87_p0 = (double)*(float*)(cpu->ecx + 0x1Cu);
    cpu->eax += 0x20u;
    *(float*)(cpu->eax + 0xFFFFFFE0u) = x87_p0; 
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->eax + 0xFFFFFFD0u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFD4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x14u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFD8u) = cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->ecx += 0x24u;
    if ((int32_t)cpu->edx < (int32_t)cpu->edi) goto label_00078AD0;
label_00078B0E:
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478B22u)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x478B22u));
    cpu->ebx = *(uint16_t*)(cpu->esi + 6u);
    cpu->edi = cpu->ebx + (cpu->ebx * 2u);
    if ((int32_t)cpu->edi > (int32_t)0xBB8u) goto label_000790AB;
    cpu->eax = *(uint16_t*)(cpu->esi + 4u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->ecx = cpu->ecx + (cpu->edx * 4u);
    cpu->edx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_collision_scratch_runtime.dynamic_indices_aux[0];
    if ((int32_t)cpu->ebx <= 0) goto label_00078B76;
label_00078B51:
    cpu->ebx = *(uint16_t*)(cpu->ecx);
    *(uint16_t*)(cpu->eax) = cpu->ebx & 0xFFFFu;
    cpu->ebx = *(uint16_t*)(cpu->ecx + 2u);
    *(uint16_t*)(cpu->eax + 2u) = cpu->ebx & 0xFFFFu;
    cpu->ebx = *(uint16_t*)(cpu->ecx + 4u);
    *(uint16_t*)(cpu->eax + 4u) = cpu->ebx & 0xFFFFu;
    cpu->ebx = *(uint16_t*)(cpu->esi + 6u);
    ++cpu->edx;
    cpu->eax += 6u;
    cpu->ecx += 0xCu;
    if ((int32_t)cpu->edx < (int32_t)cpu->ebx) goto label_00078B51;
label_00078B76:
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_client_main_scalar_runtime.mode_01) == 2u);
    cpu->ebp = cpu->edx;
    if ((uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u) goto label_00078B8F;
    cpu->ebp = 0u;
label_00078B8F:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478B96u)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x478B96u));
    cpu->ecx = cpu->edi + cpu->edi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_collision_scratch_runtime.dynamic_indices_aux[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x478BA0u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478BBDu)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x478BBDu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ebp |= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478BF7u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x478BF7u));
    g_sfera_client_config_runtime.state_08 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->edx = *(uint16_t*)(cpu->esi + 0xAu);
    g_sfera_main_input_state_runtime.timing_accumulator = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x50u);
label_00078C0F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x12u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx + 0x30u)) goto label_00078883;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
label_00078C2E:
    lift_push32(cpu, 0x44u);
    cpu->edx = cpu->esp + 0x94u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x478C3Au));
    x87_p0 = 1.0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x9Cu) = x87_p0;
    *(float*)(cpu->esp + 0xA0u) = x87_p0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0x98u) = x87_p0;
    cpu->eax = cpu->esp + 0x90u;
    *(float*)(cpu->esp + 0x9Cu) = x87_p0;
    lift_push32(cpu, cpu->eax);
    x87_p1 = 0.0;
    *(float*)(cpu->esp + 0xB4u) = x87_p1;
    *(float*)(cpu->esp + 0xB8u) = x87_p1;
    *(float*)(cpu->esp + 0xBCu) = x87_p1;
    *(float*)(cpu->esp + 0xD4u) = x87_p1; 
    *(float*)(cpu->esp + 0xC0u) = x87_p0;
    *(float*)(cpu->esp + 0xA4u) = x87_p0;
    *(float*)(cpu->esp + 0xA8u) = x87_p0;
    *(float*)(cpu->esp + 0xACu) = x87_p0;
    *(float*)(cpu->esp + 0xB0u) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478CB4u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x478CB4u));
    { const double lift_right=(double)*(float*)(cpu->esi + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_00078D4C; }
    lift_push32(cpu, 0x44u);
    cpu->ecx = cpu->esp + 0x94u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x478CD5u));
    x87_p0 = 1.0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x9Cu) = x87_p0;
    *(float*)(cpu->esp + 0xA0u) = x87_p0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0x98u) = x87_p0;
    cpu->edx = cpu->esp + 0x90u;
    *(float*)(cpu->esp + 0x9Cu) = x87_p0;
    lift_push32(cpu, cpu->edx);
    x87_p1 = 0.0;
    *(float*)(cpu->esp + 0xB4u) = x87_p1;
    *(float*)(cpu->esp + 0xB8u) = x87_p1;
    *(float*)(cpu->esp + 0xBCu) = x87_p1;
    *(float*)(cpu->esp + 0xD4u) = x87_p1; 
    *(float*)(cpu->esp + 0xA4u) = x87_p0;
    *(float*)(cpu->esp + 0xA8u) = x87_p0;
    *(float*)(cpu->esp + 0xACu) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478D41u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x478D41u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78D4Cu)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_RVA(0x78D4Cu));
label_00078D4C:
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03) = 1u;
    cpu->edi = cpu->esi + 0xF8u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 5u;
label_00078D64:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if (cpu->ecx == 0u) goto label_00078D6F;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x78D6Fu)); sfera_sub_00477020(cpu, LIFT_CODE_TOKEN_RVA(0x78D6Fu));
label_00078D6F:
    cpu->edi += 4u;
    if ((--*(uint32_t*)(cpu->esp + 0x3Cu)) != 0u) goto label_00078D64;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    g_sfera_view_spatial_runtime.basis[3].x.u32 = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    g_sfera_view_spatial_runtime.position_offset.x.u32 = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    g_sfera_view_spatial_runtime.basis[3].y.u32 = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    g_sfera_view_spatial_runtime.basis[3].z.u32 = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03) = 0u;
    g_sfera_view_spatial_runtime.position_offset.y.u32 = cpu->ecx;
    g_sfera_view_spatial_runtime.position_offset.z.u32 = cpu->edx;
    if (cpu->eax == g_sfera_world_objects.controlled_object_handle) goto label_00078FEF;
    if (*(uint8_t*)(cpu->ebx + 0xA0u) >= 4u) goto label_00078FEF;
    { const double lift_right=(double)*(float*)(cpu->esi + 0x148u); const double lift_left=1.0; if (lift_left!=lift_right) goto label_00078FEF; }
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xB8u);
    x87_p0 = (double)*(float*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB4u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xBCu);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xACu);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0xB0u);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->edx;
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 0x78u)));
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xC0u);
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_p0 = (double)*(float*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ecx;
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 0x80u)));
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->eax;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x38u) = x87_p0; 
    *(uint32_t*)(cpu->eax) = cpu->edx;
    x87_p0 = 0.0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478E6Bu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x478E6Bu));
    x87_p0 = (double)*(float*)(cpu->esp + 0x48u); x87_p1 = x87_p0;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esp + 0x24u)));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(float*)(cpu->esp + 0x30u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p1 = (x87_p1) * (x87_p0);
    *(float*)(cpu->esp + 0x34u) = x87_p1; 
    x87_p1 = x87_p0;
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x38u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x30u);
    x87_p2 = 0.5;
    x87_p1 = (x87_p1) * (x87_p2);
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x54u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p2 = (x87_p2) * (x87_p1);
    *(float*)(cpu->esp + 0x58u) = x87_p2; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x5Cu) = x87_p1; 
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->ebp))) + (((double)*(float*)(cpu->esp + 0x54u))));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x58u))) + (((double)*(float*)(cpu->ebp + 4u))));
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esp + 0x5Cu))) + (((double)*(float*)(cpu->ebp + 8u))));
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x10u)));
    x87_p0 = (x87_p0) * (0.800000011920929);
    *(float*)(cpu->esp + 0x50u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x24u); x87_p1 = x87_p0;
    x87_p2 = (double)*(float*)(cpu->esp + 0x50u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x30u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x28u); x87_p3 = x87_p2;
    x87_p3 = (x87_p3) - (x87_p1);
    *(float*)(cpu->esp + 0x34u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p4 = x87_p3;
    x87_p4 = (x87_p4) - (x87_p1);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 0x38u) = x87_p4; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    x87_p4 = x87_p1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    x87_p0 = x87_p0 + x87_p4; 
    std::swap(x87_p3, x87_p0);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    *(float*)(cpu->esp + 0x30u) = x87_p3; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    x87_p2 = (x87_p2) + (x87_p1);
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edx;
    *(float*)(cpu->esp + 0x40u) = x87_p2; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    x87_p2 = x87_p1;
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x44u) = x87_p1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->eax;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x88u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x98u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478FC6u)); sfera_sub_0046F280(cpu, LIFT_CODE_TOKEN_VA(0x478FC6u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478FDAu)); sfera_sub_0048D580(cpu, LIFT_CODE_TOKEN_VA(0x478FDAu));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x478FE1u)); sfera_sub_0048DA20(cpu, LIFT_CODE_TOKEN_VA(0x478FE1u));
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->ecx + 0x1B4u) = x87_p0; 
label_00078FEF:
    cpu->edi = 0u;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_03 <= (int32_t)cpu->edi) goto label_00079092;
label_00079000:
    if (*(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) != 1u) goto label_00079085;
    cpu->esi = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    if ((int32_t)cpu->esi >= 0) goto label_00079023;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79023u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79023u));
label_00079023:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00079037;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79037u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79037u));
label_00079037:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->edx + (cpu->esi * 4u)) == 0u) goto label_00079085;
    g_sfera_main_command_state_runtime.light_update_counter = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u;
    if ((int32_t)cpu->esi >= 0) goto label_00079057;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79057u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79057u));
label_00079057:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_0007906B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7906Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7906Bu));
label_0007906B:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = 0u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79085u)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x79085u));
label_00079085:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00079000;
label_00079092:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4E4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_000790AB:
    cpu->ecx = (uintptr_t)"MNO_INDICES_IN_PRIMITIVE exceed";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4790B5u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4790B5u));
    lift_trap(cpu, 0x4790B5u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004790C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x4B4u;
    cpu->eax = 1u;
    g_sfera_grass_map_runtime.alternating_update_phase ^= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    g_sfera_recovered_static_runtime.input_state_b = cpu->eax;
    cpu->eax = g_sfera_world_objects.extended_object_count;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    if ((int32_t)cpu->eax <= (int32_t)cpu->esi) goto label_000794CB;
    label_00079108:
    if ((int32_t)cpu->esi >= 0) goto label_00079116;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79116u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79116u));
    label_00079116:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_0007912A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7912Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7912Au));
    label_0007912A:
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_0007913C;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    goto label_00079108;
    label_0007913C:
    if ((int32_t)cpu->esi >= 0) goto label_0007914A;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7914Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7914Au));
    label_0007914A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_0007915E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7915Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7915Eu));
    label_0007915E:
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    if ((int32_t)cpu->ebx >= 0) goto label_00079179;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79179u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79179u));
    label_00079179:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007918D;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7918Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7918Du));
    label_0007918D:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->ebx * 4u));
    if (cpu->edi == 0u) goto label_000791A7;
    if (*(uint8_t*)(cpu->edi + 0x138u) == 0u) goto label_000794E2;
    label_000791A7:
    if (*(uint8_t*)(cpu->edi + 0x274u) == 0u) goto label_000794B3;
    if (*(uint8_t*)(cpu->edi + 0x141u) == 0u) goto label_000794B3;
    if (*(uint32_t*)(cpu->edi + 0x184u) != 0u) goto label_000794B3;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x275u));
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000791E5;
    if (g_sfera_grass_map_runtime.alternating_update_phase == 0u) goto label_000794B3;
    label_000791E5:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18Cu);
    if (cpu->eax == 0u) goto label_0007920D;
    if (*(uint16_t*)(cpu->eax + 0x9Au) != 0u) goto label_0007920D;
    cpu->eax = g_sfera_recovered_static_runtime.simulation_tick;
    cpu->eax -= *(uint32_t*)(cpu->edi + 0x2F0u);
    if (cpu->eax > 0x78u) goto label_000794B3;
    label_0007920D:
    x87_v0 = (double)*(float*)(cpu->ebp + 8u);
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00079220;
    x87_v0 = (x87_v0) + (x87_v0);
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    goto label_00079222;
    label_00079220:
    x87_v0 = x87_v0; 
    label_00079222:
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x140u) == 1u;
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->edi + 0x294u))) * (((double)*(float*)(cpu->esp + 0x28u))));
    if (!sub_pred[0]) goto label_000792AF;
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v1 = 0.0;
    x87_v2 = x87_v1;
    { const double lift_left=x87_v2; const double lift_right=x87_v0;  x87_v0=x87_v1;  if (lift_left!=lift_right) goto label_000792AD; }
    *(float*)(cpu->esp + 0x44u) = ((((double)*(float*)(cpu->edi + 0x288u))) + (((double)*(float*)(cpu->edi + 0x27Cu))));
    *(float*)(cpu->esp + 0x48u) = ((((double)*(float*)(cpu->edi + 0x28Cu))) + (((double)*(float*)(cpu->edi + 0x280u))));
    *(float*)(cpu->esp + 0x4Cu) = ((((double)*(float*)(cpu->edi + 0x290u))) + (((double)*(float*)(cpu->edi + 0x284u))));
    { const double lift_right=(double)*(float*)(cpu->esp + 0x44u); const double lift_left=x87_v0; if (lift_left!=lift_right) goto label_000792AD; }
    { const double lift_right=(double)*(float*)(cpu->esp + 0x48u); const double lift_left=x87_v0; if (lift_left!=lift_right) goto label_000792AD; }
    x87_v1 = (double)*(float*)(cpu->esp + 0x4Cu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left==lift_right) goto label_000794B3; }
    goto label_000792AF;
    label_000792AD:
    x87_v0 = x87_v0; 
    label_000792AF:
    ++g_sfera_recovered_static_runtime.input_state_b;
    cpu->ecx = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4792BFu)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x4792BFu));
    lift_push32(cpu, 0u);
    cpu->edx = 4u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4792CDu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4792CDu));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state <= (int32_t)cpu->esi) goto label_00079456;
    label_000792DF:
    if ((int32_t)cpu->esi >= 0) goto label_000792ED;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x792EDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x792EDu));
    label_000792ED:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.clip_indices.capacity) goto label_00079301;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79301u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79301u));
    label_00079301:
    cpu->ecx = g_sfera_scene_array_runtime.clip_indices.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 1u) goto label_00079445;
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x479316u));
    cpu->ebx = 1u;
    cpu->esp += 4u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47932Bu)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x47932Bu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00079354;
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x479337u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x47933Eu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x479345u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = cpu->ebx;
    label_00079354:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47935Bu)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x47935Bu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00079384;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)" = ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x479367u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x47936Eu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x479375u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = cpu->ebx;
    label_00079384:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479393u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x479393u));
    cpu->ecx = 1u;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47939Fu)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x47939Fu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_000793C8;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4793A7u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4793AEu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4793B5u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = 1u;
    label_000793C8:
    cpu->eax = g_sfera_recovered_static_runtime.simulation_tick;
    x87_v0 = (double)*(float*)(cpu->edi + 0x10u);
    cpu->edx = cpu->eax;
    cpu->edx -= *(uint32_t*)(cpu->edi + 0x2F0u);
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    *(double*)(cpu->esp + 0x10u) = x87_v0;
     x87_v0 = (double)*(float*)(cpu->edi + 0xCu);
    *(double*)(cpu->esp + 8u) = x87_v0;
     x87_v0 = (double)*(float*)(cpu->edi + 8u);
    *(double*)(cpu->esp) = x87_v0;
    lift_push32(cpu, (uintptr_t)" = %f %f %f = %d = %d = %d\n"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4793FDu));
    cpu->esp += 0x2Cu;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479410u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x479410u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_0007943D;
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x47941Cu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x479423u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x47942Au));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = 1u;
    label_0007943D:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    label_00079445:
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) goto label_000792DF;
    label_00079456:
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    cpu->esp -= 8u;
    sub_pred[1] = *(uint8_t*)(cpu->edi + 0x276u) == 0u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp) = x87_v0; 
    if (!sub_pred[1]) goto label_0007947F;
    cpu->edx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47947Du)); sfera_sub_00473C20(cpu, LIFT_CODE_TOKEN_VA(0x47947Du));
    goto label_000794A5;
    label_0007947F:
    if (*(uint32_t*)(cpu->edi + 0x278u) != 0u) goto label_0007948F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47948Du)); sfera_sub_004748E0(cpu, LIFT_CODE_TOKEN_VA(0x47948Du));
    goto label_000794A5;
    label_0007948F:
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479496u)); sfera_sub_00473C20(cpu, LIFT_CODE_TOKEN_VA(0x479496u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x794A5u)); sfera_sub_00474120(cpu, LIFT_CODE_TOKEN_RVA(0x794A5u));
    label_000794A5:
    cpu->ecx = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4794AFu)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x4794AFu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    label_000794B3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    ++cpu->eax;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esp + 0x40u)) goto label_00079108;
    label_000794CB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000794E2:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4794F1u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4794F1u));
    if (cpu->eax != 0u) goto label_000794FA;
    cpu->eax = (uintptr_t)"<none>";
    label_000794FA:
    lift_push32(cpu, 0x33DAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xC4u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x479512u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xB8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479527u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x479527u));
    lift_trap(cpu, 0x479527u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00479530(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x40Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if (cpu->esi == 0xFFFFFFFFu) goto label_000797B3;
    if ((int32_t)cpu->esi >= 0) goto label_00079562;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79562u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79562u));
    label_00079562:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00079576;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79576u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79576u));
    label_00079576:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_000797B3;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_000795CE;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47959Eu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47959Eu));
    if (cpu->eax != 0u) goto label_000795A7;
    cpu->eax = (uintptr_t)"<none>";
    label_000795A7:
    lift_push32(cpu, 0x35A8u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4795BCu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x795CEu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x795CEu));
    label_000795CE:
    *(float*)(cpu->esp + 8u) = ((((double)*(float*)(cpu->esi + 0x294u))) * (((double)*(float*)(cpu->esp + 0x414u))));
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    x87_v3 = x87_v2;
    { const double lift_left=x87_v3; const double lift_right=x87_v1;  x87_v1=x87_v2;  if (lift_left==lift_right) goto label_00079604; }
    x87_v2 = (double)*(float*)(cpu->esi + 0x14u);
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi + 0x14u) = x87_v1; 
    *(float*)(cpu->esp + 8u) = x87_v0; 
    goto label_00079608;
    label_00079604:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00079608:
    x87_v0 = 333.0;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    if (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_02 != (cpu->ebx & 0xFFu)) goto label_000796CC;
    if (g_sfera_graphics_runtime.render_mode_enabled != (cpu->ebx & 0xFFu)) goto label_000796CC;
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32);
    x87_v1 = (x87_v1) - (x87_v0);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = x87_v1; 
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32);
    x87_v1 = (x87_v1) - (x87_v0);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = x87_v1; 
    x87_v0 = (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator))) - (x87_v0);
    g_sfera_main_input_state_runtime.motion_accumulator = x87_v0; 
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi + 8u)));
    *(float*)(cpu->esp + 8u) = x87_v1; 
    *(float*)(cpu->esp + 8u) = (fabs(((double)*(float*)(cpu->esp + 8u))));
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    x87_v2 = (double)0.5f;
    { const double lift_left=x87_v2; const double lift_right=x87_v1; x87_v1=x87_v2;  if (lift_left<lift_right) goto label_0007970D; }
    *(float*)(cpu->esp + 8u) = ((((double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32))) - (((double)*(float*)(cpu->esi + 0xCu))));
    *(float*)(cpu->esp + 8u) = (fabs(((double)*(float*)(cpu->esp + 8u))));
    { const double lift_left=(double)*(float*)(cpu->esp + 8u); const double lift_right=x87_v1; if (lift_left>lift_right) goto label_0007970D; }
    *(float*)(cpu->esp + 8u) = ((((double)g_sfera_main_input_state_runtime.motion_accumulator)) - (((double)*(float*)(cpu->esi + 0x10u))));
    *(float*)(cpu->esp + 8u) = (fabs(((double)*(float*)(cpu->esp + 8u))));
    { const double lift_left=x87_v1; const double lift_right=((double)*(float*)(cpu->esp + 8u));  if (lift_left<lift_right) goto label_0007970F; }
    label_000796CC:
    x87_v0 = x87_v0; 
    label_000796CE:
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, 0u);
    cpu->edx = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4796E0u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4796E0u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x418u);
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    cpu->esp -= 8u;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x276u) == 0u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    if (!sub_pred[0]) goto label_0007972C;
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47970Bu)); sfera_sub_00475430(cpu, LIFT_CODE_TOKEN_VA(0x47970Bu));
    goto label_00079759;
    label_0007970D:
    x87_v1 = x87_v1; 
    label_0007970F:
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_03) = cpu->ebx & 0xFFu;
    *(float*)(cpu->esi + 8u) = x87_v0; 
    *(float*)(cpu->esi + 0xCu) = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32);
    *(float*)(cpu->esi + 0x10u) = (double)g_sfera_main_input_state_runtime.motion_accumulator;
    goto label_000796CE;
    label_0007972C:
    if (*(uint32_t*)(cpu->esi + 0x278u) != 0u) goto label_0007973C;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47973Au)); sfera_sub_00475DC0(cpu, LIFT_CODE_TOKEN_VA(0x47973Au));
    goto label_00079759;
    label_0007973C:
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479743u)); sfera_sub_00475430(cpu, LIFT_CODE_TOKEN_VA(0x479743u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x418u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79759u)); sfera_sub_004755E0(cpu, LIFT_CODE_TOKEN_RVA(0x79759u));
    label_00079759:
    if (g_sfera_graphics_runtime.render_mode_enabled != (cpu->ebx & 0xFFu)) goto label_000797B2;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_02) = cpu->ebx & 0xFFu;
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
    label_000797B2:
    cpu->ebx = lift_pop32(cpu);
    label_000797B3:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x40Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004797D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x38u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_model_registry_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47980Cu)); sfera_sub_00404900(cpu, LIFT_CODE_TOKEN_VA(0x47980Cu));
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->eax == g_sfera_model_registry_runtime.sentinel) goto label_0007983F;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00079826;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00079826:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479835u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x479835u));
    if ((int32_t)cpu->eax < 0) goto label_0007983F;
    cpu->eax = cpu->esp + 8u;
    goto label_0007984D;
    label_0007983F:
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->eax = cpu->esp + 0xCu;
    label_0007984D:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != g_sfera_model_registry_runtime.sentinel) goto label_000798C1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    *(uint8_t*)(cpu->esp + 0x20u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47987Au)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x47987Au));
    *(uint32_t*)(cpu->esp + 0x30u) = 1u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_model_registry_runtime;
    *(uint32_t*)(cpu->esp + 0x48u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47989Bu)); sfera_sub_00410950(cpu, LIFT_CODE_TOKEN_VA(0x47989Bu));
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_model_registry_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4798ABu)); sfera_sub_0040C9F0(cpu, LIFT_CODE_TOKEN_VA(0x4798ABu));
    if (*(uint32_t*)(cpu->esp + 0x28u) < 0x10u) goto label_000798C4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4798BCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4798BCu));
    cpu->esp += 4u;
    goto label_000798C4;
    label_000798C1:
    ++*(uint32_t*)(cpu->eax + 0x28u);
    label_000798C4:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004798E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    cpu->ebx = 0u;
    cpu->edi = 0x77A10u;
    cpu->ebp = cpu->ebx + 0xFu;
    label_00079920:
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0007992E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7992Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7992Eu));
    label_0007992E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00079942;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79942u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79942u));
    label_00079942:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->eax != cpu->ebx) goto label_00079995;
    lift_push32(cpu, 0xCu); lift_push32(cpu, (uintptr_t)"<empty slot>");
    cpu->ecx = cpu->esp + 0x38u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47996Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x47996Au));
    cpu->ecx = cpu->esp + 0x30u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479977u)); sfera_sub_004797D0(cpu, LIFT_CODE_TOKEN_VA(0x479977u));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x44u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x58u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_00079A02;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479990u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x479990u));
    cpu->esp += 4u;
    goto label_00079A02;
    label_00079995:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4799A4u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4799A4u));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ebx & 0xFFu;
    cpu->esi = cpu->ecx + 1u;
    label_000799B5:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000799B5;
    cpu->ecx -= cpu->esi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4799C9u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4799C9u));
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x58u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4799DAu)); sfera_sub_004797D0(cpu, LIFT_CODE_TOKEN_VA(0x4799DAu));
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x28u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x58u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_000799F6;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4799F3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4799F3u));
    cpu->esp += 4u;
    label_000799F6:
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ebx & 0xFFu;
    label_00079A02:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)0x7A120u) goto label_00079920;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00479A30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479A4Du)); sfera_sub_0047F210(cpu, LIFT_CODE_TOKEN_VA(0x479A4Du));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_00079AB8;
    cpu->ebx = 0u;
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = cpu->ebx & 0xFFu;
    --cpu->edi;
    label_00079A64:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_00079A64;
    cpu->eax = cpu->ebp;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"CreateObject: no model with such name: "),40u); cpu->edi += 40u; cpu->ecx = 0u;
    cpu->esi = cpu->eax;
    label_00079A80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_00079A80;
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    cpu->eax -= cpu->esi;
    --cpu->edi;
    (void)cpu;
    label_00079A90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((uint8_t)(cpu->ecx) != (uint8_t)(cpu->ebx)) goto label_00079A90;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479AABu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x479AABu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00079AB8:
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = g_sfera_client_main_scalar_runtime.mode_02;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_model_registry_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479AD1u)); sfera_sub_0040B940(cpu, LIFT_CODE_TOKEN_VA(0x479AD1u));
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    g_sfera_model_registry_runtime.size = cpu->ebx;
    label_00079AF0:
    if ((int32_t)cpu->edi < (int32_t)0x7A120u) goto label_00079B00;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479AFDu)); sfera_sub_004798E0(cpu, LIFT_CODE_TOKEN_VA(0x479AFDu));
    label_00079B00:
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_00079B0E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79B0Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79B0Eu));
    label_00079B0E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00079B22;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79B22u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79B22u));
    label_00079B22:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->edx + (cpu->edi * 4u)) == cpu->ebx) goto label_00079B30;
    ++cpu->edi;
    goto label_00079AF0;
    label_00079B30:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479B35u)); sfera_sub_0045CBB0(cpu, LIFT_CODE_TOKEN_VA(0x479B35u));
    if (*(uint32_t*)(cpu->esp + 0x2Cu) == cpu->ebx) goto label_00079BA2;
    cpu->ebp = 0u;
    label_00079B40:
    if ((int32_t)cpu->ebp >= (int32_t)cpu->ebx) goto label_00079B4E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79B4Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79B4Eu));
    label_00079B4E:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_00079B62;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79B62u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79B62u));
    label_00079B62:
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebp * 4u)) == cpu->ebx) goto label_00079B6F;
    ++cpu->ebp;
    goto label_00079B40;
    label_00079B6F:
    if ((int32_t)cpu->ebp >= (int32_t)cpu->ebx) goto label_00079B7D;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79B7Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79B7Du));
    label_00079B7D:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_00079B91;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79B91u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79B91u));
    label_00079B91:
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u)) = cpu->edi;
    ++g_sfera_world_objects.extended_object_count;
    goto label_00079BA5;
    label_00079BA2:
    cpu->ebp |= 0xFFFFFFFFu;
    label_00079BA5:
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    if (*(uint32_t*)(cpu->esp + 0x30u) != cpu->ebx) goto label_00079BF3;
    lift_push32(cpu, 0x23CCu);
    cpu->ecx = 0x13Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479BBFu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x479BBFu));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_00079BCF;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79BCFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79BCFu));
    label_00079BCF:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00079BE3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79BE3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79BE3u));
    label_00079BE3:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    *(uint32_t*)(cpu->edx + (cpu->edi * 4u)) = cpu->esi;
    lift_push32(cpu, 0x13Cu);
    goto label_00079C33;
    label_00079BF3:
    lift_push32(cpu, 0x23D1u);
    cpu->ecx = 0x2F4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479C02u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x479C02u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_00079C12;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79C12u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x79C12u));
    label_00079C12:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00079C26;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79C26u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x79C26u));
    label_00079C26:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = cpu->esi;
    lift_push32(cpu, 0x2F4u);
    label_00079C33:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x479C35u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x3Cu));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + 0x138u) = cpu->ecx & 0xFFu;
    if ((int32_t)cpu->edi <= (int32_t)g_sfera_world_objects.max_occupied_object_handle) goto label_00079C55;
    g_sfera_world_objects.max_occupied_object_handle = cpu->edi;
    label_00079C55:
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    cpu->edx = cpu->edi + 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    g_sfera_client_main_scalar_runtime.mode_02 = cpu->edx;
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esi + 0x14u) = x87_v0;
    *(float*)(cpu->esi + 0x18u) = x87_v0;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esi + 0x1Cu) = x87_v0;
    x87_v1 = (double)-1.0f;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esi + 0x34u) = x87_v1; 
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x139u) = 1u;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x24u) = 0xF4240u;
    *(uint32_t*)(cpu->esi + 0xF4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xF8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xFCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x100u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x104u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x108u) = cpu->ebx;
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x10Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x110u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x114u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x118u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x11Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x120u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x124u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x128u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x12Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x130u) = cpu->eax;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x138u) == 1u;
    *(uint32_t*)(cpu->esi + 0x134u) = cpu->ebx;
    if (!sub_pred[0]) goto label_00079F7A;
    *(float*)(cpu->esi + 0x178u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x13Cu) = cpu->ebp;
    x87_v1 = 1.0;
    *(uint32_t*)(cpu->esi + 0x174u) = cpu->ebx;
    *(float*)(cpu->esi + 0x148u) = x87_v1; 
    *(uint32_t*)(cpu->esi + 0x170u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x144u) = cpu->ebx;
    *(uint16_t*)(cpu->esi + 0x141u) = 1u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x27Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x280u) = cpu->eax;
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esi + 0x294u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->ecx;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->edx;
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esi + 0x2B0u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x28Cu) = cpu->eax;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x290u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x2ACu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    *(uint16_t*)(cpu->esi + 0x274u) = cpu->ebx & 0xFFFFu;
    *(uint8_t*)(cpu->esi + 0x276u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x140u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x278u) = 1u;
    *(uint16_t*)(cpu->esi + 0x2A0u) = cpu->ebx & 0xFFFFu;
    cpu->edx = g_sfera_recovered_static_runtime.simulation_tick;
    *(uint32_t*)(cpu->esi + 0x2F0u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x164u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x158u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x168u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x15Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x150u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x16Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x160u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x154u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x190u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x184u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x188u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x228u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x22Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esi + 0x230u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esi + 0x2B4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esi + 0x18Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x2B8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->esi + 0x2C0u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2CCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esi + 0x2BCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x2C4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x2D0u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esi + 0x2D8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esi + 0x2C8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2D4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x2DCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->esi + 0x2E4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2E0u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x2E8u) = cpu->edx;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2ECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x479F78u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_VA(0x479F78u));
    goto label_00079F83;
    label_00079F7A:
    cpu->ecx = cpu->edi;
    x87_v0 = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x79F83u)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_RVA(0x79F83u));
    label_00079F83:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    ++g_sfera_main_render_runtime.world_object_count;
    lift_push32(cpu, (uintptr_t)"crt04"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x479F93u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00079FA7;
    *(uint32_t*)(cpu->esi + 0x38u) = 5u;
    label_00079FA7:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00479FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = cpu->edx;
    if ((int32_t)cpu->edi >= 0) goto label_0007A00D;
    lift_push32(cpu, (uintptr_t)"Wrong handle: Link_object_to_object\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A005u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x47A005u));
    cpu->esp += 8u;
    goto label_0007A0E0;
    label_0007A00D:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007A021;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7A021u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7A021u));
    label_0007A021:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    lift_push32(cpu, cpu->ebp);
    if (cpu->eax != 0u) goto label_0007A032;
    cpu->ebp = 0u;
    goto label_0007A07C;
    label_0007A032:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0007A07A;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A04Au)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47A04Au));
    if (cpu->eax != 0u) goto label_0007A053;
    cpu->eax = (uintptr_t)"<none>";
    label_0007A053:
    lift_push32(cpu, 0x373Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47A068u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7A07Au)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7A07Au));
    label_0007A07A:
    cpu->ebp = cpu->eax;
    label_0007A07C:
    if (*(uint32_t*)(cpu->ebp + (cpu->ebx * 4u) + 0xF8u) == 0u) goto label_0007A08F;
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7A08Fu)); sfera_sub_004593C0(cpu, LIFT_CODE_TOKEN_RVA(0x7A08Fu));
    label_0007A08F:
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A09Cu)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x47A09Cu));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0007A0AC;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7A0ACu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7A0ACu));
    label_0007A0AC:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007A0C0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7A0C0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7A0C0u));
    label_0007A0C0:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->eax != 0u) goto label_0007A0FA;
    label_0007A0CC:
    *(uint32_t*)(cpu->ebp + (cpu->ebx * 4u) + 0xF8u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0x184u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x188u) = cpu->ebx;
    cpu->ebp = lift_pop32(cpu);
    label_0007A0E0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0007A0FA:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0007A0CC;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A112u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47A112u));
    if (cpu->eax != 0u) goto label_0007A11B;
    cpu->eax = (uintptr_t)"<none>";
    label_0007A11B:
    lift_push32(cpu, 0x3740u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47A130u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A142u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x47A142u));
    lift_trap(cpu, 0x47A142u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0047A150(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24;
 bool lift_test[1]; bool sub_pred[2]; double x87_p0, x87_p1, x87_p2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xA0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xB0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edi = 0u;
    lift_test[0]=((g_sfera_grass_map_runtime.init_guard & 0xFFu)&1u)==0u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esi;
    if (!lift_test[0]) goto label_0007A1CD;
    g_sfera_grass_map_runtime.init_guard |= 1u;
    cpu->ecx = (uintptr_t)&g_sfera_grass_map_runtime.manager;
    *(uint32_t*)(cpu->esp + 0xB8u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A1C2u)); sfera_sub_00430BB0(cpu, LIFT_CODE_TOKEN_VA(0x47A1C2u));
    *(uint32_t*)(cpu->esp + 0xB8u) = 0xFFFFFFFFu;
label_0007A1CD:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u))));
    cpu->ebx = native_function_address32(&::rand);
    x87_p1 = 8.33329963684082;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    x87_p0 = (x87_p0) * (x87_p1);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edi;
    std::swap(x87_p1, x87_p0);
    *(uint8_t*)(cpu->esp + 0x27u) = 0u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(float*)(cpu->esp + 0x54u) = x87_p1; 
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    x87_p0 = (x87_p0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))));
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    *(float*)(cpu->esp + 0x48u) = x87_p0; 
label_0007A20C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    x87_p0 = (double)sfera_grass_jitter_x(cpu->eax >> 2u);
    cpu->edx = cpu->esp + 0x74u;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x54u)));
    cpu->ecx = cpu->esp + 0x60u;
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)sfera_grass_jitter_y(cpu->eax >> 2u);
    cpu->eax = cpu->esp + 0x5Cu;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x48u)));
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A250u)); sfera_sub_0046D270(cpu, LIFT_CODE_TOKEN_VA(0x47A250u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x30u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0; 
    cpu->ecx = (uintptr_t)&g_sfera_grass_map_runtime.manager;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A284u)); sfera_sub_00430920(cpu, LIFT_CODE_TOKEN_VA(0x47A284u));
    cpu->esi = cpu->eax;
    cpu->esi&=0xFu;
    if (cpu->esi==0u) goto label_0007A605;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A294u)); sfera_sub_00457020(cpu, LIFT_CODE_TOKEN_VA(0x47A294u));
    if (cpu->eax == 0u) goto label_0007A29B;
    cpu->esi += 0xFu;
label_0007A29B:
    cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[1].id;
label_0007A2A2:
    if (*(uint32_t*)(cpu->eax + 0xFFFFFFC8u) == cpu->esi) goto label_0007A2EB;
    if (*(uint32_t*)(cpu->eax) == cpu->esi) goto label_0007A2D6;
    if (*(uint32_t*)(cpu->eax + 0x38u) == cpu->esi) goto label_0007A2D9;
    if (*(uint32_t*)(cpu->eax + 0x70u) == cpu->esi) goto label_0007A2DE;
    if (*(uint32_t*)(cpu->eax + 0xA8u) == cpu->esi) goto label_0007A2E3;
    if (*(uint32_t*)(cpu->eax + 0xE0u) == cpu->esi) goto label_0007A2E8;
    cpu->eax += 0x150u;
    cpu->ecx += 6u;
    if ((int32_t)cpu->eax < (int32_t)((uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[1].id + 0x690u)) goto label_0007A2A2;
    goto label_0007A2EB;
label_0007A2D6:
    ++cpu->ecx;
    goto label_0007A2EB;
label_0007A2D9:
    cpu->ecx += 2u;
    goto label_0007A2EB;
label_0007A2DE:
    cpu->ecx += 3u;
    goto label_0007A2EB;
label_0007A2E3:
    cpu->ecx += 4u;
    goto label_0007A2EB;
label_0007A2E8:
    cpu->ecx += 5u;
label_0007A2EB:
    if (cpu->ecx == 0x1Eu) goto label_0007A876;
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx * 8u;
    cpu->esi -= cpu->ecx;
    cpu->ecx = cpu->esp + 0x84u;
    lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0; 
    cpu->esi = (cpu->esi * 8u) + ((uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[0].id);
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esp + 0x5Cu;
    cpu->ecx = cpu->esp + 0x84u;
    *(float*)(cpu->esp) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A332u)); sfera_sub_00470640(cpu, LIFT_CODE_TOKEN_VA(0x47A332u));
    if ((cpu->eax & 0xFFu) != 1u) goto label_0007A431;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A33Cu), LIFT_CODE_TOKEN_RVA(0x7A33Au))) { return; }
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"grass") + 4u));
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)((uintptr_t)"grass");
    cpu->eax = (int32_t)(cpu->eax) >> 15u;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->edx;
    cpu->edx = cpu->esi + (cpu->eax * 4u);
    cpu->eax = cpu->eax + cpu->edx + 4u;
    *(uint16_t*)(cpu->esp + 0x98u) = cpu->ecx & 0xFFFFu;
    cpu->esi = cpu->eax;
label_0007A370:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007A370;
    cpu->edi = cpu->esp + 0x94u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
label_0007A381:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007A381;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->edi += cpu->eax;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = g_sfera_model_runtime.repository;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x2F4u);
    cpu->eax = cpu->esp + 0x94u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A3B4u)); sfera_sub_0047F210(cpu, LIFT_CODE_TOKEN_VA(0x47A3B4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x7Cu);
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_x)) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].model_handle)) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(float*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_z)) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].state_01)) = cpu->ecx;
    *(float*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_y)) = x87_p0; 
    *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].state_02)) = cpu->edx;
    x87_p0 = (double)*(float*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].state_03)) = cpu->eax;
    *(float*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].vector_x)) = x87_p0; 
    *(float*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].vector_y)) = (double)*(float*)(cpu->esp + 0x88u);
    *(float*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].vector_z)) = (double)*(float*)(cpu->esp + 0x8Cu);
    *(float*)(cpu->esi + ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].scale)) = (double)(1.0);
    goto label_0007A605;
label_0007A431:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x2F4u);
    cpu->esi += ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_x);
    cpu->edi = 8u;
label_0007A446:
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A448u), LIFT_CODE_TOKEN_RVA(0x7A446u))) { return; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esp + 0x34u) = ((((((((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))))) * (0.5)))) / (32767.0)))) - (0.25)))) * (8.33329963684082)))) + (((double)*(float*)(cpu->esp + 0x14u))));
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A472u), LIFT_CODE_TOKEN_RVA(0x7A470u))) { return; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    cpu->esp -= 8u;
    cpu->edx = cpu->esp + 0x28u;
    cpu->ecx = cpu->esp + 0x6Cu;
    x87_p0 = (x87_p0) * (0.5);
    x87_p0 = (x87_p0) / (32767.0);
    x87_p0 = (x87_p0) - (0.25);
    x87_p0 = (x87_p0) * (8.33329963684082);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A4B9u)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x47A4B9u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007A5FE;
    *(uint8_t*)(cpu->esp + 0x27u) = 1u;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A4C8u), LIFT_CODE_TOKEN_RVA(0x7A4C6u))) { return; }
    cpu->ecx = *(uint32_t*)((uintptr_t)"grass_s00");
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"grass_s00") + 4u);
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"grass_s00") + 8u));
    cpu->eax = (int32_t)(cpu->eax) >> 15u;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->edx;
    *(uint16_t*)(cpu->esp + 0x9Cu) = cpu->ecx & 0xFFFFu;
    cpu->ecx = g_sfera_model_runtime.repository;
    cpu->edx = cpu->esp + 0x94u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0xA0u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A51Du)); sfera_sub_0047F210(cpu, LIFT_CODE_TOKEN_VA(0x47A51Du));
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->eax;
    *(float*)(cpu->esi) = x87_p0; 
    *(float*)(cpu->esi + 8u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esi + 4u) = (double)*(float*)(cpu->esp + 0x20u);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A536u), LIFT_CODE_TOKEN_RVA(0x7A534u))) { return; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esp + 0x18u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))))) * (0.5)))) / (32767.0)))) + (0.6000000238418579));
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esi + 0x144u) = x87_p0;
    x87_p0 = (x87_p0) * (0.1745329648256302);
    x87_p0 = (0.3141593337059021) - (x87_p0);
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A570u), LIFT_CODE_TOKEN_RVA(0x7A56Eu))) { return; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    x87_p1 = 6.283185958862305;
    x87_p2 = 0.0;
    x87_p1 = (x87_p1) - (x87_p2);
    std::swap(x87_p2, x87_p0);
    x87_p1 = x87_p1 * x87_p2; 
    x87_p1 = (x87_p1) / (32767.0);
    x87_p1 = (x87_p1) + (x87_p0);
    *(float*)(cpu->esi + 0xCu) = x87_p1; 
    x87_p0 = (((double)*(float*)(cpu->esp + 0x34u))) - (x87_p0);
    *(double*)(cpu->esp + 0x34u) = x87_p0;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A59Bu), LIFT_CODE_TOKEN_RVA(0x7A599u))) { return; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esi + 0x10u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))))) * (*(double*)(cpu->esp + 0x34u))))) / (32767.0)))) + (0.0));
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7A5B8u), LIFT_CODE_TOKEN_RVA(0x7A5B6u))) { return; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi += 0x2F4u;
    x87_p0 = (x87_p0) * (*(double*)(cpu->esp + 0x34u));
    x87_p0 = (x87_p0) / (32767.0);
    x87_p0 = (x87_p0) + (0.0);
    *(float*)(cpu->esi + 0xFFFFFD20u) = x87_p0; 
    *(float*)(cpu->esi + 0xFFFFFE5Cu) = (double)*(float*)(cpu->esp + 0x64u);
    *(float*)(cpu->esi + 0xFFFFFE60u) = (double)*(float*)(cpu->esp + 0x68u);
    *(float*)(cpu->esi + 0xFFFFFE64u) = (double)*(float*)(cpu->esp + 0x6Cu);
label_0007A5FE:
    if ((--cpu->edi) != 0u) goto label_0007A446;
label_0007A605:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax += 4u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x10u) goto label_0007A20C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x1Cu) == 4u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (!sub_pred[0]) goto label_0007A808;
    if (*(uint8_t*)(cpu->esp + 0x27u) != 0u) goto label_0007A813;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47A662u));
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 15u;
    if ((int32_t)cpu->eax <= 0) goto label_0007A813;
    cpu->esi = native_function_address32(&::rand);
    cpu->ebx = (uintptr_t)&g_sfera_grass_placement_runtime.slots[4].position_x;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
label_0007A692:
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7A694u), LIFT_CODE_TOKEN_RVA(0x7A692u))) { return; }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))))) * (8.33329963684082)))) / (32767.0)))) + (((double)*(float*)(cpu->esp + 0x54u))));
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7A6B2u), LIFT_CODE_TOKEN_RVA(0x7A6B0u))) { return; }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    cpu->esp -= 8u;
    cpu->edx = cpu->esp + 0x58u;
    x87_p0 = (x87_p0) * (8.33329963684082);
    cpu->ecx = cpu->esp + 0x6Cu;
    x87_p0 = (x87_p0) / (32767.0);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x50u)));
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A6EDu)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x47A6EDu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007A7FE;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7A6F7u), LIFT_CODE_TOKEN_RVA(0x7A6F5u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 15u;
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    sub_pred[1] = *(uint8_t*)(cpu->eax + cpu->edx + 0x1Du) == 0u;
    cpu->eax = cpu->eax + cpu->edx + 0x1Du;
    if (sub_pred[1]) goto label_0007A7FE;
    cpu->ecx = *(uint32_t*)((uintptr_t)"flower");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"flower") + 4u));
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"flower") + 6u));
    *(uint16_t*)(cpu->esp + 0x98u) = cpu->edx & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0x9Au) = cpu->ecx & 0xFFu;
    cpu->esi = cpu->eax;
label_0007A747:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007A747;
    cpu->edi = cpu->esp + 0x94u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
label_0007A758:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007A758;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->edi += cpu->eax;
    cpu->edx = cpu->esp + 0x94u;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47A781u)); sfera_sub_0047F210(cpu, LIFT_CODE_TOKEN_VA(0x47A781u));
    *(uint32_t*)(cpu->ebx + 0xFFFFFFFCu) = cpu->eax;
    *(float*)(cpu->ebx) = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->ebx + 8u) = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->ebx + 4u) = (double)*(float*)(cpu->esp + 0x50u);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47A798u));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = native_function_address32(&::rand);
    x87_p0 = (x87_p0) * (3.1415929794311523);
    cpu->ebx += 0x2F4u;
    x87_p0 = (x87_p0) + (x87_p0);
    x87_p0 = (x87_p0) / (32767.0);
    *(float*)(cpu->ebx + 0xFFFFFD18u) = x87_p0; 
    x87_p0 = 0.0;
    *(float*)(cpu->ebx + 0xFFFFFD1Cu) = x87_p0;
    *(float*)(cpu->ebx + 0xFFFFFD20u) = x87_p0; 
    *(float*)(cpu->ebx + 0xFFFFFE5Cu) = (double)*(float*)(cpu->esp + 0x64u);
    *(float*)(cpu->ebx + 0xFFFFFE60u) = (double)*(float*)(cpu->esp + 0x68u);
    *(float*)(cpu->ebx + 0xFFFFFE64u) = (double)*(float*)(cpu->esp + 0x6Cu);
    *(float*)(cpu->ebx + 0xFFFFFE50u) = (double)(1.0);
label_0007A7FE:
    if ((--*(uint32_t*)(cpu->esp + 0x18u)) != 0u) goto label_0007A692;
label_0007A808:
    if (*(uint32_t*)(cpu->esp + 0x1Cu) == 0u) goto label_0007AAFE;
label_0007A813:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_y);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    cpu->esi = 1u;
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = x87_p0;
     value_9 = x87_p0; if ((int32_t)cpu->edi <= (int32_t)cpu->esi) { value_8 = value_9; goto label_0007A99C; }
    cpu->eax = cpu->edi + 0xFFFFFFFFu;
    if ((int32_t)(cpu->eax) < (int32_t)(4u)) { value_5 = value_9; goto label_0007A949; }
    cpu->ecx = cpu->edi + 0xFFFFFFFBu;
    cpu->ecx >>= 2u;
    ++cpu->ecx;
    cpu->edx = (uintptr_t)&g_sfera_grass_placement_runtime.slots[2].position_y;
    cpu->esi = (cpu->ecx * 4u) + 1u; value_0 = value_9;
label_0007A855:
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->edx + 0xFFFFFD0Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
     value_10 = x87_p0; if (!(((double)*(float*)(cpu->esp + 0x14u))>(value_10))) goto label_0007A881;
    *(float*)(cpu->esp + 0x14u) = value_10; 
     value_1 = value_0; goto label_0007A898;
label_0007A876:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Grass pattern not found. Type=%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7A881u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_RVA(0x7A881u));
label_0007A881:
    if (!((value_10)>(value_0))) goto label_0007A896;
    *(float*)(cpu->esp + 0x10u) = value_10; 
    value_11 = (double)*(float*)(cpu->esp + 0x10u);
     value_1 = value_11; goto label_0007A898;
label_0007A896:
      value_1 = value_0;
label_0007A898:
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->edx);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
     value_12 = x87_p0; if (!(((double)*(float*)(cpu->esp + 0x14u))>(value_12))) goto label_0007A8B5;
    *(float*)(cpu->esp + 0x14u) = value_12; 
     value_2 = value_1; goto label_0007A8CC;
label_0007A8B5:
    if (!((value_12)>(value_1))) goto label_0007A8CA;
    *(float*)(cpu->esp + 0x10u) = value_12; 
    value_13 = (double)*(float*)(cpu->esp + 0x10u);
     value_2 = value_13; goto label_0007A8CC;
label_0007A8CA:
      value_2 = value_1;
label_0007A8CC:
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->edx + 0x2F4u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
     value_14 = x87_p0; if (!(((double)*(float*)(cpu->esp + 0x14u))>(value_14))) goto label_0007A8ED;
    *(float*)(cpu->esp + 0x14u) = value_14; 
     value_3 = value_2; goto label_0007A904;
label_0007A8ED:
    if (!((value_14)>(value_2))) goto label_0007A902;
    *(float*)(cpu->esp + 0x10u) = value_14; 
    value_15 = (double)*(float*)(cpu->esp + 0x10u);
     value_3 = value_15; goto label_0007A904;
label_0007A902:
      value_3 = value_2;
label_0007A904:
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->edx + 0x5E8u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
     value_16 = x87_p0; if (!(((double)*(float*)(cpu->esp + 0x14u))>(value_16))) goto label_0007A925;
    *(float*)(cpu->esp + 0x14u) = value_16; 
     value_4 = value_3; goto label_0007A93C;
label_0007A925:
    if (!((value_16)>(value_3))) goto label_0007A93A;
    *(float*)(cpu->esp + 0x10u) = value_16; 
    value_17 = (double)*(float*)(cpu->esp + 0x10u);
     value_4 = value_17; goto label_0007A93C;
label_0007A93A:
      value_4 = value_3;
label_0007A93C:
    cpu->edx += 0xBD0u;
    if ((--cpu->ecx) != 0u) { value_0 = value_4; goto label_0007A855; } value_5 = value_4;
label_0007A949:
    if ((int32_t)cpu->esi >= (int32_t)cpu->edi) { value_8 = value_5; goto label_0007A99C; }
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x2F4u);
    cpu->edx = cpu->edi;
    cpu->ecx += ((uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_y);
    cpu->edx -= cpu->esi; value_6 = value_5;
label_0007A95F:
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->ecx);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
     value_18 = x87_p0; if (!(((double)*(float*)(cpu->esp + 0x14u))>(value_18))) goto label_0007A97C;
    *(float*)(cpu->esp + 0x14u) = value_18; 
     value_7 = value_6; goto label_0007A993;
label_0007A97C:
    if (!((value_18)>(value_6))) goto label_0007A991;
    *(float*)(cpu->esp + 0x10u) = value_18; 
    value_19 = (double)*(float*)(cpu->esp + 0x10u);
     value_7 = value_19; goto label_0007A993;
label_0007A991:
      value_7 = value_6;
label_0007A993:
    cpu->ecx += 0x2F4u;
    if ((--cpu->edx) != 0u) { value_6 = value_7; goto label_0007A95F; } value_8 = value_7;
label_0007A99C:
    value_20 = (value_8) + (1.0);
    *(float*)(cpu->esp + 0x10u) = value_20; 
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) - (2.5));
    value_21 = (double)*(float*)(cpu->esp + 0x54u);
    x87_p0 = 4.16664981842041;
    value_22 = (value_21) + (x87_p0);
    value_24 = x87_p0; x87_p0 = value_22;
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    *(float*)(cpu->esp + 0x38u) = (double)*(float*)(cpu->esp + 0x10u);
    value_23 = (value_24) + (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x3Cu) = value_23; 
     if ((int32_t)cpu->edi <= 0) goto label_0007AA23;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi += 8u;
    cpu->esi = (uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_z;
label_0007A9EA:
    *(float*)(cpu->esi + 0xFFFFFFF8u) = ((((double)*(float*)(cpu->esi + 0xFFFFFFF8u))) - (((double)*(float*)(cpu->esp + 0x34u))));
    *(float*)(cpu->esi + 0xFFFFFFFCu) = ((((double)*(float*)(cpu->esi + 0xFFFFFFFCu))) - (((double)*(float*)(cpu->esp + 0x10u))));
    *(float*)(cpu->esi) = ((((double)*(float*)(cpu->esi))) - (((double)*(float*)(cpu->esp + 0x3Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AA15u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47AA15u));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->edi += 4u;
    cpu->esi += 0x2F4u;
    if ((--cpu->ebx) != 0u) goto label_0007A9EA;
label_0007AA23:
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 0x14u)));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.auto_grass_object);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AA50u)); sfera_sub_00469090(cpu, LIFT_CODE_TOKEN_VA(0x47AA50u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"grass1_21";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AA60u)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x47AA60u));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    if ((int32_t)cpu->esi >= 0) goto label_0007AA72;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AA72u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7AA72u));
label_0007AA72:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007AA86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AA86u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7AA86u));
label_0007AA86:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_p0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(float*)(cpu->eax + 0x1Cu) = x87_p0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->eax + 0x18u) = x87_p0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(float*)(cpu->eax + 0x14u) = x87_p0; 
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint8_t*)(cpu->eax + 0x139u) = 0u;
    cpu->edx = g_sfera_static_render_lookup_runtime.color_remap_a[cpu->ecx];
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = g_sfera_static_render_lookup_runtime.color_remap_b[cpu->ecx];
    cpu->edx|=0xFFFFFF00u;
    cpu->edx <<= 8u;
    cpu->edx|=cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->ecx = g_sfera_static_render_lookup_runtime.color_remap_c[cpu->ecx];
    cpu->edx <<= 8u;
    cpu->edx |= cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x134u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AAFEu)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_RVA(0x7AAFEu));
label_0007AAFE:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047AB30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_p0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x418u;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 1u) goto label_0007AF8D;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) != 0u);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AB98u)); sfera_sub_004BB800(cpu, LIFT_CODE_TOKEN_VA(0x47AB98u));
    cpu->esi = native_function_address32(&::Sleep);
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7ABA2u), LIFT_CODE_TOKEN_RVA(0x7ABA0u))) { return; }
    cpu->edi |= 0xFFFFFFFFu;
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABB2u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x47ABB2u));
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABBFu)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x47ABBFu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABC6u)); sfera_sub_0042AFB0(cpu, LIFT_CODE_TOKEN_VA(0x47ABC6u));
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7ABCAu), LIFT_CODE_TOKEN_RVA(0x7ABC8u))) { return; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABCFu)); sfera_sub_0042A630(cpu, LIFT_CODE_TOKEN_VA(0x47ABCFu));
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7ABD3u), LIFT_CODE_TOKEN_RVA(0x7ABD1u))) { return; }
    cpu->ecx = (uintptr_t)"models\\materls.mtr";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABDDu)); sfera_sub_00462740(cpu, LIFT_CODE_TOKEN_VA(0x47ABDDu));
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7ABE1u), LIFT_CODE_TOKEN_RVA(0x7ABDFu))) { return; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABE6u)); sfera_sub_0045B370(cpu, LIFT_CODE_TOKEN_VA(0x47ABE6u));
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7ABEAu), LIFT_CODE_TOKEN_RVA(0x7ABE8u))) { return; }
    cpu->edx = 0x42C7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABF9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47ABF9u));
    lift_push32(cpu, 0x1030u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC03u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47AC03u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 0u;
    if (cpu->eax == 0u) goto label_0007AC27;
    lift_push32(cpu, (uintptr_t)"sky.txt");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC25u)); sfera_sub_00494A10(cpu, LIFT_CODE_TOKEN_VA(0x47AC25u));
    goto label_0007AC29;
    label_0007AC27:
    cpu->eax = 0u;
    label_0007AC29:
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) == 0u;
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_font_runtime.renderer = cpu->eax;
    if (sub_pred[0]) goto label_0007AC89;
    cpu->edx = 0x42C9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC4Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AC4Du));
    lift_push32(cpu, 0x1030u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC57u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47AC57u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 1u;
    if (cpu->eax == 0u) goto label_0007AC7B;
    lift_push32(cpu, (uintptr_t)"landscape_hr\\sky_hr.txt");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC79u)); sfera_sub_00494A10(cpu, LIFT_CODE_TOKEN_VA(0x47AC79u));
    goto label_0007AC7D;
    label_0007AC7B:
    cpu->eax = 0u;
    label_0007AC7D:
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_main_aux_runtime.secondary_world_manager = cpu->eax;
    label_0007AC89:
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7AC8Du), LIFT_CODE_TOKEN_RVA(0x7AC8Bu))) { return; }
    cpu->edx = 0x42CDu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC9Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AC9Cu));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ACA6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47ACA6u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 2u;
    if (cpu->eax == 0u) goto label_0007ACC5;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ACC3u)); sfera_sub_0047EDD0(cpu, LIFT_CODE_TOKEN_VA(0x47ACC3u));
    goto label_0007ACC7;
    label_0007ACC5:
    cpu->eax = 0u;
    label_0007ACC7:
    lift_push32(cpu, (uintptr_t)"models\\");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x424u) = cpu->edi;
    g_sfera_model_runtime.repository = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ACDFu)); sfera_sub_0047EEE0(cpu, LIFT_CODE_TOKEN_VA(0x47ACDFu));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_0007ACF8;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, (uintptr_t)"models_hr\\");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7ACF8u)); sfera_sub_0047EEE0(cpu, LIFT_CODE_TOKEN_RVA(0x7ACF8u));
    label_0007ACF8:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == 0u) goto label_0007AD11;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, (uintptr_t)"models_ph\\");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AD11u)); sfera_sub_0047EEE0(cpu, LIFT_CODE_TOKEN_RVA(0x7AD11u));
    label_0007AD11:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == 0u) goto label_0007AD2A;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, (uintptr_t)"models_rd\\");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AD2Au)); sfera_sub_0047EEE0(cpu, LIFT_CODE_TOKEN_RVA(0x7AD2Au));
    label_0007AD2A:
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AD35u)); sfera_sub_0047F1D0(cpu, LIFT_CODE_TOKEN_VA(0x47AD35u));
    cpu->edx = 0x42DCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x10u) = (uintptr_t)"xadd\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AD4Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AD4Cu));
    lift_push32(cpu, 0x7540u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AD56u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47AD56u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 3u;
    if (cpu->eax == 0u) goto label_0007AD7C;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AD7Au)); sfera_sub_0041CDA0(cpu, LIFT_CODE_TOKEN_VA(0x47AD7Au));
    goto label_0007AD7E;
    label_0007AD7C:
    cpu->eax = 0u;
    label_0007AD7E:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0; 
    cpu->ecx = cpu->eax;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32);
    *(uint32_t*)(cpu->esp + 0x428u) = cpu->edi;
    *(float*)(cpu->esp) = x87_p0; 
    g_sfera_recovered_static_runtime.render_state_08 = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ADA7u)); sfera_sub_0041C1B0(cpu, LIFT_CODE_TOKEN_VA(0x47ADA7u));
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7ADABu), LIFT_CODE_TOKEN_RVA(0x7ADA9u))) { return; }
    cpu->edx = 0x42E3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ADBAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47ADBAu));
    lift_push32(cpu, 0xC8D4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ADC4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47ADC4u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 4u;
    if (cpu->eax == 0u) goto label_0007ADED;
    lift_push32(cpu, 0xBB7u); lift_push32(cpu, 0x7D0u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ADEBu)); sfera_sub_0041F2B0(cpu, LIFT_CODE_TOKEN_VA(0x47ADEBu));
    goto label_0007ADEF;
    label_0007ADED:
    cpu->eax = 0u;
    label_0007ADEF:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_client_process_runtime.client_object = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE02u)); sfera_sub_0041F360(cpu, LIFT_CODE_TOKEN_VA(0x47AE02u));
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7AE06u), LIFT_CODE_TOKEN_RVA(0x7AE04u))) { return; }
    cpu->edx = 0x42F3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE15u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AE15u));
    lift_push32(cpu, 0x7E80u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE1Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47AE1Fu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 5u;
    if (cpu->eax == 0u) goto label_0007AE43;
    lift_push32(cpu, (uintptr_t)"landscape\\weather.txt");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE41u)); sfera_sub_0049BAC0(cpu, LIFT_CODE_TOKEN_VA(0x47AE41u));
    goto label_0007AE45;
    label_0007AE43:
    cpu->eax = 0u;
    label_0007AE45:
    sub_pred[1] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) == 0u;
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_weather_runtime.standard_object = cpu->eax;
    if (sub_pred[1]) goto label_0007AEA5;
    cpu->edx = 0x42F5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE69u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AE69u));
    lift_push32(cpu, 0x7E80u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE73u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47AE73u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 6u;
    if (cpu->eax == 0u) goto label_0007AE97;
    lift_push32(cpu, (uintptr_t)"landscape_hr\\weather_hr.txt");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE95u)); sfera_sub_0049BAC0(cpu, LIFT_CODE_TOKEN_VA(0x47AE95u));
    goto label_0007AE99;
    label_0007AE97:
    cpu->eax = 0u;
    label_0007AE99:
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_weather_runtime.highres_object = cpu->eax;
    if (g_sfera_weather_runtime.highres_object == 0u) g_sfera_weather_runtime.highres_object = g_sfera_weather_runtime.standard_object;
    label_0007AEA5:
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7AEA9u), LIFT_CODE_TOKEN_RVA(0x7AEA7u))) { return; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AEAEu)); sfera_sub_00461220(cpu, LIFT_CODE_TOKEN_VA(0x47AEAEu));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"cam_cube";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AEBEu)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x47AEBEu));
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)0u) goto label_0007AED3;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AED3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7AED3u));
    label_0007AED3:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != 0u) goto label_0007AF34;
    label_0007AEDF:
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"cam_cube";
    *(uint8_t*)(cpu->eax + 0x141u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AEF6u)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x47AEF6u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AEFBu)); sfera_sub_00468BD0(cpu, LIFT_CODE_TOKEN_VA(0x47AEFBu));
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7AEFFu), LIFT_CODE_TOKEN_RVA(0x7AEFDu))) { return; }
    cpu->edx = 0x4304u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AF0Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AF0Eu));
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AF15u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47AF15u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 7u;
    if (cpu->eax == 0u) goto label_0007AF7C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AF32u)); sfera_sub_0047DB70(cpu, LIFT_CODE_TOKEN_VA(0x47AF32u));
    goto label_0007AF7E;
    label_0007AF34:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0007AEDF;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AF4Cu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47AF4Cu));
    if (cpu->eax != 0u) goto label_0007AF55;
    cpu->eax = (uintptr_t)"<none>";
    label_0007AF55:
    lift_push32(cpu, 0x42FAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47AF6Au));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AF7Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7AF7Cu));
    label_0007AF7C:
    cpu->eax = 0u;
    label_0007AF7E:
    g_sfera_input_device_runtime.shared_object = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19) = 1u;
    label_0007AF8D:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047AFC0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    bool lift_cmp[1];
    cpu->esp -= 0x34u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->esi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x4Cu);
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->edx & 0xFFu;
    cpu->edx = cpu->esp + 0x18u;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AFF3u)); sfera_sub_00470640(cpu, LIFT_CODE_TOKEN_VA(0x47AFF3u));
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ebx = 0u;
    if (cpu->eax != cpu->ebx) goto label_0007B007;
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0007B007:
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ebp);
    lift_cmp[0]=x87_v0>(((double)*(float*)(cpu->esp + 0x4Cu)));
    lift_push32(cpu, cpu->edi);
    if (cpu->eax != 2u) goto label_0007B17F;
    if (lift_cmp[0]) goto label_0007B172;
    label_0007B023:
    lift_push32(cpu, 1u); lift_push32(cpu, 4u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"treeput";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B033u)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x47B033u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0007B043;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B043u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7B043u));
    label_0007B043:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007B057;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B057u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7B057u));
    label_0007B057:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    x87_v0 = 0.0;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(float*)(cpu->edi + 0x1Cu) = x87_v0;
    *(float*)(cpu->edi + 0x18u) = x87_v0;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->edi + 0x14u) = x87_v0; 
    *(uint8_t*)(cpu->edi + 0x139u) = cpu->ebx & 0xFFu;
    *(float*)(cpu->edi + 8u) = (double)*(float*)(cpu->esp + 0x48u);
    *(float*)(cpu->edi + 0xCu) = ((((double)*(float*)(cpu->esp + 0x14u))) - (1.0));
    *(float*)(cpu->edi + 0x10u) = (double)*(float*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B092u)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_VA(0x47B092u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B0A2u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47B0A2u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    label_0007B0B0:
    x87_v0 = (double)*(float*)(cpu->edi + 0xCu);
    cpu->ebp = 0u;
    x87_v0 = (x87_v0) + (0.03999999910593033);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(float*)(cpu->edi + 0xCu) = x87_v0; 
    label_0007B0D0:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    x87_v0 = (x87_v0) * (3.1415929794311523);
    x87_v0 = (x87_v0) + (x87_v0);
    x87_v0 = (x87_v0) * (0.125);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->edi + 8u) = (((((((double)*(float*)(cpu->esp + 0x20u))) * (((double)*(float*)(cpu->esp + 0x50u)))))) + (((double)*(float*)(cpu->esp + 0x48u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x50u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x4Cu)));
    *(float*)(cpu->edi + 0x10u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B125u)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_VA(0x47B125u));
    lift_push32(cpu, 1u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B136u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47B136u));
    if ((int32_t)cpu->eax >= (int32_t)2u) goto label_0007B16B;
    if (cpu->eax != 1u) goto label_0007B144;
    ++*(uint32_t*)(cpu->esp + 0x14u);
    label_0007B144:
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)8u) goto label_0007B0D0;
    if (*(uint32_t*)(cpu->esp + 0x14u) == 8u) goto label_0007B2C9;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x64u) goto label_0007B0B0;
    label_0007B16B:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B172u)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_RVA(0x7B172u));
    label_0007B172:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0007B17F:
    if (!lift_cmp[0]) goto label_0007B023;
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x10u) != 1u);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B19Eu)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x47B19Eu));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0007B1AE;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B1AEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7B1AEu));
    label_0007B1AE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007B1C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B1C2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7B1C2u));
    label_0007B1C2:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->esp + 0x48u);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->edi + 0x139u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B21Au)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_VA(0x47B21Au));
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B22Au)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47B22Au));
    cpu->ebp = 0u;
    label_0007B230:
    x87_v0 = (double)*(float*)(cpu->edi + 0xCu);
    lift_push32(cpu, 1u);
    x87_v0 = (x87_v0) - (0.10000000149011612);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->edi + 0xCu) = x87_v0; 
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B24Du)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47B24Du));
    if ((int32_t)cpu->eax >= (int32_t)2u) goto label_0007B16B;
    if (cpu->eax == cpu->ebx) goto label_0007B274;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)0x32u) goto label_0007B230;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B267u)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_VA(0x47B267u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0007B274:
    cpu->ebp = 0u;
    label_0007B280:
    x87_v0 = (double)*(float*)(cpu->edi + 0xCu);
    lift_push32(cpu, 1u);
    x87_v0 = (x87_v0) + (0.019999999552965164);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->edi + 0xCu) = x87_v0; 
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B29Du)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47B29Du));
    if ((int32_t)cpu->eax >= (int32_t)2u) goto label_0007B16B;
    if (cpu->eax == 1u) goto label_0007B3BE;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)0x64u) goto label_0007B280;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B2BCu)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_VA(0x47B2BCu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0007B2C9:
    x87_v0 = (double)*(float*)(cpu->edi + 0xCu);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B2D7u)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_VA(0x47B2D7u));
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x10u) != 1u);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B2EFu)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x47B2EFu));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0007B2FF;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B2FFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7B2FFu));
    label_0007B2FF:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007B313;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B313u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7B313u));
    label_0007B313:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->esp + 0x48u);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ecx;
    *(uint8_t*)(cpu->edi + 0x139u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47B34Fu));
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x48u))));
    cpu->ecx = cpu->esi;
    x87_v0 = (x87_v0) * (3.1415929794311523);
    x87_v0 = (x87_v0) + (x87_v0);
    x87_v0 = (x87_v0) / (32767.0);
    *(float*)(cpu->edi + 0x14u) = x87_v0; 
    x87_v0 = 0.0;
    *(float*)(cpu->edi + 0x1Cu) = x87_v0;
    *(float*)(cpu->edi + 0x18u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B37Du)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_VA(0x47B37Du));
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = 1u;
    if ((int32_t)g_sfera_scene_array_runtime.clip_indices.capacity > (int32_t)cpu->ebx) goto label_0007B39B;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B39Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7B39Bu));
    label_0007B39B:
    cpu->eax = g_sfera_scene_array_runtime.clip_indices.data;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->eax) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B3B0u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47B3B0u));
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebx;
    if (cpu->eax != cpu->ebx) goto label_0007B16B;
    label_0007B3BE:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047B3D0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
 bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3; double x87_p0, x87_p1, x87_p2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ecx >= (int32_t)g_sfera_window_runtime.input_state) goto label_0007B8B6;
    if (g_sfera_world_render_runtime.render_queue_count == 0xDACu) goto label_0007B8B6;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x468u);
    cpu->ecx += ((uintptr_t)&g_sfera_planting_table_runtime.records[0].descriptor);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B414u)); sfera_sub_0041FBB0(cpu, LIFT_CODE_TOKEN_VA(0x47B414u));
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    if ((int32_t)cpu->eax <= 0) goto label_0007B8B6;
label_0007B430:
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B43Cu)); sfera_sub_0041FBC0(cpu, LIFT_CODE_TOKEN_VA(0x47B43Cu));
    cpu->edi = cpu->eax;
    sub_pred[0] = *(uint32_t*)(cpu->edi) == 0x3E7u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edi;
    if (!sub_pred[0]) goto label_0007B8A7;
    x87_v0 = (double)*(float*)(cpu->edi + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ebx = 1u;
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->edi + 0x118u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    if ((int32_t)cpu->esi <= (int32_t)cpu->ebx) goto label_0007B6D2;
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    if ((int32_t)(cpu->eax) < (int32_t)(4u)) goto label_0007B655;
    cpu->edx = cpu->esi + 0xFFFFFFFBu;
    cpu->edx >>= 2u;
    ++cpu->edx;
    cpu->ecx = cpu->edi + 0x11Cu;
    cpu->ebx = (cpu->edx * 4u) + 1u;
label_0007B49F:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFF00u); const double lift_left=(double)*(float*)(cpu->esp + 0x20u); if (!(lift_left>lift_right)) goto label_0007B4BC; }
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ecx + 0xFFFFFF00u);
label_0007B4BC:
    { const double lift_right=(double)*(float*)(cpu->esp + 0x14u); const double lift_left=(double)*(float*)(cpu->ecx + 0xFFFFFF00u); if (!(lift_left>lift_right)) goto label_0007B4D9; }
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->ecx + 0xFFFFFF00u);
label_0007B4D9:
    { const double lift_right=(double)*(float*)(cpu->ecx); const double lift_left=(double)*(float*)(cpu->esp + 0x1Cu); if (!(lift_left>lift_right)) goto label_0007B4EE; }
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->ecx);
label_0007B4EE:
    { const double lift_right=x87_v0; const double lift_left=(double)*(float*)(cpu->ecx); if (!(lift_left>lift_right)) goto label_0007B507; }
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
label_0007B507:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFF04u); const double lift_left=(double)*(float*)(cpu->esp + 0x20u); if (!(lift_left>lift_right)) goto label_0007B524; }
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ecx + 0xFFFFFF04u);
label_0007B524:
    { const double lift_right=(double)*(float*)(cpu->esp + 0x14u); const double lift_left=(double)*(float*)(cpu->ecx + 0xFFFFFF04u); if (!(lift_left>lift_right)) goto label_0007B541; }
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->ecx + 0xFFFFFF04u);
label_0007B541:
    { const double lift_right=(double)*(float*)(cpu->ecx + 4u); const double lift_left=(double)*(float*)(cpu->esp + 0x1Cu); if (!(lift_left>lift_right)) goto label_0007B558; }
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->ecx + 4u);
label_0007B558:
    { const double lift_right=x87_v0; const double lift_left=(double)*(float*)(cpu->ecx + 4u); if (!(lift_left>lift_right)) goto label_0007B573; }
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ecx + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
label_0007B573:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFF08u); const double lift_left=(double)*(float*)(cpu->esp + 0x20u); if (!(lift_left>lift_right)) goto label_0007B590; }
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ecx + 0xFFFFFF08u);
label_0007B590:
    { const double lift_right=(double)*(float*)(cpu->esp + 0x14u); const double lift_left=(double)*(float*)(cpu->ecx + 0xFFFFFF08u); if (!(lift_left>lift_right)) goto label_0007B5AD; }
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->ecx + 0xFFFFFF08u);
label_0007B5AD:
    { const double lift_right=(double)*(float*)(cpu->ecx + 8u); const double lift_left=(double)*(float*)(cpu->esp + 0x1Cu); if (!(lift_left>lift_right)) goto label_0007B5C4; }
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->ecx + 8u);
label_0007B5C4:
    { const double lift_right=x87_v0; const double lift_left=(double)*(float*)(cpu->ecx + 8u); if (!(lift_left>lift_right)) goto label_0007B5DF; }
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ecx + 8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
label_0007B5DF:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFF0Cu); const double lift_left=(double)*(float*)(cpu->esp + 0x20u); if (!(lift_left>lift_right)) goto label_0007B5FC; }
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ecx + 0xFFFFFF0Cu);
label_0007B5FC:
    { const double lift_right=(double)*(float*)(cpu->esp + 0x14u); const double lift_left=(double)*(float*)(cpu->ecx + 0xFFFFFF0Cu); if (!(lift_left>lift_right)) goto label_0007B619; }
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->ecx + 0xFFFFFF0Cu);
label_0007B619:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xCu); const double lift_left=(double)*(float*)(cpu->esp + 0x1Cu); if (!(lift_left>lift_right)) goto label_0007B630; }
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->ecx + 0xCu);
label_0007B630:
    { const double lift_right=x87_v0; const double lift_left=(double)*(float*)(cpu->ecx + 0xCu); if (!(lift_left>lift_right)) goto label_0007B64B; }
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ecx + 0xCu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
label_0007B64B:
    cpu->ecx += 0x10u;
    if ((--cpu->edx) != 0u) goto label_0007B49F;
label_0007B655:
    if ((int32_t)cpu->ebx >= (int32_t)cpu->esi) goto label_0007B6D2;
    cpu->esi -= cpu->ebx;
    cpu->ecx = cpu->edi + (cpu->ebx * 4u) + 0x118u;
    cpu->edx = cpu->esi;
label_0007B664:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFF00u); const double lift_left=(double)*(float*)(cpu->esp + 0x20u); if (!(lift_left>lift_right)) goto label_0007B681; }
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ecx + 0xFFFFFF00u);
label_0007B681:
    { const double lift_right=(double)*(float*)(cpu->esp + 0x14u); const double lift_left=(double)*(float*)(cpu->ecx + 0xFFFFFF00u); if (!(lift_left>lift_right)) goto label_0007B69E; }
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->ecx + 0xFFFFFF00u);
label_0007B69E:
    { const double lift_right=(double)*(float*)(cpu->ecx); const double lift_left=(double)*(float*)(cpu->esp + 0x1Cu); if (!(lift_left>lift_right)) goto label_0007B6B3; }
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->ecx);
label_0007B6B3:
    { const double lift_right=x87_v0; const double lift_left=(double)*(float*)(cpu->ecx); if (!(lift_left>lift_right)) goto label_0007B6CC; }
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
label_0007B6CC:
    cpu->ecx += 4u;
    if ((--cpu->edx) != 0u) goto label_0007B664;
label_0007B6D2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x18u) = (double)(((int32_t)(*(uint32_t*)(cpu->ecx))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x28u) = x87_v1;
    std::swap(x87_v1, x87_v0);
    *(double*)(cpu->esp + 0x48u) = x87_v1;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>lift_right)) goto label_0007B8A5; }
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
label_0007B6FD:
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v2;
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    *(double*)(cpu->esp + 0x40u) = x87_v3;
    if (!((x87_v3)>(x87_v2))) goto label_0007B884;
    label_0007B71C:
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7B726u), LIFT_CODE_TOKEN_RVA(0x7B724u))) { return; }
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(float*)(cpu->esp + 0x30u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))))) * (((double)*(float*)(cpu->esp + 0x18u)))))) / (32767.0)))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7B742u), LIFT_CODE_TOKEN_RVA(0x7B740u))) { return; }
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 8u;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x24u)));
    x87_p0 = (x87_p0) / (32767.0);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x38u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x38u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B77Au)); sfera_sub_0041FBF0(cpu, LIFT_CODE_TOKEN_VA(0x47B77Au));
    if (cpu->eax == 0u) goto label_0007B859;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x464u);
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    if ((int32_t)(cpu->edx) < (int32_t)(2u)) goto label_0007B7B4;
    cpu->ecx = cpu->edx + 0xFFFFFFFEu;
    cpu->ecx >>= 1u;
    cpu->eax += 0x34u;
    ++cpu->ecx;
    cpu->ebx = cpu->ecx + cpu->ecx;
label_0007B7A5:
    cpu->esi += *(uint32_t*)(cpu->eax + 0xFFFFFFE4u);
    cpu->edi += *(uint32_t*)(cpu->eax);
    cpu->eax += 0x38u;
    if ((--cpu->ecx) != 0u) goto label_0007B7A5;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
label_0007B7B4:
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_0007B7C5;
    cpu->edx = cpu->ebx * 8u;
    cpu->edx -= cpu->ebx;
    cpu->ebp = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x18u);
label_0007B7C5:
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47B7C5u));
    cpu->edi += cpu->esi;
    cpu->edi += cpu->ebp;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x464u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 15u;
    cpu->esi = 0u;
    cpu->ecx = 0u;
    cpu->edx = cpu->edi + 0x18u;
    (void)cpu;
label_0007B7F0:
    if ((int32_t)cpu->ecx >= (int32_t)cpu->ebx) goto label_0007B8BE;
    cpu->esi += *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_0007B804;
    ++cpu->ecx;
    cpu->edx += 0x1Cu;
    goto label_0007B7F0;
label_0007B804:
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    x87_p0 = (double)*(float*)(cpu->edi + (cpu->eax * 4u) + 0x1Cu);
    cpu->eax = cpu->edi + (cpu->eax * 4u);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_p0; 
    cpu->ecx = cpu->eax + 4u;
    x87_p0 = (double)*(float*)(cpu->esp + 0x38u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B834u)); sfera_sub_0047AFC0(cpu, LIFT_CODE_TOKEN_VA(0x47B834u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_0007B855;
    cpu->ecx = g_sfera_world_render_runtime.render_queue_count;
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_world_render_queue_runtime.entries[1])) = cpu->eax;
    ++cpu->ecx;
    g_sfera_world_render_runtime.render_queue_count = cpu->ecx;
    if (cpu->ecx == 0xDACu) goto label_0007B8B6;
label_0007B855:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
label_0007B859:
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
     value_0 = x87_p0; if (((double)*(float*)(cpu->esp + 0x1Cu))<(*(double*)(cpu->esp + 0x40u))) goto label_0007B71C;
    x87_p0 = *(double*)(cpu->esp + 0x48u);
    x87_p0 = value_0;
label_0007B884:
    x87_v2 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v2 = (x87_v2) + (x87_v1);
    *(float*)(cpu->esp + 0x28u) = x87_v2; 
    if (((double)*(float*)(cpu->esp + 0x28u))<(x87_v0)) goto label_0007B6FD;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    label_0007B8A5:
    label_0007B8A7:
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esp + 0x3Cu)) goto label_0007B430;
label_0007B8B6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
label_0007B8BE:
    cpu->ecx = (uintptr_t)"internal error 743827592";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B8C8u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x47B8C8u));
    lift_trap(cpu, 0x47B8C8u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0047B8D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_28;
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    cpu->eax += cpu->ebp;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_28) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)5u) goto label_0007BD10;
    cpu->edx = g_sfera_main_render_runtime.grass_depth_mode;
    cpu->eax = g_sfera_input_device_runtime.input_generation;
    lift_push32(cpu, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_28) = 0u;
    if (cpu->edx == 0u) goto label_0007B910;
    if (cpu->eax != 0u) goto label_0007B910;
    cpu->edi = cpu->ebp;
    goto label_0007B912;
    label_0007B910:
    cpu->edi = 0u;
    label_0007B912:
    if (cpu->edx != 0u) goto label_0007B91E;
    if (cpu->eax == 0u) goto label_0007B91E;
    cpu->eax = cpu->ebp;
    goto label_0007B920;
    label_0007B91E:
    cpu->eax = 0u;
    label_0007B920:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    g_sfera_input_device_runtime.input_generation = cpu->edx;
    if (cpu->eax == 0u) goto label_0007B96E;
    cpu->ecx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ebx = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_0007B96E;
    label_0007B938:
    cpu->esi = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_0007B962;
    label_0007B940:
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ecx += cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x98u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B956u)); sfera_sub_00459420(cpu, LIFT_CODE_TOKEN_VA(0x47B956u));
    cpu->ecx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->esi += cpu->ebp;
    if ((int32_t)cpu->esi < (int32_t)cpu->ecx) goto label_0007B940;
    label_0007B962:
    cpu->ebx += cpu->ebp;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ecx) goto label_0007B938;
    cpu->edx = g_sfera_main_render_runtime.grass_depth_mode;
    label_0007B96E:
    if (cpu->edx == 0u) goto label_0007BD0D;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0007B98A;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B98Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7B98Au));
    label_0007B98A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47B9A1u)); sfera_sub_004246B0(cpu, LIFT_CODE_TOKEN_VA(0x47B9A1u));
    if (cpu->edi == 0u) goto label_0007B9B4;
    cpu->eax = 0xF4240u;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07) = cpu->eax;
    label_0007B9B4:
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0007B9C8;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7B9C8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7B9C8u));
    label_0007B9C8:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_v0 = (double)*(float*)(cpu->eax + 8u);
    x87_v0 = (x87_v0) * (0.11999999731779099);
    x87_v0 = (x87_v0) + (100000.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->esi = cpu->eax + 0xFFFE7960u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0007BA03;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BA03u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7BA03u));
    label_0007BA03:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    x87_v0 = (double)*(float*)(cpu->edx + 0x10u);
    x87_v0 = (x87_v0) * (0.11999999731779099);
    x87_v0 = (x87_v0) + (100000.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edi = cpu->eax + 0xFFFE7960u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    if (cpu->esi != cpu->eax) goto label_0007BA3F;
    if (cpu->edi == *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07) goto label_0007BD0D;
    label_0007BA3F:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03;
    cpu->esi -= cpu->eax;
    cpu->eax = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ebp = cpu->edi;
    cpu->ebp -= (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47BA5Du));
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->edx = cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->esp += 0xCu;
    cpu->ecx = 0u;
    cpu->eax = 0u;
    if ((int32_t)cpu->edx <= 0) goto label_0007BAA3;
    label_0007BA80:
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u)) = cpu->ecx;
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) = cpu->ecx;
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->edx = cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebx);
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0007BA80;
    label_0007BAA3:
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((int32_t)cpu->eax > (int32_t)1u) goto label_0007BC4F;
    cpu->eax = cpu->ebp;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = cpu->eax;
    cpu->edi ^= cpu->edx;
    cpu->edi -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edi;
    if ((int32_t)cpu->edi > (int32_t)1u) goto label_0007BC4B;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0007BB05;
    cpu->ecx = 0u;
    if (cpu->esi == cpu->ecx) goto label_0007BAF5;
    cpu->eax = 1u;
    if (cpu->esi == cpu->eax) goto label_0007BAEB;
    cpu->ecx = (uintptr_t)"internal error 763927845";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BAEBu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7BAEBu));
    label_0007BAEB:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_0007BB19;
    label_0007BAF5:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
    goto label_0007BB19;
    label_0007BB05:
    cpu->ecx = cpu->ebx + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = cpu->ebx + 0xFFFFFFFEu;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    cpu->ecx = 0u;
    label_0007BB19:
    if (cpu->ebp == 0xFFFFFFFFu) goto label_0007BB4C;
    if (cpu->ebp == cpu->ecx) goto label_0007BB3E;
    if (cpu->ebp == 1u) goto label_0007BB31;
    cpu->ecx = (uintptr_t)"internal error 764554745";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BB31u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7BB31u));
    label_0007BB31:
    cpu->ebp = 1u;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    goto label_0007BB5A;
    label_0007BB3E:
    cpu->ebp = 0u;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    goto label_0007BB5A;
    label_0007BB4C:
    cpu->ebp = cpu->ebx + 0xFFFFFFFEu;
    cpu->edx = cpu->ebx + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    label_0007BB5A:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->ecx = cpu->ebx;
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if ((int32_t)cpu->ecx <= 0) goto label_0007BC4B;
    cpu->ecx = cpu->ebx;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx -= cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    label_0007BB80:
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_0007BC35;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    label_0007BBA0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    cpu->edx += cpu->ebp;
    cpu->edi = cpu->edx;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ebx);
    cpu->esi = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebx += cpu->eax;
    cpu->esi += cpu->eax;
    cpu->edi += cpu->ebx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x98u);
    cpu->esi += cpu->ecx;
    cpu->edi += cpu->ecx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),152u); cpu->esi += 152u; cpu->edi += 152u;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(g_sfera_landscape_interpolation_runtime.subdivision_count);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ecx;
    cpu->ecx = g_sfera_window_runtime.landscape_grid_records;
    *(uint32_t*)(cpu->ecx + (cpu->edx * 8u) + 4u) = 1u;
    cpu->edx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ecx = g_sfera_window_runtime.landscape_grid_records;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->edx += cpu->eax;
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx + (cpu->edx * 8u)) = 1u;
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = cpu->ebx;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x28u);
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)cpu->ecx) goto label_0007BBA0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    label_0007BC35:
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) < (int32_t)cpu->edx) goto label_0007BB80;
    label_0007BC4B:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0007BC4F:
    cpu->ebp = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0007BC94;
    label_0007BC55:
    cpu->esi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0007BC8F;
    label_0007BC60:
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx += cpu->esi;
    if (*(uint32_t*)(cpu->edx + (cpu->ecx * 8u)) != 0u) goto label_0007BC8A;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x98u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47BC84u)); sfera_sub_00459420(cpu, LIFT_CODE_TOKEN_VA(0x47BC84u));
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    label_0007BC8A:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_0007BC60;
    label_0007BC8F:
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ebx) goto label_0007BC55;
    label_0007BC94:
    cpu->ebp = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0007BCFD;
    label_0007BCA0:
    cpu->esi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0007BCF8;
    label_0007BCB0:
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx += cpu->esi;
    if (*(uint32_t*)(cpu->edx + (cpu->ecx * 8u) + 4u) != 0u) goto label_0007BCF3;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x98u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base);
    cpu->eax = cpu->ebx + 0xFFFFFFFFu;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->edx = cpu->eax + cpu->edi;
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ebp;
    cpu->ecx += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47BCEDu)); sfera_sub_0047A150(cpu, LIFT_CODE_TOKEN_VA(0x47BCEDu));
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    label_0007BCF3:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_0007BCB0;
    label_0007BCF8:
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ebx) goto label_0007BCA0;
    label_0007BCFD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05) = cpu->edx;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07) = cpu->edi;
    label_0007BD0D:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_0007BD10:
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047BD30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x4A8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ebx & 0xFFu;
    if (g_sfera_client_config_runtime.state_14 != cpu->esi) goto label_0007C608;
    cpu->edi = g_sfera_shadow_runtime.manager;
    if (cpu->edi == cpu->esi) goto label_0007BDF1;
    if (g_sfera_view_spatial_runtime.alternate_projection != 0u) goto label_0007BDF1;
    g_sfera_graphics_runtime.view_scale = (double)(0.0);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    x87_v1 = 0.4000000059604645;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0007BDB2; }
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (fabs(((double)*(float*)(cpu->esp + 0x10u))));
    g_sfera_graphics_runtime.view_scale = ((((double)*(float*)(cpu->esp + 0x10u))) / (1.399999976158142));
    goto label_0007BDB6;
    label_0007BDB2:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_0007BDB6:
    x87_v0 = (double)g_sfera_graphics_runtime.view_scale;
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (x87_v0) * (0.5);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 - x87_v0; 
    g_sfera_graphics_runtime.view_scale = x87_v0; 
    *(float*)(cpu->esp) = (double)g_sfera_graphics_runtime.view_scale;
    lift_push32(cpu, (uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47BDEAu)); sfera_sub_0048C860(cpu, LIFT_CODE_TOKEN_VA(0x47BDEAu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BDF1u)); sfera_sub_0048D9D0(cpu, LIFT_CODE_TOKEN_RVA(0x7BDF1u));
    label_0007BDF1:
    cpu->edi = g_sfera_world_objects.controlled_object_handle;
    cpu->eax = g_sfera_main_render_runtime.grass_depth_mode;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if (cpu->edi == 0xFFFFFFFFu) goto label_0007BE4A;
    if ((int32_t)cpu->edi >= (int32_t)cpu->esi) goto label_0007BE13;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BE13u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7BE13u));
    label_0007BE13:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007BE27;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BE27u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7BE27u));
    label_0007BE27:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    if (cpu->eax != cpu->esi) goto label_0007BE93;
    cpu->eax = 0u;
    label_0007BE36:
    { const double lift_left=(double)*(float*)(cpu->eax + 0xCu); const double lift_right=1000.0; if (!(lift_left>lift_right)) goto label_0007BEE1; }
    label_0007BE4A:
    g_sfera_main_render_runtime.grass_depth_mode = cpu->esi;
    label_0007BE50:
    cpu->edi = 1u;
    if ((cpu->ebx & 0xFFu) != 1u) goto label_0007BE5F;
    label_0007BE5A:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BE5Fu)); sfera_sub_0047B8D0(cpu, LIFT_CODE_TOKEN_RVA(0x7BE5Fu));
    label_0007BE5F:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 == cpu->esi) goto label_0007BF23;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0007BE7F;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BE7Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7BE7Fu));
    label_0007BE7F:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)80.0f;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    goto label_0007BF46;
    label_0007BE93:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0007BE36;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47BEABu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47BEABu));
    if (cpu->eax != cpu->esi) goto label_0007BEB4;
    cpu->eax = (uintptr_t)"<none>";
    label_0007BEB4:
    lift_push32(cpu, 0x2873u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0xC0u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47BECCu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xB4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BEE1u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7BEE1u));
    label_0007BEE1:
    if (g_sfera_main_render_runtime.grass_depth_mode != 2u) goto label_0007BE50;
    cpu->edi = 1u;
    if ((cpu->ebx & 0xFFu) != 1u) goto label_0007BE5F;
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47BF07u)); sfera_sub_00424A40(cpu, LIFT_CODE_TOKEN_VA(0x47BF07u));
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_main_render_runtime.grass_depth_mode) != cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47BF1Eu)); sfera_sub_00424AC0(cpu, LIFT_CODE_TOKEN_VA(0x47BF1Eu));
    goto label_0007BE5A;
    label_0007BF23:
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0007BF37;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BF37u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7BF37u));
    label_0007BF37:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)g_sfera_main_input_state_runtime.motion_y;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    label_0007BF46:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esp -= 0x10u;
    cpu->ecx = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47BF65u)); sfera_sub_0046DD80(cpu, LIFT_CODE_TOKEN_VA(0x47BF65u));
    cpu->ecx = g_sfera_landscape_patch_lookup_runtime.active_count;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state) = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0007BF85;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BF85u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7BF85u));
    label_0007BF85:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->esi) goto label_0007C17C;
    cpu->ebp = 0u;
    label_0007BFB2:
    if ((int32_t)cpu->esi >= 0) goto label_0007BFC0;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BFC0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7BFC0u));
    label_0007BFC0:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_character_index_map.capacity) goto label_0007BFD4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BFD4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7BFD4u));
    label_0007BFD4:
    cpu->ecx = g_sfera_character_index_map.data;
    cpu->edi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)cpu->esi >= 0) goto label_0007BFEB;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BFEBu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7BFEBu));
    label_0007BFEB:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_0007BFFF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7BFFFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7BFFFu));
    label_0007BFFF:
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    *(uint32_t*)(cpu->eax + cpu->ebp) = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0007C017;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C017u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C017u));
    label_0007C017:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_character_index_map.capacity) goto label_0007C02B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C02Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C02Bu));
    label_0007C02B:
    cpu->ecx = g_sfera_character_index_map.data;
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if ((int32_t)cpu->edi >= 0) goto label_0007C042;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C042u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C042u));
    label_0007C042:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007C056;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C056u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C056u));
    label_0007C056:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->esp + 0x44u))));
    *(float*)(cpu->esp + 0x3Cu) = ((((double)*(float*)(cpu->eax + 0xCu))) - (((double)*(float*)(cpu->esp + 0x48u))));
    *(float*)(cpu->esp + 0x40u) = ((((double)*(float*)(cpu->eax + 0x10u))) - (((double)*(float*)(cpu->esp + 0x4Cu))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x40u);
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
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->esi >= 0) goto label_0007C0C3;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C0C3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C0C3u));
    label_0007C0C3:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_0007C0D7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C0D7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C0D7u));
    label_0007C0D7:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    *(float*)(cpu->eax + cpu->ebp + 8u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0007C0F2;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C0F2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C0F2u));
    label_0007C0F2:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_character_index_map.capacity) goto label_0007C106;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C106u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C106u));
    label_0007C106:
    cpu->ecx = g_sfera_character_index_map.data;
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if ((int32_t)cpu->edi >= 0) goto label_0007C11D;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C11Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C11Du));
    label_0007C11D:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007C131;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C131u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C131u));
    label_0007C131:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->edi = cpu->edx + (cpu->edi * 4u);
    if ((int32_t)cpu->esi >= 0) goto label_0007C148;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C148u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C148u));
    label_0007C148:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_0007C15C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C15Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C15Cu));
    label_0007C15C:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    *(uint32_t*)(cpu->edx + cpu->ebp + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state;
    ++cpu->esi;
    cpu->ebp += 0xCu;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0007BFB2;
    label_0007C17C:
    cpu->esi = 1u;
    if ((int32_t)cpu->eax <= (int32_t)cpu->esi) goto label_0007C18F;
    cpu->edx = cpu->eax + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C18Fu)); sfera_sub_00456880(cpu, LIFT_CODE_TOKEN_RVA(0x7C18Fu));
    label_0007C18F:
    cpu->edi = 2u;
    if (g_sfera_main_render_runtime.grass_depth_mode != cpu->edi) goto label_0007C1CE;
    if ((cpu->ebx & 0xFFu) != 1u) goto label_0007C1CE;
    if ((int32_t)g_sfera_scene_array_runtime.object_positions.capacity > (int32_t)0u) goto label_0007C1B6;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C1B6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C1B6u));
    label_0007C1B6:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state;
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C1CEu)); sfera_sub_004249C0(cpu, LIFT_CODE_TOKEN_RVA(0x7C1CEu));
    label_0007C1CE:
    sub_pred[0] = (uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = 0x7530u;
    g_sfera_window_runtime.render_state_word = cpu->esi;
    if (sub_pred[0]) goto label_0007C1F3;
    if ((int32_t)g_sfera_options_dialog_runtime.reflection_quality <= (int32_t)cpu->esi) goto label_0007C2DA;
    label_0007C1F3:
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state <= (int32_t)cpu->ebp) goto label_0007C2DA;
    cpu->ebx = 0u;
    label_0007C203:
    if ((int32_t)cpu->ebp >= 0) goto label_0007C211;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C211u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C211u));
    label_0007C211:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_0007C225;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C225u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C225u));
    label_0007C225:
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->esi = *(uint32_t*)(cpu->ebx + cpu->edx);
    if ((int32_t)cpu->esi >= 0) goto label_0007C23C;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C23Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C23Cu));
    label_0007C23C:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007C250;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C250u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C250u));
    label_0007C250:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi == 1u) goto label_0007C2C1;
    if (*(uint8_t*)(cpu->edi + 0x138u) != 1u) goto label_0007C26F;
    if (*(uint8_t*)(cpu->edi + 0x141u) == 0u) goto label_0007C2C1;
    label_0007C26F:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C27Eu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47C27Eu));
    if (*(uint8_t*)(cpu->eax + 0x50u) != 0u) goto label_0007C2C1;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C293u)); sfera_sub_0047F230(cpu, LIFT_CODE_TOKEN_VA(0x47C293u));
    cpu->ecx = cpu->esi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007C2BC;
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->edi + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C2A5u)); sfera_sub_00456760(cpu, LIFT_CODE_TOKEN_VA(0x47C2A5u));
    if (*(uint8_t*)(cpu->esp + 0x14u) != 1u) goto label_0007C2B3;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C2B3u)); sfera_sub_00477020(cpu, LIFT_CODE_TOKEN_RVA(0x7C2B3u));
    label_0007C2B3:
    *(float*)(cpu->edi + 0xCu) = (double)*(float*)(cpu->esp + 0x10u);
    goto label_0007C2C1;
    label_0007C2BC:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C2C1u)); sfera_sub_00477020(cpu, LIFT_CODE_TOKEN_RVA(0x7C2C1u));
    label_0007C2C1:
    ++cpu->ebp;
    cpu->ebx += 0xCu;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state) goto label_0007C203;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x14u));
    cpu->edi = 2u;
    label_0007C2DA:
    if (g_sfera_main_render_runtime.grass_depth_mode != cpu->edi) goto label_0007C2F2;
    if ((cpu->ebx & 0xFFu) != 1u) goto label_0007C2F2;
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C2F2u)); sfera_sub_004255D0(cpu, LIFT_CODE_TOKEN_RVA(0x7C2F2u));
    label_0007C2F2:
    if (g_sfera_main_render_runtime.secondary_render_pass == 0u) goto label_0007C307;
    if ((int32_t)g_sfera_options_dialog_runtime.reflection_quality <= (int32_t)cpu->edi) goto label_0007C5FE;
    label_0007C307:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state <= (int32_t)cpu->edi) goto label_0007C5FE;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    label_0007C320:
    if ((int32_t)cpu->edi >= 0) goto label_0007C32E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C32Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C32Eu));
    label_0007C32E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_0007C342;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C342u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C342u));
    label_0007C342:
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->ecx + cpu->eax);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if (cpu->esi == 1u) goto label_0007C5E8;
    if ((int32_t)cpu->esi >= 0) goto label_0007C369;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C369u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7C369u));
    label_0007C369:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007C37D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C37Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7C37Du));
    label_0007C37D:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->esi + 0x138u) == 0u) goto label_0007C5E8;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C3A2u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47C3A2u));
    cpu->ebx = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x50u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007C5E8;
    if (*(uint8_t*)(cpu->esi + 0x138u) == 0u) goto label_0007C621;
    if (*(uint8_t*)(cpu->esi + 0x141u) == 0u) goto label_0007C5E8;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x144u) < (int32_t)0u) goto label_0007C54F;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x170u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x174u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    if ((int32_t)cpu->edx < (int32_t)cpu->edi) goto label_0007C3FB;
    cpu->ecx = cpu->eax & 0xFFu;
    if ((int32_t)cpu->edx < (int32_t)cpu->ecx) goto label_0007C417;
    label_0007C3FB:
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, (uintptr_t)"DrawObjects: wrong animation. Name=%s\n"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47C406u));
    cpu->esp += 0xCu;
    cpu->edx = 0u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    label_0007C417:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if ((int32_t)(cpu->edx) < (int32_t)(2u)) goto label_0007C451;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x5Cu);
    cpu->ecx = cpu->edx + 0xFFFFFFFEu;
    cpu->ecx >>= 1u;
    ++cpu->ecx;
    cpu->ebx = cpu->ecx + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    label_0007C432:
    cpu->ebx = *(uint16_t*)(cpu->eax);
    cpu->edi += cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->eax + 2u);
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->eax += 4u;
    if ((--cpu->ecx) != 0u) goto label_0007C432;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_0007C451:
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_0007C45E;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x5Cu);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u));
    goto label_0007C462;
    label_0007C45E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0007C462:
    cpu->edi += *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = 0u;
    cpu->eax += cpu->edi;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ecx) goto label_0007C479;
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x5Cu);
    cpu->edx = *(uint16_t*)(cpu->edi + (cpu->edx * 2u));
    if ((int32_t)cpu->ebp < (int32_t)cpu->edx) goto label_0007C47B;
    label_0007C479:
    cpu->ebp = 0u;
    label_0007C47B:
    x87_v0 = (double)0.009999999776482582f;
    cpu->eax += cpu->ebp;
    g_sfera_client_main_scalar_runtime.state_06 = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = cpu->ecx;
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esi + 0x178u));  if (!(lift_left<lift_right)) goto label_0007C54F; }
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = 1u;
    *(float*)((uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32) = (double)*(float*)(cpu->esi + 0x178u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x180u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    if ((int32_t)cpu->edx < (int32_t)cpu->ecx) goto label_0007C4D5;
    cpu->edi = *(uint8_t*)(cpu->ebx + 0x50u);
    if ((int32_t)cpu->edx < (int32_t)cpu->edi) goto label_0007C4DD;
    label_0007C4D5:
    cpu->edx = 0u;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_0007C4DD:
    cpu->edi = 0u;
    cpu->ebp = 0u;
    cpu->ecx = 0u;
    if ((int32_t)(cpu->edx) < (int32_t)(2u)) goto label_0007C51D;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x5Cu);
    cpu->ecx = cpu->edx + 0xFFFFFFFEu;
    cpu->ecx >>= 1u;
    ++cpu->ecx;
    cpu->ebx = cpu->ecx + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    label_0007C500:
    cpu->ebx = *(uint16_t*)(cpu->eax);
    cpu->edi += cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->eax + 2u);
    cpu->ebp += cpu->ebx;
    cpu->eax += 4u;
    if ((--cpu->ecx) != 0u) goto label_0007C500;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0007C51D:
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edx) goto label_0007C52E;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x5Cu);
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->ecx * 2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_0007C532;
    label_0007C52E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    label_0007C532:
    cpu->edi += cpu->ebp;
    cpu->ecx += cpu->edi;
    if ((int32_t)cpu->eax < 0) goto label_0007C545;
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x5Cu);
    cpu->edx = *(uint16_t*)(cpu->edi + (cpu->edx * 2u));
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0007C547;
    label_0007C545:
    cpu->eax = 0u;
    label_0007C547:
    cpu->ecx += cpu->eax;
    g_sfera_render_sample_runtime.material_base = cpu->ecx;
    label_0007C54F:
    { const double lift_left=0.0; const double lift_right=((double)*(float*)(cpu->ebx + 0x1C0u)); if (!(lift_left<lift_right)) goto label_0007C59A; }
    if (g_sfera_main_render_runtime.grass_depth_mode != 2u) goto label_0007C59A;
    if (*(uint8_t*)(cpu->esp + 0x14u) != 1u) goto label_0007C59A;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x1C0u);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esi + 0x10u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C598u)); sfera_sub_004246E0(cpu, LIFT_CODE_TOKEN_VA(0x47C598u));
    goto label_0007C59E;
    label_0007C59A:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0007C59E:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x144u) < (int32_t)0u) goto label_0007C5B0;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C5AEu)); sfera_sub_00477FB0(cpu, LIFT_CODE_TOKEN_VA(0x47C5AEu));
    goto label_0007C5E4;
    label_0007C5B0:
    x87_v0 = (double)*(float*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1E0u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C5CBu)); sfera_sub_0044ECA0(cpu, LIFT_CODE_TOKEN_VA(0x47C5CBu));
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->eax;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C5E4u)); sfera_sub_0041D3C0(cpu, LIFT_CODE_TOKEN_RVA(0x7C5E4u));
    label_0007C5E4:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0007C5E8:
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state) goto label_0007C320;
    label_0007C5FE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    g_sfera_main_render_runtime.grass_depth_mode = cpu->ecx;
    label_0007C608:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4A8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007C621:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C630u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47C630u));
    if (cpu->eax != 0u) goto label_0007C639;
    cpu->eax = (uintptr_t)"<none>";
    label_0007C639:
    lift_push32(cpu, 0x28CBu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0xC0u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47C651u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xB4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C666u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x47C666u));
    lift_trap(cpu, 0x47C666u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0047C670(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26, value_27, value_28, value_29, value_30, value_31, value_32, value_33, value_34, value_35, value_36;
 double x87_p0, x87_p1, x87_p2;
    bool lift_cmp[1];
    goto label_0007C670;
label_00076B40:
    cpu->esp -= 0x38u;
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    if (cpu->ecx == 0xFFFFFFFFu) goto label_00076DBD;
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476B66u)); sfera_sub_004766E0(cpu, LIFT_CODE_TOKEN_VA(0x476B66u));
    if (cpu->eax != 5u) goto label_00076DBD;
    x87_p0 = 0.0;
    x87_p1 = (double)g_sfera_main_input_state_runtime.camera_step;
    lift_cmp[0]=x87_p1<x87_p0;
    x87_p2 = 0.20000000298023224;
     value_11 = x87_p2; value_12 = x87_p1; value_13 = x87_p0; if (!lift_cmp[0]) { value_0 = value_12; goto label_00076BA0; }
    x87_p0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    x87_p0 = (x87_p0) / (value_11);
    value_14 = value_12 + x87_p0; 
    g_sfera_main_input_state_runtime.camera_step = value_14; 
    value_15 = (double)g_sfera_main_input_state_runtime.camera_step;
     value_0 = value_15;
label_00076BA0:
    *(float*)(cpu->esp + 4u) = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    x87_p0 = (double)*(float*)(cpu->esp + 4u); x87_p1 = x87_p0;
    x87_p1 = (x87_p1) / (value_11);
     value_17 = x87_p1; value_18 = x87_p0; if (!((value_17)<(value_0))) goto label_00076DCC;
    value_19 = value_0 - value_17; 
    g_sfera_main_input_state_runtime.camera_step = value_19; 
    value_20 = (double)g_sfera_main_input_state_runtime.camera_step;
      value_1 = value_20;
label_00076BD1:
    x87_p0 = (double)g_sfera_recovered_static_runtime.cursor_accumulator;
     value_21 = x87_p0; { const double lift_left=value_21; const double lift_right=value_13;   if (!(lift_left<lift_right)) { value_2 = value_1; value_3 = value_21; goto label_00076BFC; } }
    x87_p0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    x87_p0 = (x87_p0) / (value_11);
    value_22 = value_21 + x87_p0; 
    g_sfera_recovered_static_runtime.cursor_accumulator = value_22; 
    value_23 = (double)g_sfera_recovered_static_runtime.cursor_accumulator;
     value_2 = value_1; value_3 = value_23;
label_00076BFC:
    *(float*)(cpu->esp + 4u) = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    x87_p0 = (double)*(float*)(cpu->esp + 4u); x87_p1 = x87_p0;
    x87_p1 = (x87_p1) / (value_11);
     value_24 = x87_p1; value_25 = x87_p0; if (!((value_24)<(value_3))) goto label_00076DD3;
    value_26 = value_3 - value_24; 
    g_sfera_recovered_static_runtime.cursor_accumulator = value_26; 
    value_27 = (double)g_sfera_recovered_static_runtime.cursor_accumulator;
      value_4 = value_2; value_5 = value_27;
label_00076C2D:
    lift_push32(cpu, cpu->ebx);
    value_28 = -value_4;
    lift_push32(cpu, cpu->ebp);
    value_29 = value_28 / value_18; 
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    value_30 = (value_29) * (value_11);
    *(float*)(cpu->esp + 0x14u) = value_30; 
    value_31 = -value_5;
    value_32 = value_31 / value_25; 
    value_33 = (value_32) * (value_11);
    *(float*)(cpu->esp + 0x10u) = value_33; 
     if ((int32_t)cpu->esi >= 0) { value_6 = value_11; goto label_00076C63; }
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476C5Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x476C5Du));
    x87_p0 = 0.20000000298023224;
     value_34 = x87_p0;  value_6 = value_34;
label_00076C63:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_00076C7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476C79u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x476C79u));
    x87_p0 = 0.20000000298023224;
label_00076C7F:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edx = 0x5F317777u;
    *(float*)(cpu->esp + 0x1Cu) = x87_p0;
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esi + (cpu->esi * 2u);
    cpu->edi = cpu->ecx + (cpu->eax * 8u);
    *(float*)(cpu->esp + 0x20u) = x87_p1;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3030)) & 0xFFFFu);
    x87_p2 = x87_p0;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    x87_p2 = (x87_p2) + (value_6);
    *(uint16_t*)(cpu->esp + 0x40u) = cpu->eax & 0xFFFFu;
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x10u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->esp + 0x42u) = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(float*)(cpu->esp + 0x24u) = x87_p2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(float*)(cpu->esp + 0x2Cu) = x87_p2; 
    *(uint8_t*)(cpu->esp + 0x3Eu) = cpu->edx & 0xFFu;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    *(float*)(cpu->esp + 0x28u) = x87_p1;
    cpu->eax -= cpu->edx;
    value_7 = value_6 + x87_p1; 
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    value_35 = x87_p0; x87_p0 = value_7;
    cpu->ecx = 0xAu;
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(float*)(cpu->esp + 0x30u) = x87_p0;
    *(float*)(cpu->esp + 0x38u) = x87_p0; 
    *(float*)(cpu->esp + 0x34u) = value_35; 
    *(float*)(cpu->esp + 0x10u) = (fabs(((double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y))));
    value_8 = (double)*(float*)(cpu->esp + 0x10u); x87_p0 = value_8;
    x87_p0 = (x87_p0) * (((double)g_sfera_view_spatial_runtime.basis[3].x.f32));
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.basis[2].x.f32));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x40u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x41u) = cpu->edx & 0xFFu;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    x87_p0 = value_8;
    x87_p0 = (x87_p0) * (((double)g_sfera_view_spatial_runtime.basis[3].y.f32));
    cpu->esi = cpu->eax;
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.basis[2].y.f32));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    value_9 = (value_8) * (((double)g_sfera_view_spatial_runtime.basis[3].z.f32));
    cpu->ebp = cpu->eax;
    value_10 = (value_9) + (((double)g_sfera_view_spatial_runtime.basis[2].z.f32));
    cpu->eax = (uint32_t)(int32_t)std::trunc(value_10); 
    cpu->ebx = cpu->eax;
     if ((int32_t)cpu->esi <= (int32_t)0xFFu) goto label_00076D6C;
    cpu->esi = 0xFFu;
label_00076D6C:
    if ((int32_t)cpu->ebp <= (int32_t)0xFFu) goto label_00076D79;
    cpu->ebp = 0xFFu;
label_00076D79:
    if ((int32_t)cpu->ebx <= (int32_t)0xFFu) goto label_00076D86;
    cpu->ebx = 0xFFu;
label_00076D86:
    x87_p0 = (double)*(float*)(cpu->edi + 8u);
    cpu->edx = cpu->esp + 0x1Cu;
    x87_p0 = (x87_p0) * (255.0);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476DB9u)); sfera_sub_0044FF80(cpu, LIFT_CODE_TOKEN_VA(0x476DB9u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
label_00076DBD:
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_00076DCC:
     value_1 = value_0; goto label_00076BD1;
label_00076DD3:
     value_4 = value_2; value_5 = value_3; goto label_00076C2D;
label_0007C670:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi == 1u) goto label_0007C686;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    if (cpu->esi != 2u) goto label_0007C68B;
label_0007C686:
    cpu->ecx = 0x100u;
label_0007C68B:
    if (cpu->esi == 1u) goto label_0007C69A;
    cpu->eax = g_sfera_graphics_runtime.display_height;
    if (cpu->esi != 2u) goto label_0007C69F;
label_0007C69A:
    cpu->eax = 0x100u;
label_0007C69F:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C6ACu)); sfera_sub_0046BD40(cpu, LIFT_CODE_TOKEN_VA(0x47C6ACu));
    x87_p0 = 1.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C6CAu)); sfera_sub_004D87E0(cpu, LIFT_CODE_TOKEN_VA(0x47C6CAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if (cpu->esi == 2u) goto label_0007C6EB;
    cpu->eax = g_sfera_view_spatial_runtime.basis[0].y.u32;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C6E2u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47C6E2u));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[0].z.u32;
    lift_push32(cpu, cpu->ecx);
    goto label_0007C70D;
label_0007C6EB:
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.y))) - (1.0));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C707u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47C707u));
    cpu->eax = g_sfera_view_spatial_runtime.scale.y.u32;
    lift_push32(cpu, cpu->eax);
label_0007C70D:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x25u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C71Au)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47C71Au));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C71Fu)); sfera_sub_00450A00(cpu, LIFT_CODE_TOKEN_VA(0x47C71Fu));
    if (cpu->esi != 0u) goto label_0007C72D;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C728u)); sfera_sub_0044E1B0(cpu, LIFT_CODE_TOKEN_VA(0x47C728u));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C72Du)); sfera_sub_0044E230(cpu, LIFT_CODE_TOKEN_RVA(0x7C72Du));
label_0007C72D:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C73Cu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47C73Cu));
    if (g_sfera_view_spatial_runtime.alternate_projection != 0u) goto label_0007C74E;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 1u) goto label_0007C753;
label_0007C74E:
    if (cpu->esi != 1u) goto label_0007C789;
label_0007C753:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C758u)); if (!sfera_sub_00457E80(cpu, LIFT_CODE_TOKEN_VA(0x47C758u), value_36)) { return; }
    *(float*)(cpu->esp + 4u) = value_36; 
    value_16 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = value_16; 
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C769u)); sfera_sub_0045C230(cpu, LIFT_CODE_TOKEN_VA(0x47C769u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C76Eu)); sfera_sub_00457020(cpu, LIFT_CODE_TOKEN_VA(0x47C76Eu));
    if (cpu->eax != 1u) goto label_0007C77D;
    cpu->ecx = (uintptr_t)&g_sfera_view_render_objects_runtime.primary.storage[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C77Du)); sfera_sub_00454DC0(cpu, LIFT_CODE_TOKEN_RVA(0x7C77Du));
label_0007C77D:
    cpu->ecx = (uintptr_t)&g_sfera_view_render_objects_runtime.alternate.storage[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C787u)); sfera_sub_00454DC0(cpu, LIFT_CODE_TOKEN_VA(0x47C787u));
    goto label_0007C7B2;
label_0007C789:
    x87_p0 = 0.0;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, 0xFFu); lift_push32(cpu, (uintptr_t)"black"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C7B2u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_RVA(0x7C7B2u));
label_0007C7B2:
    x87_p0 = 1.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C7D0u)); sfera_sub_004D87E0(cpu, LIFT_CODE_TOKEN_VA(0x47C7D0u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C7DFu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47C7DFu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C7E4u)); sfera_sub_00470DA0(cpu, LIFT_CODE_TOKEN_VA(0x47C7E4u));
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].x);
    *(uint64_t*)(cpu->esp + 8u) = static_cast<int64_t>(std::trunc(x87_p0));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx&=0xFFu;
    cpu->ecx <<= 8u;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].y);
    *(uint64_t*)(cpu->esp + 8u) = static_cast<int64_t>(std::trunc(x87_p0));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx &= 0xFFu;
    cpu->ecx|=cpu->edx;
    cpu->ecx <<= 8u;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].z);
    *(uint64_t*)(cpu->esp + 8u) = static_cast<int64_t>(std::trunc(x87_p0));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax &= 0xFFu;
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x22u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C885u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47C885u));
    if (cpu->esi != 1u) goto label_0007C895;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_0047BD30(cpu, stop_address); return;
label_0007C895:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C89Cu)); sfera_sub_0047BD30(cpu, LIFT_CODE_TOKEN_VA(0x47C89Cu));
    if (cpu->esi != 0u) goto label_0007C96D;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C8A9u)); sfera_sub_00450A00(cpu, LIFT_CODE_TOKEN_VA(0x47C8A9u));
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    x87_p0 = -x87_p0;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    *(float*)(cpu->esp + 8u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    x87_p0 = -x87_p0;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_p0 = -x87_p0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C90Au)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x47C90Au));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C90Fu)); sfera_sub_0046A070(cpu, LIFT_CODE_TOKEN_VA(0x47C90Fu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C914u)); sfera_sub_0041A0B0(cpu, LIFT_CODE_TOKEN_VA(0x47C914u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C91Bu)); sfera_sub_0041A560(cpu, LIFT_CODE_TOKEN_VA(0x47C91Bu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C929u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47C929u));
    cpu->ecx = (uintptr_t)&g_sfera_server_wall;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C933u)); sfera_sub_0048A740(cpu, LIFT_CODE_TOKEN_VA(0x47C933u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C938u)); sfera_sub_00450260(cpu, LIFT_CODE_TOKEN_VA(0x47C938u));
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_flare_projection.y.f32);
    cpu->eax = g_sfera_recovered_static_runtime.scene_state_09;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xDCu);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_flare_projection.x.f32);
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C964u)); sfera_sub_0042ADA0(cpu, LIFT_CODE_TOKEN_VA(0x47C964u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    goto label_00076B40;
label_0007C96D:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047C980(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0; double x87_p0;
    cpu->esp -= 0xCu;
    x87_v0 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 1u;
    sub_pred[0] = (uint32_t)(g_sfera_world_render_runtime.feature_toggle) == cpu->edi;
    lift_push32(cpu, (uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x); lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (sub_pred[0]);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = cpu->edi + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C9A9u)); sfera_sub_00457510(cpu, LIFT_CODE_TOKEN_VA(0x47C9A9u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C9BCu)); sfera_sub_004DA310(cpu, LIFT_CODE_TOKEN_VA(0x47C9BCu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007CB92;
    lift_push32(cpu, cpu->esi);
    g_sfera_world_render_runtime.scene_active = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C9D0u)); sfera_sub_004C3A20(cpu, LIFT_CODE_TOKEN_VA(0x47C9D0u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C9D7u)); sfera_sub_004C3AB0(cpu, LIFT_CODE_TOKEN_VA(0x47C9D7u));
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x98u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7C9F3u), LIFT_CODE_TOKEN_RVA(0x7C9F1u))) { return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0xA0u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CA0Cu), LIFT_CODE_TOKEN_RVA(0x7CA0Au))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x48u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CA1Bu), LIFT_CODE_TOKEN_RVA(0x7CA19u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->ecx == 0u) goto label_0007CB31;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x94u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CA3Du), LIFT_CODE_TOKEN_RVA(0x7CA3Bu))) { return; }
    x87_p0 = 0.0;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = cpu->edi + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CA4Du)); sfera_sub_00464600(cpu, LIFT_CODE_TOKEN_VA(0x47CA4Du));
    cpu->ecx = cpu->edi + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CA55u)); sfera_sub_0047C670(cpu, LIFT_CODE_TOKEN_VA(0x47CA55u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27 == 0u) goto label_0007CAAF;
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0007CAAF;
    if ((int32_t)cpu->esi >= 0) goto label_0007CA77;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CA77u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7CA77u));
    label_0007CA77:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007CA8B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CA8Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7CA8Bu));
    label_0007CA8B:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_saved_controlled_position.x;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = g_sfera_saved_controlled_position.y;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_saved_controlled_position.z;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    label_0007CAAF:
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0007CAC3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CAC3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7CAC3u));
    label_0007CAC3:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_34;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = g_sfera_client_main_scalar_runtime.state_35;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_36;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0007CAFA;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CAFAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7CAFAu));
    label_0007CAFA:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0];
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1];
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2];
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CB25u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_VA(0x47CB25u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CB31u), LIFT_CODE_TOKEN_RVA(0x7CB2Fu))) { return; }
    label_0007CB31:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x94u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CB4Cu), LIFT_CODE_TOKEN_RVA(0x7CB4Au))) { return; }
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x9Cu);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CB64u), LIFT_CODE_TOKEN_RVA(0x7CB62u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CB70u), LIFT_CODE_TOKEN_RVA(0x7CB6Eu))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CB7Cu), LIFT_CODE_TOKEN_RVA(0x7CB7Au))) { return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CB87u)); sfera_sub_004D8840(cpu, LIFT_CODE_TOKEN_VA(0x47CB87u));
    g_sfera_world_render_runtime.scene_active = 0u;
    cpu->esi = lift_pop32(cpu);
    label_0007CB92:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047CBA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2; double x87_p0;
    cpu->esp -= 0x20u;
    if (g_sfera_view_spatial_runtime.alternate_projection != 0u) goto label_0007CD85;
    *(float*)((uintptr_t)&g_sfera_window_runtime.distance_scratch.f32) = (double)100000.0f;
    g_sfera_main_input_state_runtime.motion_x = (double)1000000.0f;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CBD8u)); sfera_sub_0046D6A0(cpu, LIFT_CODE_TOKEN_VA(0x47CBD8u));
    x87_v0 = (double)99999.0f;
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_window_runtime.distance_scratch.f32);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (lift_left>lift_right) goto label_0007CD83; }
    x87_v1 = 0.0;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0xCu) = x87_v1;
    cpu->edx = cpu->esp + 0xCu;
    x87_v2 = (double)-1.0f;
    g_sfera_main_render_runtime.secondary_render_pass = 1u;
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xDCu);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CC2Fu), LIFT_CODE_TOKEN_RVA(0x7CC2Du))) { return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CC41u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47CC41u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CC4Cu)); sfera_sub_004DA310(cpu, LIFT_CODE_TOKEN_VA(0x47CC4Cu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007CD58;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CC6Eu), LIFT_CODE_TOKEN_RVA(0x7CC6Cu))) { return; }
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xA0u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CC86u), LIFT_CODE_TOKEN_RVA(0x7CC84u))) { return; }
    cpu->ecx = g_sfera_render_sample_runtime.active_record;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x48u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CC9Eu), LIFT_CODE_TOKEN_RVA(0x7CC9Cu))) { return; }
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x94u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CCB8u), LIFT_CODE_TOKEN_RVA(0x7CCB6u))) { return; }
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_window_runtime.distance_scratch.f32);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    *(float*)(cpu->esp) = x87_p0; 
    cpu->ecx = 1u;
    g_sfera_world_render_runtime.scene_active = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CCD8u)); sfera_sub_00464600(cpu, LIFT_CODE_TOKEN_VA(0x47CCD8u));
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CCE2u)); sfera_sub_0047C670(cpu, LIFT_CODE_TOKEN_VA(0x47CCE2u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CCEEu)); sfera_sub_00464AA0(cpu, LIFT_CODE_TOKEN_VA(0x47CCEEu));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CCFAu), LIFT_CODE_TOKEN_RVA(0x7CCF8u))) { return; }
    cpu->edx = *(uint32_t*)(cpu->esp);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x94u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CD13u), LIFT_CODE_TOKEN_RVA(0x7CD11u))) { return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x9Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CD2Cu), LIFT_CODE_TOKEN_RVA(0x7CD2Au))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CD37u), LIFT_CODE_TOKEN_RVA(0x7CD35u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CD43u), LIFT_CODE_TOKEN_RVA(0x7CD41u))) { return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CD4Eu)); sfera_sub_004D8840(cpu, LIFT_CODE_TOKEN_VA(0x47CD4Eu));
    g_sfera_world_render_runtime.scene_active = 0u;
    label_0007CD58:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CD6Au)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47CD6Au));
    g_sfera_main_render_runtime.secondary_render_pass = 0u;
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007CD83:
    x87_v0 = x87_v0; 
    label_0007CD85:
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047CDA0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[4]; double x87_v0, x87_v1;
    goto label_0007CDA0;
    label_0001C0A0:
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C0ADu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x41C0ADu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7528u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x752Cu);
    cpu->ebx = cpu->ecx;
    cpu->ebx|=cpu->edi; lift_test[0]=cpu->ebx==0u;
    *(uint32_t*)(cpu->esi + 0x7528u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x752Cu) = cpu->edx;
    if (lift_test[0]) goto label_0001C1A1;
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x7530u);
    sub_pred[0] = cpu->ebx < cpu->ecx; cpu->ebx -= cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->ecx -= cpu->edi + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)5u) goto label_0001C132;
    *(float*)(cpu->esp + 0xCu) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0xCu)))))) * (9.999999747378752e-05));
    x87_v0 = 1.100000023841858;
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = std::pow(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esp + 0xCu))) * (((double)*(float*)(cpu->esi + 0x7538u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)(cpu->esi + 0x7538u) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esi);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left<lift_right)) goto label_0001C185; }
    x87_v0 = (double)*(float*)(cpu->esi);
    goto label_0001C17F;
    label_0001C132:
    if ((int32_t)cpu->eax <= (int32_t)0xAu) goto label_0001C185;
    *(float*)(cpu->esp + 0xCu) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0xCu)))))) * (0.00039999998989515007));
    x87_v0 = 0.8999999761581421;
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = std::pow(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esp + 0xCu))) * (((double)*(float*)(cpu->esi + 0x7538u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)(cpu->esi + 0x7538u) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esi + 4u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0001C185; }
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    label_0001C17F:
    *(float*)(cpu->esi + 0x7538u) = x87_v0; 
    label_0001C185:
    x87_v0 = (double)*(float*)(cpu->esi + 0x7538u);
    *(uint32_t*)(cpu->esi + 0x7530u) = 0u;
    x87_v0 = (x87_v0) * (0.699999988079071);
    *(float*)(cpu->esi + 0x7534u) = x87_v0; 
    label_0001C1A1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007CDA0:
    if (g_sfera_texture_cache_runtime.cache_enabled != 0u) goto label_0007CDBE;
    if (g_sfera_window_runtime.windowed == 0u) goto label_0007D03F;
    lift_push32(cpu, 0x64u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7CDB8u));
    label_0007CDBE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CDC3u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x47CDC3u));
    cpu->ecx = cpu->eax;
    cpu->ecx -= g_sfera_grass_map_runtime.last_frame_timestamp.low;
    sub_pred[1] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25) == 0u;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.lighting_state) = cpu->ecx;
    g_sfera_grass_map_runtime.last_frame_timestamp.low = cpu->eax;
    g_sfera_grass_map_runtime.last_frame_timestamp.high = cpu->edx;
    if (sub_pred[1]) goto label_0007CDED;
    x87_v0 = (double)g_sfera_graphics_runtime.saved_fog_distance;
    goto label_0007CDF3;
    label_0007CDED:
    x87_v0 = (double)g_sfera_graphics_runtime.fog_distance;
    label_0007CDF3:
    sub_pred[2] = (uint32_t)(g_sfera_window_runtime.runtime_debug_enabled) == 0u;
    g_sfera_main_input_state_runtime.motion_y = x87_v0; 
    if (!sub_pred[2]) goto label_0007CE0E;
    g_sfera_graphics_runtime.environment_factor = (double)g_sfera_graphics_runtime.view_parameter;
    label_0007CE0E:
    if (g_sfera_view_spatial_runtime.alternate_projection == 0u) goto label_0007CE1C;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CE1Cu)); sfera_sub_0047C980(cpu, LIFT_CODE_TOKEN_RVA(0x7CE1Cu));
    label_0007CE1C:
    x87_v0 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    sub_pred[3] = (uint32_t)(g_sfera_world_render_runtime.feature_toggle) == cpu->ebx;
    lift_push32(cpu, (uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x); lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (sub_pred[3]);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CE41u)); sfera_sub_00457510(cpu, LIFT_CODE_TOKEN_VA(0x47CE41u));
    if ((int32_t)g_sfera_options_dialog_runtime.reflection_quality <= (int32_t)0u) goto label_0007CE58;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 != 0u) goto label_0007CE58;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CE58u)); sfera_sub_0047CBA0(cpu, LIFT_CODE_TOKEN_RVA(0x7CE58u));
    label_0007CE58:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CE63u)); sfera_sub_004DA310(cpu, LIFT_CODE_TOKEN_VA(0x47CE63u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007D033;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CE76u)); sfera_sub_004D8360(cpu, LIFT_CODE_TOKEN_VA(0x47CE76u));
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007CE99;
    if (g_sfera_graphics_runtime.post_effects_enabled != cpu->ebx) goto label_0007CE99;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CE8Eu)); sfera_sub_004DAF50(cpu, LIFT_CODE_TOKEN_VA(0x47CE8Eu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CE99u)); sfera_sub_004DACD0(cpu, LIFT_CODE_TOKEN_RVA(0x7CE99u));
    label_0007CE99:
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = 0u;
    g_sfera_world_render_runtime.scene_active = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEAEu)); sfera_sub_00464600(cpu, LIFT_CODE_TOKEN_VA(0x47CEAEu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEB5u)); sfera_sub_0047C670(cpu, LIFT_CODE_TOKEN_VA(0x47CEB5u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEBAu)); sfera_sub_0044DE30(cpu, LIFT_CODE_TOKEN_VA(0x47CEBAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEC8u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47CEC8u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CED6u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47CED6u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEDBu)); sfera_sub_0045E560(cpu, LIFT_CODE_TOKEN_VA(0x47CEDBu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEEAu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47CEEAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEF9u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x47CEF9u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CF04u)); sfera_sub_004D8360(cpu, LIFT_CODE_TOKEN_VA(0x47CF04u));
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007CF1B;
    if (g_sfera_graphics_runtime.post_effects_enabled != cpu->ebx) goto label_0007CF1B;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CF1Bu)); sfera_sub_004DB030(cpu, LIFT_CODE_TOKEN_RVA(0x7CF1Bu));
    label_0007CF1B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CF20u)); sfera_sub_00451EB0(cpu, LIFT_CODE_TOKEN_VA(0x47CF20u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CF25u)); sfera_sub_0044D5A0(cpu, LIFT_CODE_TOKEN_VA(0x47CF25u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CF2Au)); sfera_sub_0044DF90(cpu, LIFT_CODE_TOKEN_VA(0x47CF2Au));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27 == 0u) goto label_0007CF86;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0007CF85;
    if ((int32_t)cpu->esi >= 0) goto label_0007CF4D;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CF4Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7CF4Du));
    label_0007CF4D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007CF61;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CF61u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7CF61u));
    label_0007CF61:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_saved_controlled_position.x;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = g_sfera_saved_controlled_position.y;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->ecx = g_sfera_saved_controlled_position.z;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    label_0007CF85:
    cpu->esi = lift_pop32(cpu);
    label_0007CF86:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 == 0u) goto label_0007D006;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebx) goto label_0007CFA3;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CFA3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7CFA3u));
    label_0007CFA3:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_34;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = g_sfera_client_main_scalar_runtime.state_35;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_36;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebx) goto label_0007CFDB;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7CFDBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7CFDBu));
    label_0007CFDB:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0];
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1];
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2];
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D006u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_RVA(0x7D006u));
    label_0007D006:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D011u)); sfera_sub_004D8840(cpu, LIFT_CODE_TOKEN_VA(0x47D011u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D016u)); sfera_sub_0044E020(cpu, LIFT_CODE_TOKEN_VA(0x47D016u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    g_sfera_world_render_runtime.scene_active = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D033u)); sfera_sub_004D8880(cpu, LIFT_CODE_TOKEN_RVA(0x7D033u));
    label_0007D033:
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    cpu->ebx = lift_pop32(cpu);
    goto label_0001C0A0;
    label_0007D03F:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047D040(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1;
    (void)stop_address;
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->esi = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_04) = cpu->esi;
    cpu->edi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D067u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x47D067u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    (void)cpu;
    label_0007D070:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D075u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x47D075u));
    cpu->ecx = cpu->eax;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi += cpu->ecx;
    if ((cpu->edi == 0x2710u) || ((int32_t)(cpu->edi) < (int32_t)(0x2710u))) goto label_0007D08A;
    cpu->edi = 0x2710u;
    label_0007D08A:
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->ecx = cpu->edi + 0x1Au;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x4EC4EC4Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ebp = cpu->edx;
    cpu->ebp = cpu->ebp >> 31u;
    cpu->ebp += cpu->edx;
    cpu->edx = cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xFFFFFFCCu);
    cpu->edi += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    if (cpu->ebp != cpu->ebx) goto label_0007D0E5;
    cpu->ecx = 0x34u;
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)0x32u) goto label_0007D0D9;
    cpu->eax = 0x14u;
    goto label_0007D0DD;
    label_0007D0D9:
    if ((int32_t)cpu->eax <= (int32_t)cpu->esi) goto label_0007D0E5;
    label_0007D0DD:
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7D0DFu));
    label_0007D0E5:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D0ECu)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D0ECu));
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_0007D47C;
    label_0007D100:
    cpu->eax = g_sfera_pending_key_runtime.count;
    if (cpu->eax == cpu->ebx) goto label_0007D136;
    cpu->ecx = g_sfera_pending_key_runtime.key_codes[0];
    --cpu->eax;
    g_sfera_world_load_runtime.active_tool_context = cpu->ecx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_0007D131;
    std::memmove((void*)((uintptr_t)&g_sfera_pending_key_runtime.key_codes[0]),(void*)((uintptr_t)&g_sfera_pending_key_runtime.key_codes[1]),(cpu->eax)*4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = 1u;
    label_0007D131:
    g_sfera_pending_key_runtime.count = cpu->eax;
    label_0007D136:
    cpu->eax = g_sfera_scene_control_runtime.context_count;
    if (cpu->eax == cpu->ebx) goto label_0007D16C;
    cpu->edx = g_sfera_scene_control_runtime.context_queue[0];
    --cpu->eax;
    g_sfera_scene_control_runtime.active_context = cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_0007D167;
    std::memmove((void*)((uintptr_t)&g_sfera_scene_control_runtime.context_queue[0]),(void*)((uintptr_t)&g_sfera_scene_control_runtime.context_queue[1]),(cpu->eax)*4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = 1u;
    label_0007D167:
    g_sfera_scene_control_runtime.context_count = cpu->eax;
    label_0007D16C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D171u)); sfera_sub_0044CC70(cpu, LIFT_CODE_TOKEN_VA(0x47D171u));
    g_sfera_recovered_static_runtime.graphics_state = cpu->eax;
    if (cpu->eax != cpu->esi) goto label_0007D186;
    if (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.escape_without_query == cpu->esi) goto label_0007D71A;
    label_0007D186:
    if (g_sfera_input_device_runtime.render_state != cpu->ebx) goto label_0007D735;
    if (cpu->eax != 0x58u) goto label_0007D19F;
    g_sfera_landscape_map_runtime.show_fps = (uint64_t)(g_sfera_landscape_map_runtime.show_fps) ^ (uint64_t)(cpu->esi);
    goto label_0007D1AA;
    label_0007D19F:
    if (cpu->eax != 0x41u) goto label_0007D1AA;
    g_sfera_recovered_static_runtime.client_state_05 = (uint64_t)(g_sfera_recovered_static_runtime.client_state_05) ^ (uint64_t)(cpu->esi);
    label_0007D1AA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D1AFu)); sfera_sub_0044CBF0(cpu, LIFT_CODE_TOKEN_VA(0x47D1AFu));
    cpu->ecx = (uintptr_t)&g_sfera_main_input_state_runtime.cursor_x;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D1B9u)); sfera_sub_00462F00(cpu, LIFT_CODE_TOKEN_VA(0x47D1B9u));
    if (((g_sfera_direct_input_runtime.view_adjust_state) & (0x80u)) == 0u) goto label_0007D226;
    g_sfera_graphics_runtime.view_parameter = (((((((double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x)))))) * (0.0005000000237487257)))) + (((double)g_sfera_graphics_runtime.view_parameter)));
    x87_v0 = 0.0;
    x87_v1 = (double)g_sfera_graphics_runtime.view_parameter;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_0007D1FF; }
    x87_v0 = (x87_v0) + (1.0);
    g_sfera_graphics_runtime.view_parameter = x87_v0; 
    x87_v0 = (double)g_sfera_graphics_runtime.view_parameter;
    label_0007D1FF:
    { const double lift_left=1.0; const double lift_right=x87_v0; if (!(lift_left<=lift_right)) goto label_0007D218; }
    x87_v0 = (x87_v0) - (1.0);
    g_sfera_graphics_runtime.view_parameter = x87_v0; 
    goto label_0007D21A;
    label_0007D218:
    x87_v0 = x87_v0; 
    label_0007D21A:
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y) = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x) = cpu->ebx;
    label_0007D226:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D22Bu)); sfera_sub_00467A70(cpu, LIFT_CODE_TOKEN_VA(0x47D22Bu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_flags;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    cpu->edx = g_sfera_world_load_runtime.active_tool_context;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_scene_control_runtime.active_context;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D249u)); sfera_sub_004BAFB0(cpu, LIFT_CODE_TOKEN_VA(0x47D249u));
    if (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08 != cpu->esi) goto label_0007D2CF;
    if (g_sfera_recovered_static_runtime.interaction_enabled != cpu->ebx) goto label_0007D2CF;
    if (g_sfera_recovered_static_runtime.render_gate != cpu->ebx) goto label_0007D2CF;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 == cpu->ebx) goto label_0007D2C8;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebx) goto label_0007D27D;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D27Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7D27Du));
    label_0007D27D:
    x87_v0 = (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x))));
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx);
    x87_v0 = (x87_v0) * (0.5);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->eax + 8u) = x87_v0; 
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebx) goto label_0007D2AB;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D2ABu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7D2ABu));
    label_0007D2AB:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y))));
    x87_v1 = (x87_v1) * (0.5);
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->eax + 0x10u) = x87_v0; 
    goto label_0007D322;
    label_0007D2C8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D2CDu)); sfera_sub_00476DE0(cpu, LIFT_CODE_TOKEN_VA(0x47D2CDu));
    goto label_0007D322;
    label_0007D2CF:
    x87_v0 = 0.0;
    cpu->ecx = cpu->esp + 0x30u;
    g_sfera_main_view_state_runtime.view_coefficients[5] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[4] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[3] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[2] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[1] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[0] = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.z.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.y.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.x.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.z.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.y.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.x.f32) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D322u)); sfera_sub_00462F00(cpu, LIFT_CODE_TOKEN_RVA(0x7D322u));
    label_0007D322:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D329u)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D329u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D330u)); sfera_sub_004496F0(cpu, LIFT_CODE_TOKEN_VA(0x47D330u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D337u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x47D337u));
    cpu->ecx = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D341u)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D341u));
    if (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08 != cpu->ebx) goto label_0007D358;
    x87_v0 = (double)0.0052083334885537624f;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D358u)); sfera_sub_00479530(cpu, LIFT_CODE_TOKEN_RVA(0x7D358u));
    label_0007D358:
    cpu->ecx = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D362u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x47D362u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax != 4u) goto label_0007D396;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D37Du)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D37Du));
    x87_v0 = (double)0.02083333395421505f;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D38Cu)); sfera_sub_004790C0(cpu, LIFT_CODE_TOKEN_VA(0x47D38Cu));
    cpu->ecx = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D396u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_RVA(0x7D396u));
    label_0007D396:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax != 6u) goto label_0007D3D7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D3AAu)); sfera_sub_004517D0(cpu, LIFT_CODE_TOKEN_VA(0x47D3AAu));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_16 != cpu->ebx) goto label_0007D3D7;
    cpu->ecx = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D3C0u)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D3C0u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D3CD;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D3CDu)); sfera_sub_00429C10(cpu, LIFT_CODE_TOKEN_RVA(0x7D3CDu));
    label_0007D3CD:
    cpu->ecx = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D3D7u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_RVA(0x7D3D7u));
    label_0007D3D7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if (cpu->eax != 6u) goto label_0007D40B;
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    g_sfera_landscape_render_runtime.rotation_step = cpu->eax;
    if (cpu->eax != 0x20u) goto label_0007D401;
    g_sfera_landscape_render_runtime.rotation_step = cpu->ebx;
    label_0007D401:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D406u)); sfera_sub_00456A90(cpu, LIFT_CODE_TOKEN_VA(0x47D406u));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D40Bu)); sfera_sub_00432880(cpu, LIFT_CODE_TOKEN_RVA(0x7D40Bu));
    label_0007D40B:
    cpu->ecx = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D415u)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D415u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D41Au)); sfera_sub_0045EF20(cpu, LIFT_CODE_TOKEN_VA(0x47D41Au));
    cpu->ecx = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D424u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x47D424u));
    x87_v0 = (double)g_sfera_recovered_static_runtime.animation_phase;
    x87_v0 = (x87_v0) + (0.0005000000237487257);
    g_sfera_scene_control_runtime.active_context = cpu->ebx;
    g_sfera_world_load_runtime.active_tool_context = cpu->ebx;
    g_sfera_recovered_static_runtime.animation_phase = x87_v0; 
    x87_v0 = 1.0;
    x87_v1 = (double)g_sfera_recovered_static_runtime.animation_phase;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>lift_right)) goto label_0007D463; }
    x87_v0 = (x87_v0) - (1.0);
    g_sfera_recovered_static_runtime.animation_phase = x87_v0; 
    goto label_0007D465;
    label_0007D463:
    x87_v0 = x87_v0; 
    label_0007D465:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D46Au)); sfera_sub_00451580(cpu, LIFT_CODE_TOKEN_VA(0x47D46Au));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->ebp) goto label_0007D100;
    label_0007D47C:
    cpu->eax = g_sfera_frame_runtime.frame_state;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0007D49D;
    cpu->eax += cpu->esi;
    g_sfera_frame_runtime.frame_state = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D492u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x47D492u));
    g_sfera_frame_runtime.frame_state_anchor.high = cpu->edx;
    g_sfera_frame_runtime.frame_state_anchor.low = cpu->eax;
    label_0007D49D:
    cpu->ecx = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D4A7u)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D4A7u));
    cpu->ecx = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D4B1u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x47D4B1u));
    cpu->ecx = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D4BBu)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D4BBu));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D5D4;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == cpu->ebx) goto label_0007D528;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->esi) goto label_0007D4E3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D4E3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7D4E3u));
    label_0007D4E3:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)300.0f;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->edx + 0xCu));  if (!(lift_left<lift_right)) goto label_0007D528; }
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->esi) goto label_0007D510;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D510u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7D510u));
    label_0007D510:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    { const double lift_left=(double)*(float*)(cpu->ecx + 0xCu); const double lift_right=800.0; if (lift_left<lift_right) goto label_0007D544; }
    label_0007D528:
    x87_v0 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.environment_lookup_result); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D53Cu)); sfera_sub_00433E10(cpu, LIFT_CODE_TOKEN_VA(0x47D53Cu));
    cpu->ecx = g_sfera_weather_runtime.standard_object;
    if (cpu->ecx == 0u) cpu->ecx = g_sfera_weather_runtime.highres_object;
    goto label_0007D55E;
    label_0007D544:
    x87_v0 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.environment_lookup_result); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D558u)); sfera_sub_00433E10(cpu, LIFT_CODE_TOKEN_VA(0x47D558u));
    cpu->ecx = g_sfera_weather_runtime.highres_object;
    if (cpu->ecx == 0u) cpu->ecx = g_sfera_weather_runtime.standard_object;
    label_0007D55E:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D564u)); sfera_sub_0049CC90(cpu, LIFT_CODE_TOKEN_VA(0x47D564u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10 != cpu->esi) goto label_0007D5C8;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11 <= (int32_t)cpu->ebx) goto label_0007D589;
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x47D574u));
    cpu->ecx = cpu->esi + cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D581u)); sfera_sub_004982F0(cpu, LIFT_CODE_TOKEN_VA(0x47D581u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11) = cpu->ebx;
    goto label_0007D59D;
    label_0007D589:
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x47D589u));
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D597u)); sfera_sub_004982F0(cpu, LIFT_CODE_TOKEN_VA(0x47D597u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11) = cpu->esi;
    label_0007D59D:
    g_sfera_client_config_runtime.scalar_01 = ((((double)g_sfera_client_config_runtime.scalar_01)) + (1.0));
    { const double lift_left=(double)g_sfera_client_config_runtime.scalar_01; const double lift_right=50.0; if (!(lift_left>lift_right)) goto label_0007D5C8; }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10) = cpu->ebx;
    label_0007D5C8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D5CDu)); sfera_sub_0047CDA0(cpu, LIFT_CODE_TOKEN_VA(0x47D5CDu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D5D2u)); sfera_sub_00499EE0(cpu, LIFT_CODE_TOKEN_VA(0x47D5D2u));
    goto label_0007D635;
    label_0007D5D4:
    if (g_sfera_texture_cache_runtime.cache_enabled != cpu->ebx) goto label_0007D5EC;
    if (g_sfera_window_runtime.windowed == cpu->ebx) goto label_0007D635;
    lift_push32(cpu, 0x64u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7D5E6u));
    label_0007D5EC:
    x87_v0 = 1.0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D607u)); sfera_sub_004D87E0(cpu, LIFT_CODE_TOKEN_VA(0x47D607u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D612u)); sfera_sub_004DA310(cpu, LIFT_CODE_TOKEN_VA(0x47D612u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007D635;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D61Bu)); sfera_sub_0044DF90(cpu, LIFT_CODE_TOKEN_VA(0x47D61Bu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D626u)); sfera_sub_004D8840(cpu, LIFT_CODE_TOKEN_VA(0x47D626u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D635u)); sfera_sub_004D8880(cpu, LIFT_CODE_TOKEN_RVA(0x7D635u));
    label_0007D635:
    cpu->ecx = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D63Fu)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x47D63Fu));
    cpu->ecx = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D649u)); sfera_sub_0049A690(cpu, LIFT_CODE_TOKEN_VA(0x47D649u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D656;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D656u)); sfera_sub_00497ED0(cpu, LIFT_CODE_TOKEN_RVA(0x7D656u));
    label_0007D656:
    cpu->ecx = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D660u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x47D660u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D665u)); sfera_sub_0044C160(cpu, LIFT_CODE_TOKEN_VA(0x47D665u));
    if ((uint32_t)(g_sfera_render_lookup_runtime.initialized) == cpu->esi) goto label_0007D752;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D678u)); sfera_sub_0049A6D0(cpu, LIFT_CODE_TOKEN_VA(0x47D678u));
    sub_pred[0] = (uint32_t)((uint64_t)(g_sfera_profiler_runtime.accumulated_ticks[0].high)) == cpu->ebx; sub_pred[1] = (int32_t)((uint32_t)((uint64_t)(g_sfera_profiler_runtime.accumulated_ticks[0].high))) < (int32_t)(cpu->ebx);
    if ((int32_t)((uint32_t)((uint64_t)(g_sfera_profiler_runtime.accumulated_ticks[0].high))) < (int32_t)(cpu->ebx)) goto label_0007D070;
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_0007D696;
    if ((uint32_t)(g_sfera_profiler_runtime.accumulated_ticks[0].low) <= 0xF4240u) goto label_0007D070;
    label_0007D696:
    cpu->ebp = 0u;
    cpu->esi = 1u;
    cpu->edi = (uintptr_t)&g_sfera_profiler_runtime.report_percent[1];
    label_0007D6B0:
    cpu->edx = g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].high;
    cpu->eax = g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].low;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D6C8u)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x47D6C8u));
    lift_push32(cpu, g_sfera_profiler_runtime.accumulated_ticks[0].high); lift_push32(cpu, g_sfera_profiler_runtime.accumulated_ticks[0].low); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D6DBu)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x47D6DBu));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].low = cpu->ebx;
    g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].high = cpu->ebx;
    cpu->edi += 4u;
    cpu->ebp += cpu->eax;
    ++cpu->esi;
    if ((int32_t)cpu->edi <= (int32_t)((uintptr_t)&g_sfera_profiler_runtime.report_percent[8])) goto label_0007D6B0;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_profiler_runtime.report_percent[0])) = cpu->ebp;
    g_sfera_profiler_runtime.accumulated_ticks[0].low = cpu->ebx;
    g_sfera_profiler_runtime.accumulated_ticks[0].high = cpu->ebx;
    cpu->esi = 1u;
    goto label_0007D070;
    label_0007D71A:
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D724u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x47D724u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D729u)); sfera_sub_0049A730(cpu, LIFT_CODE_TOKEN_VA(0x47D729u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D72Eu)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x47D72Eu));
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x7D72Fu));
    label_0007D735:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x13u));
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x17u;
    lift_push32(cpu, cpu->edx);
    g_sfera_input_device_runtime.render_state = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Bu) = cpu->ecx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D752u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x7D752u));
    label_0007D752:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D757u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x47D757u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D75Cu)); sfera_sub_0042EB70(cpu, LIFT_CODE_TOKEN_VA(0x47D75Cu));
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_VA(0x47D75Du));
    lift_trap(cpu, 0x47D763u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0047D770(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_p0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x47D773u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetThreadAffinityMask), LIFT_CODE_TOKEN_VA(0x47D77Au));
    cpu->ecx = LIFT_CALLBACK(sfera_sub_0044D7E0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D78Au)); sfera_sub_004EC1C0(cpu, LIFT_CODE_TOKEN_VA(0x47D78Au));
    cpu->ecx = LIFT_CALLBACK(sfera_sub_00434D50);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D794u)); sfera_sub_004EBF20(cpu, LIFT_CODE_TOKEN_VA(0x47D794u));
    const uint32_t launch_guard = (uintptr_t)"/15FCE220-0246-58ec-3EH2-968B3072ACF8";
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_strstr_address32();
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, launch_guard); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7D7C4u), LIFT_CODE_TOKEN_RVA(0x7D7C2u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0007D7E5;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340 \347\340\357\363\361\352\340."); lift_push32(cpu, (uintptr_t)"\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 Sphere.exe."); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x47D7D7u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0007D7E5:
    cpu->eax = 0u;
    lift_push32(cpu, (uintptr_t)"/locale"); lift_push32(cpu, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_process_runtime.locale[0]) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_client_process_runtime.locale[4]) = cpu->eax;
    (*(uint16_t*)(void*)&g_sfera_client_process_runtime.locale[8]) = cpu->eax & 0xFFFFu;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7D7FFu), LIFT_CODE_TOKEN_RVA(0x7D7FDu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0007D845;
    cpu->eax += 7u;
    label_0007D810:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D81C;
    if ((cpu->ecx & 0xFFu) != 9u) goto label_0007D81F;
    label_0007D81C:
    ++cpu->eax;
    goto label_0007D810;
    label_0007D81F:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = 0u;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D845;
    label_0007D828:
    if ((cpu->ecx & 0xFFu) == 9u) goto label_0007D845;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0007D845;
    if ((int32_t)cpu->edx >= (int32_t)0xAu) goto label_0007D845;
    ++cpu->eax;
    *(uint8_t*)(cpu->edx + ((uintptr_t)&g_sfera_client_process_runtime.locale[0])) = cpu->ecx & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0007D828;
    label_0007D845:
    lift_push32(cpu, (uintptr_t)"/login"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7D84Du), LIFT_CODE_TOKEN_RVA(0x7D84Bu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0007D85D;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.gamexp_sid_present) = 1u;
    goto label_0007D8B4;
    label_0007D85D:
    lift_push32(cpu, (uintptr_t)"/gamexp_sid"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7D865u), LIFT_CODE_TOKEN_RVA(0x7D863u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0007D9A0;
    cpu->eax += 0xBu;
    label_0007D873:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D87F;
    if ((cpu->ecx & 0xFFu) != 9u) goto label_0007D882;
    label_0007D87F:
    ++cpu->eax;
    goto label_0007D873;
    label_0007D882:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = 0u;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D8AD;
    label_0007D890:
    if ((cpu->ecx & 0xFFu) == 9u) goto label_0007D8AD;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0007D8AD;
    if ((int32_t)cpu->edx >= (int32_t)0x1Eu) goto label_0007D8AD;
    ++cpu->eax;
    *(uint8_t*)(cpu->edx + ((uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0])) = cpu->ecx & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0007D890;
    label_0007D8AD:
    *(uint8_t*)(cpu->edx + ((uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0])) = 0u;
    label_0007D8B4:
    cpu->ecx = (uintptr_t)"connect.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D8BEu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x47D8BEu));
    if (cpu->eax != 0u) goto label_0007D8ED;
    cpu->edx = cpu->esp + 8u;
    cpu->ecx = (uintptr_t)"CONNECT_TYPE";
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D8D4u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x47D8D4u));
    if (cpu->eax != 0u) goto label_0007D8E6;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 8u) == 1u;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) = 1u;
    if (sub_pred[0]) goto label_0007D8ED;
    label_0007D8E6:
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) = 0u;
    label_0007D8ED:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D8F4u)); sfera_sub_0042E920(cpu, LIFT_CODE_TOKEN_VA(0x47D8F4u));
    cpu->esi = native_function_address32(&::InitializeCriticalSection);
    lift_push32(cpu, (uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7D901u), LIFT_CODE_TOKEN_RVA(0x7D8FFu))) { return; }
    lift_push32(cpu, (uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7D908u), LIFT_CODE_TOKEN_RVA(0x7D906u))) { return; }
    lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x7D90Fu), LIFT_CODE_TOKEN_RVA(0x7D90Du))) { return; }
    cpu->ebp = native_function_address32(&::CreateFileA);
    cpu->ebx = native_function_address32(&::CreateDirectoryA);
    cpu->edi = 0u;
    label_0007D920:
    cpu->esi = (uintptr_t)(cpu->edi == 0u ? ".\\logs" : ".\\players");
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x7D935u), LIFT_CODE_TOKEN_RVA(0x7D933u))) { return; }
    if (cpu->eax != 0xFFFFFFFFu) goto label_0007D941;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7D93Fu), LIFT_CODE_TOKEN_RVA(0x7D93Du))) { return; }
    goto label_0007D948;
    label_0007D941:
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x7D942u));
    label_0007D948:
    cpu->edi += 4u;
    if (cpu->edi < 8u) goto label_0007D920;
    x87_p0 = 0.30000001192092896;
    cpu->esp -= 0x10u;
    *(double*)(cpu->esp + 8u) = x87_p0;
    x87_p0 = 1.0;
    *(double*)(cpu->esp) = x87_p0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D967u)); sfera_sub_0044EBC0(cpu, LIFT_CODE_TOKEN_VA(0x47D967u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = (uintptr_t)&g_sfera_startup_command_line_runtime.text[0];
    cpu->ebp = lift_pop32(cpu);
    g_sfera_startup_command_line_runtime.parser_state = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_0007D987:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0007D987;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D996u)); sfera_sub_00464BA0(cpu, LIFT_CODE_TOKEN_VA(0x47D996u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D99Bu)); sfera_sub_0045BC60(cpu, LIFT_CODE_TOKEN_VA(0x47D99Bu));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D9A0u)); sfera_sub_0047D040(cpu, LIFT_CODE_TOKEN_RVA(0x7D9A0u));
    label_0007D9A0:
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340 \347\340\357\363\361\352\340"); lift_push32(cpu, (uintptr_t)"\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 launchpoint.exe."); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x47D9AEu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047D9C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"BM"));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint16_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFFFu;
    cpu->ebx = cpu->edi + (cpu->edi * 2u);
    cpu->eax = cpu->ebx + 3u;
    cpu->eax &= 0xFFFFFFFCu;
    cpu->edx = cpu->eax;
    cpu->esi = cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"BM") + 2u));
    *(uint8_t*)(cpu->esp + 0x12u) = cpu->ecx & 0xFFu;
    cpu->ecx = cpu->edx + 0x39u;
    cpu->ecx &= 0xFFFFFFFCu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->ecx -= cpu->edx;
    cpu->ecx -= 0x36u;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA15u)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x47DA15u));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA25u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DA25u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA33u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DA33u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->ebx = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA47u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DA47u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x36u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA5Du)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DA5Du));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA73u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DA73u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA85u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DA85u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DA97u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DA97u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DAADu)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DAADu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DAC3u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DAC3u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DAD5u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DAD5u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DAE3u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DAE3u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xB12u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DAF9u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DAF9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DB07u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DB07u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DB19u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DB19u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DB27u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x47DB27u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047DB30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x4Eu);
    cpu->edx = (uintptr_t)"MapGenerator.cpp";
    cpu->ecx = 0xC0000u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DB44u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47DB44u));
    lift_push32(cpu, 0x2000u);
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DB5Du)); sfera_sub_0047D9C0(cpu, LIFT_CODE_TOKEN_VA(0x47DB5Du));
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047DB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DB92u)); sfera_sub_004815D0(cpu, LIFT_CODE_TOKEN_VA(0x47DB92u));
    cpu->eax = *(uint32_t*)((uintptr_t)"xadd\\matbase");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"xadd\\matbase") + 4u);
    cpu->edx = *(uint32_t*)(((uintptr_t)"xadd\\matbase") + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"xadd\\matbase") + 0xCu));
    *(uint8_t*)(cpu->esp + 0x30u) = cpu->eax & 0xFFu;
    cpu->ebp = 0u;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x31u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x35u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x39u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Du) = cpu->eax;
    *(uint16_t*)(cpu->esp + 0x41u) = cpu->eax & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0x43u) = cpu->eax & 0xFFu;
    cpu->eax = (uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->ecx = cpu->eax;
    label_0007DBE0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007DBE0;
    cpu->edi = cpu->esp + 0x24u;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0007DBF0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007DBF0;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x24u;
    --cpu->eax;
    label_0007DC10:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007DC10;
    cpu->ecx = *(uint32_t*)((uintptr_t)".dat");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".dat") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DC2Eu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x47DC2Eu));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DC37u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x47DC37u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DC3Eu)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x47DC3Eu));
    *(uint32_t*)(cpu->ebx) = cpu->ebp;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0007E0D3;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->ebx) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DC58u)); sfera_sub_00482170(cpu, LIFT_CODE_TOKEN_VA(0x47DC58u));
    cpu->edx = (uintptr_t)"words";
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DC68u)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x47DC68u));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0007DC7A;
    cpu->ecx = (uintptr_t)"CMatFilter::CMatFilter: \354\340\361\361\350\342 words \355\345 \355\340\351\344\345\355 \342 matbase.dat";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7DC7Au)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7DC7Au));
    label_0007DC7A:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 8u) <= (int32_t)cpu->ebp) goto label_0007DD44;
    label_0007DC90:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"words";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DCA3u)); sfera_sub_00481300(cpu, LIFT_CODE_TOKEN_VA(0x47DCA3u));
    cpu->ecx = cpu->esp + 0x10u;
    cpu->ebp = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"w";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DCB6u)); sfera_sub_00481180(cpu, LIFT_CODE_TOKEN_VA(0x47DCB6u));
    if (cpu->eax != 0u) goto label_0007DCC4;
    cpu->ecx = (uintptr_t)"CMatFilter::CMatFilter: field 'w' absent in one of array's elements";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7DCC4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7DCC4u));
    label_0007DCC4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + 1u;
    label_0007DCD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007DCD0;
    cpu->eax -= cpu->edx;
    cpu->edx = (uintptr_t)"e";
    cpu->ecx = cpu->ebp;
    cpu->edi = cpu->edi + cpu->eax + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DCE9u)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x47DCE9u));
    cpu->ebx = cpu->eax;
    cpu->esi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0007DD2A;
    label_0007DCF1:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uintptr_t)"e";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DD03u)); sfera_sub_004812A0(cpu, LIFT_CODE_TOKEN_VA(0x47DD03u));
    if (cpu->eax != 0u) goto label_0007DD11;
    cpu->ecx = (uintptr_t)"CMatFilter::CMatFilter: error reading exceptions";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7DD11u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7DD11u));
    label_0007DD11:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + 1u;
    label_0007DD18:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007DD18;
    cpu->eax -= cpu->edx;
    ++cpu->esi;
    cpu->edi = cpu->edi + cpu->eax + 1u;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_0007DCF1;
    label_0007DD2A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx + 8u)) goto label_0007DC90;
    cpu->ebp = 0u;
    cpu->ebx = cpu->ecx;
    label_0007DD44:
    lift_push32(cpu, 0x55u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DD55u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47DD55u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x56u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    *(uint32_t*)(cpu->ebx + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DD6Bu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47DD6Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x57u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    *(uint32_t*)(cpu->ebx + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DD81u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47DD81u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x58u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    *(uint32_t*)(cpu->ebx + 0x14u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DD97u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47DD97u));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->ebx + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 8u) <= (int32_t)cpu->ebp) goto label_0007DEED;
    label_0007DDB0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"words";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DDC3u)); sfera_sub_00481300(cpu, LIFT_CODE_TOKEN_VA(0x47DDC3u));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"w";
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DDD8u)); sfera_sub_00481180(cpu, LIFT_CODE_TOKEN_VA(0x47DDD8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += cpu->esi;
    label_0007DDE5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->edx;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007DDE5;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    *(uint32_t*)(cpu->ecx + cpu->ebp) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->edx += cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"t";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DE17u)); sfera_sub_00481120(cpu, LIFT_CODE_TOKEN_VA(0x47DE17u));
    if (cpu->eax != 0u) goto label_0007DE25;
    cpu->ecx = (uintptr_t)"CMatFilter::CMatFilter: field 't' absent in one of array's elements";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7DE25u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7DE25u));
    label_0007DE25:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + 1u;
    label_0007DE30:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007DE30;
    cpu->eax -= cpu->edx;
    cpu->edx = (uintptr_t)"e";
    cpu->ecx = cpu->ebx;
    cpu->esi = cpu->esi + cpu->eax + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DE49u)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x47DE49u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_0007DE5C;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + cpu->ebp) = 0u;
    goto label_0007DED7;
    label_0007DE5C:
    lift_push32(cpu, 0x6Bu);
    cpu->ecx = (cpu->ebx * 4u) + 4u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DE6Fu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47DE6Fu));
    cpu->ecx = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    *(uint32_t*)(cpu->edx + cpu->ebp) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebp);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    if ((int32_t)cpu->ebx <= 0) goto label_0007DED7;
    label_0007DE85:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->edx = (uintptr_t)"e";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DE99u)); sfera_sub_004812A0(cpu, LIFT_CODE_TOKEN_VA(0x47DE99u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += cpu->esi;
    label_0007DEA6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->edx;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007DEA6;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ebp);
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u) + 4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + 1u;
    label_0007DEC5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007DEC5;
    cpu->eax -= cpu->edx;
    ++cpu->edi;
    cpu->esi = cpu->esi + cpu->eax + 1u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_0007DE85;
    label_0007DED7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx + 8u)) goto label_0007DDB0;
    label_0007DEED:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DEF6u)); sfera_sub_004815C0(cpu, LIFT_CODE_TOKEN_VA(0x47DEF6u));
    cpu->eax = 0u;
    cpu->esi = cpu->eax + 0x20u;
    label_0007DF00:
    if ((int32_t)cpu->eax < (int32_t)0x41u) goto label_0007DF0A;
    if ((int32_t)cpu->eax <= (int32_t)0x5Au) goto label_0007DF39;
    label_0007DF0A:
    if ((int32_t)cpu->eax < (int32_t)0x61u) goto label_0007DF14;
    if ((int32_t)cpu->eax <= (int32_t)0x7Au) goto label_0007DF39;
    label_0007DF14:
    if ((int32_t)cpu->eax >= (int32_t)0xC0u) goto label_0007DF39;
    if (cpu->eax == 0xA8u) goto label_0007DF39;
    if (cpu->eax == 0xB8u) goto label_0007DF39;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0])) = cpu->esi;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0])) = cpu->esi;
    goto label_0007DF6E;
    label_0007DF39:
    cpu->edi = cpu->eax + 0xFFFFFFBFu;
    cpu->ecx = cpu->eax;
    if (cpu->edi > 0x19u) goto label_0007DF46;
    cpu->ecx = cpu->eax + 0x20u;
    label_0007DF46:
    cpu->edx = cpu->ecx + 0xFFFFFF40u;
    if (cpu->edx > 0x1Fu) goto label_0007DF53;
    cpu->ecx += cpu->esi;
    label_0007DF53:
    if (cpu->ecx != 0xA8u) goto label_0007DF60;
    cpu->ecx = 0xB8u;
    label_0007DF60:
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0])) = cpu->ecx;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0])) = cpu->ecx;
    label_0007DF6E:
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x100u) goto label_0007DF00;
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
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007E0D3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E0F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 8u) <= (int32_t)cpu->edi) goto label_0007E12D;
    label_0007E100:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    sub_pred[0] = *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == 0u;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    if (sub_pred[0]) goto label_0007E127;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0xB8u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E11Du)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47E11Du));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) = 0u;
    label_0007E127:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_0007E100;
    label_0007E12D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    lift_push32(cpu, 0xB9u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E13Fu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47E13Fu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, 0xBAu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E151u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47E151u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, 0xBBu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E163u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47E163u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, 0xBCu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E175u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47E175u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E180(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = *(uint32_t*)(cpu->ecx + 4u) == 0u;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0];
    if (sub_pred[0]) goto label_0007E190;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0];
    label_0007E190:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (*(uint8_t*)(cpu->eax) == 0u) goto label_0007E1AE;
    label_0007E1A0:
    cpu->edx = *(uint8_t*)(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + (cpu->edx * 4u)));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax) != 0u) goto label_0007E1A0;
    label_0007E1AE:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E1C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)*(uint32_t*)(cpu->edi + 8u) <= (int32_t)cpu->esi) goto label_0007E468;
    label_0007E1E0:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->eax += *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    label_0007E1F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    ++cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E1F0;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0];
    if (*(uint32_t*)(cpu->edi + 4u) == 0u) goto label_0007E20A;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0];
    label_0007E20A:
    if (((uint8_t)g_sfera_material_filter_runtime.filter_word[0]) == 0u) goto label_0007E226;
    cpu->eax = (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    label_0007E218:
    cpu->edx = *(uint8_t*)(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + (cpu->edx * 4u)));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax) != 0u) goto label_0007E218;
    label_0007E226:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->eax > 4u) goto label_0007E45A;
    switch (cpu->eax) {
        case 0u: goto label_0007E23C;
        case 1u: goto label_0007E279;
        case 2u: goto label_0007E29B;
        case 3u: goto label_0007E2BD;
        case 4u: goto label_0007E301;
        default: lift_trap(cpu, 0x47E235u, "resolved jump-table index out of range"); return;
    }
label_0007E23C: ;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    label_0007E247:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0007E267;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0007E263;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0007E267;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007E247;
    label_0007E263:
    cpu->eax = 0u;
    goto label_0007E26C;
    label_0007E267:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_0007E26C:
    if (cpu->eax == 0u) goto label_0007E364;
    goto label_0007E45A;
    label_0007E279:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E283u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp != 0u) goto label_0007E364;
    goto label_0007E45A;
    label_0007E29B:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E2A5u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp == cpu->ebx) goto label_0007E364;
    goto label_0007E45A;
    label_0007E2BD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E2C7u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp == 0u) goto label_0007E45A;
    if (cpu->ebp == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0007E364;
    cpu->eax = sfera_cp1251_is_russian_vowel_or_sign(*(uint8_t*)(cpu->ebp + 0xFFFFFFFFu));
    if (cpu->eax == 0u) goto label_0007E45A;
    goto label_0007E364;
    label_0007E301:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E30Bu));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp != cpu->ebx) goto label_0007E45A;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_0007E323:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E323;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    cpu->eax = (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    cpu->esi = cpu->eax + 1u;
    label_0007E336:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E336;
    cpu->eax -= cpu->esi;
    if (cpu->edx == cpu->eax) goto label_0007E360;
    cpu->ecx = cpu->ebx;
    cpu->eax = sfera_cp1251_is_russian_vowel_or_sign(*(uint8_t*)(cpu->eax + cpu->ecx));
    if (cpu->eax == 0u) goto label_0007E456;
    label_0007E360:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0007E364:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x18u);
    if (*(uint32_t*)(cpu->edx + (cpu->esi * 4u)) == 0u) goto label_0007E474;
    cpu->ebx = 0u;
    label_0007E373:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if ((int32_t)cpu->ebx >= (int32_t)*(uint32_t*)(cpu->eax)) goto label_0007E474;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u) + 4u);
    cpu->ecx = cpu->ecx + cpu->edx + 1u;
    cpu->edx = (uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0];
    label_0007E391:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0007E391;
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0]);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E3A7u)); sfera_sub_0047E180(cpu, LIFT_CODE_TOKEN_VA(0x47E3A7u));
    cpu->eax = (uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0];
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0007E3B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E3B0;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->eax -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 4u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->ecx + cpu->edx));
    if ((cpu->ecx -= 0x30u) == 0u) goto label_0007E420;
    if ((--cpu->ecx) != 0u) goto label_0007E450;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    cpu->esi = cpu->ecx + 1u;
    label_0007E3E0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007E3E0;
    cpu->ecx -= cpu->esi;
    cpu->esi = cpu->ecx + cpu->ebp;
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->ecx + 1u;
    label_0007E3F1:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007E3F1;
    cpu->ecx -= cpu->edi;
    if ((int32_t)cpu->ecx < (int32_t)cpu->eax) goto label_0007E448;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x47E405u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0007E45A;
    ++cpu->ebx;
    goto label_0007E373;
    label_0007E420:
    cpu->ecx = cpu->ebp;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ecx < (int32_t)cpu->eax) goto label_0007E450;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp;
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0]); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x47E435u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0007E45A;
    ++cpu->ebx;
    goto label_0007E373;
    label_0007E448:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0007E450:
    ++cpu->ebx;
    goto label_0007E373;
    label_0007E456:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0007E45A:
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 8u)) goto label_0007E1E0;
    label_0007E468:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0007E474:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E4A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    cpu->edx = cpu->eax + 1u;
    label_0007E4B3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E4B3;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x1000u);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47E4CAu));
    cpu->esp += 0xCu;
    cpu->ebp = 0u;
    cpu->eax = cpu->esi;
    cpu->edi -= cpu->esi;
    label_0007E4D8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) != 0x3Cu) goto label_0007E4EA;
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    *(uint8_t*)(cpu->edi + cpu->eax) = 0x20u;
    goto label_0007E4FA;
    label_0007E4EA:
    if (*(uint8_t*)(cpu->esp + 0x13u) != 1u) goto label_0007E4F7;
    *(uint8_t*)(cpu->edi + cpu->eax) = 0x20u;
    goto label_0007E4FA;
    label_0007E4F7:
    *(uint8_t*)(cpu->edi + cpu->eax) = cpu->ecx & 0xFFu;
    label_0007E4FA:
    if (*(uint8_t*)(cpu->eax) != 0x3Eu) goto label_0007E504;
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    label_0007E504:
    ++cpu->ebp;
    ++cpu->eax;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ebx) goto label_0007E4D8;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E520(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = (uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->edx -= cpu->eax;
    label_0007E538:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E538;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0];
    if (*(uint32_t*)(cpu->esi + 4u) == cpu->ebp) goto label_0007E551;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0];
    label_0007E551:
    if (((uint8_t)g_sfera_material_filter_runtime.normalized_input[0]) == 0u) goto label_0007E56E;
    cpu->eax = (uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    (void)cpu;
    label_0007E560:
    cpu->edx = *(uint8_t*)(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + (cpu->edx * 4u)));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax) != 0u) goto label_0007E560;
    label_0007E56E:
    cpu->eax = (uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    cpu->esi = 0u;
    --cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    label_0007E580:
    if (cpu->esi == 0u) goto label_0007E58E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->edx & 0xFFu) == *(uint8_t*)((uintptr_t)&g_sfera_material_filter_runtime.normalized_input[cpu->esi - 1u])) goto label_0007E597;
    label_0007E58E:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + ((uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0])) = cpu->edx & 0xFFu;
    ++cpu->esi;
    label_0007E597:
    ++cpu->eax;
    ++cpu->ecx;
    if (*(uint8_t*)(cpu->eax) != 0u) goto label_0007E580;
    cpu->eax = (uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    cpu->edi = (uintptr_t)&g_sfera_material_filter_runtime.token_starts[0];
    cpu->esi = 0u;
    label_0007E5B0:
    if (*(uint8_t*)(cpu->eax) != 0x20u) goto label_0007E5BB;
    label_0007E5B5:
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax) == 0x20u) goto label_0007E5B5;
    label_0007E5BB:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E5C5;
    cpu->ecx = 0u;
    goto label_0007E5E6;
    label_0007E5C5:
    cpu->edx = 0u;
    cpu->ebx = cpu->eax;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007E5DE;
    label_0007E5D0:
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0007E5DE;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    ++cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0007E5D0;
    label_0007E5DE:
    *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0])) = cpu->edx;
    cpu->ecx = cpu->ebx;
    label_0007E5E6:
    cpu->eax = *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0]));
    ++cpu->ebp;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->esi = cpu->ebp * 4u;
    cpu->edi = cpu->esi + ((uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]);
    cpu->eax += cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0xFFFFFFFCu) != 0u) goto label_0007E5B0;
    --cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if (cpu->ebp == 0u) goto label_0007E6E2;
    if (((uint8_t)g_sfera_material_filter_runtime.normalized_input[0]) == 0u) goto label_0007E62E;
    cpu->eax = (uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    label_0007E620:
    if (*(uint8_t*)(cpu->eax) != 0x20u) goto label_0007E628;
    *(uint8_t*)(cpu->eax) = 0u;
    label_0007E628:
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax) != 0u) goto label_0007E620;
    label_0007E62E:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = 0u;
    if ((int32_t)cpu->esi <= 0) goto label_0007E6E2;
    label_0007E640:
    cpu->eax = *(uint32_t*)((cpu->ebp * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E651u)); sfera_sub_0047E1C0(cpu, LIFT_CODE_TOKEN_VA(0x47E651u));
    if (cpu->eax != 0u) goto label_0007E6EC;
    cpu->eax = *(uint32_t*)((cpu->ebp * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]));
    cpu->edx = (uintptr_t)&g_sfera_material_filter_runtime.match_buffer[0];
    cpu->edx -= cpu->eax;
    label_0007E667:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E667;
    if ((int32_t)*(uint32_t*)((cpu->ebp * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0])) > (int32_t)3u) goto label_0007E6D5;
    cpu->ebx = cpu->ebp + 1u;
    if ((int32_t)cpu->ebx >= (int32_t)cpu->esi) goto label_0007E6D5;
    label_0007E682:
    if ((int32_t)*(uint32_t*)((cpu->ebx * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0])) > (int32_t)3u) goto label_0007E6D5;
    cpu->eax = *(uint32_t*)((cpu->ebx * 4u) + ((uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]));
    cpu->ecx = cpu->eax;
    label_0007E695:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007E695;
    cpu->edi = (uintptr_t)&g_sfera_material_filter_runtime.match_buffer[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0007E6A6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007E6A6;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.match_buffer[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E6CAu)); sfera_sub_0047E1C0(cpu, LIFT_CODE_TOKEN_VA(0x47E6CAu));
    if (cpu->eax != 0u) goto label_0007E6EC;
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x18u)) goto label_0007E682;
    label_0007E6D5:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->esi) goto label_0007E640;
    label_0007E6E2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0007E6EC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.tag_stripped_input[0]); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E712u)); sfera_sub_0047E4A0(cpu, LIFT_CODE_TOKEN_VA(0x47E712u));
    if (*(uint32_t*)(cpu->esi) != 0u) goto label_0007E71D;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0007E71D:
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.tag_stripped_input[0]);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E730u)); sfera_sub_0047E520(cpu, LIFT_CODE_TOKEN_VA(0x47E730u));
    if (cpu->eax == 0u) goto label_0007E73D;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0007E73D:
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.tag_stripped_input[0]);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E750u)); sfera_sub_0047E520(cpu, LIFT_CODE_TOKEN_VA(0x47E750u));
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E760(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_0007E772:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007E772;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((int32_t)cpu->edx <= 0) goto label_0007E82E;
    label_0007E790:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->ebp));
    if ((cpu->ecx & 0xFFu) == 0x2Du) goto label_0007E7E6;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007E7E6;
    if ((cpu->ecx & 0xFFu) == 0x5Fu) goto label_0007E7E6;
    if ((cpu->ecx & 0xFFu) < 0x30u) goto label_0007E7AC;
    if ((cpu->ecx & 0xFFu) <= 0x39u) goto label_0007E7E6;
    label_0007E7AC:
    if ((cpu->ecx & 0xFFu) < 0x61u) goto label_0007E7B6;
    if ((cpu->ecx & 0xFFu) <= 0x7Au) goto label_0007E7BD;
    label_0007E7B6:
    cpu->eax = cpu->ecx + 0xFFFFFFBFu;
    if ((cpu->eax & 0xFFu) > 0x19u) goto label_0007E7CA;
    label_0007E7BD:
    cpu->eax = 1u;
    lift_test[0]=cpu->edi==0u; lift_test[1]=((cpu->edi)&0x80000000u)!=0u;
    if (cpu->edi!=0u) goto label_0007E7EA;
    cpu->edi = cpu->eax;
    goto label_0007E825;
    label_0007E7CA:
    if ((cpu->ecx & 0xFFu) >= 0xC0u) goto label_0007E7D9;
    if ((cpu->ecx & 0xFFu) == 0xB8u) goto label_0007E7D9;
    if ((cpu->ecx & 0xFFu) != 0xA8u) goto label_0007E838;
    label_0007E7D9:
    cpu->eax = 2u;
    lift_test[0]=cpu->edi==0u; lift_test[1]=((cpu->edi)&0x80000000u)!=0u;
    if (cpu->edi!=0u) goto label_0007E7EA;
    cpu->edi = cpu->eax;
    goto label_0007E825;
    label_0007E7E6:
    cpu->eax = 0u;
    lift_test[0]=cpu->edi==0u; lift_test[1]=((cpu->edi)&0x80000000u)!=0u;
    label_0007E7EA:
    if ((lift_test[0]) || (lift_test[1])) goto label_0007E825;
    if (cpu->edi == cpu->eax) goto label_0007E825;
    if (sfera_identifier_char_is_keyboard_ambiguous((uint8_t)cpu->ecx)) { goto label_0007E838; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    label_0007E825:
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->edx) goto label_0007E790;
    label_0007E82E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007E838:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E850(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->edx < 0xEu) goto label_0007E863;
    if (*(uint32_t*)(cpu->ecx) != 0x52485053u) goto label_0007E863;
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007E863:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if (cpu->ebp < 0xEu) goto label_0007E8F2;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"SPHR"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x47E88Du));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0007E8F2;
    if (*(uint32_t*)(cpu->edi) != cpu->eax) goto label_0007E8BA;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xEu));
    *(uint8_t*)(cpu->edi) = (uint64_t)(*(uint8_t*)(cpu->edi)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->edi + 1u) = (uint64_t)(*(uint8_t*)(cpu->edi + 1u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->edi + 2u) = (uint64_t)(*(uint8_t*)(cpu->edi + 2u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->edi + 3u) = (uint64_t)(*(uint8_t*)(cpu->edi + 3u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007E8BA:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u));
    *(uint8_t*)(cpu->esi + 9u) = (uint64_t)(*(uint8_t*)(cpu->esi + 9u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x11u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x11u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x14u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xEu));
    *(uint8_t*)(cpu->esi + 4u) = (uint64_t)(*(uint8_t*)(cpu->esi + 4u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 5u) = (uint64_t)(*(uint8_t*)(cpu->esi + 5u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 6u) = (uint64_t)(*(uint8_t*)(cpu->esi + 6u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 7u) = (uint64_t)(*(uint8_t*)(cpu->esi + 7u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->ecx = cpu->esi + 8u;
    cpu->ebp += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E8E4u)); sfera_sub_004DD810(cpu, LIFT_CODE_TOKEN_VA(0x47E8E4u));
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = -cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007E8F2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFEu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->esi + 8u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E91Eu)); sfera_sub_004DD8E0(cpu, LIFT_CODE_TOKEN_VA(0x47E91Eu));
    cpu->esp += 0x14u;
    if (cpu->eax == 0u) goto label_0007E92F;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007E92F:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx));
    *(uint8_t*)(cpu->esi + 9u) = (uint64_t)(*(uint8_t*)(cpu->esi + 9u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x11u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x11u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x14u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xEu));
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebp;
    *(uint8_t*)(cpu->esi + 4u) = (uint64_t)(*(uint8_t*)(cpu->esi + 4u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 5u) = (uint64_t)(*(uint8_t*)(cpu->esi + 5u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 6u) = (uint64_t)(*(uint8_t*)(cpu->esi + 6u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 7u) = (uint64_t)(*(uint8_t*)(cpu->esi + 7u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint32_t*)(cpu->esi) = 0x52485053u;
    *(uint32_t*)(cpu->edi) = (uint64_t)(*(uint32_t*)(cpu->edi)) + (uint64_t)(8u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)g_sfera_string_utility_runtime.format_buffer);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x47E96Fu));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)g_sfera_string_utility_runtime.format_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0047E990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = 1u;
    if (g_sfera_string_utility_runtime.case_tables_initialized == cpu->ecx) goto label_0007EA11;
    cpu->eax = 0u;
    (void)cpu;
    label_0007E9A0:
    g_sfera_string_utility_runtime.lowercase[cpu->eax] = cpu->eax & 0xFFu;
    cpu->eax += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)0x100u) goto label_0007E9A0;
    cpu->eax = 0u;
    label_0007E9B1:
    g_sfera_string_utility_runtime.uppercase[cpu->eax] = cpu->eax & 0xFFu;
    cpu->eax += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)0x100u) goto label_0007E9B1;
    for (uint32_t letter = 'A'; letter <= 'Z'; ++letter) { g_sfera_string_utility_runtime.lowercase[letter] = (uint8_t)(letter + ('a' - 'A')); *(uint8_t*)(letter + ('a' - 'A') + ((uintptr_t)g_sfera_string_utility_runtime.uppercase)) = (uint8_t)letter; }
    g_sfera_string_utility_runtime.case_tables_initialized = cpu->ecx;
    label_0007EA11:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EA20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint32_t)(g_sfera_string_utility_runtime.case_tables_initialized) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (!sub_pred[0]) goto label_0007EA31;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7EA31u)); sfera_sub_0047E990(cpu, LIFT_CODE_TOKEN_RVA(0x7EA31u));
    label_0007EA31:
    if (*(uint8_t*)(cpu->esi) == 0u) goto label_0007EA51;
    cpu->eax = cpu->esi;
    label_0007EA40:
    cpu->ecx = *(uint8_t*)(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (g_sfera_string_utility_runtime.lowercase[cpu->ecx]);
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax) != 0u) goto label_0007EA40;
    label_0007EA51:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EA60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0007EA6B;
    if ((int32_t)cpu->esi < (int32_t)cpu->edx) goto label_0007EA83;
    label_0007EA6B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"check_index: wrong index %d, File:%s, Line:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EA80u)); sfera_sub_0047E960(cpu, LIFT_CODE_TOKEN_VA(0x47EA80u));
    cpu->esp += 0x10u;
    label_0007EA83:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx < cpu->eax) goto label_0007EAA4;
    cpu->eax += *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_pop32(cpu);
    if (cpu->ecx <= cpu->eax) goto label_0007EABC;
    label_0007EAA4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"check_pointer: wrong pointer or size %d, File:%s, Line:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EAB9u)); sfera_sub_0047E960(cpu, LIFT_CODE_TOKEN_VA(0x47EAB9u));
    cpu->esp += 0x10u;
    label_0007EABC:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->esi < cpu->eax) goto label_0007EAF1;
    cpu->ecx = cpu->eax + cpu->edx;
    cpu->ebp = cpu->esi + cpu->edi;
    if (cpu->ebp > cpu->ecx) goto label_0007EAF1;
    if (cpu->ebx < cpu->eax) goto label_0007EAF1;
    cpu->ebp = cpu->ebx + cpu->edi;
    if (cpu->ebp > cpu->ecx) goto label_0007EAF1;
    if ((int32_t)cpu->edi > 0) goto label_0007EB0D;
    label_0007EAF1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"memmove_safe: pDest=%x, pSrc=%x, len=%d, pGuard=%x, guardLen=%d; File:%s, Line:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EB0Au)); sfera_sub_0047E960(cpu, LIFT_CODE_TOKEN_VA(0x47EB0Au));
    cpu->esp += 0x20u;
    label_0007EB0D:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x47EB10u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->esi < cpu->eax) goto label_0007EB5A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->esi + cpu->ebx;
    cpu->ebp += cpu->eax;
    if (cpu->edx > cpu->ebp) goto label_0007EB5A;
    if (cpu->edi < cpu->ecx) goto label_0007EB5A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = cpu->edi + cpu->ebx;
    cpu->ebp += cpu->ecx;
    if (cpu->edx > cpu->ebp) goto label_0007EB5A;
    if ((int32_t)cpu->ebx > 0) goto label_0007EB80;
    label_0007EB5A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"memcpy_safe: pDest=%x, pSrc=%x, len=%d, pGuard1=%x, guardLen1=%d, pGuard2=%x, guardLen2=%d; File:%s, Line:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EB7Du)); sfera_sub_0047E960(cpu, LIFT_CODE_TOKEN_VA(0x47EB7Du));
    cpu->esp += 0x28u;
    label_0007EB80:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47EB83u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EBA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"check_error: FALSE, File:%s, Line:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EBACu)); sfera_sub_0047E960(cpu, LIFT_CODE_TOKEN_VA(0x47EBACu));
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EBB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->edi;
    cpu->ebx = cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    label_0007EBC0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007EBC0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->esi = cpu->eax + 1u;
    label_0007EBD5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007EBD5;
    cpu->eax -= cpu->esi;
    cpu->ecx = cpu->eax + cpu->edx + 1u;
    lift_push32(cpu, 0xF3u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EBF1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47EBF1u));
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_0007EBF7:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0007EBF7;
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    label_0007EC06:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007EC06;
    cpu->edi = *(uint32_t*)(cpu->ebx);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0007EC12:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007EC12;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EC40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0007EC50:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007EC50;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->eax + 1u;
    label_0007EC62:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007EC62;
    cpu->eax -= cpu->edx;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = cpu->eax + 1u;
    label_0007EC74:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007EC74;
    cpu->eax -= cpu->esi;
    cpu->eax += cpu->ecx;
    lift_push32(cpu, 0xFBu);
    cpu->ecx = cpu->eax + cpu->edi + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EC92u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47EC92u));
    *(uint32_t*)(cpu->ebp) = cpu->eax;
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->eax;
    label_0007ECA0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0007ECA0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax;
    label_0007ECB0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007ECB0;
    cpu->edi = *(uint32_t*)(cpu->ebp);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    (void)cpu;
    label_0007ECC0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007ECC0;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->eax;
    label_0007ECE0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007ECE0;
    cpu->edi = *(uint32_t*)(cpu->ebp);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    (void)cpu;
    label_0007ECF0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007ECF0;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047ED10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_0007ED2E;
    lift_push32(cpu, 0x103u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ED28u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47ED28u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_0007ED2E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047ED30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047ED40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    label_0007ED50:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007ED50;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x127u);
    cpu->ecx = cpu->eax + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ED6Bu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47ED6Bu));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_0007ED71:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0007ED71;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_0007ED82:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007ED82;
    cpu->eax -= cpu->edi;
    --cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_0007ED9B;
    label_0007ED90:
    if (*(uint8_t*)(cpu->ecx + cpu->eax) == 0x2Eu) goto label_0007ED9B;
    --cpu->eax;
    if ((int32_t)cpu->eax > 0) goto label_0007ED90;
    label_0007ED9B:
    *(uint8_t*)(cpu->ecx + cpu->eax) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EDB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_0007EDCE;
    lift_push32(cpu, 0x130u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EDC8u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47EDC8u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_0007EDCE:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EDD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x420u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47EDFCu));
    cpu->esp += 0xCu;
    cpu->edx = 0x2Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EE13u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47EE13u));
    lift_push32(cpu, 0x20018u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EE1Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47EE1Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_0007EE42;
    lift_push32(cpu, 0x4B0u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0x20u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EE40u)); sfera_sub_00430F60(cpu, LIFT_CODE_TOKEN_VA(0x47EE40u));
    goto label_0007EE44;
    label_0007EE42:
    cpu->eax = 0u;
    label_0007EE44:
    cpu->edx = 0x2Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EE5Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47EE5Du));
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EE64u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47EE64u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
    if (cpu->eax == 0u) goto label_0007EE80;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EE7Eu)); sfera_sub_00480380(cpu, LIFT_CODE_TOKEN_VA(0x47EE7Eu));
    goto label_0007EE82;
    label_0007EE80:
    cpu->eax = 0u;
    label_0007EE82:
    lift_push32(cpu, (uintptr_t)"models\\mdlparam.txt");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x404u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EE9Cu)); sfera_sub_004803B0(cpu, LIFT_CODE_TOKEN_VA(0x47EE9Cu));
    lift_push32(cpu, 0x31u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    cpu->ecx = 0x2580u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EEADu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x47EEADu));
    *(uint32_t*)(cpu->esi + 0x3F8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EEB8u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x47EEB8u));
    *(uint32_t*)(cpu->esi + 0x410u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x414u) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047EEE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x138u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14Cu;
    cpu->esi = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x3ECu) < (int32_t)0xAu) goto label_0007EF30;
    cpu->ecx = (uintptr_t)"ModelsMngr::register_folder: MAX_MDL_PATH_NUM exceeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7EF30u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7EF30u));
    label_0007EF30:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x15Cu);
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    cpu->ebx = 0u;
    label_0007EF40:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007EF40;
    cpu->eax -= cpu->edx;
    if (cpu->eax < 0x64u) goto label_0007EF58;
    cpu->ecx = (uintptr_t)"ModelsMngr::register_folder: MAX_MDL_PATH_LEN exceeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7EF58u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7EF58u));
    label_0007EF58:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3ECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax + cpu->esi + 4u;
    cpu->ebp = 1u;
    label_0007EF70:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    cpu->ecx += cpu->ebp;
    cpu->edx += cpu->ebp;
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007EF70;
    *(uint32_t*)(cpu->esi + 0x3ECu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x3ECu)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3ECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->ecx = cpu->eax + cpu->esi + 0xFFFFFFA0u;
    lift_push32(cpu, (uintptr_t)"*.mdl"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EF9Eu)); sfera_sub_0047EBB0(cpu, LIFT_CODE_TOKEN_VA(0x47EF9Eu));
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x158u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EFB1u)); sfera_sub_0047ED30(cpu, LIFT_CODE_TOKEN_VA(0x47EFB1u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x47EFB2u));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x154u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EFD5u)); sfera_sub_0047ED10(cpu, LIFT_CODE_TOKEN_VA(0x47EFD5u));
    if (cpu->edi == 0xFFFFFFFFu) goto label_0007F19A;
    label_0007EFE0:
    if ((*(uint8_t*)(cpu->esp + 0x20u)&0x10u)!=0u) goto label_0007F108;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->edi = cpu->eax + (cpu->eax * 2u);
    cpu->edi <<= 4u;
    cpu->edi += *(uint32_t*)(cpu->esi + 0x3F8u);
    lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47F001u));
    cpu->esp += 0xCu;
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F017u)); sfera_sub_0047ED40(cpu, LIFT_CODE_TOKEN_VA(0x47F017u));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x154u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F025u)); sfera_sub_0047ED30(cpu, LIFT_CODE_TOKEN_VA(0x47F025u));
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    label_0007F030:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    cpu->eax += cpu->ebp;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007F030;
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x154u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F04Fu)); sfera_sub_0047EDB0(cpu, LIFT_CODE_TOKEN_VA(0x47F04Fu));
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_0007F054:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007F054;
    cpu->eax -= cpu->edx;
    if (cpu->eax < 0x20u) goto label_0007F06C;
    cpu->ecx = (uintptr_t)"Too long mdl name";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F06Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7F06Cu));
    label_0007F06C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3ECu);
    cpu->ecx -= cpu->ebp;
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x400u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x3F4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F097u)); sfera_sub_004311D0(cpu, LIFT_CODE_TOKEN_VA(0x47F097u));
    if (*(uint32_t*)(cpu->esi + 0x400u) != 0xC8u) goto label_0007F108;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3F4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3F0u);
    lift_push32(cpu, 0x63u);
    cpu->edx = cpu->eax + (cpu->eax * 2u) + 0x258u;
    lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp");
    cpu->edx <<= 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F0C5u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x47F0C5u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x3F8u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3F4u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x3F0u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47F0EEu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x3F4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x3F4u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->ebx;
    label_0007F108:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x47F112u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0007EFE0;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x47F124u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->esp += 4u;
    if (cpu->ecx == cpu->ebx) goto label_0007F19A;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3F4u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3F0u);
    lift_push32(cpu, 0x6Du);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp");
    cpu->edx <<= 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F157u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x47F157u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x3F8u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3F4u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x3F0u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47F180u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x3F4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x3F4u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->ebx;
    label_0007F19A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x144u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F1D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x3F4u) < (int32_t)0x1388u) goto label_0007F1EE;
    cpu->edx = 0x7Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F1EEu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x7F1EEu));
    label_0007F1EE:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3F8u);
    lift_push32(cpu, 0x7Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F200u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F200u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F21Eu)); sfera_sub_00430F20(cpu, LIFT_CODE_TOKEN_VA(0x47F21Eu));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x1388u;
    cpu->eax = (cpu->eax < *(uint32_t*)(cpu->esp + 4u)) ? 0xFFFFFFFFu : 0u;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->ecx == 0u) goto label_0007F265;
    lift_push32(cpu, 0xC2u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F25Eu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F25Eu));
    *(uint32_t*)(cpu->esi + 0x24u) = 0u;
    label_0007F265:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C8u);
    if (cpu->ecx == 0u) goto label_0007F288;
    lift_push32(cpu, 0xC3u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F27Eu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F27Eu));
    *(uint32_t*)(cpu->esi + 0x1C8u) = 0u;
    label_0007F288:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (cpu->ecx == 0u) goto label_0007F2AB;
    lift_push32(cpu, 0xC4u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F2A1u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F2A1u));
    *(uint32_t*)(cpu->esi + 0x1CCu) = 0u;
    label_0007F2AB:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->eax == 0u) goto label_0007F2BF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x47F2B6u));
    cpu->esp += 4u;
    label_0007F2BF:
    lift_push32(cpu, 0xC8u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F2D0u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F2D0u));
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F2E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ebx;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x3F4u) <= (int32_t)cpu->ebx) goto label_0007F3B7;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    label_0007F301:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3F0u);
    sub_pred[0] = *(uint32_t*)(cpu->edi + cpu->eax + 0x24u) == cpu->ebx;
    cpu->edi = cpu->edi + cpu->eax + 0x24u;
    if (sub_pred[0]) goto label_0007F395;
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->ecx == cpu->ebx) goto label_0007F330;
    lift_push32(cpu, 0xC2u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F32Du)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F32Du));
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebx;
    label_0007F330:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C8u);
    if (cpu->ecx == cpu->ebx) goto label_0007F34F;
    lift_push32(cpu, 0xC3u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F349u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F349u));
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ebx;
    label_0007F34F:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (cpu->ecx == cpu->ebx) goto label_0007F36E;
    lift_push32(cpu, 0xC4u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F368u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F368u));
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ebx;
    label_0007F36E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->eax == cpu->ebx) goto label_0007F382;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x47F379u));
    cpu->esp += 4u;
    label_0007F382:
    lift_push32(cpu, 0xC8u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F393u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F393u));
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    label_0007F395:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 0x30u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebp + 0x3F4u)) goto label_0007F301;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0007F3B7:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F3C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F3CBu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x47F3CBu));
    *(uint32_t*)(cpu->esi + 0x410u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x418u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax <<= 4u;
    cpu->eax += *(uint32_t*)(cpu->esi + 0x3F0u);
    *(uint32_t*)(cpu->esi + 0x414u) = cpu->edx;
    cpu->edx = cpu->eax + 0x24u;
    if (*(uint32_t*)(cpu->eax + 0x24u) == 0u) goto label_0007F41E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x410u);
    sub_pred[0] = cpu->ecx < *(uint32_t*)(cpu->eax + 0x28u); cpu->ecx -= *(uint32_t*)(cpu->eax + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x414u);
    sub_pred[3] = (int64_t)((int32_t)(cpu->edi)) < (int64_t)((int32_t)(*(uint32_t*)(cpu->eax + 0x2Cu))) + (sub_pred[0]); cpu->edi -= *(uint32_t*)(cpu->eax + 0x2Cu) + (sub_pred[0]); sub_pred[1] = (int32_t)(cpu->edi) < 0; sub_pred[2] = cpu->edi == 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    if (sub_pred[1]) goto label_0007F41E;
    if ((!sub_pred[2]) && (!sub_pred[3])) goto label_0007F416;
    if (cpu->ecx <= 0x895440u) goto label_0007F41E;
    label_0007F416:
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F41Eu)); sfera_sub_0047F240(cpu, LIFT_CODE_TOKEN_RVA(0x7F41Eu));
    label_0007F41E:
    ++*(uint32_t*)(cpu->esi + 0x418u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x418u);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x3F4u)) goto label_0007F43C;
    *(uint32_t*)(cpu->esi + 0x418u) = 0u;
    label_0007F43C:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F450(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F459u)); sfera_sub_0047F2E0(cpu, LIFT_CODE_TOKEN_VA(0x47F459u));
    cpu->edx = 0x3Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F468u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47F468u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x404u);
    if (cpu->edi == 0u) goto label_0007F482;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F479u)); sfera_sub_00480390(cpu, LIFT_CODE_TOKEN_VA(0x47F479u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F47Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x47F47Fu));
    cpu->esp += 4u;
    label_0007F482:
    cpu->edx = 0x3Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F491u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47F491u));
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->edi == 0u) goto label_0007F4A7;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F49Eu)); sfera_sub_00430BC0(cpu, LIFT_CODE_TOKEN_VA(0x47F49Eu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F4A4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x47F4A4u));
    cpu->esp += 4u;
    label_0007F4A7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3F0u);
    if (cpu->ecx == 0u) goto label_0007F4C7;
    lift_push32(cpu, 0x3Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F4BDu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x47F4BDu));
    *(uint32_t*)(cpu->esi + 0x3F0u) = 0u;
    label_0007F4C7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F4D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if (cpu->edi != 0xFFFFFFFFu) goto label_0007F4EE;
    cpu->ecx = (uintptr_t)"get_model_by_id: id == -1";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F4E7u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x47F4E7u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0007F4EE:
    if (cpu->edi <= 0x1388u) goto label_0007F4FD;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0007F4FD:
    if ((int32_t)cpu->edi < 0) goto label_0007F509;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 0x3F4u)) goto label_0007F518;
    label_0007F509:
    cpu->edx = 0x9Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F518u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x7F518u));
    label_0007F518:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3F0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x410u);
    cpu->edi = cpu->edi + (cpu->edi * 2u);
    cpu->edi += cpu->edi;
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 0x28u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x414u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 0x2Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3F0u);
    cpu->edx = cpu->eax + (cpu->edi * 8u);
    cpu->ecx = cpu->edx + 0x24u;
    if (*(uint32_t*)(cpu->edx + 0x24u) != 0u) goto label_0007F560;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x404u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x20u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->eax = cpu->eax + cpu->esi + 4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F560u)); sfera_sub_00465B80(cpu, LIFT_CODE_TOKEN_RVA(0x7F560u));
    label_0007F560:
    ++*(uint32_t*)(cpu->esi + 0x408u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x408u) <= (int32_t)0x186A0u) goto label_0007F583;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x408u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F583u)); sfera_sub_0047F3C0(cpu, LIFT_CODE_TOKEN_RVA(0x7F583u));
    label_0007F583:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3F0u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->edi * 8u) + 0x24u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F5A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_nature_runtime.manager;
    *(uint32_t*)(cpu->eax + 0x1Cu) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F5C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    bool lift_cmp[1];
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F5E2u)); sfera_sub_00426180(cpu, LIFT_CODE_TOKEN_VA(0x47F5E2u));
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F5EDu)); sfera_sub_00426160(cpu, LIFT_CODE_TOKEN_VA(0x47F5EDu));
    if (*(uint32_t*)(cpu->eax + 0x5Cu) > 0u) goto label_0007F5F7;
    cpu->esi = 0u;
    goto label_0007F5FA;
    label_0007F5F7:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    label_0007F5FA:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F606u)); sfera_sub_00455E40(cpu, LIFT_CODE_TOKEN_VA(0x47F606u));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esi + 0x18u))) - (((double)*(float*)(cpu->esp + 0x1Cu))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esi + 0x1Cu))) - (((double)*(float*)(cpu->esp + 0x20u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x20u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x24u)));
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->ecx;
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->edx;
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
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    lift_cmp[0]=x87_v0<(15.0);
    cpu->ecx = 0x13BCu;
    if (lift_cmp[0]) goto label_0007F687;
    cpu->ecx = 0x13BBu;
    label_0007F687:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F68Cu)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F68Cu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_nature_runtime.manager;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F6C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->edx == 0xFFFFFFFFu) goto label_0007F6DB;
    cpu->ecx = 0x190u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F6D8u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F6D8u));
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    label_0007F6DB:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F6E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi |= 0xFFFFFFFFu;
    if (cpu->ecx == cpu->edi) goto label_0007F6F3;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F6F3u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_RVA(0x7F6F3u));
    label_0007F6F3:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_0007F705;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F702u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F702u));
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    label_0007F705:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->ecx == cpu->edi) goto label_0007F714;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F711u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F711u));
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    label_0007F714:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->ecx == cpu->edi) goto label_0007F723;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F720u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F720u));
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    label_0007F723:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->edx == 0xFFFFFFFFu) goto label_0007F74B;
    cpu->ecx = 0x19Au;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F748u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F748u));
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    label_0007F74B:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_0007F760;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F760u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_RVA(0x7F760u));
    label_0007F760:
    *(uint32_t*)(cpu->esi + 0x28u) = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F770(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1Cu);
    if (cpu->esi == 0u) goto label_0007F7AC;
    if (g_sfera_world_objects.controlled_object_handle == 0xFFFFFFFFu) goto label_0007F7AC;
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 - x87_v0; 
    x87_v0 = (x87_v0) * (640.0);
    x87_v0 = (x87_v0) + (320.0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F7ACu)); sfera_sub_00425F40(cpu, LIFT_CODE_TOKEN_RVA(0x7F7ACu));
    label_0007F7AC:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F7B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_nature_runtime.manager;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_0007F7CC;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F7C5u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F7C5u));
    *(uint32_t*)(cpu->esi + 0x2Cu) = 0xFFFFFFFFu;
    label_0007F7CC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_0007F7E0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F7D9u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F7D9u));
    *(uint32_t*)(cpu->esi + 0x30u) = 0xFFFFFFFFu;
    label_0007F7E0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_0007F807;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F7EDu)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F7EDu));
    cpu->eax = g_sfera_nature_runtime.manager;
    *(uint32_t*)(cpu->esi + 0x34u) = 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x10u) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007F807:
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F820(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    cpu->eax = g_sfera_nature_runtime.manager;
    sub_pred[0] = *(uint32_t*)(cpu->eax + 0x1Cu) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (sub_pred[0]) goto label_0007F834;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0007F834:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (*(uint32_t*)(cpu->esi + 0x28u) == 1u) goto label_0007F857;
    lift_push32(cpu, (uintptr_t)"Unknown effect classID for lighting.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F849u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x47F849u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F84Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x47F84Fu));
    cpu->eax = g_sfera_nature_runtime.manager;
    cpu->esp += 8u;
    label_0007F857:
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->esi;
    if (g_sfera_world_objects.controlled_object_handle == 0xFFFFFFFFu) goto label_0007F88D;
    x87_v0 = (double)*(float*)(cpu->eax + 0x20u);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 - x87_v0; 
    x87_v0 = (x87_v0) * (640.0);
    x87_v0 = (x87_v0) + (320.0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7F88Du)); sfera_sub_00425F40(cpu, LIFT_CODE_TOKEN_RVA(0x7F88Du));
    label_0007F88D:
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edi + 4u) = 1u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F8A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = (double)0.5f;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    std::construct_at(reinterpret_cast<NatureRainListener*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    std::construct_at(reinterpret_cast<LightingListener*>(cpu->esi + 8u));
    *(float*)(cpu->esi + 0x14u) = x87_v0;
    cpu->eax = 0u;
    *(float*)(cpu->esi + 0x20u) = x87_v0; 
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = 0x190u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F8E1u)); sfera_sub_0042AA90(cpu, LIFT_CODE_TOKEN_VA(0x47F8E1u));
    cpu->edx = cpu->esi + 8u;
    cpu->ecx = 0x19Au;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F8EEu)); sfera_sub_0042AA90(cpu, LIFT_CODE_TOKEN_VA(0x47F8EEu));
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F900(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->edi);
    x87_v1 = 0.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left!=lift_right) goto label_0007F926; }
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edi |= 0xFFFFFFFFu;
    if (cpu->ecx == cpu->edi) goto label_0007F957;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F921u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F921u));
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    goto label_0007F957;
    label_0007F926:
    x87_v0 = (double)*(float*)(cpu->esi + 0x14u);
    x87_v1 = 0.4000000059604645;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>=lift_right)) goto label_0007F968; }
    cpu->edi |= 0xFFFFFFFFu;
    x87_v0 = x87_v0; 
    if (*(uint32_t*)(cpu->esi + 0x2Cu) != cpu->edi) goto label_0007F957;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F954u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F954u));
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    label_0007F957:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->ecx == cpu->edi) goto label_0007F9B7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F963u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F963u));
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    goto label_0007F9B7;
    label_0007F968:
    x87_v1 = (double)*(float*)(cpu->esi + 0x14u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0007F9C9; }
    { const double lift_left=(double)*(float*)(cpu->esi + 0x14u); const double lift_right=0.800000011920929; if (!(lift_left<=lift_right)) goto label_0007F9C9; }
    cpu->edi |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) != cpu->edi) goto label_0007F99F;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F99Cu)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F99Cu));
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    label_0007F99F:
    if (*(uint32_t*)(cpu->esi + 0x30u) != cpu->edi) goto label_0007F9B7;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F9B4u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F9B4u));
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    label_0007F9B7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->ecx == cpu->edi) goto label_0007FA14;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F9C3u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x47F9C3u));
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007F9C9:
    cpu->edi |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) != cpu->edi) goto label_0007F9E4;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F9E1u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F9E1u));
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    label_0007F9E4:
    if (*(uint32_t*)(cpu->esi + 0x30u) != cpu->edi) goto label_0007F9FC;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47F9F9u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47F9F9u));
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    label_0007F9FC:
    if (*(uint32_t*)(cpu->esi + 0x34u) != cpu->edi) goto label_0007FA14;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FA11u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x47FA11u));
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->eax;
    label_0007FA14:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FA20(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax == 0u) goto label_0007FA42;
    if (g_sfera_world_objects.controlled_object_handle == 0xFFFFFFFFu) goto label_0007FA42;
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    *(float*)(cpu->ecx + 0x14u) = x87_v0;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->ecx + 0x18u)));
    *(float*)(cpu->eax + 0x6Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7FA42u)); sfera_sub_0047F900(cpu, LIFT_CODE_TOKEN_RVA(0x7FA42u));
    label_0007FA42:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FA50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->ecx = g_sfera_nature_runtime.manager;
    if (*(uint32_t*)(cpu->ecx + 0x10u) == 0u) goto label_0007FA61;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0007FA61:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    if (*(uint32_t*)(cpu->esi + 0x28u) == 3u) goto label_0007FA85;
    lift_push32(cpu, (uintptr_t)"Unknown effect classID for rain.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FA76u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x47FA76u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FA7Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x47FA7Cu));
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->esp += 8u;
    label_0007FA85:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = (uintptr_t)"rain";
    lift_push32(cpu, cpu->ebx);
    label_0007FA90:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->ebx) < *(uint8_t*)(cpu->edx);
    if ((uint8_t)(cpu->ebx) != *(uint8_t*)(cpu->edx)) goto label_0007FAB0;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0007FAAC;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->ebx) < *(uint8_t*)(cpu->edx + 1u);
    if ((uint8_t)(cpu->ebx) != *(uint8_t*)(cpu->edx + 1u)) goto label_0007FAB0;
    cpu->eax += 2u;
    cpu->edx += 2u;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_0007FA90;
    label_0007FAAC:
    cpu->eax = 0u;
    goto label_0007FAB5;
    label_0007FAB0:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_0007FAB5:
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_0007FAD3;
    lift_push32(cpu, (uintptr_t)"Unknown effect manager for 'rain' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FAC4u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x47FAC4u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FACAu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x47FACAu));
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->esp += 8u;
    label_0007FAD3:
    x87_v0 = (double)60.0f;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->esi;
    *(float*)(cpu->ecx + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->ecx + 0x14u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    if ((uint32_t)(g_sfera_world_objects.controlled_object_handle) == 0xFFFFFFFFu) goto label_0007FB09;
    *(float*)(cpu->esi + 0x6Cu) = ((((double)*(float*)(cpu->esp + 8u))) * (60.0));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7FB09u)); sfera_sub_0047F900(cpu, LIFT_CODE_TOKEN_RVA(0x7FB09u));
    label_0007FB09:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FB10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    if (g_sfera_nature_runtime.manager != 0u) goto label_0007FB86;
    cpu->edx = 0xA6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\NatureManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FB49u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47FB49u));
    lift_push32(cpu, 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FB50u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x47FB50u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_0007FB7F;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FB6Au)); sfera_sub_0047F8A0(cpu, LIFT_CODE_TOKEN_VA(0x47FB6Au));
    g_sfera_nature_runtime.manager = cpu->eax;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007FB7F:
    cpu->eax = 0u;
    g_sfera_nature_runtime.manager = cpu->eax;
    label_0007FB86:
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FBA0(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_nature_runtime.manager == 0u) goto label_0007FBE6;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0xB0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\NatureManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FBB9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47FBB9u));
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0007FBDB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FBCAu)); sfera_sub_00429990(cpu, LIFT_CODE_TOKEN_VA(0x47FBCAu));
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FBD2u)); sfera_sub_00429990(cpu, LIFT_CODE_TOKEN_VA(0x47FBD2u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FBD8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x47FBD8u));
    cpu->esp += 4u;
    label_0007FBDB:
    g_sfera_nature_runtime.manager = 0u;
    cpu->esi = lift_pop32(cpu);
    label_0007FBE6:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FBF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x45Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x44u);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47FC10u));
    cpu->ebx = native_function_address32(&::timeGetTime);
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x44u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7FC3Au), LIFT_CODE_TOKEN_RVA(0x7FC38u))) { return; }
    lift_push32(cpu, 0x400u);
    cpu->ecx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->ecx);
    cpu->ebp = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::GetSystemDirectoryA), LIFT_CODE_TOKEN_VA(0x47FC46u));
    cpu->eax = cpu->esp + 0x64u;
    --cpu->eax;
    label_0007FC51:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007FC51;
    cpu->edx = *(uint32_t*)((uintptr_t)"\\ping.exe -n 1 ");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"\\ping.exe -n 1 ") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"\\ping.exe -n 1 ") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"\\ping.exe -n 1 ") + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->eax = (uintptr_t)g_sfera_network_probe_runtime.host;
    cpu->edx = cpu->eax;
    label_0007FC83:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0007FC83;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esp + 0x68u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0007FC92:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0007FC92;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 0u);
    lift_push32(cpu, 0u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateProcessA), LIFT_CODE_TOKEN_VA(0x47FCCDu));
    cpu->edi = lift_pop32(cpu);
    if (cpu->eax != 0u) goto label_0007FD07;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x47FCD8u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CreateProcess error: %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FCE9u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x47FCE9u));
    cpu->esp += 8u;
    label_0007FCEC:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007FD07:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, 0x7530u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::WaitForSingleObject), LIFT_CODE_TOKEN_VA(0x47FD11u));
    sub_pred[0] = cpu->eax == 0x102u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    if (!sub_pred[0]) goto label_0007FD51;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_VA(0x47FD25u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x47FD30u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007FD51:
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeProcess), LIFT_CODE_TOKEN_VA(0x47FD57u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x47FD64u));
    if (cpu->esi == 0u) goto label_0007FCEC;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != 1u) goto label_0007FD96;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFEu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007FD96:
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7FD98u), LIFT_CODE_TOKEN_RVA(0x7FD96u))) { return; }
    cpu->esi = lift_pop32(cpu);
    cpu->eax -= cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FDC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0007FDD0:
    cpu->esi = 0u;
    label_0007FDD2:
    lift_push32(cpu, 0xC8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x47FDD7u));
    if ((uint8_t)(g_sfera_network_probe_runtime.stop_requested) == 1u) goto label_0007FE97;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x14u) goto label_0007FDD2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47FDF5u)); sfera_sub_0047FBF0(cpu, LIFT_CODE_TOKEN_VA(0x47FDF5u));
    lift_push32(cpu, 0u);
    cpu->esi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x47FDF9u));
    cpu->ecx = g_sfera_network_probe_runtime.context_b;
    cpu->ebx = g_sfera_network_probe_runtime.context_a;
    cpu->esp += 4u;
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_network_probe_runtime.context_c;
    lift_push32(cpu, (uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x47FE24u));
    lift_push32(cpu, 0x1C8u); lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.samples[0]); lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.samples[1]);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x47FE39u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)((uintptr_t)&g_sfera_network_probe_runtime.samples[0].context_c) = cpu->eax;
    cpu->eax = g_sfera_network_probe_runtime.sample_count;
    ++cpu->eax;
    cpu->esp += 0xCu;
    g_sfera_network_probe_runtime.samples[0].timestamp.low = cpu->edi;
    *(uint32_t*)((uintptr_t)&g_sfera_network_probe_runtime.samples[0].timestamp.high) = cpu->ebp;
    *(uint32_t*)((uintptr_t)&g_sfera_network_probe_runtime.samples[0].probe_result) = cpu->esi;
    *(uint32_t*)((uintptr_t)&g_sfera_network_probe_runtime.samples[0].context_a) = cpu->ebx;
    *(uint32_t*)((uintptr_t)&g_sfera_network_probe_runtime.samples[0].context_b) = cpu->edx;
    g_sfera_network_probe_runtime.sample_count = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)0x14u) goto label_0007FE87;
    g_sfera_network_probe_runtime.sample_count = 0x14u;
    label_0007FE87:
    lift_push32(cpu, (uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x47FE8Cu));
    goto label_0007FDD0;
    label_0007FE97:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    g_sfera_network_probe_runtime.context_a = cpu->ecx;
    g_sfera_network_probe_runtime.context_c = cpu->edx;
    g_sfera_network_probe_runtime.context_b = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x8Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007FEF6;
    cpu->eax = (uintptr_t)"at";
    label_0007FEF6:
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"Net.log";
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x47FEFDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0007FF56;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x47FF12u));
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x47FF1Du));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m %H:%M:%S ");
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x47FF33u));
    cpu->edi = native_function_address32(&::fputs);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x7FF47u), LIFT_CODE_TOKEN_RVA(0x7FF45u))) { return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x7FF4Bu), LIFT_CODE_TOKEN_RVA(0x7FF49u))) { return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x47FF4Cu));
    cpu->esp += 0x2Cu;
    cpu->edi = lift_pop32(cpu);
    label_0007FF56:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x104u;
    cpu->eax = (uintptr_t)"Net.log";
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x47FF90u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp != 0u) goto label_0007FFB5;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007FFB5:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x47FFBCu));
    cpu->esi = (uintptr_t)&g_sfera_network_probe_runtime.samples[0];
    std::memmove((void*)((uintptr_t)&g_sfera_network_probe_runtime.snapshot[0]),(void*)(cpu->esi),480u); cpu->esi += 480u;
    cpu->ecx = g_sfera_network_probe_runtime.sample_count;
    lift_push32(cpu, (uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    g_sfera_network_probe_runtime.snapshot_count = cpu->ecx;
    g_sfera_network_probe_runtime.sample_count = 0u;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x47FFEEu));
    cpu->edi = g_sfera_network_probe_runtime.snapshot_count;
    if ((int32_t)(--cpu->edi) < 0) goto label_00080069;
    cpu->esi = cpu->edi + (cpu->edi * 2u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fputs);
    cpu->esi = (cpu->esi * 8u) + ((uintptr_t)&g_sfera_network_probe_runtime.snapshot[0].context_a);
    label_00080010:
    cpu->edx = cpu->esi + 0xFFFFFFF4u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x480014u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m %H:%M:%S ");
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x48002Au));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x80038u), LIFT_CODE_TOKEN_RVA(0x80036u))) { return; }
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d\n"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480051u));
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8005Fu), LIFT_CODE_TOKEN_RVA(0x8005Du))) { return; }
    cpu->esp += 0x3Cu;
    cpu->esi -= 0x18u;
    if ((int32_t)(--cpu->edi) >= 0) goto label_00080010;
    cpu->ebx = lift_pop32(cpu);
    label_00080069:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x48006Au));
    cpu->eax = g_sfera_network_probe_runtime.snapshot_count;
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480090(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    cpu->eax = cpu->ecx;
    cpu->edx = (uintptr_t)g_sfera_network_probe_runtime.host;
    g_sfera_network_probe_runtime.sample_count = cpu->ebx;
    cpu->edx -= cpu->eax;
    label_000800A3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000800A3;
    lift_push32(cpu, (uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4800B2u));
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0047FDC0)); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    g_sfera_network_probe_runtime.stop_requested = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_probe_runtime.context_a = cpu->ebx;
    g_sfera_network_probe_runtime.context_c = cpu->ebx;
    g_sfera_network_probe_runtime.context_b = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x4800DEu));
    sub_pred[0] = cpu->eax == cpu->ebx;
    g_sfera_network_probe_runtime.thread_handle = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00080102;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4800EEu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CreateThread error: %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4800FFu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4800FFu));
    cpu->esp += 8u;
    label_00080102:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480110(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::GetExitCodeThread);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::Sleep);
    *(uint8_t*)(cpu->esp + 0xCu) = cpu->ecx & 0xFFu;
    g_sfera_network_probe_runtime.stop_requested = (uint8_t)(1u);
    cpu->esi = 0u;
    (void)cpu;
    label_00080130:
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    if (cpu->eax == 0u) goto label_000801A3;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x80149u), LIFT_CODE_TOKEN_RVA(0x80147u))) { return; }
    if (cpu->eax == 0u) goto label_00080161;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0x103u) goto label_00080161;
    lift_push32(cpu, 7u);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8015Bu), LIFT_CODE_TOKEN_RVA(0x80159u))) { return; }
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x28u) goto label_00080130;
    label_00080161:
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    if (cpu->eax == 0u) goto label_000801A3;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x8017Au), LIFT_CODE_TOKEN_RVA(0x80178u))) { return; }
    if (cpu->eax == 0u) goto label_000801A3;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0x103u) goto label_000801A3;
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x480190u));
    cpu->ecx = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x8019Du));
    label_000801A3:
    lift_push32(cpu, (uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::DeleteCriticalSection), LIFT_CODE_TOKEN_VA(0x4801A8u));
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0xCu) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000801CE;
    cpu->edx = (uintptr_t)"NetError.log";
    cpu->eax = (uintptr_t)"Net.log";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4801C5u));
    cpu->esp += 8u;
    label_000801CE:
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004801E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_network_connection_checker.instance;
    if (cpu->eax != 0u) goto label_00080217;
    cpu->edx = cpu->eax + 0x1Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\NetworkConnectionChecker.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4801F6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4801F6u));
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4801FDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4801FDu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00080210;
    *(uint32_t*)(cpu->eax) = 0u;
    g_sfera_network_connection_checker.instance = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00080210:
    cpu->eax = 0u;
    g_sfera_network_connection_checker.instance = cpu->eax;
    label_00080217:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480220(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::Sleep);
    label_00080230:
    lift_push32(cpu, 0xB8u);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x2BF20u);
    cpu->eax = cpu->esp + 0x17u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint8_t*)(cpu->esp + 0x1Bu) = 5u;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x80272u), LIFT_CODE_TOKEN_RVA(0x80270u))) { return; }
    lift_push32(cpu, 0x7D0u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x80279u), LIFT_CODE_TOKEN_RVA(0x80277u))) { return; }
    goto label_00080230;
}
__declspec(noinline) void sfera_sub_00480280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000802AE;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x48029Au));
    if (cpu->eax == 0u) goto label_000802AE;
    if (*(uint32_t*)(cpu->esp + 4u) == 0x103u) goto label_000802ED;
    label_000802AE:
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00480220)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x4802C0u));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000802ED;
    cpu->ecx = (uintptr_t)"CClNetworkConnectionChecker::Start(): CreateThread error: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4802D6u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4802D6u));
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4802D6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4802E3u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x4802E3u));
    cpu->ecx = (uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x802EDu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_RVA(0x802EDu));
    label_000802ED:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->edx = 0x26u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\NetworkConnectionChecker.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480311u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x480311u));
    cpu->eax = g_sfera_network_connection_checker.instance;
    cpu->esi = cpu->eax;
    if (cpu->eax == 0u) goto label_00080367;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008035E;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x480330u));
    if (cpu->eax == 0u) goto label_0008035E;
    if (*(uint32_t*)(cpu->esp + 4u) != 0x103u) goto label_0008035E;
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x480349u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x480352u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_0008035E:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480364u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x480364u));
    cpu->esp += 4u;
    label_00080367:
    g_sfera_network_connection_checker.instance = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_000803A2;
    lift_push32(cpu, 0x18u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x803A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x803A2u));
    label_000803A2:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004803B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4803C0u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x4803C0u));
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->edi) == 0u) goto label_000803D1;
    cpu->ecx = (uintptr_t)"CObjParamManager::Open: object already initialized";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x803D1u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x803D1u));
    label_000803D1:
    lift_push32(cpu, 0x21u);
    cpu->ecx = cpu->esi + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4803E0u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4803E0u));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = cpu->ebx;
    *(uint8_t*)(cpu->eax + cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4803EFu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x4803EFu));
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4803FBu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4803FBu));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480402u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x480402u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480410(LiftCpu* cpu, uint32_t stop_address) {
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0008041C;
    if ((cpu->ecx & 0xFFu) == 0xDu) goto label_0008041C;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008041C:
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480430(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00080494;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp = native_function_address32(&::_stricmp);
    label_00080446:
    if ((cpu->eax & 0xFFu) != 0xDu) goto label_0008044F;
    cpu->edi += 2u;
    goto label_0008048E;
    label_0008044F:
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_00080481;
    cpu->esi = cpu->edi;
    label_00080455:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_00080461;
    if ((cpu->eax & 0xFFu) != 0xDu) goto label_0008046B;
    label_00080461:
    cpu->ecx = (uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8046Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8046Bu));
    label_0008046B:
    if (*(uint8_t*)(cpu->esi) != 0x20u) goto label_00080455;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi) = 0u;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x80477u), LIFT_CODE_TOKEN_RVA(0x80475u))) { return; }
    cpu->esp += 8u;
    *(uint8_t*)(cpu->esi) = 0x20u;
    if (cpu->eax == 0u) goto label_0008049D;
    label_00080481:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48048Au)); sfera_sub_00480410(cpu, LIFT_CODE_TOKEN_VA(0x48048Au));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00080481;
    label_0008048E:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    if ((cpu->eax & 0xFFu) != 0u) goto label_00080446;
    label_00080494:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008049D:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000804A1:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000804AD;
    if ((cpu->eax & 0xFFu) != 0xDu) goto label_000804B7;
    label_000804AD:
    cpu->ecx = (uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x804B7u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x804B7u));
    label_000804B7:
    if (*(uint8_t*)(cpu->esi) == 0x20u) goto label_000804A1;
    cpu->ecx = cpu->esi;
    label_000804C0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_000804D8;
    if ((cpu->eax & 0xFFu) == 0x2Cu) goto label_000804D8;
    if ((cpu->eax & 0xFFu) == 0x3Du) goto label_000804D8;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000804D8;
    if ((cpu->eax & 0xFFu) != 0xDu) goto label_000804C0;
    label_000804D8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esi) = 0u;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x804E1u), LIFT_CODE_TOKEN_RVA(0x804DFu))) { return; }
    cpu->esp += 8u;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    if (cpu->eax == 0u) goto label_0008050A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ebx & 0xFFu) & 0xFFu);
    if ((cpu->eax & 0xFFu) == 0x2Cu) goto label_000804A1;
    label_000804F0:
    if ((cpu->eax & 0xFFu) == 0u) goto label_000805BF;
    if ((cpu->eax & 0xFFu) == 0xDu) goto label_000805BF;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0x2Cu) goto label_000804F0;
    goto label_000804A1;
    label_0008050A:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->edi == 0u) goto label_000805B3;
    if ((cpu->ebx & 0xFFu) == 0x2Cu) goto label_00080524;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_00080524;
    if ((cpu->ebx & 0xFFu) != 0xDu) goto label_0008052E;
    label_00080524:
    cpu->ecx = (uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8052Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8052Eu));
    label_0008052E:
    if (*(uint8_t*)(cpu->esi) != 0x20u) goto label_00080539;
    label_00080533:
    ++cpu->esi;
    if (*(uint8_t*)(cpu->esi) == 0x20u) goto label_00080533;
    label_00080539:
    if (*(uint8_t*)(cpu->esi) == 0x3Du) goto label_00080548;
    cpu->ecx = (uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80548u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80548u));
    label_00080548:
    ++cpu->esi;
    if (*(uint8_t*)(cpu->esi) != 0x20u) goto label_00080556;
    label_00080550:
    ++cpu->esi;
    if (*(uint8_t*)(cpu->esi) == 0x20u) goto label_00080550;
    label_00080556:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax != 0u) goto label_00080566;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%f");
    goto label_0008059A;
    label_00080566:
    if (cpu->eax != 1u) goto label_00080594;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    cpu->ecx = cpu->edi;
    if ((cpu->eax & 0xFFu) == 0x2Cu) goto label_00080585;
    label_00080573:
    if ((cpu->eax & 0xFFu) == 0u) goto label_00080585;
    if ((cpu->eax & 0xFFu) == 0xDu) goto label_00080585;
    ++cpu->esi;
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0x2Cu) goto label_00080573;
    label_00080585:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx) = 0u;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00080594:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d");
    label_0008059A:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x48059Bu));
    cpu->esp += 0xCu;
    if (cpu->eax == 1u) goto label_000805B3;
    cpu->ecx = (uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x805B3u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x805B3u));
    label_000805B3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000805BF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 2u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004805D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((cpu->eax & 0xFFu) == 0u) goto label_00080624;
    cpu->edi = cpu->esi + 1u;
    (void)cpu;
    label_000805E0:
    if ((cpu->eax & 0xFFu) != 0x2Fu) goto label_000805F4;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 1u) != (cpu->eax & 0xFFu)) goto label_000805F4;
    cpu->edx += 2u;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->esi = cpu->edi;
    goto label_0008061C;
    label_000805F4:
    if (cpu->esi == 0u) goto label_00080606;
    if ((cpu->eax & 0xFFu) != 0xAu) goto label_0008061A;
    g_sfera_config_parser_runtime.line_number += cpu->edi;
    cpu->esi = 0u;
    goto label_0008061A;
    label_00080606:
    if ((cpu->eax & 0xFFu) != 0xAu) goto label_00080612;
    g_sfera_config_parser_runtime.line_number += cpu->edi;
    goto label_0008061A;
    label_00080612:
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_0008061A;
    if ((cpu->eax & 0xFFu) != 0xDu) goto label_00080629;
    label_0008061A:
    *(uint32_t*)(cpu->ecx) = (uint64_t)(*(uint32_t*)(cpu->ecx)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    label_0008061C:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000805E0;
    label_00080624:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00080629:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480641u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00480660(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 4u;
    cpu->ebx = 0u;
    g_sfera_config_parser_runtime.line_number = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48067Cu)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x48067Cu));
    if (cpu->eax == 0u) goto label_00080E8B;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_00080687:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    if ((cpu->eax & 0xFFu) != 0x7Du) goto label_0008078A;
    cpu->esi = g_sfera_config_parser_runtime.frame_depth;
    if (cpu->esi != 0u) goto label_000806CA;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x24u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4806B1u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4806C4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4806C4u));
    cpu->esi = g_sfera_config_parser_runtime.frame_depth;
    label_000806CA:
    --cpu->esi;
    g_sfera_config_parser_runtime.frame_depth = cpu->esi;
    cpu->esi = cpu->esi + (cpu->esi * 2u);
    ++cpu->edi;
    ++cpu->ebx;
    sub_pred[0] = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_00080E77;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4806F1u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x4806F1u));
    if (cpu->eax == 0u) goto label_00080E77;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx) != 0x2Cu) goto label_00080E77;
    cpu->edi = 1u;
    g_sfera_config_parser_runtime.frame_depth += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) = cpu->edi;
    cpu->ebx += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480728u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480728u));
    if (cpu->eax != 0u) goto label_00080752;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x25u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x48073Fu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80752u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80752u));
    label_00080752:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax) == 0x7Bu) goto label_00080781;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x26u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x48076Eu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80781u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80781u));
    label_00080781:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    goto label_00080E77;
    label_0008078A:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x61u) goto label_00080792;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x7Au) goto label_000807C4;
    label_00080792:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x41u) goto label_0008079A;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x5Au) goto label_000807C4;
    label_0008079A:
    if ((cpu->eax & 0xFFu) == 0x5Fu) goto label_000807C4;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4807B1u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x807C4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x807C4u));
    label_000807C4:
    cpu->esi = native_function_address32(&::sprintf);
    cpu->ebp = 0u;
    label_000807D0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->ebp + ((uintptr_t)&g_sfera_config_parser_runtime.token[0])) = cpu->eax & 0xFFu;
    ++cpu->ebp;
    ++cpu->edi;
    if ((int32_t)cpu->ebp <= (int32_t)0xFAu) goto label_00080804;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x807F7u), LIFT_CODE_TOKEN_RVA(0x807F5u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80804u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80804u));
    label_00080804:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x61u) goto label_0008080E;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x7Au) goto label_000807D0;
    label_0008080E:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x41u) goto label_00080816;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x5Au) goto label_000807D0;
    label_00080816:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_0008081E;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_000807D0;
    label_0008081E:
    if ((cpu->eax & 0xFFu) == 0x5Fu) goto label_000807D0;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint8_t*)(cpu->ebp + ((uintptr_t)&g_sfera_config_parser_runtime.token[0])) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480836u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480836u));
    if (cpu->eax != 0u) goto label_0008085C;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x8084Fu), LIFT_CODE_TOKEN_RVA(0x8084Du))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8085Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8085Cu));
    label_0008085C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edi) == 0x3Cu) goto label_00080886;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 5u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x80879u), LIFT_CODE_TOKEN_RVA(0x80877u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80886u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80886u));
    label_00080886:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    cpu->esi = 0u;
    if ((cpu->eax & 0xFFu) == 0x61u) goto label_00080894;
    if ((cpu->eax & 0xFFu) != 0x41u) goto label_0008089A;
    label_00080894:
    cpu->esi = 0x80u;
    ++cpu->edi;
    label_0008089A:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edi));
    cpu->eax += 0xFFFFFFBAu;
    if (cpu->eax > 0x2Fu) goto label_000808C5;
    switch (cpu->eax) {
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
    label_000808B6:
    cpu->esi += 2u;
    goto label_000808EB;
    label_000808BB:
    cpu->esi += 3u;
    goto label_000808EB;
    label_000808C0:
    cpu->esi += 4u;
    goto label_000808EB;
    label_000808C5:
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4808D8u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x808EBu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x808EBu));
    label_000808EB:
    if (cpu->esi != 0x83u) goto label_00080918;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480905u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80918u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80918u));
    label_00080918:
    if (*(uint8_t*)(cpu->edi + 1u) == 0x3Eu) goto label_00080944;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480931u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80944u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80944u));
    label_00080944:
    cpu->edi += 2u;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480954u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480954u));
    cpu->edi = native_function_address32(&::sprintf);
    if (cpu->eax != 0u) goto label_00080980;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 9u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80973u), LIFT_CODE_TOKEN_RVA(0x80971u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80980u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80980u));
    label_00080980:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax) == 0x3Du) goto label_000809AB;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xAu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8099Eu), LIFT_CODE_TOKEN_RVA(0x8099Cu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x809ABu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x809ABu));
    label_000809AB:
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4809B8u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x4809B8u));
    if (cpu->eax != 0u) goto label_000809DE;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xBu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x809D1u), LIFT_CODE_TOKEN_RVA(0x809CFu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x809DEu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x809DEu));
    label_000809DE:
    if (cpu->esi == 0u) goto label_00080E2F;
    if (cpu->esi != 0x80u) goto label_00080A9E;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080A00;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080A25;
    label_00080A00:
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_00080A25;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80A18u), LIFT_CODE_TOKEN_RVA(0x80A16u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80A25u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80A25u));
    label_00080A25:
    cpu->ebx = cpu->ebx + cpu->ebp + 0xAu;
    goto label_00080A34;
    label_00080A30:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_00080A34:
    cpu->ebx += 4u;
    label_00080A37:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080A43;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080A37;
    label_00080A43:
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480A50u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480A50u));
    if (cpu->eax == 0u) goto label_00080E77;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx) != 0x2Cu) goto label_00080E77;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480A72u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480A72u));
    if (cpu->eax != 0u) goto label_00080A30;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x11u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480A89u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480A9Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x480A9Cu));
    goto label_00080A30;
    label_00080A9E:
    if (cpu->esi != 1u) goto label_00080AF9;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080AB1;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080ADA;
    label_00080AB1:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00080ADA;
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_00080ADA;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x12u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80ACDu), LIFT_CODE_TOKEN_RVA(0x80ACBu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80ADAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80ADAu));
    label_00080ADA:
    cpu->ebx = cpu->ebx + cpu->ebp + 7u;
    label_00080AE0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080AEC;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080AE0;
    label_00080AEC:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00080AE0;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    goto label_00080E77;
    label_00080AF9:
    if (cpu->esi != 0x81u) goto label_00080BA2;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080B13;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080B25;
    label_00080B13:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00080B25;
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_00080B25;
    cpu->ecx = 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80B25u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80B25u));
    label_00080B25:
    cpu->ebx = cpu->ebx + cpu->ebp + 0xAu;
    goto label_00080B34;
    label_00080B30:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_00080B34:
    cpu->ebx += 4u;
    label_00080B37:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080B43;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080B37;
    label_00080B43:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00080B37;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480B54u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480B54u));
    if (cpu->eax == 0u) goto label_00080E77;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx) != 0x2Cu) goto label_00080E77;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480B76u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480B76u));
    if (cpu->eax != 0u) goto label_00080B30;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x16u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480B8Du));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480BA0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x480BA0u));
    goto label_00080B30;
    label_00080BA2:
    if (cpu->esi != 2u) goto label_00080BFF;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->esi) == 0x22u) goto label_00080BBA;
    cpu->ecx = 0x17u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80BBAu)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80BBAu));
    label_00080BBA:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    cpu->ebx = cpu->ebx + cpu->ebp + 5u;
    if ((cpu->eax & 0xFFu) == 0x22u) goto label_00080BF4;
    label_00080BC6:
    if ((cpu->eax & 0xFFu) != 0u) goto label_00080BEB;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x18u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80BDEu), LIFT_CODE_TOKEN_RVA(0x80BDCu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80BEBu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80BEBu));
    label_00080BEB:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    ++cpu->ebx;
    if ((cpu->eax & 0xFFu) != 0x22u) goto label_00080BC6;
    label_00080BF4:
    ++cpu->ebx;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    goto label_00080E77;
    label_00080BFF:
    if (cpu->esi != 0x82u) goto label_00080CD5;
    cpu->ebx = cpu->ebx + cpu->ebp + 9u;
    (void)cpu;
    label_00080C10:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->esi) == 0x22u) goto label_00080C3B;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x19u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80C2Eu), LIFT_CODE_TOKEN_RVA(0x80C2Cu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80C3Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80C3Bu));
    label_00080C3B:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    cpu->ebx += 2u;
    if ((cpu->eax & 0xFFu) == 0x22u) goto label_00080C75;
    label_00080C46:
    if ((cpu->eax & 0xFFu) != 0u) goto label_00080C6C;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x1Au); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80C5Fu), LIFT_CODE_TOKEN_RVA(0x80C5Du))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80C6Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80C6Cu));
    label_00080C6C:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    ++cpu->ebx;
    if ((cpu->eax & 0xFFu) != 0x22u) goto label_00080C46;
    label_00080C75:
    ++cpu->esi;
    cpu->ecx = cpu->esp + 0x10u;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480C84u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480C84u));
    if (cpu->eax == 0u) goto label_00080E77;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax) != 0x2Cu) goto label_00080E77;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480CA6u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480CA6u));
    if (cpu->eax != 0u) goto label_00080C10;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1Bu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80CC3u), LIFT_CODE_TOKEN_RVA(0x80CC1u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480CD0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x480CD0u));
    goto label_00080C10;
    label_00080CD5:
    if (cpu->esi != 3u) goto label_00080D7E;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080CEC;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080CF6;
    label_00080CEC:
    cpu->ecx = 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80CF6u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80CF6u));
    label_00080CF6:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ebx + cpu->ebp + 7u;
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x480D05u));
    cpu->esp += 0xCu;
    if (cpu->eax == 1u) goto label_00080D20;
    cpu->ecx = 0x1Du;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480D1Du)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_VA(0x480D1Du));
    label_00080D20:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080D2C;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080D20;
    label_00080D2C:
    if (*(uint8_t*)(cpu->esi) == 0x3Au) goto label_00080D3B;
    cpu->ecx = 0x1Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80D3Bu)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80D3Bu));
    label_00080D3B:
    ++cpu->esi;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480D49u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480D49u));
    if (cpu->eax != 0u) goto label_00080D55;
    cpu->ecx = cpu->eax + 0x1Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80D55u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80D55u));
    label_00080D55:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx += cpu->eax;
    cpu->ecx = (cpu->eax * 8u) + 6u;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_00080E77;
    label_00080D7E:
    if (cpu->esi != 4u) goto label_00080DD1;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) = 0u;
    ++cpu->eax;
    cpu->ecx = cpu->esp + 0x10u;
    g_sfera_config_parser_runtime.frame_depth = cpu->eax;
    cpu->ebx = cpu->ebx + cpu->ebp + 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480DA9u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480DA9u));
    if (cpu->eax != 0u) goto label_00080DB5;
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80DB5u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80DB5u));
    label_00080DB5:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edx) == 0x7Bu) goto label_00080DC8;
    cpu->ecx = 0x21u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80DC8u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80DC8u));
    label_00080DC8:
    ++*(uint32_t*)(cpu->esp + 0x10u);
    goto label_00080E77;
    label_00080DD1:
    if (cpu->esi != 0x84u) goto label_00080E25;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->esi = 1u;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) = cpu->esi;
    cpu->ebx = cpu->ebx + cpu->ebp + 0xDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480DFAu)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480DFAu));
    if (cpu->eax != 0u) goto label_00080E06;
    cpu->ecx = cpu->esi + 0x21u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80E06u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80E06u));
    label_00080E06:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx) == 0x7Bu) goto label_00080E19;
    cpu->ecx = 0x23u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80E19u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80E19u));
    label_00080E19:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    g_sfera_config_parser_runtime.frame_depth += cpu->esi;
    goto label_00080E77;
    label_00080E25:
    cpu->ecx = 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80E2Fu)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x80E2Fu));
    label_00080E2F:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080E3D;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080E63;
    label_00080E3D:
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_00080E63;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xDu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80E56u), LIFT_CODE_TOKEN_RVA(0x80E54u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80E63u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80E63u));
    label_00080E63:
    cpu->ebx = cpu->ebx + cpu->ebp + 7u;
    label_00080E67:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00080E77;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00080E67;
    label_00080E77:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480E80u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x480E80u));
    if (cpu->eax != 0u) goto label_00080687;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00080E8B:
    if (g_sfera_config_parser_runtime.frame_depth == 0u) goto label_00080EB9;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480EA6u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80EB9u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80EB9u));
    label_00080EB9:
    cpu->eax = cpu->ebx + 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->eax <= 0) goto label_00080F91;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::sprintf);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_00080F30:
    if (*(uint8_t*)(cpu->esi) == 0u) goto label_00080F3B;
    if (*(uint8_t*)(cpu->esi + 1u) != 0u) goto label_00080F5C;
    label_00080F3B:
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x27u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x80F4Fu), LIFT_CODE_TOKEN_RVA(0x80F4Du))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x80F5Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x80F5Cu));
    label_00080F5C:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    cpu->eax = *(uint8_t*)(cpu->esi);
    cpu->ecx = 7u;
    cpu->ecx -= cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx - 0x30u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->eax -= 0x30u;
    cpu->ecx = cpu->edi;
    cpu->eax = (int32_t)(cpu->eax) >> (((cpu->ecx & 0xFFu)) & 31u);
    ++cpu->ebp;
    ++cpu->esi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFFu) = cpu->edx & 0xFFu;
    if (cpu->edi != 6u) goto label_00080F82;
    ++cpu->esi;
    label_00080F82:
    ++cpu->edi;
    if (cpu->edi != 7u) goto label_00080F8A;
    cpu->edi = 0u;
    label_00080F8A:
    if ((--*(uint32_t*)(cpu->esp + 0x14u)) != 0u) goto label_00080F30;
    cpu->ebx = lift_pop32(cpu);
    label_00080F91:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    label_00080FB0:
    cpu->eax = *(uint8_t*)(cpu->esi);
    ++cpu->esi;
    g_sfera_config_parser_runtime.current_value_type = cpu->eax;
    if (cpu->eax > 0x84u) goto label_0008101C;
    switch (cpu->eax) {
        case 0u: case 1u: goto label_00080FCE;
        case 2u: goto label_00080FE3;
        case 3u: case 4u: case 130u: case 132u: goto label_00080FFB;
        case 5u: case 6u: goto label_00081028;
        case 128u: case 129u: goto label_00081012;
        default: goto label_0008101C;
    }
label_00080FCE: ;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    ++cpu->esi;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80FD5u), LIFT_CODE_TOKEN_RVA(0x80FD3u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00081031;
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->esi += cpu->ecx;
    goto label_00080FB0;
    label_00080FE3:
    cpu->ebx = *(uint16_t*)(cpu->esi);
    cpu->esi += 2u;
    cpu->edx = cpu->esi + 1u;
    label_00080FEC:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x80FF0u), LIFT_CODE_TOKEN_RVA(0x80FEEu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00081031;
    cpu->esi += cpu->ebx;
    goto label_00080FB0;
    label_00080FFB:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->esi += 4u;
    cpu->ecx = cpu->esi + 1u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81007u), LIFT_CODE_TOKEN_RVA(0x81005u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00081031;
    cpu->esi += cpu->ebx;
    goto label_00080FB0;
    label_00081012:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->esi += 4u;
    cpu->edx = cpu->esi + 4u;
    goto label_00080FEC;
    label_0008101C:
    cpu->ecx = (uintptr_t)"getCfg: wrong address or corrupted data";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481026u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x481026u));
    goto label_00080FB0;
    label_00081028:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00081031:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_00081057;
    if (cpu->eax == g_sfera_config_parser_runtime.current_value_type) goto label_0008106C;
    cpu->ecx = (uintptr_t)"getCfg: wrong type of parameter. Name:";
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48104Eu)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_VA(0x48104Eu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00081057:
    if (((((uint8_t)g_sfera_config_parser_runtime.current_value_type)) & (0x80u)) != 0u) goto label_0008106C;
    cpu->ecx = (uintptr_t)"getCfg: get size for non array. Name:";
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8106Cu)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x8106Cu));
    label_0008106C:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00481120(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481127u)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x481127u));
    if (cpu->eax != 0u) goto label_0008112E;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008112E:
    cpu->ecx = *(uint8_t*)(cpu->eax + 0xFFFFFFFFu);
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->eax + 0xFFFFFFFCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00481150(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481157u)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x481157u));
    if (cpu->eax != 0u) goto label_0008115E;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008115E:
    cpu->ecx = *(uint8_t*)(cpu->eax + 0xFFFFFFFFu);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + cpu->eax + 0xFFFFFFFCu);
    cpu->eax = 1u;
    *(float*)(cpu->edx) = x87_v0; 
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00481180(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481187u)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x481187u));
    if (cpu->eax != 0u) goto label_0008118E;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008118E:
    cpu->ecx = *(uint8_t*)(cpu->eax);
    cpu->edx = cpu->ecx + cpu->eax + 1u;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004811B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4811B7u)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x4811B7u));
    if (cpu->eax == 0u) goto label_000811E6;
    cpu->ecx = g_sfera_config_parser_runtime.current_value_type;
    cpu->ecx += 0xFFFFFF80u;
    if (cpu->ecx > 4u) goto label_000811DC;
    switch (cpu->ecx) {
        case 0u: case 1u: goto label_000811D0;
        case 2u: case 4u: goto label_000811D3;
        case 3u: goto label_000811DC;
        default: lift_trap(cpu, 0x4811C9u, "resolved jump-table index out of range"); return;
    }
label_000811D0: ;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000811D3:
    cpu->ecx = *(uint8_t*)(cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->ecx + cpu->eax + 1u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000811DC:
    cpu->ecx = (uintptr_t)"getCfgArraySize: internal error";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x811E6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x811E6u));
    label_000811E6:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00481200(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x80u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48120Bu)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x48120Bu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00081215;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00081215:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->edi < 0) goto label_00081222;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi)) goto label_0008122C;
    label_00081222:
    cpu->ecx = (uintptr_t)"getCfg: index out of range";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8122Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8122Cu));
    label_0008122C:
    cpu->edi -= *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx = cpu->eax + (cpu->edi * 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00481250(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x81u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48125Bu)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x48125Bu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00081265;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00081265:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->edi < 0) goto label_00081272;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi)) goto label_0008127C;
    label_00081272:
    cpu->ecx = (uintptr_t)"getCfg: index out of range";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8127Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8127Cu));
    label_0008127C:
    cpu->edi -= *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax + (cpu->edi * 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->edx) = x87_v0; 
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004812A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x82u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4812ABu)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x4812ABu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_000812B5;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000812B5:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->edi < 0) goto label_000812CA;
    cpu->eax = *(uint8_t*)(cpu->esi);
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax + cpu->esi + 1u));
    if ((int32_t)cpu->edi < (int32_t)cpu->ecx) goto label_000812D4;
    label_000812CA:
    cpu->ecx = (uintptr_t)"getCfg: index out of range";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x812D4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x812D4u));
    label_000812D4:
    cpu->edx = *(uint8_t*)(cpu->esi);
    cpu->eax = cpu->edx + cpu->esi + 3u;
    if (cpu->edi == 0u) goto label_000812EA;
    (void)cpu;
    label_000812E0:
    --cpu->edi;
    cpu->ecx = *(uint16_t*)(cpu->eax);
    cpu->eax = cpu->eax + cpu->ecx + 2u;
    if (cpu->edi != 0u) goto label_000812E0;
    label_000812EA:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += 2u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00481300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x84u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48130Bu)); sfera_sub_00480FA0(cpu, LIFT_CODE_TOKEN_VA(0x48130Bu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00081315;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00081315:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->edi < 0) goto label_0008132A;
    cpu->eax = *(uint8_t*)(cpu->esi);
    cpu->ecx = *(uint16_t*)(cpu->eax + cpu->esi + 1u);
    if ((int32_t)cpu->edi < (int32_t)cpu->ecx) goto label_00081334;
    label_0008132A:
    cpu->ecx = (uintptr_t)"getCfg: index out of range";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81334u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81334u));
    label_00081334:
    cpu->edx = *(uint8_t*)(cpu->esi);
    cpu->eax = cpu->edx + cpu->esi + 3u;
    if (cpu->edi == 0u) goto label_00081349;
    (void)cpu;
    label_00081340:
    --cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->eax + cpu->ecx + 4u;
    if (cpu->edi != 0u) goto label_00081340;
    label_00081349:
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00481360(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = 0u;
    cpu->ebx = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esi) <= (int32_t)cpu->edi) goto label_00081397;
    label_00081372:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x481379u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00081392;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)"openCfg: duplicate name: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81392u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x81392u));
    label_00081392:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi)) goto label_00081372;
    label_00081397:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    if (*(uint32_t*)(cpu->esi) != cpu->eax) goto label_000813BA;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, 0x410u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp");
    cpu->edx = cpu->eax + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4813B5u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x4813B5u));
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    *(uint32_t*)(cpu->edi) = (uint64_t)(*(uint32_t*)(cpu->edi)) + (uint64_t)(0x64u) + (uint64_t)(0u);
    label_000813BA:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u)) = cpu->ebp;
    ++*(uint32_t*)(cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004813D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x422u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = 0x190u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4813F5u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4813F5u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    label_00081401:
    cpu->edi = *(uint8_t*)(cpu->esi);
    ++cpu->esi;
    if (cpu->edi > 0x84u) goto label_000814EA;
    switch (cpu->edi) {
        case 0u: case 1u: goto label_0008141F;
        case 2u: goto label_0008143C;
        case 3u: case 4u: case 130u: case 132u: goto label_0008145C;
        case 5u: case 6u: goto label_000814F9;
        case 128u: case 129u: goto label_000814C8;
        default: goto label_000814EA;
    }
label_0008141F: ;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    ++cpu->esi;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481435u)); sfera_sub_00481360(cpu, LIFT_CODE_TOKEN_VA(0x481435u));
    cpu->edx = cpu->ebx & 0xFFu;
    cpu->esi += cpu->edx;
    goto label_00081401;
    label_0008143C:
    cpu->edi = *(uint16_t*)(cpu->esi);
    cpu->esi += 2u;
    cpu->eax = cpu->esi + 1u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481458u)); sfera_sub_00481360(cpu, LIFT_CODE_TOKEN_VA(0x481458u));
    cpu->esi += cpu->edi;
    goto label_00081401;
    label_0008145C:
    cpu->ebp = *(uint32_t*)(cpu->esi);
    cpu->esi += 4u;
    cpu->eax = cpu->esi + 1u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481477u)); sfera_sub_00481360(cpu, LIFT_CODE_TOKEN_VA(0x481477u));
    if (cpu->edi != 4u) goto label_0008148F;
    cpu->edx = *(uint8_t*)(cpu->esi);
    cpu->ecx = cpu->edx + cpu->esi + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481488u)); sfera_sub_004813D0(cpu, LIFT_CODE_TOKEN_VA(0x481488u));
    cpu->esi += cpu->ebp;
    goto label_00081401;
    label_0008148F:
    if (cpu->edi != 0x84u) goto label_000814C1;
    cpu->eax = *(uint8_t*)(cpu->esi);
    cpu->ecx = *(uint16_t*)(cpu->eax + cpu->esi + 1u);
    cpu->edi = cpu->eax + cpu->esi + 3u;
    if ((int32_t)cpu->ecx <= 0) goto label_000814C1;
    cpu->ebx = cpu->ecx;
    label_000814B0:
    cpu->ecx = cpu->edi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4814B8u)); sfera_sub_004813D0(cpu, LIFT_CODE_TOKEN_VA(0x4814B8u));
    --cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edi = cpu->edi + cpu->ecx + 4u;
    if (cpu->ebx != 0u) goto label_000814B0;
    label_000814C1:
    cpu->esi += cpu->ebp;
    goto label_00081401;
    label_000814C8:
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->esi += 4u;
    cpu->edx = cpu->esi + 4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4814E3u)); sfera_sub_00481360(cpu, LIFT_CODE_TOKEN_VA(0x4814E3u));
    cpu->esi += cpu->edi;
    goto label_00081401;
    label_000814EA:
    cpu->ecx = (uintptr_t)"getCfg: wrong address or corrupted data";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4814F4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4814F4u));
    goto label_00081401;
    label_000814F9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0x44Bu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48150Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x48150Cu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004815C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x4A3u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4815CFu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4815CFu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004815D0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_config_parser_runtime.open_mode = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004815E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    g_sfera_config_parser_runtime.line_number = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481602u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481602u));
    cpu->edi = native_function_address32(&::sprintf);
    if (cpu->eax == 0u) goto label_000820E9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    label_00081612:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((cpu->eax & 0xFFu) != 0x7Du) goto label_0008176B;
    if (g_sfera_config_parser_runtime.frame_depth != 0u) goto label_0008164B;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x24u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8163Eu), LIFT_CODE_TOKEN_RVA(0x8163Cu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8164Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8164Bu));
    label_0008164B:
    *(uint8_t*)(cpu->esi) = 5u;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->ebx = 1u;
    cpu->eax -= cpu->ebx;
    g_sfera_config_parser_runtime.frame_depth = cpu->eax;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->esi += cpu->ebx;
    cpu->eax += cpu->eax;
    cpu->ecx = cpu->esi;
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) != 0u) goto label_0008168B;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin));
    cpu->ecx -= cpu->eax;
    cpu->ecx -= 4u;
    cpu->ebp += cpu->ebx;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    goto label_000820D6;
    label_0008168B:
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].count_or_cursor));
    *(uint16_t*)(cpu->eax) = (uint64_t)(*(uint16_t*)(cpu->eax)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u);
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end));
    cpu->ecx -= cpu->eax;
    cpu->ecx -= 4u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebp += cpu->ebx;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4816B9u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x4816B9u));
    if (cpu->eax == 0u) goto label_0008174E;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edx) != 0x2Cu) goto label_0008174E;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) = cpu->esi;
    cpu->eax += cpu->ebx;
    cpu->ecx = cpu->esp + 0x10u;
    cpu->esi += 4u;
    g_sfera_config_parser_runtime.frame_depth = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4816F4u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x4816F4u));
    if (cpu->eax != 0u) goto label_0008171A;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x25u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8170Du), LIFT_CODE_TOKEN_RVA(0x8170Bu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8171Au)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8171Au));
    label_0008171A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax) == 0x7Bu) goto label_00081745;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x26u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81738u), LIFT_CODE_TOKEN_RVA(0x81736u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81745u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81745u));
    label_00081745:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    goto label_000820D6;
    label_0008174E:
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin));
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->ecx -= 4u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_000820D6;
    label_0008176B:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x61u) goto label_00081773;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x7Au) goto label_000817A1;
    label_00081773:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x41u) goto label_0008177B;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x5Au) goto label_000817A1;
    label_0008177B:
    if ((cpu->eax & 0xFFu) == 0x5Fu) goto label_000817A1;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81794u), LIFT_CODE_TOKEN_RVA(0x81792u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x817A1u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x817A1u));
    label_000817A1:
    cpu->ebx = 0u;
    label_000817A3:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    *(uint8_t*)(cpu->ebx + ((uintptr_t)&g_sfera_config_parser_runtime.token[0])) = cpu->eax & 0xFFu;
    ++cpu->ebx;
    ++cpu->ebp;
    if ((int32_t)cpu->ebx <= (int32_t)0xFAu) goto label_000817D8;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x817CBu), LIFT_CODE_TOKEN_RVA(0x817C9u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x817D8u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x817D8u));
    label_000817D8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x61u) goto label_000817E3;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x7Au) goto label_000817A3;
    label_000817E3:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x41u) goto label_000817EB;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x5Au) goto label_000817A3;
    label_000817EB:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_000817F3;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_000817A3;
    label_000817F3:
    if ((cpu->eax & 0xFFu) == 0x5Fu) goto label_000817A3;
    *(uint8_t*)(cpu->ebx + ((uintptr_t)&g_sfera_config_parser_runtime.token[0])) = 0u;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48180Cu)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x48180Cu));
    if (cpu->eax != 0u) goto label_00081832;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81825u), LIFT_CODE_TOKEN_RVA(0x81823u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81832u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81832u));
    label_00081832:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ebp) == 0x3Cu) goto label_0008185D;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 5u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81850u), LIFT_CODE_TOKEN_RVA(0x8184Eu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8185Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8185Du));
    label_0008185D:
    ++cpu->ebp;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((cpu->eax & 0xFFu) == 0x61u) goto label_0008186C;
    if ((cpu->eax & 0xFFu) != 0x41u) goto label_00081870;
    label_0008186C:
    *(uint8_t*)(cpu->esi) = 0x80u;
    ++cpu->ebp;
    label_00081870:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ebp));
    cpu->eax += 0xFFFFFFBAu;
    if (cpu->eax > 0x2Fu) goto label_0008189D;
    switch (cpu->eax) {
        case 0u: case 32u: goto label_0008188A;
        case 3u: case 35u: goto label_000818BF;
        case 13u: case 45u: goto label_00081898;
        case 14u: case 46u: goto label_0008188E;
        case 15u: case 47u: goto label_00081893;
        default: goto label_0008189D;
    }
label_0008188A: ;
    ++*(uint8_t*)(cpu->esi);
    goto label_000818BF;
    label_0008188E:
    *(uint8_t*)(cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->esi)) + (uint64_t)(2u) + (uint64_t)(0u);
    goto label_000818BF;
    label_00081893:
    *(uint8_t*)(cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->esi)) + (uint64_t)(3u) + (uint64_t)(0u);
    goto label_000818BF;
    label_00081898:
    *(uint8_t*)(cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->esi)) + (uint64_t)(4u) + (uint64_t)(0u);
    goto label_000818BF;
    label_0008189D:
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x818B2u), LIFT_CODE_TOKEN_RVA(0x818B0u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x818BFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x818BFu));
    label_000818BF:
    if (*(uint8_t*)(cpu->esi) != 0x83u) goto label_000818E5;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x818D8u), LIFT_CODE_TOKEN_RVA(0x818D6u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x818E5u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x818E5u));
    label_000818E5:
    if (*(uint8_t*)(cpu->ebp + 1u) == 0x3Eu) goto label_0008190D;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81900u), LIFT_CODE_TOKEN_RVA(0x818FEu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8190Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8190Du));
    label_0008190D:
    cpu->ebp += 2u;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48191Du)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x48191Du));
    if (cpu->eax != 0u) goto label_00081943;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 9u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81936u), LIFT_CODE_TOKEN_RVA(0x81934u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81943u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81943u));
    label_00081943:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax) == 0x3Du) goto label_0008196E;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xAu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81961u), LIFT_CODE_TOKEN_RVA(0x8195Fu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8196Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8196Eu));
    label_0008196E:
    cpu->ebp = 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481980u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481980u));
    if (cpu->eax != 0u) goto label_000819A6;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xBu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81999u), LIFT_CODE_TOKEN_RVA(0x81997u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x819A6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x819A6u));
    label_000819A6:
    cpu->eax = *(uint8_t*)(cpu->esi);
    cpu->esi += cpu->ebp;
    if (cpu->eax == 0u) goto label_0008203A;
    if (cpu->eax != 0x80u) goto label_00081AD5;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_000819CD;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_000819F2;
    label_000819CD:
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_000819F2;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x819E5u), LIFT_CODE_TOKEN_RVA(0x819E3u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x819F2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x819F2u));
    label_000819F2:
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edi = cpu->esi + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->esi += 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->edi) = 0u;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481A0Eu));
    cpu->esp += 0xCu;
    cpu->esi += cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    goto label_00081A24;
    label_00081A20:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    label_00081A24:
    *(uint32_t*)(cpu->ebx) = (uint64_t)(*(uint32_t*)(cpu->ebx)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++*(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481A30u));
    cpu->esp += 0xCu;
    if (cpu->eax == 1u) goto label_00081A64;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481A51u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81A64u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81A64u));
    label_00081A64:
    cpu->esi += 4u;
    label_00081A67:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 1u));
    ++cpu->ebp;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00081A73;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00081A67;
    label_00081A73:
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481A80u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481A80u));
    if (cpu->eax == 0u) goto label_000820D0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax) != 0x2Cu) goto label_000820D0;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481AA2u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481AA2u));
    if (cpu->eax != 0u) goto label_00081A20;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x11u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481ABDu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481AD0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x481AD0u));
    goto label_00081A20;
    label_00081AD5:
    if (cpu->eax != cpu->ebp) goto label_00081B7E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00081AEC;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00081B16;
    label_00081AEC:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00081B16;
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_00081B16;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x12u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81B09u), LIFT_CODE_TOKEN_RVA(0x81B07u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81B16u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81B16u));
    label_00081B16:
    cpu->eax = cpu->ebx + 4u;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    ++cpu->esi;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481B23u));
    cpu->esi += cpu->ebx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481B32u));
    cpu->esp += 0x18u;
    if (cpu->eax == 1u) goto label_00081B62;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x13u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x81B55u), LIFT_CODE_TOKEN_RVA(0x81B53u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81B62u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81B62u));
    label_00081B62:
    cpu->esi += 4u;
    label_00081B65:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 1u));
    ++cpu->ebp;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00081B71;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00081B65;
    label_00081B71:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00081B65;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    goto label_000820D6;
    label_00081B7E:
    if (cpu->eax != 0x81u) goto label_00081C94;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00081B98;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00081BAA;
    label_00081B98:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00081BAA;
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_00081BAA;
    cpu->ecx = 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81BAAu)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81BAAu));
    label_00081BAA:
    cpu->edx = cpu->ebx + 4u;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->edi = cpu->esi + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->esi += 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->edi) = 0u;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481BC6u));
    cpu->esp += 0xCu;
    cpu->esi += cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    goto label_00081BE0;
    label_00081BD7:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    label_00081BE0:
    *(uint32_t*)(cpu->ebx) = (uint64_t)(*(uint32_t*)(cpu->ebx)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++*(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481BECu));
    cpu->esp += 0xCu;
    if (cpu->eax == 1u) goto label_00081C1F;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x15u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481C0Cu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81C1Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81C1Fu));
    label_00081C1F:
    cpu->esi += 4u;
    label_00081C22:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 1u));
    ++cpu->ebp;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00081C2E;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00081C22;
    label_00081C2E:
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_00081C22;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481C3Fu)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481C3Fu));
    if (cpu->eax == 0u) goto label_000820D0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx) != 0x2Cu) goto label_000820D0;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481C61u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481C61u));
    if (cpu->eax != 0u) goto label_00081BD7;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x16u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481C7Cu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481C8Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x481C8Fu));
    goto label_00081BD7;
    label_00081C94:
    if (cpu->eax != 2u) goto label_00081D25;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ebp) == 0x22u) goto label_00081CAF;
    cpu->ecx = cpu->eax + 0x15u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81CAFu)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81CAFu));
    label_00081CAF:
    cpu->eax = cpu->ebx + 2u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi + 2u) = cpu->ebx & 0xFFu;
    cpu->edi = cpu->esi;
    cpu->esi += 3u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    ++cpu->ebp;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481CC5u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    cpu->esp += 0xCu;
    cpu->esi += cpu->ebx;
    if ((cpu->eax & 0xFFu) == 0x22u) goto label_00081D17;
    cpu->ebx = native_function_address32(&::sprintf);
    label_00081CE0:
    if ((cpu->eax & 0xFFu) != 0u) goto label_00081D06;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x18u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x81CF9u), LIFT_CODE_TOKEN_RVA(0x81CF7u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81D06u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81D06u));
    label_00081D06:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    ++*(uint16_t*)(cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 1u));
    ++cpu->ebp;
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0x22u) goto label_00081CE0;
    label_00081D17:
    *(uint8_t*)(cpu->esi) = 0u;
    ++cpu->esi;
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    goto label_000820D0;
    label_00081D25:
    if (cpu->eax != 0x82u) goto label_00081E54;
    cpu->eax = cpu->ebx + 3u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi + 4u) = cpu->ebx & 0xFFu;
    cpu->ebp = cpu->esi;
    cpu->esi += 5u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481D44u));
    cpu->esi += cpu->ebx;
    cpu->ecx = 0u;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(uint16_t*)(cpu->esi) = cpu->ecx & 0xFFFFu;
    cpu->esi += 2u;
    label_00081D60:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edi) == 0x22u) goto label_00081D8F;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x19u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481D7Cu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81D8Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81D8Fu));
    label_00081D8F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    ++*(uint16_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp) = (uint64_t)(*(uint32_t*)(cpu->ebp)) + (uint64_t)(3u) + (uint64_t)(0u);
    cpu->eax = 1u;
    ++cpu->edi;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->ebx = cpu->esi;
    cpu->esi += 2u;
    if ((cpu->eax & 0xFFu) == 0x22u) goto label_00081DED;
    label_00081DB0:
    if ((cpu->eax & 0xFFu) != 0u) goto label_00081DDA;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1Au); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481DC7u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81DDAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x81DDAu));
    label_00081DDA:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    ++*(uint32_t*)(cpu->ebp);
    ++*(uint16_t*)(cpu->ebx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0x22u) goto label_00081DB0;
    label_00081DED:
    *(uint8_t*)(cpu->esi) = 0u;
    ++cpu->edi;
    cpu->ecx = cpu->esp + 0x10u;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481DFFu)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481DFFu));
    if (cpu->eax == 0u) goto label_000820D0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax) != 0x2Cu) goto label_000820D0;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481E21u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481E21u));
    if (cpu->eax != 0u) goto label_00081D60;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1Bu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481E3Cu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481E4Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x481E4Fu));
    goto label_00081D60;
    label_00081E54:
    if (cpu->eax != 3u) goto label_00081F2E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00081E6C;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00081E76;
    label_00081E6C:
    cpu->ecx = 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81E76u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81E76u));
    label_00081E76:
    cpu->edx = cpu->ebx + 1u;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi + 4u) = cpu->ebx & 0xFFu;
    cpu->edi = cpu->esi;
    cpu->esi += 5u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481E8Au));
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->ebp);
    cpu->esi += cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481E9Du));
    cpu->esp += 0x18u;
    if (cpu->eax == 1u) goto label_00081EB5;
    cpu->ecx = 0x1Du;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81EB5u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81EB5u));
    label_00081EB5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 1u));
    ++cpu->ebp;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00081EC1;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_00081EB5;
    label_00081EC1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi) = (uint64_t)(*(uint32_t*)(cpu->edi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    if (*(uint8_t*)(cpu->ebp) == 0x3Au) goto label_00081ED7;
    cpu->ecx = 0x1Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81ED7u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81ED7u));
    label_00081ED7:
    ++cpu->ebp;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481EE5u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481EE5u));
    if (cpu->eax != 0u) goto label_00081EF1;
    cpu->ecx = cpu->eax + 0x1Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81EF1u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81EF1u));
    label_00081EF1:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481F03u)); sfera_sub_00480F10(cpu, LIFT_CODE_TOKEN_VA(0x481F03u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi += cpu->eax;
    cpu->ecx = (cpu->eax * 8u) + 6u;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->ebx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    goto label_000820D0;
    label_00081F2E:
    if (cpu->eax != 4u) goto label_00081FA2;
    cpu->ecx = g_sfera_config_parser_runtime.frame_depth;
    cpu->eax = cpu->ecx + (cpu->ecx * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin)) = cpu->esi;
    cpu->ecx += cpu->ebp;
    cpu->esi += 4u;
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) = 0u;
    g_sfera_config_parser_runtime.frame_depth = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    cpu->esi += cpu->ebp;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481F66u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x10u;
    cpu->esi += cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x481F7Au)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x481F7Au));
    if (cpu->eax != 0u) goto label_00081F86;
    cpu->ecx = cpu->eax + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81F86u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81F86u));
    label_00081F86:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx) == 0x7Bu) goto label_00081F99;
    cpu->ecx = 0x21u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x81F99u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x81F99u));
    label_00081F99:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    goto label_000820D6;
    label_00081FA2:
    if (cpu->eax != 0x84u) goto label_00082030;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin)) = cpu->esi;
    cpu->esi += 4u;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    cpu->esi += cpu->ebp;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481FCAu));
    cpu->eax = 0u;
    *(uint16_t*)(cpu->esi + cpu->ebx) = cpu->eax & 0xFFFFu;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->esi += cpu->ebx;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].count_or_cursor)) = cpu->esi;
    cpu->esi += 2u;
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end)) = cpu->esi;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x10u;
    cpu->esi += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482002u)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x482002u));
    if (cpu->eax != 0u) goto label_0008200E;
    cpu->ecx = cpu->eax + 0x22u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8200Eu)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x8200Eu));
    label_0008200E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx) == 0x7Bu) goto label_00082021;
    cpu->ecx = 0x23u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x82021u)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x82021u));
    label_00082021:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    g_sfera_config_parser_runtime.frame_depth += cpu->ebp;
    goto label_000820D6;
    label_00082030:
    cpu->ecx = 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8203Au)); sfera_sub_00480630(cpu, LIFT_CODE_TOKEN_RVA(0x8203Au));
    label_0008203A:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_00082049;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_0008206F;
    label_00082049:
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_0008206F;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xDu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82062u), LIFT_CODE_TOKEN_RVA(0x82060u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8206Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x8206Fu));
    label_0008206F:
    cpu->eax = cpu->ebx + 4u;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    ++cpu->esi;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x48207Cu));
    cpu->esi += cpu->ebx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x48208Bu));
    cpu->esp += 0x18u;
    if (cpu->eax == 1u) goto label_000820BB;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xEu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x820AEu), LIFT_CODE_TOKEN_RVA(0x820ACu))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x820BBu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x820BBu));
    label_000820BB:
    cpu->esi += 4u;
    label_000820C0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 1u));
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_000820D0;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_000820C0;
    label_000820D0:
    cpu->edi = native_function_address32(&::sprintf);
    label_000820D6:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4820DFu)); sfera_sub_004805D0(cpu, LIFT_CODE_TOKEN_VA(0x4820DFu));
    if (cpu->eax != 0u) goto label_00081612;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000820E9:
    if (g_sfera_config_parser_runtime.frame_depth == 0u) goto label_00082114;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82107u), LIFT_CODE_TOKEN_RVA(0x82105u))) { return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x82114u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x82114u));
    label_00082114:
    cpu->eax = cpu->esi;
    cpu->eax -= *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi) = 6u;
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
