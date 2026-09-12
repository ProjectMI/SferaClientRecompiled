#include "lifted_functions.h"
#include <cmath>
namespace lifted {










__declspec(noinline) void sfera_sub_00470B80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_shadow_runtime.manager;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0xA0u) < 4u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_00070D95;
    { const double lift_left=(double)*(float*)(cpu->edi + 0x148u); const double lift_right=0.9900000095367432; if (lift_left<lift_right) goto label_00070D95; }
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB8u);
    x87_v0 = (double)*(float*)(cpu->edi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xBCu);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xACu);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xB0u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC0u);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x24u)));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = 0.0;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x4Cu;
    *SferaAbi::pointer<SferaVec3F>(cpu->ecx) = SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}.normalized(static_cast<std::int32_t>(cpu->edx)); cpu->eax = cpu->ecx; cpu->edx = sfera_f32_bits(SferaAbi::pointer<SferaVec3F>(cpu->ecx)->z); cpu->esp += 12u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x60u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    x87_v2 = x87_v1;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    x87_v0 = x87_v0 * x87_v2; 
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x30u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v2 = 0.5;
    x87_v1 = (x87_v1) * (x87_v2);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v2 = (x87_v2) * (x87_v1);
    *(float*)(cpu->esp + 0x44u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x48u) = x87_v1; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->edi + 8u))) + (((double)*(float*)(cpu->esp + 0x40u))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->edi + 0xCu))) + (((double)*(float*)(cpu->esp + 0x44u))));
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->edi + 0x10u))) + (((double)*(float*)(cpu->esp + 0x48u))));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x5Cu)));
    x87_v0 = (x87_v0) * (0.800000011920929);
    *(float*)(cpu->esp + 0x60u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x60u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) - (x87_v1);
    *(float*)(cpu->esp + 0x44u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    x87_v4 = x87_v3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    x87_v4 = (x87_v4) - (x87_v1);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(float*)(cpu->esp + 0x48u) = x87_v4; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    x87_v4 = x87_v1;
    cpu->esp -= 0xCu;
    x87_v0 = x87_v0 + x87_v4; 
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x4Cu) = x87_v3; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    x87_v2 = (x87_v2) + (x87_v1);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    *(float*)(cpu->esp + 0x50u) = x87_v2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    x87_v2 = x87_v1;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    x87_v0 = x87_v0 + x87_v2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x60u) = x87_v1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x50u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_world_spatial.gatherShadowTriangles(*SferaAbi::pointer<const SphereWorld::Bounds>(cpu->ecx), {*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, *SferaAbi::pointer<const float>(cpu->esp + 12u), {*SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const float>(cpu->esp + 20u), *SferaAbi::pointer<const float>(cpu->esp + 24u)}, {*SferaAbi::pointer<const float>(cpu->esp + 28u), *SferaAbi::pointer<const float>(cpu->esp + 32u), *SferaAbi::pointer<const float>(cpu->esp + 36u)}));  cpu->esp += 40u;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470D8Eu)); sfera_sub_0048D580(cpu, LIFT_CODE_TOKEN_VA(0x470D8Eu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70D95u)); sfera_sub_0048DA20(cpu, LIFT_CODE_TOKEN_RVA(0x70D95u));
    label_00070D95:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

















__declspec(noinline) void sfera_sub_00477020(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    const SphereRender::Material* activeMaterial = nullptr;
    bool lift_cmp[1];
    cpu->esp -= 0x12Cu;
    sub_pred[0] = (uint32_t)(g_sfera_recovered_static_runtime.scene_state_09) == 0u;
    cpu->eax = g_sfera_shadow_runtime.manager;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->eax;
    if (sub_pred[0]) goto label_00077059;
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::ContactQuery::lineOfSight(cpu->ecx));
    g_sfera_recovered_static_runtime.scene_state_09 = cpu->eax;
    label_00077059:
    if ((int32_t)cpu->ebp >= 0) goto label_00077067;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77067u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x77067u));
    label_00077067:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007707B;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7707Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7707Bu));
    label_0007707B:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    g_sfera_world_render_runtime.active_model = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x138u));
    if ((cpu->eax & 0xFFu) != 1u) goto label_000770B7;
    if (*(uint8_t*)(cpu->esi + 0x141u) == 0u) goto label_00077F62;
    label_000770B7:
    if ((cpu->eax & 0xFFu) == 0u) goto label_00077103;
    if (*(uint32_t*)(cpu->esi + 0x184u) == 0u) goto label_00077103;
    cpu->esi = *(uint32_t*)(cpu->esi + 0x188u);
    if ((int32_t)cpu->esi >= 0) goto label_000770D8;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x770D8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x770D8u));
    label_000770D8:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity))) goto label_000770EC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x770ECu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x770ECu));
    label_000770EC:
    cpu->esi <<= 6u;
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edi = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    goto label_00077113;
    label_00077103:
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_character_frame_matrix.m[0][0]);
    cpu->edx = cpu->esi + 0x14u;
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); *destination = SferaMatrix4x4F::fromEuler(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->edx)); cpu->eax = SferaAbi::address(destination); }; cpu->esp += 4u;
    label_00077113:
    x87_v0 = 0.0;
    std::memmove((void*)((uintptr_t)&g_sfera_character_rotation_matrix.m[0][0]),(void*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][0]),64u);
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[2][3]) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[1][3]) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[0][3]) = x87_v0; 
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esi = cpu->esp + 0xD8u;
    cpu->edi += 0xE8u;
    cpu->ebx = 8u;
    label_00077150:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    cpu->edi += 0xCu;
    cpu->esi += 0xCu;
    if ((--cpu->ebx) != 0u) goto label_00077150;
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0xDCu;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    cpu->eax = static_cast<std::uint32_t>((static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) <= 0 ? 0 : SferaAbi::pointer<const SferaFrustumF>(cpu->ecx)->classifyPoints(std::span<const SferaVec3F>(SferaAbi::pointer<const SferaVec3F>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
    g_sfera_client_main_scalar_runtime.mode_01 = cpu->eax;
    if (cpu->eax == 0u) goto label_00077F62;
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_000771AC;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x771ACu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x771ACu));
    label_000771AC:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    x87_v0 = (double)*(float*)(cpu->eax + 8u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebx + 8u)));
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x4Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(float*)(cpu->esp + 0x50u) = ((((double)*(float*)(cpu->eax + 0xCu))) - (((double)*(float*)(cpu->ebx + 0xCu))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    cpu->eax = cpu->esp;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebx + 0x10u)));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = 0u;
    *(float*)(cpu->esp + 0x54u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x88u;
    *SferaAbi::pointer<SferaVec3F>(cpu->ecx) = SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}.normalized(static_cast<std::int32_t>(cpu->edx)); cpu->eax = cpu->ecx; cpu->edx = sfera_f32_bits(SferaAbi::pointer<SferaVec3F>(cpu->ecx)->z); cpu->esp += 12u;
    cpu->edi = cpu->esp + 0xE8u;
    cpu->edi &= 0xFFFFFFF0u;
    cpu->esi = (uintptr_t)&g_sfera_character_rotation_matrix.m[0][0];
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_0007722B;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7722Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7722Bu));
    label_0007722B:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->edi = cpu->esp + 0xE8u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0xD8u) = cpu->edi;
    cpu->esi = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u;
    cpu->edx = cpu->esp + 0x40u;
    cpu->ecx = cpu->esp + 0xD8u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->ecx))->inverseTransformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    cpu->ecx = cpu->ebp;
    WorldDebugDraw::drawBounds(cpu->ecx);
    sub_pred[1] = *(uint8_t*)(cpu->ebx + 0x138u) == 0u;
    x87_v0 = 1.0;
    if (sub_pred[1]) goto label_000774CD;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebx + 0x184u) == cpu->esi) goto label_000774CF;
    x87_v0 = x87_v0; 
    label_0007729C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4772A9u)); sfera_sub_0044E720(cpu, LIFT_CODE_TOKEN_VA(0x4772A9u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][0]);
    cpu->edx = cpu->esp + 0x98u;
    *(float*)(cpu->esp + 0x98u) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][0]);
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0xA4u) = x87_v0; 
    *(float*)(cpu->esp + 0xA8u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][0]);
    *(float*)(cpu->esp + 0xACu) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][0]);
    *(float*)(cpu->esp + 0xB0u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][1]);
    *(float*)(cpu->esp + 0xB4u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][1]);
    *(float*)(cpu->esp + 0xB8u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][1]);
    *(float*)(cpu->esp + 0xBCu) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][1]);
    *(float*)(cpu->esp + 0xC0u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][2]);
    *(float*)(cpu->esp + 0xC4u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][2]);
    *(float*)(cpu->esp + 0xC8u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][2]);
    *(float*)(cpu->esp + 0xCCu) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][2]);
    *(float*)(cpu->esp + 0xD0u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][3]);
    *(float*)(cpu->esp + 0xD4u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][3]);
    *(float*)(cpu->esp + 0xD8u) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][3]);
    *(float*)(cpu->esp + 0xDCu) = (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][3]);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    x87_v0 = (double)*(float*)(cpu->ebx + 8u);
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (x87_v0) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x));
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->ebx + 0xCu))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->ebx + 0x10u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x6Cu) = x87_v0;
    *(float*)(cpu->esp + 0x7Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x34u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->edi + 0x1ACu);
    x87_v3 = (double)*(float*)(cpu->edi + 0x194u);
    *(double*)(cpu->esp + 0x20u) = x87_v3;
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (*(double*)(cpu->esp + 0x24u)) / (x87_v0);
    cpu->edx = cpu->esp + 0x70u;
    cpu->ecx = cpu->esp + 0x80u;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 0x1A8u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47742Du)); sfera_sub_0044EB00(cpu, LIFT_CODE_TOKEN_VA(0x47742Du));
    if (*(uint32_t*)(cpu->ebx + 0x134u) != cpu->esi) goto label_0007747A;
    x87_v0 = (double)*(float*)(cpu->ebx + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1E0u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ebx + 0x10u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477460u)); sfera_sub_0044ECA0(cpu, LIFT_CODE_TOKEN_VA(0x477460u));
    cpu->ecx = cpu->edi + 0x1D4u;
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SphereRender::Material::randomColor(*SferaAbi::pointer<const std::array<float, 3>>(cpu->ecx)));
    cpu->esi <<= 24u;
    cpu->eax |= cpu->esi;
    *(uint32_t*)(cpu->ebx + 0x134u) = cpu->eax;
    cpu->esi = 0u;
    label_0007747A:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x30u) <= (int32_t)cpu->esi) goto label_00077DFA;
    x87_v0 = (double)9.99999993922529e-09f;
    label_00077493:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax = cpu->ecx + (cpu->ecx * 8u);
    cpu->ebp = cpu->edx + (cpu->eax * 2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    cpu->edx = cpu->eax & 0xFFu;
    cpu->edx &= 0x7Fu;
    cpu->edx = (cpu->edx * 8u) + ((uintptr_t)&g_sfera_render_lookup_runtime.entries[0].resource);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->edx;
    if (*(uint32_t*)(cpu->edx) == cpu->esi) goto label_00077DEA;
    if ((int8_t)(cpu->eax & 0xFFu) >= 0) goto label_00077744;
    x87_v1 = (double)*(float*)(cpu->esp + 0x68u);
    goto label_00077748;
    label_000774CD:
    cpu->esi = 0u;
    label_000774CF:
    cpu->eax = g_sfera_view_spatial_runtime.basis[3].z.u32;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->ebx + 0x34u);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    x87_v2 = (double)-1.0f;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_cmp[0]=x87_v2!=x87_v1;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->edx;
    if (lift_cmp[0]) goto label_0007750D;
    *(float*)(cpu->ebx + 0x34u) = x87_v0; 
    goto label_00077546;
    label_0007750D:
    *(float*)(cpu->esp + 0x10u) = ((((double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.lighting_state)))))) * (0.0007999999797903001));
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0007753A; }
    x87_v0 = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ebx + 0x34u);
    x87_v2 = 1.0;
    x87_v1 = x87_v2 - x87_v1; 
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ebx + 0x34u)));
    goto label_0007753C;
    label_0007753A:
    x87_v1 = x87_v1; 
    label_0007753C:
    *(float*)(cpu->ebx + 0x34u) = x87_v0; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->ebx + 0x34u);
    label_00077546:
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x);
    cpu->esp -= 0xCu;
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->eax = cpu->esp;
    x87_v2 = x87_v1;
    cpu->esp -= 0xCu;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x) = x87_v1; 
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y) = x87_v1; 
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) * (((double)g_sfera_view_spatial_runtime.basis[3].z.f32));
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z) = x87_v0; 
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    x87_v0 = -x87_v0;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    x87_v0 = -x87_v0;
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    x87_v0 = -x87_v0;
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    g_sfera_light_runtime.setDirectionalLight(SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const float>(cpu->esp + 20u)});  cpu->esp += 24u;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4775DEu)); sfera_sub_00468750(cpu, LIFT_CODE_TOKEN_VA(0x4775DEu));
    cpu->edx = 0u;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_03 <= (int32_t)cpu->esi) goto label_0007729C;
    cpu->ebx = cpu->esp + 0xE8u;
    cpu->ebx &= 0xFFFFFFF0u;
    cpu->eax = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0].position.y;
    label_00077600:
    cpu->edi = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xD8u) = cpu->edi;
    cpu->esi = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u;
    x87_v0 = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xD8u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->eax))) - (((double)*(float*)(cpu->ecx + 0x1Cu))));
    *(float*)(cpu->esp + 0x3Cu) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->ecx + 0x2Cu))));
    x87_v0 = (double)*(float*)(cpu->ecx + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->ecx)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ecx + 0x20u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x3Cu); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->eax + 0xFFFFFFFCu) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ecx + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->ecx + 4u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->ecx + 0x24u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->eax) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ecx + 0x18u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->ecx + 8u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ecx + 0x28u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->eax + 4u) = x87_v0;
    *(float*)(cpu->esp + 0x88u) = (double)*(float*)(cpu->eax + 0x18u);
    *(float*)(cpu->esp + 0x8Cu) = (double)*(float*)(cpu->eax + 0x18u);
    *(float*)(cpu->esp + 0x90u) = (double)*(float*)(cpu->eax + 0x18u);
    x87_v1 = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x88u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x58u) = x87_v2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    x87_v2 = (double)*(float*)(cpu->eax);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    x87_v3 = (double)*(float*)(cpu->esp + 0x8Cu); x87_v4 = x87_v3;
    x87_v2 = x87_v2 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x5Cu) = x87_v3; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    x87_v3 = (double)*(float*)(cpu->esp + 0x90u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    x87_v4 = x87_v3;
    x87_v0 = x87_v0 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x60u) = x87_v3; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    x87_v3 = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->ecx;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax)));
    ++cpu->edx;
    cpu->eax += 0x3Cu;
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF0u) = cpu->ecx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 0xFFFFFFC8u)));
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF4u) = cpu->ecx;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00077600;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = 0u;
    goto label_0007729C;
    label_00077744:
    x87_v1 = (double)*(float*)(cpu->esp + 0x78u);
    label_00077748:
    *(float*)(cpu->esp + 0x50u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x50u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_00077774; }
    x87_v2 = x87_v1;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    x87_v3 = 1.0;
    x87_v2 = x87_v3 - x87_v2; 
    { const double lift_left=x87_v2; const double lift_right=9.99999993922529e-09;  if (lift_left>lift_right) goto label_00077778; }
    label_00077774:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_00077778:
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (lift_left<lift_right) goto label_00077DEA; }
    x87_v0 = x87_v0; 
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03 == cpu->esi) goto label_0007779D;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7779Du)); sfera_sub_0048D450(cpu, LIFT_CODE_TOKEN_RVA(0x7779Du));
    label_0007779D:
    cpu->eax = *(uint8_t*)(cpu->ebp);
    cpu->eax &= 0x7Fu;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xACu);
    cpu->eax += *(uint32_t*)(cpu->edi + 0x3Cu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) != 0x5Fu) goto label_000777C2;
    sub_pred[2] = *(uint8_t*)(cpu->eax + 1u) == 0x7Au;
    *(uint32_t*)(cpu->esp + 0x70u) = 1u;
    if (sub_pred[2]) goto label_000777C6;
    label_000777C2:
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->esi;
    label_000777C6:
    if ((cpu->ecx & 0xFFu) != 0x5Fu) goto label_000777D8;
    if (*(uint8_t*)(cpu->eax + 1u) != 0x73u) goto label_000777D8;
    cpu->edi = 1u;
    goto label_000777DA;
    label_000777D8:
    cpu->edi = 0u;
    label_000777DA:
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    if ((cpu->ecx & 0xFFu) != 0x5Fu) goto label_000777F0;
    if (*(uint8_t*)(cpu->eax + 1u) != 0x75u) goto label_000777F0;
    cpu->edx = 1u;
    goto label_000777F2;
    label_000777F0:
    cpu->edx = 0u;
    label_000777F2:
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0x5Fu) goto label_00077808;
    if (*(uint8_t*)(cpu->eax + 1u) != 0x63u) goto label_00077808;
    cpu->eax = 1u;
    goto label_0007780A;
    label_00077808:
    cpu->eax = 0u;
    label_0007780A:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->edi != cpu->esi) goto label_0007781E;
    if (cpu->edx != cpu->esi) goto label_0007781E;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_00077826;
    label_0007781E:
    *(uint32_t*)(cpu->esp + 0x3Cu) = 1u;
    label_00077826:
    activeMaterial = g_sfera_materials.at(*SferaAbi::pointer<const std::uint16_t>(cpu->ebp + 2u));
    if (activeMaterial == nullptr) throw std::out_of_range("Model material index");
    x87_v0 = activeMaterial->color[0];
    x87_v0 = (x87_v0) + (((double)g_sfera_view_spatial_runtime.basis[2].x.f32));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = activeMaterial->color[1];
    x87_v0 = (x87_v0) + (((double)g_sfera_view_spatial_runtime.basis[2].y.f32));
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = activeMaterial->color[2];
    x87_v0 = (x87_v0) + (((double)g_sfera_view_spatial_runtime.basis[2].z.f32));
    cpu->ebx = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    if ((int32_t)cpu->esi <= (int32_t)0xFFu) goto label_00077871;
    cpu->esi = 0xFFu;
    label_00077871:
    if ((int32_t)cpu->ebx <= (int32_t)0xFFu) goto label_0007787E;
    cpu->ebx = 0xFFu;
    label_0007787E:
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_0007788A;
    cpu->eax = 0xFFu;
    label_0007788A:
    cpu->esi|=0xFFFFFF00u;
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->esi <<= 8u;
    cpu->esi|=cpu->ecx;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->edx = cpu->eax & 0xFFu;
    cpu->esi <<= 8u;
    cpu->esi |= cpu->edx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x8Bu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    if (activeMaterial->hasColorVariation) goto label_000778D5;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u); cpu->esp += 4u;
    if ((cpu->eax & 0xFFu)!=0u) goto label_000778D5;
    cpu->ecx&=0xFFFFFF00u;
    goto label_000778D7;
    label_000778D5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    label_000778D7:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x134u);
    cpu->esi = cpu->eax;
    cpu->esi >>= 24u;
    if ((cpu->ecx & 0xFFu)==0u) goto label_00077917;
    cpu->ecx = cpu->eax;
    cpu->edx = cpu->eax;
    cpu->ecx >>= 16u;
    cpu->edx >>= 8u;
    cpu->ecx &= 0xFFu;
    cpu->edx&=0xFFu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->esi);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi);
    cpu->eax *= cpu->esi;
    cpu->ecx >>= 8u;
    cpu->edx >>= 8u;
    cpu->eax >>= 8u;
    goto label_0007791D;
    label_00077917:
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    cpu->eax = cpu->esi;
    label_0007791D:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477923u)); sfera_sub_0044EE70(cpu, LIFT_CODE_TOKEN_VA(0x477923u));
    cpu->edi = 0u;
    cpu->ebx = 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_03 <= (int32_t)cpu->edi) goto label_00077A85;
    label_00077940:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if (((*(uint32_t*)(cpu->eax + 4u)) & (cpu->ecx)) == 0u) goto label_000779E3;
    if (*(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) != 0u) goto label_00077A73;
    cpu->esi = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) = cpu->ebx;
    if ((int32_t)cpu->esi >= 0) goto label_0007797B;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7797Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7797Bu));
    label_0007797B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_0007798F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7798Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7798Fu));
    label_0007798F:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->edx + (cpu->esi * 4u)) == cpu->ebx) goto label_00077A73;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    cpu->eax += cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = cpu->eax;
    if ((int32_t)cpu->eax > (int32_t)8u) goto label_00077F7B;
    if ((int32_t)cpu->esi >= 0) goto label_000779C1;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x779C1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x779C1u));
    label_000779C1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_000779D5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x779D5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x779D5u));
    label_000779D5:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    goto label_00077A67;
    label_000779E3:
    if (*(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) != cpu->ebx) goto label_00077A73;
    cpu->esi = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) = 0u;
    if ((int32_t)cpu->esi >= 0) goto label_00077A10;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77A10u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x77A10u));
    label_00077A10:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00077A24;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77A24u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x77A24u));
    label_00077A24:
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) == 0u) goto label_00077A73;
    g_sfera_main_command_state_runtime.light_update_counter = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - (uint64_t)(cpu->ebx) - (uint64_t)(0u);
    if ((int32_t)cpu->esi >= 0) goto label_00077A44;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77A44u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x77A44u));
    label_00077A44:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00077A58;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77A58u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x77A58u));
    label_00077A58:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = 0u;
    lift_push32(cpu, 0u);
    label_00077A67:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->LightEnable(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) != 0u), "LightEnable")); cpu->esp += 8u;
    label_00077A73:
    *(uint32_t*)(cpu->esp + 0x18u) = *(uint32_t*)(cpu->esp + 0x18u) << 1u;
    cpu->edi += cpu->ebx;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00077940;
    label_00077A85:
    activeMaterial = g_sfera_materials.at(*SferaAbi::pointer<const std::uint16_t>(cpu->ebp + 2u));
    if (activeMaterial == nullptr) throw std::out_of_range("Model material index");
    cpu->esi = static_cast<std::uint32_t>(activeMaterial->textures.at(0));
    if (*(uint32_t*)(cpu->esp + 0x6Cu) == cpu->esi) goto label_00077ABF;
    cpu->ecx = cpu->esi;
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(cpu->ecx));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(cpu->ecx));
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->esi;
    label_00077ABF:
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0xAu);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices32.lock(static_cast<std::int32_t>(cpu->ecx)));
    if (cpu->eax == 0u) goto label_00077F62;
    cpu->edx = *(uint16_t*)(cpu->ebp + 8u);
    cpu->esi = g_sfera_world_render_runtime.active_model;
    cpu->esi = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = cpu->edx + (cpu->edx * 8u);
    cpu->ecx = cpu->esi + (cpu->ecx * 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x1D0u);
    if (cpu->esi != 0u) goto label_00077BC0;
    cpu->edx = 0u;
    if ((cpu->esi & 0xFFFFu) >= *(uint16_t*)(cpu->ebp + 0xAu)) goto label_00077C42;
    x87_v0 = 0.009999999776482582;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x70u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x48u);
    cpu->eax += 8u;
    x87_v2 = (double)*(float*)(cpu->esp + 0x44u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x40u);
    label_00077B1A:
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFFCu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    if (cpu->esi == 0u) goto label_00077B82;
    x87_v4 = x87_v3;
    x87_v4 = (x87_v4) - (((double)*(float*)(cpu->eax + 0xFFFFFFF8u)));
    *(float*)(cpu->esp + 0x28u) = x87_v4; 
    x87_v4 = x87_v2;
    x87_v4 = (x87_v4) - (((double)*(float*)(cpu->eax + 0xFFFFFFFCu)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v4; 
    x87_v4 = x87_v1;
    x87_v4 = (x87_v4) - (((double)*(float*)(cpu->eax)));
    *(float*)(cpu->esp + 0x30u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v4 = (x87_v4) * (x87_v0);
    *(float*)(cpu->esp + 0x58u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v4 = (x87_v4) * (x87_v0);
    *(float*)(cpu->esp + 0x5Cu) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v4 = (x87_v4) * (x87_v0);
    *(float*)(cpu->esp + 0x60u) = x87_v4; 
    *(float*)(cpu->eax + 0xFFFFFFF8u) = ((((double)*(float*)(cpu->esp + 0x58u))) + (((double)*(float*)(cpu->eax + 0xFFFFFFF8u))));
    *(float*)(cpu->eax + 0xFFFFFFFCu) = ((((double)*(float*)(cpu->eax + 0xFFFFFFFCu))) + (((double)*(float*)(cpu->esp + 0x5Cu))));
    *(float*)(cpu->eax) = ((((double)*(float*)(cpu->eax))) + (((double)*(float*)(cpu->esp + 0x60u))));
    label_00077B82:
    x87_v4 = (double)*(float*)(cpu->ecx + 0x18u);
    ++cpu->edx;
    *(float*)(cpu->eax + 0x10u) = x87_v4; 
    cpu->eax += 0x20u;
    x87_v4 = (double)*(float*)(cpu->ecx + 0x1Cu);
    cpu->ecx += 0x24u;
    *(float*)(cpu->eax + 0xFFFFFFF4u) = x87_v4; 
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xFFFFFFE8u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFE4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0xFFFFFFE8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFECu) = cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->ebp + 0xAu);
    if ((int32_t)cpu->edx < (int32_t)cpu->edi) goto label_00077B1A;
    x87_v0 = x87_v3; 
    x87_v1 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    goto label_00077C42;
    label_00077BC0:
    cpu->edx = cpu->edx + (cpu->edx * 2u);
    cpu->edx = cpu->esi + (cpu->edx * 8u);
    cpu->edi = 0u;
    cpu->esi = 0u;
    if ((cpu->edi & 0xFFFFu) >= *(uint16_t*)(cpu->ebp + 0xAu)) goto label_00077C42;
    cpu->eax += 0xCu;
    cpu->edi = cpu->edx + 0xCu;
    cpu->ecx += 0x1Cu;
    label_00077BE0:
    cpu->ebp = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF4u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF8u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFFCu) = cpu->ebp;
    *(float*)(cpu->eax + 0xCu) = (double)*(float*)(cpu->ecx + 0xFFFFFFFCu);
    *(float*)(cpu->eax + 0x10u) = (double)*(float*)(cpu->ecx);
    if (*(uint32_t*)(cpu->ebx + 0x1C4u) != 0u) goto label_00077C14;
    cpu->ebp = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->edi + 8u);
    goto label_00077C22;
    label_00077C14:
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0xFFFFFFF8u);
    label_00077C22:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->ebp = *(uint16_t*)(cpu->ebp + 0xAu);
    ++cpu->esi;
    cpu->eax += 0x20u;
    cpu->ecx += 0x24u;
    cpu->edx += 0x18u;
    cpu->edi += 0x18u;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebp) goto label_00077BE0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x64u);
    label_00077C42:
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices32.buffer.get());
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->eax)->native_buffer);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "VertexBuffer::Unlock")); cpu->esp += 4u;
    cpu->esi = *(uint16_t*)(cpu->ebp + 6u);
    cpu->edi = cpu->esi + (cpu->esi * 2u);
    if ((int32_t)cpu->edi > (int32_t)0xBB8u) goto label_00077F9D;
    cpu->eax = *(uint16_t*)(cpu->ebp + 4u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    cpu->edx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_dynamic_index_scratch[0];
    if ((int32_t)cpu->esi <= 0) goto label_00077CA6;
    label_00077C81:
    cpu->esi = *(uint16_t*)(cpu->ecx);
    *(uint16_t*)(cpu->eax) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint16_t*)(cpu->ecx + 2u);
    *(uint16_t*)(cpu->eax + 2u) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint16_t*)(cpu->ecx + 4u);
    *(uint16_t*)(cpu->eax + 4u) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint16_t*)(cpu->ebp + 6u);
    ++cpu->edx;
    cpu->eax += 6u;
    cpu->ecx += 0xCu;
    if ((int32_t)cpu->edx < (int32_t)cpu->esi) goto label_00077C81;
    label_00077CA6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0xAu);
    cpu->edx = 0u;
    g_sfera_texture_cache_runtime.upload_serial = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->eax) == 2u);
    cpu->esi = cpu->edx;
    if ((uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u) goto label_00077CC9;
    cpu->esi = 0u;
    label_00077CC9:
    cpu->esi |= 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x3Cu) == 0u) goto label_00077CD6;
    cpu->esi |= 4u;
    label_00077CD6:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ebx == 0u) goto label_00077D14;
    x87_v0 = (double)*(float*)(cpu->esp + 0x50u);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 - x87_v0; 
    cpu->eax = 0xE7Fu;
    x87_v0 = (x87_v0) * (127.0);
    *(uint64_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx -= 0xFFFFFF80u;
    lift_push32(cpu, cpu->ecx);
    goto label_00077D2E;
    label_00077D14:
    if (*(uint32_t*)(cpu->esp + 0x54u) != 0u) goto label_00077D29;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) != 0u) goto label_00077D29;
    if (*(uint32_t*)(cpu->esp + 0x14u) == 0u) goto label_00077D3B;
    label_00077D29:
    lift_push32(cpu, 0x80u);
    label_00077D2E:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x18u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    label_00077D3B:
    cpu->ecx = cpu->edi;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_primary.lock(static_cast<std::int32_t>(cpu->ecx)));
    cpu->edx = cpu->edi + cpu->edi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_dynamic_index_scratch[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x477D4Cu));
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_primary.buffer.get());
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->eax)->native_buffer);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "IndexBuffer::Unlock")); cpu->esp += 4u;
    cpu->edx = g_sfera_graphics_runtime.d3d_runtime->indices_primary.position;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_primary.buffer.get());
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->eax)->native_buffer);
    cpu->eax = g_sfera_graphics_runtime.d3d_runtime->vertices32.position;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_texture_cache_runtime.upload_serial;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices32.buffer.get());
    lift_push32(cpu, cpu->edx);
    cpu->edx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->ecx)->native_buffer);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->drawBuffer(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 32u)); cpu->esp += 36u;
    g_sfera_graphics_runtime.d3d_runtime->indices_primary.position = (uint64_t)((g_sfera_graphics_runtime.d3d_runtime->indices_primary.position)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    if (cpu->ebx != 0u) goto label_00077DBC;
    if (*(uint32_t*)(cpu->esp + 0x54u) != cpu->ebx) goto label_00077DBC;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) != cpu->ebx) goto label_00077DBC;
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->ebx) goto label_00077DCB;
    label_00077DBC:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x18u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    label_00077DCB:
    cpu->eax = g_sfera_texture_cache_runtime.upload_serial;
    x87_v0 = (double)9.99999993922529e-09f;
    g_sfera_graphics_runtime.d3d_runtime->vertices32.position = (uint64_t)((g_sfera_graphics_runtime.d3d_runtime->vertices32.position)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = 0u;
    label_00077DEA:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->edi + 0x30u)) goto label_00077493;
    x87_v0 = x87_v0; 
    label_00077DFA:
    lift_push32(cpu, 0x44u);
    cpu->ecx = cpu->esp + 0xDCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x477E05u));
    x87_v0 = 1.0;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->esp + 0xE4u) = x87_v0;
    *(float*)(cpu->esp + 0xE8u) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0xE0u) = x87_v0;
    cpu->edx = cpu->esp + 0xD8u;
    *(float*)(cpu->esp + 0xE4u) = x87_v0;
    lift_push32(cpu, cpu->edx);
    x87_v1 = 0.0;
    *(float*)(cpu->esp + 0xFCu) = x87_v1;
    *(float*)(cpu->esp + 0x100u) = x87_v1;
    *(float*)(cpu->esp + 0x104u) = x87_v1;
    *(float*)(cpu->esp + 0x11Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x108u) = x87_v0;
    *(float*)(cpu->esp + 0xECu) = x87_v0;
    *(float*)(cpu->esp + 0xF0u) = x87_v0;
    *(float*)(cpu->esp + 0xF4u) = x87_v0;
    *(float*)(cpu->esp + 0xF8u) = x87_v0; 
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetMaterial(SferaAbi::pointer<const D3DMATERIAL9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))), "SetMaterial")); cpu->esp += 4u;
    if (*(uint8_t*)(cpu->ebx + 0x138u) == 0u) goto label_00077E94;
    if (*(uint32_t*)(cpu->ebx + 0x184u) != cpu->esi) goto label_00077F62;
    label_00077E94:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    cpu->edi = 0u;
    g_sfera_view_spatial_runtime.basis[3].x.u32 = cpu->eax;
    g_sfera_view_spatial_runtime.basis[3].y.u32 = cpu->ecx;
    g_sfera_view_spatial_runtime.basis[3].z.u32 = cpu->edx;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_03 <= (int32_t)cpu->esi) goto label_00077F62;
    label_00077ED0:
    if (*(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) != 1u) goto label_00077F55;
    cpu->esi = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    if ((int32_t)cpu->esi >= 0) goto label_00077EF3;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77EF3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x77EF3u));
    label_00077EF3:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00077F07;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77F07u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x77F07u));
    label_00077F07:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00077F55;
    g_sfera_main_command_state_runtime.light_update_counter = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u;
    if ((int32_t)cpu->esi >= 0) goto label_00077F26;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77F26u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x77F26u));
    label_00077F26:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00077F3A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77F3Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x77F3Au));
    label_00077F3A:
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = 0u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->LightEnable(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) != 0u), "LightEnable")); cpu->esp += 8u;
    label_00077F55:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00077ED0;
    label_00077F62:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x12Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00077F7B:
    lift_push32(cpu, 0x26AEu); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x477F8Au));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77F9Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x77F9Du));
    label_00077F9D:
    cpu->ecx = (uintptr_t)"MNO_INDICES_IN_PRIMITIVE exceed";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477FA7u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x477FA7u));
    cpu->eip = 0x477FA7u; ::DebugBreak(); return;
}

} // namespace lifted
