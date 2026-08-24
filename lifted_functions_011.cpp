#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static int sfera_world_type_has_spatial_extent(uint32_t type) { switch (type) { case 7u: case 8u: case 9u: case 10u: case 11u: case 14u: case 21u: case 23u: case 24u: case 25u: case 28u: case 32u: case 35u: case 39u: return 1; default: return 0; } }
__declspec(noinline) void sfera_sub_0046D8B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    cpu->eax = cpu->ecx + 0x9C40u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx + cpu->eax;
    cpu->eax = cpu->ebx + 0x9C40u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->esi -= 0x2690u;
    cpu->eax -= 0x2690u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->edi = 4u;
    if (cpu->esi > 0xFFu) goto label_0006DC26;
    { uint64_t l=cpu->eax, r=0xFFu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0006DC26;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ebx;
    cpu->esi <<= 8u;
    cpu->ecx &= 0xFFFFFFFCu;
    cpu->ebp &= 0xFFFFFFFCu;
    cpu->esi += cpu->eax;
    cpu->esi = (cpu->esi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.quadtree_cells[0]);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    goto label_0006D929;
    label_0006D925:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0006D929:
    cpu->esi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if (cpu->esi == 0u) goto label_0006DC25;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esi = cpu->edi + cpu->ebp;
    { uint64_t l=cpu->ebx, r=cpu->esi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebx = 0u;
    cpu->edx = cpu->ecx + cpu->edi;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->ebx + (cpu->eax * 2u);
    cpu->esi = cpu->esi + (cpu->eax * 4u);
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0006D96A;
    cpu->ecx = cpu->edx;
    label_0006D96A:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_0006D972;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    label_0006D972:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)2u) goto label_0006D925;
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (cpu->ebp == 0u) goto label_0006DC25;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebp) <= (int32_t)cpu->ebx) goto label_0006DAAC;
    label_0006D995:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u));
    if ((int32_t)cpu->esi >= 0) goto label_0006D9A9;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D9A9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6D9A9u));
    label_0006D9A9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006D9BD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D9BDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6D9BDu));
    label_0006D9BD:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint32_t*)(cpu->eax + 0xF4u) == 1u) goto label_0006DAA2;
    if ((int32_t)cpu->esi >= 0) goto label_0006D9E1;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D9E1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6D9E1u));
    label_0006D9E1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006D9F5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D9F5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6D9F5u));
    label_0006D9F5:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + 0xF4u) = 1u;
    cpu->eax = g_sfera_landscape_patch_lookup_runtime.active_count;
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0006DA1D;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DA1Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DA1Du));
    label_0006DA1D:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_character_index_map.capacity) goto label_0006DA31;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DA31u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DA31u));
    label_0006DA31:
    cpu->eax = g_sfera_character_index_map.data;
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = cpu->esi;
    if ((int32_t)cpu->esi >= 0) goto label_0006DA47;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DA47u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DA47u));
    label_0006DA47:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006DA5B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DA5Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DA5Bu));
    label_0006DA5B:
    cpu->edi = g_sfera_landscape_patch_lookup_runtime.active_count;
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)cpu->edi >= 0) goto label_0006DA78;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DA78u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DA78u));
    label_0006DA78:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_visibility_indices.capacity) goto label_0006DA8C;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DA8Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DA8Cu));
    label_0006DA8C:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = g_sfera_scene_array_runtime.object_visibility_indices.data;
    cpu->edx += 0xF4u;
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = cpu->edx;
    ++g_sfera_landscape_patch_lookup_runtime.active_count;
    label_0006DAA2:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->ebp)) goto label_0006D995;
    label_0006DAAC:
    if (*(uint32_t*)(cpu->ebp + 0xCu) != 1u) goto label_0006DC25;
    if (*(uint32_t*)(cpu->esp + 0x28u) != 1u) goto label_0006DC25;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->edx + (cpu->edx * 4u);
    cpu->edi = cpu->eax + (cpu->ecx * 2u);
    if (*(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x8Cu) != 0u) goto label_0006DAE2;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DAE2u)); sfera_sub_0046CBA0(cpu, LIFT_CODE_TOKEN_RVA(0x6DAE2u));
    label_0006DAE2:
    *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x53Cu) = 0x3E8u;
    cpu->esi = g_sfera_scene_build_runtime.object_count;
    if ((int32_t)cpu->esi >= 0) goto label_0006DB01;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DB01u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DB01u));
    label_0006DB01:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_sort_indices.capacity) goto label_0006DB15;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DB15u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DB15u));
    label_0006DB15:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = cpu->eax + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0x8Cu);
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_indices.data;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->eax;
    cpu->eax = g_sfera_scene_build_runtime.object_count;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0006DB4E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DB49u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x46DB49u));
    cpu->eax = g_sfera_scene_build_runtime.object_count;
    label_0006DB4E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_sort_indices.capacity) goto label_0006DB67;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DB62u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x46DB62u));
    cpu->eax = g_sfera_scene_build_runtime.object_count;
    label_0006DB67:
    cpu->edx = g_sfera_scene_array_runtime.object_sort_indices.data;
    cpu->edi = cpu->edx + (cpu->esi * 4u);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0006DB80;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DB80u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DB80u));
    label_0006DB80:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_sort_keys.capacity) goto label_0006DB94;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DB94u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DB94u));
    label_0006DB94:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->edx += cpu->edx;
    cpu->ecx = cpu->eax + (cpu->edx * 8u) + 0xCu;
    cpu->edx = g_sfera_scene_array_runtime.object_sort_keys.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->ecx;
    cpu->eax = g_sfera_scene_build_runtime.object_count;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0006DBCC;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DBCCu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DBCCu));
    label_0006DBCC:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_draw_indices.capacity) goto label_0006DBE0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DBE0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DBE0u));
    label_0006DBE0:
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x28u));
    cpu->eax = g_sfera_scene_array_runtime.object_draw_indices.data;
    *(float*)(cpu->eax + (cpu->esi * 4u)) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = g_sfera_scene_build_runtime.object_count;
    if ((int32_t)cpu->esi >= 0) goto label_0006DBFF;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DBFFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DBFFu));
    label_0006DBFF:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.candidate_handles.capacity) goto label_0006DC13;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DC13u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DC13u));
    label_0006DC13:
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x2Cu));
    cpu->ecx = g_sfera_collision_runtime.candidate_handles.data;
    *(float*)(cpu->ecx + (cpu->esi * 4u)) = cpu->fpu[0u]; lift_x87_pop(cpu);
    ++g_sfera_scene_build_runtime.object_count;
    label_0006DC25:
    cpu->ebp = lift_pop32(cpu);
    label_0006DC26:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046DC30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->esi >= 0) goto label_0006DC44;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DC44u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DC44u));
    label_0006DC44:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006DC58;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DC58u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DC58u));
    label_0006DC58:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    g_sfera_landscape_patch_lookup_runtime.active_count = 0u;
    g_sfera_scene_build_runtime.object_count = 0u;
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x24u);
    if (cpu->ebx == 0xF4240u) goto label_0006DD7A;
    if ((int32_t)cpu->ebx > (int32_t)*(uint32_t*)(cpu->edi + 0x28u)) goto label_0006DD34;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    lift_x87_push(cpu, 0.11999999731779099);
    label_0006DC95:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x2Cu);
    if ((int32_t)cpu->esi > (int32_t)cpu->ecx) goto label_0006DD28;
    label_0006DCA0:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 1000.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006DCB7;
    cpu->eax = 1u;
    goto label_0006DCB9;
    label_0006DCB7:
    cpu->eax = 0u;
    label_0006DCB9:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->esp -= 0x10u;
    ++cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[1u]);
    cpu->edx = cpu->esi;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->ecx = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x2Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = ((double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x24u))))) / (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DD16u)); sfera_sub_0046D8B0(cpu, LIFT_CODE_TOKEN_VA(0x46DD16u));
    lift_x87_push(cpu, 0.11999999731779099);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    ++cpu->esi;
    if ((int32_t)cpu->esi <= (int32_t)cpu->ecx) goto label_0006DCA0;
    label_0006DD28:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx <= (int32_t)*(uint32_t*)(cpu->edi + 0x28u)) goto label_0006DC95;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006DD34:
    cpu->esi = 0u;
    if ((int32_t)g_sfera_landscape_patch_lookup_runtime.active_count <= (int32_t)cpu->esi) goto label_0006DD7A;
    label_0006DD40:
    if ((int32_t)cpu->esi >= 0) goto label_0006DD4E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DD4Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DD4Eu));
    label_0006DD4E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_visibility_indices.capacity) goto label_0006DD62;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DD62u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DD62u));
    label_0006DD62:
    cpu->edx = g_sfera_scene_array_runtime.object_visibility_indices.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    ++cpu->esi;
    *(uint32_t*)(cpu->eax) = 0u;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_patch_lookup_runtime.active_count) goto label_0006DD40;
    label_0006DD7A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046DD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_push32(cpu, cpu->ebp);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_push32(cpu, cpu->edi);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.11999999731779099);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, 100000.0);
    cpu->fpu[3u] = (cpu->fpu[3u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DDACu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46DDACu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->esi = cpu->eax + 0xFFFE7960u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[4u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DDC7u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46DDC7u));
    lift_x87_push(cpu, cpu->fpu[4u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    cpu->ebp = cpu->eax + 0xFFFE7960u;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[4u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DDDAu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46DDDAu));
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[3u]);
    cpu->ebx = cpu->eax + 0xFFFE7960u;
    cpu->eax = 0u;
    g_sfera_landscape_patch_lookup_runtime.active_count = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    g_sfera_scene_build_runtime.object_count = cpu->eax;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DDFDu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46DDFDu));
    cpu->edi = cpu->eax + 0xFFFE7960u;
    if ((int32_t)cpu->edi > (int32_t)cpu->ebp) goto label_0006DE76;
    goto label_0006DE0D;
    label_0006DE09:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0006DE0D:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) > (int32_t)cpu->ebx) goto label_0006DE71;
    label_0006DE13:
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->esp -= 0x10u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DE60u)); sfera_sub_0046D8B0(cpu, LIFT_CODE_TOKEN_VA(0x46DE60u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    ++cpu->esi;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    if ((int32_t)cpu->esi <= (int32_t)cpu->ebx) goto label_0006DE13;
    label_0006DE71:
    ++cpu->edi;
    if ((int32_t)cpu->edi <= (int32_t)cpu->ebp) goto label_0006DE09;
    label_0006DE76:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = 0u;
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)g_sfera_landscape_patch_lookup_runtime.active_count <= (int32_t)cpu->esi) goto label_0006DEBF;
    label_0006DE86:
    if ((int32_t)cpu->esi >= 0) goto label_0006DE94;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DE94u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6DE94u));
    label_0006DE94:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_visibility_indices.capacity) goto label_0006DEA8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6DEA8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6DEA8u));
    label_0006DEA8:
    cpu->eax = g_sfera_scene_array_runtime.object_visibility_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    ++cpu->esi;
    *(uint32_t*)(cpu->ecx) = 0u;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_patch_lookup_runtime.active_count) goto label_0006DE86;
    label_0006DEBF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046DED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x90u;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi + 0x1B20u;
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DF1Du)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x46DF1Du));
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_0006EC39;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_0006EC39;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_0006EC39;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_0006EC39;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_0006EC39;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_0006EC39;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46DF98u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x46DF98u));
    if (cpu->eax == 0u) goto label_0006EC39;
    cpu->edx = cpu->esi + 0x1D78u;
    cpu->ebx = cpu->esi + 0xCu;
    cpu->ebp = cpu->esi + 0x24F8u;
    cpu->ecx = cpu->esi + 0x1B98u;
    g_sfera_landscape_patch_lookup_runtime.visible_count = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = 4u;
    cpu->esi = 1u;
    label_0006DFE0:
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E009u)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x46E009u));
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_0006E2CB;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_0006E2CB;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_0006E2CB;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_0006E2CB;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_0006E2CB;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_0006E2CB;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E084u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x46E084u));
    if (cpu->eax == 0u) goto label_0006E2CB;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = 4u;
    label_0006E0A4:
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E0CDu)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x46E0CDu));
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_0006E29A;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_0006E29A;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_0006E29A;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_0006E29A;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_0006E29A;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_0006E29A;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E148u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x46E148u));
    if (cpu->eax == 0u) goto label_0006E29A;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 9u;
    label_0006E160:
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E18Bu)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x46E18Bu));
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_0006E28A;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_0006E28A;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_0006E28A;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_0006E28A;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_0006E28A;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_0006E28A;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E206u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x46E206u));
    if (cpu->eax == 0u) goto label_0006E28A;
    cpu->esi = g_sfera_landscape_patch_lookup_runtime.visible_count;
    if ((int32_t)cpu->esi >= 0) goto label_0006E222;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E222u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6E222u));
    label_0006E222:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006E236;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E236u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E236u));
    label_0006E236:
    cpu->edx = g_sfera_light_runtime.cell_indices.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->ebx;
    cpu->esi = g_sfera_landscape_patch_lookup_runtime.visible_count;
    if ((int32_t)cpu->esi >= 0) goto label_0006E253;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E253u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6E253u));
    label_0006E253:
    { uint64_t l=cpu->esi, r=g_sfera_light_runtime.cell_records.capacity, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006E267;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E267u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E267u));
    label_0006E267:
    cpu->edi = cpu->esi + (cpu->esi * 2u);
    cpu->edi <<= 5u;
    cpu->edi += g_sfera_light_runtime.cell_records.data;
    cpu->ecx = 0x18u;
    cpu->esi = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    lift_movs32(cpu, 1u);
    ++g_sfera_landscape_patch_lookup_runtime.visible_count;
    cpu->esi = 1u;
    label_0006E28A:
    cpu->ebp += 0x78u;
    cpu->ebx += 0x30u;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x1Cu), r=cpu->esi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x1Cu) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006E160;
    label_0006E29A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx += 0x78u;
    cpu->ebx += 0x1B0u;
    cpu->ebp += 0x438u;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x30u), r=cpu->esi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x30u) = v; }
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006E0A4;
    label_0006E2CB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x1E0u) + (uint64_t)(0u);
    cpu->ecx += 0x78u;
    cpu->ebp += 0x10E0u;
    cpu->ebx += 0x6C0u;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x24u), r=cpu->esi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x24u) = v; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006DFE0;
    cpu->ecx = g_sfera_landscape_patch_lookup_runtime.visible_count;
    if (cpu->ecx == 0u) goto label_0006EC39;
    lift_x87_push(cpu, 10000.0);
    cpu->ebp = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_0006E6C7;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    goto label_0006E334;
    label_0006E330:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0006E334:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->ebp >= 0) goto label_0006E344;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E344u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6E344u));
    label_0006E344:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006E358;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E358u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E358u));
    label_0006E358:
    cpu->eax = g_sfera_light_runtime.cell_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebp * 4u));
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1B0Cu);
    cpu->ecx = cpu->eax + (cpu->ecx * 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->ebp >= 0) goto label_0006E391;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E391u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6E391u));
    label_0006E391:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_records.capacity) goto label_0006E3A5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E3A5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E3A5u));
    label_0006E3A5:
    cpu->eax = g_sfera_light_runtime.cell_records.data;
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->eax + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->eax + 0x20u);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edx;
    if ((int32_t)cpu->ebp >= 0) goto label_0006E3D5;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E3D0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x46E3D0u));
    cpu->eax = g_sfera_light_runtime.cell_records.data;
    label_0006E3D5:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_records.capacity) goto label_0006E3EE;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E3E9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x46E3E9u));
    cpu->eax = g_sfera_light_runtime.cell_records.data;
    label_0006E3EE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->eax + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->eax + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->ecx + cpu->eax + 0x44u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    cpu->edi = cpu->esi + 1u;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_01 <= (int32_t)cpu->esi) goto label_0006E4CB;
    label_0006E424:
    if ((int32_t)cpu->esi >= 0) goto label_0006E432;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E432u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6E432u));
    label_0006E432:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_0006E446;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E446u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E446u));
    label_0006E446:
    cpu->edx = g_sfera_light_runtime.visible_handles.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006E4BC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006E4BC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006E4BC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x2Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006E4BC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x30u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006E4BC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x34u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006E4BC;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x10u)) | (uint64_t)(cpu->edi);
    ++cpu->ebx;
    if (cpu->ebx == 7u) goto label_0006E4CB;
    label_0006E4BC:
    ++cpu->esi;
    cpu->edi += cpu->edi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_client_main_scalar_runtime.counter_01) goto label_0006E424;
    label_0006E4CB:
    if ((int32_t)cpu->ebp >= 0) goto label_0006E4D9;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E4D9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6E4D9u));
    label_0006E4D9:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_records.capacity) goto label_0006E4ED;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E4EDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E4EDu));
    label_0006E4ED:
    cpu->eax = g_sfera_light_runtime.cell_records.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx + cpu->eax + 8u;
    cpu->edi = cpu->ebx + 8u;
    (void)cpu;
    label_0006E500:
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_0006E518;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E518u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E518u));
    label_0006E518:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xFFFFFFF8u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xFFFFFFFCu)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E567u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x46E567u));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_x87_compare(cpu, cpu->fpu[0u], 50.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006E57D;
    ++cpu->ebx;
    label_0006E57D:
    cpu->esi += 0xCu;
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006E500;
    if (cpu->ebx != 8u) goto label_0006E597;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x10u)) | (uint64_t)(0x40000000u);
    label_0006E597:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1B1Cu);
    { uint64_t l=*(uint32_t*)(cpu->ecx + (cpu->edx * 8u) + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->ecx + (cpu->edx * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006E6AD;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0006E5D9;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E5D9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6E5D9u));
    label_0006E5D9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_0006E5ED;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6E5EDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6E5EDu));
    label_0006E5ED:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    cpu->esi += g_sfera_scene_array_runtime.scene_records.data;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx));
    *(float*)(cpu->edi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx &= 0x3FFFFFFFu;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.x));
    lift_x87_push(cpu, 4.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    lift_x87_push(cpu, 8.333333015441895);
    cpu->fpu[2u] = (cpu->fpu[2u]) / (cpu->fpu[0u]);
    lift_x87_push(cpu, 10000.0);
    cpu->fpu[3u] = (cpu->fpu[3u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E638u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46E638u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->eax + cpu->edx + 0xFFFFD8F0u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z));
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E658u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46E658u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->eax + cpu->ecx + 0xFFFFD8F0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    if ((int32_t)cpu->ebp >= 0) goto label_0006E67B;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E675u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x46E675u));
    lift_x87_push(cpu, 10000.0);
    label_0006E67B:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_records.capacity) goto label_0006E697;
    cpu->edx = cpu->ebp;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E691u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x46E691u));
    lift_x87_push(cpu, 10000.0);
    label_0006E697:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi += g_sfera_light_runtime.cell_records.data;
    cpu->edi += 0x14u;
    cpu->ecx = 0x18u;
    lift_movs32(cpu, 1u);
    goto label_0006E6B3;
    label_0006E6AD:
    lift_x87_push(cpu, 10000.0);
    label_0006E6B3:
    cpu->ecx = g_sfera_landscape_patch_lookup_runtime.visible_count;
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x60u) + (uint64_t)(0u);
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ecx) goto label_0006E330;
    label_0006E6C7:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_12 == 0u) goto label_0006EBAE;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_0006EBAE;
    lift_x87_push(cpu, 8.333330154418945);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    goto label_0006E720;
    label_0006E700:
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, 8.333330154418945);
    lift_x87_push(cpu, 10000.0);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_0006E720:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->esi >= 0) goto label_0006E75A;
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E73Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x46E73Au));
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, 8.333330154418945);
    lift_x87_push(cpu, 10000.0);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_0006E75A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006E796;
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esi;
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E776u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x46E776u));
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, 8.333330154418945);
    lift_x87_push(cpu, 10000.0);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_0006E796:
    cpu->edx = g_sfera_light_runtime.cell_indices.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    { uint64_t l=*(uint32_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006EB83;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    goto label_0006E7E0;
    label_0006E7C0:
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, 8.333330154418945);
    lift_x87_push(cpu, 10000.0);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_0006E7E0:
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.x));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->fpu[1u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->eax + cpu->ecx);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.y));
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (0.05000000074505806);
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    cpu->ebp = 0u;
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)g_sfera_view_spatial_runtime.world_anchor.z.f32)) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x6Cu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x44u)));
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->edx;
    cpu->edx = *(uint16_t*)(cpu->eax + 2u);
    cpu->eax = *(uint16_t*)(cpu->eax + 4u);
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x44u)));
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edx;
    *(float*)(cpu->esp + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->edx;
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 4u)));
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->eax;
    goto label_0006E921;
    label_0006E901:
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, 8.333330154418945);
    lift_x87_push(cpu, 10000.0);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_0006E921:
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFF00FF00u;
    if (cpu->ebp == 2u) goto label_0006E933;
    cpu->ebx = cpu->ebp + 1u;
    goto label_0006E935;
    label_0006E933:
    cpu->ebx = 0u;
    label_0006E935:
    cpu->eax = cpu->ebp + (cpu->ebp * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + cpu->eax + 0x78u));
    cpu->edi = cpu->esp + cpu->eax + 0x78u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[4u]);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[3u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E95Eu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46E95Eu));
    cpu->esi = cpu->eax;
    cpu->eax = cpu->ebx + (cpu->ebx * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + cpu->eax + 0x78u));
    cpu->ebx = cpu->esp + cpu->eax + 0x78u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[5u]);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[4u]);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006EA1E;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46E9AFu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46E9AFu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006EA1E;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebx)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006EA1E;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, 0x1Fu, 32u);
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->esi -= cpu->ecx;
    { uint64_t x=cpu->esi, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->esi = v; }
    cpu->esi = (uint64_t)(cpu->esi) - (uint64_t)(cpu->esi) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi &= 0xFF010000u;
    cpu->esi += 0xFFFF00FFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    label_0006EA1E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + cpu->eax + 0x80u));
    cpu->eax = cpu->esp + cpu->eax + 0x80u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[4u]);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[3u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EA49u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46EA49u));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + cpu->eax + 0x80u));
    cpu->eax = cpu->esp + cpu->eax + 0x80u;
    cpu->fpu[5u] = cpu->fpu[5u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->fpu[3u] = cpu->fpu[0u] / cpu->fpu[3u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->fpu[3u] = cpu->fpu[3u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006EB22;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EAA7u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46EAA7u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006EB24;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esp + 0x10u)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006EB26;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, 0x1Fu, 32u);
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->esi -= cpu->ecx;
    { uint64_t x=cpu->esi, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->esi = v; }
    cpu->esi = (uint64_t)(cpu->esi) - (uint64_t)(cpu->esi) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi &= 0xFFFFFF01u;
    cpu->esi += 0xFFFF00FFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    goto label_0006EB26;
    label_0006EB22:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006EB24:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006EB26:
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->edx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EB5Cu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x46EB5Cu));
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)3u) goto label_0006E901;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edx + 8u)) goto label_0006E7C0;
    goto label_0006EB8B;
    label_0006EB83:
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006EB8B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EB90u)); sfera_sub_00451EB0(cpu, LIFT_CODE_TOKEN_VA(0x46EB90u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EB95u)); sfera_sub_00451E00(cpu, LIFT_CODE_TOKEN_VA(0x46EB95u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = g_sfera_landscape_patch_lookup_runtime.visible_count;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_0006E700;
    goto label_0006EBB0;
    label_0006EBAE:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006EBB0:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esi = 0u;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if ((int32_t)cpu->ecx <= (int32_t)cpu->esi) goto label_0006EC2C;
    label_0006EBC0:
    if ((int32_t)cpu->esi >= 0) goto label_0006EBCE;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6EBCEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6EBCEu));
    label_0006EBCE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006EBE2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6EBE2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6EBE2u));
    label_0006EBE2:
    cpu->eax = g_sfera_light_runtime.cell_indices.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1B0Cu);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edi += *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ebx = cpu->ecx + (cpu->eax * 4u);
    if ((int32_t)cpu->edi <= (int32_t)0x7530u) goto label_0006EC21;
    cpu->edx = cpu->esi + 0xFFFFFFFFu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EC1Bu)); sfera_sub_0046C0B0(cpu, LIFT_CODE_TOKEN_VA(0x46EC1Bu));
    cpu->edi = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_0006EC21:
    cpu->ecx = g_sfera_landscape_patch_lookup_runtime.visible_count;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ecx) goto label_0006EBC0;
    label_0006EC2C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    --cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6EC39u)); sfera_sub_0046C0B0(cpu, LIFT_CODE_TOKEN_RVA(0x6EC39u));
    label_0006EC39:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x90u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046EC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006EC8F;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6EC8Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6EC8Fu));
    label_0006EC8F:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (8.333333015441895);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (12000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46ECABu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46ECABu));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xCu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006ECCB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ECCBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6ECCBu));
    label_0006ECCB:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (8.333333015441895);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (12000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46ECE8u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46ECE8u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xCu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ebp = cpu->edx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006ED06;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ED06u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6ED06u));
    label_0006ED06:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (100.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46ED23u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46ED23u));
    cpu->esi = cpu->eax + 0xFFFFFC18u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006ED3D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ED3Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6ED3Du));
    label_0006ED3D:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (100.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46ED5Au)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46ED5Au));
    cpu->ecx = 0x40Fu;
    cpu->ecx -= cpu->eax;
    { uint64_t l=cpu->esi, r=0x28u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0006ED6B;
    if ((int32_t)cpu->esi < (int32_t)0x50u) goto label_0006ED6D;
    label_0006ED6B:
    cpu->esi = 0u;
    label_0006ED6D:
    if ((int32_t)cpu->ecx < 0) goto label_0006ED76;
    { uint64_t l=cpu->ecx, r=0x50u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006ED78;
    label_0006ED76:
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_0006ED78:
    cpu->eax = cpu->esi + (cpu->esi * 4u);
    cpu->eax <<= 4u;
    cpu->eax += cpu->ecx;
    cpu->esi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->ebx = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    cpu->ecx = cpu->ebx + (cpu->ebx * 4u);
    cpu->edi = cpu->eax + (cpu->ecx * 2u);
    { uint64_t l=*(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x8Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006EDB6;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6EDB6u)); sfera_sub_0046CBA0(cpu, LIFT_CODE_TOKEN_RVA(0x6EDB6u));
    label_0006EDB6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x53Cu) = 0x3E8u;
    cpu->edi = *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x8Cu);
    cpu->edx = cpu->ebp + (cpu->ebp * 2u);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B1Cu);
    *(float*)(cpu->edx + (cpu->ecx * 8u)) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->edx + (cpu->ecx * 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = 0x646E616Cu;
    cpu->eax = 0x70616373u;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x5C65)) & 0xFFFFu);
    lift_push32(cpu, 0x27u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->eax = cpu->esp + 0x2Fu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint16_t*)(cpu->esp + 0x34u) = cpu->ecx & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0x36u) = cpu->edx & 0xFFu;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46EE20u));
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    label_0006EE30:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006EE30;
    cpu->edi = cpu->esp + 0x20u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0006EE40:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    { uint64_t v= cpu->ecx & 0xFFu; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006EE40;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = cpu->esp + 0x20u;
    lift_movs8(cpu, 1u);
    cpu->edx = cpu->eax + 1u;
    label_0006EE60:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006EE60;
    cpu->edi = cpu->esp + 0x20u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0006EE70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006EE70;
    cpu->ecx = *(uint32_t*)((uintptr_t)"_00");
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x18u));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + cpu->eax + 0x21u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + cpu->eax + 0x22u) = cpu->ecx & 0xFFu;
    cpu->eax = cpu->esp + 0x20u;
    --cpu->eax;
    label_0006EE97:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006EE97;
    cpu->edx = *(uint32_t*)((uintptr_t)".wtr");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".wtr") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1B1Cu);
    cpu->ecx = 0u;
    cpu->ebp = 0u;
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->eax += 0xCu;
    cpu->edx = cpu->ecx + 0x24u;
    label_0006EEC8:
    cpu->ebx = 0u;
    { uint64_t l=*(uint32_t*)(cpu->eax + 0xFFFFFFF8u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx += cpu->ebx;
    cpu->ebx = 0u;
    { uint64_t l=*(uint32_t*)(cpu->eax), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi += cpu->ebx;
    cpu->ebx = 0u;
    { uint64_t l=*(uint32_t*)(cpu->eax + 8u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edi += cpu->ebx;
    cpu->ebx = 0u;
    { uint64_t l=*(uint32_t*)(cpu->eax + 0x10u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 0x20u;
    cpu->ebp += cpu->ebx;
    { uint64_t l=cpu->edx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006EEC8;
    cpu->esi += cpu->edi;
    cpu->esi += cpu->ebp;
    { uint64_t l=cpu->ecx, r=cpu->esi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006EF20;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_unlink), LIFT_CODE_TOKEN_VA(0x46EF02u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0006EF20:
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EF29u)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x46EF29u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1B1Cu);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x480u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EF41u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x46EF41u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EF48u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x46EF48u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046EF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2Cu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    lift_push32(cpu, cpu->ebp);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.11999999731779099);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, 100000.0);
    cpu->fpu[3u] = (cpu->fpu[3u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EF8Bu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46EF8Bu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ebp = cpu->eax + 0xFFFE7960u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[4u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EFA6u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46EFA6u));
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[5u] = cpu->fpu[5u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = cpu->eax + 0xFFFE7960u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EFBBu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46EFBBu));
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->edi = cpu->eax + 0xFFFE7960u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    g_sfera_scene_build_runtime.object_count = 0u;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46EFDCu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x46EFDCu));
    cpu->eax -= 0x186A0u;
    if ((int32_t)cpu->eax > (int32_t)cpu->esi) goto label_0006F275;
    cpu->ecx = cpu->eax + 0x1D4C0u;
    cpu->esi -= cpu->eax;
    cpu->eax = 1u;
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    label_0006F001:
    if ((int32_t)cpu->ebp > (int32_t)cpu->edi) goto label_0006F266;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xCu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->eax, r=0xFFFFD8F0u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->ecx = cpu->edx;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    { uint64_t l=cpu->edi, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->ebx = cpu->eax;
    { uint64_t l=cpu->ebx, r=0x80000001u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006F04F;
    --cpu->ebx;
    cpu->ebx |= 0xFFFFFFFEu;
    ++cpu->ebx;
    label_0006F04F:
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->ebp + 0x1D4C0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = cpu->ecx;
    cpu->esi -= cpu->edx;
    { uint64_t l=cpu->eax, r=cpu->ebp, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    { uint64_t l=cpu->eax, v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_0006F08C;
    label_0006F080:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0006F08C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xCu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ebp = cpu->eax + 0xFFFFD8F0u;
    cpu->ecx = cpu->edx;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = cpu->edi + (cpu->eax * 2u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax;
    { uint64_t l=cpu->edx, r=0x80000001u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006F0D2;
    --cpu->edx;
    cpu->edx |= 0xFFFFFFFEu;
    ++cpu->edx;
    label_0006F0D2:
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->ecx -= cpu->eax;
    cpu->esi = cpu->esi + (cpu->ecx * 2u);
    cpu->esi += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = 0x27u;
    cpu->edx = cpu->ebx + (cpu->edx * 2u);
    cpu->eax -= cpu->ebp;
    { uint64_t l=cpu->ecx, r=0x28u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0006F0F8;
    if ((int32_t)cpu->ecx < (int32_t)0x50u) goto label_0006F0FA;
    label_0006F0F8:
    cpu->ecx = 0u;
    label_0006F0FA:
    if ((int32_t)cpu->eax < 0) goto label_0006F103;
    { uint64_t l=cpu->eax, r=0x50u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006F105;
    label_0006F103:
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_0006F105:
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->ecx <<= 4u;
    cpu->eax += cpu->ecx;
    cpu->edi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edx = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    cpu->ecx = cpu->edx + (cpu->edx * 4u);
    cpu->ebx = cpu->eax + (cpu->ecx * 2u);
    if (*(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x8Cu) != 0u) goto label_0006F13D;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F13Du)); sfera_sub_0046CBA0(cpu, LIFT_CODE_TOKEN_RVA(0x6F13Du));
    label_0006F13D:
    *(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x53Cu) = 0x3E8u;
    cpu->ebx = *(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x8Cu);
    cpu->edi = g_sfera_scene_build_runtime.object_count;
    if ((int32_t)cpu->edi >= 0) goto label_0006F163;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F163u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F163u));
    label_0006F163:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_sort_keys.capacity) goto label_0006F177;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F177u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F177u));
    label_0006F177:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = cpu->edx + (cpu->eax * 4u);
    cpu->eax = cpu->esi + (cpu->ecx * 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = g_sfera_scene_array_runtime.object_sort_keys.data;
    cpu->ecx += cpu->ecx;
    cpu->edx = cpu->ebx + (cpu->ecx * 8u) + 0xCu;
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = cpu->edx;
    cpu->eax = g_sfera_scene_build_runtime.object_count;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0006F1AD;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F1ADu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F1ADu));
    label_0006F1AD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_sort_indices.capacity) goto label_0006F1C1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F1C1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F1C1u));
    label_0006F1C1:
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_indices.data;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->ebx;
    cpu->esi = g_sfera_scene_build_runtime.object_count;
    if ((int32_t)cpu->esi >= 0) goto label_0006F1DE;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F1DEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F1DEu));
    label_0006F1DE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_draw_indices.capacity) goto label_0006F1F2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F1F2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F1F2u));
    label_0006F1F2:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = g_sfera_scene_array_runtime.object_draw_indices.data;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u)))));
    *(float*)(cpu->eax + (cpu->esi * 4u)) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = g_sfera_scene_build_runtime.object_count;
    if ((int32_t)cpu->esi >= 0) goto label_0006F21D;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F21Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F21Du));
    label_0006F21D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.candidate_handles.capacity) goto label_0006F231;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F231u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F231u));
    label_0006F231:
    cpu->ecx = g_sfera_collision_runtime.candidate_handles.data;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u)))));
    *(float*)(cpu->ecx + (cpu->esi * 4u)) = cpu->fpu[0u]; lift_x87_pop(cpu);
    g_sfera_scene_build_runtime.object_count = (uint64_t)(g_sfera_scene_build_runtime.object_count) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x18u) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006F080;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0006F266:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x20u), r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x20u) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006F001;
    cpu->ebx = lift_pop32(cpu);
    label_0006F275:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046F280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x180u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x190u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x188u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x194u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1ACu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46F2D0u)); sfera_sub_0046EF60(cpu, LIFT_CODE_TOKEN_VA(0x46F2D0u));
    cpu->ebx = 0u;
    cpu->edi = 0u;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    if ((int32_t)g_sfera_scene_build_runtime.object_count <= (int32_t)cpu->ebx) goto label_0006F568;
    goto label_0006F2F4;
    label_0006F2F0:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x40u);
    label_0006F2F4:
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0006F302;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F302u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F302u));
    label_0006F302:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_sort_keys.capacity) goto label_0006F316;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F316u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F316u));
    label_0006F316:
    cpu->edx = g_sfera_scene_array_runtime.object_sort_keys.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0006F331;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F331u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F331u));
    label_0006F331:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_sort_indices.capacity) goto label_0006F345;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F345u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F345u));
    label_0006F345:
    cpu->eax = g_sfera_scene_array_runtime.object_sort_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0006F35F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F35Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F35Fu));
    label_0006F35F:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_draw_indices.capacity) goto label_0006F373;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F373u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F373u));
    label_0006F373:
    cpu->edx = g_sfera_scene_array_runtime.object_draw_indices.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + (cpu->edi * 4u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0006F38E;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F38Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F38Eu));
    label_0006F38E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_collision_runtime.candidate_handles.capacity) goto label_0006F3A2;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F3A2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F3A2u));
    label_0006F3A2:
    cpu->eax = g_sfera_collision_runtime.candidate_handles.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + (cpu->edi * 4u)));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)*(uint32_t*)(cpu->esi + 8u) <= (int32_t)cpu->ebx) goto label_0006F551;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    label_0006F3C7:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = *(uint16_t*)(cpu->edx);
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->ecx * 8u));
    cpu->ecx = cpu->eax + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    cpu->ecx = *(uint16_t*)(cpu->edx + 2u);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + (cpu->ecx * 8u));
    cpu->ecx = cpu->eax + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->edx + 4u);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->eax = cpu->eax + (cpu->ecx * 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006F4A0;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006F4A0;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007032F;
    label_0006F4A0:
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006F4C8;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006F4CA;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0006F534;
    goto label_0006F4CC;
    label_0006F4C8:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006F4CA:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006F4CC:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006F500;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006F500;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00070336;
    label_0006F500:
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00070113;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00070115;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00070117;
    label_0006F532:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006F534:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006F536:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_0006F3C7;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0006F551:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    ++cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_build_runtime.object_count) goto label_0006F2F0;
    label_0006F568:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x194u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1A0u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x198u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1ACu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46F59Au)); sfera_sub_0046DD80(cpu, LIFT_CODE_TOKEN_VA(0x46F59Au));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    if ((int32_t)g_sfera_landscape_patch_lookup_runtime.active_count <= (int32_t)cpu->ebx) goto label_0006FFAA;
    label_0006F5B0:
    if ((int32_t)cpu->esi >= 0) goto label_0006F5BE;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F5BEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F5BEu));
    label_0006F5BE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_character_index_map.capacity) goto label_0006F5D2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F5D2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F5D2u));
    label_0006F5D2:
    cpu->edx = g_sfera_character_index_map.data;
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if ((int32_t)cpu->edi >= 0) goto label_0006F5E9;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F5E9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F5E9u));
    label_0006F5E9:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006F5FD;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F5FDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F5FDu));
    label_0006F5FD:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ebx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46F614u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x46F614u));
    cpu->ebp = cpu->eax;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x1BCu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006FF95;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1A4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1A8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1ACu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1B0u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1B4u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1B8u);
    cpu->ebx += 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_0006F67A;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F67Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6F67Au));
    label_0006F67A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_character_index_map.capacity) goto label_0006F68E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6F68Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6F68Eu));
    label_0006F68E:
    cpu->edx = g_sfera_character_index_map.data;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46F6A0u)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x46F6A0u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->edi = cpu->esp + 0x128u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xCu)));
    cpu->edi = cpu->esp + 0x78u;
    lift_movs32(cpu, 1u);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x1Cu)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x2Cu)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    cpu->edi = cpu->esp + 0x128u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    cpu->edi &= 0xFFFFFFF0u;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = 0x10u;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = cpu->esp + 0x78u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->edi;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0xA4u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x94u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x84u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_movs32(cpu, 1u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x1Cu)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x2Cu)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax)));
    cpu->edx = cpu->esp + 0xB8u;
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46F802u)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x46F802u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xB8u));
    cpu->eax = cpu->esp + 0x128u;
    cpu->eax &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xBCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xC0u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xB8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xBCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xC0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xC4u));
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xC8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xC4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xC8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xD0u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xD4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xD8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xD0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xD4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xD8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xDCu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xE0u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xE4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xDCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xE0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xE4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xE8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xF0u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    cpu->esi = cpu->ebx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xE8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xECu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xF0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xF4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xF8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xFCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xF4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xF8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xFCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x100u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x104u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    cpu->edi = cpu->eax;
    cpu->esi = cpu->ebx;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x108u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x100u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x104u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->eax;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x108u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x118u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x110u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x114u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x110u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esp + 0xBCu;
    *(float*)(cpu->esp + 0x118u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46FD21u)); sfera_sub_0044F870(cpu, LIFT_CODE_TOKEN_VA(0x46FD21u));
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x19Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006FF95;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_0006FD40:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1A0u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if ((int32_t)*(uint32_t*)(cpu->edx + 4u) <= (int32_t)cpu->esi) goto label_0006FF7B;
    label_0006FD60:
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    { uint64_t l=cpu->eax, r=cpu->esi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->ecx <<= 4u;
    cpu->ecx += *(uint32_t*)(cpu->ebp + 0x1A4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0006FF6D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0006FF6D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0006FF6D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x6Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0006FF6D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x70u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0006FF6D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x74u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0006FF6D;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x18u)));
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x20u)));
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 0x3Cu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 0x40u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x34u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], 0.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0006FF6D;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 0x3Cu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 0x40u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x58u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], 0.699999988079071);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0006FF6D;
    cpu->esi = cpu->esp + 0x168u;
    cpu->ebp = cpu->ecx + 0x18u;
    *(uint32_t*)(cpu->esp + 0x28u) = 3u;
    (void)cpu;
    label_0006FE70:
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    cpu->edi = cpu->eax;
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    ++cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    *(float*)(cpu->esp + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebx + 4u)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x68u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebx + 8u)));
    cpu->fpu[4u] = cpu->fpu[4u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0xCu));
    cpu->fpu[4u] = cpu->fpu[4u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebx + 0x14u)));
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebx + 0x10u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[3u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebx + 0x18u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebx + 0x1Cu)));
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x20u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebx + 0x24u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebx + 0x2Cu)));
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle) = cpu->eax;
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->edi >= 0) goto label_0006FF09;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6FF09u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6FF09u));
    label_0006FF09:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.scene_points.capacity) goto label_0006FF1D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6FF1Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6FF1Du));
    label_0006FF1D:
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = cpu->edi + (cpu->edi * 2u);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebp += 0xCu;
    { uint64_t l=cpu->esi, r=0xCu, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x28u), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x28u) = v; }
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006FE70;
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle), 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax == 0x12Cu) goto label_0006FFAA;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x60u);
    label_0006FF6D:
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edx + 4u)) goto label_0006FD60;
    label_0006FF7B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebp + 0x19Cu)) goto label_0006FD40;
    label_0006FF95:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_patch_lookup_runtime.active_count) goto label_0006F5B0;
    label_0006FFAA:
    cpu->esi = 0u;
    { uint64_t l=(*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle), r=cpu->esi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000700E1;
    cpu->edi = 0u;
    label_0006FFC0:
    if ((int32_t)cpu->esi >= 0) goto label_0006FFCE;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6FFCEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6FFCEu));
    label_0006FFCE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_points.capacity) goto label_0006FFE2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6FFE2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6FFE2u));
    label_0006FFE2:
    { uint64_t l=g_sfera_world_objects.object_handles.capacity, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00070016;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70016u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x70016u));
    label_00070016:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, 0.014999999664723873);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->esi >= 0) goto label_000700A0;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x700A0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x700A0u));
    label_000700A0:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_points.capacity) goto label_000700B4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x700B4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x700B4u));
    label_000700B4:
    cpu->edx = g_sfera_scene_array_runtime.scene_points.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax = cpu->edi + cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    ++cpu->esi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edi += 0xCu;
    { uint64_t l=cpu->esi, r=(*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006FFC0;
    label_000700E1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18Cu);
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle), 32u, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ebp = lift_pop32(cpu);
    cpu->eax += cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle) = cpu->eax;
    cpu->esp += 0x180u;
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
    label_00070113:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00070115:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00070117:
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007014D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007014D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007031C;
    label_0007014D:
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00070182;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00070184;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00070186;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00070179:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    goto label_0006F536;
    label_00070182:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00070184:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00070186:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1A4u));
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1A8u));
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->esp + 0x1ACu))) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1B0u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1B4u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1B8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], 0.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00070179;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edx + 0x14u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x50u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edx + 0x18u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], 0.699999988079071);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00070179;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_00070225;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70225u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x70225u));
    label_00070225:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_points.capacity) goto label_00070239;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70239u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x70239u));
    label_00070239:
    cpu->edx = g_sfera_scene_array_runtime.scene_points.data;
    cpu->ecx = cpu->esi + (cpu->esi * 2u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_00070270;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70270u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x70270u));
    label_00070270:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_points.capacity) goto label_00070284;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70284u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x70284u));
    label_00070284:
    cpu->ecx = g_sfera_scene_array_runtime.scene_points.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->esi + (cpu->esi * 2u);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_000702BB;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x702BBu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x702BBu));
    label_000702BB:
    { uint64_t l=cpu->esi, r=g_sfera_scene_array_runtime.scene_points.capacity, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000702CF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x702CFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x702CFu));
    label_000702CF:
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->edx = cpu->esi + (cpu->esi * 2u);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle), 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax == 0x12Cu) goto label_0006FFAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    goto label_0006F536;
    label_0007031C:
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    goto label_0006F536;
    label_0007032F:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0006F532;
    label_00070336:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0006F534;
}
__declspec(noinline) void sfera_sub_00470350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x58u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, 0.11999999731779099);
    lift_push32(cpu, cpu->esi);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, 100000.0);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->fpu[2u] = (cpu->fpu[2u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470379u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x470379u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x6Cu)));
    cpu->esi = cpu->eax;
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470386u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x470386u));
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->esi + 0x4E20u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->esi = 0xCu;
    lift_divide_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edi = cpu->eax + 0xFFFFD8F0u;
    cpu->eax = cpu->ecx + 0x4E20u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = cpu->esi;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ecx = 0x27u;
    cpu->ebx = cpu->eax + 0xFFFFD8F0u;
    cpu->eax = cpu->edi + 0x28u;
    cpu->ecx -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    if (cpu->eax > 0x4Fu) goto label_0007062D;
    { uint64_t l=cpu->ecx, r=0x4Fu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0007062D;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax <<= 4u;
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->esi = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470400u)); sfera_sub_0046D240(cpu, LIFT_CODE_TOKEN_VA(0x470400u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->esi + (cpu->esi * 4u);
    cpu->edx = cpu->ecx + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->edx * 4u) + 0x8Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, *(uint32_t*)(cpu->esp + 0x10u), 32u, 1u);
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 1u);
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    { uint64_t l=cpu->esi, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, *(uint32_t*)(cpu->esp + 0x10u), 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->eax + (cpu->edx * 2u);
    cpu->eax = cpu->ecx;
    { uint64_t l=cpu->eax, r=0x80000001u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0007046E;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    ++cpu->eax;
    label_0007046E:
    cpu->edx = cpu->eax + (cpu->edx * 2u);
    cpu->eax = cpu->esi;
    { uint64_t l=cpu->eax, r=0x80000001u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0007047F;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    ++cpu->eax;
    label_0007047F:
    cpu->eax = cpu->eax + (cpu->edx * 2u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x64u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x64u);
    cpu->eax -= cpu->ecx;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax -= cpu->esi;
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp;
    cpu->ecx = cpu->ecx + (cpu->eax * 2u);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    cpu->edx += cpu->edx;
    cpu->eax = cpu->ecx + (cpu->edx * 8u) + 0xCu;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x6Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x70u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x6Cu));
    *(uint32_t*)(cpu->esp + 0x6Cu) = 0u;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)-10000.0f);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x70u));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)-9000.0f);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->ebx <= 0) goto label_000705C8;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esi = *(uint32_t*)(cpu->eax + 0xCu);
    label_00070520:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->eax = *(uint16_t*)(cpu->esi);
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    cpu->edi = cpu->ebp + (cpu->eax * 8u);
    cpu->eax = *(uint16_t*)(cpu->esi + 2u);
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x18u));
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint16_t*)(cpu->esi + 4u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x14u)));
    cpu->edx = cpu->ebp + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->ebp + (cpu->eax * 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x18u)));
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x64u;
    *(float*)(cpu->esp + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470595u)); sfera_sub_00451A40(cpu, LIFT_CODE_TOKEN_VA(0x470595u));
    if (cpu->eax != 1u) goto label_000705B4;
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 3u);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4705B0u)); sfera_sub_00451B40(cpu, LIFT_CODE_TOKEN_VA(0x4705B0u));
    if (cpu->eax != 0u) goto label_000705D4;
    label_000705B4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    ++cpu->eax;
    cpu->esi += 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->ebx) goto label_00070520;
    label_000705C8:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000705D4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->ebp = lift_pop32(cpu);
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x14u)));
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->edi = lift_pop32(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 8u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x18u)));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esp += 0x58u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007062D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00470640(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0xA0u;
    lift_x87_push(cpu, 2.0);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47065Du)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x47065Du));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->esp -= 8u;
    cpu->fpu[0u] = (2.450000047683716) / (cpu->fpu[0u]);
    cpu->edx = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47068Bu)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x47068Bu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)0.75f));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    cpu->esp -= 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (2.450000047683716);
    cpu->edx = cpu->esp + 0x60u;
    cpu->ecx = cpu->esp + 0x38u;
    *(double*)(cpu->esp + 0x88u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4706E3u)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x4706E3u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    cpu->esp -= 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (2.450000047683716);
    cpu->edx = cpu->esp + 0x64u;
    cpu->ecx = cpu->esp + 0x38u;
    *(double*)(cpu->esp + 0xA0u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47071Du)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x47071Du));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    cpu->esp -= 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (2.450000047683716);
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x38u;
    *(double*)(cpu->esp + 0x80u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470757u)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x470757u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    cpu->esp -= 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (2.450000047683716);
    cpu->edx = cpu->esp + 0x6Cu;
    cpu->ecx = cpu->esp + 0x38u;
    *(double*)(cpu->esp + 0x98u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470791u)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x470791u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->esp -= 8u;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->edx = cpu->esp + 0x70u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 0xCu)));
    cpu->ecx = cpu->esp + 0x38u;
    *(double*)(cpu->esp + 0xA8u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 8u)));
    *(double*)(cpu->esp + 0x90u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4707DAu)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x4707DAu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->edx = cpu->esp + 0x74u;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = cpu->esp + 0x38u;
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(double*)(cpu->esp + 0x20u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->ebp + 8u))) - (cpu->fpu[0u]);
    *(double*)(cpu->esp + 0x58u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470821u)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x470821u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esp + 0x78u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->ecx = cpu->esp + 0x38u;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470848u)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x470848u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esp + 0x7Cu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->ecx = cpu->esp + 0x38u;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47086Fu)); sfera_sub_00470350(cpu, LIFT_CODE_TOKEN_VA(0x47086Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0x80u));
    cpu->fpu[0u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebp + 8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0x98u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0x78u));
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    cpu->fpu[2u] = cpu->fpu[2u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0x90u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0xA0u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0x88u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (*(double*)(cpu->esp + 0x50u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    cpu->fpu[2u] = cpu->fpu[2u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)0.5f);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00070B65;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00070B65;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00070B65;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x64u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00070B65;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00070B65;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x6Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00070B65;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x70u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00070B65;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x74u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x4Cu)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esp + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00070B67;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    lift_x87_compare(cpu, cpu->fpu[0u], 1e-06);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00070B0C;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470ABBu)); sfera_sub_004EEC4E(cpu, LIFT_CODE_TOKEN_VA(0x470ABBu));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (4.7123894691467285) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    *(float*)(cpu->edi + 8u) = cpu->fpu[0u];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470AD9u)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x470AD9u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(double*)(cpu->esp + 0x50u) = cpu->fpu[0u];
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470AF2u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x470AF2u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x18u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (*(double*)(cpu->esp + 0x50u));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    goto label_00070B13;
    label_00070B0C:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->edi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00070B13:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470B1Cu)); sfera_sub_004EEC4E(cpu, LIFT_CODE_TOKEN_VA(0x470B1Cu));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (4.7123894691467285) - (cpu->fpu[0u]);
    *(float*)(cpu->edi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x470B2Du));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.1415929794311523);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    *(float*)(cpu->edi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->edi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->edi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00070B65:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00070B67:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00470B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_shadow_runtime.manager;
    { uint64_t l=*(uint8_t*)(cpu->esi + 0xA0u), r=4u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00070D95;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x148u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.9900000095367432);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00070D95;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xBCu);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xACu);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xB0u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC0u);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x24u)));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470C27u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x470C27u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u));
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    lift_x87_push(cpu, 0.5);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x5Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.800000011920929);
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[2u]);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[3u]);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->esp -= 0xCu;
    cpu->fpu[4u] = cpu->fpu[4u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
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
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470D7Au)); sfera_sub_0046F280(cpu, LIFT_CODE_TOKEN_VA(0x470D7Au));
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
__declspec(noinline) void sfera_sub_00470DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x70u;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    cpu->fpu[0u] = -cpu->fpu[0u];
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->fpu[0u] = -cpu->fpu[0u];
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470E1Du)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x470E1Du));
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x74u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x70u) = cpu->fpu[0u];
    cpu->eax = cpu->esp + 0x3Cu;
    *(float*)(cpu->esp + 0x6Cu) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x6Cu) = cpu->fpu[0u];
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0x68u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x64u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esp + 0x80u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x6Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470E79u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x470E79u));
    cpu->ebp = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00070E92;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70E92u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x70E92u));
    label_00070E92:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (100.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470EB5u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x470EB5u));
    cpu->edi = cpu->eax + 0xFFFFFC18u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00070ECF;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70ECFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x70ECFu));
    label_00070ECF:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (100.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470EF1u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x470EF1u));
    cpu->esi = cpu->eax + 0xFFFFFC18u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00070F0F;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70F0Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x70F0Fu));
    label_00070F0F:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (100.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470F32u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x470F32u));
    cpu->ebx = cpu->eax + 0xFFFFFC18u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00070F50;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x70F50u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x70F50u));
    label_00070F50:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (100.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1000.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x470F73u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x470F73u));
    cpu->eax -= 0x3E8u;
    cpu->ebp = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_0007107A;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_00070F91:
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_00071068;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x64u);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->ecx = cpu->eax;
    cpu->edi = 0x27u;
    cpu->ecx -= cpu->esi;
    cpu->ebp += 0x28u;
    cpu->edi -= cpu->esi;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_00070FC0:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.x) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.y) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->ebp > 0x4Fu) goto label_00071053;
    { uint64_t l=cpu->edi, r=0x4Fu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00071053;
    cpu->eax = cpu->ebp + (cpu->ebp * 4u);
    cpu->eax <<= 4u;
    cpu->eax += cpu->edi;
    cpu->esi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edx = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    cpu->ecx = cpu->edx + (cpu->edx * 4u);
    cpu->ebx = cpu->eax + (cpu->ecx * 2u);
    if (*(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x8Cu) != 0u) goto label_0007101F;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7101Fu)); sfera_sub_0046CBA0(cpu, LIFT_CODE_TOKEN_RVA(0x7101Fu));
    label_0007101F:
    cpu->edx = *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x21Cu);
    *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x53Cu) = 0x3E8u;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_02) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x8Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471043u)); sfera_sub_0046DED0(cpu, LIFT_CODE_TOKEN_VA(0x471043u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    label_00071053:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x64u) + (uint64_t)(0u);
    --cpu->edi;
    { uint64_t l=cpu->ecx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00070FC0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00071068:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x64u) + (uint64_t)(0u);
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_00070F91;
    label_0007107A:
    cpu->eax = (uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count;
    (void)cpu;
    label_00071080:
    ++*(uint32_t*)(cpu->eax);
    cpu->eax += 0x10u;
    { uint64_t l=cpu->eax, r=((uintptr_t)&g_sfera_texture_cache_runtime.entries[kTextureCacheEntryCount] + offsetof(SferaTextureCacheEntry, use_count)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00071080;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004710A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x178u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->edi) goto label_00071E1A;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000710DB;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x710DBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x710DBu));
    label_000710DB:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebp * 4u)) == cpu->edi) goto label_00071E1A;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000710FD;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x710FDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x710FDu));
    label_000710FD:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47111Au)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47111Au));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.minimum.x.f32));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->ebp;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.minimum.y.f32));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count) = cpu->edi;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.minimum.z.f32));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.maximum.x.f32));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.maximum.y.f32));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.maximum.z.f32));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471173u)); sfera_sub_0046DC30(cpu, LIFT_CODE_TOKEN_VA(0x471173u));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    if ((int32_t)g_sfera_landscape_patch_lookup_runtime.active_count <= (int32_t)cpu->edi) goto label_00071B12;
    label_00071185:
    if ((int32_t)cpu->esi >= 0) goto label_00071193;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71193u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71193u));
    label_00071193:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_character_index_map.capacity) goto label_000711A7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x711A7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x711A7u));
    label_000711A7:
    cpu->eax = g_sfera_character_index_map.data;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if ((int32_t)cpu->edi >= 0) goto label_000711BD;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x711BDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x711BDu));
    label_000711BD:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000711D1;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x711D1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x711D1u));
    label_000711D1:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4711E9u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4711E9u));
    cpu->ebx = cpu->esi + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    if (cpu->edi == cpu->ebp) goto label_00071AF7;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 1u) goto label_00071212;
    if (*(uint8_t*)(cpu->esi + 0x141u) == 0u) goto label_00071AF7;
    label_00071212:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->eax + 0x6Cu) == 3u) goto label_00071AF7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x38u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->edx += *(uint32_t*)(cpu->esi + 0x38u);
    { uint64_t l=(uint32_t)sfera_world_type_has_spatial_extent(cpu->edx), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00071AF7;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471248u)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x471248u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x40u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00071AF7;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x4Cu));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00071AF7;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x44u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00071AF7;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x50u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00071AF7;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x48u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00071AF7;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x54u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00071AF7;
    if (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count != 0x64u) goto label_000713BD;
    cpu->eax = g_sfera_graphics_runtime.runtime_counter;
    ++cpu->eax;
    g_sfera_graphics_runtime.runtime_counter = cpu->eax;
    if (cpu->eax != 0x7D1u) goto label_000713BD;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles;
    g_sfera_graphics_runtime.runtime_counter = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471304u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x471304u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471315u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x471315u));
    cpu->ecx = (uintptr_t)"===CLD_NUM problem =======\n";
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471321u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x471321u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471328u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x471328u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47132Du)); sfera_sub_00451DC0(cpu, LIFT_CODE_TOKEN_VA(0x47132Du));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471338u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x471338u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471346u)); sfera_sub_0044BF00(cpu, LIFT_CODE_TOKEN_VA(0x471346u));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471351u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x471351u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47135Fu)); sfera_sub_0044BF00(cpu, LIFT_CODE_TOKEN_VA(0x47135Fu));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47136Au)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x47136Au));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471378u)); sfera_sub_0044BF00(cpu, LIFT_CODE_TOKEN_VA(0x471378u));
    cpu->esi = 0u;
    label_00071380:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47138Bu)); sfera_sub_00451D50(cpu, LIFT_CODE_TOKEN_VA(0x47138Bu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471398u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x471398u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4713A9u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4713A9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4713B0u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4713B0u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4713B5u)); sfera_sub_00451DC0(cpu, LIFT_CODE_TOKEN_VA(0x4713B5u));
    cpu->esi += 5u;
    if ((int32_t)cpu->esi < (int32_t)0x64u) goto label_00071380;
    label_000713BD:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4713CEu)); sfera_sub_00451D50(cpu, LIFT_CODE_TOKEN_VA(0x4713CEu));
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6Cu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x40u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x44u);
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x48u);
    *(uint32_t*)(cpu->edx + 0x14u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x4Cu);
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x50u);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x54u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    if (cpu->eax == 0u) goto label_00071AEF;
    cpu->esi = cpu->ebx + 0x58u;
    cpu->edi = cpu->edx + 0x24u;
    cpu->ecx = 0x18u;
    lift_movs32(cpu, 1u);
    if (cpu->eax == 1u) goto label_00071AEF;
    if (*(uint32_t*)(cpu->edx + 4u) != 2u) goto label_0007146B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x194u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x194u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00071464;
    *(uint32_t*)(cpu->edx + 8u) = 1u;
    g_sfera_main_command_state_runtime.near_collision_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count)) + 1u;
    goto label_00071AFB;
    label_00071464:
    *(uint32_t*)(cpu->edx + 4u) = 1u;
    label_0007146B:
    lift_x87_push(cpu, 0.0);
    cpu->eax = 0u;
    g_sfera_texture_cache_runtime.active_index = cpu->eax;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->esp + 0x70u;
    lift_movs32(cpu, 1u);
    *(float*)(cpu->esp + 0x9Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x8Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esp + 0x100u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_bounds_runtime.minimum.x.f32;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4714A8u)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x4714A8u));
    cpu->eax = cpu->esp + 0xC0u;
    cpu->eax &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ebp = cpu->esp + 0x100u;
    *(uint32_t*)(cpu->esp + 0x14u) = 8u;
    label_000714D0:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0xB0u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esp + 0xB0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4714F2u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x4714F2u));
    cpu->ebp += 0xCu;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x14u), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x14u) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000714D0;
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esp + 0x104u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471510u)); sfera_sub_0044F870(cpu, LIFT_CODE_TOKEN_VA(0x471510u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x19Cu) <= (int32_t)cpu->eax) goto label_00071AF7;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_00071530:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A0u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x64u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x3Cu);
    cpu->ecx = cpu->edx + cpu->eax + 0x84u;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000718FA;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000718FA;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000718FA;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000718FA;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000718FA;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000718FA;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = cpu->edi + (cpu->edi * 4u);
    cpu->edi <<= 4u;
    cpu->edi += *(uint32_t*)(cpu->ecx + 0x1A4u);
    { uint64_t l=*(uint32_t*)(cpu->eax + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x38u) = 0u;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000718FA;
    label_00071600:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000718E1;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000718E1;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000718E1;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000718E1;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000718E1;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000718E1;
    cpu->esi = cpu->esp + 0x160u;
    cpu->ebp = cpu->edi + 0x18u;
    cpu->ebx = 3u;
    label_00071686:
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4716A2u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x4716A2u));
    cpu->ebp += 0xCu;
    cpu->esi += 0xCu;
    { uint64_t l=cpu->ebx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00071686;
    cpu->edx = cpu->esp + 0x178u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x170u;
    cpu->ecx = cpu->esp + 0x164u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4716C6u)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x4716C6u));
    if (cpu->eax == 0u) goto label_000718E1;
    if (*(uint32_t*)(cpu->esp + 0x64u) != cpu->ebx) goto label_00071706;
    cpu->eax = g_sfera_texture_cache_runtime.active_index;
    ++cpu->eax;
    g_sfera_texture_cache_runtime.active_index = cpu->eax;
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_points.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4716EBu)); sfera_sub_00451CF0(cpu, LIFT_CODE_TOKEN_VA(0x4716EBu));
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->eax = g_sfera_texture_cache_runtime.active_index;
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_points.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4716FFu)); sfera_sub_00451CF0(cpu, LIFT_CODE_TOKEN_VA(0x4716FFu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    label_00071706:
    cpu->edx = g_sfera_texture_cache_runtime.active_index;
    --cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_points.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471718u)); sfera_sub_00451CF0(cpu, LIFT_CODE_TOKEN_VA(0x471718u));
    ++*(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.cloud_records.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47172Au)); sfera_sub_00451D20(cpu, LIFT_CODE_TOKEN_VA(0x47172Au));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x160u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x164u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x168u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x16Cu);
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x170u);
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x178u);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x174u);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x17Cu);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x180u);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x4Cu));
    *(uint8_t*)(cpu->esi + 0x4Cu) = cpu->edx & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x4Du));
    *(uint8_t*)(cpu->esi + 0x4Du) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x3Cu);
    cpu->edx = cpu->esi + 0x3Cu;
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x40u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x44u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4717AFu)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x4717AFu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x16Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x168u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000717DD;
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000717F0;
    label_000717DD:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000717EE;
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000717F0;
    label_000717EE:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000717F0:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x170u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00071808;
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007181B;
    label_00071808:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00071819;
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007181B;
    label_00071819:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007181B:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x174u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00071833;
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00071846;
    label_00071833:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00071844;
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00071846;
    label_00071844:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00071846:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x178u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007185C;
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007186F;
    label_0007185C:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007186D;
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007186F;
    label_0007186D:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007186F:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x17Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00071887;
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007189A;
    label_00071887:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00071898;
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007189A;
    label_00071898:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007189A:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x180u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000718B2;
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000718C5;
    label_000718B2:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000718C3;
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000718C5;
    label_000718C3:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000718C5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)0x7D0u) goto label_00071E0E;
    *(uint32_t*)(cpu->esp + 0x64u) = 1u;
    label_000718E1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->edi += 0x50u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edx + 4u)) goto label_00071600;
    label_000718FA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx + 0x19Cu)) goto label_00071530;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) == 0u) goto label_00071AF7;
    cpu->esi = 0u;
    if ((int32_t)g_sfera_texture_cache_runtime.active_index <= (int32_t)cpu->esi) goto label_0007194A;
    label_00071930:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.near_result_handles;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47193Bu)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x47193Bu));
    ++cpu->esi;
    *(uint32_t*)(cpu->eax) = 0u;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_texture_cache_runtime.active_index) goto label_00071930;
    label_0007194A:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) <= (int32_t)0u) goto label_00071ADD;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->edx += 0x84u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    (void)cpu;
    label_00071970:
    lift_x87_push(cpu, (double)2.0f);
    cpu->esi = 0u;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)g_sfera_texture_cache_runtime.active_index <= (int32_t)cpu->esi) goto label_00071A91;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    label_00071990:
    if ((int32_t)cpu->esi >= 0) goto label_0007199E;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7199Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7199Eu));
    label_0007199E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.near_result_handles.capacity) goto label_000719B2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x719B2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x719B2u));
    label_000719B2:
    cpu->ecx = g_sfera_collision_runtime.near_result_handles.data;
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if ((int32_t)cpu->esi >= 0) goto label_000719C9;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x719C9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x719C9u));
    label_000719C9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.clip_points.capacity) goto label_000719DD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x719DDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x719DDu));
    label_000719DD:
    cpu->edx = g_sfera_scene_array_runtime.clip_points.data;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ebx == *(uint32_t*)(cpu->edx + cpu->eax + 4u)) goto label_00071A7F;
    if ((int32_t)cpu->esi >= 0) goto label_000719FF;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x719FFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x719FFu));
    label_000719FF:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.clip_points.capacity) goto label_00071A13;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71A13u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71A13u));
    label_00071A13:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = g_sfera_scene_array_runtime.clip_points.data;
    cpu->edi = *(uint32_t*)(cpu->edx + cpu->ecx + 8u);
    { uint64_t l=cpu->edi, r=cpu->ebx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00071A2F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71A2Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71A2Fu));
    label_00071A2F:
    { uint64_t l=cpu->edi, r=g_sfera_scene_array_runtime.cloud_records.capacity, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00071A43;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71A43u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71A43u));
    label_00071A43:
    cpu->ecx = cpu->edi + (cpu->edi * 4u);
    cpu->ecx <<= 4u;
    cpu->ecx += g_sfera_scene_array_runtime.cloud_records.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x40u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00071A7D;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebp = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ecx;
    goto label_00071A7F;
    label_00071A7D:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00071A7F:
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_texture_cache_runtime.active_index) goto label_00071990;
    label_00071A91:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x6Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = 0x14u;
    lift_movs32(cpu, 1u);
    if ((int32_t)cpu->ebp >= 0) goto label_00071AAE;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71AAEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71AAEu));
    label_00071AAE:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_collision_runtime.near_result_handles.capacity) goto label_00071AC2;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71AC2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71AC2u));
    label_00071AC2:
    cpu->eax = g_sfera_collision_runtime.near_result_handles.data;
    ++*(uint32_t*)(cpu->eax + (cpu->ebp * 4u));
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x50u) + (uint64_t)(0u);
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x38u), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x38u) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00071970;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebp;
    label_00071ADD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->ecx + 0x27184u) = cpu->eax;
    label_00071AEF:
    g_sfera_main_command_state_runtime.near_collision_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count)) + 1u;
    goto label_00071AFB;
    label_00071AF7:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    label_00071AFB:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_patch_lookup_runtime.active_count) goto label_00071185;
    cpu->edi = 0u;
    label_00071B12:
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count;
    if ((int32_t)cpu->esi >= (int32_t)cpu->edi) goto label_00071B26;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71B26u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71B26u));
    label_00071B26:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.world_cell_records.capacity) goto label_00071B3A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71B3Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71B3Au));
    label_00071B3A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x27188u);
    cpu->esi += g_sfera_scene_array_runtime.world_cell_records.data;
    *(uint32_t*)(cpu->esi) = 1u;
    cpu->eax = *(uint32_t*)(cpu->edx + 0x6Cu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = 2u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 4u) != cpu->eax) goto label_00071B6E;
    *(uint32_t*)(cpu->esi + 4u) = 1u;
    label_00071B6E:
    *(uint32_t*)(cpu->esi + 0x27184u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if ((int32_t)g_sfera_scene_build_runtime.object_count <= (int32_t)cpu->edi) goto label_00071DC8;
    label_00071B84:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)cpu->esi >= 0) goto label_00071B96;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71B96u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71B96u));
    label_00071B96:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_sort_keys.capacity) goto label_00071BAA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71BAAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71BAAu));
    label_00071BAA:
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_keys.data;
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    if ((int32_t)cpu->esi >= 0) goto label_00071BC5;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71BC5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71BC5u));
    label_00071BC5:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_sort_indices.capacity) goto label_00071BD9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71BD9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71BD9u));
    label_00071BD9:
    cpu->edx = g_sfera_scene_array_runtime.object_sort_indices.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_00071BF4;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71BF4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71BF4u));
    label_00071BF4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_draw_indices.capacity) goto label_00071C08;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71C08u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71C08u));
    label_00071C08:
    cpu->ecx = g_sfera_scene_array_runtime.object_draw_indices.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + (cpu->esi * 4u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->esi >= 0) goto label_00071C23;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71C23u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71C23u));
    label_00071C23:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.candidate_handles.capacity) goto label_00071C37;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71C37u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71C37u));
    label_00071C37:
    { uint64_t l=*(uint32_t*)(cpu->edi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = g_sfera_collision_runtime.candidate_handles.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + (cpu->esi * 4u)));
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00071DB3;
    cpu->esi = 0u;
    label_00071C60:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->eax = cpu->esi + cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->edx = *(uint16_t*)(cpu->eax);
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->edx * 8u));
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    cpu->edx = *(uint16_t*)(cpu->eax + 2u);
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint16_t*)(cpu->eax + 4u);
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->edx * 8u));
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esp + 0x4Cu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x64u));
    cpu->ecx = cpu->esp + 0x5Cu;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebp;
    *(float*)(cpu->esp + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471D23u)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x471D23u));
    if (cpu->eax == 0u) goto label_00071D9A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x27184u);
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->ecx += cpu->ecx;
    cpu->eax = cpu->edx + (cpu->ecx * 8u) + 0x84u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edi = *(uint32_t*)(cpu->esi + cpu->ecx + 0x10u);
    cpu->ecx = cpu->esi + cpu->ecx + 0x10u;
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->ecx;
    *(uint16_t*)(cpu->eax + 0x4Cu) = 0u;
    ++*(uint32_t*)(cpu->edx + 0x27184u);
    label_00071D9A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    ++cpu->eax;
    cpu->esi += 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edx + 8u)) goto label_00071C60;
    label_00071DB3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_build_runtime.object_count) goto label_00071B84;
    label_00071DC8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (*(uint32_t*)(cpu->eax + 0x27184u) == 0u) goto label_00071DF5;
    cpu->ecx = cpu->eax + 0x84u;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x27184u);
    --cpu->edx;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471DEFu)); sfera_sub_00455580(cpu, LIFT_CODE_TOKEN_VA(0x471DEFu));
    g_sfera_main_command_state_runtime.near_collision_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count)) + 1u;
    label_00071DF5:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x178u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00071E0E:
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count) = 0u;
    goto label_00071DF5;
    label_00071E1A:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00071E27:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00071E27;
    cpu->ecx = 8u;
    cpu->esi = (uintptr_t)"GreatherNearCldInfo: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471E42u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x471E42u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x178u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00471E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x184u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xB4u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471E9Cu)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x471E9Cu));
    cpu->ebp = 0u;
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebp) goto label_00071EAC;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71EACu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x71EACu));
    label_00071EAC:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00071EC0;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x71EC0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x71EC0u));
    label_00071EC0:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x471ED7u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x471ED7u));
    lift_x87_push(cpu, (double)1000.0f);
    cpu->esi += 0x3Cu;
    g_sfera_recovered_static_runtime.clip_depth = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (cpu->ebx > 4u) goto label_00071F4D;
    switch (cpu->ebx) {
        case 0u: case 1u: goto label_00071F47;
        case 2u: goto label_00071EFC;
        case 3u: goto label_00071F33;
        case 4u: goto label_00071F3F;
        case 5u: goto label_0007307A;
        case 6u: goto label_00072418;
        case 7u: goto label_000730DC;
        case 8u: goto label_000723E8;
        case 9u: goto label_00072C0D;
        case 10u: case 11u: goto label_00073105;
        case 12u: goto label_0007310D;
        case 13u: goto label_00072828;
        case 14u: goto label_0007304A;
        default: lift_trap(cpu, 0x471EF5u, "resolved jump-table index out of range"); return;
    }
label_00071EFC: ;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)-1.0f);
    g_sfera_view_spatial_runtime.view_axis.x.u32 = cpu->edx;
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    g_sfera_view_spatial_runtime.view_axis.y.u32 = cpu->eax;
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    g_sfera_view_spatial_runtime.view_axis.z.u32 = cpu->ecx;
    g_sfera_recovered_static_runtime.view_direction_state = cpu->ebp;
    goto label_00071F4F;
    label_00071F33:
    g_sfera_recovered_static_runtime.scene_mode = 6u;
    goto label_00071F4D;
    label_00071F3F:
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebp;
    goto label_00071F4D;
    label_00071F47:
    g_sfera_window_runtime.clip_vector_count = cpu->ebp;
    label_00071F4D:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00071F4F:
    if (*(uint32_t*)(cpu->esp + 0x198u) == cpu->ebp) goto label_00071FC4;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.minimum.x.f32));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x40u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00071FC4;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.minimum.y.f32));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x44u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00071FC4;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.minimum.z.f32));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x48u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00071FC4;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.maximum.x.f32));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x4Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00071FC4;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.maximum.y.f32));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00071FC4;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_spatial_bounds_runtime.maximum.z.f32));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x54u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00072043;
    label_00071FC4:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x40u));
    lift_x87_push(cpu, (double)1.2000000476837158f); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x48u));
    g_sfera_spatial_bounds_runtime.minimum.x.u32 = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[1u]);
    g_sfera_spatial_bounds_runtime.minimum.y.u32 = cpu->eax;
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    g_sfera_spatial_bounds_runtime.minimum.z.u32 = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x4Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x54u)));
    g_sfera_spatial_bounds_runtime.maximum.x.u32 = cpu->edx;
    g_sfera_spatial_bounds_runtime.maximum.y.u32 = cpu->eax;
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    g_sfera_spatial_bounds_runtime.maximum.z.u32 = cpu->ecx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x72043u)); sfera_sub_004710A0(cpu, LIFT_CODE_TOKEN_RVA(0x72043u));
    label_00072043:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x40u));
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebp;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x44u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x48u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x4Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x54u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count <= (int32_t)cpu->ebp) goto label_00073138;
    label_00072090:
    if ((int32_t)cpu->ebp >= 0) goto label_0007209E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7209Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7209Eu));
    label_0007209E:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_scene_array_runtime.world_cell_records.capacity) goto label_000720B2;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x720B2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x720B2u));
    label_000720B2:
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x27188u);
    cpu->ebp += g_sfera_scene_array_runtime.world_cell_records.data;
    { uint64_t l=*(uint32_t*)(cpu->ebp), r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00072154;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007301F;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007301F;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007301F;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007301F;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007301F;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x20u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007301F;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00072154:
    if (cpu->ebx == 3u) goto label_000721A5;
    if (cpu->ebx == 4u) goto label_000721A5;
    cpu->esi = 0u;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state <= (int32_t)cpu->esi) goto label_000721A5;
    label_00072168:
    if ((int32_t)cpu->esi >= 0) goto label_00072176;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x72176u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x72176u));
    label_00072176:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.clip_indices.capacity) goto label_0007218A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7218Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7218Au));
    label_0007218A:
    cpu->edx = g_sfera_scene_array_runtime.clip_indices.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->eax == *(uint32_t*)(cpu->ebp)) goto label_0007301F;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) goto label_00072168;
    label_000721A5:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x10u), r=3u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000721BB;
    if (cpu->edi != 2u) goto label_0007301F;
    label_000721BB:
    cpu->esi = *(uint32_t*)(cpu->ebp);
    if ((int32_t)cpu->esi >= 0) goto label_000721CC;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x721CCu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x721CCu));
    label_000721CC:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000721E0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x721E0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x721E0u));
    label_000721E0:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4721F8u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4721F8u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (cpu->ebx != 0u) goto label_0007246B;
    if (cpu->edi != 0u) goto label_00072253;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 4u) goto label_000730D7;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0007222E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7222Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7222Eu));
    label_0007222E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.clip_indices.capacity) goto label_00072242;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x72242u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x72242u));
    label_00072242:
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->ecx = g_sfera_scene_array_runtime.clip_indices.data;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->eax;
    goto label_0007301F;
    label_00072253:
    if (cpu->edi != 1u) goto label_000722D6;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x10Cu;
    cpu->ecx += 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47226Bu)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x47226Bu));
    cpu->edx = cpu->ebp + 0x24u;
    cpu->ecx = cpu->esp + 0x10Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47227Au)); sfera_sub_0045E660(cpu, LIFT_CODE_TOKEN_VA(0x47227Au));
    if (cpu->eax == 0u) goto label_0007301F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax == cpu->edi) goto label_0007306A;
    { uint64_t l=cpu->eax, r=4u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00072291:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000730D7;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_000722B2;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x722B2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x722B2u));
    label_000722B2:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.clip_indices.capacity) goto label_000722C6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x722C6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x722C6u));
    label_000722C6:
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = g_sfera_scene_array_runtime.clip_indices.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = cpu->edx;
    goto label_0007301F;
    label_000722D6:
    if (cpu->edi != 2u) goto label_0007301F;
    cpu->eax = 0u;
    cpu->ecx = cpu->edi + 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x10u) != cpu->edi) goto label_000722F4;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x27184u);
    --cpu->eax;
    cpu->ecx |= 0xFFFFFFFFu;
    label_000722F4:
    cpu->ebx = 0u;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x27184u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0007244E;
    cpu->edi = cpu->ecx + (cpu->ecx * 4u);
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->edi <<= 4u;
    cpu->ecx += cpu->ecx;
    cpu->esi = cpu->ebp + (cpu->ecx * 8u) + 0x88u;
    label_00072314:
    if (*(uint32_t*)(cpu->esp + 0x10u) != 3u) goto label_00072336;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x48u));
    cpu->edx = cpu->eax & 0xFFu;
    if ((int32_t)cpu->edx >= (int32_t)g_sfera_recovered_static_runtime.scene_mode) goto label_0007243F;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00072340;
    goto label_0007243F;
    label_00072336:
    if (*(uint8_t*)(cpu->esi + 0x48u) > 0u) goto label_0007243F;
    label_00072340:
    if (*(uint32_t*)(cpu->ebp) == 1u) goto label_000723C5;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xFFFFFFFCu));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007243F;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007243F;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007243F;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007243F;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007243F;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007243F;
    label_000723C5:
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x20u;
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4723D4u)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x4723D4u));
    if (cpu->eax == 0u) goto label_0007243F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax > 4u) goto label_0007243F;
    switch (cpu->eax) {
        case 0u: goto label_0007307A;
        case 1u: goto label_00072418;
        case 2u: goto label_000730DC;
        case 3u: goto label_000723E8;
        case 4u: goto label_00072C0D;
        case 5u: case 6u: goto label_00073105;
        case 7u: goto label_0007310D;
        case 8u: goto label_00072828;
        case 9u: goto label_0007304A;
        default: lift_trap(cpu, 0x4723E1u, "resolved jump-table index out of range"); return;
    }
    label_000723E8:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xB4u);
    g_sfera_recovered_static_runtime.scene_mode = cpu->ecx;
    if (cpu->edx != g_sfera_world_objects.controlled_object_handle) goto label_0007243F;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47240Fu)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x47240Fu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472416u)); sfera_sub_00461DD0(cpu, LIFT_CODE_TOKEN_VA(0x472416u));
    goto label_0007243F;
    label_00072418:
    cpu->eax = g_sfera_window_runtime.clip_vector_count;
    lift_push32(cpu, cpu->eax);
    ++cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.data;
    g_sfera_window_runtime.clip_vector_count = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47242Eu)); sfera_sub_00451CF0(cpu, LIFT_CODE_TOKEN_VA(0x47242Eu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x38u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x3Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x40u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    label_0007243F:
    ++cpu->ebx;
    cpu->esi += cpu->edi;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->ebp + 0x27184u)) goto label_00072314;
    label_0007244E:
    if (*(uint32_t*)(cpu->esp + 0x10u) != 1u) goto label_0007301F;
    if ((int32_t)g_sfera_window_runtime.clip_vector_count > (int32_t)0u) goto label_000730D7;
    goto label_0007301F;
    label_0007246B:
    if (cpu->ebx != 1u) goto label_0007288A;
    if (cpu->edi != 0u) goto label_000724AC;
    cpu->ecx = cpu->ebp + 0xCu;
    cpu->edx = cpu->esp + 0x10Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472487u)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x472487u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx += 0x58u;
    cpu->ecx = cpu->esp + 0x10Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47249Au)); sfera_sub_0045E660(cpu, LIFT_CODE_TOKEN_VA(0x47249Au));
    if (cpu->eax == 0u) goto label_0007301F;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x10u), r=4u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    goto label_00072291;
    label_000724AC:
    if (cpu->edi != 1u) goto label_00072513;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->ebp + 0x24u;
    cpu->ecx += 0x58u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4724C0u)); sfera_sub_0045E660(cpu, LIFT_CODE_TOKEN_VA(0x4724C0u));
    if (cpu->eax == 0u) goto label_0007301F;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 4u) goto label_000730D7;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_000724EE;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x724EEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x724EEu));
    label_000724EE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.clip_indices.capacity) goto label_00072502;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x72502u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x72502u));
    label_00072502:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    cpu->edx = g_sfera_scene_array_runtime.clip_indices.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->ecx;
    goto label_0007301F;
    label_00072513:
    if (cpu->edi != 2u) goto label_0007301F;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->edi + 0xFFFFFFFFu;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u];
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u];
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x188u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x190u));
    cpu->eax = 0u;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (*(uint32_t*)(cpu->esp + 0x10u) != cpu->edi) goto label_000725A9;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x27184u);
    --cpu->eax;
    cpu->ecx |= 0xFFFFFFFFu;
    label_000725A9:
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x27184u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0007284F;
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->ecx <<= 4u;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax <<= 4u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    cpu->ebx = cpu->eax + cpu->ebp + 0x88u;
    label_000725D5:
    if (*(uint32_t*)(cpu->esp + 0x10u) != 3u) goto label_000725F7;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x48u));
    cpu->ecx = cpu->eax & 0xFFu;
    if ((int32_t)cpu->ecx >= (int32_t)g_sfera_recovered_static_runtime.scene_mode) goto label_00072832;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00072601;
    goto label_00072832;
    label_000725F7:
    if (*(uint8_t*)(cpu->ebx + 0x48u) > 0u) goto label_00072832;
    label_00072601:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->edx) == 1u) goto label_00072681;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0xFFFFFFFCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072832;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072832;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072832;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072832;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072832;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072832;
    label_00072681:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0xA8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x24u);
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x30u);
    *(uint32_t*)(cpu->esp + 0xACu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x28u);
    *(uint32_t*)(cpu->esp + 0xA4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x9Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->edi = cpu->esp + 0xCCu;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0xA4u;
    cpu->ecx = cpu->esp + 0xBCu;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47270Au)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x47270Au));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = cpu->esp + 0xCCu;
    cpu->edi &= 0xFFFFFFF0u;
    cpu->ebp += 0x148u;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebp;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0xA4u;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472741u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x472741u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = cpu->esp + 0xCCu;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x94u;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472770u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x472770u));
    cpu->edi = cpu->esp + 0xCCu;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebp;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x94u;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47279Du)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x47279Du));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = cpu->esp + 0xCCu;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4727CCu)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x4727CCu));
    cpu->edi = cpu->esp + 0xCCu;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebp;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4727F9u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x4727F9u));
    cpu->eax = cpu->esp + 0x84u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x98u;
    cpu->ecx = cpu->esp + 0xA8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472814u)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x472814u));
    if (cpu->eax == 0u) goto label_00072832;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax > 4u) goto label_00072832;
    switch (cpu->eax) {
        case 0u: case 1u: goto label_00073105;
        case 2u: goto label_0007310D;
        case 3u: goto label_00072828;
        case 4u: goto label_0007304A;
        default: lift_trap(cpu, 0x472821u, "resolved jump-table index out of range"); return;
    }
    label_00072828:
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0x48u);
    g_sfera_recovered_static_runtime.scene_mode = cpu->ecx;
    label_00072832:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x48u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edx + 0x27184u)) goto label_000725D5;
    label_0007284F:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    goto label_00073019;
    label_0007288A:
    if (cpu->ebx != 2u) goto label_0007301F;
    if (cpu->edi != 0u) goto label_00072C2D;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32));
    cpu->ecx = cpu->ebp + 0xCu;
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esp + 0x10Cu;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32));
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x10u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x14u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x18u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x1Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x20u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47291Bu)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x47291Bu));
    cpu->eax = cpu->esp + 0xCCu;
    cpu->eax &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->ebx = cpu->esp + 0x10Cu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 8u;
    label_00072940:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472964u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x472964u));
    cpu->ebx += 0xCu;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x1Cu), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x1Cu) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00072940;
    cpu->ecx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x58u;
    cpu->ecx = cpu->esp + 0x110u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472982u)); sfera_sub_0044F870(cpu, LIFT_CODE_TOKEN_VA(0x472982u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x19Cu) <= (int32_t)cpu->ecx) goto label_00072BC7;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x68u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x64u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u));
    label_000729B4:
    cpu->edi = *(uint32_t*)(cpu->eax + 0x1A0u);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + cpu->eax + 0x84u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu);
    cpu->ecx = cpu->edx + cpu->eax + 0x84u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072B9D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[4u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072B9D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072B9D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[5u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072B9D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072B9D;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[6u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072B9D;
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = cpu->esi + (cpu->esi * 4u);
    cpu->esi <<= 4u;
    cpu->esi += *(uint32_t*)(cpu->ecx + 0x1A4u);
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edi + 4u) <= (int32_t)cpu->ebx) goto label_00072B9D;
    label_00072A52:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072B90;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[4u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072B90;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072B90;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[5u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072B90;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072B90;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[6u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072B90;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->fpu[5u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x16Cu) = cpu->edx;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x174u) = cpu->ecx;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x170u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->esp + 0x178u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    *(uint32_t*)(cpu->esp + 0x180u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x38u);
    *(uint32_t*)(cpu->esp + 0x17Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0x184u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x16Cu;
    *(uint32_t*)(cpu->esp + 0x188u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472B27u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x472B27u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x178u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472B37u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x472B37u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x184u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472B47u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x472B47u));
    cpu->edx = cpu->esp + 0x184u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x17Cu;
    cpu->ecx = cpu->esp + 0x170u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472B62u)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x472B62u));
    if (cpu->eax != 0u) goto label_00072C02;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x68u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x64u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u));
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_00072B90:
    ++cpu->ebx;
    cpu->esi += 0x50u;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00072A52;
    label_00072B9D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->eax + 0x19Cu)) goto label_000729B4;
    cpu->fpu[5u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00072BC7:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    goto label_00073019;
    label_00072C02:
    if (*(uint32_t*)(cpu->esp + 0x10u) != 4u) goto label_000730D7;
    label_00072C0D:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state;
    lift_push32(cpu, cpu->eax);
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->eax;
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472C26u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x472C26u));
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    goto label_0007301F;
    label_00072C2D:
    if (cpu->edi != 1u) goto label_0007301F;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0xA0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi += 0x3Cu;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32));
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->esi;
    *(float*)(cpu->esp + 0xB8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = cpu->esp + 0x10Cu;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32));
    *(uint32_t*)(cpu->esp + 0x1Cu) = 8u;
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32));
    *(float*)(cpu->esp + 0x80u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32));
    *(float*)(cpu->esp + 0xB0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32));
    *(float*)(cpu->esp + 0x90u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u];
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u];
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x188u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x190u));
    cpu->eax = cpu->esp + 0xCCu;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->ebp += 0x24u;
    label_00072CE4:
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472D19u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x472D19u));
    cpu->ebp += 0xCu;
    cpu->ebx += 0xCu;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x1Cu), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x1Cu) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00072CE4;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x70u;
    cpu->ecx = cpu->esp + 0x110u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472D3Au)); sfera_sub_0044F870(cpu, LIFT_CODE_TOKEN_VA(0x472D3Au));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x19Cu) <= (int32_t)cpu->ecx) goto label_00072FD4;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x74u));
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x70u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x6Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    goto label_00072D72;
    label_00072D6E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    label_00072D72:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1A0u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + cpu->eax + 0x84u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu);
    cpu->edx = cpu->edx + cpu->eax + 0x84u;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072FAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[4u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072FAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072FAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[5u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072FAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072FAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[6u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072FAA;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax <<= 4u;
    cpu->eax += *(uint32_t*)(cpu->edx + 0x1A4u);
    { uint64_t l=*(uint32_t*)(cpu->ecx + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00072FAA;
    goto label_00072E25;
    label_00072E21:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_00072E25:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072F8F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[4u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072F8F;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072F8F;
    cpu->edx = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[5u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072F8F;
    cpu->eax = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00072F8F;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[6u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00072F8F;
    cpu->fpu[5u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->esp + 0xCCu;
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax &= 0xFFFFFFF0u;
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->esp + 0xCCu;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = cpu->ecx;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    cpu->ebp = cpu->esp + 0x16Cu;
    cpu->ebx += 0x18u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 3u;
    label_00072ED0:
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->ebp) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472EECu)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x472EECu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472F10u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x472F10u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi += 0x148u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472F3Au)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x472F3Au));
    cpu->ebx += 0xCu;
    cpu->ebp += 0xCu;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x1Cu), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x1Cu) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00072ED0;
    cpu->edx = cpu->esp + 0x184u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x17Cu;
    cpu->ecx = cpu->esp + 0x170u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x472F61u)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x472F61u));
    if (cpu->eax != 0u) goto label_0007303F;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x74u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x70u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x6Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_00072F8F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x50u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx + 4u)) goto label_00072E21;
    label_00072FAA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edx + 0x19Cu)) goto label_00072D6E;
    cpu->fpu[5u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00072FD4:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xA0u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xB8u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x7Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x80u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xB0u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x90u));
    label_00073019:
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007301F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.near_collision_count) goto label_00073138;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    goto label_00072090;
    label_0007303F:
    if (*(uint32_t*)(cpu->esp + 0x10u) != 4u) goto label_00073105;
    label_0007304A:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state;
    lift_push32(cpu, cpu->eax);
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473066u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x473066u));
    *(uint32_t*)(cpu->eax) = cpu->esi;
    goto label_0007301F;
    label_0007306A:
    cpu->ecx = cpu->ebp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473072u)); sfera_sub_0045D840(cpu, LIFT_CODE_TOKEN_VA(0x473072u));
    cpu->eax = *(uint32_t*)(cpu->ebp);
    goto label_0007313A;
    label_0007307A:
    if (*(uint32_t*)(cpu->ebp) == 1u) goto label_00073096;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xA4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x8Cu)));
    g_sfera_recovered_static_runtime.clip_depth = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00073096:
    if ((int32_t)g_sfera_scene_array_runtime.clip_vectors.capacity > (int32_t)0u) goto label_000730AB;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x730ABu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x730ABu));
    label_000730AB:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x38u);
    cpu->edx = g_sfera_scene_array_runtime.clip_vectors.data;
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3Cu);
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = g_sfera_scene_array_runtime.clip_vectors.data;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    g_sfera_window_runtime.clip_vector_count = 1u;
    label_000730D7:
    cpu->eax = *(uint32_t*)(cpu->ebp);
    goto label_0007313A;
    label_000730DC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x38u);
    g_sfera_view_spatial_runtime.view_axis.x.u32 = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x3Cu);
    g_sfera_view_spatial_runtime.view_axis.y.u32 = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    g_sfera_view_spatial_runtime.view_axis.z.u32 = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x49u);
    g_sfera_recovered_static_runtime.view_direction_state = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    goto label_0007313A;
    label_00073105:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    goto label_0007313A;
    label_0007310D:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x38u);
    g_sfera_view_spatial_runtime.view_axis.x.u32 = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    g_sfera_view_spatial_runtime.view_axis.y.u32 = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    g_sfera_view_spatial_runtime.view_axis.z.u32 = cpu->edx;
    cpu->eax = *(uint8_t*)(cpu->ebx + 0x49u);
    g_sfera_recovered_static_runtime.view_direction_state = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    goto label_0007313A;
    label_00073138:
    cpu->eax = 0u;
    label_0007313A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x184u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004731A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4731B2u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4731B2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004731C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCCu;
    { uint64_t l=(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000733D1;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 0u) goto label_000733D1;
    lift_x87_push(cpu, (double)1000000.0f);
    *(uint32_t*)(cpu->esp + 0x60u) = 0xFFFFFFFFu;
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473211u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x473211u));
    cpu->ecx = cpu->esp + 0x80u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x80u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[3u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[2u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x84u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->eax = cpu->esp;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z));
    cpu->edx = 0u;
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473380u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x473380u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000733D9;
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, cpu->fpu[3u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000733D9;
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000733DB;
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000733D1:
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00073A11;
    label_000733D9:
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000733DB:
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[0].z));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.800000011920929);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], 50.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007340C;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)50.0f);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    label_0007340C:
    if (cpu->esi == 0u) goto label_00073418;
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_00073418:
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->edx = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].x);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].y);
    cpu->ecx = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].z);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_x87_push(cpu, cpu->fpu[2u]);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 1u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    lift_x87_push(cpu, 0.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.10000000149011612);
    *(float*)(cpu->esp + 0x78u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_000734B4;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4734B0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x4734B0u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    label_000734B4:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esp -= 0x10u;
    cpu->ecx = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4734DCu)); sfera_sub_0046DD80(cpu, LIFT_CODE_TOKEN_VA(0x4734DCu));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->esi;
    if ((int32_t)g_sfera_landscape_patch_lookup_runtime.active_count <= (int32_t)cpu->esi) goto label_00073A03;
    goto label_000734F4;
    label_000734F0:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x5Cu);
    label_000734F4:
    if ((int32_t)cpu->esi >= 0) goto label_00073502;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73502u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x73502u));
    label_00073502:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_character_index_map.capacity) goto label_00073516;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_character_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73516u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x73516u));
    label_00073516:
    cpu->ecx = g_sfera_character_index_map.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    if ((int32_t)cpu->esi >= 0) goto label_00073531;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73531u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x73531u));
    label_00073531:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00073545;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73545u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x73545u));
    label_00073545:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47355Du)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47355Du));
    cpu->ebp = cpu->eax;
    cpu->ebx = cpu->edi + 0x3Cu;
    if (cpu->esi == 1u) goto label_000739EA;
    if (cpu->esi == g_sfera_world_objects.controlled_object_handle) goto label_000739EA;
    if (*(uint8_t*)(cpu->edi + 0x139u) == 0u) goto label_000739EA;
    if (*(uint8_t*)(cpu->edi + 0x138u) != 1u) goto label_0007359A;
    if (*(uint8_t*)(cpu->edi + 0x141u) == 0u) goto label_000739EA;
    label_0007359A:
    if (*(uint32_t*)(cpu->ebp + 0x6Cu) == 3u) goto label_000739EA;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4735ABu)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x4735ABu));
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x6Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x74u);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00073634;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x40u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x44u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x48u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x4Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x50u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x54u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00073778;
    label_00073634:
    lift_x87_push(cpu, 0.0);
    cpu->edi = cpu->esp + 0x98u;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = cpu->fpu[0u];
    cpu->edi &= 0xFFFFFFF0u;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x188u));
    cpu->esi = cpu->ebx;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esp + 0x50u;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x18Cu));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x190u));
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473696u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x473696u));
    cpu->edi = cpu->esp + 0x98u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    cpu->esi = cpu->ebp + 0x148u;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x50u;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4736C4u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x4736C4u));
    cpu->edi = cpu->esp + 0x98u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x44u;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4736EEu)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x4736EEu));
    cpu->edi = cpu->esp + 0x98u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebp + 0x148u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x44u;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47371Cu)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x47371Cu));
    cpu->edi = cpu->esp + 0x98u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x64u;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473746u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x473746u));
    cpu->edi = cpu->esp + 0x98u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebp + 0x148u;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x64u;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473774u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x473774u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    label_00073778:
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47378Au)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x47378Au));
    if (cpu->eax == 0u) goto label_000739EA;
    lift_x87_push(cpu, (double)1000000.0f);
    cpu->edi = 0u;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count <= (int32_t)cpu->edi) goto label_00073838;
    label_000737B0:
    lift_x87_push(cpu, (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x50u)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x54u)));
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x58u)));
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473806u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x473806u));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00073829;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007382B;
    label_00073829:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007382B:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count) goto label_000737B0;
    label_00073838:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000739E8;
    if (*(uint32_t*)(cpu->ebp + 0x6Cu) == 2u) goto label_00073860;
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->esi;
    goto label_000739EA;
    label_00073860:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = cpu->esp + 0x98u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x50u;
    cpu->ecx = cpu->esp + 0x88u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4738BCu)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x4738BCu));
    cpu->edi = cpu->esp + 0x98u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x44u;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4738E6u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x4738E6u));
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x19Cu) <= (int32_t)cpu->ebx) goto label_000739EA;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    label_00073900:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1A0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->edx + 8u);
    { uint64_t v=cpu->ecx; lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000739D4;
    cpu->esi = cpu->eax + (cpu->eax * 4u);
    cpu->esi <<= 4u;
    cpu->edi = cpu->ecx;
    label_00073922:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1A4u);
    { uint64_t l=*(uint8_t*)(cpu->esi + cpu->ecx + 0x4Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = cpu->esi + cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000739CA;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473949u)); sfera_sub_00455D00(cpu, LIFT_CODE_TOKEN_VA(0x473949u));
    if (cpu->eax != 2u) goto label_000739CA;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x50u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x54u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x58u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47399Du)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x47399Du));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000739C8;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->eax;
    goto label_000739CA;
    label_000739C8:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000739CA:
    cpu->esi += 0x50u;
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00073922;
    label_000739D4:
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->ebp + 0x19Cu)) goto label_00073900;
    goto label_000739EA;
    label_000739E8:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000739EA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x5Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_landscape_patch_lookup_runtime.active_count) goto label_000734F0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x70u);
    label_00073A03:
    if (cpu->ebx == 0u) goto label_00073A0D;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(float*)(cpu->ebx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00073A0D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x60u);
    label_00073A11:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00473A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x418u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    if ((int32_t)cpu->ebx >= 0) goto label_00073A56;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73A56u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x73A56u));
    label_00073A56:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00073A6A;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73A6Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x73A6Au));
    label_00073A6A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    if (cpu->esi != 0u) goto label_00073BA8;
    label_00073A7A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473A8Bu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x473A8Bu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x430u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x42Cu));
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x434u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473ABFu)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x473ABFu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->edi + 0x198u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473AD2u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x473AD2u));
    cpu->edi = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x42Cu)));
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(float*)(cpu->esp + 0x42Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x430u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x430u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x434u)));
    *(float*)(cpu->esp + 0x434u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->edi <= 0) goto label_00073B8B;
    label_00073B23:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->ebp = *(uint32_t*)(cpu->esi + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x42Cu)));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_push32(cpu, 1u);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x434u)));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x438u)));
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x43Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473B7Au)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x473B7Au));
    if (cpu->eax != 0u) goto label_00073BF4;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00073B23;
    label_00073B8B:
    cpu->eax = 0u;
    label_00073B8D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00073BA8:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00073A7A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473BC4u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x473BC4u));
    if (cpu->eax != 0u) goto label_00073BCD;
    cpu->eax = (uintptr_t)"<none>";
    label_00073BCD:
    lift_push32(cpu, 0x3420u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x473BE2u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73BF4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x73BF4u));
    label_00073BF4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 2u;
    goto label_00073B8D;
}
__declspec(noinline) void sfera_sub_00473C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x42Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((int32_t)cpu->edi >= 0) goto label_00073C4E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73C4Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x73C4Eu));
    label_00073C4E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00073C62;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73C62u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x73C62u));
    label_00073C62:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->esi != 0u) goto label_00073F28;
    label_00073C72:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x288u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x27Cu)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x280u)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x290u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x284u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x444u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->ebx != 0u) goto label_00073CD3;
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00073CD3:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x440u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473CFEu)); sfera_sub_00473A30(cpu, LIFT_CODE_TOKEN_VA(0x473CFEu));
    if (cpu->eax == 0u) goto label_000740FF;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x10u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, 0.0);
    cpu->ebx = 1u;
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x290u) = cpu->fpu[0u];
    *(uint8_t*)(cpu->esi + 0x2A0u) = cpu->ebx & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00073D2C;
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u];
    label_00073D2C:
    *(float*)(cpu->esi + 0x294u) = cpu->fpu[0u];
    *(uint8_t*)(cpu->esi + 0x2A1u) = cpu->ebx & 0xFFu;
    if ((int32_t)g_sfera_scene_array_runtime.clip_vectors.capacity > (int32_t)0u) goto label_00073D51;
    cpu->edx = 0u;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473D4Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x473D4Fu));
    lift_x87_push(cpu, 0.0);
    label_00073D51:
    cpu->eax = g_sfera_scene_array_runtime.clip_vectors.data;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0x2ACu) = cpu->eax;
    lift_x87_push(cpu, (double)g_sfera_recovered_static_runtime.clip_depth);
    *(float*)(cpu->esi + 0x2B0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=g_sfera_window_runtime.clip_vector_count, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = native_function_address32(&::rand);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00074075;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x2A8u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.9900000095367432);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00074075;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2A8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2A4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2ACu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473DE5u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x473DE5u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->esp -= 0xCu;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473E1Fu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x473E1Fu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[5u] = cpu->fpu[5u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[4u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[6u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[3u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->esp -= 0xCu;
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->fpu[3u] = cpu->fpu[0u] - cpu->fpu[3u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473EE3u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x473EE3u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x73EF9u), LIFT_CODE_TOKEN_RVA(0x73EF7u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, 0.800000011920929);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00073F74;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.125);
    goto label_00073F7C;
    label_00073F28:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00073C72;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473F44u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x473F44u));
    if (cpu->eax != 0u) goto label_00073F4D;
    cpu->eax = (uintptr_t)"<none>";
    label_00073F4D:
    lift_push32(cpu, 0x343Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x473F62u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x73F74u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x73F74u));
    label_00073F74:
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (5.0);
    label_00073F7C:
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->eax = cpu->esp;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x473FDCu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x473FDCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x440u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0x2ACu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0x10u;
    cpu->ecx = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47401Du)); sfera_sub_00473A30(cpu, LIFT_CODE_TOKEN_VA(0x47401Du));
    if (cpu->eax != 2u) goto label_000740FF;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x440u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474051u)); sfera_sub_00473A30(cpu, LIFT_CODE_TOKEN_VA(0x474051u));
    if (cpu->eax == 2u) goto label_00074077;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2ACu) = cpu->ecx;
    goto label_000740FF;
    label_00074075:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00074077:
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x74079u), LIFT_CODE_TOKEN_RVA(0x74077u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (1.0);
    *(float*)(cpu->esi + 0x2A4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x2A8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x7409Fu), LIFT_CODE_TOKEN_RVA(0x7409Du))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (1.0);
    *(float*)(cpu->esi + 0x2ACu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2A4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2A8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2ACu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4740E5u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x4740E5u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0x2ACu) = cpu->eax;
    label_000740FF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x42Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00474120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x410u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    if ((int32_t)cpu->ebx >= 0) goto label_00074146;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x74146u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x74146u));
    label_00074146:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007415A;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7415Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7415Au));
    label_0007415A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    if (cpu->esi != 0u) goto label_000743A1;
    label_0007416A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474179u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x474179u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x41Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 9.800000190734863);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x28Cu)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u];
    lift_x87_compare(cpu, cpu->fpu[0u], 30.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000741D5;
    lift_x87_push(cpu, (double)30.0f);
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000741D5:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.003000000026077032f);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00074594;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->ecx + 0x198u)));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474207u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x474207u));
    cpu->edi = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->ebp = 0u;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->edi <= 0) goto label_00074249;
    label_00074220:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_push32(cpu, 1u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47423Cu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47423Cu));
    if (cpu->eax != 0u) goto label_000743ED;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->edi) goto label_00074220;
    label_00074249:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18Cu);
    if (cpu->ecx == 0u) goto label_00074329;
    lift_x87_push(cpu, (double)-745.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007427B;
    lift_x87_push(cpu, (double)-740.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007431F;
    label_0007427B:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -495.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007429F;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -490.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007431F;
    label_0007429F:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -245.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000742BF;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -240.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007431F;
    label_000742BF:
    lift_x87_push(cpu, (double)5.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000742DF;
    lift_x87_push(cpu, (double)10.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007431F;
    label_000742DF:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 255.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000742FF;
    lift_x87_push(cpu, (double)260.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007431F;
    label_000742FF:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 505.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00074329;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 510.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00074329;
    label_0007431F:
    cpu->edx = (uintptr_t)"phKILL 1";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x74329u)); sfera_sub_00437FF0(cpu, LIFT_CODE_TOKEN_RVA(0x74329u));
    label_00074329:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 8000.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007439A;
    cpu->edi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x74341u), LIFT_CODE_TOKEN_RVA(0x7433Fu))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (6.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (77.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (3.0);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)160.0f);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x7436Fu), LIFT_CODE_TOKEN_RVA(0x7436Du))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (6.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (95.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (3.0);
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00074392:
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007439A:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    goto label_00074598;
    label_000743A1:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0007416A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4743BDu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4743BDu));
    if (cpu->eax != 0u) goto label_000743C6;
    cpu->eax = (uintptr_t)"<none>";
    label_000743C6:
    lift_push32(cpu, 0x3487u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4743DBu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x743EDu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x743EDu));
    label_000743ED:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.029999999329447746);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0007447C;
    label_00074411:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.25);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00074420:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00074458;
    lift_push32(cpu, 1u);
    cpu->edx = 2u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474454u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x474454u));
    if (cpu->eax == 0u) goto label_00074420;
    label_00074458:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.029999999329447746);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_00074411;
    label_0007447C:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0x28Cu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00074392;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) == 0u) goto label_000744DC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], 7.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000744DC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"phDMG %5.1f"); lift_push32(cpu, (uintptr_t)&g_sfera_physics_runtime.damage_text[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4744C3u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18Cu);
    cpu->esp += 0x10u;
    cpu->edx = (uintptr_t)&g_sfera_physics_runtime.damage_text[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x744DCu)); sfera_sub_00437FF0(cpu, LIFT_CODE_TOKEN_RVA(0x744DCu));
    label_000744DC:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    *(uint32_t*)(cpu->esi + 0x278u) = 0u;
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)g_sfera_view_spatial_runtime.view_axis.x.f32));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.6000000238418579);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x288u));
    lift_x87_push(cpu, 0.4000000059604645);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.z));
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x290u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x290u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47455Cu));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0517578125e-05);
    cpu->fpu[0u] = (0.5) - (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x28Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esi + 0x294u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00074598;
    label_00074594:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00074598:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x410u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004745C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x420u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->edi >= 0) goto label_000745E6;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x745E6u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x745E6u));
    label_000745E6:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000745FA;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x745FAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x745FAu));
    label_000745FA:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->esi != 0u) goto label_0007474A;
    label_0007460A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47461Bu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47461Bu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x438u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x434u));
    cpu->ebx = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x43Cu));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474653u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x474653u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->ebx + 0x198u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474666u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x474666u));
    cpu->ebx = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->ebp = 0u;
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x434u)));
    *(float*)(cpu->esp + 0x434u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x438u)));
    *(float*)(cpu->esp + 0x438u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x43Cu)));
    *(float*)(cpu->esp + 0x43Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->ebx <= 0) goto label_0007470C;
    label_000746B1:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x434u)));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_push32(cpu, 1u);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->ecx = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x440u)));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x444u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4746FFu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4746FFu));
    if (cpu->eax != 0u) goto label_00074796;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ebx) goto label_000746B1;
    label_0007470C:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.029999999329447746);
    cpu->ebx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    lift_push32(cpu, 1u);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474730u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x474730u));
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    if (cpu->eax == 0u) goto label_0007481D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    goto label_000748BE;
    label_0007474A:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0007460A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474766u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x474766u));
    if (cpu->eax != 0u) goto label_0007476F;
    cpu->eax = (uintptr_t)"<none>";
    label_0007476F:
    lift_push32(cpu, 0x34E1u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x474784u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x74796u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x74796u));
    label_00074796:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x38u);
    lift_x87_push(cpu, (double)0.4000000059604645f);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->eax == 4u) goto label_000747AD;
    if (cpu->eax != 5u) goto label_000747B7;
    label_000747AD:
    lift_x87_push(cpu, (double)0.05000000074505806f);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000747B7:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, 1u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    *(double*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    cpu->fpu[0u] = (((double)*(float*)(cpu->esi + 0xCu))) - (cpu->fpu[0u]);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4747D6u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4747D6u));
    if (cpu->eax == 0u) goto label_00074868;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_push32(cpu, 1u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (*(double*)(cpu->esp + 0x14u));
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4747F3u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4747F3u));
    if (cpu->eax == 0u) goto label_00074868;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 2u;
    goto label_000748C0;
    label_0007481D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.4000000059604645);
    lift_push32(cpu, 1u);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47483Bu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47483Bu));
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    if (cpu->eax != 0u) goto label_00074861;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esi + 0x278u) = cpu->eax;
    goto label_000748C0;
    label_00074861:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    label_00074868:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x198u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    label_0007487A:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.25);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00074884:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_push32(cpu, 1u);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4748A0u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4748A0u));
    if (cpu->eax == 0u) goto label_00074884;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.029999999329447746);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0007487A;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000748BE:
    cpu->eax = 0u;
    label_000748C0:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x420u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004748E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x440u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x448u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp >= 0) goto label_00074913;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x74913u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x74913u));
    label_00074913:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00074927;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x74927u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x74927u));
    label_00074927:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->ebp * 4u));
    if (cpu->edi != 0u) goto label_00074A5E;
    label_00074937:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    cpu->ebx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state;
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_push32(cpu, 1u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x27Cu)));
    cpu->edx = 0u;
    cpu->ecx = cpu->ebp;
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x284u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x288u)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x290u)));
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = 0u;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474984u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x474984u));
    cpu->esi = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebx;
    if ((int32_t)cpu->esi <= (int32_t)1u) goto label_00074AEE;
    if ((int32_t)cpu->esi >= 0) goto label_000749A3;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x749A3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x749A3u));
    label_000749A3:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000749B7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x749B7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x749B7u));
    label_000749B7:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 8u)));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x10u)));
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = 0u;
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4749FDu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x4749FDu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00074AAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00074AAA;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00074AAA;
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    goto label_00074AAC;
    label_00074A5E:
    if (*(uint8_t*)(cpu->edi + 0x138u) != 0u) goto label_00074937;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474A7Au)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x474A7Au));
    if (cpu->eax != 0u) goto label_00074A83;
    cpu->eax = (uintptr_t)"<none>";
    label_00074A83:
    lift_push32(cpu, 0x3523u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x58u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x474A98u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x74AAAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x74AAAu));
    label_00074AAA:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00074AAC:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, 2.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(uint32_t*)(cpu->edi + 0x288u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->edi + 0x28Cu) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->edi + 0x290u) = cpu->ecx;
    label_00074AEE:
    lift_push32(cpu, 1u);
    cpu->edx = 3u;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474AFCu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x474AFCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    cpu->edx = 2u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.05999999865889549);
    cpu->ecx = cpu->ebp;
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474B1Du)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x474B1Du));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = g_sfera_recovered_static_runtime.scene_mode;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, 0.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.normalized_levels[0])));
    *(uint8_t*)(cpu->edi + 0x142u) = 0u;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)0.699999988079071f));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00074BDE;
    *(uint8_t*)(cpu->edi + 0x142u) = 1u;
    label_00074BDE:
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474BE7u)); sfera_sub_0044F800(cpu, LIFT_CODE_TOKEN_VA(0x474BE7u));
    if (cpu->eax == 1u) goto label_0007500E;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x454u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474C1Bu)); sfera_sub_004745C0(cpu, LIFT_CODE_TOKEN_VA(0x474C1Bu));
    if (cpu->eax == 1u) goto label_0007521E;
    if (cpu->eax != 2u) goto label_0007500E;
    lift_x87_push(cpu, 0.0);
    *(uint16_t*)(cpu->edi + 0x2A0u) = 0x101u;
    *(float*)(cpu->edi + 0x288u) = cpu->fpu[0u];
    *(float*)(cpu->edi + 0x290u) = cpu->fpu[0u];
    *(float*)(cpu->edi + 0x294u) = cpu->fpu[0u];
    if ((int32_t)g_sfera_scene_array_runtime.clip_vectors.capacity > (int32_t)0u) goto label_00074C63;
    cpu->edx = 0u;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474C61u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x474C61u));
    lift_x87_push(cpu, 0.0);
    label_00074C63:
    cpu->eax = g_sfera_scene_array_runtime.clip_vectors.data;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi + 0x2A4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edi + 0x2A8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edi + 0x2ACu) = cpu->eax;
    lift_x87_push(cpu, (double)g_sfera_recovered_static_runtime.clip_depth);
    *(float*)(cpu->edi + 0x2B0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_window_runtime.clip_vector_count != 1u) goto label_00074F7E;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x2A8u));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.9900000095367432);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00074F7E;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2A8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2A4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2ACu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474CF2u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x474CF2u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474D44u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x474D44u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[5u] = cpu->fpu[5u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[4u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->esp -= 0xCu;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[6u]);
    cpu->eax = cpu->esp;
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[3u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[3u] = cpu->fpu[0u] - cpu->fpu[3u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474E08u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x474E08u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = native_function_address32(&::rand);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x74E24u), LIFT_CODE_TOKEN_RVA(0x74E22u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, 0.800000011920929);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00074E53;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.125);
    goto label_00074E5B;
    label_00074E53:
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (5.0);
    label_00074E5B:
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->eax = cpu->esp;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474EBBu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x474EBBu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi + 0x2A4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edi + 0x2A8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = cpu->edi + 0x2A4u;
    *(uint32_t*)(cpu->edi + 0x2ACu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474EE0u)); sfera_sub_0044F800(cpu, LIFT_CODE_TOKEN_VA(0x474EE0u));
    if (cpu->eax == 1u) goto label_0007500E;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2A4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x454u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2A8u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2ACu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474F1Au)); sfera_sub_004745C0(cpu, LIFT_CODE_TOKEN_VA(0x474F1Au));
    if (cpu->eax != 2u) goto label_0007500E;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474F2Cu)); sfera_sub_0044F800(cpu, LIFT_CODE_TOKEN_VA(0x474F2Cu));
    if (cpu->eax == 1u) goto label_00074F61;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x454u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474F5Cu)); sfera_sub_004745C0(cpu, LIFT_CODE_TOKEN_VA(0x474F5Cu));
    if (cpu->eax == 2u) goto label_00074F86;
    label_00074F61:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->edi + 0x2A4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x2A8u) = cpu->ecx;
    goto label_00075008;
    label_00074F7E:
    cpu->ebx = native_function_address32(&::rand);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00074F86:
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x74F88u), LIFT_CODE_TOKEN_RVA(0x74F86u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (1.0);
    *(float*)(cpu->edi + 0x2A4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->edi + 0x2A8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x74FAEu), LIFT_CODE_TOKEN_RVA(0x74FACu))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (1.0);
    *(float*)(cpu->edi + 0x2ACu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2A4u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2A8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2ACu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x474FF4u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x474FF4u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi + 0x2A4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edi + 0x2A8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    label_00075008:
    *(uint32_t*)(cpu->edi + 0x2ACu) = cpu->edx;
    label_0007500E:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    lift_push32(cpu, 1u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 2u;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    cpu->ecx = cpu->ebp;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.05999999865889549);
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47502Fu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47502Fu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.765999972820282f);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00075135;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475060u)); sfera_sub_004EED5A(cpu, LIFT_CODE_TOKEN_VA(0x475060u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47506Du)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x47506Du));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->esp -= 0xCu;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (4.0);
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.x));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.z));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4750BDu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x4750BDu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x288u)));
    *(float*)(cpu->edi + 0x288u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x28Cu)));
    *(float*)(cpu->edi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x290u)));
    *(float*)(cpu->edi + 0x290u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0007513B;
    label_00075135:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    label_0007513B:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)g_sfera_render_sample_runtime.blend_weights[0].f32));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x290u));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x288u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475166u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x475166u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000751AE;
    lift_x87_compare(cpu, cpu->fpu[0u], 9.999999747378752e-05);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000751AE;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x288u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    *(float*)(cpu->edi + 0x288u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->edi + 0x290u))) / (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000751BA;
    label_000751AE:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->edi + 0x288u) = cpu->fpu[0u];
    label_000751BA:
    *(float*)(cpu->edi + 0x290u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[0].f32));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (10.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.7799999713897705);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4751E3u)); sfera_sub_004EE9FE(cpu, LIFT_CODE_TOKEN_VA(0x4751E3u));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x294u)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(float*)(cpu->edi + 0x294u) = cpu->fpu[0u];
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_compare(cpu, cpu->fpu[0u], 9.999999747378752e-05);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007521E;
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->edi + 0x294u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007521E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x440u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00475240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x418u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    if ((int32_t)cpu->ebx >= 0) goto label_00075266;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75266u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x75266u));
    label_00075266:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007527A;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7527Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7527Au));
    label_0007527A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    if (cpu->esi != 0u) goto label_000753B8;
    label_0007528A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47529Bu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47529Bu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x430u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x42Cu));
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x434u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4752CFu)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x4752CFu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->edi + 0x198u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4752E2u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4752E2u));
    cpu->edi = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x42Cu)));
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(float*)(cpu->esp + 0x42Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x430u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x430u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x434u)));
    *(float*)(cpu->esp + 0x434u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->edi <= 0) goto label_0007539B;
    label_00075333:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->ebp = *(uint32_t*)(cpu->esi + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x42Cu)));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_push32(cpu, 1u);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x434u)));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x438u)));
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x43Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47538Au)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x47538Au));
    if (cpu->eax != 0u) goto label_00075404;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00075333;
    label_0007539B:
    cpu->eax = 0u;
    label_0007539D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000753B8:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0007528A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4753D4u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4753D4u));
    if (cpu->eax != 0u) goto label_000753DD;
    cpu->eax = (uintptr_t)"<none>";
    label_000753DD:
    lift_push32(cpu, 0x35FAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4753F2u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75404u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x75404u));
    label_00075404:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 2u;
    goto label_0007539D;
}
__declspec(noinline) void sfera_sub_00475430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x420u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->edi >= 0) goto label_00075459;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75459u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x75459u));
    label_00075459:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007546D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7546Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7546Du));
    label_0007546D:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->esi != 0u) goto label_0007558E;
    label_0007547D:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x288u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x27Cu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x280u)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x290u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x284u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x434u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->ebx != 0u) goto label_000754DE;
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000754DE:
    lift_push32(cpu, 1u);
    cpu->edx = 3u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4754ECu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4754ECu));
    cpu->eax = g_sfera_recovered_static_runtime.scene_mode;
    lift_x87_push(cpu, (double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.normalized_levels[0])));
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x440u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47554Bu)); sfera_sub_00475240(cpu, LIFT_CODE_TOKEN_VA(0x47554Bu));
    if (cpu->eax == 0u) goto label_00075574;
    lift_x87_push(cpu, 0.0);
    *(uint8_t*)(cpu->esi + 0x2A0u) = 1u;
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x290u) = cpu->fpu[0u];
    if (cpu->ebx == 0u) goto label_0007556E;
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u];
    label_0007556E:
    *(float*)(cpu->esi + 0x294u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075574:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x420u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007558E:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0007547D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4755AAu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4755AAu));
    if (cpu->eax != 0u) goto label_000755B3;
    cpu->eax = (uintptr_t)"<none>";
    label_000755B3:
    lift_push32(cpu, 0x3617u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4755C8u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4755DAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4755DAu));
    lift_trap(cpu, 0x4755DAu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004755E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x414u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    if ((int32_t)cpu->ebp >= 0) goto label_00075606;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75606u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x75606u));
    label_00075606:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0007561A;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7561Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7561Au));
    label_0007561A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ebp * 4u));
    if (cpu->esi != 0u) goto label_00075882;
    label_0007562A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475639u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x475639u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x420u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 9.800000190734863);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x28Cu)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u];
    lift_x87_compare(cpu, cpu->fpu[0u], 30.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00075695;
    lift_x87_push(cpu, (double)30.0f);
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075695:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.003000000026077032f);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00075A70;
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->ecx + 0x198u)));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4756C7u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4756C7u));
    cpu->edi = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->ebx = 0u;
    *(uint8_t*)(cpu->esp + 0x1Bu) = 0u;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->edi <= 0) goto label_0007580A;
    label_000756E5:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_push32(cpu, 1u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = cpu->ebp;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475701u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475701u));
    if (cpu->eax != 0u) goto label_000758CE;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) == cpu->eax) goto label_000757E2;
    lift_x87_push(cpu, (double)-745.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00075739;
    lift_x87_push(cpu, (double)-740.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000757DD;
    label_00075739:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -495.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007575D;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -490.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000757DD;
    label_0007575D:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -245.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007577D;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], -240.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000757DD;
    label_0007577D:
    lift_x87_push(cpu, (double)5.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007579D;
    lift_x87_push(cpu, (double)10.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000757DD;
    label_0007579D:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 255.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000757BD;
    lift_x87_push(cpu, (double)260.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0xCu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000757DD;
    label_000757BD:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 505.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000757E2;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 510.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000757E2;
    label_000757DD:
    *(uint8_t*)(cpu->esp + 0x1Bu) = 1u;
    label_000757E2:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_000756E5;
    if (*(uint8_t*)(cpu->esp + 0x1Bu) == 0u) goto label_0007580A;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18Cu);
    cpu->edx = (uintptr_t)"phKILL 1";
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7580Au)); sfera_sub_00437FF0(cpu, LIFT_CODE_TOKEN_RVA(0x7580Au));
    label_0007580A:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 8000.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007587B;
    cpu->edi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x75822u), LIFT_CODE_TOKEN_RVA(0x75820u))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (6.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (77.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (3.0);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)160.0f);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x75850u), LIFT_CODE_TOKEN_RVA(0x7584Eu))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (6.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) / (32767.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (95.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (3.0);
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075873:
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007587B:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    goto label_00075A74;
    label_00075882:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0007562A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47589Eu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x47589Eu));
    if (cpu->eax != 0u) goto label_000758A7;
    cpu->eax = (uintptr_t)"<none>";
    label_000758A7:
    lift_push32(cpu, 0x362Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4758BCu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x758CEu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x758CEu));
    label_000758CE:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.029999999329447746);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0007595C;
    label_000758F2:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.25);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075900:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00075938;
    lift_push32(cpu, 1u);
    cpu->edx = 2u;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475934u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475934u));
    if (cpu->eax == 0u) goto label_00075900;
    label_00075938:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.029999999329447746);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_000758F2;
    label_0007595C:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0x28Cu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00075873;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) == 0u) goto label_000759B8;
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esi + 0x28Cu)));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000759B8;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"phDMG %5.1f"); lift_push32(cpu, (uintptr_t)&g_sfera_physics_runtime.damage_text[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47599Fu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18Cu);
    cpu->esp += 0x10u;
    cpu->edx = (uintptr_t)&g_sfera_physics_runtime.damage_text[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x759B8u)); sfera_sub_00437FF0(cpu, LIFT_CODE_TOKEN_RVA(0x759B8u));
    label_000759B8:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x28Cu));
    *(uint32_t*)(cpu->esi + 0x278u) = 0u;
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)g_sfera_view_spatial_runtime.view_axis.x.f32));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.6000000238418579);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x288u));
    lift_x87_push(cpu, 0.4000000059604645);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.z));
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x290u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x290u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x475A38u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0517578125e-05);
    cpu->fpu[0u] = (0.5) - (cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x28Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esi + 0x294u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00075A74;
    label_00075A70:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075A74:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x414u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00475A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x420u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->edi >= 0) goto label_00075AB6;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75AB6u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x75AB6u));
    label_00075AB6:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00075ACA;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75ACAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x75ACAu));
    label_00075ACA:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->esi != 0u) goto label_00075C1D;
    label_00075ADA:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475AEBu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x475AEBu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x438u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x434u));
    cpu->ebx = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x43Cu));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475B23u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x475B23u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->ebx + 0x198u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475B36u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x475B36u));
    cpu->ebx = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->ebp = 0u;
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x434u)));
    *(float*)(cpu->esp + 0x434u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x438u)));
    *(float*)(cpu->esp + 0x438u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x43Cu)));
    *(float*)(cpu->esp + 0x43Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->ebx <= 0) goto label_00075BDF;
    label_00075B81:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x434u)));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_push32(cpu, 1u);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 1u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->ecx = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x440u)));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x444u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475BD2u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475BD2u));
    if (cpu->eax != 0u) goto label_00075C69;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ebx) goto label_00075B81;
    label_00075BDF:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.029999999329447746);
    cpu->ebx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    lift_push32(cpu, 1u);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475C03u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475C03u));
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    if (cpu->eax == 0u) goto label_00075CF0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    goto label_00075D91;
    label_00075C1D:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00075ADA;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475C39u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x475C39u));
    if (cpu->eax != 0u) goto label_00075C42;
    cpu->eax = (uintptr_t)"<none>";
    label_00075C42:
    lift_push32(cpu, 0x368Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x475C57u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75C69u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x75C69u));
    label_00075C69:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x38u);
    lift_x87_push(cpu, (double)0.4000000059604645f);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->eax == 4u) goto label_00075C80;
    if (cpu->eax != 5u) goto label_00075C8A;
    label_00075C80:
    lift_x87_push(cpu, (double)0.05000000074505806f);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075C8A:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, 1u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    *(double*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    cpu->fpu[0u] = (((double)*(float*)(cpu->esi + 0xCu))) - (cpu->fpu[0u]);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475CA9u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475CA9u));
    if (cpu->eax == 0u) goto label_00075D3B;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_push32(cpu, 1u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (*(double*)(cpu->esp + 0x14u));
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475CC6u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475CC6u));
    if (cpu->eax == 0u) goto label_00075D3B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 2u;
    goto label_00075D93;
    label_00075CF0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.4000000059604645);
    lift_push32(cpu, 1u);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475D0Eu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475D0Eu));
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    if (cpu->eax != 0u) goto label_00075D34;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esi + 0x278u) = cpu->eax;
    goto label_00075D93;
    label_00075D34:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    label_00075D3B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x198u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    label_00075D4D:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.25);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075D57:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_push32(cpu, 1u);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475D73u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475D73u));
    if (cpu->eax == 0u) goto label_00075D57;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.029999999329447746);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_00075D4D;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075D91:
    cpu->eax = 0u;
    label_00075D93:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x420u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00475DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x470u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x478u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebx >= 0) goto label_00075DF3;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75DF3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x75DF3u));
    label_00075DF3:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00075E07;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75E07u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x75E07u));
    label_00075E07:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    if (cpu->esi != 0u) goto label_00075F42;
    label_00075E17:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    cpu->ebp = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state;
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_push32(cpu, 1u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x27Cu)));
    cpu->edx = 0u;
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x284u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x288u)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x290u)));
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = 0u;
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475E64u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475E64u));
    cpu->edi = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = cpu->ebp;
    if ((int32_t)cpu->edi <= (int32_t)1u) goto label_00075FD5;
    if ((int32_t)cpu->edi >= 0) goto label_00075E83;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75E83u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x75E83u));
    label_00075E83:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00075E97;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75E97u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x75E97u));
    label_00075E97:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edi + 8u)));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edi + 0x10u)));
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = 0u;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475EDDu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x475EDDu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00075F91;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00075F91;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00075F91;
    lift_x87_push(cpu, (double)2.0f);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    goto label_00075F93;
    label_00075F42:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00075E17;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475F5Eu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x475F5Eu));
    if (cpu->eax != 0u) goto label_00075F67;
    cpu->eax = (uintptr_t)"<none>";
    label_00075F67:
    lift_push32(cpu, 0x36CDu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x88u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x475F7Fu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x75F91u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x75F91u));
    label_00075F91:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00075F93:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, 2.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x28Cu) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi + 0x290u) = cpu->ecx;
    label_00075FD5:
    lift_push32(cpu, 1u);
    cpu->edx = 3u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x475FE3u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x475FE3u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->edx = 2u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.05999999865889549);
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476004u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x476004u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = g_sfera_recovered_static_runtime.scene_mode;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, 0.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.normalized_levels[0])));
    *(uint8_t*)(cpu->esi + 0x142u) = 0u;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x60u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)0.699999988079071f));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000760C5;
    *(uint8_t*)(cpu->esi + 0x142u) = 1u;
    label_000760C5:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x484u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4760F0u)); sfera_sub_00475A90(cpu, LIFT_CODE_TOKEN_VA(0x4760F0u));
    if (cpu->eax == 1u) goto label_000766C2;
    if (cpu->eax != 2u) goto label_00076499;
    lift_x87_push(cpu, 0.0);
    cpu->edi = 0u;
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u];
    *(uint8_t*)(cpu->esi + 0x2A0u) = 1u;
    *(float*)(cpu->esi + 0x290u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x294u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)g_sfera_window_runtime.clip_vector_count <= (int32_t)cpu->edi) goto label_000762D9;
    cpu->ebp = 0u;
    label_00076130:
    if ((int32_t)cpu->edi >= 0) goto label_0007613E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7613Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x7613Eu));
    label_0007613E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.clip_vectors.capacity) goto label_00076152;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x76152u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x76152u));
    label_00076152:
    cpu->eax = g_sfera_scene_array_runtime.clip_vectors.data;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 8u);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.9900000095367432);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000762C9;
    lift_x87_push(cpu, 0.0);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = 0xDu;
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4761AAu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x4761AAu));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[5u] = cpu->fpu[5u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[4u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[6u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[3u]);
    lift_x87_push(cpu, cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, 9.999999747378752e-05);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    cpu->esp -= 0x10u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x74u)));
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x7Cu)));
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4762BCu)); sfera_sub_00475A90(cpu, LIFT_CODE_TOKEN_VA(0x4762BCu));
    if (cpu->eax == 1u) goto label_000766C2;
    if (cpu->eax == 0u) goto label_000762D9;
    label_000762C9:
    ++cpu->edi;
    cpu->ebp += 0xCu;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_window_runtime.clip_vector_count) goto label_00076130;
    label_000762D9:
    cpu->edi = 0u;
    if ((int32_t)g_sfera_window_runtime.clip_vector_count <= (int32_t)cpu->edi) goto label_00076499;
    cpu->ebp = 0u;
    label_000762F0:
    if ((int32_t)cpu->edi >= 0) goto label_000762FE;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x762FEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x762FEu));
    label_000762FE:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.clip_vectors.capacity) goto label_00076312;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x76312u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x76312u));
    label_00076312:
    cpu->eax = g_sfera_scene_array_runtime.clip_vectors.data;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x5Cu));
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 8u);
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.9900000095367432);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00076489;
    lift_x87_push(cpu, 0.0);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = 0xEu;
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47636Au)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x47636Au));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[5u] = cpu->fpu[5u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[4u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[6u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[3u]);
    lift_x87_push(cpu, cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, 0.019999999552965164);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    cpu->esp -= 0x10u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x74u)));
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x7Cu)));
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47647Cu)); sfera_sub_00475A90(cpu, LIFT_CODE_TOKEN_VA(0x47647Cu));
    if (cpu->eax == 1u) goto label_000766C2;
    if (cpu->eax == 0u) goto label_00076499;
    label_00076489:
    ++cpu->edi;
    cpu->ebp += 0xCu;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_window_runtime.clip_vector_count) goto label_000762F0;
    label_00076499:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    lift_push32(cpu, 1u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 2u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    cpu->ecx = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.05999999865889549);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4764BAu)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x4764BAu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.y));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.765999972820282f);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000765C0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4764EBu)); sfera_sub_004EED5A(cpu, LIFT_CODE_TOKEN_VA(0x4764EBu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4764F8u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x4764F8u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->esp -= 0xCu;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (4.0);
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.x));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.view_axis.z));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476548u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x476548u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x64u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x6Cu)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x288u)));
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x28Cu)));
    *(float*)(cpu->esi + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x290u)));
    *(float*)(cpu->esi + 0x290u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000765C6;
    label_000765C0:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    label_000765C6:
    cpu->eax = g_sfera_recovered_static_runtime.view_direction_state;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[0].f32))));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_000765E2;
    *(uint8_t*)(cpu->esi + 0x142u) = 0u;
    label_000765E2:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x290u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x288u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476603u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x476603u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007664B;
    lift_x87_compare(cpu, cpu->fpu[0u], 9.999999747378752e-05);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007664B;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x288u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->esi + 0x290u))) / (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00076657;
    label_0007664B:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x288u) = cpu->fpu[0u];
    label_00076657:
    *(float*)(cpu->esi + 0x290u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = g_sfera_recovered_static_runtime.view_direction_state;
    lift_x87_push(cpu, (double)*(float*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[0].f32)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (10.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x54u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.7799999713897705);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476687u)); sfera_sub_004EE9FE(cpu, LIFT_CODE_TOKEN_VA(0x476687u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x294u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esi + 0x294u) = cpu->fpu[0u];
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], 9.999999747378752e-05);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000766C2;
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x294u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000766C2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x470u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004766E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if ((int32_t)cpu->esi >= 0) goto label_000766FD;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x766FDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x766FDu));
    label_000766FD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00076711;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x76711u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x76711u));
    label_00076711:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00076730;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x76730u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x76730u));
    label_00076730:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x10u)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476780u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x476780u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], 15.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007679D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007679D:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4767A5u)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x4767A5u));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    lift_x87_push(cpu, 0.11999999731779099);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, 100000.0);
    cpu->fpu[2u] = (cpu->fpu[2u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4767BFu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4767BFu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x10u)));
    cpu->esi = cpu->eax;
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4767CBu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4767CBu));
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->esi + 0x4E20u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->esi = 0xCu;
    lift_divide_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->esi = cpu->eax + 0xFFFFD8F0u;
    cpu->eax = cpu->ecx + 0x4E20u;
    cpu->ebx = cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xCu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ecx = 0x27u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = cpu->eax + 0xFFFFD8F0u;
    cpu->eax = cpu->esi + 0x28u;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if (cpu->eax > 0x4Fu) goto label_00076B2D;
    { uint64_t l=cpu->ecx, r=0x4Fu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00076B2D;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax <<= 4u;
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->esi = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476852u)); sfera_sub_0046D240(cpu, LIFT_CODE_TOKEN_VA(0x476852u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esi + (cpu->esi * 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    cpu->edx = *(uint32_t*)(cpu->ebp + (cpu->eax * 4u) + 0x8Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 1u);
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    { uint64_t l=cpu->esi, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 1u);
    cpu->ebp = cpu->edx;
    cpu->ebp = cpu->ebp >> 31u;
    { uint64_t l=cpu->ebp, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebp = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + (cpu->ebp * 2u);
    cpu->eax = cpu->ecx;
    { uint64_t l=cpu->eax, r=0x80000001u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000768B8;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    ++cpu->eax;
    label_000768B8:
    cpu->edx = cpu->eax + (cpu->edx * 2u);
    cpu->eax = cpu->esi;
    { uint64_t l=cpu->eax, r=0x80000001u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000768C9;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    ++cpu->eax;
    label_000768C9:
    cpu->eax = cpu->eax + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= cpu->ecx;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax -= cpu->esi;
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebx + (cpu->eax * 2u);
    cpu->ecx += cpu->eax;
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx += cpu->ecx;
    cpu->eax = cpu->edx + (cpu->ecx * 8u) + 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x1B1Cu);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = cpu->edx + (cpu->ecx * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->edx == 0u) goto label_0007690B;
    *(uint32_t*)(cpu->edx) = 0xFFFFFFFFu;
    label_0007690B:
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->esi == 0u) goto label_0007696D;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x8Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007696D;
    if (cpu->edx == 0u) goto label_00076929;
    *(uint32_t*)(cpu->edx) = cpu->esi;
    label_00076929:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x80u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (0.25);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007694F;
    cpu->ebp = lift_pop32(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007694F:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (30.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007696D;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 5u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007696D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = 0u;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.20000000298023224);
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, 0u);
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476999u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x476999u));
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebp;
    if (cpu->eax != 0u) goto label_000769AE;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000769AE:
    if ((int32_t)cpu->eax <= (int32_t)1u) goto label_000769F2;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4769BEu)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x4769BEu));
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4769CFu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4769CFu));
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"tree"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strnicmp), LIFT_CODE_TOKEN_VA(0x4769D7u));
    cpu->esp += 0xCu;
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ebx = lift_pop32(cpu);
    cpu->eax &= 0xFFFFFFFDu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 6u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000769F2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_x87_push(cpu, 100.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) / (cpu->fpu[0u]);
    lift_x87_push(cpu, 254.0);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, 1.0);
    cpu->fpu[3u] = (cpu->fpu[3u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476A27u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x476A27u));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[2u] = cpu->fpu[0u] / cpu->fpu[2u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476A4Eu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x476A4Eu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebx = *(uint32_t*)(cpu->edx + (cpu->eax * 4u) + 0x3ACu);
    cpu->eax = 2u;
    cpu->ecx = cpu->esi + 0xFFFFFFFEu;
    cpu->eax -= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    label_00076A80:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebp = cpu->eax + cpu->edx + 0xFFFFFFFEu;
    label_00076A90:
    cpu->ecx = cpu->edi;
    cpu->eax = cpu->ebp;
    if ((int32_t)cpu->edi >= 0) goto label_00076A9C;
    cpu->ecx = 0u;
    goto label_00076AA9;
    label_00076A9C:
    if ((int32_t)cpu->edi <= (int32_t)0xFFu) goto label_00076AA9;
    cpu->ecx = 0xFFu;
    label_00076AA9:
    if ((int32_t)cpu->eax >= 0) goto label_00076AB1;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    goto label_00076ABD;
    label_00076AB1:
    { uint64_t l=cpu->eax, r=0xFFu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00076ABD;
    cpu->eax = 0xFFu;
    label_00076ABD:
    cpu->eax <<= 8u;
    { uint64_t l=cpu->eax, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = *(uint16_t*)(cpu->ebx + (cpu->eax * 2u) + 0x20u);
    cpu->ecx = cpu->esi;
    cpu->ecx >>= 6u;
    cpu->ecx &= 0x1Fu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x64u);
    cpu->eax = 0x9C09C09Du;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 6u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ecx = cpu->esi;
    cpu->eax += cpu->edx;
    cpu->ecx &= 0x1Fu;
    { uint64_t l=cpu->ecx, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00076B20;
    cpu->esi >>= 11u;
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_00076B20;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    ++cpu->edi;
    cpu->edx += cpu->edi;
    if ((int32_t)cpu->edx < (int32_t)5u) goto label_00076A90;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)5u) goto label_00076A80;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00076B20:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 2u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00076B2D:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00476DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x428u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)0u) goto label_00076E09;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x76E09u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x76E09u));
    label_00076E09:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_00076FCF;
    label_00076E18:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x164u));
    lift_push32(cpu, 0u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.x.f32)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x168u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 0x16Cu)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14Cu));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.z.f32)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x150u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 0x154u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 8u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0xCu)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, 192.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(uint32_t*)(cpu->eax + 0x27Cu) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax + 0x280u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->eax + 0x284u) = cpu->ecx;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 0x288u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax + 0x28Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x290u) = cpu->edx;
    cpu->edx = 4u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476F10u)); sfera_sub_00471E70(cpu, LIFT_CODE_TOKEN_VA(0x476F10u));
    lift_x87_push(cpu, (double)0.0052083334885537624f);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = 1u;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = 0u;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476F2Eu)); sfera_sub_00475430(cpu, LIFT_CODE_TOKEN_VA(0x476F2Eu));
    lift_x87_push(cpu, 0.0);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.y.f32));
    cpu->ecx = 0u;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.x.f32));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476F51u)); sfera_sub_004634E0(cpu, LIFT_CODE_TOKEN_VA(0x476F51u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476F56u)); sfera_sub_00463EC0(cpu, LIFT_CODE_TOKEN_VA(0x476F56u));
    lift_x87_push(cpu, (double)g_sfera_main_view_state_runtime.view_coefficients[0]);
    lift_x87_push(cpu, (double)0.972000002861023f); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x424u);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx ^= cpu->esp;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    g_sfera_main_view_state_runtime.view_coefficients[0] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)g_sfera_main_view_state_runtime.view_coefficients[1]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    g_sfera_main_view_state_runtime.view_coefficients[1] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)(*(float*)(void*)&g_sfera_main_view_state_runtime.view_coefficients[2])));
    g_sfera_main_view_state_runtime.view_coefficients[2] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)g_sfera_main_view_state_runtime.view_coefficients[3]);
    lift_x87_push(cpu, (double)0.972000002861023f); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    g_sfera_main_view_state_runtime.view_coefficients[3] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)g_sfera_main_view_state_runtime.view_coefficients[4]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    g_sfera_main_view_state_runtime.view_coefficients[4] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)(*(float*)(void*)&g_sfera_main_view_state_runtime.view_coefficients[5])));
    g_sfera_main_view_state_runtime.view_coefficients[5] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x428u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00076FCF:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00076E18;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x476FEBu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x476FEBu));
    if (cpu->eax != 0u) goto label_00076FF4;
    cpu->eax = (uintptr_t)"<none>";
    label_00076FF4:
    lift_push32(cpu, 0x1046u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x477009u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47701Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x47701Bu));
    lift_trap(cpu, 0x47701Bu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00477020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x12Cu;
    { uint64_t l=g_sfera_recovered_static_runtime.scene_state_09, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = g_sfera_shadow_runtime.manager;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00077059;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477054u)); sfera_sub_00460D50(cpu, LIFT_CODE_TOKEN_VA(0x477054u));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477097u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x477097u));
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
    { uint64_t l=cpu->esi, r=g_sfera_scene_array_runtime.character_matrices.capacity, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000770EC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x770ECu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x770ECu));
    label_000770EC:
    cpu->esi <<= 6u;
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    cpu->ecx = 0x10u;
    cpu->edi = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    lift_movs32(cpu, 1u);
    goto label_00077113;
    label_00077103:
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_character_frame_matrix.m[0][0]);
    cpu->edx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77113u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_RVA(0x77113u));
    label_00077113:
    lift_x87_push(cpu, 0.0);
    cpu->ecx = 0x10u;
    cpu->esi = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    cpu->edi = (uintptr_t)&g_sfera_character_rotation_matrix.m[0][0];
    lift_movs32(cpu, 1u);
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[2][3]) = cpu->fpu[0u];
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[1][3]) = cpu->fpu[0u];
    *(float*)((uintptr_t)&g_sfera_character_rotation_matrix.m[0][3]) = cpu->fpu[0u]; lift_x87_pop(cpu);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47716Cu)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x47716Cu));
    cpu->edi += 0xCu;
    cpu->esi += 0xCu;
    { uint64_t l=cpu->ebx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00077150;
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0xDCu;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477188u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x477188u));
    g_sfera_client_main_scalar_runtime.mode_01 = cpu->eax;
    if (cpu->eax == 0u) goto label_00077F62;
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_000771AC;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x771ACu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x771ACu));
    label_000771AC:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebx + 8u)));
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebx + 0xCu)));
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    cpu->eax = cpu->esp;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebx + 0x10u)));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = 0u;
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4771FDu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x4771FDu));
    cpu->edi = cpu->esp + 0xE8u;
    cpu->edi &= 0xFFFFFFF0u;
    cpu->ecx = 0x10u;
    cpu->esi = (uintptr_t)&g_sfera_character_rotation_matrix.m[0][0];
    lift_movs32(cpu, 1u);
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
    cpu->ecx = 0x10u;
    cpu->esi = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->edx = cpu->esp + 0x40u;
    cpu->ecx = cpu->esp + 0xD8u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477276u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x477276u));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47727Du)); sfera_sub_0045F060(cpu, LIFT_CODE_TOKEN_VA(0x47727Du));
    { uint64_t l=*(uint8_t*)(cpu->ebx + 0x138u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, 1.0);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000774CD;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebx + 0x184u) == cpu->esi) goto label_000774CF;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007729C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4772A9u)); sfera_sub_0044E720(cpu, LIFT_CODE_TOKEN_VA(0x4772A9u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][0]));
    cpu->edx = cpu->esp + 0x98u;
    *(float*)(cpu->esp + 0x98u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][0]));
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0xA4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][0]));
    *(float*)(cpu->esp + 0xA8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][0]));
    *(float*)(cpu->esp + 0xACu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][1]));
    *(float*)(cpu->esp + 0xB0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][1]));
    *(float*)(cpu->esp + 0xB4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][1]));
    *(float*)(cpu->esp + 0xB8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][1]));
    *(float*)(cpu->esp + 0xBCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][2]));
    *(float*)(cpu->esp + 0xC0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][2]));
    *(float*)(cpu->esp + 0xC4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][2]));
    *(float*)(cpu->esp + 0xC8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][2]));
    *(float*)(cpu->esp + 0xCCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[0][3]));
    *(float*)(cpu->esp + 0xD0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[1][3]));
    *(float*)(cpu->esp + 0xD4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[2][3]));
    *(float*)(cpu->esp + 0xD8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_character_frame_matrix.m[3][3]));
    *(float*)(cpu->esp + 0xDCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477391u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x477391u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 8u));
    lift_push32(cpu, cpu->ecx);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x6Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x1ACu));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x194u));
    *(double*)(cpu->esp + 0x20u) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4773FFu)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x4773FFu));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ecx);
    cpu->fpu[0u] = (*(double*)(cpu->esp + 0x24u)) / (cpu->fpu[0u]);
    cpu->edx = cpu->esp + 0x70u;
    cpu->ecx = cpu->esp + 0x80u;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x1A8u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47742Du)); sfera_sub_0044EB00(cpu, LIFT_CODE_TOKEN_VA(0x47742Du));
    if (*(uint32_t*)(cpu->ebx + 0x134u) != cpu->esi) goto label_0007747A;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 8u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1E0u);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x10u));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477460u)); sfera_sub_0044ECA0(cpu, LIFT_CODE_TOKEN_VA(0x477460u));
    cpu->ecx = cpu->edi + 0x1D4u;
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47746Du)); sfera_sub_0044ED70(cpu, LIFT_CODE_TOKEN_VA(0x47746Du));
    cpu->esi <<= 24u;
    cpu->eax |= cpu->esi;
    *(uint32_t*)(cpu->ebx + 0x134u) = cpu->eax;
    cpu->esi = 0u;
    label_0007747A:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x30u) <= (int32_t)cpu->esi) goto label_00077DFA;
    lift_x87_push(cpu, (double)9.99999993922529e-09f);
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
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x68u));
    goto label_00077748;
    label_000774CD:
    cpu->esi = 0u;
    label_000774CF:
    cpu->eax = g_sfera_view_spatial_runtime.basis[3].z.u32;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x34u));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    lift_x87_push(cpu, (double)-1.0f);
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007750D;
    *(float*)(cpu->ebx + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00077546;
    label_0007750D:
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.lighting_state)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.0007999999797903001);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007753A;
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x34u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebx + 0x34u)));
    goto label_0007753C;
    label_0007753A:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0007753C:
    *(float*)(cpu->ebx + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x34u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00077546:
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x));
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->eax = cpu->esp;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->esp -= 0xCu;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)g_sfera_view_spatial_runtime.basis[3].z.f32));
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4775D7u)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x4775D7u));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4775DEu)); sfera_sub_00468750(cpu, LIFT_CODE_TOKEN_VA(0x4775DEu));
    cpu->edx = 0u;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_03 <= (int32_t)cpu->esi) goto label_0007729C;
    cpu->ebx = cpu->esp + 0xE8u;
    cpu->ebx &= 0xFFFFFFF0u;
    cpu->eax = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][4];
    label_00077600:
    cpu->edi = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xD8u) = cpu->edi;
    cpu->ecx = 0x10u;
    cpu->esi = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFFCu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xD8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax + 0xFFFFFFFCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 8u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18u));
    *(float*)(cpu->esp + 0x88u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18u));
    *(float*)(cpu->esp + 0x8Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18u));
    *(float*)(cpu->esp + 0x90u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFFCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x88u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x8Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x90u));
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFFCu));
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax)));
    ++cpu->edx;
    cpu->eax += 0x3Cu;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF0u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0xFFFFFFC8u)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF4u) = cpu->ecx;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00077600;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = 0u;
    goto label_0007729C;
    label_00077744:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x78u));
    label_00077748:
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00077774;
    lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], 9.99999993922529e-09);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00077778;
    label_00077774:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_00077778:
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00077DEA;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
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
    { uint64_t l=*(uint8_t*)(cpu->eax + 1u), r=0x7Au, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->esp + 0x70u) = 1u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000777C6;
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
    cpu->edi = *(uint16_t*)(cpu->ebp + 2u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x88u);
    cpu->edi += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)g_sfera_view_spatial_runtime.basis[2].x.f32));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477844u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x477844u));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x6Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)g_sfera_view_spatial_runtime.basis[2].y.f32));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477854u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x477854u));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x70u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)g_sfera_view_spatial_runtime.basis[2].z.f32));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477864u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x477864u));
    if ((int32_t)cpu->esi <= (int32_t)0xFFu) goto label_00077871;
    cpu->esi = 0xFFu;
    label_00077871:
    if ((int32_t)cpu->ebx <= (int32_t)0xFFu) goto label_0007787E;
    cpu->ebx = 0xFFu;
    label_0007787E:
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_0007788A;
    cpu->eax = 0xFFu;
    label_0007788A:
    { uint64_t l=cpu->esi, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->esi <<= 8u;
    { uint64_t l=cpu->esi, r=cpu->ecx, v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->esi <<= 8u;
    cpu->esi |= cpu->edx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x8Bu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4778B1u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x4778B1u));
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x84u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000778D5;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4778CDu)); sfera_sub_0047F230(cpu, LIFT_CODE_TOKEN_VA(0x4778CDu));
    { uint64_t v= cpu->eax & 0xFFu; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000778D5;
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), v=l ^ r; lift_flags_logic(cpu,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    goto label_000778D7;
    label_000778D5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    label_000778D7:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x134u);
    cpu->esi = cpu->eax;
    cpu->esi >>= 24u;
    { uint64_t v= cpu->ecx & 0xFFu; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00077917;
    cpu->ecx = cpu->eax;
    cpu->edx = cpu->eax;
    cpu->ecx >>= 16u;
    cpu->edx >>= 8u;
    cpu->ecx &= 0xFFu;
    { uint64_t l=cpu->edx, r=0xFFu, v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->esi);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi);
    { int64_t v=(int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->esi); cpu->eax= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
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
    { uint64_t l=*(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00077A73;
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
    { uint64_t l=*(uint32_t*)(cpu->edx + (cpu->esi * 4u)), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00077A73;
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
    { uint64_t l=*(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00077A73;
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
    { uint64_t l=*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00077A73;
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77A73u)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x77A73u));
    label_00077A73:
    *(uint32_t*)(cpu->esp + 0x18u) = *(uint32_t*)(cpu->esp + 0x18u) << 1u;
    cpu->edi += cpu->ebx;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00077940;
    label_00077A85:
    cpu->eax = *(uint16_t*)(cpu->ebp + 2u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x88u);
    cpu->esi = *(uint32_t*)(cpu->eax + cpu->ecx + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x6Cu) == cpu->esi) goto label_00077ABF;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477AA6u)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x477AA6u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477AB4u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x477AB4u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477ABBu)); sfera_sub_0049A4B0(cpu, LIFT_CODE_TOKEN_VA(0x477ABBu));
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->esi;
    label_00077ABF:
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0xAu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477AC8u)); sfera_sub_0044EFE0(cpu, LIFT_CODE_TOKEN_VA(0x477AC8u));
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
    lift_x87_push(cpu, 0.009999999776482582);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x70u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    cpu->eax += 8u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    label_00077B1A:
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFFCu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    if (cpu->esi == 0u) goto label_00077B82;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xFFFFFFF8u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xFFFFFFFCu)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0xFFFFFFF8u)));
    *(float*)(cpu->eax + 0xFFFFFFF8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFFCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x5Cu)));
    *(float*)(cpu->eax + 0xFFFFFFFCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x60u)));
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00077B82:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    ++cpu->edx;
    *(float*)(cpu->eax + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax += 0x20u;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x1Cu));
    cpu->ecx += 0x24u;
    *(float*)(cpu->eax + 0xFFFFFFF4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xFFFFFFE8u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFE4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0xFFFFFFE8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFECu) = cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->ebp + 0xAu);
    if ((int32_t)cpu->edx < (int32_t)cpu->edi) goto label_00077B1A;
    cpu->fpu[3u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
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
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xFFFFFFFCu));
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    *(float*)(cpu->eax + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
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
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477C56u)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x477C56u));
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
    { uint64_t l=*(uint32_t*)(cpu->eax), r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_texture_cache_runtime.upload_serial = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=g_sfera_main_render_runtime.secondary_render_pass, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00077CC9;
    cpu->esi = 0u;
    label_00077CC9:
    cpu->esi |= 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x3Cu) == 0u) goto label_00077CD6;
    cpu->esi |= 4u;
    label_00077CD6:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ebx == 0u) goto label_00077D14;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    lift_x87_push(cpu, 1.0);
    *(uint16_t*)(cpu->esp + 0x18u) = cpu->fpu_control;
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->eax = *(uint16_t*)(cpu->esp + 0x18u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (127.0);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Cu);
    *(uint64_t*)(cpu->esp + 0x1Cu) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx -= 0xFFFFFF80u;
    lift_push32(cpu, cpu->ecx);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Cu);
    goto label_00077D2E;
    label_00077D14:
    if (*(uint32_t*)(cpu->esp + 0x54u) != 0u) goto label_00077D29;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) != 0u) goto label_00077D29;
    if (*(uint32_t*)(cpu->esp + 0x14u) == 0u) goto label_00077D3B;
    label_00077D29:
    lift_push32(cpu, 0x80u);
    label_00077D2E:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77D3Bu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_RVA(0x77D3Bu));
    label_00077D3B:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477D42u)); sfera_sub_0044F0F0(cpu, LIFT_CODE_TOKEN_VA(0x477D42u));
    cpu->edx = cpu->edi + cpu->edi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_dynamic_index_scratch[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x477D4Cu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477D68u)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x477D68u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_texture_cache_runtime.upload_serial;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477DA0u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x477DA0u));
    g_sfera_client_config_runtime.state_07 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    if (cpu->ebx != 0u) goto label_00077DBC;
    if (*(uint32_t*)(cpu->esp + 0x54u) != cpu->ebx) goto label_00077DBC;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) != cpu->ebx) goto label_00077DBC;
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->ebx) goto label_00077DCB;
    label_00077DBC:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77DCBu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_RVA(0x77DCBu));
    label_00077DCB:
    cpu->eax = g_sfera_texture_cache_runtime.upload_serial;
    lift_x87_push(cpu, (double)9.99999993922529e-09f);
    g_sfera_main_input_state_runtime.timing_accumulator = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = 0u;
    label_00077DEA:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->edi + 0x30u)) goto label_00077493;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00077DFA:
    lift_push32(cpu, 0x44u);
    cpu->ecx = cpu->esp + 0xDCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x477E05u));
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0xE4u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0xE8u) = cpu->fpu[0u];
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0xE0u) = cpu->fpu[0u];
    cpu->edx = cpu->esp + 0xD8u;
    *(float*)(cpu->esp + 0xE4u) = cpu->fpu[0u];
    lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0xFCu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x100u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x104u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x11Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x108u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0xECu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0xF0u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0xF4u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0xF8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x477E7Fu)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x477E7Fu));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x77F55u)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x77F55u));
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
    lift_trap(cpu, 0x477FA7u, "INT3"); return;
}

} // namespace lifted
