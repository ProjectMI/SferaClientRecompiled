#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3750u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->edi + 0x48u)) != (uint8_t)(0u)) goto label_000C3970;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebp)) goto label_000C37AC;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_store32(cpu->esp + 0xCu, cpu->ebp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000C379E;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC379Eu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C379E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C379Eu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000C37AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C37ACu);
    cpu->edx = lift_load32(cpu->edi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->edi + 0x34u);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C37F8u); lift_push32(cpu, r); sfera_sub_004C3A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C37FFu); lift_push32(cpu, r); sfera_sub_004C3AC0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3816u); lift_push32(cpu, r); sfera_sub_004C3A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C381Du); lift_push32(cpu, r); sfera_sub_004C3AB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->edi + 0xDCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    { uint64_t l=cpu->esp, r=(uint64_t)(0x10u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx |= 0xFFFFFFu;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->edx = cpu->eax;
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C386Fu); lift_push32(cpu, r); sfera_sub_004CEE10(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = g_sfera_world_objects.controlled_object_handle;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000C396D;
    cpu->esi = lift_load32(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebp)) goto label_000C38BA;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000C38AC;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC38ACu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C38AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C38ACu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    label_000C38BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C38BAu);
    cpu->eax += 0x7Fu;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ecx += 0x84u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->esi = cpu->ebx;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000C38F1;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC38F1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000C38F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C38F1u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->edi + 0x194u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000C396D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->esp -= 0x14u;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->eax + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x5Cu, cpu->ecx);
    lift_x87_push(cpu, 28.0);
    lift_store32(cpu->eax + 0x7Cu, cpu->ecx);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    cpu->ecx = lift_load32(cpu->edi + 0x194u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC396Du); lift_push32(cpu, r); sfera_sub_004CEE60(cpu,r); if (cpu->eip != r) return; }
    label_000C396D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C396Du);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000C3970: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3970u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3980u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x1Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    lift_store32(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C39B9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C39C0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C39EE;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x15u); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C39ECu); lift_push32(cpu, r); sfera_sub_004DA880(cpu,r); if (cpu->eip != r) return; }
    goto label_000C39F0;
    label_000C39EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C39EEu);
    cpu->eax = 0u;
    label_000C39F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C39F0u);
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C3A08;
    cpu->ecx = (uint32_t)(uintptr_t)"SphereUI::CMinimapTexture::CMinimapTexture(): failed to create a texture";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC3A08u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000C3A08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3A08u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3A20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_minimap_texture_runtime.singleton;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C3A94;
    cpu->edx = (uint32_t)(cpu->eax + 0x54u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3A57u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3A5Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C3A8D;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3A78u); lift_push32(cpu, r); sfera_sub_004C3980(cpu,r); if (cpu->eip != r) return; }
    g_sfera_minimap_texture_runtime.singleton = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000C3A8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3A8Du);
    cpu->eax = 0u;
    g_sfera_minimap_texture_runtime.singleton = (uint32_t)(cpu->eax);
    label_000C3A94: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3A94u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3AB0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3AC0u);
    cpu->eax = 0x100u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3AD0u);
    if ((uint32_t)(g_sfera_minimap_texture_runtime.singleton) == (uint32_t)(0u)) goto label_000C3B39;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x5Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3AE9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_minimap_texture_runtime.singleton;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000C3B2E;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_000C3B1F;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x4Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3B08u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000C3B1E;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3B15u); lift_push32(cpu, r); sfera_sub_004DA4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3B1Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C3B1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B1Eu);
    cpu->edi = lift_pop32(cpu);
    label_000C3B1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B1Fu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3B2Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C3B2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B2Eu);
    g_sfera_minimap_texture_runtime.singleton = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    label_000C3B39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B39u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000C3B4B;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C3B4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B4Bu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC3B5Au), LIFT_CODE_TOKEN_RVA(0xC3B58u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B5Au);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C3B64;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C3B64: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B64u);
    lift_push32(cpu, (uintptr_t)"PERCENT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC3B6Cu), LIFT_CODE_TOKEN_RVA(0xC3B6Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B6Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C3B7B;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C3B7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B7Bu);
    lift_push32(cpu, (uintptr_t)"STYLE1"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC3B83u), LIFT_CODE_TOKEN_RVA(0xC3B81u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3B83u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFEu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 2u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3BA0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3BA8u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->eax = 0u;
    lift_store_f32(cpu->esi + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    lift_store32(cpu->esi + 0x1F0u, cpu->eax);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x1ACu, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::ProgressBar*>(cpu->esi));
    lift_store32(cpu->esi + 0x19Cu, 0x64u);
    lift_store32(cpu->esi + 0x50u, 4u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3C00u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C3DDD;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C3DDD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000C3C58;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C3C4A;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC3C4Au); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C3C4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3C4Au);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 8u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000C3C58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3C58u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C3D18;
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x1A4u)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000C3D18;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000C3CC9;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C3CC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3CC9u);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C3CEA;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C3CEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3CEAu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x1A4u))));
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3D10u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    label_000C3D18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3D18u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) <= (uint32_t)(0u)) goto label_000C3DD8;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1ECu)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3D34u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x1F0u))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3D47u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + 0x64u);
    cpu->edx = (uint32_t)(cpu->eax + 0x64u);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->eax);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ecx);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->edx);
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(0xFFu)) goto label_000C3D85;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C3D85;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3D7Au); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = g_sfera_screen_clip_runtime.left;
    cpu->eax = g_sfera_screen_clip_runtime.top;
    label_000C3D85: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3D85u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1ACu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3DB4u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(0xFFu)) goto label_000C3DDC;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C3DDC;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000C3DD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3DD8u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C3DDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3DDCu);
    cpu->edi = lift_pop32(cpu);
    label_000C3DDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3DDDu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3DF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esp + 4u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    lift_store32(cpu->esp + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(lift_load32(cpu->esp + 4u))))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 0x1A4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000C3E4B;
    lift_store_f32(cpu->esi + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000C3E4D;
    label_000C3E4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3E4Bu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C3E4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3E4Du);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C3E9E;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C3E77;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C3E9E;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d / %d");
    cpu->esi += 0x1ACu;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C3E6Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3E71u);
    cpu->esp += 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C3E77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3E77u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1A4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (100.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3E88u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d%%");
    cpu->esi += 0x1ACu;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C3E95u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3E9Bu);
    cpu->esp += 0xCu;
    label_000C3E9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3E9Eu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3EB0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFF82Fu);
    if ((uint32_t)(cpu->edx) > (uint32_t)(9u)) goto label_000C3F8D;
    cpu->eax += 0xFFFFF82Fu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000C3F88;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000C3EDF;
        case 1u: goto label_000C3F22;
        case 3u: goto label_000C3F54;
        case 9u: goto label_000C3F74;
        default: goto label_000C3F88;
    }
label_000C3EDF: ;
    cpu->edx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x1A0u)) == (uint32_t)(cpu->edx)) goto label_000C3F1A;
    cpu->eax = lift_load32(cpu->ecx + 0x198u);
    lift_store32(cpu->ecx + 0x1A0u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000C3F01;
    lift_store32(cpu->ecx + 0x1A0u, cpu->eax);
    label_000C3F01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F01u);
    cpu->eax = lift_load32(cpu->ecx + 0x19Cu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1A0u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000C3F15;
    lift_store32(cpu->ecx + 0x1A0u, cpu->eax);
    label_000C3F15: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F15u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC3F1Au); lift_push32(cpu, r); sfera_sub_004C3DF0(cpu,r); if (cpu->eip != r) return; }
    label_000C3F1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F1Au);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C3F22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F22u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->ecx + 0x198u, cpu->eax);
    lift_store32(cpu->ecx + 0x19Cu, cpu->edx);
    lift_store32(cpu->ecx + 0x1A0u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000C3F15;
    ++cpu->eax;
    lift_store32(cpu->ecx + 0x19Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3F4Cu); lift_push32(cpu, r); sfera_sub_004C3DF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C3F54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F54u);
    cpu->edx = lift_load32(cpu->ecx + 0x198u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 0x19Cu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C3F74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F74u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A0u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C3F88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F88u);
    cpu->eax = 0u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C3F8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3F8Du);
    lift_store32(cpu->esp + 4u, cpu->eax);
    sfera_sub_004D2DD0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3FC0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3FD9u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) != (uint32_t)(0u)) goto label_000C3FFC;
    lift_push32(cpu, 0x6Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ProgressBar.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3FF3u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3FF9u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C3FFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3FFCu);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"drawMethod");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C400Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C40AE;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4023u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C40AE;
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"SPRITE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xC403Du), LIFT_CODE_TOKEN_RVA(0xC403Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C403Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C4097;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4052u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C40AE;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4066u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x194u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C40AE;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ProgressBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C408Cu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4092u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    goto label_000C40AE;
    label_000C4097: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4097u);
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xC40A3u), LIFT_CODE_TOKEN_RVA(0xC40A1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C40A3u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C40AE;
    lift_store32(cpu->esi + 0x24u, (uint64_t)(lift_load32(cpu->esi + 0x24u)) | (uint64_t)(2u));
    label_000C40AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C40AEu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"statusShow");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C40BBu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C40E1;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C40CDu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C40E1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C40DBu); lift_push32(cpu, r); sfera_sub_004C3B40(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    label_000C40E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C40E1u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"range");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C40EEu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C4156;
    cpu->ebx = (uint32_t)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebp = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C4109u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C410Fu);
    cpu->esp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(2u)) goto label_000C413A;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ProgressBar::LoadUI(%s,%d,%d) -> Not enough args in 'range'.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4131u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4137u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C413A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C413Au);
    cpu->eax = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C4148;
    lift_store32(cpu->ebp, cpu->ecx);
    lift_store32(cpu->ebx, cpu->eax);
    label_000C4148: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4148u);
    cpu->eax = lift_load32(cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C4156;
    ++cpu->eax;
    lift_store32(cpu->ebx, cpu->eax);
    label_000C4156: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4156u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"progressPos");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4163u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C419A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4170u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C4186;
    lift_store32(cpu->esi + 0x1A0u, cpu->ecx);
    label_000C4186: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4186u);
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1A0u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000C419A;
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    label_000C419A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C419Au);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"statusPos");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C41A7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C41F0;
    cpu->edx = (uint32_t)(cpu->esi + 0x1F0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1ECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C41C2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C41C8u);
    cpu->esp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(2u)) goto label_000C41F0;
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ProgressBar::LoadUI(%s,%d,%d) -> Not enough args in 'statusPos'.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C41E7u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C41EDu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C41F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C41F0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C41F7u); lift_push32(cpu, r); sfera_sub_004C3DF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4203u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4220u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C422Fu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1A0u);
    lift_store32(cpu->esi + 0x1A0u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1A4u));
    lift_store_f32(cpu->esi + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->edi + 0x1A8u);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x1ACu);
    cpu->ecx -= cpu->esi;
    cpu->ebp = 0x40u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000C4280: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4280u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C4280;
    cpu->eax = lift_load32(cpu->edi + 0x1ECu);
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1F0u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1F0u, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C42B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C42B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xD9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ProgressBar.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C42E4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C42EEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C430C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4308u); lift_push32(cpu, r); sfera_sub_004C3BA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000C430E;
    label_000C430C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C430Cu);
    cpu->esi = 0u;
    label_000C430E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C430Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C431Eu); lift_push32(cpu, r); sfera_sub_004C4220(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000C4346;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4338u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC4346u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C4346: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4346u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4360u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A8u)) != (uint8_t)(0u)) goto label_000C438C;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C438C;
    cpu->edx = lift_load32(cpu->esi + 0x3Cu);
    lift_push32(cpu, 8u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x3EAu); lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    label_000C438C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C438Cu);
    lift_store8(cpu->esi + 0x1A8u, 0u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004A1350(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C43A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C43A0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C43A8u); lift_push32(cpu, r); sfera_sub_004A0E60(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::RadioButtonCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C43C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C43C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x56u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\RadioButton.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C43F4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C43FEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000C4429;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C441Au); lift_push32(cpu, r); sfera_sub_004A0E60(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::RadioButtonCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 8u);
    goto label_000C442B;
    label_000C4429: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4429u);
    cpu->esi = 0u;
    label_000C442B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C442Bu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C443Bu); lift_push32(cpu, r); sfera_sub_004A1690(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000C4463;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4455u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC4463u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C4463: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4463u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4480u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4497u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"scrollbar");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C44AFu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C44D7;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C44C9u); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1CCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC44D7u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C44D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C44D7u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C44E3u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C44F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C44F0u);
    cpu->esp -= 8u;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->esi + 0x1C0u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)"_";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4513u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x1BCu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C452D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C452D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C452Du);
    cpu->eax = lift_load32(cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C453B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C453B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C453Bu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4550u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp += 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    cpu->edi = lift_pop32(cpu);
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    lift_store64(cpu->esp + 4u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xCu));
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C45A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C45A0u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = lift_load32(cpu->ecx + 0x198u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x10u);
    lift_store32(cpu->ecx + 0x1ACu, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C45C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C45C0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0x1CCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C4668;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi + 0x19Cu);
    cpu->esi -= lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->edi + 0x1C4u);
    cpu->esi = (uint32_t)(cpu->edx + 1u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->esi)) goto label_000C4632;
    cpu->eax -= cpu->edx;
    cpu->ebx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    label_000C4632: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4632u);
    cpu->eax = lift_load32(cpu->edi + 0x1C8u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x18u, 0u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esp + 0x14u, 0x17u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4666u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C4668: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4668u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C46D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C46D0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x1ACu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ecx + 0x1ACu, v); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C470F;
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C4705;
    cpu->edi = lift_load32(cpu->ecx + 0x198u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->edx = lift_load32(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFF4u);
    --cpu->eax;
    lift_store32(cpu->ecx + 0x1ACu, cpu->edx);
    lift_store32(cpu->ecx + 0x1A8u, cpu->eax);
    goto label_000C470F;
    label_000C4705: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4705u);
    lift_store32(cpu->ecx + 0x1ACu, 0u);
    label_000C470F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C470Fu);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C4723;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4723: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4723u);
    cpu->edx = lift_load32(cpu->ecx + 0x1C4u);
    cpu->edi = lift_load32(cpu->ecx + 0x1C8u);
    cpu->edi += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C473E;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C473E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C473Eu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C4751;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C4751: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4751u);
    sfera_sub_004C45C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4760u);
    lift_store32(cpu->ecx + 0x1ACu, (uint64_t)(lift_load32(cpu->ecx + 0x1ACu)) + 1u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x1A8u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 8u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x198u);
    cpu->edx -= cpu->esi;
    cpu->ebx = lift_load32(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0x10u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x1ACu)) <= (uint32_t)(cpu->ebx)) goto label_000C47C8;
    cpu->edi = lift_load32(cpu->ecx + 0x19Cu);
    cpu->edi -= lift_load32(cpu->ecx + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edx)) goto label_000C47C2;
    ++cpu->esi;
    lift_store32(cpu->ecx + 0x1ACu, 0u);
    lift_store32(cpu->ecx + 0x1A8u, cpu->esi);
    goto label_000C47C8;
    label_000C47C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C47C2u);
    lift_store32(cpu->ecx + 0x1ACu, cpu->ebx);
    label_000C47C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C47C8u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C47DC;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C47DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C47DCu);
    cpu->edx = lift_load32(cpu->ecx + 0x1C4u);
    cpu->esi = lift_load32(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    cpu->edi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C47F9;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C47F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C47F9u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C480C;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C480C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C480Cu);
    sfera_sub_004C45C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4820u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    lift_push32(cpu, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C485E;
    cpu->esi = lift_load32(cpu->ecx + 0x1ACu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000C4857;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x198u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFE4u);
    cpu->edx = lift_load32(cpu->edx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(cpu->edx)) goto label_000C4857;
    lift_store32(cpu->ecx + 0x1ACu, cpu->edx);
    label_000C4857: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4857u);
    --cpu->eax;
    lift_store32(cpu->ecx + 0x1A8u, cpu->eax);
    label_000C485E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C485Eu);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C4872;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4872: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4872u);
    cpu->edx = lift_load32(cpu->ecx + 0x1C4u);
    cpu->esi = lift_load32(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C488D;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C488D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C488Du);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C48A0;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C48A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C48A0u);
    sfera_sub_004C45C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C48B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C48B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x19Cu);
    cpu->esi -= lift_load32(cpu->ecx + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x1A8u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_000C4910;
    cpu->edx = lift_load32(cpu->ecx + 0x1ACu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000C4909;
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->esi -= cpu->eax;
    cpu->eax = lift_load32(cpu->ecx + 0x198u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(cpu->eax)) goto label_000C4909;
    lift_store32(cpu->ecx + 0x1ACu, cpu->eax);
    label_000C4909: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4909u);
    ++cpu->edi;
    lift_store32(cpu->ecx + 0x1A8u, cpu->edi);
    label_000C4910: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4910u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C4924;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4924: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4924u);
    cpu->edx = lift_load32(cpu->ecx + 0x1C4u);
    cpu->esi = lift_load32(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    cpu->edi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C4940;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4940: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4940u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C4953;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C4953: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4953u);
    sfera_sub_004C45C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4960u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x1C4u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x1A8u)), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->ecx + 0x1A8u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C4979;
    lift_store32(cpu->ecx + 0x1A8u, 0u);
    label_000C4979: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4979u);
    cpu->edx = lift_load32(cpu->ecx + 0x1ACu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000C49AA;
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ebx -= cpu->eax;
    cpu->eax = lift_load32(cpu->ecx + 0x198u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 4u));
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(cpu->eax)) goto label_000C49AA;
    lift_store32(cpu->ecx + 0x1ACu, cpu->eax);
    label_000C49AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C49AAu);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C49BE;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C49BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C49BEu);
    cpu->edx = lift_load32(cpu->ecx + 0x1C8u);
    cpu->edx += cpu->esi;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000C49D2;
    cpu->eax -= cpu->esi;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C49D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C49D2u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x1C8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000C49E6;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C49E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C49E6u);
    sfera_sub_004C45C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C49F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C49F0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + 0x1C4u);
    lift_store32(cpu->ecx + 0x1A8u, (uint64_t)(lift_load32(cpu->ecx + 0x1A8u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x19Cu);
    cpu->esi -= lift_load32(cpu->ecx + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x1A8u)) <= (uint32_t)(cpu->edx)) goto label_000C4A30;
    --cpu->eax;
    lift_store32(cpu->ecx + 0x1A8u, cpu->eax);
    label_000C4A30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4A30u);
    cpu->edx = lift_load32(cpu->ecx + 0x1ACu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000C4A5F;
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->esi -= cpu->eax;
    cpu->eax = lift_load32(cpu->ecx + 0x198u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(cpu->eax)) goto label_000C4A5F;
    lift_store32(cpu->ecx + 0x1ACu, cpu->eax);
    label_000C4A5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4A5Fu);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C4A73;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4A73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4A73u);
    cpu->edx = lift_load32(cpu->ecx + 0x1C8u);
    cpu->edx += cpu->ebx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000C4A87;
    cpu->eax -= cpu->ebx;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4A87: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4A87u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x1C8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000C4A9D;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C4A9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4A9Du);
    sfera_sub_004C45C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4AB0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1B4u)), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C4AD5;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4AC9u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->edx);
    label_000C4AD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4AD5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4ADAu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1B0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1B4u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 8u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000C4B24;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4B14u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->edx);
    label_000C4B24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4B24u);
    lift_x87_push(cpu, 0.4000000059604645);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000C4B6C;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 4u))) / (lift_x87_get(cpu, 0u)));
    lift_store16(cpu->esp + 4u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 4u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 8u));
    lift_store32(cpu->esp + 8u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 8u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    lift_store8(cpu->esi + 0x1B8u, cpu->ecx & 0xFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    goto label_000C4B70;
    label_000C4B6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4B6Cu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C4B70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4B70u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x4Au)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C4C18;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1B8u)) == (uint8_t)(0u)) goto label_000C4C18;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000C4BA3;
    cpu->eax = lift_load32(cpu->eax);
    label_000C4BA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4BA3u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    cpu->ecx -= 2u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4BC5u); lift_push32(cpu, r); sfera_sub_004A5330(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"_");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4BF2u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C4C06;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C4C06: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4C06u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4C0Fu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC4C18u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    label_000C4C18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4C18u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4C20u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = 0u;
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000C4D4A;
    if ((uint32_t)(cpu->edi) == (uint32_t)(1u)) goto label_000C4D77;
    cpu->ecx = lift_load32(cpu->ebp + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->ebp + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C4D77;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store8(cpu->ecx, 0u);
    cpu->ecx = lift_load32(cpu->ebp + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->ebp + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C4D4A;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->edi = cpu->edi;
    label_000C4CA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4CA0u);
    cpu->eax = lift_load32(cpu->ebp + 0x198u);
    cpu->eax += lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000C4CB2;
    cpu->eax = lift_load32(cpu->eax);
    label_000C4CB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4CB2u);
    cpu->ecx = cpu->eax;
    cpu->edi = (uint32_t)(cpu->ecx + 1u);
    label_000C4CB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4CB7u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C4CB7;
    cpu->ecx -= cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->esi + 1u);
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(cpu->edi)) goto label_000C4D53;
    cpu->ecx = cpu->eax;
    label_000C4CD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4CD2u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C4CD2;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    label_000C4CE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4CE4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C4CE4;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000C4D00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4D00u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000C4D00;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    lift_store16(cpu->edi, cpu->ecx & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->ebp + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->ebp + 0x198u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    ++cpu->edi;
    cpu->eax += cpu->edx;
    cpu->esi = cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_000C4CA0;
    cpu->ebx = lift_pop32(cpu);
    label_000C4D4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4D4Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_000C4D53: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4D53u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi -= cpu->esi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4C4D5Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4D64u);
    cpu->esp += 0xCu;
    cpu->edi += cpu->esi;
    lift_store8(cpu->edi + cpu->ebx, 0u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_000C4D77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4D77u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->edx, 0u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C4D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4D90u);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000C510D;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C510D;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000C4DF6;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000C4DE8;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC4DE8u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C4DE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4DE8u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    label_000C4DF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4DF6u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4E23u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4E3Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000C4E52;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C4E52: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4E52u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4E5Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C4E70;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C4E70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4E70u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4E77u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = 0u;
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4ECCu); lift_push32(cpu, r); sfera_sub_004D8990(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->ebx = lift_load32(cpu->esp + 0x40u);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ebx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C4EE6;
    cpu->edi = cpu->eax;
    label_000C4EE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4EE6u);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ebx)) goto label_000C4EEC;
    cpu->ebp = cpu->ebx;
    label_000C4EEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4EECu);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->ebx + cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C4EFB;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000C4EFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4EFBu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000C4F0A;
    cpu->edx -= cpu->ebp;
    cpu->eax = cpu->edx;
    label_000C4F0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4F0Au);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000C4F12;
    cpu->ebx += cpu->edi;
    cpu->edi = 0u;
    label_000C4F12: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4F12u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000C4F1A;
    cpu->eax += cpu->ebp;
    cpu->ebp = 0u;
    label_000C4F1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4F1Au);
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    cpu->edx = (uint32_t)(cpu->ebx + cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C4F2B;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000C4F2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4F2Bu);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C4F3C;
    cpu->ecx -= cpu->ebp;
    cpu->eax = cpu->ecx;
    label_000C4F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4F3Cu);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_x87_push(cpu, 1.0);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C4F68u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(0xFFu)) goto label_000C4F84;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C4F84;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC4F84u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000C4F84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4F84u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->ecx -= lift_load32(cpu->esi + 0x198u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C5046;
    cpu->ecx = lift_load32(cpu->esi + 0x1C8u);
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    cpu->eax -= cpu->ecx;
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->edx)) goto label_000C4FC8;
    cpu->eax = cpu->edx;
    label_000C4FC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4FC8u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C5046;
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edi -= cpu->ecx;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->ebx = cpu->eax;
    (void)cpu;
    label_000C4FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4FE0u);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    cpu->eax += cpu->edi;
    cpu->edi += 0x1Cu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000C4FF3;
    cpu->eax = lift_load32(cpu->eax);
    label_000C4FF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4FF3u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C501Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5025u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x1C0u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1C0u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C503B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C503B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C503Bu);
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C4FE0;
    label_000C5046: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5046u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->eax -= lift_load32(cpu->esi + 0x1C8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x1C0u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C506B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C506B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C506Bu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    cpu->esp -= 8u;
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C508Cu); lift_push32(cpu, r); sfera_sub_004C4AB0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xDCu)), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C50AD;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C50AD;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC50ADu); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000C50AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C50ADu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C50BDu); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C510D;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000C5100;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C50E9;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C50E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C50E9u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000C5100: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5100u);
    cpu->ecx = lift_load32(cpu->esi + 0x1CCu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000C510D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C510Du);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5120u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x60u);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    cpu->edx = lift_load32(cpu->edi + 0x198u);
    cpu->esi -= cpu->eax;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->eax -= cpu->ecx;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ebx = 0u;
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ecx)) goto label_000C5198;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    goto label_000C519C;
    label_000C5198: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5198u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000C519C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C519Cu);
    lift_store8(cpu->esp + 0x19u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x44u, 0xFu);
    lift_store32(cpu->esp + 0x40u, cpu->ebp);
    lift_store8(cpu->esp + 0x30u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x58u, cpu->ebp);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(cpu->ecx)) goto label_000C51BD;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_000C51BF;
    label_000C51BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C51BDu);
    cpu->ecx = cpu->esi;
    label_000C51BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C51BFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load8(cpu->edi + 0x8Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->edi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C51DDu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C52E7;
    label_000C51F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C51F0u);
    cpu->ecx = lift_load8(cpu->edi + 0x8Du);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->edi + 0x8Cu);
    lift_store8(cpu->esp + 0x1Cu, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C521Au); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x1BCu);
    cpu->edx += lift_load32(cpu->esp + 0x28u);
    cpu->edx += lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(lift_load32(cpu->edi + 0x28u))) goto label_000C52BB;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x18u)) & 0xFFu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax -= cpu->ebp;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_000C532B;
    cpu->esi = (uint32_t)(cpu->ebp + 1u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFFFFEu)) goto label_000C532B;
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_000C530A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5266u); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000C529D;
    label_000C5272: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5272u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C527F;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    label_000C527F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C527Fu);
    lift_store8(cpu->eax + cpu->ebp, cpu->ebx & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x44u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C5295;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    label_000C5295: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5295u);
    lift_store8(cpu->eax + cpu->esi, 0u);
    label_000C5299: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5299u);
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    label_000C529D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C529Du);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000C51F0;
    label_000C52BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C52BBu);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000C52D3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC52D3u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    label_000C52D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C52D3u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x44u)) < (uint32_t)(0x10u)) goto label_000C52E7;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C52E4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C52E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C52E7u);
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 8u, stop_address); return;
    label_000C530A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C530Au);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000C5272;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C5323;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    label_000C5323: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5323u);
    lift_store8(cpu->eax, 0u);
    goto label_000C5299;
    label_000C532B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C532Bu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    lift_trap(cpu, 0x4C5336u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5340u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = lift_load32(cpu->esp + 0x4Cu);
    cpu->edi = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->ecx -= cpu->edi;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ebx = cpu->edx;
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(0x1Fu), 32u);
    cpu->ebx += cpu->edx;
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->edi;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000C53D1;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000C53C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C53C0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->esi, 32u, 1u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esi = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_000C53C0;
    label_000C53D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C53D1u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C54C3;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C54C3;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebx) * 8u));
    cpu->ecx -= cpu->ebx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->esi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    goto label_000C5410;
    label_000C5404: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5404u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_000C5410: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5410u);
    cpu->ecx += cpu->esi;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_000C5418;
    cpu->ecx = cpu->edi;
    label_000C5418: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5418u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_000C546C;
    cpu->ebp = lift_load32(cpu->esi + 0xCu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx);
    lift_store32(cpu->esi, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esi + 4u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esi + 8u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->esi + 0xCu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->edi);
    lift_store32(cpu->ecx + 0xCu, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    label_000C546C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C546Cu);
    cpu->edi = cpu->ebp;
    cpu->edi -= cpu->ecx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000C548F;
    cpu->ecx += lift_load32(cpu->esp + 0x1Cu);
    goto label_000C54A3;
    label_000C548F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C548Fu);
    cpu->ecx = cpu->ebx;
    cpu->ecx -= cpu->eax;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->eax -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    label_000C54A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C54A3u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000C5418;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) - (uint64_t)(0x1Cu) - (uint64_t)(0u));
    --cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000C5404;
    label_000C54C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C54C3u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C54F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C54F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::RichEditCtrl*>(cpu->esi));
    cpu->edi = 0u;
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(cpu->edi);
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1CCu)) == (uint32_t)(cpu->edi)) goto label_000C555F;
    cpu->edx = 0x8Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\RichEditCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5546u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000C5559;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000C5559: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5559u);
    lift_store32(cpu->esi + 0x1CCu, cpu->edi);
    label_000C555F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C555Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000C558F;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5580u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C558Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C558F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C558Fu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x198u, cpu->edi);
    lift_store32(cpu->esi + 0x19Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1A0u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C55B0u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C55D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000C55D0;
    label_000C4680: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4680u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C4694;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4694: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4694u);
    cpu->edx = lift_load32(cpu->ecx + 0x1C4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C46B0;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C46B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C46B0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C46C3;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C46C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C46C3u);
    sfera_sub_004C45C0(cpu, stop_address); return;
    label_000C55D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C55D0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi + 0x1A8u);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebx) * 8u));
    cpu->ecx -= cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x10u)) <= (uint32_t)(cpu->ebp)) goto label_000C56D1;
    cpu->eax = lift_load32(cpu->esi + 0x1ACu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_000C56C0;
    cpu->ebp = lift_load32(cpu->esi + 0x19Cu);
    cpu->ebp -= lift_load32(cpu->esi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_000C578F;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000C578F;
    cpu->ebp = lift_load32(cpu->ecx + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->ebx);
    --cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5645u); lift_push32(cpu, r); sfera_sub_004C5120(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C56A6;
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5669u); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0x10u)) != (uint32_t)(0u)) goto label_000C56A6;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C5695;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    label_000C5695: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5695u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC56A6u); lift_push32(cpu, r); sfera_sub_0040B7D0(cpu,r); if (cpu->eip != r) return; }
    label_000C56A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C56A6u);
    lift_store32(cpu->esi + 0x1A8u, (uint64_t)(lift_load32(cpu->esi + 0x1A8u)) - 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1ACu, cpu->ebp);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000C4680;
    label_000C56C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C56C0u);
    --cpu->eax;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C56CFu); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    goto label_000C5745;
    label_000C56D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C56D1u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000C573F;
    cpu->ecx = cpu->ebx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C56F7u); lift_push32(cpu, r); sfera_sub_0040A270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5711u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x19Cu, (uint64_t)(lift_load32(cpu->esi + 0x19Cu)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x1A8u, (uint64_t)(lift_load32(cpu->esi + 0x1A8u)) - 1u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x10u);
    lift_store32(cpu->esi + 0x1ACu, cpu->ecx);
    goto label_000C5745;
    label_000C573F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C573Fu);
    lift_store32(cpu->esi + 0x1ACu, cpu->ebp);
    label_000C5745: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5745u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u))) goto label_000C5759;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C5759: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5759u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000C5773;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C5773: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5773u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u)) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_000C5781;
    lift_store32(cpu->esi + 0x1C8u, cpu->ebp);
    label_000C5781: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5781u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004C45C0(cpu, stop_address); return;
    label_000C578F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C578Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C57A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000C57A0;
    label_000C4680: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4680u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u))) goto label_000C4694;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C4694: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C4694u);
    cpu->edx = lift_load32(cpu->ecx + 0x1C4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C46B0;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->ecx + 0x1C8u, cpu->eax);
    label_000C46B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C46B0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C46C3;
    lift_store32(cpu->ecx + 0x1C8u, 0u);
    label_000C46C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C46C3u);
    sfera_sub_004C45C0(cpu, stop_address); return;
    label_000C57A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C57A0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x1A8u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->eax -= cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C57DC;
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000C57DC;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C57D7u); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    goto label_000C5937;
    label_000C57DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C57DCu);
    cpu->ecx = lift_load32(cpu->esi + 0x1ACu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_000C58C2;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C58C2;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_000C58C2;
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5823u); lift_push32(cpu, r); sfera_sub_004C5120(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C58B5;
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    ++cpu->eax;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C584Cu); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0x2Cu)) != (uint32_t)(0u)) goto label_000C58B5;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C5880;
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0x1Cu);
    label_000C5880: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5880u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx += 0x1Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5894u); lift_push32(cpu, r); sfera_sub_0040A270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C58AEu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x19Cu, (uint64_t)(lift_load32(cpu->esi + 0x19Cu)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u));
    label_000C58B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C58B5u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000C4680;
    label_000C58C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C58C2u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C5937;
    --cpu->eax;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000C5937;
    cpu->eax = cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000C58F8;
    cpu->ecx = cpu->edi;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    label_000C58F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C58F8u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C590Cu); lift_push32(cpu, r); sfera_sub_0040A270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5926u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x19Cu, (uint64_t)(lift_load32(cpu->esi + 0x19Cu)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x1ACu, 0u);
    label_000C5937: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5937u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u))) goto label_000C594B;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C594B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C594Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000C5965;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C5965: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5965u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C5978;
    lift_store32(cpu->esi + 0x1C8u, 0u);
    label_000C5978: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5978u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004C45C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5990u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5998u); lift_push32(cpu, r); sfera_sub_004C54F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C59A8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C59A5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C59A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C59A8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C59B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C59B0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C59BEu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C59D0u); lift_push32(cpu, r); sfera_sub_004C3290(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x1A8u);
    lift_store32(cpu->esi + 0x1A8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1B0u);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    lift_store32(cpu->esi + 0x1B4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1B8u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1B8u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->edi + 0x1BCu);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1C0u);
    lift_store32(cpu->esi + 0x1C0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1C4u);
    lift_store32(cpu->esi + 0x1C4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1CCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1CCu, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5A50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000C5AD2;
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->esi)) goto label_000C5AD2;
    cpu->esi -= cpu->eax;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000C5AA9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5AA9u); lift_push32(cpu, r); sfera_sub_00411060(cpu,r); if (cpu->eip != r) return; }
    label_000C5AA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5AA9u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi) * 8u));
    cpu->eax -= cpu->esi;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000C5B0E;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    goto label_000C5AFD;
    label_000C5AD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5AD2u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000C5AE0;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5AE0u); lift_push32(cpu, r); sfera_sub_00411060(cpu,r); if (cpu->eip != r) return; }
    label_000C5AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5AE0u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000C5B0E;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    label_000C5AFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5AFDu);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    lift_store8(cpu->ecx, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5B0Eu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000C5B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5B0Eu);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5B30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx -= lift_load32(cpu->esi);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ebp = cpu->edx;
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(0x1Fu), 32u);
    cpu->ebp += cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000C5B83;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5B83u); lift_push32(cpu, r); sfera_sub_00411060(cpu,r); if (cpu->eip != r) return; }
    label_000C5B83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5B83u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000C5BC0;
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    cpu->eax = cpu->edi;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000C5BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5BB0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C5BB0;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5BC0u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000C5BC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5BC0u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp) * 8u));
    cpu->edi -= cpu->ebp;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFE4u);
    cpu->ecx += cpu->edi;
    lift_store32(cpu->esp + 0x24u, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000C5BF5;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000C5BF5;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5BF5u); lift_push32(cpu, r); sfera_sub_004C5340(cpu,r); if (cpu->eip != r) return; }
    label_000C5BF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5BF5u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx += cpu->edi;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5C20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx -= lift_load32(cpu->esi);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ebp = cpu->edx;
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(0x1Fu), 32u);
    cpu->ebp += cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000C5C72;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5C72u); lift_push32(cpu, r); sfera_sub_00411060(cpu,r); if (cpu->eip != r) return; }
    label_000C5C72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5C72u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C5CA8;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ecx, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5CA8u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000C5CA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5CA8u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp) * 8u));
    cpu->edi -= cpu->ebp;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFE4u);
    cpu->ecx += cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000C5CDD;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000C5CDD;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5CDDu); lift_push32(cpu, r); sfera_sub_004C5340(cpu,r); if (cpu->eip != r) return; }
    label_000C5CDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5CDDu);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx += cpu->edi;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5D00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5D3Bu); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::RichEditCtrl*>(cpu->esi));
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store8(cpu->esp + 0x40u, 1u);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    lift_store32(cpu->esi + 0x1CCu, cpu->eax);
    lift_store32(cpu->esi + 0x50u, 0x11u);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x4Au, cpu->eax & 0xFFu);
    lift_store32(cpu->esp + 0x2Cu, 0xFu);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store8(cpu->esp + 0x18u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5DC0u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_store8(cpu->esp + 0x3Cu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5DD5u); lift_push32(cpu, r); sfera_sub_004C5A50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) < (uint32_t)(0x10u)) goto label_000C5DE9;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5DE6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C5DE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5DE9u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5E10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x6Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\RichEditCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5E44u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5E4Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C5E6C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5E68u); lift_push32(cpu, r); sfera_sub_004C5D00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000C5E6E;
    label_000C5E6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5E6Cu);
    cpu->esi = 0u;
    label_000C5E6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5E6Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5E7Eu); lift_push32(cpu, r); sfera_sub_004C59B0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000C5EA6;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5E98u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5EA6u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C5EA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5EA6u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1CCu)) == (uint32_t)(0u)) goto label_000C5ECA;
    cpu->ecx = lift_load32(cpu->edi + 0x1CCu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5EBCu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1CCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC5ECAu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C5ECA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5ECAu);
    cpu->eax = lift_load8(cpu->edi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5ED9u); lift_push32(cpu, r); sfera_sub_004C44F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5EE0u); lift_push32(cpu, r); sfera_sub_004C45C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C5F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5F00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x60u)) & 0xFFu);
    cpu->esi = lift_load32(cpu->ecx + 0x198u);
    cpu->ebx = lift_load32(cpu->esp + 0x64u);
    cpu->ebp = (uint32_t)(cpu->ecx + 0x198u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->ecx -= cpu->esi;
    lift_store8(cpu->esp + 0x14u, cpu->eax & 0xFFu);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    lift_store8(cpu->esp + 0x15u, 0u);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->ecx)) goto label_000C5FD5;
    cpu->esi = 0u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x40u, 0xFu);
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_store8(cpu->esp + 0x2Cu, 0u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000C5F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5F90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C5F90;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5FA8u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5FB8u); lift_push32(cpu, r); sfera_sub_004C5A50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x40u)) < (uint32_t)(0x10u)) goto label_000C60A1;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5FCDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000C60A1;
    label_000C5FD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C5FD5u);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    cpu->eax = lift_load32(cpu->esp + 0x5Cu);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebx) * 8u));
    cpu->edi -= cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edi += cpu->edi;
    lift_push32(cpu, 1u);
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C5FF6u); lift_push32(cpu, r); sfera_sub_0048E480(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebp);
    cpu->esi += cpu->edi;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(0u)) goto label_000C60A1;
    label_000C6005: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6005u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C600F;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_000C6011;
    label_000C600F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C600Fu);
    cpu->ecx = cpu->esi;
    label_000C6011: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6011u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load8(cpu->eax + 0x8Du);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->eax + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6033u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 0x1BCu);
    cpu->ecx += lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->eax + 0x28u))) goto label_000C60A1;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C6050;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_000C6052;
    label_000C6050: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6050u);
    cpu->ecx = cpu->esi;
    label_000C6052: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6052u);
    cpu->eax = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    label_000C6060: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6060u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C6060;
    cpu->eax -= lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->ecx + 0xFFFFFFFFu)) & 0xFFu);
    --cpu->eax;
    lift_push32(cpu, 1u);
    lift_store8(cpu->esp + 0x24u, cpu->ecx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C607Eu); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->ebx + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6092u); lift_push32(cpu, r); sfera_sub_004C5F00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebp);
    cpu->esi += cpu->edi;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) != (uint32_t)(0u)) goto label_000C6005;
    label_000C60A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C60A1u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C60D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C60D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x70u);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->edi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C6167;
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C6167;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6146u); lift_push32(cpu, r); sfera_sub_0040A270(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x19Cu);
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6161u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x19Cu, cpu->ebp);
    label_000C6167: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6167u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x38u, 0xFu);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    lift_store8(cpu->esp + 0x24u, 0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x68u, cpu->ebp);
    lift_store8(cpu->esp + 0x19u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C622D;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000C6190: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6190u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx)) & 0xFFu);
    ++cpu->ebx;
    lift_store8(cpu->esp + 0x14u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_000C61A2;
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    goto label_000C61DE;
    label_000C61A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C61A2u);
    cpu->edx = lift_load8(cpu->edi + 0x8Du);
    lift_store8(cpu->esp + 0x18u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->edi + 0x8Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C61C8u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x1BCu);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    cpu->eax += cpu->ebp;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->edi + 0x28u))) goto label_000C61FD;
    lift_push32(cpu, cpu->ecx);
    label_000C61DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C61DEu);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C61E9u); lift_push32(cpu, r); sfera_sub_004C5A50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C61F9u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    goto label_000C620D;
    label_000C61FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C61FDu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6209u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp += lift_load32(cpu->esp + 0x1Cu);
    label_000C620D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C620Du);
    if ((uint8_t)(lift_load8(cpu->ebx)) != (uint8_t)(0u)) goto label_000C6190;
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) <= (uint32_t)(0u)) goto label_000C622D;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC622Du); lift_push32(cpu, r); sfera_sub_004C5A50(cpu,r); if (cpu->eip != r) return; }
    label_000C622D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C622Du);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->edi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebx = 0x10u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C62A5;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x5Cu, 0xFu);
    lift_store32(cpu->esp + 0x58u, 0u);
    lift_store8(cpu->esp + 0x48u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6278u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_store8(cpu->esp + 0x6Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C628Du); lift_push32(cpu, r); sfera_sub_004C5A50(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x68u, 0u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x54u)) < (uint32_t)(cpu->ebx)) goto label_000C62A5;
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C62A2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C62A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C62A5u);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->edi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 0xFFFFFFFFu);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    lift_store32(cpu->edi + 0x1A8u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x10u);
    cpu->eax = lift_load32(cpu->edi + 0x1A8u);
    lift_store32(cpu->edi + 0x1ACu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x1C8u))) goto label_000C62F9;
    lift_store32(cpu->edi + 0x1C8u, cpu->eax);
    label_000C62F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C62F9u);
    cpu->ecx = lift_load32(cpu->edi + 0x1C4u);
    cpu->edx = lift_load32(cpu->edi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000C6313;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->edi + 0x1C8u, cpu->eax);
    label_000C6313: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6313u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x1C8u)) >= (int32_t)(uint32_t)(0u)) goto label_000C6326;
    lift_store32(cpu->edi + 0x1C8u, 0u);
    label_000C6326: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6326u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C632Du); lift_push32(cpu, r); sfera_sub_004C45C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x38u)) < (uint32_t)(cpu->ebx)) goto label_000C6340;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C633Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C6340: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6340u);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6370u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x1771u)) goto label_000C6395;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C638C;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC638Cu); lift_push32(cpu, r); sfera_sub_004C60D0(cpu,r); if (cpu->eip != r) return; }
    label_000C638C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C638Cu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C6395: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6395u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x1772u)) goto label_000C63BA;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C63B1;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC63B1u); lift_push32(cpu, r); sfera_sub_004C4C20(cpu,r); if (cpu->eip != r) return; }
    label_000C63B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C63B1u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C63BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C63BAu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x66u)) goto label_000C63E0;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C63D7;
    lift_store32(cpu->esi + 0x1C8u, 0u);
    label_000C63D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C63D7u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C63E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C63E0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x69u)) goto label_000C6441;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x4Au, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C6438;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_store8(cpu->esi + 0x4Au, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C640Cu); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6420u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6434u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Au, 1u);
    label_000C6438: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6438u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C6441: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6441u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6453u); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6460u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x25u, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C6498;
    cpu->ecx = lift_load32(cpu->edi);
    goto label_000C649A;
    label_000C6498: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6498u);
    cpu->ecx = cpu->edi;
    label_000C649A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C649Au);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load8(cpu->esi + 0x8Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C64B8u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load8(cpu->esi + 0x8Du);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C64DAu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 0x1ACu);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_000C658E;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->esi + 0x28u))) goto label_000C6579;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx -= lift_load32(cpu->esi + 0x198u);
    cpu->edi = lift_load32(cpu->esi + 0x1A8u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ecx)) goto label_000C655A;
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000C653F;
    cpu->ecx = cpu->edi;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    label_000C653F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C653Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6558u); lift_push32(cpu, r); sfera_sub_004C5B30(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6566;
    label_000C655A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C655Au);
    ++cpu->edi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC6566u); lift_push32(cpu, r); sfera_sub_004C5F00(cpu,r); if (cpu->eip != r) return; }
    label_000C6566: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6566u);
    cpu->ebx = 1u;
    lift_store32(cpu->esi + 0x1A8u, (uint64_t)(lift_load32(cpu->esi + 0x1A8u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x1ACu, cpu->ebx);
    goto label_000C65C0;
    label_000C6579: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6579u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6583u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    goto label_000C65C0;
    label_000C658E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C658Eu);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->esi + 0x28u))) goto label_000C65AB;
    cpu->edx = lift_load32(cpu->esi + 0x1A8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C65A3u); lift_push32(cpu, r); sfera_sub_004C5F00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1ACu, (uint64_t)(lift_load32(cpu->esi + 0x1ACu)) + 1u);
    goto label_000C65C0;
    label_000C65AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C65ABu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C65BAu); lift_push32(cpu, r); sfera_sub_0048E480(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1ACu, (uint64_t)(lift_load32(cpu->esi + 0x1ACu)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    label_000C65C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C65C0u);
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1ACu)) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C65D0;
    lift_store32(cpu->esi + 0x1ACu, cpu->edx);
    label_000C65D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C65D0u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->edi = lift_load32(cpu->esi + 0x198u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u) + 0x10u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1ACu)) <= (uint32_t)(cpu->ecx)) goto label_000C65F7;
    lift_store32(cpu->esi + 0x1ACu, cpu->ecx);
    label_000C65F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C65F7u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u))) goto label_000C6605;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C6605: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6605u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edi = lift_load32(cpu->esi + 0x1C8u);
    cpu->edi += cpu->ecx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C661F;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C661F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C661Fu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u)) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C662D;
    lift_store32(cpu->esi + 0x1C8u, cpu->edx);
    label_000C662D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C662Du);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6634u); lift_push32(cpu, r); sfera_sub_004C45C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6640u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_000C66D3;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000C66A9;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    label_000C66A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C66A9u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C66C2u); lift_push32(cpu, r); sfera_sub_004C5B30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A8u, (uint64_t)(lift_load32(cpu->esi + 0x1A8u)) + 1u);
    lift_store32(cpu->esi + 0x1ACu, cpu->ebx);
    goto label_000C679F;
    label_000C66D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C66D3u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C66DD;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000C66DF;
    label_000C66DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C66DDu);
    cpu->eax = cpu->edi;
    label_000C66DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C66DFu);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store8(cpu->esp + 0x18u, cpu->eax & 0xFFu);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x2Cu, 0xFu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000C6700: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6700u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000C6700;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6714u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1ACu);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ebx = 0u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C672Eu); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1A8u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000C674E;
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    label_000C674E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C674Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6767u); lift_push32(cpu, r); sfera_sub_004C5C20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A8u, (uint64_t)(lift_load32(cpu->esi + 0x1A8u)) + 1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x1ACu, cpu->ebx);
    lift_store32(cpu->esp + 0x40u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C678F;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C678Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C678F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C678Fu);
    lift_store32(cpu->esp + 0x2Cu, 0xFu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store8(cpu->esp + 0x18u, cpu->ebx & 0xFFu);
    label_000C679F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C679Fu);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u))) goto label_000C67B3;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C67B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C67B3u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000C67CD;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000C67CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C67CDu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C8u)) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000C67DB;
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    label_000C67DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C67DBu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C67E2u); lift_push32(cpu, r); sfera_sub_004C45C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6810u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)(0u)) goto label_000C6826;
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(1u);
    label_000C6826: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6826u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C69BD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000C6870;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000C6862;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC6862u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C6862: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6862u);
    cpu->ebp = lift_load32(cpu->edi + 0x30u);
    cpu->ebx = lift_load32(cpu->edi + 0x34u);
    cpu->ebp += lift_load32(cpu->esp + 0x10u);
    cpu->ebx += lift_load32(cpu->esp + 0x14u);
    label_000C6870: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6870u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x4Au)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C691A;
    cpu->eax = lift_load8(cpu->edi + 0x15u);
    if ((uint8_t)((cpu->eax & 0xFFu)) < (uint8_t)(0x20u)) goto label_000C688E;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC688Eu); lift_push32(cpu, r); sfera_sub_004C6460(cpu,r); if (cpu->eip != r) return; }
    label_000C688E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C688Eu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x14u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C691A;
    cpu->eax = cpu->eax & 0xFFu;
    cpu->eax += 0xFFFFFFF8u;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x26u)) goto label_000C691A;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000C68B2;
        case 5u: goto label_000C68FD;
        case 25u: goto label_000C690F;
        case 26u: goto label_000C6906;
        case 27u: goto label_000C68F4;
        case 28u: goto label_000C68E8;
        case 29u: goto label_000C68C4;
        case 30u: goto label_000C68D6;
        case 31u: goto label_000C68CD;
        case 32u: goto label_000C68DF;
        case 38u: goto label_000C68BB;
        default: goto label_000C691A;
    }
label_000C68B2: ;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C68B9u); lift_push32(cpu, r); sfera_sub_004C55D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C68BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68BBu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C68C2u); lift_push32(cpu, r); sfera_sub_004C57A0(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C68C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68C4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C68CBu); lift_push32(cpu, r); sfera_sub_004C46D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C68CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68CDu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C68D4u); lift_push32(cpu, r); sfera_sub_004C4760(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C68D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68D6u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C68DDu); lift_push32(cpu, r); sfera_sub_004C4820(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C68DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68DFu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C68E6u); lift_push32(cpu, r); sfera_sub_004C48B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C68E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68E8u);
    lift_store32(cpu->esi + 0x1ACu, 0u);
    goto label_000C6916;
    label_000C68F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68F4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C68FBu); lift_push32(cpu, r); sfera_sub_004C45A0(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C68FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C68FDu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6904u); lift_push32(cpu, r); sfera_sub_004C6640(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C6906: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6906u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C690Du); lift_push32(cpu, r); sfera_sub_004C49F0(cpu,r); if (cpu->eip != r) return; }
    goto label_000C6916;
    label_000C690F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C690Fu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC6916u); lift_push32(cpu, r); sfera_sub_004C4960(cpu,r); if (cpu->eip != r) return; }
    label_000C6916: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6916u);
    lift_store8(cpu->edi + 0x14u, 0u);
    label_000C691A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C691Au);
    cpu->ecx = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C692C;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000C692C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C692Cu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax += cpu->ebp;
    cpu->ecx += cpu->ebx;
    if ((uint8_t)((lift_load8(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000C69BA;
    cpu->edx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000C69AB;
    cpu->ebx = lift_load32(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000C69AB;
    cpu->edi = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000C69AB;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C69AB;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) != (uint8_t)(0u)) goto label_000C69BA;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6975u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6989u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C699Du); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x4Au, 1u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000C69AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C69ABu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x69u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C69BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C69BAu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C69BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C69BDu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6A20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6A28u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    lift_store16(cpu->esi + 0x1D0u, cpu->eax & 0xFFFFu);
    lift_store8(cpu->esi + 0x1D2u, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi));
    lift_store32(cpu->esi + 0x1C8u, 1u);
    lift_store32(cpu->esi + 0x1CCu, 0x14u);
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    lift_store32(cpu->esi + 0x1DCu, cpu->eax);
    lift_store8(cpu->esi + 0x1F0u, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store32(cpu->esi + 0x1E0u, cpu->eax);
    lift_store32(cpu->esi + 0x1E8u, cpu->eax);
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    lift_store32(cpu->esi + 0x50u, 5u);
    lift_store32(cpu->esi + 0x1C0u, 0x64u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6AD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1B0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C6B31;
    cpu->edx = 0x5Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6B1Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C6B31;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000C6B31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6B31u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B4u)) == (uint32_t)(0u)) goto label_000C6B5C;
    cpu->edx = 0x5Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6B49u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C6B5C;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000C6B5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6B5Cu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6B6Bu); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6B80u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6B97u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) != (uint32_t)(0u)) goto label_000C6BBA;
    lift_push32(cpu, 0x6Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6BB1u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6BB7u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C6BBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6BBAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"horizontal");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6BCDu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6BE8;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6BDAu); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6BE8;
    lift_store32(cpu->esi + 0x1ACu, 1u);
    label_000C6BE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6BE8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"bounds");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6BF5u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6C4C;
    cpu->ecx = (uint32_t)(cpu->esi + 0x1ECu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1E4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1E0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C6C1Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6C24u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(4u)) goto label_000C6C4C;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Invalid args in 'bounds'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6C43u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6C49u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C6C4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6C4Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"postMessage");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6C59u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6C71;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6C66u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x1D2u, cpu->eax & 0xFFu);
    label_000C6C71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6C71u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"drawMethod");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6C7Eu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6D1F;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6C94u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6D1F;
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"SPRITE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xC6CAEu), LIFT_CODE_TOKEN_RVA(0xC6CACu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6CAEu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C6D08;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6CC3u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6D1F;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6CD7u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x194u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C6D1F;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6CFDu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6D03u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    goto label_000C6D1F;
    label_000C6D08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6D08u);
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xC6D14u), LIFT_CODE_TOKEN_RVA(0xC6D12u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6D14u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C6D1F;
    lift_store32(cpu->esi + 0x24u, (uint64_t)(lift_load32(cpu->esi + 0x24u)) | (uint64_t)(2u));
    label_000C6D1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6D1Fu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"scrollSpr");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6D2Cu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6DD3;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6D42u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6DD3;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6D5Au); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C6D89;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6D80u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6D86u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    label_000C6D89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6D89u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%s %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C6DA5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6DABu);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000C6DD3;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Not enough args in 'scrollSpr'.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6DCAu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6DD0u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C6DD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6DD3u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"leftbutton");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6DE7u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 6u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6E20;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 1u); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6E06u); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6E14u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    lift_store32(cpu->eax + 0x1A8u, (uint64_t)(lift_load32(cpu->eax + 0x1A8u)) | (uint64_t)(cpu->ebx));
    label_000C6E20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6E20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"rightbutton");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6E34u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6E68;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 2u); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6E4Eu); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6E5Cu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    lift_store32(cpu->eax + 0x1A8u, (uint64_t)(lift_load32(cpu->eax + 0x1A8u)) | (uint64_t)(cpu->ebx));
    label_000C6E68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6E68u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"deltaStep");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6E75u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C6E91;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6E84u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    lift_store8(cpu->esi + 0x1D1u, 1u);
    label_000C6E91: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6E91u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6E9Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6EA6u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C6EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6EC0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C7110;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C7110;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000C6F18;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C6F0A;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC6F0Au); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C6F0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6F0Au);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 8u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000C6F18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6F18u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C6FBF;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000C6F76;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C6F76: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6F76u);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C6F97;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C6F97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6F97u);
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6FB7u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    label_000C6FBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C6FBFu);
    cpu->edi = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000C7067;
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1BCu))) goto label_000C7067;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1A4u)))));
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C6FEFu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x1A8u))))));
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7000u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->ecx |= 0xFFFFFFu;
    lift_store32(cpu->edi + 0x1Cu, cpu->ecx);
    lift_store32(cpu->edi + 0x3Cu, cpu->ecx);
    lift_store32(cpu->edi + 0x5Cu, cpu->ecx);
    lift_store32(cpu->edi + 0x7Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->esp -= 0x10u;
    cpu->edx += cpu->ebx;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7064u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu);
    goto label_000C706B;
    label_000C7067: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7067u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C706B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C706Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C70BC;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000C70AF;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C7098;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C7098: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7098u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000C70AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C70AFu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000C70BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C70BCu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C7110;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000C70FF;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C70E8;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C70E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C70E8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000C70FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C70FFu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    lift_return(cpu, 0u, stop_address); return;
    label_000C7110: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7110u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7120u);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C714E;
    lift_push32(cpu, cpu->ebx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000C714E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C714Eu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C7160;
    lift_push32(cpu, cpu->ebx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000C7160: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7160u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x20u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7174u); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 1u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C7216;
    cpu->edi = 0x3E9u;
    label_000C7186: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7186u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) != (uint32_t)(cpu->edi)) goto label_000C7202;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C71BA;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C7202;
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C7202;
    cpu->eax += lift_load32(cpu->esi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C71E0;
    goto label_000C71DA;
    label_000C71BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C71BAu);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C7202;
    cpu->eax -= lift_load32(cpu->esi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C71E0;
    label_000C71DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C71DAu);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    label_000C71E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C71E0u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C71E9u);
    { uint64_t l=(uint64_t)(g_sfera_interface_runtime.sounds_enabled), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C7202;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_line.wav";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7202u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000C7202: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7202u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C720Eu); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C7186;
    label_000C7216: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7216u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) == (uint32_t)(0u)) goto label_000C7320;
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000C7320;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000C7251;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7251u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C7251: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7251u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->edx = lift_load32(cpu->edi + 0x28u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->edi + 0x2Cu);
    cpu->ebp = lift_load32(cpu->ebx);
    cpu->edx += cpu->eax;
    cpu->edi += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->eax)) goto label_000C7320;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C7320;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000C7320;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edi)) goto label_000C7320;
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000C72B9;
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1BCu))) goto label_000C72B9;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1C0u))) goto label_000C72B9;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_line.wav";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC72B9u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000C72B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C72B9u);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000C72D8;
    cpu->ecx = lift_load32(cpu->esi + 0x1C8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    lift_store32(cpu->esi + 0x1C4u, (uint64_t)(lift_load32(cpu->esi + 0x1C4u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    goto label_000C72E7;
    label_000C72D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C72D8u);
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    lift_store32(cpu->esi + 0x1C4u, (uint64_t)(lift_load32(cpu->esi + 0x1C4u)) - (uint64_t)(cpu->edx) - (uint64_t)(0u));
    label_000C72E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C72E7u);
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000C72FB;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000C72FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C72FBu);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C4u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000C730F;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000C730F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C730Fu);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7318u);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    label_000C7320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7320u);
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (1u)) == 0u) goto label_000C73E6;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1D0u)) != (uint8_t)(0u)) goto label_000C73E6;
    cpu->ebp = lift_load32(cpu->esi + 0x9Cu);
    cpu->edx = 0u;
    cpu->edi = 0u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edx)) goto label_000C7374;
    cpu->ecx = lift_load32(cpu->ebp + 0x9Cu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000C7366;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7366u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C7366: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7366u);
    cpu->edx = lift_load32(cpu->ebp + 0x30u);
    cpu->edi = lift_load32(cpu->ebp + 0x34u);
    cpu->edx += lift_load32(cpu->esp + 0x14u);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    label_000C7374: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7374u);
    cpu->eax = lift_load32(cpu->esi + 0x1A4u);
    cpu->eax += lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    cpu->ecx += lift_load32(cpu->esi + 0x34u);
    cpu->ebp = lift_load32(cpu->ebx);
    cpu->eax += cpu->edx;
    cpu->ecx += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->eax)) goto label_000C73BA;
    cpu->ebx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ebx += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000C73BA;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000C73BA;
    cpu->ebp = lift_load32(cpu->esi + 0x1A0u);
    cpu->ebp += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_000C73BA;
    lift_store8(cpu->esi + 0x1D0u, 1u);
    label_000C73BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C73BAu);
    cpu->edx += lift_load32(cpu->esi + 0x30u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi += lift_load32(cpu->esi + 0x34u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000C73E6;
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C73E6;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_000C73E6;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C73E6;
    lift_store8(cpu->esi + 0x1F0u, 1u);
    label_000C73E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C73E6u);
    if ((uint8_t)((lift_load8(cpu->ebx + 0x10u)) & (1u)) != 0u) goto label_000C73FA;
    lift_store8(cpu->esi + 0x1D0u, 0u);
    lift_store8(cpu->esi + 0x1F0u, 0u);
    label_000C73FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C73FAu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1D0u)) == (uint8_t)(0u)) goto label_000C7540;
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->ecx = 0u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_000C7446;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000C7438;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7438u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C7438: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7438u);
    cpu->ecx = lift_load32(cpu->edi + 0x30u);
    cpu->eax = lift_load32(cpu->edi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    label_000C7446: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7446u);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->edx += cpu->eax;
    if ((uint8_t)((lift_load8(cpu->esi + 0x1ACu)) & (1u)) == 0u) goto label_000C74CD;
    cpu->eax = lift_load32(cpu->ebx);
    cpu->eax -= lift_load32(cpu->esi + 0x30u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C7467;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000C7467: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7467u);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000C7472;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_000C7472: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7472u);
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    cpu->eax -= lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000C749C;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C749C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C749Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C74ABu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x1C4u)) == (uint32_t)(cpu->eax)) goto label_000C7540;

    lift_store32(cpu->esi + 0x1C4u, cpu->eax);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C74C6u);
    cpu->ecx = 1u;
    goto label_000C7544;
    label_000C74CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C74CDu);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C74DE;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000C74DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C74DEu);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000C74E9;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_000C74E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C74E9u);
    cpu->edx = lift_load32(cpu->esi + 0x1C0u);
    cpu->edx -= lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000C7513;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C7513: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7513u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7522u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x1C4u)) == (uint32_t)(cpu->eax)) goto label_000C7540;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7539u);
    cpu->ecx = 1u;
    goto label_000C7544;
    label_000C7540: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7540u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_000C7544: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7544u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x14u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C75D1;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000C784F;
    cpu->eax = cpu->eax & 0xFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x21u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C75AF;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C75D9;
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C75D9;
    cpu->eax += lift_load32(cpu->esi + 0x1CCu);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C7588;
    label_000C7582: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7582u);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    label_000C7588: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7588u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7591u);
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000C784F;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_page.wav";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C75AAu); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    goto label_000C784F;
    label_000C75AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C75AFu);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C75D9;
    cpu->eax -= lift_load32(cpu->esi + 0x1CCu);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C7588;
    goto label_000C7582;
    label_000C75D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C75D1u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000C784F;
    label_000C75D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C75D9u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1D0u)) != (uint8_t)(0u)) goto label_000C7861;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1F0u)) == (uint8_t)(0u)) goto label_000C7861;
    if ((uint8_t)((lift_load8(cpu->ebx + 0x10u)) & (1u)) == 0u) goto label_000C7861;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7602u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1D8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1DCu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.10000000149011612);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000C7861;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C763Eu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 0x1DCu, cpu->edx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000C7687;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C7679;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7679u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C7679: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7679u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    label_000C7687: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7687u);
    cpu->ebp = lift_load32(cpu->esi + 0x34u);
    cpu->edi = lift_load32(cpu->esi + 0x30u);
    cpu->ebp += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edi += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->ebp);
    cpu->ebp += lift_load32(cpu->esi + 0x1E4u);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = lift_load32(cpu->ebx);
    cpu->edx = (uint32_t)(cpu->edi + cpu->eax);
    cpu->edi += lift_load32(cpu->esi + 0x1E0u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->edi)) goto label_000C7861;
    cpu->edx -= lift_load32(cpu->esi + 0x1E8u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C7861;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000C7861;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edx -= lift_load32(cpu->esi + 0x1ECu);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C7861;
    if ((uint8_t)((lift_load8(cpu->esi + 0x1ACu)) & (1u)) == 0u) goto label_000C779B;
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->eax -= lift_load32(cpu->esi + 0x1E8u);
    cpu->ebx = lift_load32(cpu->esi + 0x1E0u);
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C7731;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C7731: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7731u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x1C0u);
    cpu->edx -= lift_load32(cpu->esi + 0x1BCu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x14u))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7754u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000C7861;
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    cpu->edx -= cpu->ebx;
    cpu->ebx = (uint32_t)(cpu->edx + cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000C778A;
    cpu->ecx -= lift_load32(cpu->esi + 0x1CCu);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000C7846;
    goto label_000C7840;
    label_000C778A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C778Au);
    cpu->ebx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ebx += cpu->edx;
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    goto label_000C782E;
    label_000C779B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C779Bu);
    cpu->ecx -= lift_load32(cpu->esi + 0x1ECu);
    cpu->edi = lift_load32(cpu->esi + 0x1E4u);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C77C5;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C77C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C77C5u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x1C0u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1BCu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x14u))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C77E8u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000C7861;
    cpu->edx = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx -= cpu->edi;
    cpu->edi = (uint32_t)(cpu->edx + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edi)) goto label_000C7822;
    cpu->ecx -= lift_load32(cpu->esi + 0x1CCu);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000C7817;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000C7817: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7817u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7820u);
    goto label_000C784F;
    label_000C7822: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7822u);
    cpu->edi = lift_load32(cpu->esi + 0x1A0u);
    cpu->edi += cpu->edx;
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000C782E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C782Eu);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000C7861;
    cpu->ecx += lift_load32(cpu->esi + 0x1CCu);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000C7846;
    label_000C7840: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7840u);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000C7846: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7846u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    label_000C784F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C784Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) == (uint32_t)(0u)) goto label_000C7861;

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->loadControlParameters(cpu);
    label_000C7861: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7861u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7880u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1C4u)))));
    cpu->eax -= lift_load32(cpu->esi + 0x1BCu);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(lift_load32(cpu->esp + 0x10u))))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esi + 0x1B8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000C78C4;
    lift_store_f32(cpu->esi + 0x1B8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000C78C6;
    label_000C78C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C78C4u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C78C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C78C6u);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x1B8u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000C78DD;
    lift_store_f32(cpu->esi + 0x1B8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000C78DF;
    label_000C78DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C78DDu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C78DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C78DFu);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->edi = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx -= lift_load32(cpu->esi + 0x1E8u);
    cpu->edi -= lift_load32(cpu->esi + 0x1ECu);
    cpu->ebx = lift_load32(cpu->esi + 0x1E0u);
    cpu->ebp = lift_load32(cpu->esi + 0x1E4u);
    cpu->ecx -= cpu->ebx;
    cpu->edi -= cpu->ebp;
    if ((uint8_t)((lift_load8(cpu->esi + 0x1ACu)) & (1u)) == 0u) goto label_000C794E;
    cpu->ecx -= lift_load32(cpu->esi + 0x19Cu);
    cpu->eax = cpu->edi;
    cpu->eax -= lift_load32(cpu->esi + 0x1A0u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x1B8u))));
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7936u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    lift_store32(cpu->esi + 0x1A4u, (uint64_t)(lift_load32(cpu->esi + 0x1A4u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x1A8u, (uint64_t)(lift_load32(cpu->esi + 0x1A8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C794E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C794Eu);
    cpu->edi -= lift_load32(cpu->esi + 0x1A0u);
    cpu->eax = cpu->ecx;
    cpu->eax -= lift_load32(cpu->esi + 0x19Cu);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x1B8u))));
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C797Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A4u, (uint64_t)(lift_load32(cpu->esi + 0x1A4u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1A8u, (uint64_t)(lift_load32(cpu->esi + 0x1A8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C79A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C79A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 1u;
    cpu->esi = cpu->ecx;
    if ((uint8_t)((lift_load8(cpu->edi + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_000C79FB;
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1BCu)) != (uint32_t)(cpu->eax)) goto label_000C79CF;
    cpu->ebx = 0u;
    label_000C79CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C79CFu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C79E5;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C79E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C79E5u);
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C79FB;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C79FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C79FBu);
    if ((uint8_t)((lift_load8(cpu->edi + 4u)) & (4u)) == 0u) goto label_000C7A2E;
    cpu->eax = lift_load32(cpu->edi + 0x14u);
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C7A1A;
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    label_000C7A1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7A1Au);
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000C7A2E;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000C7A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7A2Eu);
    if ((uint8_t)((lift_load8(cpu->edi + 4u)) & (2u)) == 0u) goto label_000C7A3D;
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->esi + 0x1CCu, cpu->ecx);
    label_000C7A3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7A3Du);
    if ((uint8_t)((lift_load8(cpu->edi + 4u)) & (0x10u)) == 0u) goto label_000C7A55;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1D1u)) != (uint8_t)(0u)) goto label_000C7A55;
    cpu->edx = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->esi + 0x1C8u, cpu->edx);
    label_000C7A55: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7A55u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->ecx)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7A5Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7A70u);
    cpu->edx = lift_load32(cpu->ecx + 0x1BCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x1C0u);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x1CCu);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x1C4u);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 0x1C8u);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7AB0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFF63Bu);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x63u)) goto label_000C7C4B;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFF63Bu);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x63u)) goto label_000C7C4B;
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: goto label_000C7AE3;
        case 1u: goto label_000C7B23;
        case 2u: goto label_000C7BB2;
        case 3u: goto label_000C7B88;
        case 4u: goto label_000C7BD3;
        case 5u: goto label_000C7BE8;
        case 6u: goto label_000C7C29;
        case 99u: goto label_000C7B9D;
        default: goto label_000C7C4B;
    }
label_000C7AE3: ;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000C7AFD;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000C7AFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7AFDu);
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000C7B11;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000C7B11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B11u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B1Au);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C7B23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B23u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store32(cpu->esi + 0x1C0u, cpu->ecx);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    cpu->edi = 1u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000C7B49;
    cpu->edi = 0u;
    label_000C7B49: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B49u);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C7B5F;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C7B5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B5Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C7B75;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C7B75: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B75u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B7Eu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C7B88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B88u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7B94u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C7B9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7B9Du);
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C7BB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7BB2u);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x1C0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C7BD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7BD3u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7BDFu); lift_push32(cpu, r); sfera_sub_004C7A70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C7BE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7BE8u);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C7C20;
    cpu->eax += lift_load32(cpu->esi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C7C0E;
    label_000C7C08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7C08u);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    label_000C7C0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7C0Eu);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7C17u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->loadControlParameters(cpu);
    label_000C7C20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7C20u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000C7C29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7C29u);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C7C20;
    cpu->eax -= lift_load32(cpu->esi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000C7C0E;
    goto label_000C7C08;
    label_000C7C4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7C4Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7C5Du); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7CF0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) == (uint32_t)(0u)) goto label_000C7D39;
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->edx = cpu->edx & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(cpu->edx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edx += 0x66u;
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C7D39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7D39u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1D2u)) == (uint8_t)(0u)) goto label_000C7D85;
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax += 0x66u;
    lift_store32(cpu->esp + 4u, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C7D85;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7D85u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000C7D85: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7D85u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7DA0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->ecx + 0x1ACu, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7DB0u);
    cpu->eax = lift_load32(cpu->ecx + 0x1ACu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7DC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7DC8u); lift_push32(cpu, r); sfera_sub_004C6AD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C7DD8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7DD5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C7DD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7DD8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7DE0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7DEEu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1A0u);
    lift_store32(cpu->esi + 0x1A0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1A4u);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1A8u);
    lift_store32(cpu->esi + 0x1A8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1B0u);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    lift_store32(cpu->esi + 0x1B4u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1B8u));
    lift_store_f32(cpu->esi + 0x1B8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 0x1BCu);
    lift_store32(cpu->esi + 0x1BCu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1C0u);
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1C4u);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C8u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1CCu);
    lift_store32(cpu->esi + 0x1CCu, cpu->eax);
    cpu->ecx = lift_load8(cpu->edi + 0x1D0u);
    lift_store8(cpu->esi + 0x1D0u, cpu->ecx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1D1u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1D1u, cpu->edx & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1D2u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1D2u, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->edi + 0x1D8u);
    lift_store32(cpu->esi + 0x1D8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1DCu);
    lift_store32(cpu->esi + 0x1DCu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1E0u);
    lift_store32(cpu->esi + 0x1E0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1E4u);
    lift_store32(cpu->esi + 0x1E4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1E8u);
    lift_store32(cpu->esi + 0x1E8u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1ECu);
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    cpu->ecx = lift_load8(cpu->edi + 0x1F0u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x1F0u, cpu->ecx & 0xFFu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C7F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7F20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xF0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7F54u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7F5Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C7F7C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7F78u); lift_push32(cpu, r); sfera_sub_004C6A20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000C7F7E;
    label_000C7F7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7F7Cu);
    cpu->esi = 0u;
    label_000C7F7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7F7Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C7F8Eu); lift_push32(cpu, r); sfera_sub_004C7DE0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B0u)) == (uint32_t)(0u)) goto label_000C7FB6;
    cpu->ecx = lift_load32(cpu->edi + 0x1B0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7FA8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7FB6u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C7FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7FB6u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B4u)) == (uint32_t)(0u)) goto label_000C7FDA;
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7FCCu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7FDAu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C7FDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7FDAu);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000C7FFE;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7FF0u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC7FFEu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C7FFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C7FFEu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C8020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8020u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8028u); lift_push32(cpu, r); sfera_sub_004C6A20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x238u, cpu->eax);
    lift_store8(cpu->esi + 0x1F8u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x240u, cpu->eax);
    lift_store32(cpu->esi + 0x23Cu, cpu->eax);
    std::construct_at(reinterpret_cast<SphereUI::SliderCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 0xBu);
    lift_store32(cpu->esi + 0x1ACu, 1u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C8060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8060u);
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0x9Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C80A2;
    cpu->edx = lift_load32(cpu->eax + 0xD8u);
    lift_store32(cpu->esp + 4u, cpu->edx);
    lift_store32(cpu->esp, cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 0x1C4u);
    cpu->edx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0xCu, 0xED8u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC80A2u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000C80A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C80A2u);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C80C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C80C0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C80D9u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x9Cu)) != (uint32_t)(0u)) goto label_000C80FF;
    lift_push32(cpu, 0x8Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SliderCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C80F6u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C80FCu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C80FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C80FFu);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"range");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8110u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C815A;
    cpu->ecx = (uint32_t)(cpu->edi + 0x1C0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x1BCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xC8133u), LIFT_CODE_TOKEN_RVA(0xC8131u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8133u);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000C815A;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SliderCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'range'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8151u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8157u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C815A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C815Au);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"step");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8167u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C817A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8174u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1C8u, cpu->eax);
    label_000C817A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C817Au);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"page");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8187u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C819A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8194u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1CCu, cpu->eax);
    label_000C819A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C819Au);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"defaultPos");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C81A7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C81BA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C81B4u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1C4u, cpu->eax);
    label_000C81BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C81BAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"statusPos");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C81C7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C820B;
    cpu->ecx = (uint32_t)(cpu->edi + 0x240u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x23Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xC81E4u), LIFT_CODE_TOKEN_RVA(0xC81E2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C81E4u);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000C820B;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SliderCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'statusPos'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8202u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8208u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C820B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C820Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"statusShow");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8218u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C823E;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.slider_status_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C822Au); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C823E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.slider_status_value[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8238u); lift_push32(cpu, r); sfera_sub_004C3B40(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x238u, cpu->eax);
    label_000C823E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C823Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C824Au); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8258u); lift_push32(cpu, r); sfera_sub_004C6B80(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C8270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8270u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8278u); lift_push32(cpu, r); sfera_sub_004C7880(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x238u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C82DA;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C82B3;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C82DA;
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    cpu->eax -= lift_load32(cpu->esi + 0x1BCu);
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d / %d");
    cpu->esi += 0x1F8u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C82A8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C82AEu);
    cpu->esp += 0x10u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C82B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C82B3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1B8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (100.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C82C4u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d%%");
    cpu->esi += 0x1F8u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C82D1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C82D7u);
    cpu->esp += 0xCu;
    label_000C82DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C82DAu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C82E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C82E0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C83EA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C82F5u); lift_push32(cpu, r); sfera_sub_004C6EC0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x238u)) <= (uint32_t)(0u)) goto label_000C83EA;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = 0u;
    cpu->edi = 0u;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000C8341;
    cpu->ecx = lift_load32(cpu->ebx + 0x9Cu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C8333;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8333u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C8333: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8333u);
    cpu->eax = lift_load32(cpu->ebx + 0x30u);
    cpu->edi = lift_load32(cpu->ebx + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0xCu);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    label_000C8341: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8341u);
    cpu->ecx = lift_load32(cpu->esi + 0x23Cu);
    cpu->ecx += lift_load32(cpu->esi + 0x30u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->ecx += cpu->eax;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x240u);
    cpu->edx += lift_load32(cpu->esi + 0x34u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x64u);
    cpu->edx += cpu->edi;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(cpu->edx + 0x64u);
    cpu->edi = 0xFFu;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->edx);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->edi)) goto label_000C839D;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)((cpu->ebx & 0xFFu))) goto label_000C839D;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8391u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_screen_clip_runtime.left;
    cpu->edx = g_sfera_screen_clip_runtime.top;
    label_000C839D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C839Du);
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x1F8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C83C8u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->edi)) goto label_000C83E8;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)((cpu->ebx & 0xFFu))) goto label_000C83E8;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000C83E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C83E8u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C83EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C83EAu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C83F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C83F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C83FFu); lift_push32(cpu, r); sfera_sub_004C7DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    cpu->eax = (uint32_t)(cpu->esi + 0x1F8u);
    cpu->ecx -= cpu->esi;
    cpu->edi = 0x40u;
    cpu->edi = cpu->edi;
    label_000C8410: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8410u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C8410;
    cpu->eax = lift_load32(cpu->ebp + 0x238u);
    lift_store32(cpu->esi + 0x238u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x23Cu);
    lift_store32(cpu->esi + 0x23Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x240u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x240u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C8450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8450u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x53u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SliderCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8485u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x248u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C848Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000C84DA;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C84A9u); lift_push32(cpu, r); sfera_sub_004C6A20(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::SliderCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 0xBu);
    lift_store32(cpu->esi + 0x1ACu, 1u);
    lift_store32(cpu->esi + 0x238u, cpu->ebx);
    lift_store8(cpu->esi + 0x1F8u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x240u, cpu->ebx);
    lift_store32(cpu->esi + 0x23Cu, cpu->ebx);
    goto label_000C84DC;
    label_000C84DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C84DAu);
    cpu->esi = 0u;
    label_000C84DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C84DCu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C84ECu); lift_push32(cpu, r); sfera_sub_004C83F0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B0u)) == (uint32_t)(cpu->ebx)) goto label_000C8513;
    cpu->ecx = lift_load32(cpu->edi + 0x1B0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8505u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8513u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C8513: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8513u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B4u)) == (uint32_t)(cpu->ebx)) goto label_000C8536;
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8528u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8536u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C8536: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8536u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(cpu->ebx)) goto label_000C8559;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C854Bu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8559u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C8559: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8559u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C8570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8570u);
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->eax + 0x48u)) == (uint8_t)(0u)) goto label_000C8599;
    cpu->eax = 0u;
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
    label_000C8599: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8599u);
    cpu->ecx = lift_load32(cpu->eax + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, 0x138Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C85BEu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C85E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C85E0u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C8CF8;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C8CF8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_000C863C;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000C862E;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC862Eu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C862E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C862Eu);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    label_000C863C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C863Cu);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->ebx = lift_load32(cpu->esi + 0x1A4u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1A4u);
    { int64_t v=(int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx); cpu->eax= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1A8u)), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(0x10u), 32u);
    cpu->eax &= 0xFFFFFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ebx = lift_load32(cpu->esi + 0x1ACu);
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x18u), 32u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->edi = cpu->edx;
    cpu->ebx |= cpu->edx;
    cpu->edi |= 0xFFFFFFu;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x250u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C8702;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000C8702;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x1B4u))))));
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x1B0u))))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8700u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    goto label_000C874F;
    label_000C8702: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8702u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000C874B;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x1B4u))))));
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x1B0u))))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8749u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    goto label_000C874F;
    label_000C874B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C874Bu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C874F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C874Fu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x251u)) == (uint8_t)(0u)) goto label_000C8821;
    lift_store32(cpu->esi + 0x1D4u, cpu->edi);
    lift_store32(cpu->esi + 0x1F4u, cpu->edi);
    lift_store32(cpu->esi + 0x214u, cpu->edi);
    lift_store32(cpu->esi + 0x234u, cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1BCu)) >= (uint32_t)(cpu->eax)) goto label_000C87A4;
    cpu->edx = lift_load32(cpu->esi + 0x1BCu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    label_000C87A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C87A4u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1C0u)) >= (uint32_t)(cpu->ecx)) goto label_000C87BE;
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    label_000C87BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C87BEu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8821u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    label_000C8821: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8821u);
    cpu->eax = lift_load32(cpu->esi + 0x288u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000C8862;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->eax + 0x3Cu, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_store32(cpu->eax + 0x5Cu, cpu->edi);
    lift_store32(cpu->eax + 0x7Cu, cpu->edi);
    cpu->ecx = lift_load32(cpu->esi + 0x288u);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8862u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    label_000C8862: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8862u);
    cpu->eax = lift_load32(cpu->esi + 0x28Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000C88F5;
    lift_store32(cpu->eax + 0x1Cu, cpu->edi);
    lift_store32(cpu->eax + 0x3Cu, cpu->edi);
    lift_store32(cpu->eax + 0x5Cu, cpu->edi);
    lift_store32(cpu->eax + 0x7Cu, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x28Cu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C8892;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C8892: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8892u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ecx + 8u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C88A6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C88A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C88A6u);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->esp -= 8u;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C88CD;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C88CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C88CDu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ecx + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C88E1;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C88E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C88E1u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC88F5u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    label_000C88F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C88F5u);
    cpu->eax = lift_load32(cpu->esi + 0x290u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000C89B0;
    lift_x87_push(cpu, (double)3.0f);
    lift_store32(cpu->eax + 0x1Cu, cpu->edi);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x3Cu, cpu->edi);
    lift_x87_push(cpu, (double)2.0f);
    lift_store32(cpu->eax + 0x5Cu, cpu->edi);
    lift_store32(cpu->eax + 0x7Cu, cpu->edi);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    lift_x87_push(cpu, 1.0);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000C893C;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000C893E;
    label_000C893C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C893Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C893E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C893Eu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFEu)) goto label_000C894F;
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000C8951;
    label_000C894F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C894Fu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C8951: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8951u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x18u))));
    cpu->ecx = lift_load32(cpu->esi + 0x290u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C896F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C896F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C896Fu);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ecx + 8u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C8981;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C8981: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8981u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC89B0u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    label_000C89B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C89B0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) <= (uint32_t)(cpu->ebp)) goto label_000C8CA6;
    if ((uint8_t)(lift_load8(cpu->esi + 0x251u)) != (uint8_t)(0u)) goto label_000C89CC;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (4u)) == 0u) goto label_000C8CA6;
    label_000C89CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C89CCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x49u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C89DE;
    cpu->eax = lift_load32(cpu->esi + 0x98u);
    label_000C89DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C89DEu);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->eax &= 0xFFFFFFu;
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C89FDu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8A0Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000C8A22;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C8A22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8A22u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8A2Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000C8A40;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000C8A40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8A40u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8A47u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    cpu->edi = 0u;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x118u)) == (uint32_t)(cpu->ebp)) goto label_000C8AD5;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C8A63;
    cpu->eax = lift_load32(cpu->eax);
    label_000C8A63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8A63u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8A83u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x118u);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000C8A9D;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->eax)) goto label_000C8A9D;
    cpu->eax -= cpu->ebp;
    cpu->edi = cpu->eax;
    label_000C8A9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8A9Du);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_000C8AB1;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000C8AB1;
    cpu->eax -= cpu->ecx;
    cpu->ebx = cpu->eax;
    label_000C8AB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8AB1u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000C8AC3;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->eax)) goto label_000C8AC3;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edi = cpu->eax;
    label_000C8AC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8AC3u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (8u)) == 0u) goto label_000C8AD5;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000C8AD5;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->ebx = cpu->eax;
    label_000C8AD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8AD5u);
    cpu->edi += lift_load32(cpu->esi + 0x27Cu);
    cpu->ebx += lift_load32(cpu->esi + 0x280u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xDCu)), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C8B05;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x8Cu)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C8B05;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8B05u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000C8B05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8B05u);
    cpu->ebp = lift_load32(cpu->esi + 0xDCu);
    cpu->edi = (uint32_t)(cpu->esi + 0x54u);
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(0x18u), 32u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C8B1F;
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    goto label_000C8B23;
    label_000C8B1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8B1Fu);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    label_000C8B23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8B23u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f64(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8B3Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f64(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8B53u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8B7Eu); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C8B8C;
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    goto label_000C8B90;
    label_000C8B8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8B8Cu);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    label_000C8B90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8B90u);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x30u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8B9Fu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x38u)) - (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8BACu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8BD7u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C8BE1;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000C8BE3;
    label_000C8BE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8BE1u);
    cpu->eax = cpu->edi;
    label_000C8BE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8BE3u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8C08u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0x10u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000C8C16;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000C8C18;
    label_000C8C16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8C16u);
    cpu->eax = cpu->edi;
    label_000C8C18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8C18u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8C3Fu); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000C8C46;
    cpu->edi = lift_load32(cpu->edi);
    label_000C8C46: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8C46u);
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x38u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8C6Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x50u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8C78u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8C81u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(0xFFu)) goto label_000C8CA0;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C8CA0;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8CA0u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000C8CA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8CA0u);
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->ebp = 0u;
    label_000C8CA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8CA6u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000C8CF5;
    lift_store32(cpu->eax + 0x1Cu, cpu->ebx);
    lift_store32(cpu->eax + 0x3Cu, cpu->ebx);
    lift_store32(cpu->eax + 0x5Cu, cpu->ebx);
    lift_store32(cpu->eax + 0x7Cu, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1B4u)))));
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    cpu->esp -= 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1B0u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8CF5u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    label_000C8CF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8CF5u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C8CF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8CF8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C8D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8D00u);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C8F3F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_000C8D5B;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000C8D4D;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8D4Du); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C8D4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8D4Du);
    cpu->ecx = lift_load32(cpu->edi + 0x30u);
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    cpu->edx += lift_load32(cpu->esp + 0x18u);
    label_000C8D5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8D5Bu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->edi = lift_load32(cpu->esi + 0x28u);
    cpu->ebp = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += cpu->edx;
    cpu->edi += cpu->eax;
    cpu->ebp += cpu->ecx;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x2A]) != (uint8_t)(0u)) goto label_000C8D86;
    { uint64_t l=(uint64_t)(g_sfera_direct_input_runtime.keyboard_state[0x36]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store8(cpu->esp + 0x13u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C8D8B;
    label_000C8D86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8D86u);
    lift_store8(cpu->esp + 0x13u, 1u);
    label_000C8D8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8D8Bu);
    cpu->ebx = lift_load32(cpu->esp + 0x40u);
    cpu->edx = lift_load32(cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000C8EB0;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->edi)) goto label_000C8EB0;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000C8EB0;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_000C8EB0;
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (1u)) == 0u) goto label_000C8DEB;
    if ((uint8_t)(lift_load8(cpu->esi + 0x25Cu)) != (uint8_t)(0u)) goto label_000C8DEB;
    if ((uint8_t)(lift_load8(cpu->esi + 0x25Eu)) != (uint8_t)(0u)) goto label_000C8DEB;
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) != (uint8_t)(0u)) goto label_000C8DEB;
    lift_store8(cpu->esi + 0x25Cu, 1u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_store32(cpu->esi + 0x254u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->esi + 0x258u, cpu->ecx);
    label_000C8DEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8DEBu);
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (2u)) == 0u) goto label_000C8DF8;
    lift_store8(cpu->esi + 0x25Du, 1u);
    label_000C8DF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8DF8u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03)) != (uint8_t)(0u)) goto label_000C8EB0;
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (4u)) == 0u) goto label_000C8E41;
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) != (uint8_t)(0u)) goto label_000C8E41;
    if ((uint8_t)(lift_load8(cpu->esi + 0x25Cu)) == (uint8_t)(0u)) goto label_000C8E41;
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x28u, 0x3E9u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8E41u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000C8E41: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8E41u);
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (8u)) == 0u) goto label_000C8E7D;
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) != (uint8_t)(0u)) goto label_000C8E7D;
    if ((uint8_t)(lift_load8(cpu->esi + 0x25Du)) == (uint8_t)(0u)) goto label_000C8E7D;
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x28u, 0x3EDu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8E7Du); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000C8E7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8E7Du);
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (1u)) == 0u) goto label_000C8E8E;
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) == (uint8_t)(0u)) goto label_000C8E8E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_000C8E90;
    label_000C8E8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8E8Eu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    label_000C8E90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8E90u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x274u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x260u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C8EA1;
    cpu->eax = lift_load32(cpu->eax);
    label_000C8EA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8EA1u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8EA9u); lift_push32(cpu, r); sfera_sub_004A21F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8EB0u); lift_push32(cpu, r); sfera_sub_004A2740(cpu,r); if (cpu->eip != r) return; }
    label_000C8EB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8EB0u);
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (8u)) == 0u) goto label_000C8EBD;
    lift_store8(cpu->esi + 0x25Du, 0u);
    label_000C8EBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8EBDu);
    if ((uint8_t)((lift_load8(cpu->ebx + 0x10u)) & (1u)) != 0u) goto label_000C8ED1;
    lift_store8(cpu->esi + 0x25Cu, 0u);
    lift_store8(cpu->esi + 0x25Eu, 0u);
    label_000C8ED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8ED1u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x25Cu)) == (uint8_t)(0u)) goto label_000C8F3C;
    if ((uint8_t)(lift_load8(cpu->esi + 0x25Eu)) != (uint8_t)(0u)) goto label_000C8F3C;
    cpu->eax = lift_load32(cpu->esi + 0x254u);
    cpu->eax -= lift_load32(cpu->ebx);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(2u)) goto label_000C8F08;
    cpu->eax = lift_load32(cpu->esi + 0x258u);
    cpu->eax -= lift_load32(cpu->ebx + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(2u)) goto label_000C8F3C;
    label_000C8F08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8F08u);
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x28u, 0x138Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8F2Eu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x25Cu, 0u);
    lift_store8(cpu->esi + 0x25Eu, 1u);
    label_000C8F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8F3Cu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C8F3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8F3Fu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C8F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C8F60u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8F8Eu); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    std::construct_at(reinterpret_cast<SphereUI::SlotCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x198u, cpu->ebx);
    lift_store32(cpu->esi + 0x19Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1A4u, 0x80u);
    lift_store32(cpu->esi + 0x1ACu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C8FCBu); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    lift_store16(cpu->esi + 0x250u, cpu->ebx & 0xFFFFu);
    lift_store16(cpu->esi + 0x25Cu, cpu->ebx & 0xFFFFu);
    lift_store8(cpu->esi + 0x25Eu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x274u, 0xFu);
    lift_store32(cpu->esi + 0x270u, cpu->ebx);
    lift_store8(cpu->esi + 0x260u, cpu->ebx & 0xFFu);
    cpu->eax = 2u;
    cpu->ecx = 1u;
    lift_store32(cpu->esi + 0x280u, cpu->eax);
    lift_store8(cpu->esi + 0x8Cu, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x288u, cpu->ebx);
    lift_store32(cpu->esi + 0x28Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x290u, cpu->ebx);
    lift_store8(cpu->esi + 0x48u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x50u, 0xEu);
    lift_store8(cpu->esi + 0x4Cu, cpu->ecx & 0xFFu);
    lift_store32(cpu->esi + 0x1B0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B4u, cpu->ebx);
    lift_store32(cpu->esi + 0x27Cu, 0xFFFFFFFEu);
    lift_store32(cpu->esi + 0x284u, cpu->ebx);
    lift_store32(cpu->esi + 0x118u, cpu->ecx);
    lift_store32(cpu->esi + 0x1A8u, 0x141414u);
    lift_store32(cpu->esi + 0x1ACu, 0xFF9E7C6Au);
    lift_store32(cpu->esi + 0x90u, 0xFFFFFFFFu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9080u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::SlotCtrl*>(cpu->esi));
    cpu->ecx = lift_load32(cpu->esi + 0x288u);
    lift_store32(cpu->esp + 0x14u, 2u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C90C5;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC90C5u); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    label_000C90C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C90C5u);
    cpu->ecx = lift_load32(cpu->esi + 0x28Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C90D4;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC90D4u); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    label_000C90D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C90D4u);
    cpu->ecx = lift_load32(cpu->esi + 0x290u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C90E3;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC90E3u); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    label_000C90E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C90E3u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x274u)) < (uint32_t)(0x10u)) goto label_000C90FB;
    cpu->eax = lift_load32(cpu->esi + 0x260u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C90F8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C90FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C90FBu);
    lift_store32(cpu->esi + 0x274u, 0xFu);
    lift_store32(cpu->esi + 0x270u, 0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store8(cpu->esi + 0x260u, 0u);
    lift_store8(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9126u); lift_push32(cpu, r); sfera_sub_004CF160(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9135u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9150u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9158u); lift_push32(cpu, r); sfera_sub_004C9080(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C9168;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9165u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C9168: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9168u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9170u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_000C91F2;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    lift_store16(cpu->esi + 0x250u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9196u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esi + 0x260u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C91A7u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x290u);
    lift_store32(cpu->esi + 0x284u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000C91C2;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C91BCu); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x290u, cpu->ebx);
    label_000C91C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C91C2u);
    cpu->ecx = lift_load32(cpu->esi + 0x288u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000C91D7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C91D1u); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x288u, cpu->ebx);
    label_000C91D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C91D7u);
    cpu->ecx = lift_load32(cpu->esi + 0x28Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000C923F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C91E6u); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x28Cu, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C91F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C91F2u);
    cpu->eax = lift_load32(cpu->esi + 0x1B8u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000C9229;
    cpu->edx = cpu->ebp;
    (void)cpu;
    label_000C9200: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9200u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C9220;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000C921C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C9220;
    cpu->eax += 2u;
    cpu->edx += 2u;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000C9200;
    label_000C921C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C921Cu);
    cpu->eax = 0u;
    goto label_000C9225;
    label_000C9220: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9220u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000C9225: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9225u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000C9235;
    label_000C9229: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9229u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC9235u); lift_push32(cpu, r); sfera_sub_004CF1A0(cpu,r); if (cpu->eip != r) return; }
    label_000C9235: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9235u);
    lift_store16(cpu->esi + 0x250u, 0x100u);
    cpu->edi = lift_pop32(cpu);
    label_000C923F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C923Fu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9250u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x48u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFEC77u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xBu)) goto label_000C9589;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000C92A0;
        case 1u: goto label_000C9316;
        case 2u: case 3u: goto label_000C9589;
        case 4u: goto label_000C92B2;
        case 5u: goto label_000C9533;
        case 6u: goto label_000C950C;
        case 7u: goto label_000C9519;
        case 8u: goto label_000C9526;
        case 9u: goto label_000C9375;
        case 10u: goto label_000C9483;
        case 11u: goto label_000C93FA;
        default: lift_trap(cpu, 0x4C9299u, "resolved jump-table index out of range"); return;
    }
label_000C92A0: ;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC92A8u); lift_push32(cpu, r); sfera_sub_004C9170(cpu,r); if (cpu->eip != r) return; }
    label_000C92A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92A8u);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C92B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92B2u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000C92FB;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x274u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x260u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C92C7;
    cpu->eax = lift_load32(cpu->eax);
    label_000C92C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92C7u);
    cpu->ecx = cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000C92D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92D0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C92F0;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000C92EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C92F0;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C92D0;
    label_000C92EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92ECu);
    cpu->eax = 0u;
    goto label_000C92F5;
    label_000C92F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92F0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000C92F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92F5u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C930C;
    goto label_000C9300;
    label_000C92FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C92FBu);
    cpu->edi = (uint32_t)(uintptr_t)"";
    label_000C9300: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9300u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x260u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC930Cu); lift_push32(cpu, r); sfera_sub_0049D560(cpu,r); if (cpu->eip != r) return; }
    label_000C930C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C930Cu);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9316: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9316u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C934D;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C9328;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C92A8;
    cpu->eax = 0x366425u;
    goto label_000C932D;
    label_000C9328: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9328u);
    cpu->eax = 0x821C1Bu;
    label_000C932D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C932Du);
    lift_store32(cpu->esi + 0x1A4u, 0x8Cu);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    label_000C9343: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9343u);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C934D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C934Du);
    lift_store32(cpu->esi + 0x1A8u, 0x141414u);
    lift_store32(cpu->esi + 0x1A4u, 0x80u);
    lift_store32(cpu->esi + 0x1ACu, 0xFF9E7C6Au);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9375: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9375u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000C9396;
    cpu->ecx = lift_load32(cpu->esi + 0x288u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C9343;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9388u); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x288u, cpu->edi);
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    goto label_000C9597;
    label_000C9396: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9396u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x288u)) != (uint32_t)(0u)) goto label_000C93E4;
    cpu->edx = 0x253u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C93AEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C93B8u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C93D4;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C93D2u); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    goto label_000C93D6;
    label_000C93D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C93D4u);
    cpu->eax = 0u;
    label_000C93D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C93D6u);
    lift_store32(cpu->esp + 0x3Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x288u, cpu->eax);
    label_000C93E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C93E4u);
    cpu->ecx = lift_load32(cpu->esi + 0x288u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C93F0u); lift_push32(cpu, r); sfera_sub_004CF1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C93FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C93FAu);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000C941F;
    cpu->ecx = lift_load32(cpu->esi + 0x290u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C9343;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9411u); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x290u, cpu->edi);
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    goto label_000C9597;
    label_000C941F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C941Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x290u)) != (uint32_t)(0u)) goto label_000C946D;
    cpu->edx = 0x264u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9437u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9441u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C945D;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C945Bu); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    goto label_000C945F;
    label_000C945D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C945Du);
    cpu->eax = 0u;
    label_000C945F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C945Fu);
    lift_store32(cpu->esp + 0x3Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x290u, cpu->eax);
    label_000C946D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C946Du);
    cpu->ecx = lift_load32(cpu->esi + 0x290u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9479u); lift_push32(cpu, r); sfera_sub_004CF1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9483: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9483u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000C94A8;
    cpu->ecx = lift_load32(cpu->esi + 0x28Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C9343;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C949Au); lift_push32(cpu, r); sfera_sub_004CF280(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x28Cu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    goto label_000C9597;
    label_000C94A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C94A8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x28Cu)) != (uint32_t)(0u)) goto label_000C94F6;
    cpu->edx = 0x275u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C94C0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C94CAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C94E6;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C94E4u); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    goto label_000C94E8;
    label_000C94E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C94E6u);
    cpu->eax = 0u;
    label_000C94E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C94E8u);
    lift_store32(cpu->esp + 0x3Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x28Cu, cpu->eax);
    label_000C94F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C94F6u);
    cpu->ecx = lift_load32(cpu->esi + 0x28Cu);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9502u); lift_push32(cpu, r); sfera_sub_004CF1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C950C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C950Cu);
    lift_store32(cpu->esi + 0x1A8u, cpu->edi);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9519: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9519u);
    lift_store32(cpu->esi + 0x1A4u, cpu->edi);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9526: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9526u);
    lift_store32(cpu->esi + 0x1ACu, cpu->edi);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9533: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9533u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x284u)) == (uint32_t)(cpu->edi)) goto label_000C9343;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000C955B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9550u); lift_push32(cpu, r); sfera_sub_0049D560(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x284u, cpu->edi);
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    goto label_000C9597;
    label_000C955B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C955Bu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C9566u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C956Cu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C957Cu); lift_push32(cpu, r); sfera_sub_0049D560(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x284u, cpu->edi);
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9589: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9589u);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC9597u); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    label_000C9597: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9597u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C95F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C95F0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9607u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x9Cu)) != (uint32_t)(0u)) goto label_000C962D;
    lift_push32(cpu, 0xA1u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9624u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C962Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C962D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C962Du);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotpic");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C963Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C9654;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotFull");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9650u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C969F;
    label_000C9654: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9654u);
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9662u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9698;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9676u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x198u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C9698;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, (uintptr_t)"SlotCtrl:: Sprite not found '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C968Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9695u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000C9698: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9698u);
    lift_store8(cpu->edi + 0x250u, 1u);
    label_000C969F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C969Fu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotempty");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C96ACu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C96F4;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C96BEu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C96F4;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C96D2u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x19Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C96F4;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, (uintptr_t)"SlotCtrl:: Sprite not found '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C96EBu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C96F1u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000C96F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C96F4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotborder");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9701u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9749;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9713u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9749;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9727u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1A0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C9749;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, (uintptr_t)"SlotCtrl:: Sprite not found '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9740u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9746u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000C9749: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9749u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotpicofs");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9757u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C97A2;
    cpu->ecx = (uint32_t)(cpu->edi + 0x1B4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x1B0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xC977Au), LIFT_CODE_TOKEN_RVA(0xC9778u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C977Au);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000C97A2;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SlotCtrl::LoadUI(%s,%d,%d) Invalid args in 'slotpicofs'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9799u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C979Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C97A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C97A2u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"textofs");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C97AFu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C97F4;
    cpu->ecx = (uint32_t)(cpu->edi + 0x280u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x27Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xC97CCu), LIFT_CODE_TOKEN_RVA(0xC97CAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C97CCu);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000C97F4;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SlotCtrl::LoadUI(%s,%d,%d) Invalid args in 'textofs'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C97EBu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C97F1u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C97F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C97F4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotnumber");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9801u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9847;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C980Fu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9847;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C981Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9824u);
    cpu->eax = (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value;
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000C9830: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9830u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9830;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC9847u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000C9847: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9847u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotItem");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9854u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9877;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9867u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9877;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC9877u); lift_push32(cpu, r); sfera_sub_004C9170(cpu,r); if (cpu->eip != r) return; }
    label_000C9877: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9877u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9883u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9890u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C989Eu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1A0u);
    lift_store32(cpu->esi + 0x1A0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1A4u);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1A8u);
    lift_store32(cpu->esi + 0x1A8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1B0u);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    cpu->edx = (uint32_t)(cpu->edi + 0x1B8u);
    lift_store32(cpu->esi + 0x1B4u, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9910u); lift_push32(cpu, r); sfera_sub_004CEFF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load8(cpu->edi + 0x250u);
    lift_store8(cpu->esi + 0x250u, cpu->eax & 0xFFu);
    cpu->ecx = lift_load8(cpu->edi + 0x251u);
    lift_store8(cpu->esi + 0x251u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 0x254u);
    lift_store32(cpu->esi + 0x254u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x258u);
    lift_store32(cpu->esi + 0x258u, cpu->eax);
    cpu->ecx = lift_load8(cpu->edi + 0x25Cu);
    lift_store8(cpu->esi + 0x25Cu, cpu->ecx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x25Du)) & 0xFFu);
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_store8(cpu->esi + 0x25Du, cpu->edx & 0xFFu);
    cpu->eax = lift_load8(cpu->edi + 0x25Eu);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x260u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x260u);
    lift_store8(cpu->esi + 0x25Eu, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C997Eu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x27Cu);
    lift_store32(cpu->esi + 0x27Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x280u);
    lift_store32(cpu->esi + 0x280u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x284u);
    lift_store32(cpu->esi + 0x284u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x288u);
    lift_store32(cpu->esi + 0x288u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x28Cu);
    lift_store32(cpu->esi + 0x28Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x290u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x290u, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C99D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C99D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x1B0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9A04u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x298u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9A0Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9A2C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9A28u); lift_push32(cpu, r); sfera_sub_004C8F60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000C9A2E;
    label_000C9A2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9A2Cu);
    cpu->esi = 0u;
    label_000C9A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9A2Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9A3Eu); lift_push32(cpu, r); sfera_sub_004C9890(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000C9A66;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9A58u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC9A66u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C9A66: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9A66u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9A80u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%dx%d %d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C9A95u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9A9Bu);
    cpu->esp += 0x14u;
    cpu->eax = (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9AF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS_NUMBER";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9AFFu); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C9B13;
    label_000C9B05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9B05u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.working_bindings[0])))) goto label_000C9B48;
    ++cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000C9B05;
    label_000C9B13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9B13u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000C9B48;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x1Bu)) goto label_000C9B48;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x70u)) goto label_000C9B48;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xDu)) goto label_000C9B48;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFD0u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(9u)) goto label_000C9B48;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x10u)) goto label_000C9B48;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x11u)) goto label_000C9B48;
    cpu->esi += 0xFFFFFFDBu;
    cpu->ecx = 3u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C9B48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9B48u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9B50u);
    g_sfera_graphics_options_runtime.dialog_state = (uint32_t)(0u);
    g_sfera_control_options.working_bindings[0] = (uint32_t)(0x57u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[1], 0x53u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[2], 0x41u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[3], 0x44u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[4], 0x20u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[5], 0xC0u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[6], 0xBDu);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[7], 9u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[8], 0x52u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[9], 0x49u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[10], 0x4Bu);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[11], 0x48u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[12], 0x54u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[13], 0x4Eu);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[14], 0x50u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[15], 0x4Du);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[16], 0x4Au);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[17], 0x4Fu);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[18], 0x59u);
    lift_store32((uintptr_t)&g_sfera_control_options.working_bindings[19], 0xBFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9C30u);
    if ((uint32_t)(lift_load32(cpu->edx + 8u)) != (uint32_t)(0x64u)) goto label_000C9C3D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    goto label_000C9CD0;
    label_000C9C3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9C3Du);
    lift_return(cpu, 0u, stop_address); return;
    label_000C9CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9CD0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"authors";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9CDDu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C9D0C;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C9D0B;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9CEDu); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"authors";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9CFDu); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9D0B;
    lift_store32(cpu->eax + 0xF8u, LIFT_CALLBACK(sfera_sub_004C9C30));
    label_000C9D0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9D0Bu);
    lift_return(cpu, 0u, stop_address); return;
    label_000C9D0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9D0Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9D0B;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9D1Cu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    sfera_sub_004CD1A0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9C40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9C40u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x64u)) goto label_000C9C5F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3E9u)) goto label_000C9C5E;
    cpu->eax = 1u;
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(cpu->eax)) goto label_000C9C5E;
    g_sfera_render_lookup_runtime.initialized = (uint32_t)(cpu->eax);
    label_000C9C5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9C5Eu);
    lift_return(cpu, 0u, stop_address); return;
    label_000C9C5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9C5Fu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9C70u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"quit";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9C7Du); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C9CAC;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C9CAB;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9C8Du); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"quit";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9C9Du); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9CAB;
    lift_store32(cpu->eax + 0xF8u, LIFT_CALLBACK(sfera_sub_004C9C40));
    label_000C9CAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9CABu);
    lift_return(cpu, 0u, stop_address); return;
    label_000C9CAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9CACu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9CAB;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9CBCu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    sfera_sub_004CD1A0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9D30u);
    cpu->eax = g_sfera_options_dialog_runtime.widget_keys_initialized;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9D40u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9D60u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.end;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_options_dialog_runtime.graphics_modes.begin;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C9DA6;
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    (void)cpu;
    label_000C9D90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9D90u);
    if ((uint32_t)(lift_load32(cpu->eax + 0xFFFFFFF8u)) != (uint32_t)(cpu->ecx)) goto label_000C9D9E;
    if ((uint32_t)(lift_load32(cpu->eax + 0xFFFFFFFCu)) != (uint32_t)(cpu->ebx)) goto label_000C9D9E;
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->edx)) goto label_000C9DDE;
    label_000C9D9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9D9Eu);
    ++cpu->edi;
    cpu->eax += 0xCu;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->esi)) goto label_000C9D90;
    label_000C9DA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9DA6u);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000C9DD4;
    cpu->edi = g_sfera_scene_control_runtime.timing_anchor;
    cpu->ebx = g_sfera_recovered_static_runtime.scene_state_07;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    label_000C9DC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9DC0u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->edx)) goto label_000C9DCE;
    if ((uint32_t)(lift_load32(cpu->ecx + 0xFFFFFFFCu)) > (uint32_t)(cpu->edi)) goto label_000C9DCE;
    if ((uint32_t)(lift_load32(cpu->ecx)) <= (uint32_t)(cpu->ebx)) goto label_000C9DD7;
    label_000C9DCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9DCEu);
    cpu->ecx -= 0xCu;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C9DC0;
    label_000C9DD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9DD4u);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    label_000C9DD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9DD7u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C9DDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9DDEu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9DF0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.end;
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_options_dialog_runtime.graphics_modes.begin;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C9E36;
    cpu->edx = (uint32_t)(cpu->edi + 8u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->edi;
    label_000C9E20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9E20u);
    if ((uint32_t)(lift_load32(cpu->edx + 0xFFFFFFF8u)) != (uint32_t)(cpu->ecx)) goto label_000C9E2E;
    if ((uint32_t)(lift_load32(cpu->edx + 0xFFFFFFFCu)) != (uint32_t)(cpu->ebx)) goto label_000C9E2E;
    if ((uint32_t)(lift_load32(cpu->edx)) == (uint32_t)(cpu->edi)) goto label_000C9E3E;
    label_000C9E2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9E2Eu);
    ++cpu->esi;
    cpu->edx += 0xCu;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_000C9E20;
    label_000C9E36: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9E36u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C9E3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9E3Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9E50u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C9EA7;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x15555555u)) goto label_000C9E79;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9E72u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C9EA7;
    label_000C9E79: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9E79u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC9EA7u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000C9EA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9EA7u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9EB0u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT21";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9EBBu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000C9EC7;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9EC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9EC7u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[0][0];
    cpu->edx -= cpu->eax;
    cpu->edi = cpu->edi;
    label_000C9ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9ED0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9ED0;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT20";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9EE4u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000C9EEB;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9EEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9EEBu);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[1][0];
    cpu->edx -= cpu->eax;
    label_000C9EF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9EF2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9EF2;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT19";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9F06u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000C9F0D;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9F0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F0Du);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[2][0];
    cpu->edx -= cpu->eax;
    label_000C9F14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F14u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9F14;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT18";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9F28u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000C9F2F;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9F2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F2Fu);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[3][0];
    cpu->edx -= cpu->eax;
    label_000C9F36: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F36u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9F36;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9F4Au); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000C9F51;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9F51: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F51u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[4][0];
    cpu->edx -= cpu->eax;
    label_000C9F58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F58u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9F58;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9F6Cu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000C9F73;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9F73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F73u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edx -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000C9F80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9F80;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9F94u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000C9F9B;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9F9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9F9Bu);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[6][0];
    cpu->edx -= cpu->eax;
    label_000C9FA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9FA2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9FA2;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT36";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9FB6u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C9FBE;
    cpu->eax = lift_load32(cpu->eax);
    label_000C9FBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9FBEu);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->edx -= cpu->eax;
    label_000C9FC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9FC5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C9FC5;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C9FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9FD0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000C9FFF;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000C9FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9FE0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C9FF4;
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 8u, cpu->esi);
    label_000C9FF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9FF4u);
    cpu->ecx += 0xCu;
    cpu->eax += 0xCu;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000C9FE0;
    cpu->esi = lift_pop32(cpu);
    label_000C9FFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9FFFu);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CA0E5(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA0E5u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA0EEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA0FAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4CA0FAu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CA100(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000CA100;
    label_000CA010: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA010u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0x15555555u)) goto label_000CA053;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xCA053u);
    label_000CA053: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA053u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_000CA0D1;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA077u); lift_push32(cpu, r); sfera_sub_004C9E50(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA093u); lift_push32(cpu, r); sfera_sub_004C9FD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000CA0B7;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA0B4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000CA0B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA0B7u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->esi, cpu->eax);
    label_000CA0D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA0D1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000CA100: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA100u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    cpu->edx = 0x15555555u;
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->esi)) goto label_000CA133;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xCA133u);
    label_000CA133: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA133u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->esi += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000CA174;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0x15555555u;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000CA161;
    cpu->eax = 0u;
    goto label_000CA163;
    label_000CA161: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA161u);
    cpu->eax += cpu->edx;
    label_000CA163: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA163u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_000CA169;
    cpu->eax = cpu->esi;
    label_000CA169: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA169u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    goto label_000CA010;
    label_000CA174: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA174u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CA180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA180u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x64u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CA2D8;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CA2E0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x384u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CA21B;
    cpu->edx = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CA276;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CA2D8;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(7u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CA21B;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.graphics_values[12]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.graphics_values[12] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA21D;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT33";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA1D0u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA1DA;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA1DC;
    label_000CA1DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA1DAu);
    cpu->ecx = cpu->eax;
    label_000CA1DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA1DCu);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA202;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA202: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA202u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CA207: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA207u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA207;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA21Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_000CA21B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA21Bu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA21D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA21Du);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT34";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA227u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA231;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA233;
    label_000CA231: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA231u);
    cpu->ecx = cpu->eax;
    label_000CA233: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA233u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA259;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA259: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA259u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000CA260: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA260u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA260;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA273u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA276: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA276u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_sphere_options_runtime.saved_music_volume); lift_push32(cpu, 0xA28u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA2A0u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.audio_settings); lift_push32(cpu, 0xA28u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA2CCu);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[12];
    g_sfera_graphics_options_runtime.graphics_values[7] = (uint32_t)(cpu->ecx);
    label_000CA2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA2D8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    goto label_000CA300;
    label_000CA2E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA2E0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + 4u)), r=(uint64_t)(7u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->edx + 0xCu);
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CA2EF;
    sfera_sub_004982F0(cpu, stop_address); return;
    label_000CA2EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA2EFu);
    sfera_sub_00497B60(cpu, stop_address); return;
    label_000CA300: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA300u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"sound_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA30Du); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CA49F;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA445;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA324u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"sound_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA334u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000CA445;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebx + 0xF8u, LIFT_CALLBACK(sfera_sub_004CA180));
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x4CA34Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA34Fu);
    g_sfera_sphere_options_runtime.saved_music_volume = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA359u); lift_push32(cpu, r); sfera_sub_00497980(cpu,r); if (cpu->eip != r) return; }
    g_sfera_options_dialog_runtime.audio_settings = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA398u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3AAu);
    cpu->eax = g_sfera_sphere_options_runtime.saved_music_volume;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3C0u);
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3D7u);
    lift_native_call(cpu, native_function_address32(&SI_GetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA3D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3DDu);
    cpu->eax = cpu->eax & 0xFFu;
    g_sfera_graphics_options_runtime.graphics_values[7] = (uint32_t)(cpu->eax);
    g_sfera_graphics_options_runtime.graphics_values[12] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA447;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT33";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA3F8u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA402;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA404;
    label_000CA402: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA402u);
    cpu->ecx = cpu->eax;
    label_000CA404: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA404u);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA42A;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA42A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA42Au);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000CA430: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA430u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA430;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA443u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000CA445: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA445u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA447: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA447u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT34";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA451u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA45B;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA45D;
    label_000CA45B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA45Bu);
    cpu->ecx = cpu->eax;
    label_000CA45D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA45Du);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA483;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA483: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA483u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CA488: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA488u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA488;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA49Bu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA49F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA49Fu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CA445;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4AFu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_sphere_options_runtime.saved_music_volume;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4BAu); lift_push32(cpu, r); sfera_sub_004982F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4C5u); lift_push32(cpu, r); sfera_sub_00497B60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4CCu); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.graphics_values[7]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&SI_SetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA4DAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA4E0u);
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4EDu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_options_dialog_runtime.audio_settings;
    cpu->ecx = (uint32_t)(uintptr_t)"SNDVOL";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4FDu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_sphere_options_runtime.saved_music_volume;
    cpu->ecx = (uint32_t)(uintptr_t)"MUSVOL";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA50Du); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[7];
    cpu->ecx = (uint32_t)(uintptr_t)"HWMIX";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA51Du); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00448490(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CA530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA530u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3E9u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000CA804;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CA60A;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFu)) goto label_000CA565;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x64u)) goto label_000CA800;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000CA890;
    label_000CA565: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA565u);
    if ((uint32_t)(g_sfera_control_options.active_slot) == (uint32_t)(0xFFFFFFFFu)) goto label_000CA800;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA57Bu); lift_push32(cpu, r); sfera_sub_004B8230(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (uint32_t)(uintptr_t)"control_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA588u); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000CA800;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA599u); lift_push32(cpu, r); sfera_sub_004C9AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_control_options.active_slot;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CA5AA;
    lift_store32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.working_bindings[0]), cpu->esi);
    label_000CA5AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA5AAu);
    cpu->eax = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA5C2u); lift_push32(cpu, r); sfera_sub_004B8750(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = g_sfera_control_options.active_slot;
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.working_bindings[0]));
    cpu->esi = lift_load32(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA5E3u); lift_push32(cpu, r); sfera_sub_004BEC00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA5EE;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA5EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA5EEu);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CA5F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA5F3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA5F3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA606u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA60A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA60Au);
    cpu->eax = lift_load32(cpu->esi + 4u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(5u)) goto label_000CA800;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000CA61E;
        case 1u: goto label_000CA62F;
        case 2u: case 4u: goto label_000CA800;
        case 3u: goto label_000CA63B;
        case 5u: goto label_000CA6EB;
        default: lift_trap(cpu, 0x4CA617u, "resolved jump-table index out of range"); return;
    }
label_000CA61E: ;
    cpu->ecx = 0x40u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_control_options.working_bindings[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0];
    lift_movs32(cpu, 1u);
    label_000CA62F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA62Fu);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000CA890;
    label_000CA63B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA63Bu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.dialog_state), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.dialog_state = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA69D;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT23";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA659u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA663;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA665;
    label_000CA663: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA663u);
    cpu->ecx = cpu->eax;
    label_000CA665: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA665u);
    cpu->edx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA681;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA681: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA681u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CA686: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA686u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA686;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA699u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA69D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA69Du);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT24";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA6A7u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA6B1;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA6B3;
    label_000CA6B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA6B1u);
    cpu->ecx = cpu->eax;
    label_000CA6B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA6B3u);
    cpu->eax = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA6CF;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA6CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA6CFu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CA6D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA6D4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA6D4;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA6E7u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA6EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA6EBu);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA6F1u); lift_push32(cpu, r); sfera_sub_004C9B50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_graphics_options_runtime.dialog_state) != (uint32_t)(0u)) goto label_000CA739;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT23";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA704u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA70E;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA710;
    label_000CA70E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA70Eu);
    cpu->ecx = cpu->eax;
    label_000CA710: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA710u);
    cpu->edx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA72A;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CA72A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA72Au);
    cpu->eax = cpu->ecx;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000CA730: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA730u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CA730;
    goto label_000CA777;
    label_000CA739: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA739u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT24";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA743u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA74D;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA74F;
    label_000CA74D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA74Du);
    cpu->ecx = cpu->eax;
    label_000CA74F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA74Fu);
    cpu->eax = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA769;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CA769: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA769u);
    cpu->eax = cpu->ecx;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000CA770: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA770u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CA770;
    label_000CA777: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA777u);
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA783u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS_NUMBER";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA7A7u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000CA7FE;
    (void)cpu;
    label_000CA7B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA7B0u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA7BBu); lift_push32(cpu, r); sfera_sub_004B8750(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.working_bindings[0]));
    cpu->edi = lift_load32(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA7D6u); lift_push32(cpu, r); sfera_sub_004BEC00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA7E1;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA7E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA7E1u);
    cpu->eax = cpu->edx;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    label_000CA7E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA7E6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA7E6;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA7F9u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000CA7B0;
    label_000CA7FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA7FEu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000CA800: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA800u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA804: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA804u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFA1u)) goto label_000CA800;
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) != (uint32_t)(0x3E9u)) goto label_000CA800;
    { uint64_t l=(uint64_t)(lift_load16(cpu->esi + 0x12u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    cpu->edx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edi = lift_load16(cpu->esi + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CA800;
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA83Bu); lift_push32(cpu, r); sfera_sub_004B8750(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx += 0x54u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA859u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    g_sfera_control_options.active_slot = (uint32_t)(cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = LIFT_CALLBACK(sfera_sub_004CA530);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004B8230(cpu, stop_address); return;
    label_000CA890: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA890u);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(uintptr_t)"control_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA8ADu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CAB0E;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CABB6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA8C4u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"control_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA8D4u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000CABB6;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x100u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_control_options.configured_bindings[0]);
    lift_store32(cpu->ebx + 0xF8u, LIFT_CALLBACK(sfera_sub_004CA530));
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4CA8F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA8FAu);
    cpu->esp += 0xCu;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS_NUMBER";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA909u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    cpu->esi = 0u;
    label_000CA911: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA911u);
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA91Du); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA924u); lift_push32(cpu, r); sfera_sub_004BEBA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]), cpu->eax);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(5u)) goto label_000CA911;
    cpu->esi = 5u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000CA958;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CA940: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA940u);
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA94Cu); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]), cpu->eax);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000CA940;
    label_000CA958: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA958u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"INMS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA964u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x40u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_control_options.working_bindings[0];
    g_sfera_control_options.configured_bindings[63] = (uint32_t)(cpu->eax);
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA9BC;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT23";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA988u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA992;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA994;
    label_000CA992: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA992u);
    cpu->ecx = cpu->eax;
    label_000CA994: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA994u);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA9AE;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CA9AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9AEu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CA9B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9B3u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CA9B3;
    goto label_000CA9F8;
    label_000CA9BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9BCu);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT24";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA9C6u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA9D0;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA9D2;
    label_000CA9D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9D0u);
    cpu->ecx = cpu->eax;
    label_000CA9D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9D2u);
    cpu->edx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA9EC;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CA9EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9ECu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CA9F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9F1u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CA9F1;
    label_000CA9F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9F8u);
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAA04u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000CAAF1;
    goto label_000CAA2B;
    label_000CAA27: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA27u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_000CAA2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA2Bu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xFA2u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA3Du);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAA46u); lift_push32(cpu, r); sfera_sub_004B8750(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"UISTR_WT_KEY%02u"); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0]);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CAA5Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA60u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAA6Du); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAA75;
    cpu->eax = lift_load32(cpu->eax);
    label_000CAA75: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA75u);
    cpu->ecx = lift_load32(cpu->edi + 0xA0u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->edx);
    cpu->ebx = lift_load32(cpu->edx + 8u);
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CAA8D;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CAA8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA8Du);
    cpu->eax = cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    label_000CAA92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA92u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CAA92;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAAA5u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    cpu->edi = lift_load32(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAAC0u); lift_push32(cpu, r); sfera_sub_004BEC00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CAACB;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAACB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAACBu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CAAD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAAD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAAD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAAE3u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000CAA27;
    label_000CAAF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAAF1u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_options_dialog_runtime.widget_keys_initialized = (uint32_t)(1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000CAB0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB0Eu);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000CABB6;
    cpu->edx = (uint32_t)(cpu->ebx + 1u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB22u); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB29u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_control_options.configured_bindings[63];
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(uintptr_t)"INMS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB3Au); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CAB40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB40u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB4Du); lift_push32(cpu, r); sfera_sub_004BEB80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB59u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(5u)) goto label_000CAB40;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS_NUMBER";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB6Bu); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esi = 5u;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000CAB97;
    label_000CAB80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB80u);
    cpu->edx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB92u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edi)) goto label_000CAB80;
    label_000CAB97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB97u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x20u, 0x10u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CABB0u); lift_push32(cpu, r); sfera_sub_004BA680(cpu,r); if (cpu->eip != r) return; }
    g_sfera_options_dialog_runtime.widget_keys_initialized = (uint32_t)(cpu->ebx);
    label_000CABB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CABB6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CABD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000CABD0;
    label_000BC440: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC440u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_10;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC44Bu); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000BC46F;
    label_000BC456: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC456u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x4Eu)) == (uint8_t)(0u)) goto label_000BC469;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC464u); lift_push32(cpu, r); sfera_sub_004D1A60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BC469: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC469u);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_000BC456;
    label_000BC46F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC46Fu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C9AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C9AB0u);
    cpu->esp -= 0x20u;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_store32(cpu->esp + 8u, 0x10u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C9AD7u); lift_push32(cpu, r); sfera_sub_004BA680(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CABD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CABD0u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x64u)) goto label_000CB0A7;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3E9u)) goto label_000CAE2A;
    cpu->eax = lift_load32(cpu->edx + 4u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x15u)) goto label_000CAE2A;

    lift_push32(cpu, cpu->edi);
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000CAC06;
        case 1u: goto label_000CAC17;
        case 5u: goto label_000CADA6;
        case 6u: goto label_000CAC20;
        case 7u: goto label_000CACA2;
        case 8u: goto label_000CAD2C;
        case 10u: goto label_000CADAD;
        case 11u: goto label_000CAE2C;
        case 14u: goto label_000CAEAC;
        case 15u: goto label_000CAF2C;
        case 18u: goto label_000CAFB2;
        case 20u: goto label_000CB02A;
        case 21u: goto label_000CB09E;
        default: goto label_000CAE29;
    }
label_000CAC06: ;
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.interface_values[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[0];
    lift_movs32(cpu, 1u);
    label_000CAC17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAC17u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004CB100(cpu, stop_address); return;
    label_000CAC20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAC20u);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[0]), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, 0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"ISSN";
    g_sfera_graphics_options_runtime.interface_values[0] = (uint32_t)(cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAC3Du); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[0]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CAC50;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CAC50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAC50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAC55u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAC5F;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CAC61;
    label_000CAC5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAC5Fu);
    cpu->ecx = cpu->eax;
    label_000CAC61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAC61u);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CAC83;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAC83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAC83u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CAC88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAC88u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAC88;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAC9Bu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CACA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CACA2u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[1]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[1] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CACC0;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CACC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CACC0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CACC5u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CACCF;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CACD1;
    label_000CACCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CACCFu);
    cpu->ecx = cpu->eax;
    label_000CACD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CACD1u);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CACF5;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CACF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CACF5u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CAD00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAD00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAD00;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAD13u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[1];
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(uintptr_t)"ISAD";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAD25u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAD2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAD2Cu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[2]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[2] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CAD4A;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CAD4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAD4Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAD4Fu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAD59;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CAD5B;
    label_000CAD59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAD59u);
    cpu->ecx = cpu->eax;
    label_000CAD5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAD5Bu);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CAD81;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAD81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAD81u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CAD86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAD86u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAD86;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAD99u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_options_runtime.interface_values[2];
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    sfera_sub_004B87D0(cpu, stop_address); return;
    label_000CADA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CADA6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000BC440;
    label_000CADAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CADADu);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[3]), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[3] = (uint32_t)(cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CADC3u); lift_push32(cpu, r); sfera_sub_004B87C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[3]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CADD6;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CADD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CADD6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CADDBu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CADE5;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CADE7;
    label_000CADE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CADE5u);
    cpu->ecx = cpu->eax;
    label_000CADE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CADE7u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CAE11;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAE11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE11u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CAE16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE16u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAE16;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCAE29u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000CAE29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE29u);
    cpu->edi = lift_pop32(cpu);
    label_000CAE2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE2Au);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CAE2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE2Cu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[4]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[4] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CAE4A;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CAE4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE4Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAE4Fu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAE59;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CAE5B;
    label_000CAE59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE59u);
    cpu->edx = cpu->eax;
    label_000CAE5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE5Bu);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 0xBu;
    label_000CAE68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE68u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CAE68;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CAE79;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAE79: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE79u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000CAE80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAE80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAE80;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAE93u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[4];
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(uintptr_t)"IAPM";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAEA5u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAEAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAEACu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[5]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[5] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CAECA;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CAECA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAECAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAECFu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAED9;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CAEDB;
    label_000CAED9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAED9u);
    cpu->edx = cpu->eax;
    label_000CAEDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAEDBu);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    label_000CAEE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAEE8u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CAEE8;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CAEFB;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAEFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAEFBu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CAF00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAF00;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAF13u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[5];
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(uintptr_t)"MBST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAF25u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAF2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF2Cu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[6]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[6] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CAF4A;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CAF4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF4Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAF4Fu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAF59;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CAF5B;
    label_000CAF59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF59u);
    cpu->edx = cpu->eax;
    label_000CAF5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF5Bu);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 3u;
    label_000CAF68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF68u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CAF68;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CAF81;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAF81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF81u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CAF86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAF86u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAF86;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAF99u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[6];
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(uintptr_t)"BALR";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAFABu); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAFB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAFB2u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[7]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[7] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CAFD0;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CAFD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAFD0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAFD5u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAFDF;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CAFE1;
    label_000CAFDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAFDFu);
    cpu->edx = cpu->eax;
    label_000CAFE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAFE1u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 3u;
    cpu->edi = cpu->edi;
    label_000CAFF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAFF0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CAFF0;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CB00B;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB00B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB00Bu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB010: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB010u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB010;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB023u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CB02A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB02Au);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[8]), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_graphics_options_runtime.interface_values[8] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CB048;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB048: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB048u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB04Du); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CB057;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CB059;
    label_000CB057: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB057u);
    cpu->edx = cpu->eax;
    label_000CB059: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB059u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 4u;
    label_000CB066: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB066u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CB066;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CB07F;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB07F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB07Fu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB084: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB084u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB084;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB097u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CB09E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB09Eu);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    goto label_000CD260;
    label_000CB0A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB0A7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004CB100(cpu, stop_address); return;
    label_000CD260: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD260u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"font_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD27Cu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CD3AD;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CD410;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD293u); lift_push32(cpu, r); sfera_sub_004CB100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD29Du); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD2AD;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCD2ADu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    label_000CD2AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD2ADu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"font_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD2BDu); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000CD410;
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    lift_store32(cpu->esi + 0xF8u, LIFT_CALLBACK(sfera_sub_004CD1F0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD2DDu); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD2E9u); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    lift_store32(cpu->esp + 0xCu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD300u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    lift_store32(cpu->esp + 0xCu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD317u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD321u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_LIST_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD331u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx += 4u;
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_EDIT_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD344u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD362u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD384u);
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.end;
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD39Cu); lift_push32(cpu, r); sfera_sub_004AB160(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CD3AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD3ADu);
    cpu->esi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000CD410;
    cpu->edx = (uint32_t)(cpu->esi + 1u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3BDu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3C4u); lift_push32(cpu, r); sfera_sub_004CB100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3CEu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_LIST_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3DFu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_EDIT_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3F2u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3F7u); lift_push32(cpu, r); sfera_sub_00448490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x14u, 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCD410u); lift_push32(cpu, r); sfera_sub_004BA680(cpu,r); if (cpu->eip != r) return; }
    label_000CD410: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD410u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CB100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB100u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"interface_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB11Cu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CB5AA;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CB6E2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB133u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"interface_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB143u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000CB6E2;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"ISSN";
    lift_store32(cpu->ebx + 0xF8u, LIFT_CALLBACK(sfera_sub_004CABD0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB163u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"ISAD";
    g_sfera_graphics_options_runtime.saved_interface_values[0] = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB174u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_graphics_options_runtime.saved_interface_values[1] = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB17Eu); lift_push32(cpu, r); sfera_sub_004B87E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"INAW";
    g_sfera_graphics_options_runtime.saved_interface_values[2] = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB18Fu); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"IAPM";
    g_sfera_graphics_options_runtime.saved_interface_values[3] = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB1A0u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    g_sfera_graphics_options_runtime.saved_interface_values[4] = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB1AFu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[5];
    cpu->ecx = (uint32_t)(uintptr_t)"MBST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB1BEu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[6];
    cpu->ecx = (uint32_t)(uintptr_t)"BALR";
    g_sfera_graphics_options_runtime.saved_interface_values[6] = (uint32_t)(0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB1D7u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_graphics_options_runtime.saved_interface_values[6]) >= (int32_t)(uint32_t)(0u)) goto label_000CB1FA;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)"BALR";
    g_sfera_graphics_options_runtime.saved_interface_values[6] = (uint32_t)(cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB1F5u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCB1FAu); lift_push32(cpu, r); sfera_sub_00448490(cpu,r); if (cpu->eip != r) return; }
    label_000CB1FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB1FAu);
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.saved_interface_values[0]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = g_sfera_interface_runtime.invite_messages;
    cpu->eax = g_sfera_interface_runtime.description_auto_popup;
    g_sfera_graphics_options_runtime.saved_interface_values[8] = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.interface_values[0];
    g_sfera_graphics_options_runtime.saved_interface_values[7] = (uint32_t)(cpu->eax);
    lift_movs32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB235;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB235: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB235u);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB23Bu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0x10u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB249;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CB24B;
    label_000CB249: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB249u);
    cpu->ecx = cpu->eax;
    label_000CB24B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB24Bu);
    cpu->edx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CB26B;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CB26B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB26Bu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CB270: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB270u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CB270;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB283u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[1]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB296;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB296: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB296u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB29Bu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB2A4;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CB2A6;
    label_000CB2A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB2A4u);
    cpu->ecx = cpu->eax;
    label_000CB2A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB2A6u);
    cpu->edx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CB2CA;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB2CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB2CAu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000CB2D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB2D0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB2D0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB2E3u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[2]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB2F6;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB2F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB2F6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB2FBu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB304;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CB306;
    label_000CB304: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB304u);
    cpu->ecx = cpu->eax;
    label_000CB306: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB306u);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CB32C;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB32C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB32Cu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB331: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB331u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB331;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB344u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[3]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB357;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB357: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB357u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB35Cu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB365;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CB367;
    label_000CB365: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB365u);
    cpu->ecx = cpu->eax;
    label_000CB367: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB367u);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CB391;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB391: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB391u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB396: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB396u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB396;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB3A9u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[4]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB3BC;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB3BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB3BCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB3C1u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB3CA;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CB3CC;
    label_000CB3CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB3CAu);
    cpu->edx = cpu->eax;
    label_000CB3CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB3CCu);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 0xBu;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CB3E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB3E0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CB3E0;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CB3F1;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB3F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB3F1u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB3F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB3F6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB3F6;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB409u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[5]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB41C;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB41C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB41Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB421u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB42A;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CB42C;
    label_000CB42A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB42Au);
    cpu->edx = cpu->eax;
    label_000CB42C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB42Cu);
    cpu->ecx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CB440: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB440u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CB440;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CB453;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB453: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB453u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB458: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB458u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB458;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB46Bu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[6]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB47E;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB47E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB47Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB483u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB48C;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CB48E;
    label_000CB48C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB48Cu);
    cpu->edx = cpu->eax;
    label_000CB48E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB48Eu);
    cpu->ecx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 3u;
    label_000CB4A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB4A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CB4A0;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CB4B9;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB4B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB4B9u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000CB4C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB4C0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB4C0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB4D3u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[7]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB4E6;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB4E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB4E6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB4EBu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000CB4F4;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CB4F6;
    label_000CB4F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB4F4u);
    cpu->edx = cpu->eax;
    label_000CB4F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB4F6u);
    cpu->ecx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 3u;
    label_000CB503: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB503u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CB503;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CB51E;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB51E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB51Eu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB523: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB523u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB523;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB536u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.interface_values[8]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB549;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    label_000CB549: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB549u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB54Eu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000CB558;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CB55A;
    label_000CB558: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB558u);
    cpu->edx = cpu->eax;
    label_000CB55A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB55Au);
    cpu->ecx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 4u;
    label_000CB567: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB567u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CB567;
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CB580;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CB580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB580u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CB585: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB585u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CB585;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB598u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CB5AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB5AAu);
    cpu->esi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000CB6E2;
    cpu->edx = (uint32_t)(cpu->esi + 1u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB5BEu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB5C5u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[0];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"ISSN";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB5D6u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[1];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"ISAD";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB5E7u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[2];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"INSN";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB5F8u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[3];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"INAW";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB609u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[4];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"IAPM";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB61Au); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[5];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"MBST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB62Bu); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[6];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"BALR";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB63Cu); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_options_runtime.saved_interface_values[7];
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[8];
    g_sfera_interface_runtime.description_auto_popup = (uint32_t)(cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    g_sfera_interface_runtime.invite_messages = (uint32_t)(cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB65Eu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[5];
    cpu->ecx = (uint32_t)(uintptr_t)"MBST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB66Eu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[6];
    cpu->ecx = (uint32_t)(uintptr_t)"BALR";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB67Eu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_runtime.hardware_cursor_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"HARDWARE_CURSOR";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB68Eu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_interface_runtime.description_auto_popup;
    cpu->ecx = (uint32_t)(uintptr_t)"DESCR_AUTO_POPUP";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB69Eu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_interface_runtime.invite_messages;
    cpu->ecx = (uint32_t)(uintptr_t)"INVITE_MESSAGES";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB6AEu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB6B3u); lift_push32(cpu, r); sfera_sub_00448490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_options_runtime.saved_interface_values[2];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB6BEu); lift_push32(cpu, r); sfera_sub_004B87D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 0x10u, 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB6D7u); lift_push32(cpu, r); sfera_sub_004BA680(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_options_runtime.saved_interface_values[3];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCB6E2u); lift_push32(cpu, r); sfera_sub_004B87C0(cpu,r); if (cpu->eip != r) return; }
    label_000CB6E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB6E2u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CB700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB700u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000CB75D;
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->esi)) goto label_000CB75D;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000CB735;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCB735u); lift_push32(cpu, r); sfera_sub_004CA100(cpu,r); if (cpu->eip != r) return; }
    label_000CB735: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB735u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CB782;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000CB75D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB75Du);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000CB76B;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCB76Bu); lift_push32(cpu, r); sfera_sub_004CA100(cpu,r); if (cpu->eip != r) return; }
    label_000CB76B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB76Bu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CB782;
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    label_000CB782: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB782u);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CB790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB790u);
    cpu->esp -= 0x40u;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store8(cpu->esp + 0xCu, cpu->ecx & 0xFFu);
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x34u, 0x17u);
    lift_store32(cpu->esp + 0x38u, 0x16u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(g_sfera_options_dialog_runtime.graphics_modes.end)) goto label_000CB7D5;
    g_sfera_options_dialog_runtime.graphics_modes.end = (uint32_t)(cpu->ecx);
    label_000CB7D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB7D5u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_000CB7E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB7E0u);
    cpu->ebx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x34u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xCB7EFu), LIFT_CODE_TOKEN_RVA(0xCB7EDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB7EFu);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x16u)) goto label_000CB802;
    lift_store32(cpu->esp + 0x14u, 0x20u);
    goto label_000CB812;
    label_000CB802: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB802u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x17u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->ecx;
    cpu->ecx &= 0x10u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    label_000CB812: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB812u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000CB8D9;
    label_000CB820: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB820u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0xCB831u), LIFT_CODE_TOKEN_RVA(0xCB82Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB831u);
    cpu->edi = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->edi) < (uint32_t)(0x320u)) goto label_000CB8BE;
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0x258u)) goto label_000CB8BE;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.end;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_options_dialog_runtime.graphics_modes.begin), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB890;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx += 8u;
    label_000CB876: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB876u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xFFFFFFF8u)) != (uint32_t)(cpu->edi)) goto label_000CB888;
    if ((uint32_t)(lift_load32(cpu->ecx + 0xFFFFFFFCu)) != (uint32_t)(cpu->ebp)) goto label_000CB888;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->edx)) goto label_000CB8BE;
    label_000CB888: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB888u);
    ++cpu->esi;
    cpu->ecx += 0xCu;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_000CB876;
    label_000CB890: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB890u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x10u)) == (uint8_t)(0u)) goto label_000CB89F;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(g_sfera_recovered_static_runtime.scene_state_07)) goto label_000CB8BE;
    label_000CB89F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB89Fu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_modes;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCB8BEu); lift_push32(cpu, r); sfera_sub_004CB700(cpu,r); if (cpu->eip != r) return; }
    label_000CB8BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB8BEu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x30u))) goto label_000CB820;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_000CB8D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB8D9u);
    ++cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->edi) < (uint32_t)(2u)) goto label_000CB7E0;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.end;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_options_dialog_runtime.graphics_modes.begin), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CB933;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Found ZERO video modes!"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SphereOptions.cpp");
    lift_store32(cpu->esp + 0x20u, 0x1ACu);
    lift_store32(cpu->esp + 0x24u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB930u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000CB933: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB933u);
    cpu->esp += 0x40u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CB950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB950u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edx;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3E9u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000CBA23;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB985;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x64u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CBA16;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CC1D8;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CB985: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB985u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CB9E4;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC224;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CB999u); lift_push32(cpu, r); sfera_sub_004CC280(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.saved_fog_distance.f32));
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[9];
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[8];
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.saved_lod_distance.f32));
    cpu->edx = g_sfera_sphere_options_runtime.saved_lods_enabled;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25) = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_graphics_options_runtime.graphics_page;
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26) = (uint32_t)(cpu->ecx);
    g_sfera_graphics_runtime.lods_enabled = (uint32_t)(cpu->edx);
    g_sfera_options_dialog_runtime.reflection_quality = (uint32_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CB9E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CB9E4u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 7u;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.graphics_values[0];
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_movs32(cpu, 1u);
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCBA16u); lift_push32(cpu, r); sfera_sub_0041C1B0(cpu,r); if (cpu->eip != r) return; }
    label_000CBA16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBA16u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_004CC280(cpu, stop_address); return;
    label_000CBA23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBA23u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x157Du)) goto label_000CC224;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->eax += 0xFFFFFFF1u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x24u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000CC1D8;

    lift_push32(cpu, cpu->ebx);
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000CBA4C;
        case 2u: goto label_000CBAA3;
        case 3u: goto label_000CBB03;
        case 9u: goto label_000CBF22;
        case 11u: goto label_000CBB7C;
        case 19u: goto label_000CBF73;
        case 24u: goto label_000CBD7F;
        case 28u: goto label_000CBC1C;
        case 36u: goto label_000CC126;
        default: goto label_000CC1D7;
    }
label_000CBA4C: ;
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    g_sfera_options_dialog_runtime.graphics_snapshot[5] = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBA80u); lift_push32(cpu, r); sfera_sub_004C9A80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CBA8B;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBA8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBA8Bu);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CBA90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBA90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBA90;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    goto label_000CC1D2;
    label_000CBAA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBAA3u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = g_sfera_shadow_runtime.manager;
    g_sfera_options_dialog_runtime.graphics_snapshot[2] = (uint32_t)(cpu->eax);
    lift_store8(cpu->ecx + 0xA0u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[0][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBAE6;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBAE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBAE6u);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CBAF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBAF0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBAF0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    goto label_000CC1D2;
    label_000CBB03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBB03u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    g_sfera_options_dialog_runtime.graphics_snapshot[3] = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    g_sfera_main_render_runtime.grass_depth_mode = (uint32_t)(cpu->edx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000CBB64;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBB4C;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBB4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBB4Cu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CBB51: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBB51u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBB51;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    goto label_000CC1D2;
    label_000CBB64: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBB64u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000CBB70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBB70u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBB70;
    goto label_000CC1C7;
    label_000CBB7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBB7Cu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26) = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000CBBE3;
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 5u;
    cpu->edi = cpu->edi;
    label_000CBBA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBBA0u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBBA0;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBBC4;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBBC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBBC4u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CBBD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBBD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBBD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    goto label_000CC1D2;
    label_000CBBE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBBE3u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 5u;
    label_000CBBF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBBF0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBBF0;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CBC10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBC10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBC10;
    goto label_000CC1C7;
    label_000CBC1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBC1Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBCFE;
    cpu->ecx = 8u;
    label_000CBC35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBC35u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBC35;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[6][0];
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000CBC50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBC50u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBC50;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[6][0]);
    cpu->ecx = (uint32_t)(cpu->edx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBC67u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBC74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBC74u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBC74;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBC95u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBCA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBCA2u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBCA2;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (12.0));
    lift_store16(cpu->esp + 0x12u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x12u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, 0u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x18u));
    lift_store64(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Eu));
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBCEFu);
    g_sfera_graphics_runtime.lods_enabled = (uint32_t)(1u);
    goto label_000CC1D7;
    label_000CBCFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBCFEu);
    cpu->edx = 8u;
    label_000CBD03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBD03u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBD03;
    cpu->ebx = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBD25;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBD25: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBD25u);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CBD30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBD30u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBD30;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBD43u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBD50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBD50u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBD50;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBD70u);
    g_sfera_graphics_runtime.lods_enabled = (uint32_t)(0u);
    goto label_000CC1D7;
    label_000CBD7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBD7Fu);
    cpu->ebp = 1u;
    cpu->ecx = cpu->edx;
    if ((uint32_t)(lift_load32(cpu->ecx + 0xCu)) != (uint32_t)(cpu->ebp)) goto label_000CBE2B;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBD99u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CBDA3;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CBDA5;
    label_000CBDA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBDA3u);
    cpu->edx = cpu->eax;
    label_000CBDA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBDA5u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 6u;
    label_000CBDB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBDB2u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBDB2;
    cpu->ebx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CBDCE;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBDCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBDCEu);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CBDD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBDD3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBDD3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBDE6u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBDF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBDF3u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBDF3;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE10u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25) = (uint32_t)(cpu->ebp);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    goto label_000CC1D7;
    label_000CBE2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE2Bu);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBE35u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CBE3F;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CBE41;
    label_000CBE3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE3Fu);
    cpu->edx = cpu->eax;
    label_000CBE41: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE41u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 6u;
    cpu->edi = cpu->edi;
    label_000CBE50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE50u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBE50;
    cpu->ebx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CBE6C;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBE6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE6Cu);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CBE71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE71u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBE71;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBE84u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBE91: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBE91u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBE91;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0xAAu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBEB2u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBECB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBECBu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBECB;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (30.0));
    lift_store16(cpu->esp + 0x12u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x12u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_push32(cpu, 0u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store64(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Eu));
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF0Fu);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25) = (uint32_t)(0u);
    goto label_000CC1D7;
    label_000CBF22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF22u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    g_sfera_options_dialog_runtime.reflection_quality = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    label_000CBF37: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF37u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBF37;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(9u), 32u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[4][0];
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBF59;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBF59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF59u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000CBF60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF60u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBF60;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    goto label_000CC1D2;
    label_000CBF73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF73u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_options_dialog_runtime.graphics_snapshot[4] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000CBFD1;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT61";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBF90u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CBF9A;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CBF9C;
    label_000CBF9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF9Au);
    cpu->edx = cpu->eax;
    label_000CBF9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBF9Cu);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 0x11u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CBFB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBFB0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBFB0;
    cpu->ebx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CBFC3;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CBFC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBFC3u);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CBFC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBFC8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CBFC8;
    goto label_000CC017;
    label_000CBFD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBFD1u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT62";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CBFDBu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CBFE5;
    cpu->edx = lift_load32(cpu->eax);
    goto label_000CBFE7;
    label_000CBFE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBFE5u);
    cpu->edx = cpu->eax;
    label_000CBFE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBFE7u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0x11u;
    label_000CBFF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CBFF4u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CBFF4;
    cpu->ebx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000CC007;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CC007: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC007u);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CC010: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC010u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CC010;
    label_000CC017: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC017u);
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC023u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_options_dialog_runtime.graphics_snapshot[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    { uint64_t l=(uint64_t)(g_sfera_options_dialog_runtime.graphics_snapshot[4]), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    cpu->ebp = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 8u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC04Eu); lift_push32(cpu, r); sfera_sub_004CB790(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC058u); lift_push32(cpu, r); sfera_sub_004C9D60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_options_dialog_runtime.graphics_snapshot[5] = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 7u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CC070: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC070u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC070;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_modes;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC086u); lift_push32(cpu, r); sfera_sub_004C9D40(cpu,r); if (cpu->eip != r) return; }
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x157Fu);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC096u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC0A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC0A3u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC0A3;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.graphics_snapshot[5];
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC0C2u);
    cpu->eax = g_sfera_options_dialog_runtime.graphics_snapshot[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC0EFu); lift_push32(cpu, r); sfera_sub_004C9A80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CC0FA;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CC0FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC0FAu);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000CC100: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC100u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CC100;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC113u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    g_sfera_options_dialog_runtime.graphics_snapshot[0] = (uint32_t)(0u);
    goto label_000CC1D7;
    label_000CC126: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC126u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    g_sfera_options_dialog_runtime.graphics_snapshot[6] = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    g_sfera_graphics_runtime.post_effects_enabled = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000CC190;
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 8u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CC150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC150u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC150;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC174;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CC174: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC174u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CC180: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC180u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CC180;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    goto label_000CC1D2;
    label_000CC190: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC190u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 8u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000CC1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC1A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC1A0;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CC1C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC1C0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CC1C0;
    label_000CC1C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC1C7u);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0]);
    cpu->ecx = (uint32_t)(cpu->edx + 0x54u);
    label_000CC1D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC1D2u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCC1D7u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000CC1D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC1D7u);
    cpu->ebx = lift_pop32(cpu);
    label_000CC1D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC1D8u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x1Cu)) goto label_000CC208;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x2Eu)) goto label_000CC224;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CC1F5;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CC1F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC1F5u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (12.0));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CC208: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC208u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CC218;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CC218: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC218u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (30.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000CC224: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC224u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CC280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC280u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"gfx_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC290u); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CCEE0;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CCEDB;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC2A8u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"gfx_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC2B8u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000CCEDA;
    lift_store32(cpu->esi + 0xF8u, LIFT_CALLBACK(sfera_sub_004CB950));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.saved_fog_distance.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    cpu->edx = g_sfera_graphics_runtime.lods_enabled;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.saved_lod_distance.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebp);
    g_sfera_graphics_options_runtime.graphics_values[9] = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_options_dialog_runtime.reflection_quality;
    lift_push32(cpu, cpu->edi);
    g_sfera_graphics_options_runtime.graphics_values[8] = (uint32_t)(cpu->ecx);
    g_sfera_sphere_options_runtime.saved_lods_enabled = (uint32_t)(cpu->edx);
    g_sfera_graphics_options_runtime.graphics_page = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC317u); lift_push32(cpu, r); sfera_sub_004C9EB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC321u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(uintptr_t)"XRES";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC339u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_runtime.display_height;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(uintptr_t)"YRES";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC351u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_window_runtime.windowed), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC360u); lift_push32(cpu, r); sfera_sub_004CB790(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = g_sfera_shadow_runtime.manager;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000CC387;
    lift_push32(cpu, 0x2B6u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SphereOptions.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC37Eu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC384u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000CC387: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC387u);
    cpu->edi = g_sfera_graphics_display_depth_bits;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC39Bu); lift_push32(cpu, r); sfera_sub_004C9D60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_main_render_runtime.grass_depth_mode;
    g_sfera_graphics_options_runtime.graphics_values[3] = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_window_runtime.windowed;
    g_sfera_graphics_options_runtime.graphics_values[5] = (uint32_t)(cpu->eax);
    g_sfera_graphics_options_runtime.graphics_values[1] = (uint32_t)(cpu->edi);
    cpu->edx = lift_load8(cpu->ebp + 0xA0u);
    g_sfera_graphics_options_runtime.graphics_values[2] = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_graphics_runtime.post_effects_enabled;
    g_sfera_graphics_options_runtime.graphics_values[4] = (uint32_t)(cpu->ecx);
    g_sfera_options_dialog_runtime.pending_graphics_value = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[0];
    g_sfera_graphics_options_runtime.graphics_values[6] = (uint32_t)(cpu->edx);
    g_sfera_options_dialog_runtime.comparison_graphics_value = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    g_sfera_graphics_options_runtime.graphics_values[10] = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    g_sfera_graphics_options_runtime.graphics_values[11] = (uint32_t)(cpu->edi);
    cpu->ecx = 7u;
    (void)cpu;
    label_000CC400: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC400u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC400;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.end;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(g_sfera_options_dialog_runtime.graphics_modes.begin), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC437u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC444: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC444u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC444;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[5];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC464u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 4u;
    label_000CC471: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC471u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC471;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC490u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 4u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000CC4A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC4A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC4A0;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[2];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC4C4u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 0x11u;
    label_000CC4D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC4D1u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC4D1;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC4EAu);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0x11u;
    label_000CC4F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC4F7u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC4F7;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[3];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC515u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 5u;
    label_000CC522: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC522u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC522;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC543u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26)) == (uint32_t)(0u)) goto label_000CC5C4;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC556u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0x10u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CC564;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CC566;
    label_000CC564: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC564u);
    cpu->ecx = cpu->eax;
    label_000CC566: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC566u);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 5u;
    label_000CC573: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC573u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC573;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CC58E;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CC58E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC58Eu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CC593: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC593u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CC593;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC5A6u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 5u;
    label_000CC5B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC5B3u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC5B3;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    goto label_000CC640;
    label_000CC5C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC5C4u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC5CEu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0x10u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CC5DC;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CC5DE;
    label_000CC5DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC5DCu);
    cpu->ecx = cpu->eax;
    label_000CC5DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC5DEu);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 5u;
    label_000CC5F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC5F0u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC5F0;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CC60B;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CC60B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC60Bu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CC610: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC610u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CC610;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC623u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 5u;
    label_000CC630: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC630u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC630;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    label_000CC640: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC640u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC651u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    cpu->edi = cpu->edi;
    label_000CC660: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC660u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC660;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC683u);
    if ((uint32_t)(g_sfera_graphics_runtime.lods_enabled) == (uint32_t)(0u)) goto label_000CC7A2;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC69Au); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CC6A3;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CC6A5;
    label_000CC6A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC6A3u);
    cpu->ecx = cpu->eax;
    label_000CC6A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC6A5u);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 8u;
    label_000CC6B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC6B2u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC6B2;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CC6CB;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CC6CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC6CBu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CC6D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC6D0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CC6D0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC6E3u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC6F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC6F0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC6F0;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC713u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CC720: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC720u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC720;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC741u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    cpu->edi = cpu->edi;
    label_000CC750: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC750u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC750;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (12.0));
    lift_store16(cpu->esp + 0x12u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x12u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_push32(cpu, 0u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x20u));
    lift_store64(cpu->esp + 0x20u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Eu));
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC79Du);
    goto label_000CC851;
    label_000CC7A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC7A2u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC7ACu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CC7B5;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CC7B7;
    label_000CC7B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC7B5u);
    cpu->ecx = cpu->eax;
    label_000CC7B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC7B7u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = 8u;
    label_000CC7C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC7C4u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC7C4;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CC7DD;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CC7DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC7DDu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CC7E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC7E2u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CC7E2;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC7F5u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC802: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC802u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC802;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC824u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CC831: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC831u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC831;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CC851: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC851u);
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%dx%d %d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CC877u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC87Du);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text;
    cpu->esp += 0x14u;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000CC8A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC8A0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CC8A0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text);
    cpu->ecx += 0x54u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC8B7u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[2];
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[0][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC8E8;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CC8E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC8E8u);
    cpu->eax = cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000CC8F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC8F0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CC8F0;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC903u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[3];
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000CC950;
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC93B;
    cpu->edi = (uint32_t)(uintptr_t)"";
    label_000CC93B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC93Bu);
    cpu->eax = cpu->edi;
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    label_000CC940: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC940u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CC940;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx += 0x54u;
    goto label_000CC987;
    label_000CC950: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC950u);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CC975: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC975u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CC975;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0]);
    cpu->ecx = (uint32_t)(cpu->edx + 0x54u);
    label_000CC987: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC987u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC98Cu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = 0x13u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CC9A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC9A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC9A0;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC9BBu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25)) == (uint32_t)(0u)) goto label_000CCA79;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT16";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CC9D2u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CC9DB;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CC9DD;
    label_000CC9DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC9DBu);
    cpu->ecx = cpu->eax;
    label_000CC9DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC9DDu);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 6u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CC9F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CC9F0u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CC9F0;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CCA0B;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CCA0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA0Bu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CCA10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CCA10;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCA23u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0x13u;
    label_000CCA30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA30u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCA30;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA4Bu);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CCA58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA58u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCA58;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA74u);
    goto label_000CCB7D;
    label_000CCA79: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA79u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT17";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCA83u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CCA8C;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CCA8E;
    label_000CCA8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA8Cu);
    cpu->ecx = cpu->eax;
    label_000CCA8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCA8Eu);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 6u;
    label_000CCAA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCAA0u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCAA0;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CCABB;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CCABB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCABBu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CCAC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCAC0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CCAC0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCAD3u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0x13u;
    label_000CCAE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCAE0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCAE0;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCAFAu);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CCB07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCB07u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCB07;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0xAAu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCB27u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 9u;
    label_000CCB34: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCB34u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCB34;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (30.0));
    lift_store16(cpu->esp + 0x12u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x12u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xC00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_push32(cpu, 0u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x20u));
    lift_store64(cpu->esp + 0x20u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Eu));
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CCB7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCB7Du);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 0x17u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CCB90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCB90u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCB90;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCBA8u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0x17u;
    label_000CCBB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCBB5u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCBB5;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_options_dialog_runtime.reflection_quality;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCBD3u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 7u;
    label_000CCBE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCBE0u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCBE0;
    cpu->edx = g_sfera_options_dialog_runtime.reflection_quality;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(9u), 32u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[4][0];
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCC03;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CCC03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC03u);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CCC08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC08u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CCC08;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCC1Bu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 0xBu;
    label_000CCC28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC28u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCC28;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC45u);
    if ((uint32_t)(g_sfera_window_runtime.windowed) == (uint32_t)(0u)) goto label_000CCCC8;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT61";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCC58u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CCC61;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CCC63;
    label_000CCC61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC61u);
    cpu->ecx = cpu->eax;
    label_000CCC63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC63u);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 0x11u;
    label_000CCC70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC70u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCC70;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CCC83;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CCC83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC83u);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CCC88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCC88u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CCC88;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCC9Bu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0xBu;
    label_000CCCA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCCA8u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCCA8;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCCC6u);
    goto label_000CCD47;
    label_000CCCC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCCC8u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT62";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCCD2u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000CCCDB;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CCCDD;
    label_000CCCDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCCDBu);
    cpu->ecx = cpu->eax;
    label_000CCCDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCCDDu);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 0x11u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CCCF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCCF0u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCCF0;
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CCD03;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CCD03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD03u);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CCD08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD08u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CCD08;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCD1Bu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0xBu;
    label_000CCD28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD28u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCD28;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD45u);
    cpu->edi = 0u;
    label_000CCD47: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD47u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCD52u); lift_push32(cpu, r); sfera_sub_004D8360(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_000CCDB8;
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0xAu;
    label_000CCD63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD63u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCD63;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD82u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0xAu;
    (void)cpu;
    label_000CCD90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCD90u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCD90;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[6];
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCDB6u);
    goto label_000CCE24;
    label_000CCDB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCDB8u);
    g_sfera_graphics_options_runtime.graphics_values[6] = (uint32_t)(cpu->edi);
    g_sfera_options_dialog_runtime.graphics_snapshot[6] = (uint32_t)(cpu->edi);
    g_sfera_graphics_runtime.post_effects_enabled = (uint32_t)(cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = 0xAu;
    label_000CCDD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCDD7u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCDD7;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCDF7u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 0xAu;
    label_000CCE04: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCE04u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCE04;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CCE24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCE24u);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[6];
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000CCE80;
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 8u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CCE40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCE40u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCE40;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(9u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCE64;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CCE64: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCE64u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CCE70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCE70u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CCE70;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    goto label_000CCEC2;
    label_000CCE80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCE80u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = 8u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000CCE90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCE90u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CCE90;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CCEB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCEB0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CCEB0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0]);
    cpu->ecx = (uint32_t)(cpu->edx + 0x54u);
    label_000CCEC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCEC2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCEC7u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_graphics_options_runtime.graphics_values[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000CCEDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCEDAu);
    cpu->esi = lift_pop32(cpu);
    label_000CCEDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCEDBu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CCEE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CCEE0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CCEDB;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCEF0u); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCEF7u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((*(uint8_t*)(void*)&g_sfera_graphics_options_runtime.graphics_values[2])) & 0xFFu);
    cpu->ecx = g_sfera_shadow_runtime.manager;
    lift_store8(cpu->ecx + 0xA0u, cpu->eax & 0xFFu);
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[3];
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[4];
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    g_sfera_main_render_runtime.grass_depth_mode = (uint32_t)(cpu->edx);
    g_sfera_window_runtime.windowed = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCF28u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = (uint32_t)(uintptr_t)"XRES";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCF43u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 4u);
    cpu->ecx = (uint32_t)(uintptr_t)"YRES";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCF5Fu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 8u);
    cpu->ecx = (uint32_t)(uintptr_t)"DEPTH";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCF7Au); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[3];
    cpu->ecx = (uint32_t)(uintptr_t)"GRASS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCF8Au); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[4];
    cpu->ecx = (uint32_t)(uintptr_t)"WINDOWED";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCF9Au); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[2];
    cpu->ecx = (uint32_t)(uintptr_t)"SHAD";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCFAAu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25;
    cpu->ecx = (uint32_t)(uintptr_t)"AUTOFOG";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCFBAu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCFC5u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)"FOGDIST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCFD1u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_options_dialog_runtime.reflection_quality;
    cpu->ecx = (uint32_t)(uintptr_t)"REFLQUAL";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCFE1u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    cpu->ecx = (uint32_t)(uintptr_t)"EFFECTS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CCFF1u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_runtime.lods_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"LODS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD001u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD00Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)"LOD_DISTANCE";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD018u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD023u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)"MIN_LOD_DIST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD02Fu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[6];
    cpu->ecx = (uint32_t)(uintptr_t)"POSTEFFECTS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD03Fu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD04Au); lift_push32(cpu, r); sfera_sub_004261B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD04Fu); lift_push32(cpu, r); sfera_sub_00448490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[10];
    if ((uint32_t)(cpu->ecx) != (uint32_t)(g_sfera_graphics_options_runtime.graphics_values[0])) goto label_000CD07C;
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[11];
    if ((uint32_t)(cpu->edx) != (uint32_t)(g_sfera_graphics_options_runtime.graphics_values[1])) goto label_000CD07C;
    cpu->eax = g_sfera_options_dialog_runtime.comparison_graphics_value;
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_graphics_options_runtime.graphics_values[4])) goto label_000CCEDB;
    label_000CD07C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD07Cu);
    cpu->ecx = 0x65687073u;
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"sphere.exe") + 4u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"sphere.exe") + 8u)) & 0xFFFFu);
    (*(uint32_t*)(void*)&g_sfera_process_runtime.executable_path[0]) = (uint32_t)(cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"sphere.exe") + 0xAu)) & 0xFFu);
    lift_store32((uintptr_t)&g_sfera_process_runtime.executable_path[4], cpu->edx);
    lift_store16((uintptr_t)&g_sfera_process_runtime.executable_path[8], cpu->eax & 0xFFFFu);
    lift_store8((uintptr_t)&g_sfera_process_runtime.executable_path[10], cpu->ecx & 0xFFu);
    g_sfera_relaunch_runtime.argument[0] = (char)0u;
    g_sfera_render_lookup_runtime.initialized = (uint32_t)(1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}
