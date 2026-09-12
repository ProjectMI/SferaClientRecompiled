#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static int sfera_cp1251_is_russian_vowel_or_sign(uint8_t value) { switch (value) { case UINT8_C(0xF3): case UINT8_C(0xE5): case UINT8_C(0xFB): case UINT8_C(0xE0): case UINT8_C(0xEE): case UINT8_C(0xFD): case UINT8_C(0xFF): case UINT8_C(0xE8): case UINT8_C(0xFE): case UINT8_C(0xFC): case UINT8_C(0xFA): return 1; default: return 0; } }
static int sfera_identifier_char_is_keyboard_ambiguous(uint8_t value) { switch (value) { case UINT8_C(0xE5): case 'e': case UINT8_C(0xF3): case 'y': case UINT8_C(0xEA): case 'k': case UINT8_C(0xE3): case 'r': case UINT8_C(0xE7): case '3': case UINT8_C(0xF5): case 'x': case UINT8_C(0xE8): case 'u': case UINT8_C(0xEE): case '0': case 'o': case UINT8_C(0xF0): case 'p': case UINT8_C(0xF1): case 'c': case UINT8_C(0xE0): case 'a': case UINT8_C(0xF2): case 'm': case 'E': case UINT8_C(0xC5): case UINT8_C(0xD3): case 'Y': case 'K': case UINT8_C(0xCA): case UINT8_C(0xC7): case 'X': case UINT8_C(0xD5): case 'O': case UINT8_C(0xCE): case UINT8_C(0xD0): case 'P': case 'C': case UINT8_C(0xD1): case 'A': case UINT8_C(0xC0): return 1; default: return 0; } }
static void sfera_apply_character_alias_group(uint32_t* table, const char* group) { const uint32_t canonical = (uint8_t)group[0]; for (uint32_t alias_index = 1u; group[alias_index] != 0; ++alias_index) { const uint32_t alias = (uint8_t)group[alias_index]; for (uint32_t index = 0u; index < kMaterialFilterCharCount; ++index) { if (table[index] == alias) { table[index] = canonical; } } } }
__declspec(noinline) void sfera_sub_00477FB0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26;
    const SphereRender::Material* activeMaterial = nullptr;
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
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::ContactQuery::lineOfSight(cpu->ecx));
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
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); *destination = SferaMatrix4x4F::fromEuler(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->edx)); cpu->eax = SferaAbi::address(destination); }; cpu->esp += 4u;
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
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    cpu->edi += 0xCu;
    cpu->esi += 0xCu;
    if ((--*(uint32_t*)(cpu->esp + 0x14u)) != 0u) goto label_000780A4;
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0x94u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    cpu->eax = static_cast<std::uint32_t>((static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) <= 0 ? 0 : SferaAbi::pointer<const SferaFrustumF>(cpu->ecx)->classifyPoints(std::span<const SferaVec3F>(SferaAbi::pointer<const SferaVec3F>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
    g_sfera_client_main_scalar_runtime.mode_01 = cpu->eax;
    if (cpu->eax == 0u) goto label_00079092;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ecx = cpu->edi;
    WorldDebugDraw::drawBounds(cpu->ecx);
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
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    SferaVec3F::rotatePair(*SferaAbi::pointer<float>(cpu->ecx), *SferaAbi::pointer<float>(cpu->edx), *SferaAbi::pointer<const float>(cpu->esp)); cpu->esp += 4u;
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
    g_sfera_light_runtime.setDirectionalLight(SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const float>(cpu->esp + 20u)});  cpu->esp += 24u;
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
    cpu->edi = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0].position.y;
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
    SphereWorld::ContactQuery::updateBounds(cpu->ecx);
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
    g_sfera_graphics_runtime.d3d_runtime->setWhiteMaterial(*SferaAbi::pointer<const float>(cpu->esp)); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
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
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4789D4u)); sfera_sub_0048D170(cpu, LIFT_CODE_TOKEN_VA(0x4789D4u));
    activeMaterial = g_sfera_materials.at(*SferaAbi::pointer<const std::uint16_t>(cpu->esi + 2u));
    if (activeMaterial == nullptr) throw std::out_of_range("Model material index");
    x87_p0 = activeMaterial->color[0];
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.basis[2].x.f32));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    x87_p0 = activeMaterial->color[1];
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.basis[2].y.f32));
    cpu->ebp = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    x87_p0 = activeMaterial->color[2];
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->edx = cpu->eax & 0xFFu;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->edx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x8Bu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    activeMaterial = g_sfera_materials.at(*SferaAbi::pointer<const std::uint16_t>(cpu->esi + 2u));
    if (activeMaterial == nullptr) throw std::out_of_range("Model material index");
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x144u);
    cpu->edi = static_cast<std::uint32_t>(activeMaterial->textures.at(cpu->eax));
    if (*(uint32_t*)(cpu->esp + 0x18u) == cpu->edi) goto label_00078AA7;
    cpu->ecx = cpu->edi;
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(cpu->ecx));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(cpu->ecx));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
label_00078AA7:
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices32.lock(static_cast<std::int32_t>(cpu->ecx)));
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
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices32.buffer.get());
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->eax)->native_buffer);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "VertexBuffer::Unlock")); cpu->esp += 4u;
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
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.lock(static_cast<std::int32_t>(cpu->ecx)));
    cpu->ecx = cpu->edi + cpu->edi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_collision_scratch_runtime.dynamic_indices_aux[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x478BA0u));
    cpu->edx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.buffer.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->edx)->native_buffer);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "IndexBuffer::Unlock")); cpu->esp += 4u;
    cpu->ecx = g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position;
    cpu->edx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.buffer.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->edx)->native_buffer);
    cpu->edx = g_sfera_graphics_runtime.d3d_runtime->vertices32.position;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices32.buffer.get());
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->eax)->native_buffer);
    lift_push32(cpu, cpu->edx);
    cpu->ebp |= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 4u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->drawBuffer(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 32u)); cpu->esp += 36u;
    g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position = (uint64_t)((g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->edx = *(uint16_t*)(cpu->esi + 0xAu);
    g_sfera_graphics_runtime.d3d_runtime->vertices32.position = (uint64_t)((g_sfera_graphics_runtime.d3d_runtime->vertices32.position)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
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
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetMaterial(SferaAbi::pointer<const D3DMATERIAL9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))), "SetMaterial")); cpu->esp += 4u;
    { const double lift_right=(double)*(float*)(cpu->esi + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_00078D4C; }
    lift_push32(cpu, 0x44u);
    cpu->ecx = cpu->esp + 0x94u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x478CD5u));
    x87_p0 = 1.0;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
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
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetMaterial(SferaAbi::pointer<const D3DMATERIAL9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))), "SetMaterial")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
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
    *SferaAbi::pointer<SferaVec3F>(cpu->ecx) = SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}.normalized(static_cast<std::int32_t>(cpu->edx)); cpu->eax = cpu->ecx; cpu->edx = sfera_f32_bits(SferaAbi::pointer<SferaVec3F>(cpu->ecx)->z); cpu->esp += 12u;
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_world_spatial.gatherShadowTriangles(*SferaAbi::pointer<const SphereWorld::Bounds>(cpu->ecx), {*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, *SferaAbi::pointer<const float>(cpu->esp + 12u), {*SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const float>(cpu->esp + 20u), *SferaAbi::pointer<const float>(cpu->esp + 24u)}, {*SferaAbi::pointer<const float>(cpu->esp + 28u), *SferaAbi::pointer<const float>(cpu->esp + 32u), *SferaAbi::pointer<const float>(cpu->esp + 36u)}));  cpu->esp += 40u;
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->LightEnable(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) != 0u), "LightEnable")); cpu->esp += 8u;
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
    cpu->eip = 0x4790B5u; ::DebugBreak(); return;
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
    g_sfera_interface.showLoadingScreen((cpu->ecx & 255u) != 0u, static_cast<std::int32_t>(cpu->edx), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), (*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) & 255u) != 0u); cpu->esp += 8u;
    cpu->esi = native_function_address32(&::Sleep);

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABB2u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x47ABB2u));
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABBFu)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x47ABBFu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABC6u)); sfera_sub_0042AFB0(cpu, LIFT_CODE_TOKEN_VA(0x47ABC6u));

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABCFu)); sfera_sub_0042A630(cpu, LIFT_CODE_TOKEN_VA(0x47ABCFu));

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->ecx = (uintptr_t)"models\\materls.mtr";
    g_sfera_materials.load(SferaAbi::pointer<const char>(cpu->ecx));

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    TerrainAssets::loadMap();

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x42C7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ABF9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47ABF9u));
    lift_push32(cpu, 0x1030u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC03u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x47AC03u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AC57u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x47AC57u));
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

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    g_sfera_models.initialize();
    g_sfera_models.addFolder("models\\");
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_0007ACF8;
    lift_push32(cpu, (uintptr_t)"models_hr\\");
    g_sfera_models.addFolder(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    label_0007ACF8:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == 0u) goto label_0007AD11;
    lift_push32(cpu, (uintptr_t)"models_ph\\");
    g_sfera_models.addFolder(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    label_0007AD11:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == 0u) goto label_0007AD2A;
    lift_push32(cpu, (uintptr_t)"models_rd\\");
    g_sfera_models.addFolder(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    label_0007AD2A:
    g_sfera_models.finishRegistration();
    cpu->edx = 0x42DCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x10u) = (uintptr_t)"xadd\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AD4Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AD4Cu));
    lift_push32(cpu, 0x7540u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AD56u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x47AD56u));
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

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x42E3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47ADBAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47ADBAu));
    cpu->eax = SferaAbi::address(new Contours(2000, 2999));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    label_0007ADEF:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_client_process_runtime.client_object = cpu->eax;
    SferaAbi::pointer<Contours>(cpu->ecx)->load();

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x42F3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE15u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AE15u));
    lift_push32(cpu, 0x7E80u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE1Fu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x47AE1Fu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AE73u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x47AE73u));
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

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    g_sfera_vegetation.patterns.loadPlanting();
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"cam_cube";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_world_objects.create(SferaAbi::pointer<const char>(cpu->ecx), cpu->edx, *SferaAbi::pointer<const std::uint32_t>(cpu->esp), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) != 0u));  cpu->esp += 8u;
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_world_objects.create(SferaAbi::pointer<const char>(cpu->ecx), cpu->edx, *SferaAbi::pointer<const std::uint32_t>(cpu->esp), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) != 0u));  cpu->esp += 8u;
    g_sfera_vegetation.initialize();

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x4304u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AF0Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x47AF0Eu));
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47AF15u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x47AF15u));
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
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    g_sfera_vegetation.updateCells();
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
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    SferaAbi::pointer<SphereWorld::DynamicVegetation>(cpu->ecx)->acquire();
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_main_render_runtime.grass_depth_mode) != cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    SferaAbi::pointer<SphereWorld::DynamicVegetation>(cpu->ecx)->setDepthMode(*SferaAbi::pointer<const std::uint32_t>(cpu->esp));  cpu->esp += 4u;
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
    g_sfera_world_spatial.gatherObjects({*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, *SferaAbi::pointer<const float>(cpu->esp + 12u));  cpu->esp += 16u;
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
    SferaAbi::pointer<SphereWorld::DynamicVegetation>(cpu->ecx)->collectModels(SferaAbi::pointer<const std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u));  cpu->esp += 8u;
    label_0007C1CE:
    sub_pred[0] = (uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u;
    (g_sfera_graphics_runtime.d3d_runtime->vertices32.position) = 0x7530u;
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
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (*(uint8_t*)(cpu->eax + 0x50u) != 0u) goto label_0007C2C1;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = static_cast<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u); cpu->esp += 4u;
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
    SferaAbi::pointer<SphereWorld::DynamicVegetation>(cpu->ecx)->update();
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
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    SferaAbi::pointer<SphereWorld::DynamicVegetation>(cpu->ecx)->addInfluence(*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u));  cpu->esp += 16u;
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
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    cpu->eip = 0x47C666u; ::DebugBreak(); return;
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_motion.surfaceInteraction(cpu->ecx, SferaAbi::pointer<std::uint32_t>(cpu->edx)));
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
    cpu->ecx = (uintptr_t)"Water material";
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476C5Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x476C5Du));
    x87_p0 = 0.20000000298023224;
     value_34 = x87_p0;  value_6 = value_34;
label_00076C63:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_graphics_runtime.water_materials.size()) goto label_00076C7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"Water material";
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476C79u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x476C79u));
    x87_p0 = 0.20000000298023224;
label_00076C7F:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.water_materials.data());
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->Clear(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<const D3DRECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), "Clear")); cpu->esp += 24u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    if (cpu->esi == 2u) goto label_0007C6EB;
    cpu->eax = g_sfera_view_spatial_runtime.basis[0].y.u32;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x24u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = g_sfera_view_spatial_runtime.basis[0].z.u32;
    lift_push32(cpu, cpu->ecx);
    goto label_0007C70D;
label_0007C6EB:
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.y))) - (1.0));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x24u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->eax = g_sfera_view_spatial_runtime.scale.y.u32;
    lift_push32(cpu, cpu->eax);
label_0007C70D:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x25u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C71Fu)); sfera_sub_00450A00(cpu, LIFT_CODE_TOKEN_VA(0x47C71Fu));
    if (cpu->esi != 0u) goto label_0007C72D;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C728u)); sfera_sub_0044E1B0(cpu, LIFT_CODE_TOKEN_VA(0x47C728u));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7C72Du)); sfera_sub_0044E230(cpu, LIFT_CODE_TOKEN_RVA(0x7C72Du));
label_0007C72D:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
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
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::Vegetation::alternatePatterns());
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->Clear(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<const D3DRECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), "Clear")); cpu->esp += 24u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    g_sfera_terrain_renderer.drawLandscape();
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x22u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
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
    g_sfera_light_runtime.setDirectionalLight(SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const float>(cpu->esp + 20u)});  cpu->esp += 24u;
    g_sfera_terrain_renderer.drawWater();
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C914u)); sfera_sub_0041A0B0(cpu, LIFT_CODE_TOKEN_VA(0x47C914u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47C91Bu)); sfera_sub_0041A560(cpu, LIFT_CODE_TOKEN_VA(0x47C91Bu));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1Cu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = (uintptr_t)&g_sfera_server_wall;
    SferaAbi::pointer<SferaServerWall>(cpu->ecx)->generateEffects();
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->beginScene());
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007CB92;
    lift_push32(cpu, cpu->esi);
    g_sfera_world_render_runtime.scene_active = cpu->edi;
    cpu->eax = SferaAbi::address(&g_sfera_graphics_runtime.d3d_runtime->minimapTexture());
    cpu->ecx = cpu->eax;
    cpu->eax = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceTexture>(cpu->ecx)->native_texture);
    cpu->esi = cpu->eax;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->eax)->native_device);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x98u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7C9F1u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0xA0u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CA0Au));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x48u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CA19u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->ecx == 0u) goto label_0007CB31;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->eax)->native_device);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x94u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CA3Bu));
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
    g_sfera_world_objects.recalculateBasis(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CB2Fu));
    label_0007CB31:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x94u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CB4Au));
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->eax)->native_device);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x9Cu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CB62u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CB6Eu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CB7Au));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->EndScene(), "EndScene"));
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
    g_sfera_terrain_renderer.gatherReflectiveWater();
    x87_v0 = (double)99999.0f;
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_window_runtime.distance_scratch.f32);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (lift_left>lift_right) goto label_0007CD83; }
    x87_v1 = 0.0;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->esp + 0xCu) = x87_v1;
    cpu->edx = cpu->esp + 0xCu;
    x87_v2 = (double)-1.0f;
    g_sfera_main_render_runtime.secondary_render_pass = 1u;
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->eax)->native_device);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xDCu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CC2Du));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x98u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->beginScene());
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007CD58;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CC6Cu));
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->eax)->native_device);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xA0u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CC84u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->reflection_target.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceTexture>(cpu->ecx)->native_texture);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x48u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CC9Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->eax)->native_device);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x94u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CCB6u));
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
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CCF8u));
    cpu->edx = *(uint32_t*)(cpu->esp);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->eax)->native_device);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x94u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x7CD11u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x9Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CD2Au));
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CD35u));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x7CD41u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->EndScene(), "EndScene"));
    g_sfera_world_render_runtime.scene_active = 0u;
    label_0007CD58:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0x98u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
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
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
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
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->beginScene());
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007D033;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->supports_post_effects);
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007CE99;
    if (g_sfera_graphics_runtime.post_effects_enabled != cpu->ebx) goto label_0007CE99;
    g_sfera_graphics_runtime.d3d_runtime->post_effects->setEnabled((cpu->ebx & 0xffu) != 0u);
    g_sfera_graphics_runtime.d3d_runtime->post_effects->beginCapture();
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 7u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xEu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47CEDBu)); sfera_sub_0045E560(cpu, LIFT_CODE_TOKEN_VA(0x47CEDBu));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->supports_post_effects);
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0007CF1B;
    if (g_sfera_graphics_runtime.post_effects_enabled != cpu->ebx) goto label_0007CF1B;
    g_sfera_graphics_runtime.d3d_runtime->post_effects->compose();
    label_0007CF1B:
    WorldDebugDraw::draw();
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
    g_sfera_world_objects.recalculateBasis(cpu->ecx);
    label_0007D006:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->EndScene(), "EndScene"));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D016u)); sfera_sub_0044E020(cpu, LIFT_CODE_TOKEN_VA(0x47D016u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    g_sfera_world_render_runtime.scene_active = 0u;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->Present(SferaAbi::pointer<const RECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), SferaAbi::pointer<const RECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), SferaAbi::pointer<HWND__>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), SferaAbi::pointer<const RGNDATA>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u))), "Present")); cpu->esp += 16u;
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
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    (void)cpu;
    label_0007D070:
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
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
    g_sfera_profiler_runtime.begin(cpu->ecx);
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
    g_sfera_interface.update(static_cast<std::uint8_t>(cpu->ecx), static_cast<std::uint8_t>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
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
    g_sfera_motion.updateOrientation();
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
    g_sfera_profiler_runtime.begin(cpu->ecx);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D330u)); sfera_sub_004496F0(cpu, LIFT_CODE_TOKEN_VA(0x47D330u));
    cpu->ecx = cpu->esi;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->ecx = 2u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08 != cpu->ebx) goto label_0007D358;
    x87_v0 = (double)0.0052083334885537624f;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    g_sfera_motion.updateControlled(*SferaAbi::pointer<const float>(cpu->esp));  cpu->esp += 4u;
    label_0007D358:
    cpu->ecx = 2u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax != 4u) goto label_0007D396;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    x87_v0 = (double)0.02083333395421505f;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    g_sfera_motion.updateObjects(*SferaAbi::pointer<const float>(cpu->esp));  cpu->esp += 4u;
    cpu->ecx = 3u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    label_0007D396:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax != 6u) goto label_0007D3D7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D3AAu)); sfera_sub_004517D0(cpu, LIFT_CODE_TOKEN_VA(0x47D3AAu));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_16 != cpu->ebx) goto label_0007D3D7;
    cpu->ecx = 4u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D3CD;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D3CDu)); sfera_sub_00429C10(cpu, LIFT_CODE_TOKEN_RVA(0x7D3CDu));
    label_0007D3CD:
    cpu->ecx = 4u;
    g_sfera_profiler_runtime.end(cpu->ecx);
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
    TerrainAssets::evictUnused();
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D40Bu)); sfera_sub_00432880(cpu, LIFT_CODE_TOKEN_RVA(0x7D40Bu));
    label_0007D40B:
    cpu->ecx = 5u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    g_sfera_world_objects.updateExtendedSpatialIndices();
    cpu->ecx = 5u;
    g_sfera_profiler_runtime.end(cpu->ecx);
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
    g_sfera_vegetation.updateGrassView();
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->ebp) goto label_0007D100;
    label_0007D47C:
    cpu->eax = g_sfera_frame_runtime.frame_state;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0007D49D;
    cpu->eax += cpu->esi;
    g_sfera_frame_runtime.frame_state = cpu->eax;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    g_sfera_frame_runtime.frame_state_anchor.high = cpu->edx;
    g_sfera_frame_runtime.frame_state_anchor.low = cpu->eax;
    label_0007D49D:
    cpu->ecx = 6u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    cpu->ecx = 6u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->ecx = 7u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->Clear(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<const D3DRECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), "Clear")); cpu->esp += 24u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->beginScene());
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007D635;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D61Bu)); sfera_sub_0044DF90(cpu, LIFT_CODE_TOKEN_VA(0x47D61Bu));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->EndScene(), "EndScene"));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->Present(SferaAbi::pointer<const RECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), SferaAbi::pointer<const RECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), SferaAbi::pointer<HWND__>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), SferaAbi::pointer<const RGNDATA>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u))), "Present")); cpu->esp += 16u;
    label_0007D635:
    cpu->ecx = 7u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->ecx = 8u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D656;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D656u)); sfera_sub_00497ED0(cpu, LIFT_CODE_TOKEN_RVA(0x7D656u));
    label_0007D656:
    cpu->ecx = 8u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D665u)); sfera_sub_0044C160(cpu, LIFT_CODE_TOKEN_VA(0x47D665u));
    if ((uint32_t)(g_sfera_render_lookup_runtime.initialized) == cpu->esi) goto label_0007D752;
    cpu->ecx = 0u;
    g_sfera_profiler_runtime.end(cpu->ecx);
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
    cpu->eip = 0x47D763u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0047D770(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_p0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x47D773u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetThreadAffinityMask), LIFT_CODE_TOKEN_VA(0x47D77Au));

    const uint32_t launch_guard = (uintptr_t)"/15FCE220-0246-58ec-3EH2-968B3072ACF8";
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_strstr_address32();
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(cpu->edi, launch_guard);

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
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
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

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(cpu->edi, (uintptr_t)"/login");

    if (cpu->eax == 0u) goto label_0007D85D;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.gamexp_sid_present) = 1u;
    goto label_0007D8B4;
    label_0007D85D:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(cpu->edi, (uintptr_t)"/gamexp_sid");

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
    ::InitializeCriticalSection(&g_sfera_network_send_runtime.critical_section);

    ::InitializeCriticalSection(&g_sfera_window_runtime.timing_critical_section);

    ::InitializeCriticalSection(&g_sfera_recovered_static_runtime.scene_lock);
    cpu->ebp = native_function_address32(&::CreateFileA);
    cpu->ebx = native_function_address32(&::CreateDirectoryA);
    cpu->edi = 0u;
    label_0007D920:
    cpu->esi = (uintptr_t)(cpu->edi == 0u ? ".\\logs" : ".\\players");

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CreateFileA)))(cpu->esi, 1u, 0u, 0u, 3u, 0u, 0u);
    if (cpu->eax != 0xFFFFFFFFu) goto label_0007D941;

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CreateDirectoryA)))(cpu->esi, 0u);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.create(SferaAbi::pointer<const char>(cpu->ecx)));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->ebx = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x36u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x28u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x18u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xB12u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    std::optional<SphereRender::ConfigDocument> configuration_document;
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    SphereRender::ConfigDocument::setStorageMode(cpu->ecx == 0u ? SphereRender::ConfigDocument::StorageMode::Plain : cpu->ecx == 1u ? SphereRender::ConfigDocument::StorageMode::Encoded : SphereRender::ConfigDocument::StorageMode::Preserve);
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
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    *(uint32_t*)(cpu->ebx) = cpu->ebp;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0007E0D3;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->ebx) = 1u;
    configuration_document.emplace(SphereRender::ConfigDocument::open(SferaAbi::pointer<const char>(cpu->ecx))); cpu->eax = SferaAbi::address(&*configuration_document);
    cpu->edx = (uintptr_t)"words";
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
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
    cpu->eax = SferaAbi::address(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->objectAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
    cpu->ecx = cpu->esp + 0x10u;
    cpu->ebp = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"w";
    cpu->ecx = cpu->ebp;
    { const char* value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->text(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value != nullptr ? 1u : 0u; if (value != nullptr) *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = SferaAbi::address(value); }; cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
    cpu->ebx = cpu->eax;
    cpu->esi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0007DD2A;
    label_0007DCF1:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uintptr_t)"e";
    cpu->ecx = cpu->ebp;
    { const char* value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->textAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value != nullptr ? 1u : 0u; if (value != nullptr) *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = SferaAbi::address(value); }; cpu->esp += 8u;
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
    cpu->eax = SferaAbi::address(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->objectAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"w";
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    { const char* value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->text(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value != nullptr ? 1u : 0u; if (value != nullptr) *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = SferaAbi::address(value); }; cpu->esp += 4u;
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
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->integer(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
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
    { const char* value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->textAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value != nullptr ? 1u : 0u; if (value != nullptr) *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = SferaAbi::address(value); }; cpu->esp += 8u;
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
    configuration_document.reset();
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
        default: cpu->eip = 0x47E235u; throw std::out_of_range("resolved jump-table index out of range"); return;
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










__declspec(noinline) void sfera_sub_0047F6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(sfera_nature_manager())); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F6C0(LiftCpu* cpu, uint32_t stop_address) {
    auto* manager = reinterpret_cast<SferaNatureManager*>(static_cast<std::uintptr_t>(cpu->ecx)); if (manager != nullptr) manager->startRain(); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F6E0(LiftCpu* cpu, uint32_t stop_address) {
    auto* manager = reinterpret_cast<SferaNatureManager*>(static_cast<std::uintptr_t>(cpu->ecx)); if (manager != nullptr) manager->stopRain(); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F730(LiftCpu* cpu, uint32_t stop_address) {
    auto* manager = reinterpret_cast<SferaNatureManager*>(static_cast<std::uintptr_t>(cpu->ecx)); if (manager != nullptr) manager->startLighting(); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F750(LiftCpu* cpu, uint32_t stop_address) {
    auto* manager = reinterpret_cast<SferaNatureManager*>(static_cast<std::uintptr_t>(cpu->ecx)); if (manager != nullptr) manager->stopLighting(); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047F770(LiftCpu* cpu, uint32_t stop_address) {
    auto* manager = reinterpret_cast<SferaNatureManager*>(static_cast<std::uintptr_t>(cpu->ecx)); if (manager != nullptr) manager->setLightingLevel(std::bit_cast<float>(*(uint32_t*)(cpu->esp + 4u))); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FA20(LiftCpu* cpu, uint32_t stop_address) {
    auto* manager = reinterpret_cast<SferaNatureManager*>(static_cast<std::uintptr_t>(cpu->ecx)); if (manager != nullptr) manager->setRainIntensity(std::bit_cast<float>(*(uint32_t*)(cpu->esp + 4u))); cpu->esp += 8u; cpu->eip = stop_address; return;
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
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
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
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x47FFBCu));
    cpu->esi = (uintptr_t)&g_sfera_network_probe_runtime.samples[0];
    std::memmove((void*)((uintptr_t)&g_sfera_network_probe_runtime.snapshot[0]),(void*)(cpu->esi),480u); cpu->esi += 480u;
    cpu->ecx = g_sfera_network_probe_runtime.sample_count;
    lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
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
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
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
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
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
    lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4800B2u));
    cpu->eax = cpu->esp + 4u;
    g_sfera_network_probe_runtime.stop_requested = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_probe_runtime.context_a = cpu->ebx;
    g_sfera_network_probe_runtime.context_c = cpu->ebx;
    g_sfera_network_probe_runtime.context_b = cpu->ebx;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_network_probe_thread, nullptr, 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->eax)))));
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
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetExitCodeThread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u)); cpu->esp += 0x8u;
    if (cpu->eax == 0u) goto label_00080161;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0x103u) goto label_00080161;

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(7u);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x28u) goto label_00080130;
    label_00080161:
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    if (cpu->eax == 0u) goto label_000801A3;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetExitCodeThread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u)); cpu->esp += 0x8u;
    if (cpu->eax == 0u) goto label_000801A3;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0x103u) goto label_000801A3;
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x480190u));
    cpu->ecx = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x8019Du));
    label_000801A3:
    lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4801FDu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4801FDu));
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
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_directplay_heartbeat_thread, nullptr, 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->edx)))));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000802ED;
    cpu->ecx = (uintptr_t)"CClNetworkConnectionChecker::Start(): CreateThread error: ";
    g_sfera_log_runtime.files[0].write(SferaAbi::pointer<const char>(cpu->ecx));
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4802D6u));
    cpu->ecx = cpu->eax;
    g_sfera_log_runtime.files[0].write(static_cast<std::int32_t>(cpu->ecx));
    cpu->ecx = (uintptr_t)"\n";
    g_sfera_log_runtime.files[0].write(SferaAbi::pointer<const char>(cpu->ecx));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x480364u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x480364u));
    cpu->esp += 4u;
    label_00080367:
    g_sfera_network_connection_checker.instance = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
























} // namespace lifted
