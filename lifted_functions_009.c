#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

static uint32_t sfera_window_class_name(void) { return (uint32_t)(uintptr_t)"SphereWclName"; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_00457E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x457E80u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x18Cu;
    cpu->eax = g_sfera_view_motion_runtime.update_serial;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) != 0u) goto label_00057EAE;
    cpu->eax |= 1u;
    g_sfera_view_motion_runtime.update_serial = (uint32_t)(cpu->eax);
    label_00057EAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x457EAEu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) != 0u) goto label_00057EBA;
    cpu->eax |= 2u;
    g_sfera_view_motion_runtime.update_serial = (uint32_t)(cpu->eax);
    label_00057EBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x457EBAu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) != 0u) goto label_00057EC6;
    cpu->eax |= 4u;
    g_sfera_view_motion_runtime.update_serial = (uint32_t)(cpu->eax);
    label_00057EC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x457EC6u);
    cpu->eax = g_sfera_main_render_runtime.secondary_render_pass;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00057EEF;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.ui_cell_width, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.125));
    goto label_00057F01;
    label_00057EEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x457EEFu);
    lift_x87_push(cpu, (double)25.600000381469727f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.ui_cell_width, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)32.0f);
    label_00057F01: cpu->eip = LIFT_CODE_TOKEN_VA(0x457F01u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_factor, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.projection_scale, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_scale, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.10000000149011612);
    lift_x87_push(cpu, 0.0);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00058919;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xFCu));
    lift_store32(cpu->esp + 0x11Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x100u));
    lift_store32(cpu->esp + 0x120u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x));
    lift_store32(cpu->esp + 0x124u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x104u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x104u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xFCu));
    lift_store32(cpu->esp + 0x110u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x108u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x108u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x100u));
    lift_store32(cpu->esp + 0x114u, cpu->ecx);
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x104u));
    lift_store32(cpu->esp + 0x118u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x108u))));
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xF8u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xFCu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x100u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x104u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x108u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x100u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x104u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x104u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x108u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu));
    lift_store32(cpu->esp + 0x108u, cpu->ecx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, 0.009999999776482582);
    lift_store32(cpu->esp + 0x10Cu, cpu->edx);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xFCu));
    lift_store32(cpu->esp + 0xF8u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    cpu->eax = (uint32_t)(cpu->esp + 0x11Cu);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x104u));
    lift_store32(cpu->esp + 0x100u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x108u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x108u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458212u); lift_push32(cpu, r); sfera_sub_0042F7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x110u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0xFCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45822Cu); lift_push32(cpu, r); sfera_sub_0042F7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_view_motion_runtime.projected_b.x.u32);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458243u); lift_push32(cpu, r); sfera_sub_0042F7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x134u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_view_motion_runtime.projected_a.x.u32);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45825Cu); lift_push32(cpu, r); sfera_sub_0042F7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x104u);
    cpu->edx = lift_load32(cpu->esp + 0x108u);
    g_sfera_view_motion_runtime.projected_b.x.u32 = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10Cu);
    lift_store32((uintptr_t)&g_sfera_view_motion_runtime.projected_b.y.u32, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xF8u);
    lift_store32((uintptr_t)&g_sfera_view_motion_runtime.projected_b.z.u32, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xFCu);
    g_sfera_view_motion_runtime.projected_a.x.u32 = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x100u);
    lift_store32((uintptr_t)&g_sfera_view_motion_runtime.projected_a.y.u32, cpu->ecx);
    lift_store32((uintptr_t)&g_sfera_view_motion_runtime.projected_a.z.u32, cpu->edx);
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00058876;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_00058876;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_model_transform_scratch_matrix;
    cpu->edi = (uint32_t)(cpu->esp + 0xB8u);
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_motion_runtime.reference_point.x.f32)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_motion_runtime.reference_point.y.f32)));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z));
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_motion_runtime.reference_point.z.f32)));
    cpu->ecx = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].y);
    g_sfera_view_motion_runtime.reference_point.y.u32 = (uint32_t)(cpu->ecx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].x);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    cpu->edx = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].z);
    cpu->edi = (uint32_t)(cpu->esp + 0x150u);
    cpu->edi &= 0xFFFFFFF0u;
    g_sfera_view_motion_runtime.reference_point.z.u32 = (uint32_t)(cpu->edx);
    g_sfera_view_motion_runtime.reference_point.x.u32 = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x140u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->esp + 0xB8u);
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x140u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45837Eu); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x104u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4583DAu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4583FFu); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.projection_scale));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x2Cu))) / (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)(*(float*)(void*)&g_sfera_main_view_state_runtime.projection_scale))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.3333300352096558));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x128u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x11Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x12Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x120u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.camera_step));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.camera_step, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.cursor_accumulator));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.cursor_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_push(cpu, 256.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)g_sfera_view_motion_runtime.motion_terms[1].f32)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.00390625); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4584F8u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458507u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    lift_store_f64(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x138u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x12Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x134u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x128u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45859Cu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x28u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.ui_cell_width));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000585E2;
    label_000585C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4585C5u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000585C5;
    label_000585E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4585E2u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000585F3;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00058610;
    label_000585F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4585F1u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_000585F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4585F3u);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_000585F1;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00058610: cpu->eip = LIFT_CODE_TOKEN_VA(0x458610u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_factor));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00058642;
    label_00058625: cpu->eip = LIFT_CODE_TOKEN_VA(0x458625u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00058625;
    label_00058642: cpu->eip = LIFT_CODE_TOKEN_VA(0x458642u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00058653;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00058670;
    label_00058651: cpu->eip = LIFT_CODE_TOKEN_VA(0x458651u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_00058653: cpu->eip = LIFT_CODE_TOKEN_VA(0x458653u);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_00058651;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00058670: cpu->eip = LIFT_CODE_TOKEN_VA(0x458670u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, 25.600000381469727);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000586A2;
    label_00058687: cpu->eip = LIFT_CODE_TOKEN_VA(0x458687u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 5u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00058687;
    label_000586A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4586A2u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000586B1;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000586CC;
    label_000586AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4586AFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_000586B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4586B1u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_000586AF;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000586CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4586CCu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, 32.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000586FE;
    label_000586E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4586E3u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 5u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000586E3;
    label_000586FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4586FEu);
    lift_x87_push(cpu, (double)32.0f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00058715;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00058732;
    label_00058713: cpu->eip = LIFT_CODE_TOKEN_VA(0x458713u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_00058715: cpu->eip = LIFT_CODE_TOKEN_VA(0x458715u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_00058713;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00058732: cpu->eip = LIFT_CODE_TOKEN_VA(0x458732u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 5u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, 1.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005875E;
    label_00058743: cpu->eip = LIFT_CODE_TOKEN_VA(0x458743u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 6u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00058743;
    label_0005875E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45875Eu);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0005876F;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0005878E;
    label_0005876D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45876Du);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0005876F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45876Fu);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0005876D;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005878E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45878Eu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 6u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000587B4;
    label_0005879D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45879Du);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 6u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0005879D;
    label_000587B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4587B4u);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000587DA;
    label_000587BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4587BFu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_000587BF;
    label_000587DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4587DAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 5u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, 6.283185958862305);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005880E;
    label_000587F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4587F3u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 6u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000587F3;
    label_0005880E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45880Eu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0005881D;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00058838;
    label_0005881B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45881Bu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0005881D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45881Du);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0005881B;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00058838: cpu->eip = LIFT_CODE_TOKEN_VA(0x458838u);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (25.600000381469727));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (32.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    goto label_000588D8;
    label_00058876: cpu->eip = LIFT_CODE_TOKEN_VA(0x458876u);
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x5887Eu), LIFT_CODE_TOKEN_RVA(0x5887Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45887Eu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x58894u), LIFT_CODE_TOKEN_RVA(0x58892u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x458894u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.phase.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x588AAu), LIFT_CODE_TOKEN_RVA(0x588A8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4588AAu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.ui_cell_width));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_factor));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    lift_x87_push(cpu, 0.0);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_000588D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4588D8u);
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00058911;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00058911: cpu->eip = LIFT_CODE_TOKEN_VA(0x458911u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x38u, cpu->edi);
    goto label_0005894B;
    label_00058919: cpu->eip = LIFT_CODE_TOKEN_VA(0x458919u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.ui_cell_width));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_factor));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    goto label_000588D8;
    label_00058931: cpu->eip = LIFT_CODE_TOKEN_VA(0x458931u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.ui_cell_width));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_factor));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    lift_x87_push(cpu, 0.0);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0005894B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45894Bu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x38u)))));
    cpu->esi = cpu->edi;
    lift_flags_logic(cpu,0u,32u); cpu->ebx = 0u;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::rhw)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f64(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    goto label_00058994;
    label_00058974: cpu->eip = LIFT_CODE_TOKEN_VA(0x458974u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.ui_cell_width));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_factor));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_push(cpu, 0.0);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00058994: cpu->eip = LIFT_CODE_TOKEN_VA(0x458994u);
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000589CB;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32));
    goto label_000589E0;
    label_000589CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4589CBu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32));
    label_000589E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4589E0u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->edx = (uint32_t)(cpu->esi + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_store_f32(cpu->esi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFF8u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFF4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458A06u); lift_push32(cpu, r); sfera_sub_0044E090(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xA4u))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xA8u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_push(cpu, 0.10000000149011612);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store32(cpu->esp + 0x11Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x120u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x));
    lift_store32(cpu->esp + 0x124u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00058B70;
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x8Cu))));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x90u))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_push(cpu, 0.125);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x64u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x6Cu);
    goto label_00058BE2;
    label_00058B70: cpu->eip = LIFT_CODE_TOKEN_VA(0x458B70u);
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x28u));
    lift_x87_push(cpu, 0.125);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.75));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    label_00058BE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x458BE2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x110u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_store32(cpu->esp + 0x114u, cpu->ecx);
    lift_store32(cpu->esp + 0x118u, cpu->edx);
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x114u))));
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x118u))));
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x98u))));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x9Cu))));
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00058C9C;
    if ((uint32_t)(lift_load32(cpu->esp + 0x38u)) != (uint32_t)(cpu->ebx)) goto label_00058C9C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_00058C9E;
    label_00058C9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x458C9Cu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    label_00058C9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x458C9Eu);
    cpu->edx = lift_load32(cpu->esp + 0x70u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458CC2u); lift_push32(cpu, r); sfera_sub_00457840(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_scale));
    cpu->eax = g_sfera_recovered_static_runtime.render_state_09;
    lift_store_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_samples[0]), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.sky_blend_factor));
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax = g_sfera_render_lookup_runtime.alpha_component;
    lift_store_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0]), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)1.5099999904632568f);
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP2();
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00058D19;
    cpu->eax = 1u;
    goto label_00058D1B;
    label_00058D19: cpu->eip = LIFT_CODE_TOKEN_VA(0x458D19u);
    cpu->eax = 0u;
    label_00058D1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x458D1Bu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.environment_parameter.f32));
    ++cpu->ebx;
    lift_store_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.samples[0]), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[0]), cpu->eax);
    ++cpu->edi;
    cpu->esi += 0x20u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0xCu)) goto label_00058974;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xAu)) goto label_00058931;
    cpu->eax = 0u;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x10u, 9u);
    (void)cpu;
    label_00058D60: cpu->eip = LIFT_CODE_TOKEN_VA(0x458D60u);
    cpu->ebx = 0xBu;
    label_00058D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x458D70u);
    cpu->ecx = cpu->edi & 0xFFFFu;
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[0]), cpu->ecx & 0xFFFFu);
    cpu->edx = (uint32_t)(cpu->ecx + 1u);
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[1]), cpu->edx & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->ecx + 0xCu);
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[2]), cpu->esi & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[3]), cpu->edx & 0xFFFFu);
    cpu->ecx += 0xDu;
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[4]), cpu->ecx & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[5]), cpu->esi & 0xFFFFu);
    cpu->eax += 6u;
    ++cpu->edi;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00058D70;
    ++cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00058D60;
    if ((uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == (uint32_t)(cpu->ebx)) goto label_00058DE0;
    cpu->ecx = (uint32_t)(uintptr_t)"black";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458DCCu); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458DD9u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"black";
    goto label_00058DFD;
    label_00058DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x458DE0u);
    cpu->ecx = (uint32_t)(uintptr_t)"stars";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458DEAu); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458DF8u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"stars";
    label_00058DFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x458DFDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458E02u); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458E11u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458E21u); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0x252u); lift_push32(cpu, (uintptr_t)&g_sfera_sky_runtime.indices[0]); lift_push32(cpu, 0x78u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0xEu); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458E43u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x458E52u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00458E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x458E80u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) < 0) goto label_0005904B;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00058EA2;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58EA2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00058EA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x458EA2u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u))) == (uint32_t)(0u)) goto label_0005904B;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00058EC5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58EC5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00058EC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x458EC5u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi += 0x44u;
    cpu->ebx = 0x1B58u;
    label_00058EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x458EE0u);
    cpu->esi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00058F1E;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00058EF5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58EF5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00058EF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x458EF5u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00058F09;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58F09u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00058F09: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F09u);
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(0u)) goto label_00058F1E;
    cpu->ecx = lift_load32(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58F1Eu); lift_push32(cpu, r); sfera_sub_00457370(cpu,r); if (cpu->eip != r) return; }
    label_00058F1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F1Eu);
    cpu->edi += 4u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00058EE0;
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00058FE1;
    label_00058F35: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F35u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00058F43;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58F43u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00058F43: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F43u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00058F57;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58F57u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00058F57: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F57u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_00058F66;
    ++cpu->esi;
    goto label_00058F35;
    label_00058F66: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F66u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00058F74;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58F74u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00058F74: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F74u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00058F88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58F88u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00058F88: cpu->eip = LIFT_CODE_TOKEN_VA(0x458F88u);
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x6DA4u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(lift_load32(cpu->edx + 0x6DA4u))) goto label_00058FD3;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00058FB1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58FB1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00058FB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x458FB1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00058FC5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58FC5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00058FC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x458FC5u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->eax + 0x6DA4u, (uint64_t)(lift_load32(cpu->eax + 0x6DA4u)) - 1u);
    label_00058FD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x458FD3u);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count))) goto label_00058F35;
    label_00058FE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x458FE1u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00058FF5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x58FF5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00058FF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x458FF5u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, 0x2E59u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45900Du); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00059021;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59021u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00059021: cpu->eip = LIFT_CODE_TOKEN_VA(0x459021u);
    cpu->edx = g_sfera_interface_runtime.windows.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u), 0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.window_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) - 1u);
    if ((uint32_t)(g_sfera_window_runtime.active_window_index) != (uint32_t)(cpu->ebp)) goto label_00059046;
    g_sfera_window_runtime.active_window_index = (uint32_t)(0xFFFFFFFFu);
    label_00059046: cpu->eip = LIFT_CODE_TOKEN_VA(0x459046u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0005904B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45904Bu);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00059058: cpu->eip = LIFT_CODE_TOKEN_VA(0x459058u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00059058;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"delete_window: wrong handle";
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0044F500(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459080u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00059143;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->eax;
    label_00059096: cpu->eip = LIFT_CODE_TOKEN_VA(0x459096u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000590A4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x590A4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000590A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4590A4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000590B8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x590B8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000590B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4590B8u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_000590C6;
    ++cpu->esi;
    goto label_00059096;
    label_000590C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4590C6u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000590D4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x590D4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000590D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4590D4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000590E8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x590E8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000590E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4590E8u);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(lift_load32(cpu->edx + 0x1Cu)) != (uint32_t)(cpu->edi)) goto label_0005913A;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00059104;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59104u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00059104: cpu->eip = LIFT_CODE_TOKEN_VA(0x459104u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00059118;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59118u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00059118: cpu->eip = LIFT_CODE_TOKEN_VA(0x459118u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00059133;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005913A;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459131u); lift_push32(cpu, r); sfera_sub_00455C20(cpu,r); if (cpu->eip != r) return; }
    goto label_0005913A;
    label_00059133: cpu->eip = LIFT_CODE_TOKEN_VA(0x459133u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5913Au); lift_push32(cpu, r); sfera_sub_00457370(cpu,r); if (cpu->eip != r) return; }
    label_0005913A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45913Au);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059096;
    cpu->ebx = lift_pop32(cpu);
    label_00059143: cpu->eip = LIFT_CODE_TOKEN_VA(0x459143u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459150u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_00059339;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00059171;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59171u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00059171: cpu->eip = LIFT_CODE_TOKEN_VA(0x459171u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u))) == (uint32_t)(0u)) goto label_00059339;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.mode_02)) goto label_0005918E;
    g_sfera_client_main_scalar_runtime.mode_02 = (uint32_t)(cpu->ebx);
    label_0005918E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45918Eu);
    cpu->eax = g_sfera_world_objects.max_occupied_object_handle;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_000591E7;
    --cpu->eax;
    g_sfera_world_objects.max_occupied_object_handle = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFFFFFFFu)) goto label_000591E7;
    label_000591A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4591A2u);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000591B7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4591B2u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.max_occupied_object_handle;
    label_000591B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4591B7u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000591D0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4591CBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.max_occupied_object_handle;
    label_000591D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4591D0u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_000591E7;
    --cpu->eax;
    g_sfera_world_objects.max_occupied_object_handle = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0xFFFFFFFFu)) goto label_000591A2;
    label_000591E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4591E7u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000591FB;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x591FBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000591FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4591FBu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45920Cu); lift_push32(cpu, r); sfera_sub_00459080(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = (uint32_t)(cpu->ebp + 0x10Cu);
    cpu->edi = 0xAu;
    label_00059217: cpu->eip = LIFT_CODE_TOKEN_VA(0x459217u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_00059223;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59223u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    label_00059223: cpu->eip = LIFT_CODE_TOKEN_VA(0x459223u);
    cpu->esi += 4u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059217;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x138u)) != (uint8_t)(1u)) goto label_000592F5;
    cpu->esi = lift_load32(cpu->ebp + 0x184u);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059265;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459247u); lift_push32(cpu, r); sfera_sub_00455D80(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = (uint32_t)(cpu->ebp + 0xF8u);
    cpu->edi = 5u;
    label_00059252: cpu->eip = LIFT_CODE_TOKEN_VA(0x459252u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0005925D;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5925Du); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    label_0005925D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45925Du);
    cpu->esi += 4u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059252;
    goto label_0005929F;
    label_00059265: cpu->eip = LIFT_CODE_TOKEN_VA(0x459265u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00059271;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59271u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00059271: cpu->eip = LIFT_CODE_TOKEN_VA(0x459271u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00059285;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59285u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00059285: cpu->eip = LIFT_CODE_TOKEN_VA(0x459285u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ebp + 0x188u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0xF8u, 0u);
    label_0005929F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45929Fu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x144u)) >= (int32_t)(uint32_t)(0u)) goto label_000592B4;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x592B4u); lift_push32(cpu, r); sfera_sub_0041B530(cpu,r); if (cpu->eip != r) return; }
    label_000592B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4592B4u);
    cpu->esi = lift_load32(cpu->ebp + 0x13Cu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000592FC;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000592CD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x592CDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000592CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4592CDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_000592E1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x592E1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000592E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4592E1u);
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), 0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_count, (uint64_t)(g_sfera_world_objects.extended_object_count) - 1u);
    goto label_000592FC;
    label_000592F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4592F5u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x592FCu); lift_push32(cpu, r); sfera_sub_00455D80(cpu,r); if (cpu->eip != r) return; }
    label_000592FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4592FCu);
    lift_push32(cpu, 0x2453u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45930Du); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00059322;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59322u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00059322: cpu->eip = LIFT_CODE_TOKEN_VA(0x459322u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u), 0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_render_runtime.world_object_count, (uint64_t)(g_sfera_main_render_runtime.world_object_count) - 1u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00059339: cpu->eip = LIFT_CODE_TOKEN_VA(0x459339u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00059346: cpu->eip = LIFT_CODE_TOKEN_VA(0x459346u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00059346;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"DeleteObject: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_0044F500(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459370u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 2u;
    label_00059376: cpu->eip = LIFT_CODE_TOKEN_VA(0x459376u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00059384;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59384u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00059384: cpu->eip = LIFT_CODE_TOKEN_VA(0x459384u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00059398;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59398u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00059398: cpu->eip = LIFT_CODE_TOKEN_VA(0x459398u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_000593AA;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x593AAu); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    label_000593AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4593AAu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x7A120u)) goto label_00059376;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004593C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4593C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000593DF;
    lift_push32(cpu, (uintptr_t)"Wrong handle: Link_object_to_object\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4593D9u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000593DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4593DFu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000593F3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x593F3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000593F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4593F3u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0xF8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0005940B;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5940Bu); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    label_0005940B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45940Bu);
    lift_store32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0xF8u, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459420u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005952C;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0005943D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5943Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005943D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45943Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00059451;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59451u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00059451: cpu->eip = LIFT_CODE_TOKEN_VA(0x459451u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00059475;
    lift_push32(cpu, 0x4024u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459472u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    label_00059475: cpu->eip = LIFT_CODE_TOKEN_VA(0x459475u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005948E;
    lift_push32(cpu, 0x4025u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45948Bu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    label_0005948E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45948Eu);
    cpu->ecx = lift_load32(cpu->esi + 0x3Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000594A7;
    lift_push32(cpu, 0x4026u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4594A4u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x3Cu, cpu->edi);
    label_000594A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4594A7u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000594C0;
    lift_push32(cpu, 0x4027u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4594BDu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    label_000594C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4594C0u);
    cpu->ecx = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000594DF;
    lift_push32(cpu, 0x4028u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4594D9u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1CCu, cpu->edi);
    label_000594DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4594DFu);
    cpu->ecx = lift_load32(cpu->esi + 0x1C8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000594FE;
    lift_push32(cpu, 0x4029u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4594F8u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1C8u, cpu->edi);
    label_000594FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4594FEu);
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00059512;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x459509u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45950Fu);
    cpu->esp += 4u;
    label_00059512: cpu->eip = LIFT_CODE_TOKEN_VA(0x459512u);
    lift_push32(cpu, 0x402Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459523u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45952Au); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx, cpu->edi);
    label_0005952C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45952Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459530u);
    cpu->eax = g_sfera_world_render_runtime.render_queue_count;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00059544;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00059544: cpu->eip = LIFT_CODE_TOKEN_VA(0x459544u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_world_render_queue_runtime.entries[0]));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005955A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5955Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005955A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45955Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005956E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5956Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005956E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45956Eu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459585u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00059590: cpu->eip = LIFT_CODE_TOKEN_VA(0x459590u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00059590;
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = g_sfera_world_render_runtime.render_queue_count;
    cpu->ecx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_world_render_queue_runtime.entries[0]));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4595D1u); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_world_render_runtime.render_queue_count, (uint64_t)(g_sfera_world_render_runtime.render_queue_count) - 1u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004595F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4595F0u);
    cpu->esp -= 0x90u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(g_sfera_view_motion_runtime.mode_value) == (uint32_t)(cpu->edi)) goto label_00059648;
    cpu->esi = native_function_address32(&::ShowCursor);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59619u), LIFT_CODE_TOKEN_RVA(0x59617u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459619u);
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x5961Du), LIFT_CODE_TOKEN_RVA(0x5961Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45961Du);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00059629;
    label_00059621: cpu->eip = LIFT_CODE_TOKEN_VA(0x459621u);
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59625u), LIFT_CODE_TOKEN_RVA(0x59623u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459625u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00059621;
    label_00059629: cpu->eip = LIFT_CODE_TOKEN_VA(0x459629u);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"Error"); lift_push32(cpu, (uintptr_t)"Reenter in epilog detected!"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x45963Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459641u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x59642u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x59648u);
    label_00059648: cpu->eip = LIFT_CODE_TOKEN_VA(0x459648u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    g_sfera_view_motion_runtime.mode_value = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45965Eu); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_world_render_runtime.world_spatial_index) == (uint32_t)(cpu->edi)) goto label_00059695;
    cpu->edx = 0x44Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459675u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005968F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459686u); lift_push32(cpu, r); sfera_sub_004258F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45968Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0005968F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45968Fu);
    g_sfera_world_render_runtime.world_spatial_index = (uint32_t)(cpu->edi);
    label_00059695: cpu->eip = LIFT_CODE_TOKEN_VA(0x459695u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_01)) == (uint8_t)(0u)) goto label_000596AB;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->halt_all_requested = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x596ABu); lift_push32(cpu, r); sfera_sub_004496F0(cpu,r); if (cpu->eip != r) return; }
    label_000596AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4596ABu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4596B5u); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4596BAu); lift_push32(cpu, r); sfera_sub_004981F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_input_device_runtime.shared_object) == (uint32_t)(cpu->edi)) goto label_000596F1;
    cpu->edx = 0x457u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4596D1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_input_device_runtime.shared_object;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000596EB;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4596E2u); lift_push32(cpu, r); sfera_sub_0047E0F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4596E8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000596EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4596EBu);
    g_sfera_input_device_runtime.shared_object = (uint32_t)(cpu->edi);
    label_000596F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4596F1u);
    if ((uint32_t)(g_sfera_client_process_runtime.client_object) == (uint32_t)(cpu->edi)) goto label_00059728;
    cpu->edx = 0x458u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459708u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00059722;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459719u); lift_push32(cpu, r); sfera_sub_0041F2F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45971Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00059722: cpu->eip = LIFT_CODE_TOKEN_VA(0x459722u);
    g_sfera_client_process_runtime.client_object = (uint32_t)(cpu->edi);
    label_00059728: cpu->eip = LIFT_CODE_TOKEN_VA(0x459728u);
    if ((uint32_t)(g_sfera_font_runtime.renderer) == (uint32_t)(cpu->edi)) goto label_00059757;
    cpu->edx = 0x459u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45973Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_font_runtime.renderer;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00059751;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45974Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00059751: cpu->eip = LIFT_CODE_TOKEN_VA(0x459751u);
    g_sfera_font_runtime.renderer = (uint32_t)(cpu->edi);
    label_00059757: cpu->eip = LIFT_CODE_TOKEN_VA(0x459757u);
    if ((uint32_t)(g_sfera_main_aux_runtime.secondary_world_manager) == (uint32_t)(cpu->edi)) goto label_00059786;
    cpu->edx = 0x45Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45976Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_main_aux_runtime.secondary_world_manager;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00059780;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45977Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00059780: cpu->eip = LIFT_CODE_TOKEN_VA(0x459780u);
    g_sfera_main_aux_runtime.secondary_world_manager = (uint32_t)(cpu->edi);
    label_00059786: cpu->eip = LIFT_CODE_TOKEN_VA(0x459786u);
    if ((uint32_t)(g_sfera_window_runtime.input_runtime_object) == (uint32_t)(cpu->edi)) goto label_000597BD;
    cpu->edx = 0x45Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45979Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_window_runtime.input_runtime_object;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000597B7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4597AEu); lift_push32(cpu, r); sfera_sub_00489810(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4597B4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000597B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4597B7u);
    g_sfera_window_runtime.input_runtime_object = (uint32_t)(cpu->edi);
    label_000597BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4597BDu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000597CD;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_RVA(0x597C7u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x597CDu);
    label_000597CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4597CDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4597D2u); lift_push32(cpu, r); sfera_sub_0042A3A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4597D7u); lift_push32(cpu, r); sfera_sub_004BCEF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4597DCu); lift_push32(cpu, r); sfera_sub_0048DB30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4597E1u); lift_push32(cpu, r); sfera_sub_00459370(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_model_runtime.repository) == (uint32_t)(cpu->edi)) goto label_00059818;
    cpu->edx = 0x46Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4597F8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_model_runtime.repository;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00059812;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459809u); lift_push32(cpu, r); sfera_sub_0047F450(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45980Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00059812: cpu->eip = LIFT_CODE_TOKEN_VA(0x459812u);
    g_sfera_model_runtime.repository = (uint32_t)(cpu->edi);
    label_00059818: cpu->eip = LIFT_CODE_TOKEN_VA(0x459818u);
    if ((uint32_t)(g_sfera_recovered_static_runtime.render_state_08) == (uint32_t)(cpu->edi)) goto label_0005984F;
    cpu->edx = 0x46Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45982Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00059849;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459840u); lift_push32(cpu, r); sfera_sub_0041B1E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459846u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00059849: cpu->eip = LIFT_CODE_TOKEN_VA(0x459849u);
    g_sfera_recovered_static_runtime.render_state_08 = (uint32_t)(cpu->edi);
    label_0005984F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45984Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459854u); lift_push32(cpu, r); sfera_sub_0044CB70(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459859u); lift_push32(cpu, r); sfera_sub_0044C110(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state)) == (uint32_t)(cpu->edi)) goto label_00059888;
    cpu->edx = 0x473u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459870u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00059882;
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x59882u), LIFT_CODE_TOKEN_RVA(0x59880u))) { return; }
    label_00059882: cpu->eip = LIFT_CODE_TOKEN_VA(0x459882u);
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state) = (uint32_t)(cpu->edi);
    label_00059888: cpu->eip = LIFT_CODE_TOKEN_VA(0x459888u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45988Du); lift_push32(cpu, r); sfera_sub_004571F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_window_runtime.main_window;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000598A3;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DestroyWindow), LIFT_CODE_TOKEN_VA(0x459897u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45989Du);
    g_sfera_window_runtime.main_window = (uint32_t)(cpu->edi);
    label_000598A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4598A3u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, sfera_window_class_name());
    lift_native_call(cpu, native_function_address32(&::UnregisterClassA), LIFT_CODE_TOKEN_VA(0x4598AFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4598B5u);
    lift_native_call(cpu, native_function_address32(&::CoUninitialize), LIFT_CODE_TOKEN_VA(0x4598B5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4598BBu);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00059A6F;
    cpu->ebx = native_function_address32(&::fflush);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::fputs);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].has_written;
    (void)cpu;
    label_000598E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4598E0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xFFFFFFFCu)) != (uint32_t)(cpu->edi)) goto label_00059A56;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4598EEu); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0005990F;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"**** Quit: ");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x598FCu), LIFT_CODE_TOKEN_RVA(0x598FAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4598FCu);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x598FFu), LIFT_CODE_TOKEN_RVA(0x598FDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4598FFu);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459900u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459906u);
    cpu->esp += 0x10u;
    lift_store32(cpu->esi, 1u);
    label_0005990F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45990Fu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x459914u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45991Au);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x45991Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459925u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y");
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x459935u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45993Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->esp += 0x18u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459947u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00059968;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x59955u), LIFT_CODE_TOKEN_RVA(0x59953u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459955u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x59958u), LIFT_CODE_TOKEN_RVA(0x59956u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459958u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459959u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45995Fu);
    cpu->esp += 0x10u;
    lift_store32(cpu->esi, 1u);
    label_00059968: cpu->eip = LIFT_CODE_TOKEN_VA(0x459968u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459971u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00059992;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"  ");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x5997Fu), LIFT_CODE_TOKEN_RVA(0x5997Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45997Fu);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x59982u), LIFT_CODE_TOKEN_RVA(0x59980u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459982u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459983u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459989u);
    cpu->esp += 0x10u;
    lift_store32(cpu->esi, 1u);
    label_00059992: cpu->eip = LIFT_CODE_TOKEN_VA(0x459992u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x459997u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45999Du);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4599A9u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000599CA;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x599B7u), LIFT_CODE_TOKEN_RVA(0x599B5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4599B7u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x599BAu), LIFT_CODE_TOKEN_RVA(0x599B8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4599BAu);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4599BBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4599C1u);
    cpu->esp += 0x10u;
    lift_store32(cpu->esi, 1u);
    label_000599CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4599CAu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4599D3u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000599F4;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"\n\n");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x599E1u), LIFT_CODE_TOKEN_RVA(0x599DFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4599E1u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x599E4u), LIFT_CODE_TOKEN_RVA(0x599E2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4599E4u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4599E5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4599EBu);
    cpu->esp += 0x10u;
    lift_store32(cpu->esi, 1u);
    label_000599F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4599F4u);
    cpu->eax = 0u;
    if ((uint8_t)(lift_load8(cpu->esi + 0xFFFFFFC8u)) == (uint8_t)(0x2Eu)) goto label_00059A10;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00059A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x459A00u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + cpu->eax + 0xFFFFFFC8u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x1Cu, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->esi + cpu->eax + 0xFFFFFFC8u)) != (uint8_t)(0x2Eu)) goto label_00059A00;
    label_00059A10: cpu->eip = LIFT_CODE_TOKEN_VA(0x459A10u);
    lift_store8(cpu->esp + cpu->eax + 0x1Cu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    --cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00059A20: cpu->eip = LIFT_CODE_TOKEN_VA(0x459A20u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00059A20;
    cpu->ecx = lift_load32((uintptr_t)".log");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)".log") + 4u)) & 0xFFu);
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459A45u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00059A54;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59A54u); lift_push32(cpu, r); sfera_sub_0044C020(cpu,r); if (cpu->eip != r) return; }
    label_00059A54: cpu->eip = LIFT_CODE_TOKEN_VA(0x459A54u);
    cpu->edi = 0u;
    label_00059A56: cpu->eip = LIFT_CODE_TOKEN_VA(0x459A56u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    cpu->esi += 0x40u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode))) goto label_000598E0;
    cpu->ebp = lift_pop32(cpu);
    label_00059A6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x459A6Fu);
    { uint64_t l=(uint64_t)(((uint8_t)g_sfera_process_runtime.executable_path[0])), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00059A92;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_relaunch_runtime.argument[0]); lift_push32(cpu, (uintptr_t)&g_sfera_process_runtime.executable_path[0]); lift_push32(cpu, (uintptr_t)&g_sfera_process_runtime.executable_path[0]);
    lift_native_call(cpu, native_function_address32(&::_execl), LIFT_CODE_TOKEN_VA(0x459A89u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459A8Fu);
    cpu->esp += 0x10u;
    label_00059A92: cpu->eip = LIFT_CODE_TOKEN_VA(0x459A92u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459A9Cu); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = native_function_address32(&::DeleteCriticalSection);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59AA9u), LIFT_CODE_TOKEN_RVA(0x59AA7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459AA9u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59AB0u), LIFT_CODE_TOKEN_RVA(0x59AAEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459AB0u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59AB7u), LIFT_CODE_TOKEN_RVA(0x59AB5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459AB7u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)(1u)) goto label_00059AF1;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24)) == (uint32_t)(cpu->edi)) goto label_00059AF1;
    cpu->edx = 0x4B4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459AD7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00059AF1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459AE8u); lift_push32(cpu, r); sfera_sub_00418D50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459AEEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00059AF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x459AF1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x90u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459B10(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459B10u);
    { uint64_t l=(uint64_t)(g_sfera_view_motion_runtime.initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00059B58;
    cpu->esi = native_function_address32(&::ShowCursor);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59B26u), LIFT_CODE_TOKEN_RVA(0x59B24u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459B26u);
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59B2Au), LIFT_CODE_TOKEN_RVA(0x59B28u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459B2Au);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00059B38;
    cpu->edi = cpu->edi;
    label_00059B30: cpu->eip = LIFT_CODE_TOKEN_VA(0x459B30u);
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59B34u), LIFT_CODE_TOKEN_RVA(0x59B32u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459B34u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00059B30;
    label_00059B38: cpu->eip = LIFT_CODE_TOKEN_VA(0x459B38u);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"Error"); lift_push32(cpu, (uintptr_t)"Reenter in exit_msg detected!"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x459B4Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459B50u);
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x59B52u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x59B58u);
    label_00059B58: cpu->eip = LIFT_CODE_TOKEN_VA(0x459B58u);
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ServerN=%d  "); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]);
    g_sfera_view_motion_runtime.initialized = (uint32_t)(1u);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459B73u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459B79u);
    cpu->eax = cpu->esi;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->eax;
    label_00059B80: cpu->eip = LIFT_CODE_TOKEN_VA(0x459B80u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00059B80;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    cpu->eax -= cpu->ecx;
    --cpu->edi;
    label_00059B92: cpu->eip = LIFT_CODE_TOKEN_VA(0x459B92u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059B92;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459BB2u); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459BB7u); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00059BFC;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    --cpu->edi;
    label_00059BC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x459BC1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00059BC1;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    lift_store16(cpu->edi, cpu->edx & 0xFFFFu);
    cpu->ecx = cpu->eax;
    label_00059BD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x459BD5u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00059BD5;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059BE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x459BE6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059BE6;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    label_00059BFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x459BFCu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459C03u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = native_function_address32(&::fputs);
    cpu->ebx = native_function_address32(&::fflush);
    cpu->ebp = native_function_address32(&::fclose);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00059C36;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x59C23u), LIFT_CODE_TOKEN_RVA(0x59C21u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C23u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x59C26u), LIFT_CODE_TOKEN_RVA(0x59C24u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C26u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x59C29u), LIFT_CODE_TOKEN_RVA(0x59C27u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C29u);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00059C36: cpu->eip = LIFT_CODE_TOKEN_VA(0x459C36u);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459C3Du); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00059C5E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x59C4Bu), LIFT_CODE_TOKEN_RVA(0x59C49u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C4Bu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x59C4Eu), LIFT_CODE_TOKEN_RVA(0x59C4Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C4Eu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x59C51u), LIFT_CODE_TOKEN_RVA(0x59C4Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C51u);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00059C5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x459C5Eu);
    cpu->esi = native_function_address32(&::ShowCursor);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59C68u), LIFT_CODE_TOKEN_RVA(0x59C66u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C68u);
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59C6Cu), LIFT_CODE_TOKEN_RVA(0x59C6Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C6Cu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00059C7B;
    label_00059C73: cpu->eip = LIFT_CODE_TOKEN_VA(0x459C73u);
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59C77u), LIFT_CODE_TOKEN_RVA(0x59C75u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459C77u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00059C73;
    label_00059C7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x459C7Bu);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x459C8Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459C93u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459C98u); lift_push32(cpu, r); sfera_sub_004595F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_VA(0x459C9Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459CA0u);
    lift_trap(cpu, 0x459CA0u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459CB0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459CB0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax = cpu->edx;
    cpu->esi -= cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00059CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x459CC0u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->ebx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00059CC0;
    cpu->ebx = lift_pop32(cpu);
    label_00059CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x459CD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00059CD0;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_00059CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x459CE0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059CE0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459D02u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_trap(cpu, 0x459D04u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459D10(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459D10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax = cpu->edx;
    cpu->esi -= cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00059D20: cpu->eip = LIFT_CODE_TOKEN_VA(0x459D20u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->ebx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00059D20;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00059D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x459D30u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00059D30;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059D41: cpu->eip = LIFT_CODE_TOKEN_VA(0x459D41u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059D41;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00059D60: cpu->eip = LIFT_CODE_TOKEN_VA(0x459D60u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00059D60;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x202C)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store16(cpu->eax, cpu->ecx & 0xFFFFu);
    lift_store8(cpu->eax + 2u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = cpu->eax;
    label_00059D81: cpu->eip = LIFT_CODE_TOKEN_VA(0x459D81u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00059D81;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059D92: cpu->eip = LIFT_CODE_TOKEN_VA(0x459D92u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00059D92;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x459DB2u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_trap(cpu, 0x459DB4u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459DC0u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(7u)) goto label_00059E1C;
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: goto label_00059DCC;
        case 1u: goto label_00059DD6;
        case 2u: goto label_00059DE0;
        case 3u: goto label_00059DEA;
        case 4u: goto label_00059DF4;
        case 5u: goto label_00059DFE;
        case 6u: goto label_00059E08;
        case 7u: goto label_00059E12;
        default: lift_trap(cpu, 0x459DC5u, "resolved jump-table index out of range"); return;
    }
label_00059DCC: ;
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \356\362\352\360\373\362\350\377 \364\340\351\353\3403: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x459DD6u);
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \361\356\347\344\340\355\350\377 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x459DE0u);
    cpu->ecx = (uint32_t)(uintptr_t)"\315\345\356\346\350\344\340\355\355\373\351 \352\356\355\345\366 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x459DEAu);
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \367\362\345\355\350\377 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x459DF4u);
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \347\340\357\350\361\350 \364\340\351\353\340 (\342\356\347\354\356\346\355\356, \355\345\362 \354\345\361\362\340 \355\340 \344\350\361\352\345): ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x459DFEu);
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \347\340\357\350\361\350 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059E08: cpu->eip = LIFT_CODE_TOKEN_VA(0x459E08u);
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \357\356\347\350\366\350\356\355\350\360\356\342\340\355\350\377 \342 \364\340\351\353\345: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059E12: cpu->eip = LIFT_CODE_TOKEN_VA(0x459E12u);
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \347\340\352\360\373\362\350\377 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059E1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x459E1Cu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459E40u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::GetSystemMetrics);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59E5Cu), LIFT_CODE_TOKEN_RVA(0x59E5Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459E5Cu);
    lift_push32(cpu, 1u);
    g_sfera_scene_control_runtime.timing_anchor = (uint32_t)(cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x59E65u), LIFT_CODE_TOKEN_RVA(0x59E63u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459E65u);
    cpu->esi = g_sfera_graphics_runtime.display_width;
    g_sfera_recovered_static_runtime.scene_state_07 = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0x320u)) goto label_00059E83;
    cpu->esi = 0x320u;
    g_sfera_graphics_runtime.display_width = (uint32_t)(cpu->esi);
    label_00059E83: cpu->eip = LIFT_CODE_TOKEN_VA(0x459E83u);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(0x258u)) goto label_00059E9C;
    cpu->ecx = 0x258u;
    g_sfera_graphics_runtime.display_height = (uint32_t)(cpu->ecx);
    label_00059E9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x459E9Cu);
    cpu->ebx = 0u;
    cpu->edi = 0u;
    if ((uint32_t)(g_sfera_window_runtime.windowed) == (uint32_t)(cpu->ebx)) goto label_00059EF3;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ebp = 0xCA0000u;
    lift_native_call(cpu, native_function_address32(&::SetRect), LIFT_CODE_TOKEN_VA(0x459EB6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459EBCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::AdjustWindowRect), LIFT_CODE_TOKEN_VA(0x459EC3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459EC9u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx -= lift_load32(cpu->esp + 0x14u);
    cpu->esi -= lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.scene_state_07)) goto label_00059F33;
    cpu->esi = g_sfera_graphics_runtime.display_width;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    g_sfera_window_runtime.windowed = (uint32_t)(cpu->ebx);
    label_00059EF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x459EF3u);
    cpu->ebp = 0x80000000u;
    label_00059EF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x459EF8u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Sphere"); lift_push32(cpu, sfera_window_class_name()); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateWindowExA), LIFT_CODE_TOKEN_VA(0x459F16u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459F1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_window_runtime.main_window = (uint32_t)(cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00059F51;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateWindowEx() failed! => init_main_window()";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x59F33u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00059F33: cpu->eip = LIFT_CODE_TOKEN_VA(0x459F33u);
    cpu->eax = g_sfera_scene_control_runtime.timing_anchor;
    cpu->eax -= cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_recovered_static_runtime.scene_state_07;
    cpu->eax -= cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebx = cpu->eax;
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(1u), 32u);
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    goto label_00059EF8;
    label_00059F51: cpu->eip = LIFT_CODE_TOKEN_VA(0x459F51u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::ShowWindow), LIFT_CODE_TOKEN_VA(0x459F54u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459F5Au);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::InvalidateRect), LIFT_CODE_TOKEN_VA(0x459F64u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459F6Au);
    cpu->ecx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::UpdateWindow), LIFT_CODE_TOKEN_VA(0x459F71u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459F77u);
    cpu->edx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::BringWindowToTop), LIFT_CODE_TOKEN_VA(0x459F7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459F84u);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00459FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x459FA0u);
    cpu->esp -= 0xB4u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00059FE9;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00059FE9;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, (uintptr_t)"fonts\\font%s.txt"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459FDEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459FE4u);
    cpu->esp += 0xCu;
    goto label_00059FFF;
    label_00059FE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x459FE9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_push32(cpu, (uintptr_t)"fonts\\font.txt"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459FF6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x459FFCu);
    cpu->esp += 8u;
    label_00059FFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x459FFFu);
    cpu->edx = lift_load32(cpu->esp + 0xCCu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0x20020u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_font_atlas_staging_runtime);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]), cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45A01Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45A022u);
    cpu->esp += 0xCu;
    cpu->eax = 0x100u;
    lift_push32(cpu, 0x7F9u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x400u;
    g_sfera_font_atlas_staging_runtime.magic = (uint32_t)(0x6D786554u);
    g_sfera_font_atlas_staging_runtime.width = (uint32_t)(cpu->eax);
    g_sfera_font_atlas_staging_runtime.height = (uint32_t)(cpu->eax);
    g_sfera_font_atlas_staging_runtime.mip_count = UINT32_C(1);
    g_sfera_font_atlas_staging_runtime.encoding = 0x115Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A066u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FAu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x400u;
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A07Eu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A089u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x7FDu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A09Cu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A0A7u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A0B3u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A0BAu); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load16(cpu->ebx + 0xAu);
    cpu->edx = lift_load16(cpu->ebx + 6u);
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->esi + 0xFFFFFD00u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->edi -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    ++cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A0DCu); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x805u);
    cpu->ecx = (uint32_t)(cpu->esi + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A0F0u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebp);
    lift_store8(cpu->esi + cpu->ebp, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A108u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A116u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A11Fu); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0005A140;
    cpu->ecx = cpu->eax;
    label_0005A130: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A130u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebp)) != (uint8_t)(0x23u)) goto label_0005A137;
    ++cpu->ecx;
    label_0005A137: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A137u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_0005A130;
    lift_store32(cpu->esp + 0x4Cu, cpu->ecx);
    label_0005A140: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A140u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x118u);
    lift_push32(cpu, 0x810u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A15Bu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebx + 0x80u);
    goto label_0005A174;
    label_0005A170: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A170u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    label_0005A174: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A174u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) <= (uint8_t)(0xC0u)) goto label_0005A18E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0x3Fu))) & 0xFFu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    label_0005A18E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A18Eu);
    cpu->eax = cpu->ecx & 0xFFu;
    cpu->edi -= cpu->eax;
    label_0005A193: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A193u);
    lift_store8(cpu->esi, cpu->edx & 0xFFu);
    ++cpu->esi;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,8u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A193;
    if ((uint32_t)(cpu->edi) != 0u) goto label_0005A170;
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u)) <= (int32_t)(uint32_t)(cpu->edx)) goto label_0005A1DA;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    cpu->edi = cpu->edi;
    label_0005A1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A1B0u);
    cpu->ecx = lift_load8(cpu->esi + cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx += cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(0xF0u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ecx)) <= (uint8_t)((cpu->eax & 0xFFu))) goto label_0005A1CF;
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) <= (uint8_t)((cpu->eax & 0xFFu))) goto label_0005A1CF;
    if ((uint8_t)(lift_load8(cpu->ecx + 2u)) <= (uint8_t)((cpu->eax & 0xFFu))) goto label_0005A1CF;
    lift_store8(cpu->esi + cpu->edx, 1u);
    goto label_0005A1D3;
    label_0005A1CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A1CFu);
    lift_store8(cpu->esi + cpu->edx, 0u);
    label_0005A1D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A1D3u);
    ++cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0005A1B0;
    label_0005A1DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A1DAu);
    lift_push32(cpu, 0x82Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A1EBu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->eax = 0u;
    cpu->edx = 0x1Au;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0005A829;
    lift_x87_push(cpu, 0.00390625);
    cpu->ecx = cpu->ebp;
    goto label_0005A229;
    label_0005A225: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A225u);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    label_0005A229: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A229u);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x23u)) goto label_0005A235;
    label_0005A22E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A22Eu);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebp)) != (uint8_t)(0x23u)) goto label_0005A22E;
    label_0005A235: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A235u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->ebp + 0xFFFFFFFFu)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A24C;
    label_0005A23F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A23Fu);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A8B2;
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp)) == (uint8_t)(0x20u)) goto label_0005A23F;
    label_0005A24C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A24Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) < (uint8_t)(0x30u)) goto label_0005A8B2;
    if ((uint8_t)((cpu->edx & 0xFFu)) > (uint8_t)(0x39u)) goto label_0005A8B2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + cpu->ebp + 0xFFFFFFFFu)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) < (uint8_t)(0x41u)) goto label_0005A8B2;
    if ((uint8_t)((cpu->ecx & 0xFFu)) > (uint8_t)(0x5Au)) goto label_0005A8B2;
    cpu->edi = cpu->edx & 0xFFu;
    cpu->ebx = cpu->ecx & 0xFFu;
    ++cpu->eax;
    cpu->edi -= 0x30u;
    cpu->ebx -= 0x41u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->ebp)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A2A4;
    label_0005A28E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A28Eu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->ebp + 1u)) & 0xFFu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0005A8B2;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_0005A28E;
    label_0005A2A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A2A4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->ebp)), r=(uint64_t)(0x27u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp);
    lift_store32(cpu->esp + 0x78u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A8B2;
    cpu->ecx = lift_load8(cpu->eax + cpu->ebp + 1u);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx += cpu->esi;
    cpu->edx -= cpu->eax;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->esp + 0x74u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0]));
    lift_store32(cpu->esp + 0x60u, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, 0x20u);
    label_0005A2F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A2F7u);
    cpu->esi = 0x20u;
    label_0005A2FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A2FCu);
    cpu->ebp = 0u;
    lift_store16(cpu->ecx, cpu->ebp & 0xFFFFu);
    lift_store8(cpu->edx + cpu->eax, 0u);
    lift_store8(cpu->eax, 0u);
    cpu->ecx += 2u;
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A2FC;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx += 0x200u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x24u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x24u, v); }
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A2F7;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1Au);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    cpu->ebx += 0x14u;
    lift_store32(cpu->esp + 0x7Cu, cpu->ebx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x118u);
    cpu->edi += 0x14u;
    cpu->ebx += cpu->edi;
    cpu->eax += cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0xC8u);
    cpu->edx = 0x60u;
    cpu->ecx += 3u;
    lift_store32(cpu->esp + 0x58u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->esp + 0x68u, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x64u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    label_0005A36C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A36Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = 0u;
    cpu->ecx += cpu->edx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_0005A37C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A37Cu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->esi, cpu->ecx & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_0005A3D9;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_0005A3D9;
    label_0005A38F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A38Fu);
    cpu->eax = 0u;
    label_0005A391: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A391u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(1u)) goto label_0005A3BA;
    cpu->ecx = cpu->ebx;
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0005A3A2;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0005A3C4;
    label_0005A3A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A3A2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0005A3AA;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_0005A3C4;
    label_0005A3AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A3AAu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0005A3B2;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_0005A3C4;
    label_0005A3B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A3B2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0005A3BA;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0005A3C4;
    label_0005A3BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A3BAu);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax);
    cpu->ecx += cpu->ebp;
    lift_store8(cpu->ecx + cpu->edi + 3u, 1u);
    label_0005A3C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A3C4u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005A391;
    ++cpu->esi;
    cpu->edx += 0x20u;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005A38F;
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_0005A3D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A3D9u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    ++cpu->ebp;
    ++cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x1Au)) goto label_0005A37C;
    cpu->eax = lift_load32(cpu->esp + 0x64u);
    cpu->edx += 0x20u;
    cpu->eax += 0x118u;
    lift_store32(cpu->esp + 0x68u, cpu->edx);
    lift_store32(cpu->esp + 0x64u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(0x3A0u)) goto label_0005A36C;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = 0x19u;
    cpu->edx += 0x1B71u;
    label_0005A417: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A417u);
    cpu->eax = 0x19u;
    cpu->ecx = cpu->edx;
    label_0005A41E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A41Eu);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0u)) goto label_0005A46F;
    cpu->ecx -= 0x118u;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0005A41E;
    --cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0005A417;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->esp + 0xD0u);
    cpu->ecx += cpu->eax;
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]), cpu->edx);
    label_0005A44B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A44Bu);
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = 0u;
    label_0005A451: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A451u);
    cpu->eax = 0u;
    cpu->ecx = cpu->esi;
    label_0005A455: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A455u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0u)) goto label_0005A486;
    ++cpu->eax;
    ++cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x1Au)) goto label_0005A455;
    ++cpu->edx;
    cpu->esi += 0x118u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(0x1Au)) goto label_0005A451;
    goto label_0005A490;
    label_0005A46F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A46Fu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    ++cpu->esi;
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx += cpu->eax;
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]), cpu->esi);
    goto label_0005A44B;
    label_0005A486: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A486u);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0005A490;
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    label_0005A490: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A490u);
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    cpu->esi = 0x19u;
    cpu->eax += cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x118u);
    cpu->eax += lift_load32(cpu->esp + 0x58u);
    cpu->eax += lift_load32(cpu->esp + 0x38u);
    label_0005A4A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A4A9u);
    cpu->ecx = 0u;
    cpu->edx = cpu->eax;
    label_0005A4AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A4ADu);
    if ((uint8_t)(lift_load8(cpu->edx)) != (uint8_t)(0u)) goto label_0005A4C3;
    ++cpu->ecx;
    ++cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x1Au)) goto label_0005A4AD;
    cpu->eax -= 0x118u;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0005A4A9;
    goto label_0005A4CD;
    label_0005A4C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A4C3u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x3Cu))) goto label_0005A4CD;
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    label_0005A4CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A4CDu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->eax -= cpu->edi;
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)((uint8_t*)&g_sfera_font_atlas_staging_runtime.pixels[0] + 2u)));
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, 0x20u);
    label_0005A4F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A4F4u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x1Cu, 8u);
    label_0005A504: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A504u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xFFFFFFFDu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A517;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    goto label_0005A52A;
    label_0005A517: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A517u);
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xFFFFFFFFu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A528;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFu);
    goto label_0005A52A;
    label_0005A528: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A528u);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_0005A52A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A52Au);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store16(cpu->edi + 0xFFFFFFFEu, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->ebx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A554;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    goto label_0005A566;
    label_0005A554: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A554u);
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A564;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFu);
    goto label_0005A566;
    label_0005A564: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A564u);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_0005A566: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A566u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store16(cpu->edi, cpu->eax & 0xFFFFu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xFFFFFFFFu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A58B;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    goto label_0005A59E;
    label_0005A58B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A58Bu);
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 1u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A59C;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFu);
    goto label_0005A59E;
    label_0005A59C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A59Cu);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_0005A59E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A59Eu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store16(cpu->edi + 2u, cpu->eax & 0xFFFFu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A5C4;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    goto label_0005A5D7;
    label_0005A5C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A5C4u);
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 2u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005A5D5;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFu);
    goto label_0005A5D7;
    label_0005A5D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A5D5u);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_0005A5D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A5D7u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store16(cpu->edi + 4u, cpu->eax & 0xFFFFu);
    cpu->edi += 8u;
    cpu->ebp += 4u;
    cpu->ebx += 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x1Cu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A504;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x200u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x2Cu, v); }
    cpu->eax = cpu->ebp;
    cpu->ecx = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005A4F4;
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    cpu->edx = lift_load32(cpu->esp + 0xC8u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->esp + 0x40u);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->ecx -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x60u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x60u)))));
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->ecx -= cpu->edx;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->ecx += 3u;
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    ++cpu->esi;
    lift_store_f32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].defined), 1u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].texture_index), cpu->edi);
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].v), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(8u)) goto label_0005A746;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    ++cpu->eax;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(8u)) goto label_0005A746;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = g_sfera_font_atlas_staging_runtime.height;
    cpu->eax = cpu->edi;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edi += cpu->eax;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->edi = (uint32_t)(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A6CFu); lift_push32(cpu, r); sfera_sub_004D8E70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x4Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x5A6E1u), LIFT_CODE_TOKEN_RVA(0x5A6DFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45A6E1u);
    cpu->esi = lift_load32(cpu->esp + 0x70u);
    cpu->ebp = (uint32_t)(uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0];
    if ((int32_t)(uint32_t)(g_sfera_font_atlas_staging_runtime.height) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005A728;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->eax += cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005A700: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A700u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x45A703u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45A708u);
    cpu->edx = g_sfera_font_atlas_staging_runtime.width;
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->edx);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    ++cpu->ebx;
    cpu->esp += 0xCu;
    cpu->ebp += cpu->eax;
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 2u));
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_font_atlas_staging_runtime.height)) goto label_0005A700;
    label_0005A728: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A728u);
    cpu->edi = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->eax + 0x50u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0x5A734u), LIFT_CODE_TOKEN_RVA(0x5A732u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45A734u);
    lift_x87_push(cpu, 0.00390625);
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + 1u);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->esi = lift_load32(cpu->esp + 0x40u);
    label_0005A746: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A746u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    cpu->ebp = lift_load32(cpu->esp + 0x5Cu);
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_0005A225;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0005A771;
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) == (uint32_t)(cpu->esi)) goto label_0005A821;
    label_0005A771: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A771u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = g_sfera_font_atlas_staging_runtime.height;
    cpu->ecx = g_sfera_font_atlas_staging_runtime.width;
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->esi += cpu->edi;
    cpu->esi = (uint32_t)(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x50u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A7AAu); lift_push32(cpu, r); sfera_sub_004D8E70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x4Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x5A7BFu), LIFT_CODE_TOKEN_RVA(0x5A7BDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45A7BFu);
    { uint64_t l=(uint64_t)(g_sfera_font_atlas_staging_runtime.height), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->esp + 0x70u);
    cpu->ebx = (uint32_t)(uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0];
    lift_store32(cpu->esp + 0x18u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0005A810;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->eax += cpu->eax;
    label_0005A7E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A7E0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x45A7E3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45A7E8u);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    cpu->edx = g_sfera_font_atlas_staging_runtime.width;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->edx);
    ++cpu->ecx;
    cpu->esp += 0xCu;
    cpu->ebx += cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_font_atlas_staging_runtime.height)) goto label_0005A7E0;
    label_0005A810: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A810u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x50u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5A820u), LIFT_CODE_TOKEN_RVA(0x5A81Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45A820u);
    ++cpu->edi;
    label_0005A821: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A821u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    label_0005A829: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A829u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx -= cpu->edx;
    cpu->ecx += 3u;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]), cpu->ecx);
    cpu->ecx = 0x14u;
    cpu->ecx -= cpu->edx;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0]), cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0]), cpu->edx);
    lift_push32(cpu, 0x8C8u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.resource_count[0]), cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A868u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x8C9u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A879u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, 0x8CAu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A88Cu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, 0x8CBu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A89Fu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_font_runtime.glyphs[124].defined) != (uint32_t)(0u)) goto label_0005A8BE;
    cpu->ecx = (uint32_t)(uintptr_t)"Symbol for CODE_FOR_UNDIFINED_SYMBOL is not found in font.txt";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5A8B2u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005A8B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A8B2u);
    cpu->ecx = (uint32_t)(uintptr_t)"wrong format of font1.txt";
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5A8BEu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005A8BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A8BEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045A8E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45A8E0u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->edi = cpu->edx;
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    cpu->esi = cpu->ecx;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45A910u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005A96C;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0005A949;
    lift_x87_push(cpu, 0.0);
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    cpu->eax = cpu->esi;
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0005A949: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A949u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, (uintptr_t)&g_sfera_terrain_diagnostic_runtime.normalize_code[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45A954u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45A95Au);
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_terrain_diagnostic_runtime.normalize_code[0];
    cpu->ecx = (uint32_t)(uintptr_t)"normalize: normal with extra short length found. Code:";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5A96Cu); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0005A96C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A96Cu);
    lift_x87_push(cpu, 1.0);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store32(cpu->esi, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->eax = cpu->esi;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045A9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45A9C0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x45A9D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45A9DDu);
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_0005A9F0;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)"\316\370\350\341\352\340 \356\362\352\360\373\362\350\377 \364\340\351\353\3402: ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5A9F0u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0005A9F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45A9F0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x45A9FDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA03u);
    cpu->ebx = native_function_address32(&::CloseHandle);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x5AA0Eu), LIFT_CODE_TOKEN_RVA(0x5AA0Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA0Eu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0005AA1D;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateFileMapping failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AA1Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AA1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA1Du);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x45AA26u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA2Cu);
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x5AA31u), LIFT_CODE_TOKEN_RVA(0x5AA2Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA31u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0005AA41;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)"MapViewOfFile failed  ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AA41u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0005AA41: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA41u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045AA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA50u);
    cpu->esp -= 0x18u;
    cpu->eax = address32(::GetModuleHandleW(nullptr));
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.direct_input); lift_push32(cpu, address32(&IID_IDirectInput8A)); lift_push32(cpu, 0x800u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DirectInput8Create), LIFT_CODE_TOKEN_VA(0x45AA75u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA7Au);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AA88;
    cpu->ecx = (uint32_t)(uintptr_t)"DirectInputCreate failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AA88u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AA88: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AA88u);
    cpu->eax = g_sfera_direct_input_runtime.direct_input;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_input_device_runtime.keyboard_device); lift_push32(cpu, address32(&GUID_SysKeyboard)); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5AAA1u), LIFT_CODE_TOKEN_RVA(0x5AA9Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AAA1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AAAF;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateDevice failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AAAFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AAAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AAAFu);
    cpu->eax = g_sfera_direct_input_runtime.direct_input;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.mouse_device); lift_push32(cpu, address32(&GUID_SysMouse)); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5AAC8u), LIFT_CODE_TOKEN_RVA(0x5AAC6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AAC8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AAD6;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateDevice failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AAD6u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AAD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AAD6u);
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x34u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x5AAECu), LIFT_CODE_TOKEN_RVA(0x5AAEAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AAECu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AAFA;
    cpu->ecx = (uint32_t)(uintptr_t)"SetCooperativeLevel failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AAFAu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AAFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AAFAu);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x34u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x5AB10u), LIFT_CODE_TOKEN_RVA(0x5AB0Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AB10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AB1E;
    cpu->ecx = (uint32_t)(uintptr_t)"SetCooperativeLevel failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AB1Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AB1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AB1Eu);
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x2Cu);
    lift_push32(cpu, address32(&c_dfDIKeyboard)); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5AB30u), LIFT_CODE_TOKEN_RVA(0x5AB2Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AB30u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AB3E;
    cpu->ecx = (uint32_t)(uintptr_t)"SetDataFormat failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AB3Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AB3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AB3Eu);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x2Cu);
    lift_push32(cpu, address32(&c_dfDIMouse)); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5AB50u), LIFT_CODE_TOKEN_RVA(0x5AB4Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AB50u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AB5E;
    cpu->ecx = (uint32_t)(uintptr_t)"SetDataFormat failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AB5Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AB5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AB5Eu);
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->edx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 4u, 0x14u);
    lift_store32(cpu->esp + 8u, 0x10u);
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_store32(cpu->esp + 0x14u, 8u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x18u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x5AB99u), LIFT_CODE_TOKEN_RVA(0x5AB97u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AB99u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005ABA7;
    cpu->ecx = (uint32_t)(uintptr_t)"SetProperty failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ABA7u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005ABA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ABA7u);
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5ABB4u), LIFT_CODE_TOKEN_RVA(0x5ABB2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45ABB4u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5ABC1u), LIFT_CODE_TOKEN_RVA(0x5ABBFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45ABC1u);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045AC40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005AC54;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC54u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005AC54: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC54u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005AC68;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC68u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005AC68: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC68u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_0005AC7D;
    cpu->ecx = (uint32_t)(uintptr_t)"text_color: wrong handle";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC7Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AC7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC7Du);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005AC8B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC8Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005AC8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC8Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005AC9F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC9Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005AC9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC9Fu);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->edx + 0x28u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005ACB9;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ACB9u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005ACB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ACB9u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005ACCD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ACCDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005ACCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ACCDu);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 0xE80u, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045ACF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45ACF0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005AD00: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AD00u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005AD14;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AD14u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005AD14: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AD14u);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005AD22;
    ++cpu->esi;
    goto label_0005AD00;
    label_0005AD22: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AD22u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFFu)) goto label_0005ADA4;
    cpu->edx = 0xD4Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45AD36u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45AD3Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AD7D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->eax + 0x18u, cpu->edi);
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->esi);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.object_reference_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count)) + 1u);
    cpu->edi = cpu->eax;
    goto label_0005AD7F;
    label_0005AD7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AD7Du);
    cpu->edi = 0u;
    label_0005AD7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AD7Fu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005AD93;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AD93u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005AD93: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AD93u);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
    label_0005ADA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ADA4u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005ADB8;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ADB8u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005ADB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ADB8u);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u))) != (uint32_t)(0u)) goto label_0005ADCE;
    cpu->ecx = (uint32_t)(uintptr_t)"create_line: wrong handle";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ADCEu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005ADCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ADCEu);
    cpu->edx = 0xD52u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45ADDDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45ADE4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005AE24;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->eax + 0x18u, cpu->edi);
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ebx);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.object_reference_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count)) + 1u);
    cpu->edi = cpu->eax;
    goto label_0005AE26;
    label_0005AE24: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AE24u);
    cpu->edi = 0u;
    label_0005AE26: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AE26u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005AE3A;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AE3Au); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005AE3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AE3Au);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045AE50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AE50u);
    cpu->esp -= 0x4B8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x4C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x4C8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(1u)) goto label_0005AE8F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45AE8Au); lift_push32(cpu, r); sfera_sub_004A5270(cpu,r); if (cpu->eip != r) return; }
    goto label_0005AF7E;
    label_0005AE8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AE8Fu);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->ebx, 0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->edx = 1u;
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005AF3A;
    label_0005AEB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AEB4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x14u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0xAu)) goto label_0005AEF0;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x4CCu));
    lift_store32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0005AED9;
    lift_store32(cpu->esi, cpu->eax);
    label_0005AED9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AED9u);
    ++cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0x12Cu)) goto label_0005AF98;
    lift_store32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x14u, 0u);
    goto label_0005AF2F;
    label_0005AEF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AEF0u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0005AF05;
    cpu->ebx = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x14u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0005AF05: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF05u);
    cpu->eax = cpu->ecx & 0xFFu;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].defined))) != (uint32_t)(0u)) goto label_0005AF1F;
    cpu->eax = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[124][0]));
    goto label_0005AF2B;
    label_0005AF1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF1Fu);
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx += cpu->eax;
    cpu->eax = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    label_0005AF2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF2Bu);
    lift_store32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x14u, (uint64_t)(lift_load32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_0005AF2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF2Fu);
    ++cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->ebp)) != (uint8_t)(0u)) goto label_0005AEB4;
    label_0005AF3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF3Au);
    cpu->eax = lift_load32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0005AF44;
    lift_store32(cpu->esi, cpu->eax);
    label_0005AF44: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF44u);
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + (uint64_t)(2u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    --cpu->edx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])));
    cpu->edx -= lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0]));
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 2u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x4CCu));
    lift_store32(cpu->ebx, cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(1u)) goto label_0005AF7D;
    cpu->eax += 2u;
    lift_store32(cpu->ebx, cpu->eax);
    label_0005AF7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF7Du);
    cpu->ebp = lift_pop32(cpu);
    label_0005AF7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF7Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4B8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0005AF98: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AF98u);
    cpu->ecx = (uint32_t)(uintptr_t)"MNO_LINES_IN_TEXT exceeded";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45AFA2u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x45AFA2u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045AFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45AFB0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45AFBCu); lift_push32(cpu, r); sfera_sub_00449180(cpu,r); if (cpu->eip != r) return; }
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_01) = (uint8_t)(1u);
    cpu->edi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45AFCAu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    g_sfera_client_process_runtime.shutdown_requested = (uint32_t)(cpu->edi);
    label_0005AFD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AFD6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45AFDBu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->ebx;
    cpu->edi += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x2710u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0005AFEE;
    cpu->edi = 0x2710u;
    label_0005AFEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AFEEu);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1Au);
    cpu->eax = 0x4EC4EC4Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xFFFFFFCCu);
    cpu->edi += cpu->edx;
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_0005B02A;
    label_0005B015: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B015u);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B01Cu); lift_push32(cpu, r); sfera_sub_004496F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_client_process_runtime.shutdown_requested) != (uint32_t)(0u)) goto label_0005B054;
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->esi)) goto label_0005B015;
    label_0005B02A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B02Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B02Fu); lift_push32(cpu, r); sfera_sub_004D0FC0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_render_lookup_runtime.initialized) == (uint32_t)(1u)) goto label_0005B042;
    lift_push32(cpu, 0xAu);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x45B03Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B040u);
    goto label_0005AFD6;
    label_0005B042: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B042u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B047u); lift_push32(cpu, r); sfera_sub_004595F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B04Cu); lift_push32(cpu, r); sfera_sub_0042EB70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x5B04Eu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x5B054u);
    label_0005B054: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B054u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045B060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45B060u);
    cpu->esp -= 0x19Cu;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x138u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->ebx = 0u;
    label_0005B087: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B087u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0005B087;
    cpu->eax = (uint32_t)(cpu->esp + 0x13Cu);
    --cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005B0A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B0A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0005B0A0;
    cpu->ecx = lift_load32((uintptr_t)"*.siz");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"*.siz") + 4u)) & 0xFFFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store16(cpu->eax + 4u, cpu->edx & 0xFFFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x140u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x45B0C8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B0CEu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0005B0E6;
    cpu->ecx = (uint32_t)(uintptr_t)"*.siz files not found";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B0E6u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005B0E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B0E6u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    label_0005B0F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B0F0u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_0005B32A;
    cpu->esi = g_sfera_recovered_static_runtime.font_renderer_state;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(0x12Bu)) goto label_0005B364;
    cpu->ebp = cpu->esi;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x6CCu);
    label_0005B117: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B117u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B125;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B125u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B125: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B125u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B139;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B139u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B139: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B139u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->edi + 0x40u)) & 0xFFu);
    cpu->eax += cpu->ebp;
    lift_store8(cpu->eax + cpu->edi, cpu->ecx & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)(lift_load8(cpu->esp + cpu->edi + 0x40u)) != (uint8_t)(0x2Eu)) goto label_0005B117;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B15D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B15Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B15D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B15Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B171;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B171u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B171: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B171u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->eax += cpu->ebp;
    lift_store8(cpu->eax + cpu->edi, cpu->ebx & 0xFFu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B18D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B18Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B18D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B18Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B1A1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B1A1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B1A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B1A1u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->ebp + 0x1Eu);
    label_0005B1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B1B0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->edi;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0005B1B0;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B1C5u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B1D5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B1D5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B1D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B1D5u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B1E9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B1E9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B1E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B1E9u);
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->ebp + 0x84u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B1FFu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B20D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B20Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B20D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B20Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B221;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B221u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B221: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B221u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebp + 0x88u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B236u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B23Du); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->ebp + 0x21Cu);
    lift_store32(cpu->esp + 0x10u, 0xAu);
    label_0005B250: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B250u);
    cpu->ebp = 0xAu;
    label_0005B255: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B255u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B263;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B263u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B263: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B263u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B277;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B277u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B277: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B277u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    lift_store32(cpu->edi + cpu->ecx + 0xFFFFFE70u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B292;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B292u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B292: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B292u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B2A6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B2A6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B2A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B2A6u);
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    lift_store32(cpu->edi + cpu->edx, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B2BD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B2BDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B2BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B2BDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B2D1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B2D1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B2D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B2D1u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    lift_store32(cpu->edi + cpu->eax + 0x190u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B2EB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B2EBu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B2EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B2EBu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B2FF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B2FFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B2FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B2FFu);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    lift_store32(cpu->edi + cpu->ecx + 0x320u, cpu->ebx);
    cpu->edi += 4u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005B255;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005B250;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.font_renderer_state, (uint64_t)(g_sfera_recovered_static_runtime.font_renderer_state) + 1u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    label_0005B32A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B32Au);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x45B330u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B336u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005B0F0;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x45B342u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B348u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x19Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0005B364: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B364u);
    cpu->ecx = (uint32_t)(uintptr_t)"Too many landscape files\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B36Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x45B36Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045B370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45B370u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1326u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x20000u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B385u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    g_sfera_client_main_scalar_runtime.state_02 = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45B395u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B39Au);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape\\*.mtx";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B3A7u); lift_push32(cpu, r); sfera_sub_0044D960(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(0u)) goto label_0005B3BA;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_hr\\*.mtx";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B3BAu); lift_push32(cpu, r); sfera_sub_0044D960(cpu,r); if (cpu->eip != r) return; }
    label_0005B3BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B3BAu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21)) == (uint32_t)(0u)) goto label_0005B3CD;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_ph\\*.mtx";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B3CDu); lift_push32(cpu, r); sfera_sub_0044D960(cpu,r); if (cpu->eip != r) return; }
    label_0005B3CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B3CDu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22)) == (uint32_t)(0u)) goto label_0005B3E0;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_rd\\*.mtx";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B3E0u); lift_push32(cpu, r); sfera_sub_0044D960(cpu,r); if (cpu->eip != r) return; }
    label_0005B3E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B3E0u);
    if ((uint32_t)(g_sfera_graphics_runtime.base_microtexture_id) != (uint32_t)(0xFFFFFFFFu)) goto label_0005B3F3;
    cpu->ecx = (uint32_t)(uintptr_t)"Base microtexture not found: landscape\\\077\077_.mtx";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B3F3u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005B3F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B3F3u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_0005B3F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B3F6u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005B404;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B404u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B404: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B404u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.microtexture_handles.capacity)) goto label_0005B418;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B418u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B418: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B418u);
    cpu->eax = g_sfera_landscape_runtime.microtexture_handles.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), 0xFFFFFFFFu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x2710u)) goto label_0005B3F6;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B437u); lift_push32(cpu, r); sfera_sub_0045B060(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(0u)) goto label_0005B44A;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_hr\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B44Au); lift_push32(cpu, r); sfera_sub_0045B060(cpu,r); if (cpu->eip != r) return; }
    label_0005B44A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B44Au);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21)) == (uint32_t)(0u)) goto label_0005B45D;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_ph\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B45Du); lift_push32(cpu, r); sfera_sub_0045B060(cpu,r); if (cpu->eip != r) return; }
    label_0005B45D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B45Du);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22)) == (uint32_t)(0u)) goto label_0005B470;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_rd\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B470u); lift_push32(cpu, r); sfera_sub_0045B060(cpu,r); if (cpu->eip != r) return; }
    label_0005B470: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B470u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape\\map.bin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B47Cu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x22600u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B48Fu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B496u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_0005B4A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B4A0u);
    cpu->ebx = 0x50u;
    label_0005B4A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B4A5u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0005B4F8;
    cpu->ebp = 0u;
    label_0005B4B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B4B1u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0005B4BF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B4BFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B4BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B4BFu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B4D3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B4D3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B4D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B4D3u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x45B4DCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B4E2u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005B519;
    ++cpu->edi;
    cpu->ebp += 0x6CCu;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state)) goto label_0005B4B1;
    label_0005B4F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B4F8u);
    cpu->edx = lift_load32((uintptr_t)"FILL_EMPT");
    cpu->eax = lift_load32(((uint32_t)(uintptr_t)"FILL_EMPT") + 4u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"FILL_EMPT") + 8u)) & 0xFFFFu);
    lift_store32(cpu->esi, cpu->edx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store16(cpu->esi + 8u, cpu->ecx & 0xFFFFu);
    lift_store16(cpu->esi + 0x14u, 0u);
    label_0005B519: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B519u);
    cpu->esi += 0x16u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005B4A5;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[kLandscapeMapRecordCount]))) goto label_0005B4A0;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    (void)cpu;
    label_0005B530: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B530u);
    cpu->ebp = 0u;
    label_0005B532: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B532u);
    cpu->esi = 0u;
    cpu->edi = 0u;
    label_0005B540: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B540u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_recovered_static_runtime.font_renderer_state), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0005B5F6;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005B55A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B55Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B55A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B55Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B56E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B56Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B56E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B56Eu);
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x16u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x45B585u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B58Bu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005B59B;
    ++cpu->esi;
    cpu->edi += 0x6CCu;
    goto label_0005B540;
    label_0005B59B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B59Bu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005B5A9;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B5A9u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005B5A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B5A9u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_0005B5BD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B5BDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005B5BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B5BDu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x6CCu);
    cpu->esi += g_sfera_landscape_runtime.file_records.data;
    cpu->edx = (uint32_t)(cpu->ebx + cpu->ebp);
    ++cpu->ebp;
    lift_store32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]), cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x50u)) goto label_0005B532;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ebx += 0x50u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x1900u)) goto label_0005B530;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0005B5F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B5F6u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx += cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16u);
    cpu->edx += ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->ecx = (uint32_t)(uintptr_t)"Patch present in map, but not found in \\landscape. Name: ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B615u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x45B615u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045B620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45B620u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xACu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xC0u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    cpu->edi = lift_load32(cpu->esp + 0xD4u);
    cpu->esi = lift_load32(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x50u, cpu->ecx);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B688u); lift_push32(cpu, r); sfera_sub_00453A20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005BC34;
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x78u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B6A1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45B6AAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45B6AFu);
    cpu->esp += 0xCu;
    cpu->ebx = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esp + 0x54u, 0x1Eu);
    lift_store32(cpu->esp + 0x58u, 0x32u);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x60u, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B6DFu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = native_function_address32(&::strncpy);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x5B6EDu), LIFT_CODE_TOKEN_RVA(0x5B6EBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45B6EDu);
    cpu->esp += 0xCu;
    lift_store8(cpu->esp + 0x6Fu, 0u);
    lift_store32(cpu->esp + 0x80u, 0x1513u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = (uint32_t)(cpu->ebx + 0x14u);
    lift_store32(cpu->esp + 0xCCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B71Au); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x84u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->edx + 0xCu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->edx + 0x14u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store16(cpu->edx + 0x1Cu, cpu->ecx & 0xFFFFu);
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esp + 0x8Cu, 0x1Eu);
    lift_store32(cpu->esp + 0x90u, 0x32u);
    lift_store32(cpu->esp + 0x94u, cpu->ebx);
    lift_store32(cpu->esp + 0x98u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45B7A0u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x5B7ABu), LIFT_CODE_TOKEN_RVA(0x5B7A9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45B7ABu);
    cpu->esp += 0xCu;
    lift_store8(cpu->esp + 0xA7u, 0u);
    lift_store32(cpu->esp + 0xB8u, 0x1514u);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x68B0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store8(cpu->esp + 0xC8u, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u) + 0x68B0u))) goto label_0005B7EB;
    cpu->ecx = (uint32_t)(uintptr_t)"Error of smoothing region's edge: numbers of vertex groups are differ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B7EBu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005B7EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B7EBu);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x68A0u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u) + 0x68A0u);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0005BBF9;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    goto label_0005B81B;
    label_0005B813: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B813u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    label_0005B81B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B81Bu);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->ebx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    ++cpu->edx;
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->ebp = lift_load16(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    ++cpu->ecx;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0005B898;
    label_0005B83B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B83Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005B84C;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B84Cu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B84C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B84Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u));
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    ++cpu->ecx;
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005B888;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B888u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B888: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B888u);
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    lift_store8(cpu->ecx + cpu->esi, 0u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B83B;
    label_0005B898: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B898u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0005B8FA;
    cpu->edi = cpu->ebp;
    label_0005B89E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B89Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005B8AF;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B8AFu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B8AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B8AFu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->eax = lift_load16(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edx = lift_load32(cpu->edx + 8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    ++cpu->ecx;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005B8EB;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B8EBu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B8EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B8EBu);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    lift_store8(cpu->eax + cpu->esi, 0u);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005B89E;
    label_0005B8FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B8FAu);
    cpu->ebx += cpu->ebp;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0005BBEF;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0005B910: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B910u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005B927;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B927u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B927: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B927u);
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->edi)) == (uint8_t)(2u)) goto label_0005BBE6;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005B94F;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B94Fu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B94F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B94Fu);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store8(cpu->edx + cpu->edi, 1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005B96B;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B96Bu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B96B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B96Bu);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->eax = lift_load32(cpu->eax + 0x14u);
    cpu->esi = (uint32_t)(cpu->edi + 1u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005BAFA;
    label_0005B992: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B992u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005B9A9;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B9A9u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B9A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B9A9u);
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) == (uint8_t)(2u)) goto label_0005BAF1;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005B9CB;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B9CBu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B9CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B9CBu);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005B9E7;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5B9E7u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005B9E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45B9E7u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005BA03;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BA03u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BA03: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BA03u);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005BA1F;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BA1Fu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BA1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BA1Fu);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->ebx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005BA37;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BA37u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BA37: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BA37u);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005BA4F;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BA4Fu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BA4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BA4Fu);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    cpu->eax = lift_load32(cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->ecx = lift_load32(cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx))));
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->ebp);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x14u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0005BAED;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005BAA9;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BAA9u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BAA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BAA9u);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store8(cpu->edx + cpu->esi, 1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005BAC5;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BAC5u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BAC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BAC5u);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005BAED: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BAEDu);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    label_0005BAF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BAF1u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B992;
    label_0005BAFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BAFAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BB25u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->esi = cpu->edi;
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005BBE6;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_0005BB70: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BB70u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005BB87;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BB87u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BB87: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BB87u);
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(1u)) goto label_0005BBDB;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x88u))) goto label_0005BBAB;
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BBABu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BBAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BBABu);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store8(cpu->edx + cpu->esi, 2u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_0005BBC7;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BBC7u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005BBC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BBC7u);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->ebp);
    lift_store32(cpu->eax + 0x14u, cpu->ebx);
    label_0005BBDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BBDBu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_0005BB70;
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    label_0005BBE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BBE6u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0005B910;
    label_0005BBEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BBEFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x34u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005B813;
    label_0005BBF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BBF9u);
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_store8(cpu->esp + 0xCCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BC14u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_store32(cpu->esp + 0xCCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BC2Fu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    label_0005BC34: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BC34u);
    cpu->ecx = lift_load32(cpu->esp + 0xC0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB8u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045BC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45BC60u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = 0u;
    g_sfera_window_runtime.runtime_debug_enabled = (uint32_t)(1u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.debug_config_enabled)) == (uint32_t)(cpu->esi)) goto label_0005BCCE;
    cpu->ecx = (uint32_t)(uintptr_t)"debug.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCA1u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_window_runtime.runtime_debug_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"RUNTIME";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCB0u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.escape_without_query;
    cpu->ecx = (uint32_t)(uintptr_t)"ESCNOQUERY";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCBFu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_world_load_runtime.render_shadows;
    cpu->ecx = (uint32_t)(uintptr_t)"RENDERSHADOW";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5BCCEu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    label_0005BCCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BCCEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCD3u); lift_push32(cpu, r); sfera_sub_00459370(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCD8u); lift_push32(cpu, r); sfera_sub_004980F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCE2u); lift_push32(cpu, r); sfera_sub_0048DA70(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCE7u); lift_push32(cpu, r); sfera_sub_00457490(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BCECu); lift_push32(cpu, r); sfera_sub_00451E00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32((uintptr_t)"cursor1");
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[5], lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"cursor1") + 4u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[4], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[3], lift_x87_get(cpu, 0u));
    cpu->edi |= 0xFFFFFFFFu;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[2], lift_x87_get(cpu, 0u));
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.default_cursor_token[0]) = (uint32_t)(cpu->eax);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[1], lift_x87_get(cpu, 0u));
    g_sfera_world_objects.controlled_object_handle = (uint32_t)(cpu->edi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[0], lift_x87_get(cpu, 0u));
    g_sfera_recovered_static_runtime.interaction_enabled = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.z.f32, lift_x87_get(cpu, 0u));
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.render_channel_mask) = (uint32_t)(0xFFu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.y.f32, lift_x87_get(cpu, 0u));
    lift_store32((uintptr_t)&g_sfera_main_command_state_runtime.default_cursor_token[1], cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.x.f32, lift_x87_get(cpu, 0u));
    g_sfera_window_runtime.active_window_index = (uint32_t)(cpu->edi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.render_scale.x.f32, lift_x87_get(cpu, 0u));
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(cpu->esi);
    lift_x87_push(cpu, 1.0);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_02) = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.render_scale.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.render_scale.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.05999999865889549f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.base_render_factor, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-05f);
    lift_store_f32((uint32_t)(uintptr_t)((uint8_t *)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0] + 0xF4u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005BD96: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BD96u);
    lift_store32(cpu->eax + 0xFFFFFFF4u, cpu->esi);
    lift_store32(cpu->eax, cpu->esi);
    cpu->eax += 0x10u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[kTextureCacheEntryCount] + offsetof(SferaTextureCacheEntry, use_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005BD96;
    cpu->edx = 0x15C2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BDB4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BDBBu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0005BDD3;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BDD1u); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    goto label_0005BDD5;
    label_0005BDD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BDD3u);
    cpu->eax = 0u;
    label_0005BDD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BDD5u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"Landscape\\zoning.cfg");
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    g_sfera_recovered_static_runtime.scene_state_08 = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BDEAu); lift_push32(cpu, r); sfera_sub_0049DF00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x15C4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BDF9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BE00u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0005BE1C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BE1Au); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    goto label_0005BE1E;
    label_0005BE1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BE1Cu);
    cpu->eax = 0u;
    label_0005BE1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BE1Eu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"Landscape\\zoningHaron.cfg");
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    g_sfera_world_render_queue_runtime.entries[0] = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BE33u); lift_push32(cpu, r); sfera_sub_0049DF00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045BE50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45BE50u);
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].kind;
    label_0005BE76: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BE76u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xFFFFFFFCu)) != (uint32_t)(cpu->eax)) goto label_0005BE86;
    cpu->esi = lift_load8(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005BF04;
    label_0005BE86: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BE86u);
    cpu->ecx += 0x10u;
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[kTextureCacheEntryCount] + offsetof(SferaTextureCacheEntry, kind))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005BE76;
    cpu->edx = 0u;
    cpu->esi = (uint32_t)(cpu->edx + 1u);
    cpu->ecx = 0x10u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0005BEA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BEA0u);
    cpu->ebp = lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count));
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count)))) goto label_0005BEB2;
    cpu->edx = cpu->esi;
    cpu->edi = cpu->ecx;
    label_0005BEB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BEB2u);
    cpu->ecx += 0x10u;
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x320u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005BEA0;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    lift_store8(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].kind), cpu->ebx & 0xFFu);
    lift_store32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].owner), cpu->eax);
    lift_store32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count), 0u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->ebx) * 2u) + 0x18u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->edx = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].resource));
    cpu->ebx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 8u));
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(6u), 32u);
    cpu->ebx += lift_load32(cpu->eax + 0x2Cu);
    cpu->edx += 0x21u;
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    goto label_0005BF3C;
    label_0005BF04: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BF04u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->esi = cpu->edx;
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45BF1Cu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count), cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005BF34: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BF34u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    label_0005BF3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BF3Cu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->edi = lift_load8(cpu->ecx + cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_a[0]));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_b[0]));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_a[0]));
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->esi = lift_load8(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_b[0]));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->eax += cpu->eax;
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.blend_lut[0]);
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, 0x40u);
    goto label_0005BF98;
    label_0005BF90: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BF90u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    label_0005BF98: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BF98u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load8(cpu->ecx);
    cpu->ebp = lift_load8(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 2u);
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load8(cpu->ecx);
    cpu->ecx += cpu->eax;
    cpu->eax = lift_load8(cpu->ecx + cpu->ebx + 0x19u);
    cpu->ecx += cpu->ebx;
    cpu->ebx = lift_load8(cpu->edi + 3u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = lift_load8(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = lift_load8(cpu->edi + 1u);
    cpu->edi = lift_load8(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = lift_load8(cpu->ecx + 1u);
    cpu->ecx = lift_load8(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_0005BFEE;
    cpu->eax = 0xFFu;
    label_0005BFEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45BFEEu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store8(cpu->edx, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load8(cpu->eax + 1u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load8(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 3u);
    cpu->ebp = lift_load8(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 2u);
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load8(cpu->eax + 1u);
    cpu->ecx += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load8(cpu->ecx + 0x19u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = lift_load8(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = lift_load8(cpu->edi + 1u);
    cpu->edi = lift_load8(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = lift_load8(cpu->ecx + 1u);
    cpu->ecx = lift_load8(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_0005C055;
    cpu->eax = 0xFFu;
    label_0005C055: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C055u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + 2u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store8(cpu->edx + 2u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load8(cpu->eax + 2u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load8(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 3u);
    cpu->ebp = lift_load8(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 2u);
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load8(cpu->eax + 2u);
    cpu->ecx += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load8(cpu->ecx + 0x19u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = lift_load8(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = lift_load8(cpu->edi + 1u);
    cpu->edi = lift_load8(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = lift_load8(cpu->ecx + 1u);
    cpu->ecx = lift_load8(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_0005C0BE;
    cpu->eax = 0xFFu;
    label_0005C0BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C0BEu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + 4u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store8(cpu->edx + 4u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load8(cpu->eax + 3u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load8(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 3u);
    cpu->ebp = lift_load8(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 2u);
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load8(cpu->eax + 3u);
    cpu->ecx += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load8(cpu->ecx + 0x19u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = lift_load8(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = lift_load8(cpu->edi + 1u);
    cpu->edi = lift_load8(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = lift_load8(cpu->ecx + 1u);
    cpu->ecx = lift_load8(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_0005C127;
    cpu->eax = 0xFFu;
    label_0005C127: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C127u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + 6u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = 4u;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store8(cpu->edx + 6u, cpu->ecx & 0xFFu);
    cpu->edx += 8u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x24u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x24u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005BF90;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    ++cpu->ecx;
    cpu->ebx = 0x100u;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005BF34;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x5C184u), LIFT_CODE_TOKEN_RVA(0x5C182u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45C184u);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x5C199u), LIFT_CODE_TOKEN_RVA(0x5C197u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45C199u);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0005C1AB;
    cpu->ecx = (uint32_t)(uintptr_t)"BeginDraw has returned NULL";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5C1ABu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005C1AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C1ABu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x54u)) != (uint32_t)(cpu->ebx)) goto label_0005C21D;
    if ((uint32_t)(lift_load32(cpu->esp + 0x58u)) != (uint32_t)(cpu->ebx)) goto label_0005C21D;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x18u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].resource));
    cpu->eax += 0x20u;
    label_0005C1D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C1D1u);
    cpu->esi = cpu->eax;
    cpu->edi = cpu->edx;
    cpu->ecx = 0x80u;
    lift_movs32(cpu, 1u);
    cpu->edx += lift_load32(cpu->esp + 0x34u);
    cpu->eax += 0x200u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005C1D1;
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x50u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x5C1F7u), LIFT_CODE_TOKEN_RVA(0x5C1F5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45C1F7u);
    cpu->ecx = lift_load32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C20Au); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005C21D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C21Du);
    cpu->ecx = (uint32_t)(uintptr_t)"BeginDraw has returned texture size != 256x256";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C227u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x45C227u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045C230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45C230u);
    cpu->esp -= 0xB8u;
    lift_x87_push(cpu, (double)0.1899999976158142f);
    lift_push32(cpu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, cpu->esi);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005C277;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.8299999833106995);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005C279;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x20u, 0x96u);
    goto label_0005C286;
    label_0005C277: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C277u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005C279: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C279u);
    cpu->ebp = 1u;
    lift_store32(cpu->esp + 0x20u, 0x40u);
    label_0005C286: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C286u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x));
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x));
    cpu->eax = cpu->esp;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].x));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)g_sfera_view_geometry_runtime.reference_points[3].y)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)g_sfera_view_geometry_runtime.reference_points[3].z)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xBCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC0u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 5u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = 1u;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C37Du); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0xA8u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0xACu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    lift_store32(cpu->esp + 0xB0u, cpu->edx);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB0u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_view_geometry_runtime.reference_points[1].x)));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    g_sfera_recovered_static_runtime.scene_state_09 = (uint32_t)(0u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.position_offset.x.f32)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y));
    lift_store32(cpu->esp + 0xA8u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.position_offset.y.f32)));
    cpu->eax = (uint32_t)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z));
    lift_store32(cpu->esp + 0xB0u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.position_offset.z.f32)));
    cpu->ecx = (uint32_t)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0xBCu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C457u); lift_push32(cpu, r); sfera_sub_00451A40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0005CB15;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xBCu));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 0.8999999761581421);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xB4u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x30u))));
    cpu->eax = (uint32_t)(cpu->esp + 0xA8u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0xBCu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    cpu->ecx = (uint32_t)(cpu->esp + 0xB8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xC4u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C520u); lift_push32(cpu, r); sfera_sub_0042F7D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005CB15;
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    cpu->edx = lift_load32(cpu->esp + 0xB4u);
    cpu->eax = lift_load32(cpu->esp + 0xB8u);
    cpu->ecx = lift_load32(cpu->esp + 0xBCu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (640.0));
    g_sfera_recovered_static_runtime.flare_clip_vector.x.u32 = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xA8u);
    g_sfera_recovered_static_runtime.flare_clip_vector.y.u32 = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xACu);
    g_sfera_recovered_static_runtime.flare_clip_vector.z.u32 = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xB0u);
    g_sfera_flare_projection.x.u32 = (uint32_t)(cpu->edx);
    g_sfera_flare_projection.y.u32 = (uint32_t)(cpu->eax);
    g_sfera_flare_projection.z.u32 = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005C59B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (256.0));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    goto label_0005C5C1;
    label_0005C59B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C59Bu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(g_sfera_graphics_runtime.display_width)))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    label_0005C5C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C5C1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->edi = 0u;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C6ABu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C6C0u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0005C6D5;
    label_0005C6D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C6D3u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005C6D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C6D5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xA8u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xACu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x98u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005C74D;
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    label_0005C74D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C74Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005C760;
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0005C762;
    label_0005C760: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C760u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005C762: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C762u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005C777;
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    label_0005C777: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C777u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005C78C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005C78C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C78Cu);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_0005C79C;
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ecx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5C79Cu); lift_push32(cpu, r); sfera_sub_004501C0(cpu,r); if (cpu->eip != r) return; }
    label_0005C79C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45C79Cu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x68u))));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x70u))));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 4u)));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height)))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x74u))));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    cpu->eax = cpu->esp;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x98u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x9Cu))));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xA0u))));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    lift_store32(cpu->eax, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB0u));
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C979u); lift_push32(cpu, r); sfera_sub_00457840(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C994u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (3.1415929794311523));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45C9C1u); lift_push32(cpu, r); sfera_sub_0044E400(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store16(cpu->esp + 0x1Cu, cpu->fpu_control);
    lift_store32(cpu->esi + 0x14u, 0u);
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->esi += 0x20u;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    ++cpu->edi;
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->ecx |= 0xFFFFFFu;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store32(cpu->esi + 0xFFFFFFF0u, cpu->ecx);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0xFFFFFFE8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[4]))) goto label_0005C6D3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005CB13;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x28u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005CB13;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005CB13;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x20u)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005CB15;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_0005CAAF;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CA82u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"sun";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CA8Cu); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CA99u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"sun";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CAA3u); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_recovered_static_runtime.scene_state_09 = (uint32_t)(1u);
    goto label_0005CADA;
    label_0005CAAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CAAFu);
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CAB8u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"moon";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CAC2u); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CAD0u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"moon";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CADAu); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    label_0005CADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CADAu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CAEAu); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 0xEu); lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CB06u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CB11u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    goto label_0005CB15;
    label_0005CB13: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CB13u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005CB15: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CB15u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xB8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045CB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45CB30u);
    cpu->esp -= 0x404u;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005CB65;
    label_0005CB4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CB4Du);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 4u, stop_address); return;
    label_0005CB65: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CB65u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_0005CB4D;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CB7Du); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005CB86;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005CB86: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CB86u);
    cpu->ecx = lift_load32(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CB9Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45CBA0u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CBACu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x45CBACu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045CBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45CBB0u);
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0005CC2A;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005CBC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CBC0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0005CBCB;
    cpu->eax = lift_load32(cpu->eax);
    label_0005CBCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CBCBu);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s\t%d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CBDAu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)(0u)) goto label_0005CC22;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0005CC02;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0005CC22;
    label_0005CBF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CBF6u);
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0005CBF6;
    goto label_0005CC22;
    label_0005CC02: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC02u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0005CC20;
    label_0005CC10: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC10u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0005CC20;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0005CC10;
    label_0005CC20: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC20u);
    cpu->esi = cpu->eax;
    label_0005CC22: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC22u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(g_sfera_model_registry_runtime.sentinel)) goto label_0005CBC0;
    label_0005CC2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC2Au);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045CC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC30u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005CD20;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005CC63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CC63u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005CC63: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC63u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005CD20;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005CC86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CC86u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005CC86: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CC86u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->edx + 0x138u)) == (uint8_t)(0u)) goto label_0005CD4B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005CCB0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CCB0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005CCB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CCB0u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0005CCD8;
    label_0005CCBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CCBCu);
    cpu->eax = lift_load32(cpu->esi + 0x18Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005CCD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CCD8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005CCBC;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CCF0u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005CCF9;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005CCF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CCF9u);
    lift_push32(cpu, 0x2475u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CD0Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45CD14u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CD20u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005CD20: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CD20u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_0005CD30: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CD30u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005CD30;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"GetProcess: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CD4Au); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0005CD4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CD4Bu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045CD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45CD70u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005CD98;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CD98u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005CD98: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CD98u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005CDAC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CDACu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005CDAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CDACu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005CDE5;
    label_0005CDB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CDB8u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x144u)) >= (int32_t)(uint32_t)(0u)) goto label_0005CE2D;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CDCEu); lift_push32(cpu, r); sfera_sub_0041B560(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005CDE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CDE5u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_0005CDB8;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CDFDu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005CE06;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005CE06: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CE06u);
    lift_push32(cpu, 0x247Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CE1Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45CE21u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CE2Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005CE2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CE2Du);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CE3Du); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005CEB8;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005CE57;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CE57u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005CE57: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CE57u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005CEB8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x50u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005CE7B;
    cpu->ecx = (uint32_t)(uintptr_t)"GetSubAnimLen: model has no animation";
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)((cpu->eax & 0xFFu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CE79u); lift_push32(cpu, r); sfera_sub_0044F4C0(cpu,r); if (cpu->eip != r) return; }
    goto label_0005CED9;
    label_0005CE7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CE7Bu);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0005CE92;
    cpu->ecx = (uint32_t)(uintptr_t)"GetSubAnimLen: negative subanimation number";
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CE90u); lift_push32(cpu, r); sfera_sub_0044F4C0(cpu,r); if (cpu->eip != r) return; }
    goto label_0005CED9;
    label_0005CE92: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CE92u);
    cpu->edx = cpu->eax & 0xFFu;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0005CEDE;
    cpu->eax = lift_load32(cpu->edi + 0x5Cu);
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->ebp) * 2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005CEB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CEB8u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0005CEC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CEC5u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005CEC5;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetSubAnimLen: wrong handle";
    lift_movs32(cpu, 1u);
    label_0005CED9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CED9u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CEDEu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_0005CEDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CEDEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045CF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45CF00u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005CFCB;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005CF33;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CF33u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005CF33: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CF33u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005CFCB;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005CF56;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CF56u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005CF56: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CF56u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0005CFFD;
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005CFAF;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CF7Fu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005CF88;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005CF88: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CF88u);
    lift_push32(cpu, 0x248Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CF9Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45CFA3u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5CFAFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005CFAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CFAFu);
    cpu->eax = (uint32_t)(cpu->esi + 0x170u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005CFCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CFCBu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005CFE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CFE0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005CFE0;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"GetAnimation: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45CFFCu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0005CFFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45CFFDu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045D020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45D020u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005D0EB;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D053;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D053u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D053: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D053u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005D0EB;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D076;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D076u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D076: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D076u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0005D11D;
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005D0CF;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D09Fu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005D0A8;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005D0A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D0A8u);
    lift_push32(cpu, 0x2493u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D0BDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45D0C3u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D0CFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005D0CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D0CFu);
    cpu->eax = (uint32_t)(cpu->esi + 0x174u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005D0EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D0EBu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005D100: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D100u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005D100;
    cpu->ecx = 5u;
    cpu->esi = (uint32_t)(uintptr_t)"GetFrame: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D11Cu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0005D11D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D11Du);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045D140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45D140u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005D20B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D173;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D173u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D173: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D173u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005D20B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D196;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D196u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D196: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D196u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0005D25A;
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005D1EF;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D1BFu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005D1C8;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005D1C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D1C8u);
    lift_push32(cpu, 0x249Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D1DDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45D1E3u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D1EFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005D1EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D1EFu);
    cpu->eax = (uint32_t)(cpu->esi + 0x178u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005D20B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D20Bu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->eax;
    label_0005D218: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D218u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0005D218;
    cpu->ecx = lift_load32((uintptr_t)"GetInterp: wrong handle");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetInterp: wrong handle") + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetInterp: wrong handle") + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetInterp: wrong handle") + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetInterp: wrong handle") + 0x10u);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetInterp: wrong handle") + 0x14u);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D25Au); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_0005D25A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D25Au);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045D280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45D280u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005D34B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D2B3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D2B3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D2B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D2B3u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005D34B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D2D6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D2D6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D2D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D2D6u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0005D39A;
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005D32F;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D2FFu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005D308;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005D308: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D308u);
    lift_push32(cpu, 0x24A5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D31Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45D323u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D32Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005D32F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D32Fu);
    cpu->eax = (uint32_t)(cpu->esi + 0x17Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005D34B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D34Bu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->eax;
    label_0005D358: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D358u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0005D358;
    cpu->ecx = lift_load32((uintptr_t)"GetFrame2: wrong handle");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetFrame2: wrong handle") + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetFrame2: wrong handle") + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetFrame2: wrong handle") + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetFrame2: wrong handle") + 0x10u);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetFrame2: wrong handle") + 0x14u);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D39Au); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_0005D39A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D39Au);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045D3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45D3C0u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005D48B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D3F3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D3F3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D3F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D3F3u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005D48B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D416;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D416u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D416: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D416u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0005D4BA;
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005D46F;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D43Fu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005D448;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005D448: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D448u);
    lift_push32(cpu, 0x24AEu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D45Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45D463u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D46Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005D46F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D46Fu);
    cpu->eax = (uint32_t)(cpu->esi + 0x180u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005D48B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D48Bu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005D4A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D4A0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005D4A0;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetAnimation2: wrong handle";
    lift_movs32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D4B9u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0005D4BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D4BAu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045D4E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45D4E0u);
    cpu->esp -= 0x418u;
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0005D512;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D512u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005D512: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D512u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005D526;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D526u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D526: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D526u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ebx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0005D57E;
    if ((uint8_t)(lift_load8(cpu->ebx + 0x138u)) != (uint8_t)(0u)) goto label_0005D588;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D54Eu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005D557;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005D557: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D557u);
    lift_push32(cpu, 0x29F1u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D56Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45D572u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D57Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005D57E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D57Eu);
    cpu->ecx = (uint32_t)(uintptr_t)"CalcCharacterNeck: wrong handle";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D588u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005D588: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D588u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x144u)) >= (int32_t)(uint32_t)(0u)) goto label_0005D5B8;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D59Eu); lift_push32(cpu, r); sfera_sub_0041C5B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005D5B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D5B8u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D5C7u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    g_sfera_world_render_runtime.active_model = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 0x170u);
    cpu->eax = lift_load32(cpu->ebx + 0x174u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->edx) < 0) goto label_0005D5F7;
    cpu->esi = lift_load8(cpu->ecx + 0x50u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->esi)) goto label_0005D62C;
    label_0005D5F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D5F7u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0005D604: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D604u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005D604;
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(uintptr_t)"CalcCharacterNeck: wrong animation";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D620u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_0005D62C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D62Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005D661;
    cpu->eax = lift_load32(cpu->ecx + 0x5Cu);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    ++cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->ecx);
    label_0005D644: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D644u);
    cpu->ebx = lift_load16(cpu->eax);
    cpu->esi += cpu->ebx;
    cpu->ebx = lift_load16(cpu->eax + 2u);
    cpu->edi += cpu->ebx;
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005D644;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0005D661: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D661u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0005D674;
    cpu->ecx = lift_load32(cpu->ecx + 0x5Cu);
    cpu->ecx = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebp) * 2u));
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0005D674: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D674u);
    cpu->edi += cpu->esi;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0005D68B;
    cpu->esi = lift_load32(cpu->ecx + 0x5Cu);
    cpu->edx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0005D6BA;
    label_0005D68B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D68Bu);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0005D698: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D698u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005D698;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"CalcCharacterNeck: wrong frame";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D6B4u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0u;
    label_0005D6BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D6BAu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    cpu->edx += cpu->eax;
    g_sfera_client_main_scalar_runtime.state_06 = (uint32_t)(cpu->edx);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = (uint32_t)(cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ebx + 0x178u)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005D7E4;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = (uint32_t)(1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x178u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ebx + 0x180u);
    cpu->eax = lift_load32(cpu->ebx + 0x17Cu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0005D719;
    cpu->esi = lift_load8(cpu->ecx + 0x50u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->esi)) goto label_0005D74C;
    label_0005D719: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D719u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0005D726: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D726u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005D726;
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)"CalcCharacterNeck: wrong animation 2";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D740u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = 0u;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_0005D74C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D74Cu);
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005D784;
    cpu->eax = lift_load32(cpu->ecx + 0x5Cu);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    ++cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    label_0005D767: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D767u);
    cpu->ebp = lift_load16(cpu->eax);
    cpu->esi += cpu->ebp;
    cpu->ebp = lift_load16(cpu->eax + 2u);
    cpu->edi += cpu->ebp;
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005D767;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    label_0005D784: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D784u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0005D795;
    cpu->eax = lift_load32(cpu->ecx + 0x5Cu);
    cpu->ebp = lift_load16(cpu->eax + ((uint32_t)(cpu->ebp) * 2u));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    goto label_0005D799;
    label_0005D795: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D795u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    label_0005D799: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D799u);
    cpu->edi += cpu->esi;
    cpu->ebp += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0005D7AC;
    cpu->ecx = lift_load32(cpu->ecx + 0x5Cu);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u));
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0005D7DC;
    label_0005D7AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D7ACu);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005D7C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D7C0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005D7C0;
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(uintptr_t)"CalcCharacterNeck: wrong frame 2";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D7DAu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    label_0005D7DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D7DCu);
    cpu->ebp += cpu->eax;
    g_sfera_render_sample_runtime.material_base = (uint32_t)(cpu->ebp);
    label_0005D7E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D7E4u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_character_frame_matrix.m[0][0]);
    cpu->edx = (uint32_t)(cpu->ebx + 0x14u);
    cpu->ecx = (uint32_t)(cpu->ebx + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D7F4u); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load8(cpu->eax + 0x40u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D806u); lift_push32(cpu, r); sfera_sub_00454FF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_scene_vector_runtime.frame_102_position.x.u32;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = g_sfera_scene_vector_runtime.frame_102_position.y.u32;
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = g_sfera_scene_vector_runtime.frame_102_position.z.u32;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045D840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45D840u);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    cpu->edx = 2u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D897u); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x28u));
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = 3u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D8EFu); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x40u));
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x44u));
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = 4u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45D947u); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    cpu->esi = (uint32_t)(cpu->esp + 0x24u);
    cpu->ebx = 3u;
    label_0005D964: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D964u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.800000011920929);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0005DA36;
    cpu->eax = g_sfera_window_runtime.clip_vector_count;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    g_sfera_window_runtime.clip_vector_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0005D99D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D99Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005D99D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D99Du);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.clip_vectors.capacity)) goto label_0005D9B1;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D9B1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D9B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D9B1u);
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFFF8u);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFFCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = g_sfera_window_runtime.clip_vector_count;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    g_sfera_window_runtime.clip_vector_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0005D9E8;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D9E8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005D9E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D9E8u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.clip_vectors.capacity)) goto label_0005D9FC;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5D9FCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005D9FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x45D9FCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFF8u));
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFFCu));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax, cpu->edx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    label_0005DA36: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DA36u);
    cpu->esi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005D964;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045DA60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45DA60u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005DA80;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5DA80u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005DA80: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DA80u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005DA94;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5DA94u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005DA94: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DA94u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x138u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (uint32_t)(cpu->esi + 0x3Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005DB52;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2D8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005DB1C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2DCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005DB1C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2E0u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005DB1C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2E4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005DB1C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2E8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005DB1C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2ECu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0005DC42;
    label_0005DB1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DB1Cu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x2D8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esi + 0x2DCu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x2E0u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->esi + 0x2E4u, cpu->ecx);
    lift_store32(cpu->esi + 0x2E8u, cpu->edx);
    lift_store32(cpu->esi + 0x2ECu, cpu->eax);
    label_0005DB52: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DB52u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DB62u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->edi + 0x6Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005DBD5;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_0005DBD5;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DB7Du); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = (uint32_t)(cpu->ebx + 0x58u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    cpu->edi += 0x88u;
    cpu->ebp = 8u;
    (void)cpu;
    label_0005DB90: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DB90u);
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DBA9u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi += 0xCu;
    cpu->esi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005DB90;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->ebx + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DBC2u); lift_push32(cpu, r); sfera_sub_0044F870(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005DBD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DBD5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x74u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x78u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store32(cpu->ebx + 0x40u, cpu->eax);
    lift_store32(cpu->ebx + 0x44u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebx + 0x48u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x7Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x80u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x84u));
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store32(cpu->ebx + 0x4Cu, cpu->eax);
    lift_store32(cpu->ebx + 0x50u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ebx + 0x54u, cpu->edx);
    label_0005DC42: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DC42u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045DC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45DC60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005DC74;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5DC74u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005DC74: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DC74u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005DC88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5DC88u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005DC88: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DC88u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = (uint32_t)(cpu->esi + 0x44u);
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(0xFFFFFFFFu)) goto label_0005DCB0;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0005DCA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DCA0u);
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x1B58u)) goto label_0005DCBA;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(0xFFFFFFFFu)) goto label_0005DCA0;
    label_0005DCB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DCB0u);
    lift_store32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x44u, cpu->edi);
    lift_store32(cpu->esi + 0x40u, (uint64_t)(lift_load32(cpu->esi + 0x40u)) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0005DCBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DCBAu);
    cpu->ecx = (uint32_t)(uintptr_t)"MNO_CONTROLS_IN_WINDOW exceed";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DCC4u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x45DCC4u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045DCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45DCD0u);
    cpu->esp -= 0xC8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005E512;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005DD04;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5DD04u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005DD04: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DD04u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005E512;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005DD27;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5DD27u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005DD27: cpu->eip = LIFT_CODE_TOKEN_VA(0x45DD27u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0005E0F4;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0005E0F4;
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x24u);
    cpu->esi = lift_load32(cpu->ebp + 0x28u);
    cpu->eax -= cpu->ecx;
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->esi -= cpu->edx;
    lift_x87_push(cpu, 0.00390625);
    ++cpu->esi;
    cpu->ebx = (uint32_t)(cpu->esp + 0xB4u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->ebx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"winfon"); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DDDAu); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.0234375f);
    cpu->edx = lift_load32(cpu->ebp + 0x14u);
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u));
    cpu->eax = cpu->ebx;
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)0.046875f);
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DE47u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->ebp + 0x14u);
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.0234375f);
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u));
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.046875f);
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x24u);
    cpu->ecx -= cpu->edx;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DEB7u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->ebp + 0x20u);
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.0234375f);
    cpu->eax = lift_load32(cpu->ebp + 0x28u);
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u));
    cpu->edx = cpu->ebx;
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)0.046875f);
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0x18u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    ++cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DF28u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.0234375f);
    cpu->eax = lift_load32(cpu->ebp + 0x28u);
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u));
    cpu->edx = cpu->ebx;
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)0.046875f);
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0x18u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45DF98u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u));
    cpu->eax -= cpu->ecx;
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00390625));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = lift_load32(cpu->ebp + 0x14u);
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u));
    cpu->esi = cpu->ebx;
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 8u);
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)0.0234375f);
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 0x24u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"wf_bord");
    cpu->esi -= cpu->edx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E016u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax = lift_load32(cpu->ebp + 0x28u);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0x18u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0x20u);
    cpu->edx -= cpu->ecx;
    ++cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E043u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->ebp + 0x24u);
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->ebp + 0x28u);
    lift_x87_push(cpu, (double)0.0234375f);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u));
    cpu->eax -= cpu->edx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u));
    ++cpu->eax;
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->esi = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00390625));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E0C5u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->ebp + 0x24u);
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x28u);
    cpu->ecx -= cpu->edx;
    ++cpu->ecx;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E0F2u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    label_0005E0F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E0F4u);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    lift_store32(cpu->esp + 0x4Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x20u);
    cpu->ecx -= lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x28u);
    cpu->edx -= lift_load32(cpu->ebp + 0x24u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    ++cpu->edx;
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E132u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x24u);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x28u);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x34u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E15Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x38u));
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E169u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x40u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0005E4C2;
    label_0005E180: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E180u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u) + 0x44u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->edi) * 4u) + 0x44u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005E19D;
    label_0005E190: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E190u);
    cpu->eax += 4u;
    ++cpu->edi;
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0xFFFFFFFFu)) goto label_0005E190;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_0005E19D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E19Du);
    cpu->esi = lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u) + 0x44u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005E1AF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E1AFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005E1AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E1AFu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005E1C3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E1C3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005E1C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E1C3u);
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ebx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_0005E508;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0xE80u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0005E39A;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x24u));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E20Au); lift_push32(cpu, r); sfera_sub_004558A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0005E4AB;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E21Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E229u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005E23E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E23Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005E23E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E23Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005E252;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E252u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005E252: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E252u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = 1u;
    cpu->esi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0005E272;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E272u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005E272: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E272u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x10u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E2C4u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 100.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0005E4A7;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E2F4u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebx + 0x1Cu);
    cpu->ecx = 0xFFu;
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005E310;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E310u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005E310: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E310u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005E324;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E324u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005E324: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E324u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_model_transform_scratch_matrix;
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E365u); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (2.0));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.x));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005E398;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.009999999776482582));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0005E39A;
    label_0005E398: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E398u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005E39A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E39Au);
    cpu->eax = lift_load32(cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005E40B;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005E4AB;
    lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xE80u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x30u));
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = lift_load32(cpu->ebx + 0xE54u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xE50u);
    cpu->edx = (uint32_t)(cpu->ebx + 0xE58u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebx + 0xE4Cu);
    cpu->edx -= lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx += lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xE48u);
    cpu->ecx -= lift_load32(cpu->esp + 0x50u);
    cpu->ecx += lift_load32(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E406u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    goto label_0005E4AB;
    label_0005E40B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E40Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0005E4AB;
    cpu->edi = (uint32_t)(cpu->ebx + 0x4E0u);
    label_0005E423: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E423u);
    cpu->esi = lift_load32(cpu->ebx + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->eax = lift_load32(cpu->ebx + 0xE40u);
    cpu->edx = lift_load32(cpu->ebx + 0xE44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->edi + 0x4B0u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->esi &= 0xFFFFFFu;
    cpu->ecx |= cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0xFFFFFB50u);
    cpu->ecx -= lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->edi);
    cpu->edx -= lift_load32(cpu->esp + 0x50u);
    cpu->ecx += lift_load32(cpu->esp + 0x38u);
    cpu->edx += lift_load32(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E490u); lift_push32(cpu, r); sfera_sub_0044D190(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 0x2Cu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005E423;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    goto label_0005E4AB;
    label_0005E4A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E4A7u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005E4AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E4ABu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    ++cpu->edi;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x40u))) goto label_0005E180;
    label_0005E4C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E4C2u);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x58u, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E4EFu); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xC8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005E508: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E508u);
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 37185837";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E512u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005E512: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E512u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    (void)cpu;
    label_0005E520: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E520u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005E520;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"draw_window: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E53Bu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xC8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045E560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45E560u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    cpu->esi = 0u;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0005E62A;
    label_0005E575: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E575u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005E583;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E583u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005E583: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E583u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005E597;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E597u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005E597: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E597u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_0005E5A5;
    ++cpu->esi;
    goto label_0005E575;
    label_0005E5A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E5A5u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005E5B3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E5B3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005E5B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E5B3u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005E5C7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E5C7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005E5C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E5C7u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005E5DE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E5DEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005E5DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E5DEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005E5F2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5E5F2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005E5F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E5F2u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_load32(cpu->ecx + 0x3Cu);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x3E8u);
    cpu->edx += lift_load32(cpu->eax + 0x6DA4u);
    lift_store32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]), cpu->esi);
    lift_store32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]), cpu->edx);
    ++cpu->ebx;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->edi)) goto label_0005E575;
    label_0005E62A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E62Au);
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E634u); lift_push32(cpu, r); sfera_sub_0044F940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0005E655;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0005E640: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E640u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E64Cu); lift_push32(cpu, r); sfera_sub_0045DCD0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count))) goto label_0005E640;
    label_0005E655: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E655u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045E660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45E660u);
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    cpu->eax = cpu->esp;
    cpu->esi = cpu->edx;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 8u))));
    cpu->edx = 6u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E6ADu); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E6DFu); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005E6EB;
    label_0005E6E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E6E3u);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005E6EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45E6EBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x2Cu));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 8u))));
    cpu->edx = 7u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E72Fu); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E761u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x3Cu));
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x40u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x44u));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 8u))));
    cpu->edx = 8u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E7ADu); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    lift_store32(cpu->esp + 0x4Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E7DFu); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    cpu->edx = 9u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E82Bu); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E85Du); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x28u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    cpu->edx = 0xAu;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E8A9u); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E8DBu); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x3Cu));
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x40u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x44u));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    cpu->edx = 0xBu;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E927u); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E959u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E973u); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E991u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E9ABu); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E9C9u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45E9E3u); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EA01u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EA1Bu); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EA39u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EA53u); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EA71u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EA8Bu); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EAA9u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EAC3u); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EAE1u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EAFBu); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EB19u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005E6E3;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EB33u); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EB51u); lift_push32(cpu, r); sfera_sub_0044FA70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045EB60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45EB60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005EB74;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EB74u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005EB74: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EB74u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005EB88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EB88u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EB88: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EB88u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_0005EB9D;
    cpu->ecx = (uint32_t)(uintptr_t)"set_sprite_alpha: wrong handle";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EB9Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005EB9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EB9Du);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005EBAB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EBABu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005EBAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EBABu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005EBBF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EBBFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EBBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EBBFu);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->edx + 0xE80u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045EBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45EBE0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0005ECF0;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005EC06;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EC06u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EC06: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC06u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(cpu->ebx)) goto label_0005ECF0;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005EC28;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EC28u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EC28: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC28u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x40u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005ECB1;
    label_0005EC41: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC41u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x44u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x44u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005EC59;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005EC50: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC50u);
    cpu->eax += 4u;
    ++cpu->ebx;
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0xFFFFFFFFu)) goto label_0005EC50;
    label_0005EC59: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC59u);
    cpu->esi = lift_load32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x44u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005EC6B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EC6Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005EC6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC6Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005EC7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EC7Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EC7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC7Fu);
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0005ECE6;
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0005EC95;
    cpu->ebp = cpu->eax;
    label_0005EC95: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EC95u);
    cpu->esi = lift_load32(cpu->esi + 0x18u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0005ECA2;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_0005ECA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ECA2u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x40u))) goto label_0005EC41;
    label_0005ECB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ECB1u);
    cpu->eax = lift_load32(cpu->edi + 0x20u);
    cpu->eax -= lift_load32(cpu->edi + 0x1Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x28u);
    cpu->ecx -= lift_load32(cpu->edi + 0x24u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    ++cpu->ebp;
    ++cpu->eax;
    ++cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0005ECCA;
    cpu->ebp = cpu->eax;
    label_0005ECCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ECCAu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0005ECD4;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_0005ECD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ECD4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + 0x2Cu, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->edi + 0x30u, cpu->eax);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005ECE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ECE6u);
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 47581837";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ECF0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005ECF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ECF0u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005ED00: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ED00u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005ED00;
    cpu->ecx = 0xAu;
    cpu->esi = (uint32_t)(uintptr_t)"recalc_virtual_window_size: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0044F500(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045ED20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45ED20u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0005ED44;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ED44u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005ED44: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ED44u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005ED58;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ED58u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005ED58: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ED58u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(1u)) goto label_0005EE13;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2B4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005EDDD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2B8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005EDDD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2BCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005EDDD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2C0u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005EDDD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2C4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005EDDD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2C8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0005EF02;
    label_0005EDDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EDDDu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x2B4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esi + 0x2B8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x2BCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->esi + 0x2C0u, cpu->ecx);
    lift_store32(cpu->esi + 0x2C4u, cpu->edx);
    lift_store32(cpu->esi + 0x2C8u, cpu->eax);
    label_0005EE13: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EE13u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EE1Cu); lift_push32(cpu, r); sfera_sub_0045DA60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x7Cu));
    lift_x87_push(cpu, 2.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, 0.11999999731779099);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, 100000.0);
    lift_x87_set(cpu, 3u, (lift_x87_get(cpu, 3u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EE3Eu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x84u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    cpu->ebp = (uint32_t)(cpu->eax + 0xFFFE7960u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EE59u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x88u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    cpu->eax -= 0x186A0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EE73u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x90u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFE7960u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EE8Eu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (uint32_t)(cpu->eax + 0xFFFE7960u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xF4240u)) goto label_0005EEBE;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_0005EEB5;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) != (uint32_t)(cpu->ecx)) goto label_0005EEB5;
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) != (uint32_t)(cpu->edi)) goto label_0005EEB5;
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) == (uint32_t)(cpu->ebx)) goto label_0005EF00;
    label_0005EEB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EEB5u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EEBEu); lift_push32(cpu, r); sfera_sub_00455D80(cpu,r); if (cpu->eip != r) return; }
    label_0005EEBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EEBEu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_world_load_runtime.live_object_count, (uint64_t)(g_sfera_world_load_runtime.live_object_count) + 1u);
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(cpu->edi)) goto label_0005EEF0;
    label_0005EEC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EEC8u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0005EEE1;
    label_0005EED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EED0u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45EEDCu); lift_push32(cpu, r); sfera_sub_004898B0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0005EED0;
    label_0005EEE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EEE1u);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0005EEC8;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_0005EEF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EEF0u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x24u, cpu->ebp);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    lift_store32(cpu->esi + 0x30u, cpu->ebx);
    label_0005EF00: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF00u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0005EF02: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF02u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045EF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF20u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_world_objects.extended_object_count;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0005F007;
    lift_push32(cpu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0005EF50: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF50u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0005EF5E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EF5Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005EF5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF5Eu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_0005EF72;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EF72u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EF72: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF72u);
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_0005EF80;
    ++cpu->edi;
    goto label_0005EF50;
    label_0005EF80: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF80u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0005EF8E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EF8Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005EF8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EF8Eu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_0005EFA2;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EFA2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EFA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EFA2u);
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005EFB9;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EFB9u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005EFB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EFB9u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005EFCD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EFCDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005EFCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EFCDu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005EFE3;
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) == (uint8_t)(0u)) goto label_0005F01F;
    label_0005EFE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EFE3u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x141u)) == (uint8_t)(0u)) goto label_0005EFFC;
    if ((uint32_t)(lift_load32(cpu->eax + 0x184u)) != (uint32_t)(0u)) goto label_0005EFFC;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5EFFCu); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    label_0005EFFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x45EFFCu);
    ++cpu->ebx;
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0005EF50;
    cpu->esi = lift_pop32(cpu);
    label_0005F007: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F007u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005F01F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F01Fu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F02Eu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005F037;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005F037: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F037u);
    lift_push32(cpu, 0x31AEu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45F04Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45F052u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F05Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x45F05Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045F060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45F060u);
    cpu->esp -= 0x64u;
    { uint64_t l=(uint64_t)(lift_load32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_15)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0005F744;
    if ((uint32_t)(cpu->esi) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_0005F744;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F092u); lift_push32(cpu, r); sfera_sub_0045DA60(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005F0A0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F0A0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005F0A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F0A0u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005F0B4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F0B4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005F0B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F0B4u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F0CBu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebx + 0x6Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_0005F0DE;
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0005F44D;
    label_0005F0DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F0DEu);
    cpu->edi = 0xFF00FF00u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0005F0ED;
    cpu->edi = 0xFFFF0000u;
    label_0005F0ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F0EDu);
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->ecx = lift_load32(cpu->esi + 0xA4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xA8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x94u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x98u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F135u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xACu);
    cpu->ecx = lift_load32(cpu->esi + 0xB0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xB4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xA8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F17Du); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xB8u);
    cpu->ecx = lift_load32(cpu->esi + 0xBCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xC0u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xACu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xB0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xB4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F1C5u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x94u);
    cpu->ecx = lift_load32(cpu->esi + 0x98u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xB8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xBCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xC0u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F20Du); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xD0u);
    cpu->ecx = lift_load32(cpu->esi + 0xD4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xC4u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xC8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xCCu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F255u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esi + 0xE0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xE4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xD0u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xD4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F29Du); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xE8u);
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xF0u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xE0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xE4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F2E5u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xC4u);
    cpu->ecx = lift_load32(cpu->esi + 0xC8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xCCu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xE8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F32Du); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xC4u);
    cpu->ecx = lift_load32(cpu->esi + 0xC8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xCCu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    cpu->ecx = lift_load32(cpu->esi + 0xB8u);
    cpu->edx = lift_load32(cpu->esi + 0xBCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xC0u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F375u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xD0u);
    cpu->ecx = lift_load32(cpu->esi + 0xD4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x94u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x98u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F3BDu); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esi + 0xE0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xE4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xA8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F405u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xE8u);
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xF0u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xACu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xB0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xB4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F44Du); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0005F44D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F44Du);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x6Cu)) != (uint32_t)(0u)) goto label_0005F73A;
    cpu->ecx = (uint32_t)(cpu->esi + 0x7Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F463u); lift_push32(cpu, r); sfera_sub_004259C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->ebx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F4A2u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_store32(cpu->eax + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F4D5u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F514u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F54Fu); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F58Eu); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F5CDu); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x64u);
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x78u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F60Cu); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F64Eu); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F68Du); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F6C8u); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_store32(cpu->eax + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F6FBu); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x64u);
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x78u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F73Au); lift_push32(cpu, r); sfera_sub_0045ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0005F73A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F73Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F73Fu); lift_push32(cpu, r); sfera_sub_00451EB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F744u); lift_push32(cpu, r); sfera_sub_00451E00(cpu,r); if (cpu->eip != r) return; }
    label_0005F744: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F744u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x64u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045F760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45F760u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005F8A9;
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F79C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F797u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F79C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F79Cu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005F8A9;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F7C1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F7BCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F7C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F7C1u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->ecx + 0x138u)) != (uint8_t)(0u)) goto label_0005F814;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F7E3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F7E3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005F7E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F7E3u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005F814: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F814u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F824;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F824u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005F824: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F824u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0005F861;
    label_0005F830: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F830u);
    cpu->eax = lift_load32(cpu->esi + 0x190u);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005F861: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F861u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005F830;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F879u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005F882;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005F882: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F882u);
    lift_push32(cpu, 0x3897u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45F897u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45F89Du);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F8A9u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005F8A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F8A9u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0005F8B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F8B7u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005F8B7;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"GetHandPosL: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F8D2u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0005F8EA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F8EAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005F8EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F8EAu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ebx, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x408u);
    lift_store32(cpu->ebx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045F920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45F920u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005FA69;
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F95C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F957u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F95C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F95Cu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005FA69;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F981;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45F97Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F981: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F981u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->ecx + 0x138u)) != (uint8_t)(0u)) goto label_0005F9D4;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F9A3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F9A3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005F9A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F9A3u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005F9D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F9D4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005F9E4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5F9E4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005F9E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F9E4u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0005FA21;
    label_0005F9F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45F9F0u);
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005FA21: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FA21u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005F9F0;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FA39u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005FA42;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005FA42: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FA42u);
    lift_push32(cpu, 0x38A0u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FA57u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45FA5Du);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FA69u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005FA69: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FA69u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0005FA77: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FA77u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005FA77;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"GetHandPosR: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FA92u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0005FAAA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FAAAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FAAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FAAAu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ebx, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x408u);
    lift_store32(cpu->ebx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045FAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45FAE0u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005FC29;
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005FB1C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FB17u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005FB1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FB1Cu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005FC29;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005FB41;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FB3Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005FB41: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FB41u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->ecx + 0x138u)) != (uint8_t)(0u)) goto label_0005FB94;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005FB63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FB63u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FB63: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FB63u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005FB94: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FB94u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0005FBA4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FBA4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FBA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FBA4u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0005FBE1;
    label_0005FBB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FBB0u);
    cpu->eax = lift_load32(cpu->esi + 0x228u);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x22Cu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x230u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005FBE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FBE1u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005FBB0;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FBF9u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005FC02;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005FC02: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FC02u);
    lift_push32(cpu, 0x38A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FC17u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45FC1Du);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FC29u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005FC29: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FC29u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0005FC37: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FC37u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005FC37;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"GetSwordPos: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FC52u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0005FC6A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FC6Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FC6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FC6Au);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ebx, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x408u);
    lift_store32(cpu->ebx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045FCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45FCA0u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005FD9F;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FCD7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FCD7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FCD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FCD7u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005FD9F;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FCFA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FCFAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FCFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FCFAu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->edx + 0x138u)) == (uint8_t)(0u)) goto label_0005FDCA;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FD24;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FD24u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FD24: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FD24u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0005FD57;
    label_0005FD30: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FD30u);
    cpu->esi += 0x1A8u;
    cpu->edi = cpu->ebx;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005FD57: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FD57u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005FD30;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FD6Fu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005FD78;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005FD78: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FD78u);
    lift_push32(cpu, 0x38BBu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FD8Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45FD93u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FD9Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005FD9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FD9Fu);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005FDB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FDB0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005FDB0;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetHandOrientL: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FDCAu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_0005FDCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FDCAu);
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45FDCFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45FDD4u);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = lift_load32(cpu->esp + 0x418u);
    lift_store_f32(cpu->ebx + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x14u, lift_x87_get(cpu, 0u));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045FE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45FE00u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005FEFF;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FE37;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FE37u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FE37: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FE37u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005FEFF;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FE5A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FE5Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FE5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FE5Au);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->edx + 0x138u)) == (uint8_t)(0u)) goto label_0005FF2A;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FE84;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FE84u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FE84: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FE84u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0005FEB7;
    label_0005FE90: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FE90u);
    cpu->esi += 0x1E8u;
    cpu->edi = cpu->ebx;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_0005FEB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FEB7u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005FE90;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45FECFu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005FED8;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0005FED8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FED8u);
    lift_push32(cpu, 0x38C4u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FEEDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45FEF3u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FEFFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005FEFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FEFFu);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0005FF10: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FF10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0005FF10;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetHandOrientR: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FF2Au); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_0005FF2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FF2Au);
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45FF2Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45FF34u);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = lift_load32(cpu->esp + 0x418u);
    lift_store_f32(cpu->ebx + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x14u, lift_x87_get(cpu, 0u));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0045FF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45FF60u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0006005F;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FF97;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FF97u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FF97: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FF97u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0006005F;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FFBA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FFBAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FFBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FFBAu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->edx + 0x138u)) == (uint8_t)(0u)) goto label_0006008A;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0005FFE4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5FFE4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005FFE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FFE4u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_00060017;
    label_0005FFF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x45FFF0u);
    cpu->esi += 0x234u;
    cpu->edi = cpu->ebx;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_00060017: cpu->eip = LIFT_CODE_TOKEN_VA(0x460017u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0005FFF0;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46002Fu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00060038;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00060038: cpu->eip = LIFT_CODE_TOKEN_VA(0x460038u);
    lift_push32(cpu, 0x38CDu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46004Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x460053u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6005Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006005F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46005Fu);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00060070: cpu->eip = LIFT_CODE_TOKEN_VA(0x460070u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00060070;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetSwordOrient: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6008Au); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_0006008A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46008Au);
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46008Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x460094u);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = lift_load32(cpu->esp + 0x418u);
    lift_store_f32(cpu->ebx + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x14u, lift_x87_get(cpu, 0u));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004600C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4600C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00060105;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_000600DB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x600DBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000600DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4600DBu);
    cpu->eax = g_sfera_light_runtime.handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00060105;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_000600FA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x600FAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000600FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4600FAu);
    cpu->ecx = g_sfera_light_runtime.handles.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00060105: cpu->eip = LIFT_CODE_TOKEN_VA(0x460105u);
    cpu->ecx = (uint32_t)(uintptr_t)"GetLight: wrong handle";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46010Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x46010Fu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00460110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x460110u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) != (uint32_t)(1u)) goto label_0006017E;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00060129;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60129u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00060129: cpu->eip = LIFT_CODE_TOKEN_VA(0x460129u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_0006013D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6013Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006013D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46013Du);
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(1u)) goto label_000601E9;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(8u)) goto label_000601B2;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46016Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x460171u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6017Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006017E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46017Eu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006018C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6018Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006018C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46018Cu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_000601A0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x601A0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000601A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4601A0u);
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_000601E9;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.light_update_counter, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u);
    label_000601B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4601B2u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000601C0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x601C0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000601C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4601C0u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_000601D4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x601D4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000601D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4601D4u);
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), cpu->edi);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x601E9u); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_000601E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4601E9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004601F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4601F0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    label_00060202: cpu->eip = LIFT_CODE_TOKEN_VA(0x460202u);
    cpu->ebx = cpu->ecx;
    cpu->ebp = 0x50u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00060210: cpu->eip = LIFT_CODE_TOKEN_VA(0x460210u);
    lift_store16(cpu->esi + 0x14u, 0u);
    if ((uint8_t)(lift_load8(cpu->ebx)) != (uint8_t)(0u)) goto label_0006022D;
    cpu->eax = lift_load32((uintptr_t)"fill");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"fill") + 4u)) & 0xFFu);
    lift_store32(cpu->esi, cpu->eax);
    lift_store8(cpu->esi + 4u, cpu->edx & 0xFFu);
    goto label_00060241;
    label_0006022D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46022Du);
    cpu->edi = cpu->esi;
    cpu->eax = cpu->ebx;
    cpu->edi -= cpu->ebx;
    label_00060233: cpu->eip = LIFT_CODE_TOKEN_VA(0x460233u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edi + cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00060233;
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    label_00060241: cpu->eip = LIFT_CODE_TOKEN_VA(0x460241u);
    cpu->esi += 0x16u;
    cpu->ebx += 0x6E0u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00060210;
    cpu->ecx += 0x16u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[kLandscapeMapRecordCount]))) goto label_00060202;
    cpu->eax = (uint32_t)(cpu->edi + 0x14u);
    cpu->edi -= cpu->eax;
    cpu->ecx = (uint32_t)(cpu->edi + 0x15u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->edi = cpu->edi;
    label_00060270: cpu->eip = LIFT_CODE_TOKEN_VA(0x460270u);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    label_00060276: cpu->eip = LIFT_CODE_TOKEN_VA(0x460276u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_00060285;
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->edi)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_0006031D;
    label_00060285: cpu->eip = LIFT_CODE_TOKEN_VA(0x460285u);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0006031D;
    cpu->ebp += cpu->edx;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x16u);
    cpu->edx = (uint32_t)(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    label_000602A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4602A8u);
    cpu->ebx = 0u;
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->edi)) <= (uint8_t)((cpu->ebx & 0xFFu))) goto label_000602F7;
    cpu->ebp = (uint32_t)(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0]));
    cpu->ecx = 0xFFFFFFECu;
    cpu->ecx -= cpu->ebp;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    goto label_000602C6;
    label_000602C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4602C2u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    label_000602C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4602C6u);
    cpu->eax = cpu->ebp;
    cpu->esi = (uint32_t)(cpu->edx + cpu->ecx);
    label_000602D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4602D0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000602D0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x10u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store8(cpu->edx + 1u, cpu->ebx & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    cpu->eax = lift_load8(cpu->ecx + cpu->edi);
    ++cpu->ebx;
    cpu->edx -= 0x16u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000602C2;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    label_000602F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4602F7u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load8(cpu->edi);
    ++cpu->eax;
    cpu->edx += 0x6E0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_000602A8;
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    label_0006031D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46031Du);
    ++cpu->edx;
    cpu->edi += 0x6E0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(0x50u)) goto label_00060276;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ebp += 0x50u;
    cpu->edi += 0x16u;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x1900u)) goto label_00060270;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    label_00060355: cpu->eip = LIFT_CODE_TOKEN_VA(0x460355u);
    cpu->ebx = 0u;
    label_00060360: cpu->eip = LIFT_CODE_TOKEN_VA(0x460360u);
    cpu->esi = 0u;
    cpu->edi = 0u;
    label_00060364: cpu->eip = LIFT_CODE_TOKEN_VA(0x460364u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_recovered_static_runtime.font_renderer_state), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0006043F;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006037E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6037Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006037E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46037Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00060392;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60392u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00060392: cpu->eip = LIFT_CODE_TOKEN_VA(0x460392u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->edx = (uint32_t)(cpu->ebx + cpu->ebp);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16u);
    cpu->edx += ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->eax = (uint32_t)(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4603A9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4603AFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000603BF;
    ++cpu->esi;
    cpu->edi += 0x6CCu;
    goto label_00060364;
    label_000603BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4603BFu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000603CD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x603CDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000603CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4603CDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_000603E1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x603E1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000603E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4603E1u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x6CCu);
    cpu->esi += g_sfera_landscape_runtime.file_records.data;
    cpu->eax = (uint32_t)(cpu->ebx + cpu->ebp);
    ++cpu->ebx;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]), cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x50u)) goto label_00060360;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ebp += 0x50u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x1900u)) goto label_00060355;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape\\map.bin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46041Eu); lift_push32(cpu, r); sfera_sub_0042EE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x22600u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460431u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    sfera_sub_0042F180(cpu, stop_address); return;
    label_0006043F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46043Fu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx += cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16u);
    cpu->edx += ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->ecx = (uint32_t)(uintptr_t)"Patch present in map, but not found in \\landscape. Name: ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46045Eu); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x46045Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00460460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x460460u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_client_main_scalar_runtime.state_07;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi) * 8u));
    cpu->edi -= cpu->esi;
    ++cpu->esi;
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(((uint32_t)(cpu->edi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[0].id));
    g_sfera_client_main_scalar_runtime.state_07 = (uint32_t)(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(0x1Eu)) goto label_00060490;
    cpu->ecx = (uint32_t)(uintptr_t)"GRASS_PATTERNS_NUM exeeded";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60490u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00060490: cpu->eip = LIFT_CODE_TOKEN_VA(0x460490u);
    cpu->esi = (uint32_t)(cpu->edi + 4u);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->esi -= cpu->eax;
    label_00060497: cpu->eip = LIFT_CODE_TOKEN_VA(0x460497u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00060497;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->edi + 9u);
    cpu->edx -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000604B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4604B0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000604B0;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->edi + 0xEu);
    cpu->edx -= cpu->eax;
    label_000604C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4604C3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000604C3;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->edi + 0x13u);
    cpu->edx -= cpu->eax;
    label_000604D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4604D6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000604D6;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->edi + 0x18u);
    cpu->edx -= cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000604F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4604F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000604F0;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->edi + 0x1Du);
    cpu->edx -= cpu->eax;
    label_00060503: cpu->eip = LIFT_CODE_TOKEN_VA(0x460503u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00060503;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->edi + 0x22u);
    cpu->edx -= cpu->eax;
    label_00060516: cpu->eip = LIFT_CODE_TOKEN_VA(0x460516u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00060516;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = (uint32_t)(cpu->edi + 0x27u);
    cpu->edx -= cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00060530: cpu->eip = LIFT_CODE_TOKEN_VA(0x460530u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00060530;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->edi + 0x2Cu);
    cpu->edx -= cpu->eax;
    label_00060543: cpu->eip = LIFT_CODE_TOKEN_VA(0x460543u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00060543;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->edi + 0x31u);
    cpu->edx -= cpu->eax;
    label_00060556: cpu->eip = LIFT_CODE_TOKEN_VA(0x460556u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00060556;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00460570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x460570u);
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"014"); lift_push32(cpu, (uintptr_t)"014"); lift_push32(cpu, (uintptr_t)"002");
    lift_push32(cpu, (uint32_t)(uintptr_t)"002");
    cpu->edx = (uint32_t)(uintptr_t)"002";
    cpu->ecx = 1u;
    g_sfera_client_main_scalar_runtime.state_07 = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4605B6u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_31"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"003"); lift_push32(cpu, (uintptr_t)"006"); lift_push32(cpu, (uintptr_t)"018");
    lift_push32(cpu, (uint32_t)(uintptr_t)"018");
    cpu->edx = (uint32_t)(uintptr_t)"018";
    cpu->ecx = 2u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4605F2u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_61"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"009"); lift_push32(cpu, (uintptr_t)"003");
    lift_push32(cpu, (uint32_t)(uintptr_t)"003");
    cpu->edx = (uint32_t)(uintptr_t)"003";
    cpu->ecx = 3u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46062Eu); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"002"); lift_push32(cpu, (uintptr_t)"002");
    lift_push32(cpu, (uint32_t)(uintptr_t)"010");
    cpu->edx = (uint32_t)(uintptr_t)"010";
    cpu->ecx = 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46066Au); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"009");
    lift_push32(cpu, (uint32_t)(uintptr_t)"009");
    cpu->edx = (uint32_t)(uintptr_t)"009";
    cpu->ecx = 5u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4606A6u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_31"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"011"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"016");
    lift_push32(cpu, (uint32_t)(uintptr_t)"016");
    cpu->edx = (uint32_t)(uintptr_t)"016";
    cpu->ecx = 6u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4606E2u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_51"); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"007");
    lift_push32(cpu, (uint32_t)(uintptr_t)"014");
    cpu->edx = (uint32_t)(uintptr_t)"014";
    cpu->ecx = 7u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46071Eu); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"013");
    lift_push32(cpu, (uint32_t)(uintptr_t)"013");
    cpu->edx = (uint32_t)(uintptr_t)"013";
    cpu->ecx = 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46075Au); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"013"); lift_push32(cpu, (uintptr_t)"003"); lift_push32(cpu, (uintptr_t)"003");
    lift_push32(cpu, (uint32_t)(uintptr_t)"007");
    cpu->edx = (uint32_t)(uintptr_t)"007";
    cpu->ecx = 9u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460796u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_31"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"003"); lift_push32(cpu, (uintptr_t)"009"); lift_push32(cpu, (uintptr_t)"009");
    lift_push32(cpu, (uint32_t)(uintptr_t)"002");
    cpu->edx = (uint32_t)(uintptr_t)"002";
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4607D2u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"013"); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"005");
    lift_push32(cpu, (uint32_t)(uintptr_t)"012");
    cpu->edx = (uint32_t)(uintptr_t)"012";
    cpu->ecx = 0xBu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46080Eu); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_61"); lift_push32(cpu, (uintptr_t)"009"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"012");
    lift_push32(cpu, (uint32_t)(uintptr_t)"012");
    cpu->edx = (uint32_t)(uintptr_t)"012";
    cpu->ecx = 0xCu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46084Au); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_51"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"015"); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"007");
    lift_push32(cpu, (uint32_t)(uintptr_t)"007");
    cpu->edx = (uint32_t)(uintptr_t)"007";
    cpu->ecx = 0xDu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460886u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"017");
    lift_push32(cpu, (uint32_t)(uintptr_t)"017");
    cpu->edx = (uint32_t)(uintptr_t)"017";
    cpu->ecx = 0xEu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4608C2u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"001"); lift_push32(cpu, (uintptr_t)"001");
    lift_push32(cpu, (uint32_t)(uintptr_t)"001");
    cpu->edx = (uint32_t)(uintptr_t)"001";
    cpu->ecx = 0xFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4608FEu); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000");
    lift_push32(cpu, (uint32_t)(uintptr_t)"000");
    cpu->edx = (uint32_t)(uintptr_t)"000";
    cpu->ecx = 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46093Au); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000");
    lift_push32(cpu, (uint32_t)(uintptr_t)"000");
    cpu->edx = (uint32_t)(uintptr_t)"000";
    cpu->ecx = 0x11u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460976u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000");
    lift_push32(cpu, (uint32_t)(uintptr_t)"000");
    cpu->edx = (uint32_t)(uintptr_t)"000";
    cpu->ecx = 0x12u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4609B2u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uint32_t)(uintptr_t)"101");
    cpu->edx = (uint32_t)(uintptr_t)"101";
    cpu->ecx = 0x13u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4609EEu); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102");
    lift_push32(cpu, (uint32_t)(uintptr_t)"102");
    cpu->edx = (uint32_t)(uintptr_t)"102";
    cpu->ecx = 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460A2Au); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uint32_t)(uintptr_t)"100");
    cpu->edx = (uint32_t)(uintptr_t)"100";
    cpu->ecx = 0x15u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460A66u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uint32_t)(uintptr_t)"101");
    cpu->edx = (uint32_t)(uintptr_t)"101";
    cpu->ecx = 0x16u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460AA2u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uint32_t)(uintptr_t)"100");
    cpu->edx = (uint32_t)(uintptr_t)"100";
    cpu->ecx = 0x17u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460ADEu); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uint32_t)(uintptr_t)"100");
    cpu->edx = (uint32_t)(uintptr_t)"100";
    cpu->ecx = 0x18u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460B1Au); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uint32_t)(uintptr_t)"100");
    cpu->edx = (uint32_t)(uintptr_t)"100";
    cpu->ecx = 0x19u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460B56u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uint32_t)(uintptr_t)"101");
    cpu->edx = (uint32_t)(uintptr_t)"101";
    cpu->ecx = 0x1Au;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460B92u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102");
    lift_push32(cpu, (uint32_t)(uintptr_t)"102");
    cpu->edx = (uint32_t)(uintptr_t)"102";
    cpu->ecx = 0x1Bu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460BCEu); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uint32_t)(uintptr_t)"100");
    cpu->edx = (uint32_t)(uintptr_t)"100";
    cpu->ecx = 0x1Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460C0Au); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uint32_t)(uintptr_t)"101");
    cpu->edx = (uint32_t)(uintptr_t)"101";
    cpu->ecx = 0x1Du;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460C46u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uint32_t)(uintptr_t)"100");
    cpu->edx = (uint32_t)(uintptr_t)"100";
    cpu->ecx = 0x1Eu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460C82u); lift_push32(cpu, r); sfera_sub_00460460(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00460C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x460C90u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00060CB8;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60CB8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00060CB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x460CB8u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00060CCC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60CCCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00060CCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x460CCCu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_00060CFE;
    label_00060CD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x460CD8u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x144u)) < (int32_t)(uint32_t)(0u)) goto label_00060CE7;
    lift_store32(cpu->esi + 0x144u, cpu->edi);
    label_00060CE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x460CE7u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_00060CFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x460CFEu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_00060CD8;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460D16u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00060D1F;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00060D1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x460D1Fu);
    lift_push32(cpu, 0x45DDu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x460D34u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x460D3Au);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460D46u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x460D46u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00460D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x460D50u);
    cpu->esp -= 0xA8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx = 1u;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00060D81;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60D81u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00060D81: cpu->eip = LIFT_CODE_TOKEN_VA(0x460D81u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_recovered_static_runtime.flare_clip_vector.x.u32;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    cpu->ecx = g_sfera_recovered_static_runtime.flare_clip_vector.y.u32;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    cpu->edx = g_sfera_recovered_static_runtime.flare_clip_vector.z.u32;
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x38u, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.10000000149011612));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00060DED;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60DEDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00060DED: cpu->eip = LIFT_CODE_TOKEN_VA(0x460DEDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00060E01;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x60E01u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00060E01: cpu->eip = LIFT_CODE_TOKEN_VA(0x460E01u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ebx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460E1Cu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx += 0x3Cu;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x6Cu)) == (uint32_t)(3u)) goto label_00061148;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(1u)) goto label_00060E45;
    if ((uint32_t)(lift_load32(cpu->eax + 0x184u)) != (uint32_t)(0u)) goto label_00061148;
    label_00060E45: cpu->eip = LIFT_CODE_TOKEN_VA(0x460E45u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460E4Cu); lift_push32(cpu, r); sfera_sub_0045DA60(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    lift_store32(cpu->esp + 0x4Cu, cpu->edx);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00060ED1;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x40u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x44u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x48u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x4Cu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x50u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x54u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00060FDF;
    label_00060ED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x460ED1u);
    lift_x87_push(cpu, 0.0);
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32, lift_x87_get(cpu, 0u));
    cpu->edi &= 0xFFFFFFF0u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0x10u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x188u));
    cpu->esi = cpu->ebx;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18Cu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x190u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_movs32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460F2Au); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ebp + 0x148u);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460F4Fu); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460F70u); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->ebp + 0x148u);
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460F95u); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460FB6u); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->ebp + 0x148u);
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460FDBu); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x38u);
    label_00060FDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x460FDFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x460FF1u); lift_push32(cpu, r); sfera_sub_0044F740(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00061148;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x6Cu)) == (uint32_t)(2u)) goto label_00061006;
    label_00060FFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x460FFFu);
    cpu->eax = 0u;
    goto label_0006114D;
    label_00061006: cpu->eip = LIFT_CODE_TOKEN_VA(0x461006u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461053u); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461074u); lift_push32(cpu, r); sfera_sub_0044B5A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x19Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x54u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00061148;
    cpu->eax = lift_load32(cpu->ebp + 0x1A0u);
    cpu->eax += 8u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_00061096: cpu->eip = LIFT_CODE_TOKEN_VA(0x461096u);
    cpu->ebx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0006112C;
    cpu->edx = lift_load32(cpu->ebp + 0x1A4u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx += cpu->ecx;
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 0x40u);
    label_000610B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4610B4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFFCu));
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4610E8u); lift_push32(cpu, r); sfera_sub_00451A40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00061120;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFD8u);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFE4u);
    lift_store32(cpu->esp + 0x50u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFF0u);
    lift_push32(cpu, 3u);
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461118u); lift_push32(cpu, r); sfera_sub_00451B40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00060FFF;
    label_00061120: cpu->eip = LIFT_CODE_TOKEN_VA(0x461120u);
    ++cpu->edi;
    cpu->esi += 0x50u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000610B4;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_0006112C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46112Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    ++cpu->ecx;
    cpu->eax += 0xCu;
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x19Cu))) goto label_00061096;
    label_00061148: cpu->eip = LIFT_CODE_TOKEN_VA(0x461148u);
    cpu->eax = 1u;
    label_0006114D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46114Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xA8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00461170(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x461170u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"wrong format of planting.txt\n";
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_movs16(cpu, 0u);
    cpu->eax = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->edi = cpu->edi;
    label_00061190: cpu->eip = LIFT_CODE_TOKEN_VA(0x461190u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00061190;
    cpu->ecx -= cpu->esi;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    cpu->ebx = cpu->ecx;
    --cpu->edi;
    label_000611A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4611A1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000611A1;
    cpu->ecx = cpu->ebx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    --cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000611C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4611C0u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000611C0;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x202C)) & 0xFFFFu);
    lift_store16(cpu->ecx, cpu->edx & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store8(cpu->ecx + 2u, cpu->edx & 0xFFu);
    cpu->ecx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000611E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4611E0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000611E0;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000611F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4611F1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000611F1;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461211u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_trap(cpu, 0x461214u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00461220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x461220u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461259u); lift_push32(cpu, r); sfera_sub_00480380(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"landscape\\planting.txt");
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46126Fu); lift_push32(cpu, r); sfera_sub_004803B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32((uintptr_t)"a00_00");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"a00_00") + 4u)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"a00_00") + 6u)) & 0xFFu);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)&g_sfera_planting_table_runtime.records[0].descriptor);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_push32(cpu, (uint32_t)(uintptr_t)"d");
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store16(cpu->esp + 0x24u, cpu->ecx & 0xFFFFu);
    lift_store32(cpu->esp + 0x1Cu, 0x303061u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store8(cpu->esp + 0x2Au, cpu->edx & 0xFFu);
    g_sfera_window_runtime.input_state = (uint32_t)(0u);
    lift_store16(cpu->esp + 0x25u, 0x3030u);
    lift_store16(cpu->esp + 0x21u, 0x3030u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4612C8u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00061466;
    label_000612D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4612D0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00061494;
    cpu->ecx = g_sfera_window_runtime.input_state;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x468u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].name[0]);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"n");
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebx = 0u;
    lift_store16(cpu->esp + 0x28u, 0x3030u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461309u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000613EC;
    cpu->esi = 0u;
    label_00061313: cpu->eip = LIFT_CODE_TOKEN_VA(0x461313u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000614A2;
    cpu->eax = g_sfera_window_runtime.input_state;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x468u);
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].value));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"v");
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461344u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000614B0;
    cpu->eax = g_sfera_window_runtime.input_state;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x468u);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].radius));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"r");
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461375u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000614BE;
    cpu->esi += 0x1Cu;
    ++cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x460u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000614CC;
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->eax + 0x30u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = g_sfera_window_runtime.input_state;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x468u);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->ebx & 0xFFu)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, 1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].name[0]));
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0x21u, cpu->ecx & 0xFFu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"n");
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4613E4u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00061313;
    label_000613EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4613ECu);
    cpu->ecx = g_sfera_window_runtime.input_state;
    cpu->edx = cpu->ecx;
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x468u); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    lift_store32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_planting_table_runtime.records[0].count), cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + 0x30u);
    lift_store8(cpu->esp + 0x15u, cpu->edx & 0xFFu);
    lift_store8(cpu->esp + 0x11u, cpu->edx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    g_sfera_window_runtime.input_state = (uint32_t)(cpu->ecx);
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x468u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_planting_table_runtime.records[0].descriptor);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0x1Eu, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x1Au, cpu->eax & 0xFFu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"d");
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46145Eu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000612D0;
    label_00061466: cpu->eip = LIFT_CODE_TOKEN_VA(0x461466u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461477u); lift_push32(cpu, r); sfera_sub_00480390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00061494: cpu->eip = LIFT_CODE_TOKEN_VA(0x461494u);
    cpu->edx = (uint32_t)(uintptr_t)"d";
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x614A2u); lift_push32(cpu, r); sfera_sub_00461170(cpu,r); if (cpu->eip != r) return; }
    label_000614A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4614A2u);
    cpu->edx = (uint32_t)(uintptr_t)"n";
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x614B0u); lift_push32(cpu, r); sfera_sub_00461170(cpu,r); if (cpu->eip != r) return; }
    label_000614B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4614B0u);
    cpu->edx = (uint32_t)(uintptr_t)"v";
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x614BEu); lift_push32(cpu, r); sfera_sub_00461170(cpu,r); if (cpu->eip != r) return; }
    label_000614BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4614BEu);
    cpu->edx = (uint32_t)(uintptr_t)"r";
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x614CCu); lift_push32(cpu, r); sfera_sub_00461170(cpu,r); if (cpu->eip != r) return; }
    label_000614CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4614CCu);
    cpu->ecx = (uint32_t)(uintptr_t)"MAX_OBJS_IN_PATTERN exceeded";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4614D6u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4614D6u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004614E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4614E0u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00061506;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61506u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00061506: cpu->eip = LIFT_CODE_TOKEN_VA(0x461506u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0006151A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6151Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006151A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46151Au);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0006152A;
    cpu->edi = 0u;
    goto label_00061574;
    label_0006152A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46152Au);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_00061572;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461542u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006154B;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0006154B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46154Bu);
    lift_push32(cpu, 0x47EFu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x461560u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x461566u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61572u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00061572: cpu->eip = LIFT_CODE_TOKEN_VA(0x461572u);
    cpu->edi = cpu->esi;
    label_00061574: cpu->eip = LIFT_CODE_TOKEN_VA(0x461574u);
    cpu->esi = lift_load32(cpu->edi + 0x13Cu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000615BD;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006158D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6158Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006158D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46158Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_000615A1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x615A1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000615A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4615A1u);
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), 0u);
    lift_store32(cpu->edi + 0x13Cu, 0xFFFFFFFFu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_count, (uint64_t)(g_sfera_world_objects.extended_object_count) - 1u);
    label_000615BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4615BDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004615E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4615E0u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00061606;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61606u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00061606: cpu->eip = LIFT_CODE_TOKEN_VA(0x461606u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0006161A;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6161Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006161A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46161Au);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006162A;
    cpu->ebx = 0u;
    goto label_00061674;
    label_0006162A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46162Au);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_00061672;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461642u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006164B;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0006164B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46164Bu);
    lift_push32(cpu, 0x47FDu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x461660u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x461666u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61672u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00061672: cpu->eip = LIFT_CODE_TOKEN_VA(0x461672u);
    cpu->ebx = cpu->eax;
    label_00061674: cpu->eip = LIFT_CODE_TOKEN_VA(0x461674u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x13Cu)) != (uint32_t)(0xFFFFFFFFu)) goto label_000616E8;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_00061680: cpu->eip = LIFT_CODE_TOKEN_VA(0x461680u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006168E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6168Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006168E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46168Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_000616A2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x616A2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000616A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4616A2u);
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_000616B0;
    ++cpu->esi;
    goto label_00061680;
    label_000616B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4616B0u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000616BE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x616BEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000616BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4616BEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_000616D2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x616D2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000616D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4616D2u);
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->edi);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_count, (uint64_t)(g_sfera_world_objects.extended_object_count) + 1u);
    lift_store32(cpu->ebx + 0x13Cu, cpu->esi);
    cpu->esi = lift_pop32(cpu);
    label_000616E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4616E8u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00461700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x461700u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_accumulator, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_accumulator)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->ecx = g_sfera_world_load_runtime.loading_work_total;
    cpu->ecx += 0xFFFFFFB0u;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(1u)) goto label_00061719;
    cpu->ecx = 1u;
    label_00061719: cpu->eip = LIFT_CODE_TOKEN_VA(0x461719u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_accumulator;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(0x64u)) goto label_00061731;
    cpu->esi = 0x64u;
    label_00061731: cpu->eip = LIFT_CODE_TOKEN_VA(0x461731u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(g_sfera_graphics_runtime.rebuild_percent)) goto label_0006179E;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    g_sfera_graphics_runtime.rebuild_percent = (uint32_t)(cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46174Au); lift_push32(cpu, r); sfera_sub_004DA310(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0006179E;
    cpu->ecx = cpu->esi;
    g_sfera_world_render_runtime.scene_active = (uint32_t)(1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46175Fu); lift_push32(cpu, r); sfera_sub_004BBE80(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46176Cu); lift_push32(cpu, r); sfera_sub_004BAFB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461771u); lift_push32(cpu, r); sfera_sub_0045E560(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46177Cu); lift_push32(cpu, r); sfera_sub_004D8840(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461781u); lift_push32(cpu, r); sfera_sub_0044E020(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    g_sfera_world_render_runtime.scene_active = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6179Eu); lift_push32(cpu, r); sfera_sub_004D8880(cpu,r); if (cpu->eip != r) return; }
    label_0006179E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46179Eu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004617A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4617A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4617CBu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    cpu->edi = 1u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000617FC;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x15u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4617FAu); lift_push32(cpu, r); sfera_sub_004DA880(cpu,r); if (cpu->eip != r) return; }
    goto label_000617FE;
    label_000617FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4617FCu);
    cpu->eax = 0u;
    label_000617FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4617FEu);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    g_sfera_render_sample_runtime.active_record = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00061819;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateTexture for water reflection failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61819u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00061819: cpu->eip = LIFT_CODE_TOKEN_VA(0x461819u);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0006182D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6182Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006182D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46182Du);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->eax + 0x18u, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061849;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61849u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061849: cpu->eip = LIFT_CODE_TOKEN_VA(0x461849u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->ecx + 0x1Cu, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061866;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61866u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061866: cpu->eip = LIFT_CODE_TOKEN_VA(0x461866u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp"));
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061889;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61889u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061889: cpu->eip = LIFT_CODE_TOKEN_VA(0x461889u);
    lift_x87_push(cpu, (double)0.4000000059604645f);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->eax + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_000618AB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x618ABu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000618AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4618ABu);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->ecx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_000618CE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x618CEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000618CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4618CEu);
    lift_x87_push(cpu, (double)0.11999999731779099f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 2u;
    lift_store_f32(cpu->edx + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_000618F6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x618F6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000618F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4618F6u);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->eax + 0x30u, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061912;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61912u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061912: cpu->eip = LIFT_CODE_TOKEN_VA(0x461912u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->ecx + 0x34u, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_0006192F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6192Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006192F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46192Fu);
    lift_x87_push(cpu, (double)0.6000000238418579f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061952;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61952u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061952: cpu->eip = LIFT_CODE_TOKEN_VA(0x461952u);
    lift_x87_push(cpu, (double)0.20000000298023224f);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->eax + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061974;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61974u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061974: cpu->eip = LIFT_CODE_TOKEN_VA(0x461974u);
    lift_x87_push(cpu, (double)0.20000000298023224f);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->ecx + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061997;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61997u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061997: cpu->eip = LIFT_CODE_TOKEN_VA(0x461997u);
    lift_x87_push(cpu, (double)0.019999999552965164f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ebx = 3u;
    lift_store_f32(cpu->edx + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_000619BF;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x619BFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000619BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4619BFu);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->eax + 0x48u, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_000619DB;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x619DBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000619DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4619DBu);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->ecx + 0x4Cu, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_000619F8;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x619F8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000619F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4619F8u);
    lift_x87_push(cpu, (double)0.6000000238418579f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_00061A1B;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61A1Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061A1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x461A1Bu);
    lift_x87_push(cpu, (double)0.33000001311302185f);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->eax + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_00061A3D;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61A3Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061A3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x461A3Du);
    lift_x87_push(cpu, (double)0.23000000417232513f);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->ecx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_00061A60;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61A60u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061A60: cpu->eip = LIFT_CODE_TOKEN_VA(0x461A60u);
    lift_x87_push(cpu, (double)0.07999999821186066f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->edi = 4u;
    lift_store_f32(cpu->edx + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061A88;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61A88u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061A88: cpu->eip = LIFT_CODE_TOKEN_VA(0x461A88u);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->eax + 0x60u, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061AA4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61AA4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061AA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x461AA4u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->ecx + 0x64u, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061AC1;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61AC1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061AC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x461AC1u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp"));
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061AE4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61AE4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061AE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x461AE4u);
    lift_x87_push(cpu, (double)0.3499999940395355f);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->eax + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061B06;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61B06u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061B06: cpu->eip = LIFT_CODE_TOKEN_VA(0x461B06u);
    lift_x87_push(cpu, (double)0.20000000298023224f);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->ecx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_00061B29;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61B29u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061B29: cpu->eip = LIFT_CODE_TOKEN_VA(0x461B29u);
    lift_x87_push(cpu, (double)0.05999999865889549f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 5u;
    lift_store_f32(cpu->edx + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061B51;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61B51u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061B51: cpu->eip = LIFT_CODE_TOKEN_VA(0x461B51u);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->eax + 0x78u, cpu->ebx);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061B6D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61B6Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061B6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x461B6Du);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->ecx + 0x7Cu, cpu->ebx);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061B8A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61B8Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061B8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x461B8Au);
    lift_x87_push(cpu, (double)0.800000011920929f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061BB0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61BB0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x461BB0u);
    lift_x87_push(cpu, (double)0.5f);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->eax + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061BD5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61BD5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061BD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x461BD5u);
    lift_x87_push(cpu, (double)0.10000000149011612f);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->ecx + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061BFB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61BFBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061BFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x461BFBu);
    lift_x87_push(cpu, (double)0.07999999821186066f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 6u;
    lift_store_f32(cpu->edx + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061C26;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61C26u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061C26: cpu->eip = LIFT_CODE_TOKEN_VA(0x461C26u);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->eax + 0x90u, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061C45;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61C45u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061C45: cpu->eip = LIFT_CODE_TOKEN_VA(0x461C45u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->ecx + 0x94u, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061C65;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61C65u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061C65: cpu->eip = LIFT_CODE_TOKEN_VA(0x461C65u);
    lift_x87_push(cpu, 1.0);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061C87;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61C87u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061C87: cpu->eip = LIFT_CODE_TOKEN_VA(0x461C87u);
    lift_x87_push(cpu, (double)0.44999998807907104f);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061CAC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61CACu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061CAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x461CACu);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->ecx + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061CCE;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61CCEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061CCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x461CCEu);
    lift_x87_push(cpu, (double)0.03999999910593033f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 7u;
    lift_store_f32(cpu->edx + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061CF9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61CF9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061CF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x461CF9u);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->eax + 0xA8u, cpu->ebx);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061D18;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61D18u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061D18: cpu->eip = LIFT_CODE_TOKEN_VA(0x461D18u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store32(cpu->ecx + 0xACu, cpu->ebx);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061D38;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61D38u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061D38: cpu->eip = LIFT_CODE_TOKEN_VA(0x461D38u);
    lift_x87_push(cpu, (double)0.6000000238418579f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061D5E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61D5Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061D5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x461D5Eu);
    lift_x87_push(cpu, (double)0.4000000059604645f);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->eax + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061D83;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61D83u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061D83: cpu->eip = LIFT_CODE_TOKEN_VA(0x461D83u);
    lift_x87_push(cpu, (double)0.10000000149011612f);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->ecx + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00061DA9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61DA9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061DA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x461DA9u);
    lift_x87_push(cpu, (double)0.03999999910593033f);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->edx + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00461DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x461DD0u);
    cpu->esp -= 0x424u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461DF8u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461DFFu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)"trap";
    cpu->ecx = cpu->esi;
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461E0Du); lift_push32(cpu, r); sfera_sub_0044CB00(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00061F47;
    cpu->ecx = cpu->ebx;
    cpu->ecx -= g_sfera_model_material_lookup_runtime.refresh_tick;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0x2710u)) goto label_00061F47;
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00061F41;
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00061E47;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61E47u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00061E47: cpu->eip = LIFT_CODE_TOKEN_VA(0x461E47u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00061E5B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61E5Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061E5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x461E5Bu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00061E93;
    label_00061E68: cpu->eip = LIFT_CODE_TOKEN_VA(0x461E68u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x18Cu)) == (uint32_t)(0u)) goto label_00061F41;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->edi + 0x10Cu);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00061E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x461E80u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(0xFFFFFFFFu)) goto label_00061EDB;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xAu)) goto label_00061E80;
    goto label_00061F41;
    label_00061E93: cpu->eip = LIFT_CODE_TOKEN_VA(0x461E93u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_00061E68;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461EABu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00061EB4;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00061EB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x461EB4u);
    lift_push32(cpu, 0x4A1Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x461EC9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x461ECFu);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61EDBu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00061EDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x461EDBu);
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x10Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461EE7u); lift_push32(cpu, r); sfera_sub_00425BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"trap %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x61EFAu), LIFT_CODE_TOKEN_RVA(0x61EF8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x461EFAu);
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    cpu->esp += 0xCu;
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00061F12;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61F12u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00061F12: cpu->eip = LIFT_CODE_TOKEN_VA(0x461F12u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00061F26;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61F26u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00061F26: cpu->eip = LIFT_CODE_TOKEN_VA(0x461F26u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00061F5F;
    label_00061F32: cpu->eip = LIFT_CODE_TOKEN_VA(0x461F32u);
    cpu->ecx = lift_load32(cpu->eax + 0x18Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x61F41u); lift_push32(cpu, r); sfera_sub_00437FF0(cpu,r); if (cpu->eip != r) return; }
    label_00061F41: cpu->eip = LIFT_CODE_TOKEN_VA(0x461F41u);
    g_sfera_model_material_lookup_runtime.refresh_tick = (uint32_t)(cpu->ebx);
    label_00061F47: cpu->eip = LIFT_CODE_TOKEN_VA(0x461F47u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x424u;
    lift_return(cpu, 0u, stop_address); return;
    label_00061F5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x461F5Fu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_00061F32;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461F77u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00061F80;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00061F80: cpu->eip = LIFT_CODE_TOKEN_VA(0x461F80u);
    lift_push32(cpu, 0x4A25u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x61F97u), LIFT_CODE_TOKEN_RVA(0x61F95u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x461F97u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x461FA3u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x461FA3u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00461FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x461FD0u);
    cpu->esp -= 0x34u;
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_shadow_runtime.manager;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xA0u)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->edi = cpu->edx;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000623A0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x148u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.9900000095367432);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000623A0;
    lift_x87_push(cpu, (double)50.0f);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = 0u;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_03) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000621CB;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][4];
    label_00062041: cpu->eip = LIFT_CODE_TOKEN_VA(0x462041u);
    if ((uint32_t)(lift_load32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_active[0]))) == (uint32_t)(0u)) goto label_00062105;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00062105;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFFCu));
    cpu->ebp = (uint32_t)(cpu->esi + 0xFFFFFFFCu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 8u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x10u))));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4620AAu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00062103;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00062103;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00062103;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    goto label_00062105;
    label_00062103: cpu->eip = LIFT_CODE_TOKEN_VA(0x462103u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00062105: cpu->eip = LIFT_CODE_TOKEN_VA(0x462105u);
    ++cpu->ebx;
    cpu->esi += 0x3Cu;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_03)) goto label_00062041;
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000621C7;
    { uint64_t l=(uint64_t)(g_sfera_view_spatial_runtime.alternate_projection), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (15.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000621AD;
    lift_x87_push(cpu, (double)0.25f);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_000621AB;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.8299999833106995);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000621AD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_scale));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000621AB;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000621AD;
    label_000621AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4621ABu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000621AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4621ADu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4621C5u); lift_push32(cpu, r); sfera_sub_0048C860(cpu,r); if (cpu->eip != r) return; }
    goto label_000621CB;
    label_000621C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4621C7u);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    label_000621CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4621CBu);
    { uint64_t l=(uint64_t)(g_sfera_view_spatial_runtime.alternate_projection), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, 1.0);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000621FA;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000621FA;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->ebp;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4621F8u); lift_push32(cpu, r); sfera_sub_0048C860(cpu,r); if (cpu->eip != r) return; }
    goto label_000621FC;
    label_000621FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4621FAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000621FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4621FCu);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(1u)) goto label_00062214;
    cpu->edx = (uint32_t)(cpu->esi + 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62214u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00062214: cpu->eip = LIFT_CODE_TOKEN_VA(0x462214u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 8u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x10u))));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462263u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 15.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10.0));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000622A0;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000622B7;
    label_000622A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4622A0u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000622B5;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000622B7;
    label_000622B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4622B5u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000622B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4622B7u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 7.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000622CD;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = 2u;
    goto label_000622DF;
    label_000622CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4622CDu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)5.0f));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000622DF;
    cpu->esi = 1u;
    label_000622DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4622DFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4622E8u); lift_push32(cpu, r); sfera_sub_0045DA60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xB0u);
    cpu->eax = lift_load32(cpu->ebp + 0xB4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xACu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp"));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x1Cu)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006232F;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00062331;
    label_0006232F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46232Fu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00062331: cpu->eip = LIFT_CODE_TOKEN_VA(0x462331u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46233Au); lift_push32(cpu, r); sfera_sub_004EED5A(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462347u); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x8Cu));
    cpu->esp -= 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x80u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_x87_set(cpu, 0u, (1.4900000095367432) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46239Eu); lift_push32(cpu, r); sfera_sub_0048CE10(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000623A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4623A0u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004623C0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4623C0u);
    cpu->esp -= 0x404u;
    cpu->ecx = lift_load32(cpu->esp + 0x408u);
    cpu->eax = (uint32_t)(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x4623E9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4623EFu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4623FAu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4623FAu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00462400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462400u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0006254E;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000624E8;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x10u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000624C2;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000624A1;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xBu), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00062565;
    if ((uint32_t)(g_sfera_window_runtime.windowed) == (uint32_t)(cpu->eax)) goto label_00062466;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_23)) == (uint32_t)(cpu->eax)) goto label_00062466;
    g_sfera_texture_cache_runtime.cache_enabled = (uint32_t)(1u);
    goto label_0006246F;
    label_00062466: cpu->eip = LIFT_CODE_TOKEN_VA(0x462466u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    g_sfera_texture_cache_runtime.cache_enabled = (uint32_t)(cpu->eax);
    label_0006246F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46246Fu);
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x46246Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x462474u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46247Bu); lift_push32(cpu, r); sfera_sub_004982F0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.scalar_01, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10) = (uint32_t)(1u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_000624A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4624A1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4624A6u); lift_push32(cpu, r); sfera_sub_004595F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::PostQuitMessage), LIFT_CODE_TOKEN_VA(0x4624A8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4624AEu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_000624C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4624C2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4624C7u); lift_push32(cpu, r); sfera_sub_004595F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4624CCu); lift_push32(cpu, r); sfera_sub_0042EB70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::PostQuitMessage), LIFT_CODE_TOKEN_VA(0x4624CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4624D4u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_000624E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4624E8u);
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_0006251F;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store32(cpu->esp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46250Au); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462514u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, 0xFFFFFFFFu);
    label_0006251F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46251Fu);
    if ((uint32_t)(g_sfera_cursor_manager_runtime.active_cursor) == (uint32_t)(0u)) goto label_00062678;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462531u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->apply(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46253Au);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_0006254E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46254Eu);
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x100u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00062619;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000625D4;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x10u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006258D;
    label_00062565: cpu->eip = LIFT_CODE_TOKEN_VA(0x462565u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::DefWindowProcA), LIFT_CODE_TOKEN_VA(0x462575u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46257Bu);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_0006258D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46258Du);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ecx;
    cpu->eax &= 0xFFF0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xF090u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00062678;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x70u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00062678;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x112u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DefWindowProcA), LIFT_CODE_TOKEN_VA(0x4625BCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4625C2u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_000625D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4625D4u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].defined))) != (uint32_t)(1u)) goto label_00062678;
    cpu->eax = g_sfera_pending_key_runtime.count;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0x1Eu)) goto label_00062678;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_pending_key_runtime.key_codes[0]), cpu->ecx);
    ++cpu->eax;
    g_sfera_pending_key_runtime.count = (uint32_t)(cpu->eax);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_00062619: cpu->eip = LIFT_CODE_TOKEN_VA(0x462619u);
    { uint64_t l=(uint64_t)(g_sfera_client_process_runtime.ui_bridge), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006263F;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state) = (uint32_t)(cpu->eax);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_0006263F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46263Fu);
    { uint64_t l=(uint64_t)(g_sfera_texture_cache_runtime.render_gate), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006265F;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].defined))) == (uint32_t)(0u)) goto label_0006265F;
    if ((uint8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0]))) == (uint8_t)(0u)) goto label_00062678;
    label_0006265F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46265Fu);
    cpu->ecx = g_sfera_scene_control_runtime.context_count;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(0x1Eu)) goto label_00062678;
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.context_queue[0]), cpu->eax);
    ++cpu->ecx;
    g_sfera_scene_control_runtime.context_count = (uint32_t)(cpu->ecx);
    label_00062678: cpu->eip = LIFT_CODE_TOKEN_VA(0x462678u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00462690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462690u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, 0x30u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46269Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4626A1u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x71u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 8u, 0x30u);
    lift_store32(cpu->esp + 0xCu, 3u);
    lift_store32(cpu->esp + 0x10u, LIFT_CALLBACK(sfera_sub_00462400));
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_store32(cpu->esp + 0x18u, 0u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::LoadIconA), LIFT_CODE_TOKEN_VA(0x4626D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4626DEu);
    lift_push32(cpu, 0x7F00u); lift_push32(cpu, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::LoadCursorA), LIFT_CODE_TOKEN_VA(0x4626E9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4626EFu);
    lift_push32(cpu, 4u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetStockObject), LIFT_CODE_TOKEN_VA(0x4626F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4626FBu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, 0u);
    lift_store32(cpu->esp + 0x2Cu, sfera_window_class_name());
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::RegisterClassExA), LIFT_CODE_TOKEN_VA(0x46271Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x462721u);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != 0u) goto label_00062730;
    cpu->ecx = (uint32_t)(uintptr_t)"RegisterClassEx() failed! => init_main_window_class()";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62730u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00062730: cpu->eip = LIFT_CODE_TOKEN_VA(0x462730u);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00462740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462740u);
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46275Bu); lift_push32(cpu, r); sfera_sub_004815D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"Models\\Materials.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462765u); lift_push32(cpu, r); sfera_sub_00482170(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->edx = (uint32_t)(uintptr_t)"materials";
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462777u); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462784u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_main_render_runtime.material_count;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462794u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_main_render_runtime.material_count;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x88u);
    lift_push32(cpu, 0x64Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4627AFu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_main_render_runtime.material_count;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x28Eu);
    lift_push32(cpu, 0x64Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4627CFu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_main_render_runtime.material_count;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x28Eu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4627EAu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4627F1u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((int32_t)(uint32_t)(g_sfera_main_render_runtime.material_count) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00062A39;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->eax -= cpu->edi;
    cpu->ebp = 0u;
    cpu->esi = (uint32_t)(cpu->edi + 0x268u);
    cpu->eax -= 0x28u;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00062820: cpu->eip = LIFT_CODE_TOKEN_VA(0x462820u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFD98u);
    cpu->edx += cpu->ebp;
    cpu->edi = cpu->edi;
    label_00062830: cpu->eip = LIFT_CODE_TOKEN_VA(0x462830u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00062830;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, (uintptr_t)"default"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x462848u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46284Eu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006285B;
    lift_store32((uintptr_t)&g_sfera_direct_input_runtime.acquire_failure_state, cpu->ebx);
    label_0006285B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46285Bu);
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFDBCu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    lift_store32(cpu->eax + cpu->ebp + 0x24u, cpu->edx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + cpu->ebp + 0x68u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebp + 0x68u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    lift_store_f32(cpu->edx + cpu->ebp + 0x78u, lift_x87_get(cpu, 0u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    lift_store_f32(cpu->eax + cpu->ebp + 0x7Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    lift_store_f32(cpu->ecx + cpu->ebp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edx + cpu->ebp + 0x24u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00062932;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->eax -= 2u;
    cpu->esi += 0xFFFFFDC0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->edi = (uint32_t)(cpu->ebp + 0x28u);
    label_000628E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4628E0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_000628E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4628E4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000628E4;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    label_000628F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4628F5u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000628F5;
    cpu->eax -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store8(cpu->ecx + cpu->eax, cpu->edx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46290Eu); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    lift_store32(cpu->edi + cpu->edx, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    ++cpu->ebx;
    cpu->edi += 4u;
    cpu->esi -= 0x24u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + cpu->ebp + 0x24u))) goto label_000628E0;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_00062932: cpu->eip = LIFT_CODE_TOKEN_VA(0x462932u);
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00062A04;
    cpu->edi = cpu->edi;
    label_00062940: cpu->eip = LIFT_CODE_TOKEN_VA(0x462940u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(uintptr_t)"materials";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46294Fu); lift_push32(cpu, r); sfera_sub_00481300(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00062A64;
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"name";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46296Au); lift_push32(cpu, r); sfera_sub_00481180(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062A6F;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x46297Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x462985u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062995;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00062940;
    goto label_00062A04;
    label_00062995: cpu->eip = LIFT_CODE_TOKEN_VA(0x462995u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->eax = (uint32_t)(cpu->edx + cpu->ebp + 0x78u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(uintptr_t)"rgbRand";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4629AEu); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062A04;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebp + 0x7Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(uintptr_t)"rgbRand";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4629CBu); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062A7A;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp + 0x80u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(uintptr_t)"rgbRand";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4629EEu); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062A7A;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    lift_store8(cpu->edx + cpu->ebp + 0x84u, 1u);
    label_00062A04: cpu->eip = LIFT_CODE_TOKEN_VA(0x462A04u);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) - (uint64_t)(0x28Eu) - (uint64_t)(0u));
    ++cpu->ebx;
    cpu->esi += 0x28Eu;
    cpu->ebp += 0x88u;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_main_render_runtime.material_count)) goto label_00062820;
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    label_00062A39: cpu->eip = LIFT_CODE_TOKEN_VA(0x462A39u);
    lift_push32(cpu, 0x67Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462A4Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462A51u); lift_push32(cpu, r); sfera_sub_004815C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
    label_00062A64: cpu->eip = LIFT_CODE_TOKEN_VA(0x462A64u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Can't go into material struct %d");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62A6Fu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    label_00062A6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x462A6Fu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Field name is absent in material %d");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62A7Au); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    label_00062A7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x462A7Au);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Wrong format of rgbRand in material struct %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462A85u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x462A85u, "INT3"); return;
}
