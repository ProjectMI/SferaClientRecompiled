#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044DE30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44DE30u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DE3Du); lift_push32(cpu, r); sfera_sub_004D8DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DE4Au); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DE59u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DE68u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DE77u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x89u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DE89u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DE98u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DEA8u); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DEBBu); lift_push32(cpu, r); sfera_sub_004D9200(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DECEu); lift_push32(cpu, r); sfera_sub_004D9250(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DEDFu); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DEF0u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044DF90(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0004DF90;
    label_0004DF00: cpu->eip = LIFT_CODE_TOKEN_VA(0x44DF00u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF11u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF22u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x89u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF34u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF43u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF52u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF61u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 0x16u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF70u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
    label_0004DF90: cpu->eip = LIFT_CODE_TOKEN_VA(0x44DF90u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DF96u); lift_push32(cpu, r); sfera_sub_0044DE30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DFA5u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DFB4u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DFB9u); lift_push32(cpu, r); sfera_sub_004B9620(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0004DFC8;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x4DFC8u); lift_push32(cpu, r); sfera_sub_004205E0(cpu,r); if (cpu->eip != r) return; }
    label_0004DFC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x44DFC8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DFCDu); lift_push32(cpu, r); sfera_sub_0044D700(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44DFD2u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->eax -= g_sfera_frame_runtime.frame_anchor.low;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_frame_runtime.frame_sample_count, (uint64_t)(g_sfera_frame_runtime.frame_sample_count) + 1u);
    lift_store32(cpu->esp, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3E8u)) goto label_0004E017;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_frame_runtime.frame_sample_count))));
    g_sfera_frame_runtime.frame_sample_count = (uint32_t)(0u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (10000.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(lift_load32(cpu->esp))))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.frame_interval.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E00Cu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    g_sfera_frame_runtime.frame_anchor.low = (uint32_t)(cpu->eax);
    lift_store32((uintptr_t)&g_sfera_frame_runtime.frame_anchor.high, cpu->edx);
    label_0004E017: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E017u);
    cpu->esp += 4u;
    goto label_0004DF00;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E020u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004E08E;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4E033u), LIFT_CODE_TOKEN_RVA(0x4E031u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E033u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x88760868u)) goto label_0004E08E;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4E04Du), LIFT_CODE_TOKEN_RVA(0x4E04Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E04Du);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0004E08E;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4E065u), LIFT_CODE_TOKEN_RVA(0x4E063u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E065u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0004E08E;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::Sleep);
    label_0004E071: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E071u);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4E075u), LIFT_CODE_TOKEN_RVA(0x4E073u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E075u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4E088u), LIFT_CODE_TOKEN_RVA(0x4E086u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E088u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_0004E071;
    cpu->esi = lift_pop32(cpu);
    label_0004E08E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E08Eu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E090u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E0A0u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E0B5u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.projection_scale)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)(*(float*)(void*)&g_sfera_main_view_state_runtime.projection_scale))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.00390625);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.view_phase));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.projection_scale));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_scale)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00390625));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_render_sample_runtime.phase.f32)));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E140u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E150u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E165u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E1B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E1B0u);
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_push32(cpu, cpu->esi);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)g_sfera_recovered_static_runtime.primary_frame_interval));
    lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004E1D5;
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) != (uint8_t)(0u)) goto label_0004E1D5;
    cpu->edi = 1u;
    goto label_0004E1D7;
    label_0004E1D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E1D5u);
    cpu->edi = 0u;
    label_0004E1D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E1D7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E1DCu); lift_push32(cpu, r); sfera_sub_0047F6B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0004E210;
    if ((uint32_t)(g_sfera_frame_runtime.primary_toggle) != (uint32_t)(0u)) goto label_0004E1FC;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E1F2u); lift_push32(cpu, r); sfera_sub_0047F6C0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_frame_runtime.primary_toggle = (uint32_t)(1u);
    label_0004E1FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E1FCu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_frame_interval));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E20Du); lift_push32(cpu, r); sfera_sub_0047FA20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0004E210: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E210u);
    if ((uint32_t)(g_sfera_frame_runtime.primary_toggle) != (uint32_t)(1u)) goto label_0004E22A;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E220u); lift_push32(cpu, r); sfera_sub_0047F6E0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_frame_runtime.primary_toggle = (uint32_t)(0u);
    label_0004E22A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E22Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E230u);
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_push32(cpu, cpu->esi);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)g_sfera_recovered_static_runtime.secondary_frame_interval));
    lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004E255;
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) != (uint8_t)(0u)) goto label_0004E255;
    cpu->edi = 1u;
    goto label_0004E257;
    label_0004E255: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E255u);
    cpu->edi = 0u;
    label_0004E257: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E257u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E25Cu); lift_push32(cpu, r); sfera_sub_0047F6B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0004E290;
    if ((uint32_t)(g_sfera_frame_runtime.secondary_toggle) != (uint32_t)(0u)) goto label_0004E27C;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E272u); lift_push32(cpu, r); sfera_sub_0047F730(cpu,r); if (cpu->eip != r) return; }
    g_sfera_frame_runtime.secondary_toggle = (uint32_t)(1u);
    label_0004E27C: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E27Cu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_frame_interval));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E28Du); lift_push32(cpu, r); sfera_sub_0047F770(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0004E290: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E290u);
    if ((uint32_t)(g_sfera_frame_runtime.secondary_toggle) != (uint32_t)(1u)) goto label_0004E2AA;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E2A0u); lift_push32(cpu, r); sfera_sub_0047F750(cpu,r); if (cpu->eip != r) return; }
    g_sfera_frame_runtime.secondary_toggle = (uint32_t)(0u);
    label_0004E2AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E2AAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E2B0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E2C0u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E2D3u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E2E7u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E2FBu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E30Fu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E323u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_store_f32(cpu->eax + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->eax + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->eax + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f64(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_load_f64(cpu->esp + 8u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_load_f64(cpu->esp + 0x18u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E400u);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004E428;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 8u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_return(cpu, 8u, stop_address); return;
    label_0004E428: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E428u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.4000000059604645);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004E456;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 8u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_return(cpu, 8u, stop_address); return;
    label_0004E456: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E456u);
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 8u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E480u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    lift_store32(cpu->esp + 0x20u, 0xAu);
    label_0004E493: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E493u);
    cpu->esi = cpu->edi;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::v)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->ebp = 0xCu;
    label_0004E4A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E4A3u);
    lift_x87_push(cpu, 255.0);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0])));
    lift_x87_push(cpu, (double)1.059999942779541f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004E4CD;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)255.0f);
    goto label_0004E502;
    label_0004E4CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E4CDu);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0])));
    lift_x87_push(cpu, (double)1.4800000190734863f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004E4EF;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    goto label_0004E502;
    label_0004E4EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E4EFu);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004E502: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E502u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store32(cpu->esp + 0x14u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0])));
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.render_samples[0]), cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E531u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x14u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E554u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x18u))) / (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004E58B;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004E58B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E58Bu);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_samples[0])));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E597u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    lift_store_f32(cpu->esi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_samples[0])));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E5BCu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    ++cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x20u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    lift_store_f32(cpu->esi + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004E4A3;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004E493;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x2Cu, 9u);
    label_0004E600: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E600u);
    cpu->ebx = 0xBu;
    label_0004E610: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E610u);
    cpu->edi = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[1]));
    cpu->edx = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[0]));
    cpu->esi = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[12]));
    cpu->edx += cpu->edi;
    cpu->edx += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0004E651;
    cpu->edx = cpu->ecx & 0xFFFFu;
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[0]), cpu->edx & 0xFFFFu);
    cpu->ebp = (uint32_t)(cpu->edx + 1u);
    cpu->edx += 0xCu;
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[1]), cpu->ebp & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[2]), cpu->edx & 0xFFFFu);
    cpu->eax += 3u;
    label_0004E651: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E651u);
    cpu->edi += cpu->esi;
    cpu->edi += lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[13]));
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0004E685;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->esi = (uint32_t)(cpu->edx + 1u);
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[0]), cpu->esi & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edx + 0xDu);
    cpu->edx += 0xCu;
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[1]), cpu->esi & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[2]), cpu->edx & 0xFFFFu);
    cpu->eax += 3u;
    label_0004E685: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E685u);
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004E610;
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x2Cu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004E600;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E6A0u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->edx;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_font_runtime.renderer;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E6CDu); lift_push32(cpu, r); sfera_sub_00495010(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u) + 0x28u));
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->ecx) * 4u) + 0x28u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x28u))));
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 4u))));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044E720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44E720u);
    cpu->esp -= 0x68u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = g_sfera_world_render_runtime.active_model;
    cpu->esi = cpu->ebp;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xACu);
    cpu->esi += lift_load32(cpu->ecx + 0x3Cu);
    cpu->eax = 2u;
    lift_push32(cpu, cpu->edi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x20u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_0004EAB7;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x38u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004E77D;
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_03;
    cpu->eax = g_sfera_client_main_scalar_runtime.mode_01;
    cpu->edx = 1u;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    lift_store32(((uint32_t)(cpu->ebp) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_render_lookup_runtime.entries[0].resource), cpu->eax);
    --cpu->edx;
    lift_store32(((uint32_t)(cpu->ebp) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_render_lookup_runtime.entries[0].mask), cpu->edx);
    goto label_0004EAB7;
    label_0004E77D: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E77Du);
    lift_push32(cpu, cpu->ebx);
    cpu->edi = (uint32_t)(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->esi + 0x24u);
    lift_store32(cpu->esp + 0x10u, 8u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0004E790: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E790u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->edi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 8u, cpu->edx);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E7ACu); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx += 0xCu;
    cpu->edi += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004E790;
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44E7C8u); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    lift_store32(((uint32_t)(cpu->ebp) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_render_lookup_runtime.entries[0].resource), cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004EAB6;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_render_lookup_runtime.entries[0].mask));
    cpu->ebp = g_sfera_client_main_scalar_runtime.counter_03;
    cpu->eax = 0u;
    cpu->ebx = 0u;
    lift_store32(cpu->edx, 0u);
    cpu->edi = 1u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(4u)) goto label_0004EA1A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][0x30];
    label_0004E805: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E805u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x84u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E87E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x88u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E87E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x8Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E87E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x90u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E87E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x94u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E87E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x98u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E87E;
    lift_store32(cpu->edx, (uint64_t)(lift_load32(cpu->edx)) | (uint64_t)(cpu->edi));
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(7u)) goto label_0004EAB6;
    label_0004E87E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E87Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x84u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E8F8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x3Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x88u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E8F8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x40u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x8Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E8F8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x90u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E8F8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x94u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E8F8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x98u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E8F8;
    lift_store32(cpu->edx, (uint64_t)(lift_load32(cpu->edx)) | (uint64_t)(cpu->edi));
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(7u)) goto label_0004EAB6;
    label_0004E8F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E8F8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x74u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x84u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E972;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x78u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x88u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E972;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x7Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x8Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E972;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x68u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x90u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E972;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x6Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x94u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E972;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x70u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x98u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E972;
    lift_store32(cpu->edx, (uint64_t)(lift_load32(cpu->edx)) | (uint64_t)(cpu->edi));
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(7u)) goto label_0004EAB6;
    label_0004E972: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E972u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xB0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x84u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E9FE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xB4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x88u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E9FE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xB8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x8Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004E9FE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xA4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x90u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E9FE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xA8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x94u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E9FE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xACu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x98u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004E9FE;
    lift_store32(cpu->edx, (uint64_t)(lift_load32(cpu->edx)) | (uint64_t)(cpu->edi));
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(7u)) goto label_0004EAB6;
    label_0004E9FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x44E9FEu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFDu);
    cpu->ecx += 0xF0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_0004E805;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_0004EA1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EA1Au);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004EAB6;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx -= cpu->eax;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][0x30]));
    label_0004EA30: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EA30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x84u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004EAA5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x88u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004EAA5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x8Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004EAA5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x90u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004EAA5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x94u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004EAA5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x98u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004EAA5;
    lift_store32(cpu->edx, (uint64_t)(lift_load32(cpu->edx)) | (uint64_t)(cpu->edi));
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(7u)) goto label_0004EAB6;
    label_0004EAA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EAA5u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx += 0x3Cu;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u)) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0004EA30;
    label_0004EAB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EAB6u);
    cpu->ebx = lift_pop32(cpu);
    label_0004EAB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EAB7u);
    cpu->edi = 0u;
    if ((uint8_t)(lift_load8(cpu->esi + 0x21u)) <= (uint8_t)(0u)) goto label_0004EAE0;
    (void)cpu;
    label_0004EAC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EAC0u);
    cpu->edx = lift_load8(cpu->esi + 0x22u);
    cpu->eax = g_sfera_world_render_runtime.active_model;
    cpu->ecx = lift_load32(cpu->eax + 0x4Cu);
    cpu->ecx += cpu->edx;
    cpu->ecx = lift_load8(cpu->ecx + cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EAD7u); lift_push32(cpu, r); sfera_sub_0044E720(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load8(cpu->esi + 0x21u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->edx)) goto label_0004EAC0;
    label_0004EAE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EAE0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x68u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044EB00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44EB00u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->esp -= 8u;
    lift_x87_push(cpu, 0.20000000298023224);
    lift_push32(cpu, cpu->esi);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0004EB30;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_0004EB30: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EB30u);
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x14u, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004EB4F;
    lift_store32(cpu->esp + 0x14u, 0u);
    label_0004EB4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EB4Fu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004EB7A;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_0004EB7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EB7Au);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (0.019999999552965164));
    lift_store_f64(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EB99u); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_load_f64(cpu->esp + 4u)));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044EBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44EBC0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x3Cu;
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_load_f64(cpu->ebp + 0x10u)));
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store_f64(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    label_0004EBD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EBD9u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_x87_push(cpu, lift_load_f64(cpu->ebp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EBEBu); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_load_f64(cpu->esp + 0x38u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->ebp + 0x10u)));
    lift_x87_push(cpu, 255.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EC01u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004EC25;
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004EC23;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004EC34;
    label_0004EC23: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EC23u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004EC25: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EC25u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004EC32;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004EC34;
    label_0004EC32: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EC32u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004EC34: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EC34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EC45u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store16(cpu->esp + 0x38u, cpu->fpu_control);
    ++cpu->esi;
    cpu->eax = lift_load16(cpu->esp + 0x38u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    cpu->esp += 8u;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x34u));
    lift_store32(cpu->esp + 0x34u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x34u)) & 0xFFu);
    lift_store8((uintptr_t)&g_sfera_static_render_lookup_runtime.color_remap_a[cpu->esi - 1u], cpu->eax & 0xFFu);
    lift_store8((uintptr_t)&g_sfera_static_render_lookup_runtime.color_remap_b[cpu->esi - 1u], cpu->eax & 0xFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store8((uintptr_t)&g_sfera_static_render_lookup_runtime.color_remap_c[cpu->esi - 1u], cpu->eax & 0xFFu);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x100u)) goto label_0004EBD9;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044ECA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44ECA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_frame_runtime.color_lookup_flags)) & (1u)) != 0u) goto label_0004ECEE;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_frame_runtime.color_lookup_flags, (uint64_t)(g_sfera_frame_runtime.color_lookup_flags) | (uint64_t)(1u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_frame_runtime.color_lookup_object[0];
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44ECE6u); lift_push32(cpu, r); sfera_sub_00430BB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    label_0004ECEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x44ECEEu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004ED56;
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) == (uint8_t)(1u)) goto label_0004ED56;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_frame_runtime.color_lookup_object[0];
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->esp + 0x10u, 0x6496C8FFu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44ED1Fu); lift_push32(cpu, r); sfera_sub_004309F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load8(cpu->esp + cpu->eax + 8u);
    cpu->eax = 0xFFu;
    cpu->eax -= cpu->ecx;
    cpu->edx = 0xFFu;
    cpu->edx -= cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
    label_0004ED56: cpu->eip = LIFT_CODE_TOKEN_VA(0x44ED56u);
    cpu->eax = 0xFFu;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044ED70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44ED70u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004EDC2;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x4ED8Cu), LIFT_CODE_TOKEN_RVA(0x4ED8Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44ED8Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    cpu->esp -= 8u;
    cpu->esi = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EDA7u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EDAFu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->esi = 0xFFu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(0x10u), 32u);
    goto label_0004EDC7;
    label_0004EDC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EDC2u);
    cpu->esi = 0xFF0000u;
    label_0004EDC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EDC7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004EE14;
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x4EDDAu), LIFT_CODE_TOKEN_RVA(0x4EDD8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44EDDAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    cpu->esp -= 8u;
    cpu->ebp = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EDF6u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EDFEu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = 0xFFu;
    cpu->ebp = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->esi |= cpu->eax;
    goto label_0004EE1A;
    label_0004EE14: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EE14u);
    cpu->esi |= 0xFF00u;
    label_0004EE1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EE1Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004EE64;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x4EE2Cu), LIFT_CODE_TOKEN_RVA(0x4EE2Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44EE2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    cpu->esp -= 8u;
    cpu->ebx = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EE48u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EE50u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->ebx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = 0xFFu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax -= cpu->edx;
    cpu->eax |= cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0004EE64: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EE64u);
    cpu->esi |= 0xFFu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044EE70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44EE70u);
    cpu->esp -= 0x50u;
    lift_push32(cpu, 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x44EE8Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44EE94u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_push(cpu, 255.0);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) / (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, ((double)(((int32_t)(lift_load32(cpu->esp + 0x58u))))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EF03u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x50u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044EF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44EF20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x134u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004EF40;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EF3Au); lift_push32(cpu, r); sfera_sub_0044ED70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x134u, cpu->eax);
    label_0004EF40: cpu->eip = LIFT_CODE_TOKEN_VA(0x44EF40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    cpu->ebx = lift_load32(cpu->esi + 0x134u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44EF6Du); lift_push32(cpu, r); sfera_sub_0044ECA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x10u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = cpu->ebx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx &= 0xFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->edx;
    cpu->edx = cpu->ebx & 0xFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->edx;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->eax &= 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    { uint64_t l=cpu->esp, r=(uint64_t)(4u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x10u), 32u);
    cpu->ecx &= 0xFFu;
    sfera_sub_0044EE70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044EFE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44EFE0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = g_sfera_render_buffer_capacities.vertex32;
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0004F094;
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0004F031;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F028u); lift_push32(cpu, r); sfera_sub_004DA450(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F02Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0004F031: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F031u);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.vertex32 = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F04Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004F077;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex32;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x112u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F075u); lift_push32(cpu, r); sfera_sub_004DA720(cpu,r); if (cpu->eip != r) return; }
    goto label_0004F079;
    label_0004F077: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F077u);
    cpu->eax = 0u;
    label_0004F079: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F079u);
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_render_buffer_capacities.vertex32;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    g_sfera_sky_runtime.draw_resource = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = (uint32_t)(cpu->ebx);
    label_0004F094: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F094u);
    cpu->eax -= (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004F0C1;
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F0B9u); lift_push32(cpu, r); sfera_sub_004D89E0(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = (uint32_t)(cpu->ebx);
    goto label_0004F0CF;
    label_0004F0C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F0C1u);
    lift_push32(cpu, 0x1000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x4F0CFu); lift_push32(cpu, r); sfera_sub_004D89E0(cpu,r); if (cpu->eip != r) return; }
    label_0004F0CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F0CFu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F0F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    lift_store32(cpu->esp + 0xCu, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_0004F1B0;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0004F147;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F13Eu); lift_push32(cpu, r); sfera_sub_004DA490(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F144u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0004F147: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F147u);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.index_primary = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F160u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004F18F;
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ecx);
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F18Du); lift_push32(cpu, r); sfera_sub_004DA7D0(cpu,r); if (cpu->eip != r) return; }
    goto label_0004F191;
    label_0004F18F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F18Fu);
    cpu->eax = 0u;
    label_0004F191: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F191u);
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05) = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = (uint32_t)(0u);
    goto label_0004F1B5;
    label_0004F1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F1B0u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    label_0004F1B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F1B5u);
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0004F1FC;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, 0x2000u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F1DCu); lift_push32(cpu, r); sfera_sub_004D8A40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004F1FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F1FCu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1000u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F219u); lift_push32(cpu, r); sfera_sub_004D8A40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F240u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = g_sfera_render_buffer_capacities.vertex28;
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0004F304;
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0004F28E;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F285u); lift_push32(cpu, r); sfera_sub_004DA450(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F28Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0004F28E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F28Eu);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.vertex28 = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F2A7u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004F2E3;
    cpu->edx = g_sfera_render_buffer_capacities.vertex28;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx -= cpu->edx;
    lift_push32(cpu, 0x1C2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F2E1u); lift_push32(cpu, r); sfera_sub_004DA720(cpu,r); if (cpu->eip != r) return; }
    goto label_0004F2E5;
    label_0004F2E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F2E3u);
    cpu->eax = 0u;
    label_0004F2E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F2E5u);
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_render_buffer_capacities.vertex28;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    g_sfera_window_runtime.render_vertex_buffer = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = (uint32_t)(0u);
    label_0004F304: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F304u);
    cpu->eax -= (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004F334;
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F32Bu); lift_push32(cpu, r); sfera_sub_004D89E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = (uint32_t)(cpu->eax);
    goto label_0004F349;
    label_0004F334: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F334u);
    lift_push32(cpu, 0x1000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F344u); lift_push32(cpu, r); sfera_sub_004D89E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    label_0004F349: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F349u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F370u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    lift_store32(cpu->esp + 0xCu, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_0004F430;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0004F3C7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F3BEu); lift_push32(cpu, r); sfera_sub_004DA490(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F3C4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0004F3C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F3C7u);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.index_secondary = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F3E0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004F40F;
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ecx);
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F40Du); lift_push32(cpu, r); sfera_sub_004DA7D0(cpu,r); if (cpu->eip != r) return; }
    goto label_0004F411;
    label_0004F40F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F40Fu);
    cpu->eax = 0u;
    label_0004F411: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F411u);
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06) = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = (uint32_t)(0u);
    goto label_0004F435;
    label_0004F430: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F430u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    label_0004F435: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F435u);
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0004F47C;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, 0x2000u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F45Cu); lift_push32(cpu, r); sfera_sub_004D8A40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004F47C: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F47Cu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1000u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F499u); lift_push32(cpu, r); sfera_sub_004D8A40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F4C0u);
    cpu->edx = cpu->ecx;
    label_0004F4C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F4C2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0004F4C2;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx -= cpu->edx;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    cpu->ebx = cpu->ecx;
    --cpu->edi;
    label_0004F4D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F4D6u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004F4D6;
    cpu->ecx = cpu->ebx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F500u);
    cpu->esp -= 0x1A4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F51Cu); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004F567;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    --cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0004F530: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F530u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0004F530;
    lift_store16(cpu->edi, cpu->ebx & 0xFFFFu);
    cpu->ecx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0004F540: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F540u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0004F540;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0004F551: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F551u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004F551;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    label_0004F567: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F567u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    --cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0004F570: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F570u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0004F570;
    lift_store16(cpu->edi, cpu->ebx & 0xFFFFu);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    --cpu->edi;
    label_0004F581: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F581u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0004F581;
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"logs\\Warnings00.log") + 8u);
    cpu->eax = lift_load32((uintptr_t)"logs\\Warnings00.log");
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"logs\\Warnings00.log") + 4u);
    lift_push32(cpu, 0xECu);
    lift_store32(cpu->esp + 0xB8u, cpu->edx);
    lift_store32(cpu->esp + 0xB0u, cpu->eax);
    cpu->eax = lift_load32(((uint32_t)(uintptr_t)"logs\\Warnings00.log") + 0xCu);
    lift_store32(cpu->esp + 0xB4u, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"logs\\Warnings00.log") + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 0xC4u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_store16(cpu->edi, cpu->ebx & 0xFFFFu);
    lift_store32(cpu->esp + 0xC4u, cpu->eax);
    lift_store32(cpu->esp + 0xC8u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x44F5DAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F5DFu);
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + 0x30u);
    lift_store8(cpu->esp + 0xC5u, cpu->edx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0xB8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0xCEu, cpu->ecx & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x44F623u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F629u);
    cpu->ebx = cpu->eax;
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004F726;
    { uint64_t l=(uint64_t)(g_sfera_frame_runtime.warning_header_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::fprintf);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004F651;
    lift_push32(cpu, (uintptr_t)"*************************************************************************\n"); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x4F64Eu), LIFT_CODE_TOKEN_RVA(0x4F64Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F64Eu);
    cpu->esp += 8u;
    label_0004F651: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F651u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x44F656u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F65Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x44F661u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F667u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y");
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x44F674u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F67Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x44F682u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F688u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->esp += 0x1Cu;
    --cpu->eax;
    label_0004F690: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F690u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0004F690;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x2020)) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"  ") + 2u)) & 0xFFu);
    lift_store16(cpu->eax, cpu->edx & 0xFFFFu);
    lift_store8(cpu->eax + 2u, cpu->ecx & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x7Cu);
    cpu->edx = cpu->eax;
    label_0004F6B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F6B1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0004F6B1;
    cpu->edi = (uint32_t)(cpu->esp + 0x18u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_0004F6C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F6C0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004F6C0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = (uint32_t)(cpu->esp + 0x18u);
    --cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0004F6E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F6E0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0004F6E0;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_store16(cpu->edi, cpu->edx & 0xFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x4F6FAu), LIFT_CODE_TOKEN_RVA(0x4F6F8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F6FAu);
    lift_push32(cpu, (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0]); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x4F702u), LIFT_CODE_TOKEN_RVA(0x4F700u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F702u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x44F703u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F709u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x44F70Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F710u);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0xFFFFFFFFu);
    g_sfera_frame_runtime.warning_header_written = (uint32_t)(1u);
    lift_native_call(cpu, native_function_address32(&::MessageBeep), LIFT_CODE_TOKEN_VA(0x44F71Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44F725u);
    cpu->ebp = lift_pop32(cpu);
    label_0004F726: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F726u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1A4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F740u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count) = (uint32_t)(3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[1], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[1], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[1], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[2], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[2], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[2], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F7A1u); lift_push32(cpu, r); sfera_sub_0044C380(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count) != (uint32_t)(0u)) goto label_0004F7AF;
    label_0004F7AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F7AAu);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_0004F7AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F7AFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F7B4u); lift_push32(cpu, r); sfera_sub_0044C4C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count)) == (uint32_t)(0u)) goto label_0004F7AA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F7C2u); lift_push32(cpu, r); sfera_sub_0044C600(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count) == (uint32_t)(0u)) goto label_0004F7AA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F7D0u); lift_push32(cpu, r); sfera_sub_0044C740(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count)) == (uint32_t)(0u)) goto label_0004F7AA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F7DEu); lift_push32(cpu, r); sfera_sub_0044C880(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count) == (uint32_t)(0u)) goto label_0004F7AA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44F7ECu); lift_push32(cpu, r); sfera_sub_0044C9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F800u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    cpu->edx = 0u;
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_push(cpu, 9.999999747378752e-05);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004F827;
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    cpu->edx = 1u;
    label_0004F827: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F827u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004F83F;
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u));
    ++cpu->edx;
    label_0004F83F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F83Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004F863;
    ++cpu->edx;
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0004F863: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F863u);
    cpu->eax = 0u;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F870u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->edx + 8u, cpu->eax);
    cpu->ecx += 0x14u;
    cpu->edi = 7u;
    cpu->edi = cpu->edi;
    label_0004F8A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F8A0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004F8BA;
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004F8CB;
    label_0004F8BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F8BAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004F8C9;
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004F8CB;
    label_0004F8C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F8C9u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004F8CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F8CBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004F8E7;
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004F8FA;
    label_0004F8E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F8E7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004F8F8;
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004F8FA;
    label_0004F8F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F8F8u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004F8FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F8FAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004F915;
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004F928;
    label_0004F915: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F915u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004F926;
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004F928;
    label_0004F926: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F926u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004F928: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F928u);
    cpu->ecx += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004F8A0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F940u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    label_0004F950: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F950u);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebx);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edi = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    cpu->esi = cpu->ecx;
    cpu->edx = cpu->ebx;
    label_0004F960: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F960u);
    cpu->eax = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_0004F960;
    --cpu->esi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0004F970: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F970u);
    cpu->eax = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->edi)) goto label_0004F970;
    ++cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->edx)) goto label_0004F9BF;
    cpu->ebp = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    cpu->eax = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]), cpu->ebp);
    cpu->ebp = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    lift_store32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]), cpu->eax);
    cpu->eax = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]), cpu->ebp);
    lift_store32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]), cpu->eax);
    ++cpu->esi;
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->edx)) goto label_0004F960;
    label_0004F9BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F9BFu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0004F9C8;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x4F9C8u); lift_push32(cpu, r); sfera_sub_0044F940(cpu,r); if (cpu->eip != r) return; }
    label_0004F9C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F9C8u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004F9D0;
    cpu->ecx = cpu->esi;
    goto label_0004F950;
    label_0004F9D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x44F9D0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044F9E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44F9E0u);
    cpu->eax = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FA00u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax += cpu->ecx;
    cpu->eax = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    cpu->eax += lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FA20u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    --cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])));
    cpu->eax += lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FA50u);
    cpu->eax = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 4u));
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FA70u);
    cpu->esp -= 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ebp = 0u;
    label_0004FA89: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FA89u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0004FA93;
    cpu->ebx = cpu->edx;
    label_0004FA93: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FA93u);
    cpu->edi = 0u;
    label_0004FA95: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FA95u);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + ((uint32_t)(cpu->eax) * 4u) + 4u));
    cpu->esi = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    if ((uint32_t)(cpu->edi) != 0u) goto label_0004FAC4;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FAEC;
    label_0004FAC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FAC4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004FAD7;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FAEC;
    label_0004FAD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FAD7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004FAEA;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FAEC;
    label_0004FAEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FAEAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FAEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FAECu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0004FB18;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FB40;
    label_0004FB18: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004FB2B;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FB40;
    label_0004FB2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB2Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004FB3E;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FB40;
    label_0004FB3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB3Eu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FB40: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB40u);
    cpu->eax = (uint32_t)(cpu->edi + 2u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004FB6F;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FB97;
    label_0004FB6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB6Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004FB82;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FB97;
    label_0004FB82: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB82u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004FB95;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FB97;
    label_0004FB95: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB95u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FB97: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FB97u);
    cpu->eax = (uint32_t)(cpu->edi + 3u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004FBC6;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FBEE;
    label_0004FBC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FBC6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004FBD9;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FBEE;
    label_0004FBD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FBD9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004FBEC;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FBEE;
    label_0004FBEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FBECu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FBEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FBEEu);
    cpu->edi += 4u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(8u)) goto label_0004FA95;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    ++cpu->ebp;
    lift_store_f32(cpu->esp + ((uint32_t)(cpu->ebp) * 4u) + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + ((uint32_t)(cpu->ebp) * 4u) + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(2u)) goto label_0004FA89;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->ebx = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004FC4B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004FC4B;
    cpu->eax = 1u;
    cpu->esp += 0x1Cu;
    lift_return(cpu, 12u, stop_address); return;
    label_0004FC4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FC4Bu);
    cpu->eax = 0u;
    cpu->esp += 0x1Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FC60u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FC76u); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x4FC85u), LIFT_CODE_TOKEN_RVA(0x4FC83u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FC85u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esi, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FCB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FCB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FCB8u); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FCC6u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0049A4B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FCD0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) == (uint32_t)(cpu->edi)) goto label_0004FF75;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(cpu->edi)) goto label_0004FF75;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FCFEu); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FD0Bu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FD12u); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFu)) goto label_0004FD22;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0004FD31;
    label_0004FD22: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FD22u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x4FD31u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    label_0004FD31: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FD31u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004FD96;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.x));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004FF6C;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004FF6A;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FD98;
    label_0004FD96: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FD96u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FD98: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FD98u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(0x18u), 32u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].z, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ecx = cpu->esi;
    cpu->ecx |= 0xFFFFFFu;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].rhw, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[0].diffuse = (uint32_t)(cpu->ecx);
    g_sfera_scene_render_runtime.textured_quad[0].specular = (uint32_t)(cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0004FDDF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 8u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FDDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FDDFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[1].diffuse = (uint32_t)(cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].z, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[1].specular = (uint32_t)(cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].rhw, lift_x87_get(cpu, 0u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0004FE13;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 8u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FE13: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FE13u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[2].diffuse = (uint32_t)(cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].z, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[2].specular = (uint32_t)(cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].rhw, lift_x87_get(cpu, 0u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0004FE47;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 8u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FE47: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FE47u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[3].diffuse = (uint32_t)(cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].z, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_scene_render_runtime.textured_quad[3].specular = (uint32_t)(cpu->edi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].rhw, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0004FE7E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004FEB2;
    label_0004FE7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FE7Eu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004FEB6;
    label_0004FEB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FEB2u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FEB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FEB6u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_push(cpu, 0.5);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, ((double)(((int32_t)(lift_load32(cpu->esp + 0x14u))))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].y, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esp + 0x20u))))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FF2Du); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FF3Du); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 0xEu); lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FF57u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FF62u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 24u, stop_address); return;
    label_0004FF6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FF6Au);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FF6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FF6Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004FF75: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FF75u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044FF80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x44FF80u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) == (uint32_t)(cpu->edi)) goto label_000501B9;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(cpu->edi)) goto label_000501B9;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FFAEu); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FFBBu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44FFC2u); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFu)) goto label_0004FFD2;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004FFE1;
    label_0004FFD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FFD2u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x4FFE1u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    label_0004FFE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x44FFE1u);
    cpu->ecx = lift_load8(cpu->esp + 0x20u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load8(cpu->esp + 0x24u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].z, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].rhw, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load8(cpu->esp + 0x28u);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->edx;
    g_sfera_scene_render_runtime.textured_quad[0].diffuse = (uint32_t)(cpu->ecx);
    g_sfera_scene_render_runtime.textured_quad[0].specular = (uint32_t)(cpu->edi);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00050038;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 8u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00050038: cpu->eip = LIFT_CODE_TOKEN_VA(0x450038u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[1].diffuse = (uint32_t)(cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].z, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[1].specular = (uint32_t)(cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].rhw, lift_x87_get(cpu, 0u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0005006C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 8u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005006C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45006Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[2].diffuse = (uint32_t)(cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].z, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[2].specular = (uint32_t)(cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].rhw, lift_x87_get(cpu, 0u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000500A0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 8u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000500A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4500A0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[3].diffuse = (uint32_t)(cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].z, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[3].specular = (uint32_t)(cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].rhw, lift_x87_get(cpu, 0u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000500D9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005010D;
    label_000500D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4500D9u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00050111;
    label_0005010D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45010Du);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00050111: cpu->eip = LIFT_CODE_TOKEN_VA(0x450111u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_push(cpu, 0.5);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, ((double)(((int32_t)(lift_load32(cpu->esp + 0x10u))))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].y, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu))))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450188u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450198u); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4501AEu); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x501B9u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    label_000501B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4501B9u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 32u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004501C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4501C0u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.animation_phase));
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    ++cpu->eax;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x10u))))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4501EFu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450204u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.019999999552965164);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 8u))));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00450260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x450260u);
    cpu->esp -= 0xF4u;
    cpu->eax = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) == (uint32_t)(cpu->ebx)) goto label_000509E0;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) == (uint32_t)(cpu->ebx)) goto label_000509E0;
    ++g_sfera_effect_manager.generation;
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4502A3u); lift_push32(cpu, r); sfera_sub_00427550(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000509E0;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4502B7u); lift_push32(cpu, r); sfera_sub_00425CD0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.44999998807907104));
    cpu->esi = cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].x));
    lift_store32(cpu->esp + 0x50u, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.3100000023841858));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.23999999463558197));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4502EAu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax += 0x14u;
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    cpu->eax = lift_load16(cpu->esi);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->eax += lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    cpu->edi = lift_load32(cpu->eax + 0x98u);
    cpu->ebp = lift_load32(cpu->eax + 0x90u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi &= 1u;
    lift_store32(cpu->esp + 0x40u, cpu->ebp);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450335u); lift_push32(cpu, r); sfera_sub_00425CE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->esi = cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450346u); lift_push32(cpu, r); sfera_sub_00425CC0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx, 0u);
    lift_store32(cpu->ebx + 8u, cpu->edi);
    lift_store32(cpu->ebx + 0xCu, cpu->ebp);
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00050365;
    cpu->ecx = 0x7530u;
    label_00050365: cpu->eip = LIFT_CODE_TOKEN_VA(0x450365u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45036Au); lift_push32(cpu, r); sfera_sub_0044F240(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0x70u);
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edx);
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x100u);
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    cpu->ebp = cpu->eax;
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4503EFu); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4503FEu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x34u, 0u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000508A2;
    lift_x87_push(cpu, 255.0);
    cpu->eax = (uint32_t)(cpu->esp + 0xC0u);
    lift_x87_push(cpu, 1.0);
    cpu->eax &= 0xFFFFFFF0u;
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x6Cu, cpu->eax);
    goto label_0005042F;
    label_0005042B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45042Bu);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    label_0005042F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45042Fu);
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->ebx = lift_load16(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->ebx + 0x98u);
    cpu->eax &= 1u;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0005045E;
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->ebx + 0x90u))) goto label_00050490;
    label_0005045E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45045Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = cpu->ecx;
    cpu->edx -= lift_load32(cpu->esi);
    cpu->esi += 0x10u;
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + 1u);
    lift_store32(cpu->esi + 0xFFFFFFF4u, cpu->edx);
    lift_store32(cpu->esi, cpu->ecx);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 0x90u);
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 0x90u);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    label_00050490: cpu->eip = LIFT_CODE_TOKEN_VA(0x450490u);
    cpu->eax = lift_load32(cpu->ebx + 0x94u);
    cpu->eax += lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_000504AD;
    lift_store32(cpu->esp + 0x38u, 0xFFu);
    label_000504AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4504ADu);
    if ((uint8_t)((lift_load8(cpu->ebx + 0x98u)) & (2u)) != 0u) goto label_000504DE;
    lift_store_f32(cpu->ebx + 0x70u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x74u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x88u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebx + 0x78u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x80u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x84u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x8Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_000504DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4504DEu);
    cpu->eax = cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->ebx + 0x74u);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x58u, cpu->ecx);
    cpu->ebx += 0x30u;
    lift_store32(cpu->esp + 0x24u, 4u);
    goto label_000504FC;
    label_000504F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4504F8u);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    label_000504FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4504FCu);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->esp + 0xB0u, cpu->edi);
    lift_store32(cpu->esp + 0x64u, cpu->ecx);
    lift_store32(cpu->esp + 0x60u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_model_transform_scratch_matrix;
    lift_movs32(cpu, 1u);
    cpu->eax = lift_load32(cpu->esp + 0xB0u);
    lift_store32(cpu->esp + 0x68u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[0].y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005058A;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0xFFu;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000505B6;
    label_0005058A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45058Au);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[0].z));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000505A3;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000505B6;
    label_000505A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4505A3u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x505B6u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    label_000505B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4505B6u);
    cpu->ecx = lift_load32(cpu->ebx + 0x30u);
    cpu->edi = lift_load32(cpu->esp + 0x44u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_store_f32(cpu->ebp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_store_f32(cpu->ebp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->ebx);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x38u));
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->esi &= 0xFFu;
    cpu->esi |= cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x38u));
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->ecx &= 0xFFu;
    cpu->esi |= cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x38u));
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->esi |= cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->ebp + 0xCu, cpu->esi);
    lift_store32(cpu->ebp + 0x10u, 0u);
    cpu->edi += 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    cpu->eax += 8u;
    lift_store_f32(cpu->ebp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF8u));
    cpu->ebx += 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x24u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x24u, v); }
    lift_store_f32(cpu->ebp + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000504F8;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx = lift_load32(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    lift_store16(cpu->ebx + ((uint32_t)(cpu->eax) * 2u) + 2u, cpu->ecx & 0xFFFFu);
    cpu->ecx = (uint32_t)(cpu->edi + 2u);
    cpu->edx = (uint32_t)(cpu->edi + 3u);
    lift_store16(cpu->ebx + ((uint32_t)(cpu->eax) * 2u), cpu->edi & 0xFFFFu);
    lift_store16(cpu->ebx + ((uint32_t)(cpu->eax) * 2u) + 4u, cpu->ecx & 0xFFFFu);
    lift_store16(cpu->ebx + ((uint32_t)(cpu->eax) * 2u) + 6u, cpu->ecx & 0xFFFFu);
    lift_store16(cpu->ebx + ((uint32_t)(cpu->eax) * 2u) + 0xAu, cpu->edi & 0xFFFFu);
    lift_store16(cpu->ebx + ((uint32_t)(cpu->eax) * 2u) + 8u, cpu->edx & 0xFFFFu);
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    cpu->edi += 4u;
    cpu->eax += 6u;
    cpu->ecx += 0xFFFFFFF8u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ecx)) goto label_000506E4;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x752Au)) goto label_00050881;
    label_000506E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4506E4u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax -= lift_load32(cpu->ecx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450708u); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    cpu->ebp = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax += g_sfera_render_buffer_capacities.vertex28;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00050808;
    cpu->esi = (uint32_t)(cpu->ebp + 4u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    label_00050733: cpu->eip = LIFT_CODE_TOKEN_VA(0x450733u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) == (uint32_t)(cpu->eax)) goto label_00050757;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005074E;
    lift_push32(cpu, 6u);
    goto label_00050750;
    label_0005074E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45074Eu);
    lift_push32(cpu, 2u);
    label_00050750: cpu->eip = LIFT_CODE_TOKEN_VA(0x450750u);
    lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x50757u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    label_00050757: cpu->eip = LIFT_CODE_TOKEN_VA(0x450757u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(cpu->eax)) goto label_0005078B;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0005078B;
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450772u); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450780u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450787u); lift_push32(cpu, r); sfera_sub_0049A4B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x3Cu);
    label_0005078B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45078Bu);
    cpu->ecx = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000507FB;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450796u); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 2u));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4507A3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4507A8u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4507C0u); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4507F3u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_08, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_000507FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4507FBu);
    cpu->esi += 0x10u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x24u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x24u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050733;
    label_00050808: cpu->eip = LIFT_CODE_TOKEN_VA(0x450808u);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    cpu->edx = 0u;
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_store32(cpu->esp + 0x18u, 1u);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_store32(cpu->ebp, cpu->edx);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esp + 0x48u))) goto label_00050852;
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 2u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->eax += lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x98u);
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    cpu->ecx &= 1u;
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    goto label_00050856;
    label_00050852: cpu->eip = LIFT_CODE_TOKEN_VA(0x450852u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    label_00050856: cpu->eip = LIFT_CODE_TOKEN_VA(0x450856u);
    lift_store32(cpu->ebp + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_store32(cpu->ebp + 0xCu, cpu->ecx);
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450873u); lift_push32(cpu, r); sfera_sub_0044F240(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 255.0);
    lift_x87_push(cpu, 1.0);
    cpu->ebp = cpu->eax;
    lift_x87_push(cpu, 0.0);
    goto label_00050885;
    label_00050881: cpu->eip = LIFT_CODE_TOKEN_VA(0x450881u);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    label_00050885: cpu->eip = LIFT_CODE_TOKEN_VA(0x450885u);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->esp + 0x48u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0005042B;
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000508A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4508A2u);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4508B7u); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    cpu->ebp = cpu->eax;
    cpu->eax += g_sfera_render_buffer_capacities.vertex28;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = (uint32_t)(cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000509C3;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->eax -= lift_load32(cpu->esi);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000509C3;
    cpu->esi = (uint32_t)(cpu->ebx + 4u);
    cpu->ebx = cpu->eax;
    cpu->edi = cpu->edi;
    label_000508F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4508F0u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) == (uint32_t)(cpu->eax)) goto label_00050914;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0005090B;
    lift_push32(cpu, 6u);
    goto label_0005090D;
    label_0005090B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45090Bu);
    lift_push32(cpu, 2u);
    label_0005090D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45090Du);
    lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x50914u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    label_00050914: cpu->eip = LIFT_CODE_TOKEN_VA(0x450914u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(cpu->eax)) goto label_00050944;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00050944;
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45092Fu); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45093Du); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x50944u); lift_push32(cpu, r); sfera_sub_0049A4B0(cpu,r); if (cpu->eip != r) return; }
    label_00050944: cpu->eip = LIFT_CODE_TOKEN_VA(0x450944u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000509B9;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45094Fu); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 2u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x450960u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x450965u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45097Cu); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4509B1u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_08, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000509B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4509B9u);
    cpu->esi += 0x10u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000508F0;
    label_000509C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4509C3u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4509CEu); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4509DDu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000509E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4509E0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xF4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00450A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x450A00u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].x));
    lift_store16(cpu->esp + 2u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 2u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    lift_store64(cpu->esp + 4u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 2u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].y));
    lift_store16(cpu->esp + 2u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 2u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    lift_store64(cpu->esp + 4u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 2u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].z));
    lift_store16(cpu->esp + 2u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 2u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    lift_store64(cpu->esp + 4u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax &= 0xFFu;
    cpu->ecx |= cpu->eax;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 2u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x8Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450AA7u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00450AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x450AB0u);
    cpu->esp -= 0x48u;
    lift_push32(cpu, 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x450AC7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x450ACCu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450B12u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x48u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00450B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x450B30u);
    cpu->eax = 0x646E616Cu;
    lift_push32(cpu, cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->ecx;
    cpu->ecx = 0x70616373u;
    cpu->ebp = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x5C65)) & 0xFFFFu);
    (*(uint8_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[10]) = (uint8_t)((cpu->eax & 0xFFu));
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint16_t)((cpu->edx & 0xFFFFu));
    cpu->ecx = cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00050B70: cpu->eip = LIFT_CODE_TOKEN_VA(0x450B70u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00050B70;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050B81: cpu->eip = LIFT_CODE_TOKEN_VA(0x450B81u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050B81;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00050BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x450BA0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050BA0;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450BBEu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450BCAu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450BD1u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00050D97;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x72685F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = (uint16_t)((cpu->eax & 0xFFFFu));
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint32_t)(cpu->edx);
    cpu->ecx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00050C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x450C10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00050C10;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050C21: cpu->eip = LIFT_CODE_TOKEN_VA(0x450C21u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050C21;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00050C40: cpu->eip = LIFT_CODE_TOKEN_VA(0x450C40u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050C40;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450C5Eu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450C6Au); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00050D97;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x68705F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = (uint16_t)((cpu->eax & 0xFFFFu));
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint32_t)(cpu->edx);
    cpu->ecx = cpu->eax;
    label_00050CA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x450CA7u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00050CA7;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050CB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x450CB8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050CB8;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    label_00050CD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x450CD4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050CD4;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450CF9u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450D00u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00050D97;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x64725F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = (uint16_t)((cpu->eax & 0xFFFFu));
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint32_t)(cpu->edx);
    cpu->ecx = cpu->eax;
    label_00050D40: cpu->eip = LIFT_CODE_TOKEN_VA(0x450D40u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00050D40;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050D51: cpu->eip = LIFT_CODE_TOKEN_VA(0x450D51u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050D51;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00050D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x450D70u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050D70;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450D95u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_00050D97: cpu->eip = LIFT_CODE_TOKEN_VA(0x450D97u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450DA2u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450DAFu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450DB6u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00450DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x450DD0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    label_00050DE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x450DE2u);
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x10u, 0x50u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00050DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x450DF0u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x14u)) != (uint8_t)(0u)) goto label_000510B2;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x15u)) != (uint8_t)(0u)) goto label_000510B2;
    cpu->edx = cpu->ebx;
    cpu->eax = cpu->ebp;
    cpu->edx -= cpu->ebp;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00050E10: cpu->eip = LIFT_CODE_TOKEN_VA(0x450E10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050E10;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x5C65)) & 0xFFFFu);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    (*(uint8_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[10]) = (uint8_t)((cpu->eax & 0xFFu));
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint16_t)((cpu->edx & 0xFFFFu));
    cpu->ecx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00050E50: cpu->eip = LIFT_CODE_TOKEN_VA(0x450E50u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00050E50;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050E61: cpu->eip = LIFT_CODE_TOKEN_VA(0x450E61u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050E61;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00050E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x450E80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050E80;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450E9Eu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450EAAu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450EB1u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00051077;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x72685F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = (uint16_t)((cpu->eax & 0xFFFFu));
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint32_t)(cpu->edx);
    cpu->ecx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00050EF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x450EF0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00050EF0;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050F01: cpu->eip = LIFT_CODE_TOKEN_VA(0x450F01u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050F01;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00050F20: cpu->eip = LIFT_CODE_TOKEN_VA(0x450F20u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050F20;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450F3Eu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450F4Au); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00051077;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x68705F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = (uint16_t)((cpu->eax & 0xFFFFu));
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint32_t)(cpu->edx);
    cpu->ecx = cpu->eax;
    label_00050F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x450F87u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00050F87;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050F98: cpu->eip = LIFT_CODE_TOKEN_VA(0x450F98u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050F98;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    label_00050FB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x450FB4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00050FB4;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450FD9u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x450FE0u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00051077;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x64725F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = (uint16_t)((cpu->eax & 0xFFFFu));
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = (uint32_t)(cpu->edx);
    cpu->ecx = cpu->eax;
    label_00051020: cpu->eip = LIFT_CODE_TOKEN_VA(0x451020u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00051020;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00051031: cpu->eip = LIFT_CODE_TOKEN_VA(0x451031u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00051031;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00051050: cpu->eip = LIFT_CODE_TOKEN_VA(0x451050u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00051050;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451075u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_00051077: cpu->eip = LIFT_CODE_TOKEN_VA(0x451077u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451084u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451091u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451098u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x18u)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    cpu->eax = 0x14u;
    lift_store8(cpu->eax + cpu->ebx, cpu->ecx & 0xFFu);
    cpu->eax = 0x15u;
    lift_store8(cpu->eax + cpu->ebx, cpu->edx & 0xFFu);
    goto label_000510C6;
    label_000510B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4510B2u);
    cpu->eax = 0u;
    lift_store32(cpu->ebx, cpu->eax);
    lift_store32(cpu->ebx + 4u, cpu->eax);
    lift_store32(cpu->ebx + 8u, cpu->eax);
    lift_store32(cpu->ebx + 0xCu, cpu->eax);
    lift_store32(cpu->ebx + 0x10u, cpu->eax);
    lift_store16(cpu->ebx + 0x14u, cpu->eax & 0xFFFFu);
    label_000510C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4510C6u);
    cpu->ebp += 0x16u;
    cpu->ebx += 0x6E0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00050DF0;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx += 0x16u;
    cpu->eax = cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[kLandscapeMapRecordCount]))) goto label_00050DE2;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451100u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 2u));
    cpu->ebx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x8Cu);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esi = (uint32_t)(cpu->ebx + 0x18u);
    lift_store32(cpu->esp + 0xCu, 4u);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00051130: cpu->eip = LIFT_CODE_TOKEN_VA(0x451130u);
    lift_store32(cpu->esp + 0x20u, 4u);
    label_00051140: cpu->eip = LIFT_CODE_TOKEN_VA(0x451140u);
    cpu->ebp = 9u;
    label_00051145: cpu->eip = LIFT_CODE_TOKEN_VA(0x451145u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005115C;
    lift_push32(cpu, 0x4392u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45115Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->edi);
    label_0005115C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45115Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->edi)) goto label_0005117A;
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005117A;
    lift_push32(cpu, 0x4393u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451177u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    label_0005117A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45117Au);
    cpu->esi += 0x30u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00051145;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00051140;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00051130;
    cpu->ecx = lift_load32(cpu->ebx + 0x1B0Cu);
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000511AC;
    lift_push32(cpu, 0x4395u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4511A6u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B0Cu, cpu->edi);
    label_000511AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4511ACu);
    cpu->ecx = lift_load32(cpu->ebx + 0x1B10u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000511CB;
    lift_push32(cpu, 0x4396u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4511C5u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B10u, cpu->edi);
    label_000511CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4511CBu);
    cpu->ecx = lift_load32(cpu->ebx + 0x1B14u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000511EA;
    lift_push32(cpu, 0x4397u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4511E4u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B14u, cpu->edi);
    label_000511EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4511EAu);
    cpu->ecx = lift_load32(cpu->ebx + 0x1B18u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00051209;
    lift_push32(cpu, 0x4398u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451203u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B18u, cpu->edi);
    label_00051209: cpu->eip = LIFT_CODE_TOKEN_VA(0x451209u);
    cpu->ecx = lift_load32(cpu->ebx + 0x1B1Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00051228;
    lift_push32(cpu, 0x4399u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451222u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B1Cu, cpu->edi);
    label_00051228: cpu->eip = LIFT_CODE_TOKEN_VA(0x451228u);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00051241;
    lift_push32(cpu, 0x439Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45123Eu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->edi);
    label_00051241: cpu->eip = LIFT_CODE_TOKEN_VA(0x451241u);
    cpu->ecx = lift_load32(cpu->ebx + 0x68A0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00051260;
    lift_push32(cpu, 0x439Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45125Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x68A0u, cpu->edi);
    label_00051260: cpu->eip = LIFT_CODE_TOKEN_VA(0x451260u);
    cpu->ecx = lift_load32(cpu->ebx + 0x68A4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005127F;
    lift_push32(cpu, 0x439Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451279u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x68A4u, cpu->edi);
    label_0005127F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45127Fu);
    cpu->ecx = lift_load32(cpu->ebx + 0x68A8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005129E;
    lift_push32(cpu, 0x439Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451298u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x68A8u, cpu->edi);
    label_0005129E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45129Eu);
    cpu->ecx = lift_load32(cpu->ebx + 0x68ACu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000512BD;
    lift_push32(cpu, 0x439Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4512B7u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x68ACu, cpu->edi);
    label_000512BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4512BDu);
    cpu->ecx = lift_load32(cpu->ebx + 0x687Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000512DC;
    lift_push32(cpu, 0x439Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4512D6u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x687Cu, cpu->edi);
    label_000512DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4512DCu);
    cpu->ecx = lift_load32(cpu->ebx + 0x6880u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000512FB;
    lift_push32(cpu, 0x43A0u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4512F5u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x6880u, cpu->edi);
    label_000512FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4512FBu);
    cpu->ecx = lift_load32(cpu->ebx + 0x6884u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005131A;
    lift_push32(cpu, 0x43A1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451314u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x6884u, cpu->edi);
    label_0005131A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45131Au);
    cpu->ecx = lift_load32(cpu->ebx + 0x6888u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00051339;
    lift_push32(cpu, 0x43A2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451333u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x6888u, cpu->edi);
    label_00051339: cpu->eip = LIFT_CODE_TOKEN_VA(0x451339u);
    lift_push32(cpu, 0x43A3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45134Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x3ACu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00051373;
    lift_push32(cpu, 0x43A4u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45136Cu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x3ACu, cpu->edi);
    label_00051373: cpu->eip = LIFT_CODE_TOKEN_VA(0x451373u);
    lift_store32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x8Cu, cpu->edi);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.client_state_03, (uint64_t)(g_sfera_recovered_static_runtime.client_state_03) - 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451390u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = cpu->edx;
    cpu->eax = 0u;
    cpu->edx = 0u;
    lift_push32(cpu, (uintptr_t)"wb"); lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0x18u, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x19u, 0x200u);
    lift_store16(cpu->esp + 0x1Du, cpu->edx & 0xFFFFu);
    lift_store8(cpu->esp + 0x1Fu, cpu->eax & 0xFFu);
    lift_store16(cpu->esp + 0x24u, cpu->esi & 0xFFFFu);
    lift_store16(cpu->esp + 0x26u, cpu->esi & 0xFFFFu);
    lift_store16(cpu->esp + 0x28u, 0x2010u);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4513DCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4513E2u);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000513FF;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_000513FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4513FFu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fwrite);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x12u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x51412u), LIFT_CODE_TOKEN_RVA(0x51410u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451412u);
    cpu->esp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00051433;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00051420: cpu->eip = LIFT_CODE_TOKEN_VA(0x451420u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x51427u), LIFT_CODE_TOKEN_RVA(0x51425u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451427u);
    cpu->esp += 0x10u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->esi) * 2u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00051420;
    label_00051433: cpu->eip = LIFT_CODE_TOKEN_VA(0x451433u);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x451434u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45143Au);
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451460u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edi = (cpu->edi & 0xFFFF0000u) | ((uint32_t)((cpu->ecx & 0xFFFFu)) & 0xFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451470u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_push(cpu, 400.0); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1000.0);
    lift_x87_set(cpu, 3u, (lift_x87_get(cpu, 3u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451491u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax -= 0x3E8u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4514A9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4514BBu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->esi = cpu->eax;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4514CAu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4514E1u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax -= 0x3E8u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4514F9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (256.0));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451512u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005151A;
    cpu->esi = 0u;
    goto label_00051527;
    label_0005151A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45151Au);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(0xFFu)) goto label_00051527;
    cpu->esi = 0xFFu;
    label_00051527: cpu->eip = LIFT_CODE_TOKEN_VA(0x451527u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0005152F;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    goto label_0005153B;
    label_0005152F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45152Fu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0005153B;
    cpu->eax = 0xFFu;
    label_0005153B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45153Bu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax += cpu->esi;
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0]), (uint64_t)(lift_load16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0]))) ^ (uint64_t)((cpu->edi & 0xFFFFu)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0]));
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0]);
    cpu->edx = 0x100u;
    cpu->ecx = (uint32_t)(uintptr_t)"lndbug.tga";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451563u); lift_push32(cpu, r); sfera_sub_00451390(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451570u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451580u);
    lift_x87_push(cpu, 1.0);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.transition_factor));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, 0.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000515B8;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.direction_x.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.direction_y.f32));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0005165A;
    label_000515B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4515B8u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.direction_y.f32));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.direction_x.f32));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4515DFu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.transition_factor));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (0.00019999999494757503) - (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)9.999999747378752e-06f));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00051632;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    goto label_00051658;
    label_00051632: cpu->eip = LIFT_CODE_TOKEN_VA(0x451632u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.direction_x.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.direction_y.f32));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    label_00051658: cpu->eip = LIFT_CODE_TOKEN_VA(0x451658u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0005165A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45165Au);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0005168E;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32));
    label_0005168E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45168Eu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000516A1;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000516A3;
    label_000516A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4516A1u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000516A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4516A3u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_000516DC;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_000516DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4516DCu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000516F3;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000516F7;
    label_000516F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4516F3u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000516F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4516F7u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_world_render_runtime.world_spatial_index;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000517C4;
    if ((uint32_t)(g_sfera_main_render_runtime.grass_depth_mode) != (uint32_t)(2u)) goto label_000517C4;
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451728u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00051767;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451762u); lift_push32(cpu, r); sfera_sub_00424680(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00051767: cpu->eip = LIFT_CODE_TOKEN_VA(0x451767u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (0.00198));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 8u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005179C;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0005179E;
    label_0005179C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45179Cu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005179E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45179Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4517BFu); lift_push32(cpu, r); sfera_sub_00424680(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_000517C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4517C4u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004517D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4517D0u);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25)) == (uint32_t)(0u)) goto label_0005188C;
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.view_transition_counter) > (int32_t)(uint32_t)(0u)) goto label_000517EF;
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    goto label_000517FB;
    label_000517EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4517EFu);
    lift_x87_push(cpu, (double)0.019999999552965164f);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.view_transition_counter, (uint64_t)(g_sfera_recovered_static_runtime.view_transition_counter) - 1u);
    label_000517FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4517FBu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)20.0f);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.frame_interval.f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005184B;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_graphics_runtime.saved_fog_distance)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 30.0);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005188C;
    lift_x87_push(cpu, (double)30.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0005184B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45184Bu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 28.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005188C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_graphics_runtime.saved_fog_distance)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 200.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005188C;
    lift_x87_push(cpu, (double)200.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005188C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45188Cu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451890u);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4518A6u); lift_push32(cpu, r); sfera_sub_004BB800(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x180u); lift_push32(cpu, (uintptr_t)"loadcount.bin");
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x4518B0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4518B6u);
    cpu->esp += 8u;
    cpu->ecx = (uint32_t)(uintptr_t)"loadcount.bin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4518C3u); lift_push32(cpu, r); sfera_sub_0042EE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_accumulator;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4518D3u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0042F180(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004518E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4518E0u);
    cpu->esp -= 0x10u;
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.004999999888241291);
    lift_x87_push(cpu, 0.000122499996908009);
    lift_x87_push(cpu, 0.04899999985843895);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    label_000518FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4518FDu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    goto label_00051919;
    label_00051917: cpu->eip = LIFT_CODE_TOKEN_VA(0x451917u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00051919: cpu->eip = LIFT_CODE_TOKEN_VA(0x451919u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 6u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00051917;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (10.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451953u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x63u)) goto label_00051963;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_physics_runtime.response_curve[0]), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00051963: cpu->eip = LIFT_CODE_TOKEN_VA(0x451963u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.009999999776482582));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 14.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000518FD;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451990u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_000519A1;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0x64u)) goto label_000519A1;
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_physics_runtime.response_curve[0])));
    lift_return(cpu, 0u, stop_address); return;
    label_000519A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4519A1u);
    lift_x87_push(cpu, 0.0);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004519B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4519B0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->ecx = g_sfera_window_runtime.input_runtime_object;
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4519CDu); lift_push32(cpu, r); sfera_sub_00489830(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004519D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4519D0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, 40.74365997314453);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4519E4u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    cpu->esi = cpu->eax;
    cpu->esi &= 0xFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4519F5u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= 0xFFu;
    cpu->esi -= cpu->eax;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x80u)) goto label_00051A1A;
    cpu->ecx = 0x100u;
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 4u, cpu->ecx);
    label_00051A1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x451A1Au);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.024543695894260174));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451A30u);
    cpu->eax = cpu->ecx & 0xFFu;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03) = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451A40u);
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 4u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 8u))));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)1.1754943508222875e-38f));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00051ABC;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_00051ABC: cpu->eip = LIFT_CODE_TOKEN_VA(0x451ABCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0xCu))));
    cpu->edx = 0xFFFFFFFEu;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00051AF8;
    cpu->edx = 1u;
    label_00051AF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x451AF8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00051B08;
    ++cpu->edx;
    label_00051B08: cpu->eip = LIFT_CODE_TOKEN_VA(0x451B08u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->ecx + 4u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->ecx + 8u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->edx;
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451B40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00051B7E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00051B7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x451B7Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->esi = 0u;
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00051C0D;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00051C00;
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, 0.0);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + 0xFFFFFFFCu);
    label_00051BBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x451BBDu);
    cpu->eax = lift_load32(cpu->eax + cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->edx + cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 8u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00051CD1;
    ++cpu->esi;
    cpu->eax = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_00051BBD;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00051C00: cpu->eip = LIFT_CODE_TOKEN_VA(0x451C00u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00051C0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x451C0Du);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00051C72;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00051C00;
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, 0.0);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + 0xFFFFFFFCu);
    label_00051C26: cpu->eip = LIFT_CODE_TOKEN_VA(0x451C26u);
    cpu->eax = lift_load32(cpu->edx + cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->edx + cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00051CD1;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_00051C26;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00051C72: cpu->eip = LIFT_CODE_TOKEN_VA(0x451C72u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00051C00;
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, 0.0);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + 0xFFFFFFFCu);
    label_00051C87: cpu->eip = LIFT_CODE_TOKEN_VA(0x451C87u);
    cpu->eax = lift_load32(cpu->edx + cpu->ebx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->edx + cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 4u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00051CD1;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_00051C87;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00051CD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x451CD1u);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451CF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00051D04;
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51D04u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00051D04: cpu->eip = LIFT_CODE_TOKEN_VA(0x451D04u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00051D13;
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51D13u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00051D13: cpu->eip = LIFT_CODE_TOKEN_VA(0x451D13u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451D20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00051D34;
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51D34u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00051D34: cpu->eip = LIFT_CODE_TOKEN_VA(0x451D34u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->edi + 4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00051D43;
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51D43u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00051D43: cpu->eip = LIFT_CODE_TOKEN_VA(0x451D43u);
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += lift_load32(cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451D50u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00051D64;
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51D64u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00051D64: cpu->eip = LIFT_CODE_TOKEN_VA(0x451D64u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00051D73;
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51D73u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00051D73: cpu->eip = LIFT_CODE_TOKEN_VA(0x451D73u);
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x27188u);
    cpu->eax += lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451D90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00051DA4;
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51DA4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00051DA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x451DA4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00051DB3;
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51DB3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00051DB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x451DB3u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451DC0u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451DC8u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00051DF5;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x451DD4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x451DDAu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x451DDBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x451DE1u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x451DE2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x451DE8u);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00051DF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x451DF5u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451E00u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00051EA1;
    label_00051E15: cpu->eip = LIFT_CODE_TOKEN_VA(0x451E15u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00051E29;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51E29u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00051E29: cpu->eip = LIFT_CODE_TOKEN_VA(0x451E29u);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_00051E37;
    ++cpu->esi;
    goto label_00051E15;
    label_00051E37: cpu->eip = LIFT_CODE_TOKEN_VA(0x451E37u);
    cpu->edx = 0xD71u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451E46u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00051E5A;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51E5Au); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00051E5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x451E5Au);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00051E76;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.object_reference_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count)) - 1u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451E73u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00051E76: cpu->eip = LIFT_CODE_TOKEN_VA(0x451E76u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00051E8A;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51E8Au); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00051E8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x451E8Au);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), 0u);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00051E15;
    label_00051EA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x451EA1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00451EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x451EB0u);
    cpu->esp -= 0x8Cu;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451ED5u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x100u);
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451F40u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000526D9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = 0xFF000000u;
    label_00051F57: cpu->eip = LIFT_CODE_TOKEN_VA(0x451F57u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00051F6B;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51F6Bu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00051F6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x451F6Bu);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_00051F7A;
    ++cpu->esi;
    goto label_00051F57;
    label_00051F7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x451F7Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00051F8E;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51F8Eu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00051F8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x451F8Eu);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00051FAB;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x51FABu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00051FAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x451FABu);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x10u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052008;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052008;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000526C9;
    goto label_0005200A;
    label_00052008: cpu->eip = LIFT_CODE_TOKEN_VA(0x452008u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005200A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45200Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005201E;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5201Eu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005201E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45201Eu);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0005203E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5203Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005203E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45203Eu);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 8u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052066;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52066u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052066: cpu->eip = LIFT_CODE_TOKEN_VA(0x452066u);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00052085;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52085u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052085: cpu->eip = LIFT_CODE_TOKEN_VA(0x452085u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_000520AE;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x520AEu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000520AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4520AEu);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_000520CE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x520CEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000520CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4520CEu);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0x10u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452153u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4521B2u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 0.0010000000474974513);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052216;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52216u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052216: cpu->eip = LIFT_CODE_TOKEN_VA(0x452216u);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005223F;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5223Fu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005223F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45223Fu);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x4], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052269;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52269u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052269: cpu->eip = LIFT_CODE_TOKEN_VA(0x452269u);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x8], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052292;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52292u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052292: cpu->eip = LIFT_CODE_TOKEN_VA(0x452292u);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x1C], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_000522BB;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x522BBu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000522BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4522BBu);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x20], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_000522E5;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x522E5u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000522E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4522E5u);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x24], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005230E;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5230Eu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005230E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45230Eu);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0005232E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5232Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005232E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45232Eu);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 8u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052357;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52357u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052357: cpu->eip = LIFT_CODE_TOKEN_VA(0x452357u);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00052376;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52376u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052376: cpu->eip = LIFT_CODE_TOKEN_VA(0x452376u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005239F;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5239Fu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005239F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45239Fu);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_000523BF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x523BFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000523BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4523BFu);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0x10u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452444u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4524A3u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 0.0010000000474974513);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052507;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52507u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052507: cpu->eip = LIFT_CODE_TOKEN_VA(0x452507u);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x4Cu))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x38], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052531;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52531u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052531: cpu->eip = LIFT_CODE_TOKEN_VA(0x452531u);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x3C], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005255B;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5255Bu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005255B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45255Bu);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x40], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052584;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52584u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052584: cpu->eip = LIFT_CODE_TOKEN_VA(0x452584u);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x4Cu))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x54], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_000525AE;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x525AEu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000525AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4525AEu);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x58], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_000525D8;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x525D8u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000525D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4525D8u);
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x28], cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0xC], cpu->ebx);
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x60], cpu->ebx);
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x44], cpu->ebx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x5C], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052619;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52619u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052619: cpu->eip = LIFT_CODE_TOKEN_VA(0x452619u);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x10], cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005263F;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5263Fu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005263F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45263Fu);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x2C], cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_00052665;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52665u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00052665: cpu->eip = LIFT_CODE_TOKEN_VA(0x452665u);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x48], cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_collision_runtime.contact_objects.capacity)) goto label_0005268B;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5268Bu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005268B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45268Bu);
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    lift_store32((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x64], cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4526ADu); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0]); lift_push32(cpu, 6u); lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x526C9u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    label_000526C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4526C9u);
    ++cpu->ebp;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count))) goto label_00051F57;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000526D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4526D9u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004526F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4526F0u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ecx + 0x1B0Cu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    g_sfera_recovered_static_runtime.client_state_01 = (uint32_t)(cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 8u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00052810;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    label_00052740: cpu->eip = LIFT_CODE_TOKEN_VA(0x452740u);
    cpu->ebp = 3u;
    label_00052745: cpu->eip = LIFT_CODE_TOKEN_VA(0x452745u);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->esi = lift_load16(cpu->ebx + cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005275A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5275Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005275A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45275Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.microtexture_handles.capacity)) goto label_0005276E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5276Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005276E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45276Eu);
    cpu->eax = g_sfera_landscape_runtime.microtexture_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0xFFFFFFFFu)) goto label_000527E5;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00052787;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52787u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00052787: cpu->eip = LIFT_CODE_TOKEN_VA(0x452787u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.microtexture_handles.capacity)) goto label_0005279B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5279Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005279B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45279Bu);
    cpu->ecx = g_sfera_recovered_static_runtime.client_state_01;
    cpu->edx = g_sfera_landscape_runtime.microtexture_handles.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.client_state_01;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    g_sfera_recovered_static_runtime.client_state_01 = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000527C5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x527C5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000527C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4527C5u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.surface_handles.capacity)) goto label_000527D9;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x527D9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000527D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4527D9u);
    cpu->eax = g_sfera_scene_array_runtime.surface_handles.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_000527E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4527E5u);
    cpu->ebx += 2u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00052745;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    cpu->ebx += 0x1Cu;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 8u))) goto label_00052740;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    label_00052810: cpu->eip = LIFT_CODE_TOKEN_VA(0x452810u);
    cpu->ecx = g_sfera_recovered_static_runtime.client_state_01;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->ebx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.client_state_01) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000528BF;
    (void)cpu;
    label_00052830: cpu->eip = LIFT_CODE_TOKEN_VA(0x452830u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005284B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5284Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005284B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45284Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.surface_records.capacity)) goto label_0005285F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5285Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005285F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45285Fu);
    cpu->ecx = g_sfera_scene_array_runtime.surface_records.data;
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00052879;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52879u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00052879: cpu->eip = LIFT_CODE_TOKEN_VA(0x452879u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.surface_handles.capacity)) goto label_0005288D;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5288Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005288D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45288Du);
    cpu->edx = g_sfera_scene_array_runtime.surface_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = 0xAu;
    ++cpu->ebx;
    lift_movs32(cpu, 1u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.client_state_01)) goto label_00052830;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    label_000528BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4528BFu);
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_02;
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 8u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00052983;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000528E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4528E0u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebp = 3u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000528F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4528F0u);
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_02;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_client_main_scalar_runtime.counter_02 = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005290B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5290Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005290B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45290Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.surface_index_map.capacity)) goto label_0005291F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5291Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005291F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45291Fu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = g_sfera_scene_array_runtime.surface_index_map.data;
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 2u));
    cpu->esi = lift_load16(cpu->ebx + cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00052941;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52941u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00052941: cpu->eip = LIFT_CODE_TOKEN_VA(0x452941u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.microtexture_handles.capacity)) goto label_00052955;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52955u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052955: cpu->eip = LIFT_CODE_TOKEN_VA(0x452955u);
    cpu->edx = g_sfera_landscape_runtime.microtexture_handles.data;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->esi) * 4u))) & 0xFFFFu);
    cpu->ebx += 2u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    lift_store16(cpu->edi, cpu->eax & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000528F0;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_000528E0;
    label_00052983: cpu->eip = LIFT_CODE_TOKEN_VA(0x452983u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.client_state_01) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000529F2;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00052990: cpu->eip = LIFT_CODE_TOKEN_VA(0x452990u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005299E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5299Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005299E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45299Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.surface_handles.capacity)) goto label_000529B2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x529B2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000529B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4529B2u);
    cpu->edx = g_sfera_scene_array_runtime.surface_handles.data;
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000529C9;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x529C9u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000529C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4529C9u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.microtexture_handles.capacity)) goto label_000529DD;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x529DDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000529DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4529DDu);
    cpu->eax = g_sfera_landscape_runtime.microtexture_handles.data;
    ++cpu->esi;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u), 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.client_state_01)) goto label_00052990;
    label_000529F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4529F2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00452A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x452A00u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1B0Cu)) != (uint32_t)(cpu->esi)) goto label_00052A29;
    lift_push32(cpu, 0x1367u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xB40u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452A23u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B0Cu, cpu->eax);
    label_00052A29: cpu->eip = LIFT_CODE_TOKEN_VA(0x452A29u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1B10u)) != (uint32_t)(cpu->esi)) goto label_00052A4B;
    lift_push32(cpu, 0x1369u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xB40u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452A45u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B10u, cpu->eax);
    label_00052A4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x452A4Bu);
    lift_push32(cpu, cpu->ebp);
    g_sfera_client_main_scalar_runtime.counter_02 = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state) = (uint32_t)(cpu->esi);
    cpu->esi = (uint32_t)(cpu->ebx + 0xCu);
    lift_store32(cpu->esp + 0xCu, 4u);
    lift_push32(cpu, cpu->edi);
    label_00052A64: cpu->eip = LIFT_CODE_TOKEN_VA(0x452A64u);
    cpu->ebp = 4u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00052A70: cpu->eip = LIFT_CODE_TOKEN_VA(0x452A70u);
    cpu->edi = 9u;
    label_00052A75: cpu->eip = LIFT_CODE_TOKEN_VA(0x452A75u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452A7Eu); lift_push32(cpu, r); sfera_sub_004526F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x30u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00052A75;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00052A70;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00052A64;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1B14u)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00052ABA;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x1374u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452AB4u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B14u, cpu->eax);
    label_00052ABA: cpu->eip = LIFT_CODE_TOKEN_VA(0x452ABAu);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1B18u)) != (uint32_t)(0u)) goto label_00052AE0;
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_02;
    lift_push32(cpu, 0x1376u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452ADAu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1B18u, cpu->eax);
    label_00052AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x452AE0u);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.surface_records.capacity) > (int32_t)(uint32_t)(0u)) goto label_00052AF5;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52AF5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052AF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x452AF5u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->ecx = g_sfera_scene_array_runtime.surface_records.data;
    cpu->edx = lift_load32(cpu->ebx + 0x1B14u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x452B12u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x452B17u);
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.surface_index_map.capacity) > (int32_t)(uint32_t)(0u)) goto label_00052B2F;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52B2Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052B2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x452B2Fu);
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_02;
    cpu->edx = g_sfera_scene_array_runtime.surface_index_map.data;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x1B18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x452B46u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x452B4Bu);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00452B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x452B60u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, 0x139Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452B7Bu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x452B88u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x452B8Du);
    lift_x87_push(cpu, (double)-0.009999999776482582f);
    lift_x87_push(cpu, (double)0.009999999776482582f);
    cpu->ecx = 0u;
    lift_x87_push(cpu, 99.98999786376953);
    cpu->esp += 0xCu;
    lift_x87_push(cpu, 100.01000213623047);
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00052EA8;
    cpu->edi = 0u;
    goto label_00052BBB;
    label_00052BB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x452BB9u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    label_00052BBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x452BBBu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + cpu->edi)));
    cpu->edx += cpu->edi;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052BF6;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052BF4;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052BF4;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052BF4;
    lift_store8(cpu->ecx + cpu->ebx, 1u);
    ++cpu->ebp;
    label_00052BF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x452BF4u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_00052BF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x452BF6u);
    ++cpu->ecx;
    cpu->edi += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052BB9;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00052C01: cpu->eip = LIFT_CODE_TOKEN_VA(0x452C01u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x13B1u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->ebp + cpu->ebp);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x688Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452C20u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x687Cu, cpu->eax);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00052C4D;
    cpu->ecx = 0u;
    (void)cpu;
    label_00052C30: cpu->eip = LIFT_CODE_TOKEN_VA(0x452C30u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) != (uint8_t)(1u)) goto label_00052C47;
    lift_store8(cpu->eax + cpu->ebx, 2u);
    cpu->edx = lift_load32(cpu->esi + 0x687Cu);
    lift_store16(cpu->ecx + cpu->edx, cpu->eax & 0xFFFFu);
    cpu->ecx += 2u;
    label_00052C47: cpu->eip = LIFT_CODE_TOKEN_VA(0x452C47u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052C30;
    label_00052C4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x452C4Du);
    cpu->ecx = 0u;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00052CAA;
    lift_x87_push(cpu, 100.01000213623047);
    cpu->ebp = 0u;
    lift_x87_push(cpu, 99.98999786376953);
    label_00052C64: cpu->eip = LIFT_CODE_TOKEN_VA(0x452C64u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ebp));
    cpu->edx += cpu->ebp;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052C9D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052C9D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052C9D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052C9D;
    lift_store8(cpu->ecx + cpu->ebx, 1u);
    ++cpu->edi;
    label_00052C9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x452C9Du);
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052C64;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00052CAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x452CAAu);
    lift_push32(cpu, 0x13C9u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esi + 0x6890u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452CC2u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x6880u, cpu->eax);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00052CEE;
    cpu->ecx = 0u;
    label_00052CD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x452CD1u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) != (uint8_t)(1u)) goto label_00052CE8;
    lift_store8(cpu->eax + cpu->ebx, 2u);
    cpu->edx = lift_load32(cpu->esi + 0x6880u);
    lift_store16(cpu->ecx + cpu->edx, cpu->eax & 0xFFFFu);
    cpu->ecx += 2u;
    label_00052CE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x452CE8u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052CD1;
    label_00052CEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x452CEEu);
    cpu->ecx = 0u;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00052D4B;
    lift_x87_push(cpu, (double)0.009999999776482582f);
    cpu->ebp = 0u;
    lift_x87_push(cpu, (double)-0.009999999776482582f);
    label_00052D05: cpu->eip = LIFT_CODE_TOKEN_VA(0x452D05u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + cpu->ebp)));
    cpu->edx += cpu->ebp;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052D3E;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052D3E;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + 8u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052D3E;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + 8u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052D3C;
    lift_store8(cpu->ecx + cpu->ebx, 1u);
    ++cpu->edi;
    label_00052D3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x452D3Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00052D3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x452D3Eu);
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052D05;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00052D4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x452D4Bu);
    lift_push32(cpu, 0x13E1u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esi + 0x6894u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452D63u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x6884u, cpu->eax);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00052D8F;
    cpu->ecx = 0u;
    label_00052D72: cpu->eip = LIFT_CODE_TOKEN_VA(0x452D72u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) != (uint8_t)(1u)) goto label_00052D89;
    lift_store8(cpu->eax + cpu->ebx, 2u);
    cpu->edx = lift_load32(cpu->esi + 0x6884u);
    lift_store16(cpu->ecx + cpu->edx, cpu->eax & 0xFFFFu);
    cpu->ecx += 2u;
    label_00052D89: cpu->eip = LIFT_CODE_TOKEN_VA(0x452D89u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052D72;
    label_00052D8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x452D8Fu);
    cpu->ecx = 0u;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00052DFC;
    lift_x87_push(cpu, 100.01000213623047);
    cpu->ebp = 0u;
    lift_x87_push(cpu, 99.98999786376953);
    lift_x87_push(cpu, (double)0.009999999776482582f);
    lift_x87_push(cpu, (double)-0.009999999776482582f);
    label_00052DB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x452DB2u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ebp));
    cpu->edx += cpu->ebp;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052DEB;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052DEB;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + 8u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052DEB;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + 8u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052DE9;
    lift_store8(cpu->ecx + cpu->ebx, 1u);
    ++cpu->edi;
    label_00052DE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x452DE9u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00052DEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x452DEBu);
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052DB2;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00052DFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x452DFCu);
    lift_push32(cpu, 0x13F9u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esi + 0x6898u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x452E14u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x6888u, cpu->eax);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00052E40;
    cpu->ecx = 0u;
    label_00052E23: cpu->eip = LIFT_CODE_TOKEN_VA(0x452E23u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) != (uint8_t)(1u)) goto label_00052E3A;
    lift_store8(cpu->eax + cpu->ebx, 2u);
    cpu->edx = lift_load32(cpu->esi + 0x6888u);
    lift_store16(cpu->ecx + cpu->edx, cpu->eax & 0xFFFFu);
    cpu->ecx += 2u;
    label_00052E3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x452E3Au);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052E23;
    label_00052E40: cpu->eip = LIFT_CODE_TOKEN_VA(0x452E40u);
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00052E8B;
    lift_x87_push(cpu, 100.01000213623047);
    cpu->ebp = 0u;
    lift_x87_push(cpu, 99.98999786376953);
    label_00052E55: cpu->eip = LIFT_CODE_TOKEN_VA(0x452E55u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebx)) == (uint8_t)(2u)) goto label_00052E7E;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ebp + 8u));
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebp + 8u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00052E7E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00052E7E;
    lift_store8(cpu->ecx + cpu->ebx, 1u);
    label_00052E7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x452E7Eu);
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052E55;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00052E8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x452E8Bu);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0005304D;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, 1u);
    goto label_00052EB4;
    label_00052EA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x452EA8u);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00052C01;
    label_00052EB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x452EB0u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_00052EB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x452EB4u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint8_t)(lift_load8(cpu->ebx + cpu->ecx + 0xFFFFFFFFu)) != (uint8_t)(1u)) goto label_00053035;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = cpu->ecx;
    cpu->ebx = cpu->edi;
    lift_store8(cpu->edx + cpu->ebp + 0xFFFFFFFFu, 2u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00052EE2;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52EE2u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00052EE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x452EE2u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_00052EF6;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52EF6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052EF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x452EF6u);
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store16(cpu->eax + cpu->edx, cpu->ecx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00052F19;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52F19u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00052F19: cpu->eip = LIFT_CODE_TOKEN_VA(0x452F19u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_00052F2D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52F2Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052F2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x452F2Du);
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edx));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index), cpu->ebx);
    ++cpu->eax;
    ++cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053035;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = (uint32_t)(cpu->edx + 0x28u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00052F70: cpu->eip = LIFT_CODE_TOKEN_VA(0x452F70u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp)) != (uint8_t)(1u)) goto label_00053028;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053028;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053028;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053028;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->edx + cpu->ebp, 2u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00052FD0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52FD0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00052FD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x452FD0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_00052FE4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52FE4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00052FE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x452FE4u);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    lift_store16(cpu->eax + ((uint32_t)(cpu->edi) * 2u), cpu->ebp & 0xFFFFu);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) >= (int32_t)(uint32_t)(0u)) goto label_00052FFF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x52FFFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00052FFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x452FFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_00053017;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53017u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00053017: cpu->eip = LIFT_CODE_TOKEN_VA(0x453017u);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store16(cpu->ecx + cpu->eax, (uint64_t)(lift_load16(cpu->ecx + cpu->eax)) + 1u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    label_00053028: cpu->eip = LIFT_CODE_TOKEN_VA(0x453028u);
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052F70;
    label_00053035: cpu->eip = LIFT_CODE_TOKEN_VA(0x453035u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00052EB0;
    label_0005304D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45304Du);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45305Bu); lift_push32(cpu, r); sfera_sub_0044DB50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1420u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esi + 0x68B0u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453073u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x68A0u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00053136;
    cpu->edx = cpu->ebp;
    lift_store32(cpu->esp + 0x24u, (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    label_00053091: cpu->eip = LIFT_CODE_TOKEN_VA(0x453091u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000530A5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x530A5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000530A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4530A5u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000530B9;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x530B9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000530B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4530B9u);
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = lift_load32(cpu->esi + 0x68A0u);
    lift_store16(cpu->edx + ((uint32_t)(cpu->ebx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->ebx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00053127;
    label_000530E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4530E0u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->edi + 1u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000530F8;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x530F8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000530F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4530F8u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_0005310C;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5310Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005310C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45310Cu);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->edx = lift_load32(cpu->esi + 0x68A0u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + ((uint32_t)(cpu->ebp) * 2u))) & 0xFFFFu);
    lift_store16(cpu->edx + ((uint32_t)(cpu->ebx) * 2u), cpu->ecx & 0xFFFFu);
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000530E0;
    label_00053127: cpu->eip = LIFT_CODE_TOKEN_VA(0x453127u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00053091;
    label_00053136: cpu->eip = LIFT_CODE_TOKEN_VA(0x453136u);
    cpu->edi = 0u;
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00053187;
    lift_x87_push(cpu, (double)0.009999999776482582f);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)-0.009999999776482582f);
    cpu->ebx = 0u;
    label_00053151: cpu->eip = LIFT_CODE_TOKEN_VA(0x453151u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp)) == (uint8_t)(2u)) goto label_0005317A;
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + cpu->ebx + 8u)));
    cpu->edx = (uint32_t)(cpu->edx + cpu->ebx + 8u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005317A;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00053178;
    lift_store8(cpu->ecx + cpu->ebp, 1u);
    label_00053178: cpu->eip = LIFT_CODE_TOKEN_VA(0x453178u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0005317A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45317Au);
    ++cpu->ecx;
    cpu->ebx += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053151;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00053187: cpu->eip = LIFT_CODE_TOKEN_VA(0x453187u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0005333D;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, 1u);
    label_000531A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4531A0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->eax + 0xFFFFFFFFu)) != (uint8_t)(1u)) goto label_00053325;
    cpu->ebp = cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->ebx = cpu->edi;
    lift_store8(cpu->edx + cpu->ebp + 0xFFFFFFFFu, 2u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000531D0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x531D0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000531D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4531D0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000531E4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x531E4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000531E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4531E4u);
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store16(cpu->eax + cpu->edx, cpu->ecx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00053207;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53207u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00053207: cpu->eip = LIFT_CODE_TOKEN_VA(0x453207u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_0005321B;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5321Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005321B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45321Bu);
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edx));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index), cpu->ebx);
    ++cpu->eax;
    ++cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053325;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = (uint32_t)(cpu->edx + 0x28u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00053260: cpu->eip = LIFT_CODE_TOKEN_VA(0x453260u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp)) != (uint8_t)(1u)) goto label_00053318;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053318;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053318;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053318;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->edx + cpu->ebp, 2u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000532C0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x532C0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000532C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4532C0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000532D4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x532D4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000532D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4532D4u);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    lift_store16(cpu->eax + ((uint32_t)(cpu->edi) * 2u), cpu->ebp & 0xFFFFu);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) >= (int32_t)(uint32_t)(0u)) goto label_000532EF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x532EFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000532EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4532EFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_00053307;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53307u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00053307: cpu->eip = LIFT_CODE_TOKEN_VA(0x453307u);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store16(cpu->ecx + cpu->eax, (uint64_t)(lift_load16(cpu->ecx + cpu->eax)) + 1u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    label_00053318: cpu->eip = LIFT_CODE_TOKEN_VA(0x453318u);
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053260;
    label_00053325: cpu->eip = LIFT_CODE_TOKEN_VA(0x453325u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000531A0;
    label_0005333D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45333Du);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45334Bu); lift_push32(cpu, r); sfera_sub_0044DB50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1448u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esi + 0x68B4u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453363u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x68A4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0005341D;
    lift_store32(cpu->esp + 0x24u, (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    (void)cpu;
    label_00053380: cpu->eip = LIFT_CODE_TOKEN_VA(0x453380u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00053394;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53394u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00053394: cpu->eip = LIFT_CODE_TOKEN_VA(0x453394u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000533A8;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x533A8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000533A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4533A8u);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx = lift_load32(cpu->esi + 0x68A4u);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->ebx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0005340E;
    label_000533C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4533C6u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ebp = (uint32_t)(cpu->eax + cpu->edi + 1u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000533DE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x533DEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000533DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4533DEu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000533F2;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x533F2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000533F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4533F2u);
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->ecx = lift_load32(cpu->esi + 0x68A4u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->ebp) * 2u))) & 0xFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000533C6;
    label_0005340E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45340Eu);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00053380;
    label_0005341D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45341Du);
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00053468;
    lift_x87_push(cpu, (double)0.009999999776482582f);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)-0.009999999776482582f);
    cpu->edi = 0u;
    label_00053436: cpu->eip = LIFT_CODE_TOKEN_VA(0x453436u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebx)) == (uint8_t)(2u)) goto label_0005345B;
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + cpu->edi)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005345B;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + cpu->edi)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00053459;
    lift_store8(cpu->ecx + cpu->ebx, 1u);
    label_00053459: cpu->eip = LIFT_CODE_TOKEN_VA(0x453459u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0005345B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45345Bu);
    ++cpu->ecx;
    cpu->edi += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053436;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00053468: cpu->eip = LIFT_CODE_TOKEN_VA(0x453468u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00053621;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, 1u);
    label_00053483: cpu->eip = LIFT_CODE_TOKEN_VA(0x453483u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->eax + 0xFFFFFFFFu)) != (uint8_t)(1u)) goto label_00053609;
    cpu->ebp = cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->ebx = cpu->edi;
    lift_store8(cpu->edx + cpu->ebp + 0xFFFFFFFFu, 2u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000534B3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x534B3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000534B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4534B3u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000534C7;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x534C7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000534C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4534C7u);
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store16(cpu->eax + cpu->edx, cpu->ecx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000534EA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x534EAu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000534EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4534EAu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000534FE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x534FEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000534FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4534FEu);
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edx + 8u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index), cpu->ebx);
    ++cpu->eax;
    ++cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053609;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = (uint32_t)(cpu->edx + 0x28u);
    cpu->edi = cpu->edi;
    label_00053540: cpu->eip = LIFT_CODE_TOKEN_VA(0x453540u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp)) != (uint8_t)(1u)) goto label_000535FC;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000535FC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000535FC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000535FC;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->edx + cpu->ebp, 2u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000535A4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x535A4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000535A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4535A4u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000535B8;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x535B8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000535B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4535B8u);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    lift_store16(cpu->eax + ((uint32_t)(cpu->edi) * 2u), cpu->ebp & 0xFFFFu);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) >= (int32_t)(uint32_t)(0u)) goto label_000535D3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x535D3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000535D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4535D3u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000535EB;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x535EBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000535EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4535EBu);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store16(cpu->ecx + cpu->eax, (uint64_t)(lift_load16(cpu->ecx + cpu->eax)) + 1u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    label_000535FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4535FCu);
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053540;
    label_00053609: cpu->eip = LIFT_CODE_TOKEN_VA(0x453609u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053483;
    label_00053621: cpu->eip = LIFT_CODE_TOKEN_VA(0x453621u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45362Fu); lift_push32(cpu, r); sfera_sub_0044DB50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1470u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esi + 0x68B8u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453647u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x68A8u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00053706;
    cpu->edx = cpu->ebp;
    lift_store32(cpu->esp + 0x24u, (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    label_00053665: cpu->eip = LIFT_CODE_TOKEN_VA(0x453665u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00053679;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53679u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00053679: cpu->eip = LIFT_CODE_TOKEN_VA(0x453679u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_0005368D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5368Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005368D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45368Du);
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = lift_load32(cpu->esi + 0x68A8u);
    lift_store16(cpu->edx + ((uint32_t)(cpu->ebx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->ebx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000536F7;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000536B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4536B0u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->edi + 1u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000536C8;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x536C8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000536C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4536C8u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000536DC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x536DCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000536DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4536DCu);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->edx = lift_load32(cpu->esi + 0x68A8u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + ((uint32_t)(cpu->ebp) * 2u))) & 0xFFFFu);
    lift_store16(cpu->edx + ((uint32_t)(cpu->ebx) * 2u), cpu->ecx & 0xFFFFu);
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000536B0;
    label_000536F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4536F7u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00053665;
    label_00053706: cpu->eip = LIFT_CODE_TOKEN_VA(0x453706u);
    cpu->edi = 0u;
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00053753;
    lift_x87_push(cpu, 100.01000213623047);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, 99.98999786376953);
    cpu->ebx = 0u;
    label_00053721: cpu->eip = LIFT_CODE_TOKEN_VA(0x453721u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp)) == (uint8_t)(2u)) goto label_00053746;
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ebx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00053746;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ebx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053746;
    lift_store8(cpu->ecx + cpu->ebp, 1u);
    label_00053746: cpu->eip = LIFT_CODE_TOKEN_VA(0x453746u);
    ++cpu->ecx;
    cpu->ebx += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053721;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00053753: cpu->eip = LIFT_CODE_TOKEN_VA(0x453753u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00053911;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00053770: cpu->eip = LIFT_CODE_TOKEN_VA(0x453770u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->eax + 0xFFFFFFFFu)) != (uint8_t)(1u)) goto label_000538F9;
    cpu->ebp = cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->ebx = cpu->edi;
    lift_store8(cpu->edx + cpu->ebp + 0xFFFFFFFFu, 2u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000537A0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x537A0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000537A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4537A0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000537B4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x537B4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000537B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4537B4u);
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store16(cpu->eax + cpu->edx, cpu->ecx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000537D7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x537D7u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000537D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4537D7u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000537EB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x537EBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000537EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4537EBu);
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edx + 8u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index), cpu->ebx);
    ++cpu->eax;
    ++cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000538F9;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = (uint32_t)(cpu->edx + 0x28u);
    label_00053830: cpu->eip = LIFT_CODE_TOKEN_VA(0x453830u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp)) != (uint8_t)(1u)) goto label_000538EC;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000538EC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000538EC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000538EC;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->edx + cpu->ebp, 2u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00053894;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53894u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00053894: cpu->eip = LIFT_CODE_TOKEN_VA(0x453894u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000538A8;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x538A8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000538A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4538A8u);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    lift_store16(cpu->eax + ((uint32_t)(cpu->edi) * 2u), cpu->ebp & 0xFFFFu);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) >= (int32_t)(uint32_t)(0u)) goto label_000538C3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x538C3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000538C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4538C3u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000538DB;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x538DBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000538DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4538DBu);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store16(cpu->ecx + cpu->eax, (uint64_t)(lift_load16(cpu->ecx + cpu->eax)) + 1u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    label_000538EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4538ECu);
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053830;
    label_000538F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4538F9u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00053770;
    label_00053911: cpu->eip = LIFT_CODE_TOKEN_VA(0x453911u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45391Fu); lift_push32(cpu, r); sfera_sub_0044DB50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1499u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esi + 0x68BCu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453937u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x68ACu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000539F7;
    lift_store32(cpu->esp + 0x24u, (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    label_00053953: cpu->eip = LIFT_CODE_TOKEN_VA(0x453953u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00053967;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53967u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00053967: cpu->eip = LIFT_CODE_TOKEN_VA(0x453967u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_0005397B;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5397Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005397B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45397Bu);
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx = lift_load32(cpu->esi + 0x68ACu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->ebx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000539E8;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000539A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4539A0u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ebp = (uint32_t)(cpu->eax + cpu->edi + 1u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000539B8;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x539B8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000539B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4539B8u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_mesh_partition_indices.capacity)) goto label_000539CC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x539CCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000539CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4539CCu);
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->ecx = lift_load32(cpu->esi + 0x68ACu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->ebp) * 2u))) & 0xFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000539A0;
    label_000539E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4539E8u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00053953;
    label_000539F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4539F7u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0x14A3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453A0Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00453A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x453A20u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x68B0u);
    cpu->ebp = 0u;
    lift_push32(cpu, 0x14CAu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453A4Fu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x68B0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x453A5Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x453A62u);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x68B0u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00053BC5;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00053A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x453A80u);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x68A0u);
    cpu->edx = lift_load16(cpu->eax + ((uint32_t)(cpu->ebp) * 2u));
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->ebp) * 2u) + 2u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    ++cpu->ebp;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->ebx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0x68B0u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00053B54;
    cpu->esi = lift_load32(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0x68A0u);
    label_00053AC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x453AC2u);
    cpu->edx = lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u) + 2u);
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00053B19;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00053B19;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053B39;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053B39;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_store8(cpu->ecx + cpu->edx, 1u);
    goto label_00053BA3;
    label_00053B19: cpu->eip = LIFT_CODE_TOKEN_VA(0x453B19u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00053B39;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00053C3B;
    label_00053B39: cpu->eip = LIFT_CODE_TOKEN_VA(0x453B39u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx += lift_load32(cpu->esp + 0x24u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x28u))) goto label_00053AC2;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_00053B54: cpu->eip = LIFT_CODE_TOKEN_VA(0x453B54u);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 8u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    cpu->esp -= 8u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->ecx = 0xFFu;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x24u, 1u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53BA3u); lift_push32(cpu, r); sfera_sub_00451460(cpu,r); if (cpu->eip != r) return; }
    label_00053BA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x453BA3u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->ebp += lift_load32(cpu->esp + 0x2Cu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x68B0u))) goto label_00053A80;
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    label_00053BC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x453BC5u);
    cpu->esi = 0u;
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x68B0u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00053CD5;
    lift_x87_push(cpu, 100.0);
    label_00053BDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x453BDCu);
    cpu->eax = lift_load32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x68A0u);
    cpu->edx = lift_load16(cpu->eax + ((uint32_t)(cpu->esi) * 2u));
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->esi) * 2u) + 2u);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)(lift_load8(cpu->edx + cpu->ebp)) != (uint8_t)(0u)) goto label_00053CC1;
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x38u)))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x38u)))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(3u)) goto label_00053C50;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    goto label_00053C5B;
    label_00053C3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x453C3Bu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_store8(cpu->eax + cpu->ecx, 1u);
    goto label_00053BA3;
    label_00053C50: cpu->eip = LIFT_CODE_TOKEN_VA(0x453C50u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(2u)) goto label_00053C5F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    label_00053C5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x453C5Bu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00053C5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x453C5Fu);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00053C6D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00053C7E;
    label_00053C6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x453C6Du);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(1u)) goto label_00053C7C;
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x38u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00053C7E;
    label_00053C7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x453C7Cu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00053C7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x453C7Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    cpu->esp -= 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x40u))));
    cpu->ecx = 0xFF00u;
    lift_store32(cpu->esp + 0x24u, 1u);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453CB7u); lift_push32(cpu, r); sfera_sub_00451460(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 100.0);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    label_00053CC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x453CC1u);
    cpu->esi += lift_load32(cpu->esp + 0x2Cu);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x68B0u))) goto label_00053BDC;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00053CD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x453CD5u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0x1509u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453CE8u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00453D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x453D00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xA8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xBCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esp + 0xD8u);
    cpu->eax = lift_load32(cpu->esp + 0xCCu);
    cpu->ecx = lift_load32(cpu->esp + 0xD0u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xDCu);
    lift_store32(cpu->esp + 0x38u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xE0u);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    if ((uint32_t)(cpu->edx) != 0u) goto label_00053D88;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00053D88;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000543DF;
    label_00053D88: cpu->eip = LIFT_CODE_TOKEN_VA(0x453D88u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x78u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453D99u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x453DA2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x453DA7u);
    cpu->esp += 0xCu;
    cpu->ebp = 0x32u;
    cpu->ebx = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esp + 0x50u, 0x1Eu);
    lift_store32(cpu->esp + 0x54u, cpu->ebp);
    lift_store32(cpu->esp + 0x58u, cpu->ebx);
    lift_store32(cpu->esp + 0x5Cu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453DD8u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = native_function_address32(&::strncpy);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x53DE6u), LIFT_CODE_TOKEN_RVA(0x53DE4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x453DE6u);
    cpu->esp += 0xCu;
    lift_store8(cpu->esp + 0x6Bu, 0u);
    lift_store32(cpu->esp + 0x7Cu, 0x1556u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_store32(cpu->esp + 0xC8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453E10u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x80u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->edx + 0xCu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->edx + 0x14u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store16(cpu->edx + 0x1Cu, cpu->ecx & 0xFFFFu);
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esp + 0x88u, 0x1Eu);
    lift_store32(cpu->esp + 0x8Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x90u, cpu->ebx);
    lift_store32(cpu->esp + 0x94u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x453E92u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x9Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x53E9Du), LIFT_CODE_TOKEN_RVA(0x53E9Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x453E9Du);
    cpu->esp += 0xCu;
    lift_store8(cpu->esp + 0xA3u, 0u);
    lift_store32(cpu->esp + 0xB4u, 0x1557u);
    cpu->edi = lift_load32(cpu->esp + 0xD4u);
    cpu->ebx = 0u;
    lift_store8(cpu->esp + 0xC4u, 1u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x688Cu)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00053F2D;
    label_00053ED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x453ED1u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_00053EE2;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53EE2u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00053EE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x453EE2u);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x687Cu);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u), cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_00053F14;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53F14u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00053F14: cpu->eip = LIFT_CODE_TOKEN_VA(0x453F14u);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store8(cpu->eax + cpu->ebx, 0u);
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x688Cu))) goto label_00053ED1;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    label_00053F2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x453F2Du);
    cpu->edi = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00053FA1;
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + ((uint32_t)(cpu->ebp) * 4u) + 0x688Cu)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00053FA1;
    label_00053F44: cpu->eip = LIFT_CODE_TOKEN_VA(0x453F44u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_00053F55;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53F55u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00053F55: cpu->eip = LIFT_CODE_TOKEN_VA(0x453F55u);
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->ebp) * 4u) + 0x687Cu);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u), cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_00053F87;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53F87u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00053F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x453F87u);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store8(cpu->eax + cpu->ebx, 0u);
    ++cpu->esi;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + ((uint32_t)(cpu->ebp) * 4u) + 0x688Cu))) goto label_00053F44;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    label_00053FA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x453FA1u);
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00054015;
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + ((uint32_t)(cpu->ebp) * 4u) + 0x688Cu)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00054015;
    label_00053FB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x453FB8u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_00053FC9;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53FC9u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00053FC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x453FC9u);
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->ebp) * 4u) + 0x687Cu);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u), cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_00053FFB;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x53FFBu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00053FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x453FFBu);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store8(cpu->eax + cpu->ebx, 0u);
    ++cpu->esi;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + ((uint32_t)(cpu->ebp) * 4u) + 0x688Cu))) goto label_00053FB8;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    label_00054015: cpu->eip = LIFT_CODE_TOKEN_VA(0x454015u);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0005408D;
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u) + 0x688Cu)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0005408D;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00054030: cpu->eip = LIFT_CODE_TOKEN_VA(0x454030u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_00054041;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54041u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00054041: cpu->eip = LIFT_CODE_TOKEN_VA(0x454041u);
    cpu->ecx = lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u) + 0x687Cu);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u), cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_00054073;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54073u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00054073: cpu->eip = LIFT_CODE_TOKEN_VA(0x454073u);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store8(cpu->eax + cpu->ebx, 0u);
    ++cpu->esi;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u) + 0x688Cu))) goto label_00054030;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    label_0005408D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45408Du);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00054371;
    label_00054097: cpu->eip = LIFT_CODE_TOKEN_VA(0x454097u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_000540AE;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x540AEu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000540AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4540AEu);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->edi)) == (uint8_t)(2u)) goto label_00054364;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_000540D6;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x540D6u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000540D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4540D6u);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store8(cpu->edx + cpu->edi, 1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_000540F2;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x540F2u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000540F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4540F2u);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->eax = lift_load32(cpu->eax + 0x14u);
    cpu->esi = (uint32_t)(cpu->edi + 1u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00054281;
    label_00054119: cpu->eip = LIFT_CODE_TOKEN_VA(0x454119u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_00054130;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54130u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00054130: cpu->eip = LIFT_CODE_TOKEN_VA(0x454130u);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) == (uint8_t)(2u)) goto label_00054274;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_00054152;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54152u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00054152: cpu->eip = LIFT_CODE_TOKEN_VA(0x454152u);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_0005416E;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5416Eu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005416E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45416Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_0005418A;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5418Au); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005418A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45418Au);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_000541A6;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x541A6u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000541A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4541A6u);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    cpu->ebx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_000541BE;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x541BEu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000541BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4541BEu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_000541D6;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x541D6u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_000541D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4541D6u);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    cpu->eax = lift_load32(cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->ecx = lift_load32(cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx))));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
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
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00054274;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_00054230;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54230u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00054230: cpu->eip = LIFT_CODE_TOKEN_VA(0x454230u);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store8(cpu->edx + cpu->esi, 1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_0005424C;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5424Cu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005424C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45424Cu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00054274: cpu->eip = LIFT_CODE_TOKEN_VA(0x454274u);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00054119;
    label_00054281: cpu->eip = LIFT_CODE_TOKEN_VA(0x454281u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4542ACu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
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
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00054364;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000542F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4542F0u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_00054307;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54307u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00054307: cpu->eip = LIFT_CODE_TOKEN_VA(0x454307u);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(1u)) goto label_0005435F;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x84u))) goto label_0005432B;
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5432Bu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0005432B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45432Bu);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store8(cpu->edx + cpu->esi, 2u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4Cu))) goto label_00054347;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54347u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_00054347: cpu->eip = LIFT_CODE_TOKEN_VA(0x454347u);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store32(cpu->eax + 0x14u, cpu->ebp);
    label_0005435F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45435Fu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000542F0;
    label_00054364: cpu->eip = LIFT_CODE_TOKEN_VA(0x454364u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00054097;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    label_00054371: cpu->eip = LIFT_CODE_TOKEN_VA(0x454371u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00054385;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store8(cpu->ecx + cpu->eax + 0x689Cu, 1u);
    label_00054385: cpu->eip = LIFT_CODE_TOKEN_VA(0x454385u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00054399;
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store8(cpu->edx + cpu->eax + 0x689Cu, 1u);
    label_00054399: cpu->eip = LIFT_CODE_TOKEN_VA(0x454399u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000543A9;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store8(cpu->eax + cpu->ebp + 0x689Cu, 1u);
    label_000543A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4543A9u);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_store8(cpu->esp + 0xC8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4543C4u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_store32(cpu->esp + 0xC8u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x543DFu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_000543DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4543DFu);
    cpu->ecx = lift_load32(cpu->esp + 0xBCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454410u);
    cpu->esp -= 0x38u;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1B20u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45444Cu); lift_push32(cpu, r); sfera_sub_0044DC10(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_x)) goto label_000549A2;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_x)) goto label_000549A2;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_y)) goto label_000549A2;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_y)) goto label_000549A2;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_z)) goto label_000549A2;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_z)) goto label_000549A2;
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4544C7u); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000549A2;
    cpu->edx = (uint32_t)(cpu->ebx + 0x1D78u);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    cpu->ebp = (uint32_t)(cpu->ebx + 0x24F8u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1B98u);
    g_sfera_landscape_patch_lookup_runtime.visible_count = (uint32_t)(0u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->ebp);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x34u, 4u);
    label_00054510: cpu->eip = LIFT_CODE_TOKEN_VA(0x454510u);
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454539u); lift_push32(cpu, r); sfera_sub_0044DC10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_x)) goto label_00054800;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_x)) goto label_00054800;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_y)) goto label_00054800;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_y)) goto label_00054800;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_z)) goto label_00054800;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_z)) goto label_00054800;
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4545B4u); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00054800;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, 4u);
    label_000545E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4545E0u);
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454609u); lift_push32(cpu, r); sfera_sub_0044DC10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_x)) goto label_000547D5;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_x)) goto label_000547D5;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_y)) goto label_000547D5;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_y)) goto label_000547D5;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_z)) goto label_000547D5;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_z)) goto label_000547D5;
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454684u); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000547D5;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x1Cu, 9u);
    label_000546A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4546A0u);
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4546CBu); lift_push32(cpu, r); sfera_sub_0044DC10(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_x)) goto label_000547C1;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_x)) goto label_000547C1;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_y)) goto label_000547C1;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_y)) goto label_000547C1;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.min_z)) goto label_000547C1;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(g_sfera_view_geometry_runtime.clipping_bounds.max_z)) goto label_000547C1;
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454746u); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000547C1;
    cpu->esi = g_sfera_landscape_patch_lookup_runtime.visible_count;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005475E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5475Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005475E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45475Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_indices.capacity)) goto label_00054772;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54772u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054772: cpu->eip = LIFT_CODE_TOKEN_VA(0x454772u);
    cpu->edx = g_sfera_light_runtime.cell_indices.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->ebx);
    cpu->esi = g_sfera_landscape_patch_lookup_runtime.visible_count;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005478F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5478Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005478F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45478Fu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_light_runtime.cell_records.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000547A3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x547A3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000547A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4547A3u);
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    cpu->edi += g_sfera_light_runtime.cell_records.data;
    cpu->ecx = 0x18u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime;
    lift_movs32(cpu, 1u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.visible_count, (uint64_t)(g_sfera_landscape_patch_lookup_runtime.visible_count) + 1u);
    label_000547C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4547C1u);
    cpu->ebp += 0x78u;
    cpu->ebx += 0x30u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x1Cu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000546A0;
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    label_000547D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4547D5u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x1B0u) + (uint64_t)(0u));
    cpu->ecx += 0x78u;
    cpu->ebp += 0x438u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x28u, v); }
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000545E0;
    label_00054800: cpu->eip = LIFT_CODE_TOKEN_VA(0x454800u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x6C0u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x1E0u) + (uint64_t)(0u));
    cpu->ecx += 0x78u;
    cpu->ebp += 0x10E0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x34u, v); }
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00054510;
    cpu->eax = g_sfera_landscape_patch_lookup_runtime.visible_count;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edi)) goto label_000549A2;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_00054846: cpu->eip = LIFT_CODE_TOKEN_VA(0x454846u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00054854;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54854u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00054854: cpu->eip = LIFT_CODE_TOKEN_VA(0x454854u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_indices.capacity)) goto label_00054868;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54868u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054868: cpu->eip = LIFT_CODE_TOKEN_VA(0x454868u);
    cpu->eax = g_sfera_light_runtime.cell_indices.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->ebx + 0x1B1Cu);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->ebp = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00054990;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0005489C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5489Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005489C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45489Cu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_000548B0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x548B0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000548B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4548B0u);
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + 0x10u)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00054990;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000548DB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x548DBu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000548DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4548DBu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_records.capacity)) goto label_000548EF;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x548EFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000548EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4548EFu);
    cpu->esi = g_sfera_light_runtime.cell_records.data;
    cpu->esi += lift_load32(cpu->esp + 0x18u);
    cpu->edx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00054910;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54910u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054910: cpu->eip = LIFT_CODE_TOKEN_VA(0x454910u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45495Eu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_x));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005498E;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_window_runtime.distance_scratch.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00054990;
    label_0005498E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45498Eu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00054990: cpu->eip = LIFT_CODE_TOKEN_VA(0x454990u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x60u) + (uint64_t)(0u));
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_landscape_patch_lookup_runtime.visible_count)) goto label_00054846;
    label_000549A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4549A2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004549B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4549B0u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00054A08;
    cpu->edi = g_sfera_world_objects.controlled_object_handle;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00054A08;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000549D6;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x549D6u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000549D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4549D6u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000549EA;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x549EAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000549EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4549EAu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esi, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00054A08: cpu->eip = LIFT_CODE_TOKEN_VA(0x454A08u);
    cpu->edx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00054A1F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54A1Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054A1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x454A1Fu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->esi, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454A40u);
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00054B92;
    lift_x87_push(cpu, 255.0);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::specular);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->ebx);
    label_00054A63: cpu->eip = LIFT_CODE_TOKEN_VA(0x454A63u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454A81u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454A8Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454A99u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0xFFu;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00054AA4;
    cpu->ebx = cpu->ecx;
    label_00054AA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x454AA4u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00054AAE;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_00054AAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x454AAEu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00054AB4;
    cpu->eax = cpu->ecx;
    label_00054AB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x454AB4u);
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.render_samples[0]));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->edx = cpu->ebx & 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load8(cpu->esp + 0x10u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->ecx);
    lift_store32(cpu->esi, 0u);
    cpu->esi += 0x20u;
    cpu->edi += 4u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(sfera_screen_vertex_field_end_address(g_sfera_sky_screen_vertices, &SferaScreenVertex::specular)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00054A63;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454B00u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(uintptr_t)"auto";
    cpu->eax = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00054B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x454B10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00054B30;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_00054B2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00054B30;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00054B10;
    label_00054B2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x454B2Cu);
    cpu->eax = 0u;
    goto label_00054B35;
    label_00054B30: cpu->eip = LIFT_CODE_TOKEN_VA(0x454B30u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00054B35: cpu->eip = LIFT_CODE_TOKEN_VA(0x454B35u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00054B55;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454B40u); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454B4Eu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54B55u); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    label_00054B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x454B55u);
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x18u), 32u, 1u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0x65u);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[0]);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454B85u); lift_push32(cpu, r); sfera_sub_004D8FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454B90u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00054B92: cpu->eip = LIFT_CODE_TOKEN_VA(0x454B92u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454BA0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00054DB4;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.render_samples[1];
    cpu->eax = sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::diffuse);
    lift_push32(cpu, cpu->esi);
    label_00054BC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x454BC0u);
    cpu->ecx = lift_load32(cpu->edx + 0xFFFFFFFCu);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ebp = cpu->esi;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->esi &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->esi;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    lift_store32(cpu->eax + 4u, cpu->ebp);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ebp = cpu->esi;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->esi &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->esi;
    lift_store32(cpu->eax + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    lift_store32(cpu->eax + 0x24u, cpu->ebp);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ebp = cpu->esi;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx |= 0xFFFFFF00u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->esi;
    lift_store32(cpu->eax + 0x40u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    lift_store32(cpu->eax + 0x44u, cpu->ebp);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ebp = cpu->esi;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx |= 0xFFFFFF00u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->esi;
    cpu->esi |= 0xFFFFFFFFu;
    lift_store32(cpu->eax + 0x60u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0xCu);
    lift_store32(cpu->eax + 0x64u, cpu->ebp);
    cpu->esi -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ebp = cpu->esi;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->esi &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->esi;
    lift_store32(cpu->eax + 0x80u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    lift_store32(cpu->eax + 0x84u, cpu->ebp);
    cpu->ebp = cpu->esi;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->esi &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->esi;
    lift_store32(cpu->eax + 0xA4u, cpu->ebp);
    lift_store32(cpu->eax + 0xA0u, cpu->ecx);
    cpu->edx += 0x18u;
    cpu->eax += 0xC0u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.lighting_state))) goto label_00054BC0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454D3Du); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454D4Cu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454D53u); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454D61u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454D68u); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0x65u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_sky_runtime.indices[0]);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454D96u); lift_push32(cpu, r); sfera_sub_004D8FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454DA5u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_004D91E0(cpu, stop_address); return;
    label_00054DB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x454DB4u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454DC0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0u)) goto label_00054DED;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xACu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->esi + 0xACu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00054DED;
    lift_store8((uintptr_t)&g_sfera_startup_command_line_runtime.text[0x148], 0u);
    lift_store8((uintptr_t)&g_sfera_view_render_objects_runtime.reset_flag, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00054DED: cpu->eip = LIFT_CODE_TOKEN_VA(0x454DEDu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x158u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454DFDu); lift_push32(cpu, r); sfera_sub_0044E480(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esi + 0xACu);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454E0Cu); lift_push32(cpu, r); sfera_sub_00454BA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_00054E28;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454E1Cu); lift_push32(cpu, r); sfera_sub_0044E6A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54E28u); lift_push32(cpu, r); sfera_sub_00454A40(cpu,r); if (cpu->eip != r) return; }
    label_00054E28: cpu->eip = LIFT_CODE_TOKEN_VA(0x454E28u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454E30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00054E78;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00054E4B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54E4Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054E4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x454E4Bu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00054E78;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00054E6A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54E6Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054E6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x454E6Au);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax += 8u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00054E78: cpu->eip = LIFT_CODE_TOKEN_VA(0x454E78u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->eax;
    label_00054E85: cpu->eip = LIFT_CODE_TOKEN_VA(0x454E85u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00054E85;
    cpu->edx = lift_load32((uintptr_t)"GetPos: wrong handle");
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetPos: wrong handle") + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetPos: wrong handle") + 8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetPos: wrong handle") + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetPos: wrong handle") + 0x10u);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"GetPos: wrong handle") + 0x14u)) & 0xFFu);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store8(cpu->eax + 0x14u, cpu->ecx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454EC7u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454ED0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00054F18;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00054EEB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54EEBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054EEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x454EEBu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00054F18;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00054F0A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54F0Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054F0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x454F0Au);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax += 0x14u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00054F18: cpu->eip = LIFT_CODE_TOKEN_VA(0x454F18u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->eax;
    label_00054F25: cpu->eip = LIFT_CODE_TOKEN_VA(0x454F25u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00054F25;
    cpu->edx = lift_load32((uintptr_t)"GetAngles: wrong handle");
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetAngles: wrong handle") + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetAngles: wrong handle") + 8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetAngles: wrong handle") + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"GetAngles: wrong handle") + 0x10u);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"GetAngles: wrong handle") + 0x14u);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454F67u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454F70u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00054FB5;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00054F8B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54F8Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054F8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x454F8Bu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00054FB5;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00054FAA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x54FAAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00054FAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x454FAAu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00054FB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x454FB5u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00054FC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x454FC3u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00054FC3;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetObjectPointer: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x454FDFu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00454FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x454FF0u);
    cpu->esp -= 0xD4u;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    cpu->esi = cpu->edx;
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    cpu->ebx = cpu->esi;
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0xACu);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_world_render_runtime.active_model;
    cpu->ebx += lift_load32(cpu->edi + 0x3Cu);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00055054;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45504Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = g_sfera_world_render_runtime.active_model;
    label_00055054: cpu->eip = LIFT_CODE_TOKEN_VA(0x455054u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_scene_array_runtime.model_matrices.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0005506E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455068u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = g_sfera_world_render_runtime.active_model;
    label_0005506E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45506Eu);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(6u), 32u);
    cpu->esi += g_sfera_scene_array_runtime.model_matrices.data;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x25u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x4Cu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000550A4;
    cpu->eax = lift_load16(cpu->ebx + 0x26u);
    cpu->edx = lift_load32(cpu->edi + 0x54u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = 7u;
    cpu->edi = (uint32_t)(cpu->esp + 0x2Cu);
    lift_movs32(cpu, 1u);
    goto label_00055358;
    label_000550A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4550A4u);
    cpu->ecx = lift_load16(cpu->ebx + 0x26u);
    cpu->ecx += g_sfera_client_main_scalar_runtime.state_06;
    cpu->edx = lift_load32(cpu->edi + 0x58u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 2u)) & 0xFFu);
    cpu->eax = lift_load16(cpu->eax);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->edi + 0x54u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0xFFu)) goto label_000550E2;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->esi = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = 7u;
    cpu->edi = (uint32_t)(cpu->esp + 0x30u);
    lift_movs32(cpu, 1u);
    goto label_00055198;
    label_000550E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4550E2u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->ecx & 0xFFu;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->edx) * 4u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    cpu->edx = (uint32_t)(cpu->esi + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00390625));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45511Cu); lift_push32(cpu, r); sfera_sub_0044BC70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    cpu->edx = lift_load32(cpu->edi + 0x58u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    label_00055198: cpu->eip = LIFT_CODE_TOKEN_VA(0x455198u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled)) == (uint32_t)(0u)) goto label_00055357;
    if ((uint8_t)(lift_load8(cpu->ebx + 0x24u)) != (uint8_t)(0u)) goto label_00055357;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(cpu->esp + 0x30u);
    cpu->edi = (uint32_t)(cpu->esp + 0x70u);
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load16(cpu->ebx + 0x26u);
    cpu->ecx += g_sfera_render_sample_runtime.material_base;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 2u)) & 0xFFu);
    cpu->eax = lift_load16(cpu->eax);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0xFFu)) goto label_000551F5;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->esi = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = 7u;
    cpu->edi = (uint32_t)(cpu->esp + 0x54u);
    lift_movs32(cpu, 1u);
    goto label_000552A8;
    label_000551F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4551F5u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->ecx & 0xFFu;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->edx) * 4u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    cpu->edx = (uint32_t)(cpu->esi + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00390625));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45522Fu); lift_push32(cpu, r); sfera_sub_0044BC70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->esp + 0x54u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x5Cu, cpu->ecx);
    label_000552A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4552A8u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4552C7u); lift_push32(cpu, r); sfera_sub_0044BC70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    label_00055357: cpu->eip = LIFT_CODE_TOKEN_VA(0x455357u);
    cpu->ebp = lift_pop32(cpu);
    label_00055358: cpu->eip = LIFT_CODE_TOKEN_VA(0x455358u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->edx = (uint32_t)(cpu->esp + 0x6Cu);
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455386u); lift_push32(cpu, r); sfera_sub_0044BB80(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x9Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x98u));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45544Fu); lift_push32(cpu, r); sfera_sub_0044B920(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->esp + 0x9Cu);
    lift_movs32(cpu, 1u);
    cpu->eax = lift_load8(cpu->ebx + 0x28u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x64u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000554C2;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00055499;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000554E9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.frame_102_position.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.frame_102_position.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.frame_102_position.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000554E9;
    label_00055499: cpu->eip = LIFT_CODE_TOKEN_VA(0x455499u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.frame_101_position.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.frame_101_position.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.frame_101_position.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000554E9;
    label_000554C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4554C2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.transform_scratch.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.transform_scratch.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.transform_scratch.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000554E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4554E9u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x28u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) >= (uint8_t)(5u)) goto label_0005552C;
    cpu->edi = cpu->eax & 0xFFu;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00055501;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55501u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00055501: cpu->eip = LIFT_CODE_TOKEN_VA(0x455501u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(g_sfera_scene_array_runtime.character_matrices.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00055515;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55515u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055515: cpu->eip = LIFT_CODE_TOKEN_VA(0x455515u);
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(6u), 32u);
    cpu->edi += g_sfera_scene_array_runtime.character_matrices.data;
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->esp + 0x9Cu);
    lift_movs32(cpu, 1u);
    label_0005552C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45552Cu);
    cpu->esi = 0u;
    if ((uint8_t)(lift_load8(cpu->ebx + 0x21u)) <= (uint8_t)(0u)) goto label_00055568;
    label_00055540: cpu->eip = LIFT_CODE_TOKEN_VA(0x455540u);
    cpu->ecx = g_sfera_world_render_runtime.active_model;
    cpu->eax = lift_load8(cpu->ebx + 0x22u);
    cpu->edx = lift_load32(cpu->ecx + 0x4Cu);
    cpu->edx += cpu->eax;
    cpu->edx = lift_load8(cpu->edx + cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x9Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45555Fu); lift_push32(cpu, r); sfera_sub_00454FF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load8(cpu->ebx + 0x21u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_00055540;
    label_00055568: cpu->eip = LIFT_CODE_TOKEN_VA(0x455568u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455580u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    (void)cpu;
    label_000555A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4555A0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    cpu->ebx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0x40u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    goto label_000555D3;
    label_000555CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4555CDu);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    label_000555D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4555D3u);
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->ecx += cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 8u) + 0x3Cu);
    label_000555DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4555DCu);
    cpu->eax = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    ++cpu->ebx;
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    cpu->ecx += 0x50u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000555DC;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    --cpu->ebx;
    cpu->eax += cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0x3Cu);
    label_00055602: cpu->eip = LIFT_CODE_TOKEN_VA(0x455602u);
    cpu->eax = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    --cpu->edx;
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    cpu->ecx -= 0x50u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00055602;
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00055671;
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->esi += cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = 0x14u;
    cpu->edi = (uint32_t)(cpu->esp + 0x18u);
    lift_movs32(cpu, 1u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax += cpu->eax;
    cpu->esi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = 0x14u;
    lift_movs32(cpu, 1u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    ++cpu->ebx;
    --cpu->edx;
    cpu->ecx = 0x14u;
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_movs32(cpu, 1u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000555CD;
    label_00055671: cpu->eip = LIFT_CODE_TOKEN_VA(0x455671u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_00055680;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55680u); lift_push32(cpu, r); sfera_sub_00455580(cpu,r); if (cpu->eip != r) return; }
    label_00055680: cpu->eip = LIFT_CODE_TOKEN_VA(0x455680u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_00055691;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    goto label_000555A0;
    label_00055691: cpu->eip = LIFT_CODE_TOKEN_VA(0x455691u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004556B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4556B0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000556C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4556C0u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000556CE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x556CEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000556CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4556CEu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_000556E2;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x556E2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000556E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4556E2u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u))) == (uint32_t)(0u)) goto label_000556F0;
    ++cpu->ebx;
    goto label_000556C0;
    label_000556F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4556F0u);
    lift_push32(cpu, 0x2E2Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x6E0Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455704u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00055714;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55714u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00055714: cpu->eip = LIFT_CODE_TOKEN_VA(0x455714u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00055728;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55728u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055728: cpu->eip = LIFT_CODE_TOKEN_VA(0x455728u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u), cpu->esi);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->eax -= cpu->ebp;
    cpu->edx = 1u;
    cpu->eax += cpu->edx;
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi + 0x28u, cpu->ecx);
    lift_store32(cpu->esi + 0x18u, cpu->ecx);
    cpu->ecx -= cpu->edi;
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    cpu->ecx += cpu->edx;
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    lift_store32(cpu->esi + 0x6E08u, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esi + 0xCu, cpu->ebp);
    lift_store32(cpu->esi + 0x30u, cpu->ecx);
    lift_store32(cpu->esi, cpu->edx);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    lift_store32(cpu->esi + 0x6DA4u, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->esi + 0x44u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = 0x1B58u;
    lift_stos32(cpu, 1u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.window_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004557C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4557C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000557D4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x557D4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000557D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4557D4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_000557E8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x557E8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000557E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4557E8u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_000557FE;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 75248635";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x557FEu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000557FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4557FEu);
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x44u)) != (uint32_t)(0xFFFFFFFFu)) goto label_0005580F;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 86557243";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5580Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005580F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45580Fu);
    lift_store32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x44u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x40u, (uint64_t)(lift_load32(cpu->esi + 0x40u)) - 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455820u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00055865;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005583B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5583Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005583B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45583Bu);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00055865;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0005585A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5585Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005585A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45585Au);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00055865: cpu->eip = LIFT_CODE_TOKEN_VA(0x455865u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00055873: cpu->eip = LIFT_CODE_TOKEN_VA(0x455873u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00055873;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetWindowPointer: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45588Fu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004558A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4558A0u);
    cpu->esp -= 0x54u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00055BD8;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000558D8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x558D8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000558D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4558D8u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00055BD8;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000558FB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x558FBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000558FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4558FBu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455913u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->esi = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_store32(cpu->esp + 0x48u, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->eax + 0x6Cu)) != (uint32_t)(0u)) goto label_0005593F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x74u));
    goto label_00055945;
    label_0005593F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45593Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x8Cu));
    label_00055945: cpu->eip = LIFT_CODE_TOKEN_VA(0x455945u);
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00055965;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55965u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055965: cpu->eip = LIFT_CODE_TOKEN_VA(0x455965u);
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = g_sfera_world_objects.object_handles.data;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00055983;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55983u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055983: cpu->eip = LIFT_CODE_TOKEN_VA(0x455983u);
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (0.10000000149011612) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00055A56;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55A56u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055A56: cpu->eip = LIFT_CODE_TOKEN_VA(0x455A56u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00055AA6;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    label_00055AA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x455AA6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455ADAu); lift_push32(cpu, r); sfera_sub_0042F7D0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->esi = cpu->eax;
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00055B14;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->edi, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->edx);
    lift_store32(cpu->edi + 8u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 4u, stop_address); return;
    label_00055B14: cpu->eip = LIFT_CODE_TOKEN_VA(0x455B14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455B28u); lift_push32(cpu, r); sfera_sub_0042F7D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00055C00;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_00055C00;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->edi, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x44u))));
    cpu->eax = cpu->esi;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->edi + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + 8u, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 4u, stop_address); return;
    label_00055BD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x455BD8u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00055BE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x455BE5u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00055BE5;
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)"Project_TopCharToScreen: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55C00u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_00055C00: cpu->eip = LIFT_CODE_TOKEN_VA(0x455C00u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x54u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455C20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00055C31;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55C31u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00055C31: cpu->eip = LIFT_CODE_TOKEN_VA(0x455C31u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00055C45;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55C45u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055C45: cpu->eip = LIFT_CODE_TOKEN_VA(0x455C45u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00055C7B;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)((cpu->eax & 0xFFu));
    --cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00055C60: cpu->eip = LIFT_CODE_TOKEN_VA(0x455C60u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00055C60;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"delete_sprite: wrong handle";
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    sfera_sub_0044F500(cpu, stop_address); return;
    label_00055C7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x455C7Bu);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455C86u); lift_push32(cpu, r); sfera_sub_004557C0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00055C94;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55C94u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00055C94: cpu->eip = LIFT_CODE_TOKEN_VA(0x455C94u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00055CA8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55CA8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055CA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x455CA8u);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, 0x30CCu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455CC0u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00055CCE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55CCEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00055CCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x455CCEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00055CE2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55CE2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055CE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x455CE2u);
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), 0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_sample_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) - 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455D00u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x3Cu));
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x40u));
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x44u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x48u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455D36u); lift_push32(cpu, r); sfera_sub_00451A40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00055D45;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
    label_00055D45: cpu->eip = LIFT_CODE_TOKEN_VA(0x455D45u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, 3u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    cpu->esi += 0x30u;
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455D6Cu); lift_push32(cpu, r); sfera_sub_00451B40(cpu,r); if (cpu->eip != r) return; }
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455D80u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00055D92;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55D92u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00055D92: cpu->eip = LIFT_CODE_TOKEN_VA(0x455D92u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00055DA6;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55DA6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055DA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x455DA6u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x24u)) == (uint32_t)(0xF4240u)) goto label_00055DF1;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_world_load_runtime.live_object_count, (uint64_t)(g_sfera_world_load_runtime.live_object_count) - 1u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->edi + 0x24u);
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x28u))) goto label_00055DF0;
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00055DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x455DD0u);
    cpu->esi = lift_load32(cpu->edi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->eax)) goto label_00055DE9;
    label_00055DD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x455DD7u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455DE1u); lift_push32(cpu, r); sfera_sub_00489BA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00055DD7;
    label_00055DE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x455DE9u);
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x28u))) goto label_00055DD0;
    cpu->esi = lift_pop32(cpu);
    label_00055DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x455DF0u);
    cpu->ebx = lift_pop32(cpu);
    label_00055DF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x455DF1u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455E00u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00055E11;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55E11u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00055E11: cpu->eip = LIFT_CODE_TOKEN_VA(0x455E11u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00055E2F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455E25u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00055E2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x455E2Fu);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455E40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00055E9A;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00055E5E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55E5Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055E5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x455E5Eu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00055E9A;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00055E7D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55E7Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055E7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x455E7Du);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->ebx, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->ebx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00055E9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x455E9Au);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00055EA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x455EA8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00055EA8;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"GetObjectPos: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455EC4u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00055EDC;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55EDCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055EDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x455EDCu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ebx, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ebx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 8u, cpu->eax);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455F00u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00055F80;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00055F1F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55F1Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055F1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x455F1Fu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00055F80;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00055F3E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55F3Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055F3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x455F3Eu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00055F5B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55F5Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055F5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x455F5Bu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx += 0x14u;
    cpu->ecx += 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455F71u); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ebx + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00055F80: cpu->eip = LIFT_CODE_TOKEN_VA(0x455F80u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00055F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x455F90u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00055F90;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"GetObjectOrient: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x455FABu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x455FB0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x455FB5u);
    lift_x87_push(cpu, 1.0);
    cpu->esp += 0xCu;
    lift_store_f32(cpu->ebx + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00455FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x455FD0u);
    cpu->edx = 1u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00055FEA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x55FEAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00055FEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x455FEAu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456010u);
    cpu->edx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00056030;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x456027u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_return(cpu, 0u, stop_address); return;
    label_00056030: cpu->eip = LIFT_CODE_TOKEN_VA(0x456030u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456040u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056054;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56054u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056054: cpu->eip = LIFT_CODE_TOKEN_VA(0x456054u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00056068;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56068u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056068: cpu->eip = LIFT_CODE_TOKEN_VA(0x456068u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x10Cu);
    label_00056078: cpu->eip = LIFT_CODE_TOKEN_VA(0x456078u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(0xFFFFFFFFu)) goto label_0005608B;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xAu)) goto label_00056078;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0005608B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45608Bu);
    lift_store32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x10Cu, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004560A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4560A0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000560B4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x560B4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000560B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4560B4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000560C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x560C8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000560C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4560C8u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_000560FB;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x10Cu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000560E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4560E0u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->edi)) goto label_000560F0;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xAu)) goto label_000560E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000560F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4560F0u);
    lift_store32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x10Cu, 0xFFFFFFFFu);
    label_000560FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4560FBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456100u);
    { uint64_t l=cpu->esp, r=(uint64_t)(0x10u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_00056110: cpu->eip = LIFT_CODE_TOKEN_VA(0x456110u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (uint32_t)(cpu->edi + cpu->edx);
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00056127;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56127u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056127: cpu->eip = LIFT_CODE_TOKEN_VA(0x456127u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_0005613B;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5613Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005613B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45613Bu);
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x38u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00056154: cpu->eip = LIFT_CODE_TOKEN_VA(0x456154u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00056162;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56162u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056162: cpu->eip = LIFT_CODE_TOKEN_VA(0x456162u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_00056176;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56176u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056176: cpu->eip = LIFT_CODE_TOKEN_VA(0x456176u);
    cpu->edx = g_sfera_light_runtime.visible_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x38u));
    ++cpu->edi;
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00056154;
    --cpu->edi;
    label_000561A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4561A0u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000561AE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x561AEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000561AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4561AEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_000561C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x561C2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000561C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4561C2u);
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x38u));
    --cpu->esi;
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000561A0;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->esi)) goto label_000562A5;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000561FD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x561FDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000561FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4561FDu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_00056211;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56211u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056211: cpu->eip = LIFT_CODE_TOKEN_VA(0x456211u);
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    cpu->ebp = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056227;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56227u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056227: cpu->eip = LIFT_CODE_TOKEN_VA(0x456227u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_0005623B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5623Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005623B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45623Bu);
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    cpu->ebx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00056252;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56252u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056252: cpu->eip = LIFT_CODE_TOKEN_VA(0x456252u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_00056266;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56266u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056266: cpu->eip = LIFT_CODE_TOKEN_VA(0x456266u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u), cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005627E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5627Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005627E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45627Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_00056292;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56292u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056292: cpu->eip = LIFT_CODE_TOKEN_VA(0x456292u);
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->ebp);
    ++cpu->edi;
    --cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00056154;
    label_000562A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4562A5u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000562B4;
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x562B4u); lift_push32(cpu, r); sfera_sub_00456100(cpu,r); if (cpu->eip != r) return; }
    label_000562B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4562B4u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000562C5;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    goto label_00056110;
    label_000562C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4562C5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004562D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4562D0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    label_000562D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4562D4u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000562E2;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x562E2u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000562E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4562E2u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_000562F6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x562F6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000562F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4562F6u);
    cpu->eax = g_sfera_light_runtime.handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00056304;
    ++cpu->esi;
    goto label_000562D4;
    label_00056304: cpu->eip = LIFT_CODE_TOKEN_VA(0x456304u);
    lift_push32(cpu, 0x397Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x3Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x456318u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056328;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56328u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056328: cpu->eip = LIFT_CODE_TOKEN_VA(0x456328u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_0005633C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5633Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005633C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45633Cu);
    cpu->ecx = g_sfera_light_runtime.handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->edi);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->edi, cpu->edx);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP2();
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edi + 0xCu, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edi + 0x14u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->edi + 0x18u, cpu->edx);
    cpu->eax = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00056390;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)10.0f);
    label_00056390: cpu->eip = LIFT_CODE_TOKEN_VA(0x456390u);
    lift_store_f32(cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.client_state_02, (uint64_t)(g_sfera_recovered_static_runtime.client_state_02) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 32u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004563A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4563A0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0005641B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_000563BB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x563BBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000563BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4563BBu);
    cpu->eax = g_sfera_light_runtime.handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0005641B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_000563DA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x563DAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000563DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4563DAu);
    cpu->ecx = g_sfera_light_runtime.handles.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, 0x398Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4563F2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_00056406;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56406u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056406: cpu->eip = LIFT_CODE_TOKEN_VA(0x456406u);
    cpu->edx = g_sfera_light_runtime.handles.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), 0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.client_state_02, (uint64_t)(g_sfera_recovered_static_runtime.client_state_02) - 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0005641B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45641Bu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00056430: cpu->eip = LIFT_CODE_TOKEN_VA(0x456430u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00056430;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"DeleteLight: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    sfera_sub_0044F500(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456450u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_00056453: cpu->eip = LIFT_CODE_TOKEN_VA(0x456453u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056461;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56461u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056461: cpu->eip = LIFT_CODE_TOKEN_VA(0x456461u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00056475;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56475u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056475: cpu->eip = LIFT_CODE_TOKEN_VA(0x456475u);
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), 0u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x1Fu)) goto label_00056453;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004564A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4564A0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x9Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_000564C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4564C5u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->edi = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000564DD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x564DDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000564DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4564DDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_000564F1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x564F1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000564F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4564F1u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x74u);
    cpu->eax += g_sfera_scene_array_runtime.scene_records.data;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056512;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45650Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_00056512: cpu->eip = LIFT_CODE_TOKEN_VA(0x456512u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_0005652A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x456526u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_0005652A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45652Au);
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    cpu->esi = lift_load32(cpu->esi + cpu->ecx + 0x10u);
    cpu->esi += lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    cpu->edi = cpu->edi;
    label_00056540: cpu->eip = LIFT_CODE_TOKEN_VA(0x456540u);
    cpu->esi = cpu->edi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    label_00056545: cpu->eip = LIFT_CODE_TOKEN_VA(0x456545u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00056553;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56553u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056553: cpu->eip = LIFT_CODE_TOKEN_VA(0x456553u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_00056567;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56567u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056567: cpu->eip = LIFT_CODE_TOKEN_VA(0x456567u);
    cpu->edx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00056582;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56582u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056582: cpu->eip = LIFT_CODE_TOKEN_VA(0x456582u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_00056596;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56596u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056596: cpu->eip = LIFT_CODE_TOKEN_VA(0x456596u);
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edx = lift_load32(cpu->esi + cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx += lift_load32(cpu->eax + 0xCu);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000565B3;
    ++cpu->edi;
    cpu->esi += 0x74u;
    goto label_00056545;
    label_000565B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4565B3u);
    cpu->esi = cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000565C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4565C0u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000565CE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x565CEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000565CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4565CEu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_000565E2;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x565E2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000565E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4565E2u);
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edx = (uint32_t)(cpu->esi + cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000565FD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x565FDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000565FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4565FDu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_00056611;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56611u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056611: cpu->eip = LIFT_CODE_TOKEN_VA(0x456611u);
    cpu->eax = g_sfera_scene_array_runtime.scene_records.data;
    cpu->ecx = lift_load32(cpu->esi + cpu->eax + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += lift_load32(cpu->edx + 0xCu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0005662D;
    --cpu->ebx;
    cpu->esi -= 0x74u;
    goto label_000565C0;
    label_0005662D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45662Du);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebx)) goto label_00056727;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00056643;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56643u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056643: cpu->eip = LIFT_CODE_TOKEN_VA(0x456643u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_00056657;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56657u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056657: cpu->eip = LIFT_CODE_TOKEN_VA(0x456657u);
    cpu->eax = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x74u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + cpu->eax);
    cpu->ecx = 0x1Du;
    cpu->edi = (uint32_t)(cpu->esp + 0x28u);
    lift_movs32(cpu, 1u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0005667F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5667Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005667F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45667Fu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_00056693;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56693u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056693: cpu->eip = LIFT_CODE_TOKEN_VA(0x456693u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x74u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000566B7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x566B7u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000566B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4566B7u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_000566CB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x566CBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000566CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4566CBu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->edi += g_sfera_scene_array_runtime.scene_records.data;
    cpu->ecx = 0x1Du;
    lift_movs32(cpu, 1u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000566EA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x566EAu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000566EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4566EAu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_000566FE;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x566FEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000566FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4566FEu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->edi += g_sfera_scene_array_runtime.scene_records.data;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->ecx = 0x1Du;
    cpu->esi = (uint32_t)(cpu->esp + 0x28u);
    --cpu->ebx;
    lift_movs32(cpu, 1u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00056540;
    label_00056727: cpu->eip = LIFT_CODE_TOKEN_VA(0x456727u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00056736;
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56736u); lift_push32(cpu, r); sfera_sub_004564A0(cpu,r); if (cpu->eip != r) return; }
    label_00056736: cpu->eip = LIFT_CODE_TOKEN_VA(0x456736u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_00056747;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    goto label_000564C5;
    label_00056747: cpu->eip = LIFT_CODE_TOKEN_VA(0x456747u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456760u);
    cpu->esp -= 0x10u;
    cpu->edx = 1u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0005677D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5677Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005677D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45677Du);
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_world_objects.object_handles.data;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056792;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56792u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056792: cpu->eip = LIFT_CODE_TOKEN_VA(0x456792u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000567A6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x567A6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000567A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4567A6u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x10u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4567F9u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (45.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (15.0));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00056829;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00056840;
    label_00056829: cpu->eip = LIFT_CODE_TOKEN_VA(0x456829u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0005683E;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00056840;
    label_0005683E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45683Eu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00056840: cpu->eip = LIFT_CODE_TOKEN_VA(0x456840u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005684E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5684Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005684E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45684Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00056862;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56862u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056862: cpu->eip = LIFT_CODE_TOKEN_VA(0x456862u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.399999976158142));
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456880u);
    { uint64_t l=cpu->esp, r=(uint64_t)(0x1Cu), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    (void)cpu;
    label_00056890: cpu->eip = LIFT_CODE_TOKEN_VA(0x456890u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->edx);
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->edi = cpu->ecx;
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000568A5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x568A5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000568A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4568A5u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_000568B9;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x568B9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000568B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4568B9u);
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 2u));
    cpu->ebp = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 4u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    goto label_000568D4;
    label_000568D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4568D0u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_000568D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4568D4u);
    cpu->ebx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ebx += cpu->ebx;
    cpu->ebx += cpu->ebx;
    label_000568E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4568E0u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000568EE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x568EEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000568EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4568EEu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_00056902;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56902u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056902: cpu->eip = LIFT_CODE_TOKEN_VA(0x456902u);
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->eax = lift_load32(cpu->ebx + cpu->edx + 4u);
    ++cpu->edi;
    cpu->ebx += 0xCu;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ebp)) goto label_000568E0;
    cpu->ebx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->ebx += cpu->ebx;
    --cpu->edi;
    cpu->ebx += cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00056920: cpu->eip = LIFT_CODE_TOKEN_VA(0x456920u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005692E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5692Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005692E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45692Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_00056942;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56942u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056942: cpu->eip = LIFT_CODE_TOKEN_VA(0x456942u);
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->edx = lift_load32(cpu->ebx + cpu->ecx + 4u);
    --cpu->esi;
    cpu->ebx -= 0xCu;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ebp)) goto label_00056920;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->esi)) goto label_00056A62;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0005696B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5696Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005696B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45696Bu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_0005697F;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5697Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005697F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45697Fu);
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ebx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ebx += cpu->ebx;
    cpu->ebx += cpu->ebx;
    cpu->ecx = lift_load32(cpu->ebx + cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->ebx + cpu->eax + 8u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000569B0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x569B0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000569B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4569B0u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_000569C4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x569C4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000569C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4569C4u);
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ebp = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    cpu->ecx += cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000569E9;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4569E5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_000569E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4569E9u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_00056A01;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4569FDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_00056A01: cpu->eip = LIFT_CODE_TOKEN_VA(0x456A01u);
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->eax = (uint32_t)(cpu->ebx + cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056A28;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56A28u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056A28: cpu->eip = LIFT_CODE_TOKEN_VA(0x456A28u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_00056A3C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56A3Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056A3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x456A3Cu);
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + cpu->ebp, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    ++cpu->edi;
    --cpu->esi;
    lift_store32(cpu->eax + cpu->ebp + 4u, cpu->edx);
    lift_store32(cpu->eax + cpu->ebp + 8u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000568D0;
    label_00056A62: cpu->eip = LIFT_CODE_TOKEN_VA(0x456A62u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00056A71;
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56A71u); lift_push32(cpu, r); sfera_sub_00456880(cpu,r); if (cpu->eip != r) return; }
    label_00056A71: cpu->eip = LIFT_CODE_TOKEN_VA(0x456A71u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esp + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00056A86;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    goto label_00056890;
    label_00056A86: cpu->eip = LIFT_CODE_TOKEN_VA(0x456A86u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456A90u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00056C1A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->ebp = 0u;
    label_00056AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x456AB0u);
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_store32(cpu->esp + 0x14u, 0u);
    label_00056AC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x456AC0u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00056ACE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56ACEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056ACE: cpu->eip = LIFT_CODE_TOKEN_VA(0x456ACEu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056AE2;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56AE2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056AE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x456AE2u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + cpu->ebp + 0x84u))) goto label_00056BFC;
    cpu->edi = 0u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00056B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x456B00u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00056B0E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56B0Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x456B0Eu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056B22;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56B22u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056B22: cpu->eip = LIFT_CODE_TOKEN_VA(0x456B22u);
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->edx + cpu->ebp + 0x88u))) goto label_00056BEE;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00056B43;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56B43u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056B43: cpu->eip = LIFT_CODE_TOKEN_VA(0x456B43u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056B57;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56B57u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056B57: cpu->eip = LIFT_CODE_TOKEN_VA(0x456B57u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->esi += lift_load32(cpu->esp + 0x14u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->edx = (uint32_t)(cpu->esi + cpu->edi);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x8Cu)) == (uint32_t)(0u)) goto label_00056BE8;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00056B7F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56B7Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056B7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x456B7Fu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056B93;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56B93u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056B93: cpu->eip = LIFT_CODE_TOKEN_VA(0x456B93u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->esi += cpu->edi;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x53Cu, (uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x53Cu)) - 1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x53Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x53Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00056BE8;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00056BC1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56BC1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056BC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x456BC1u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056BD5;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56BD5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056BD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x456BD5u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56BE8u); lift_push32(cpu, r); sfera_sub_00451100(cpu,r); if (cpu->eip != r) return; }
    label_00056BE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x456BE8u);
    ++cpu->edi;
    goto label_00056B00;
    label_00056BEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x456BEEu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0xAu) + (uint64_t)(0u));
    goto label_00056AC0;
    label_00056BFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x456BFCu);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x1B3u) + (uint64_t)(0u));
    ++cpu->ebx;
    cpu->ebp += 0x6CCu;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state)) goto label_00056AB0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00056C1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x456C1Au);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456C20u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00056D4F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->ebx = 0u;
    label_00056C40: cpu->eip = LIFT_CODE_TOKEN_VA(0x456C40u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    label_00056C46: cpu->eip = LIFT_CODE_TOKEN_VA(0x456C46u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00056C54;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56C54u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056C54: cpu->eip = LIFT_CODE_TOKEN_VA(0x456C54u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056C68;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56C68u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056C68: cpu->eip = LIFT_CODE_TOKEN_VA(0x456C68u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + cpu->eax + 0x84u))) goto label_00056D31;
    cpu->edi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00056C80: cpu->eip = LIFT_CODE_TOKEN_VA(0x456C80u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00056C8E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56C8Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056C8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x456C8Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056CA2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56CA2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056CA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x456CA2u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + cpu->ecx + 0x88u))) goto label_00056D26;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00056CBF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56CBFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056CBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x456CBFu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056CD3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56CD3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056CD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x456CD3u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx += lift_load32(cpu->esp + 0x10u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->edx += cpu->edi;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0x8Cu)) == (uint32_t)(0u)) goto label_00056D20;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00056CFB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56CFBu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056CFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x456CFBu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_landscape_runtime.file_records.capacity)) goto label_00056D0F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56D0Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056D0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x456D0Fu);
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->edx);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56D20u); lift_push32(cpu, r); sfera_sub_00451100(cpu,r); if (cpu->eip != r) return; }
    label_00056D20: cpu->eip = LIFT_CODE_TOKEN_VA(0x456D20u);
    ++cpu->edi;
    goto label_00056C80;
    label_00056D26: cpu->eip = LIFT_CODE_TOKEN_VA(0x456D26u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0xAu) + (uint64_t)(0u));
    goto label_00056C46;
    label_00056D31: cpu->eip = LIFT_CODE_TOKEN_VA(0x456D31u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x1B3u) + (uint64_t)(0u));
    ++cpu->esi;
    cpu->ebx += 0x6CCu;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state)) goto label_00056C40;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00056D4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x456D4Fu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456D60u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00056D76;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56D76u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00056D76: cpu->eip = LIFT_CODE_TOKEN_VA(0x456D76u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00056D8A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56D8Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056D8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x456D8Au);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x456DA1u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::_stricmp);
    cpu->edi = cpu->eax;
    cpu->edx = lift_load32(cpu->edi + 0x48u);
    cpu->eax = lift_load16(cpu->edx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x88u);
    cpu->eax += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"default");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x56DC5u), LIFT_CODE_TOKEN_RVA(0x56DC3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456DC5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00056DF4;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00056DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x456DD0u);
    cpu->ecx = lift_load32(cpu->edi + 0x48u);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 2u);
    ++cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x88u);
    cpu->edx += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"default");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x56DEDu), LIFT_CODE_TOKEN_RVA(0x56DEBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456DEDu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00056DD0;
    label_00056DF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x456DF4u);
    cpu->eax = lift_load32(cpu->edi + 0x48u);
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->esi) * 2u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x88u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->ecx + cpu->edx + 0x24u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00456E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x456E20u);
    cpu->esp -= 0x84u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 8u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00056FF5;
    cpu->esi = 0u;
    label_00056E4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x456E4Fu);
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z));
    cpu->eax = lift_load32(cpu->ebx + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.x));
    cpu->edx = lift_load16(cpu->esi + cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ebp = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 8u));
    lift_store32(cpu->esp + 0x58u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->edx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store32(cpu->esp + 0x5Cu, cpu->ebp);
    cpu->edx = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->esp + 0x60u, cpu->edx);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load16(cpu->esi + cpu->eax + 2u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ebp = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 8u));
    lift_store32(cpu->esp + 0x64u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->edx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_store32(cpu->esp + 0x68u, cpu->ebp);
    cpu->edx = lift_load32(cpu->edx + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->esp + 0x6Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load16(cpu->esi + cpu->eax + 4u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0x70u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x70u))));
    lift_store32(cpu->esp + 0x74u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esp + 0x78u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x7Cu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    cpu->ecx = lift_load32(cpu->edi + cpu->eax + 0x14u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store32(cpu->esp + 0x80u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    cpu->edx = lift_load32(cpu->edi + cpu->eax + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store32(cpu->esp + 0x84u, cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00056F5C;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x56F5Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00056F5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x456F5Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.flare_clip_vector.x.u32);
    cpu->edx += 8u;
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x456FA6u); lift_push32(cpu, r); sfera_sub_00451A40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00056FDD;
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, 3u);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x456FD9u); lift_push32(cpu, r); sfera_sub_00451B40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00057013;
    label_00056FDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x456FDDu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->esi += 0x1Cu;
    cpu->edi += 0x1Cu;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_00056E4F;
    label_00056FF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x456FF5u);
    cpu->eax = 1u;
    label_00056FFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x456FFAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x84u;
    lift_return(cpu, 0u, stop_address); return;
    label_00057013: cpu->eip = LIFT_CODE_TOKEN_VA(0x457013u);
    cpu->eax = 0u;
    goto label_00056FFA;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00457020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x457020u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(0u)) goto label_00057090;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(1u)) goto label_00057041;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x57041u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00057041: cpu->eip = LIFT_CODE_TOKEN_VA(0x457041u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)300.0f);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ecx + 0xCu)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00057090;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(1u)) goto label_00057071;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x57071u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00057071: cpu->eip = LIFT_CODE_TOKEN_VA(0x457071u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 800.0);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00057090;
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
    label_00057090: cpu->eip = LIFT_CODE_TOKEN_VA(0x457090u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004570A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4570A0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000570B4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x570B4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000570B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4570B4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000570C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x570C8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000570C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4570C8u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4570DFu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)5.0f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->eax + 0x194u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00057100;
    label_000570F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4570F2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_00057100: cpu->eip = LIFT_CODE_TOKEN_VA(0x457100u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45711Eu); lift_push32(cpu, r); sfera_sub_004519D0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)0.15707965195178986f));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000570F2;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->esp -= 8u;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.15707965195178986);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45715Cu); lift_push32(cpu, r); sfera_sub_004519D0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457177u); lift_push32(cpu, r); sfera_sub_004519D0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000571B3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_push(cpu, 6.283185958862305);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000571E4;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000571B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4571B3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000571E6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (6.283185958862305));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000571E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4571E4u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000571E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4571E6u);
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004571F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4571F0u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0005720B;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x57205u), LIFT_CODE_TOKEN_RVA(0x57203u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x457205u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01) = (uint32_t)(cpu->edi);
    label_0005720B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45720Bu);
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00057225;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45721Cu); lift_push32(cpu, r); sfera_sub_004DA450(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457222u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00057225: cpu->eip = LIFT_CODE_TOKEN_VA(0x457225u);
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    g_sfera_sky_runtime.draw_resource = (uint32_t)(cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00057245;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45723Cu); lift_push32(cpu, r); sfera_sub_004DA450(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457242u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00057245: cpu->eip = LIFT_CODE_TOKEN_VA(0x457245u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    g_sfera_window_runtime.render_vertex_buffer = (uint32_t)(cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00057265;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45725Cu); lift_push32(cpu, r); sfera_sub_004DA490(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457262u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00057265: cpu->eip = LIFT_CODE_TOKEN_VA(0x457265u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05) = (uint32_t)(cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00057285;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45727Cu); lift_push32(cpu, r); sfera_sub_004DA490(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457282u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00057285: cpu->eip = LIFT_CODE_TOKEN_VA(0x457285u);
    cpu->ecx = g_sfera_render_sample_runtime.active_record;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06) = (uint32_t)(cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000572A5;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45729Cu); lift_push32(cpu, r); sfera_sub_004DA4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4572A2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000572A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4572A5u);
    g_sfera_render_sample_runtime.active_record = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4572B0u); lift_push32(cpu, r); sfera_sub_0049A1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource;
    label_000572B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4572B5u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000572C5;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x572C3u), LIFT_CODE_TOKEN_RVA(0x572C1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4572C3u);
    lift_store32(cpu->esi, cpu->edi);
    label_000572C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4572C5u);
    cpu->esi += 0x10u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource + kTextureCacheEntryCount * (uint32_t)sizeof(SferaTextureCacheEntry)))) goto label_000572B5;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4572D5u); lift_push32(cpu, r); sfera_sub_00456C20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000572EF;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4572E6u); lift_push32(cpu, r); sfera_sub_004DA450(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4572ECu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000572EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4572EFu);
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    g_sfera_sky_runtime.draw_resource = (uint32_t)(cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0005730F;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457306u); lift_push32(cpu, r); sfera_sub_004DA450(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45730Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0005730F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45730Fu);
    g_sfera_window_runtime.render_vertex_buffer = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45731Au); lift_push32(cpu, r); sfera_sub_004C3AD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457325u); lift_push32(cpu, r); sfera_sub_004D8360(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_00057349;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00057349;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45733Au); lift_push32(cpu, r); sfera_sub_004DB000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457340u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02) = (uint32_t)(cpu->edi);
    label_00057349: cpu->eip = LIFT_CODE_TOKEN_VA(0x457349u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00057369;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45735Au); lift_push32(cpu, r); sfera_sub_004DA670(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457360u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_graphics_runtime.d3d9_device = (uint32_t)(cpu->edi);
    label_00057369: cpu->eip = LIFT_CODE_TOKEN_VA(0x457369u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00457370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x457370u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00057384;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong hand was used!";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457382u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00057388;
    label_00057384: cpu->eip = LIFT_CODE_TOKEN_VA(0x457384u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00057392;
    label_00057388: cpu->eip = LIFT_CODE_TOKEN_VA(0x457388u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x57392u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00057392: cpu->eip = LIFT_CODE_TOKEN_VA(0x457392u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000573A6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x573A6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000573A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4573A6u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->edi) != 0u) goto label_000573BD;
    cpu->ecx = (uint32_t)(uintptr_t)"delete_text: wrong handle";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x573BDu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000573BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4573BDu);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4573C8u); lift_push32(cpu, r); sfera_sub_004557C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000573D7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x573D7u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000573D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4573D7u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000573EB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x573EBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000573EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4573EBu);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x990u);
    lift_push32(cpu, 0xC37u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457409u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00057417;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x57417u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00057417: cpu->eip = LIFT_CODE_TOKEN_VA(0x457417u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005742B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5742Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005742B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45742Bu);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, 0xC38u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457443u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00057451;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x57451u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00057451: cpu->eip = LIFT_CODE_TOKEN_VA(0x457451u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005747A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457465u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), 0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_sample_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) - 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0005747A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45747Au);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), 0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_sample_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) - 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00457490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x457490u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0005750C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    (void)cpu;
    label_000574A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4574A0u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000574AE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x574AEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000574AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4574AEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000574C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x574C2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000574C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4574C2u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_000574D0;
    ++cpu->esi;
    goto label_000574A0;
    label_000574D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4574D0u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000574DE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x574DEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000574DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4574DEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000574F2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x574F2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000574F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4574F2u);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(0u)) goto label_00057507;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x57507u); lift_push32(cpu, r); sfera_sub_00457370(cpu,r); if (cpu->eip != r) return; }
    label_00057507: cpu->eip = LIFT_CODE_TOKEN_VA(0x457507u);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000574A0;
    cpu->edi = lift_pop32(cpu);
    label_0005750C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45750Cu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00457510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x457510u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x50u);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x457527u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x45752Cu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457538u); lift_push32(cpu, r); sfera_sub_004549B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_0005755D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1000.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005755D;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_16)) != (uint32_t)(0u)) goto label_0005755D;
    cpu->ebx = 1u;
    goto label_0005755F;
    label_0005755D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45755Du);
    cpu->ebx = 0u;
    label_0005755F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45755Fu);
    lift_store8(cpu->esi + 0x30u, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(2u)) goto label_0005756F;
    lift_x87_push(cpu, 0.03490658950558778);
    goto label_000575BD;
    label_0005756F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45756Fu);
    lift_x87_push(cpu, 0.6000000238418579);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45757Au); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width)))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (0.75));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4575ABu); lift_push32(cpu, r); sfera_sub_004EED60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    label_000575BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4575BDu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esi + 0x48u, lift_x87_get(cpu, 0u));
    if ((uint32_t)(cpu->edi) != (uint32_t)(2u)) goto label_000575D5;
    lift_x87_push(cpu, (double)997.0f);
    goto label_000575DB;
    label_000575D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4575D5u);
    lift_x87_push(cpu, (double)0.10000000149011612f);
    label_000575DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4575DBu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esi + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_00057698;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFEu);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFC63u;
    cpu->eax += 0x3EDu;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 20.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)59.0f);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)37.0f);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)12.0f);
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)19.0f);
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)47.0f);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)71.0f);
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 14.0);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45766Eu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (-3.0) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (2.0) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0005777E;
    label_00057698: cpu->eip = LIFT_CODE_TOKEN_VA(0x457698u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4576ADu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y))));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)150.0f);
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)200.0f);
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4576D5u); lift_push32(cpu, r); sfera_sub_00457020(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005772C;
    cpu->ecx = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_main_aux_runtime.secondary_world_manager;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4576F0u); lift_push32(cpu, r); sfera_sub_00495360(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4576F5u); lift_push32(cpu, r); sfera_sub_00457020(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = g_sfera_main_aux_runtime.secondary_world_manager;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00057703;
    cpu->eax = g_sfera_font_runtime.renderer;
    label_00057703: cpu->eip = LIFT_CODE_TOKEN_VA(0x457703u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = g_sfera_world_render_queue_runtime.entries[0];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    goto label_00057779;
    label_0005772C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45772Cu);
    cpu->eax = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_font_runtime.renderer;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45773Fu); lift_push32(cpu, r); sfera_sub_00495360(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457744u); lift_push32(cpu, r); sfera_sub_00457020(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = g_sfera_main_aux_runtime.secondary_world_manager;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00057752;
    cpu->eax = g_sfera_font_runtime.renderer;
    label_00057752: cpu->eip = LIFT_CODE_TOKEN_VA(0x457752u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_recovered_static_runtime.scene_state_08;
    label_00057779: cpu->eip = LIFT_CODE_TOKEN_VA(0x457779u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5777Eu); lift_push32(cpu, r); sfera_sub_0049E500(cpu,r); if (cpu->eip != r) return; }
    label_0005777E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45777Eu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13)) == (uint32_t)(0u)) goto label_000577AE;
    lift_x87_push(cpu, (double)1040.0f);
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)1050.0f);
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)100.0f);
    lift_store_f32(cpu->esi + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.20000000298023224f);
    lift_store_f32(cpu->esi + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000577AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4577AEu);
    if ((uint32_t)(lift_load32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_17)) == (uint32_t)(0u)) goto label_000577D1;
    if ((uint32_t)(cpu->edi) == (uint32_t)(2u)) goto label_000577D1;
    lift_x87_push(cpu, (double)180.0f);
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)200.0f);
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000577D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4577D1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x44u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005782E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x44u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_push(cpu, 20.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005782A;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0005782C;
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
    label_0005782A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45782Au);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005782C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45782Cu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0005782E: cpu->eip = LIFT_CODE_TOKEN_VA(0x45782Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00457840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x457840u);
    cpu->esp -= 0x3Cu;
    { uint64_t l=(uint64_t)(g_sfera_view_spatial_runtime.alternate_projection), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0005786C;
    cpu->eax = 0u;
    g_sfera_client_main_scalar_runtime.state_01 = (uint32_t)(cpu->eax);
    g_sfera_main_aux_runtime.color_component = (uint32_t)(cpu->eax);
    g_sfera_recovered_static_runtime.animation_result_b = (uint32_t)(cpu->eax);
    g_sfera_recovered_static_runtime.render_state_09 = (uint32_t)(cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 12u, stop_address); return;
    label_0005786C: cpu->eip = LIFT_CODE_TOKEN_VA(0x45786Cu);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457891u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4578B0u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f64(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4578C9u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x4Cu))));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x2Cu)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4578EAu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.5707964897155762));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.scene_scale, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.sky_blend_factor, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.31830985316916194));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457927u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.5707964897155762));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00057958;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (6.283185958862305));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    label_00057958: cpu->eip = LIFT_CODE_TOKEN_VA(0x457958u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.15915492658458097));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0005798F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x45796Bu); lift_push32(cpu, r); sfera_sub_00457020(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, (uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0]); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_font_runtime.renderer;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0005798A;
    cpu->ecx = g_sfera_main_aux_runtime.secondary_world_manager;
    label_0005798A: cpu->eip = LIFT_CODE_TOKEN_VA(0x45798Au);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5798Fu); lift_push32(cpu, r); sfera_sub_00495090(cpu,r); if (cpu->eip != r) return; }
    label_0005798F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45798Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0]));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000579C5;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_sky_interpolation_runtime.primary_key_positions[9])));
    cpu->eax = 9u;
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00057A32;
    label_000579C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4579C5u);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[9]));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000579EB;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->eax = 9u;
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    goto label_00057A32;
    label_000579EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4579EBu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 1u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[1]));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00057A18;
    label_00057A07: cpu->eip = LIFT_CODE_TOKEN_VA(0x457A07u);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[1])));
    ++cpu->ecx;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00057A07;
    label_00057A18: cpu->eip = LIFT_CODE_TOKEN_VA(0x457A18u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0])))));
    label_00057A32: cpu->eip = LIFT_CODE_TOKEN_VA(0x457A32u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0]);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 4u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457AB5u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_push(cpu, -0.30000001192092896);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.9539999961853027));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.x));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.y));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.z));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.w));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_view_spatial_runtime.position_offset.z.f32)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00057BA0;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00057BD6;
    label_00057BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x457BA0u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    label_00057BD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x457BD6u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.environment_parameter.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0]));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00057C1A;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[5]));
    cpu->eax = 5u;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    goto label_00057C8F;
    label_00057C1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x457C1Au);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[5]));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00057C44;
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    cpu->eax = 5u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    goto label_00057C8F;
    label_00057C44: cpu->eip = LIFT_CODE_TOKEN_VA(0x457C44u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 1u;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[1]));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00057C71;
    label_00057C60: cpu->eip = LIFT_CODE_TOKEN_VA(0x457C60u);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[1])));
    ++cpu->ecx;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00057C60;
    label_00057C71: cpu->eip = LIFT_CODE_TOKEN_VA(0x457C71u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00057C8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x457C8Fu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_samples[0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_samples[0]);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 4u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x457D56u); lift_push32(cpu, r); sfera_sub_0044E400(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].x));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].y));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].z));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store32(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store32(cpu->esp + 0x20u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store32(cpu->esp + 0x24u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->esp + 0x28u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_00057DF6;
    cpu->eax = 0xFFu;
    label_00057DF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x457DF6u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(0xFFu)) goto label_00057E07;
    cpu->edx = 0xFFu;
    label_00057E07: cpu->eip = LIFT_CODE_TOKEN_VA(0x457E07u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(0xFFu)) goto label_00057E18;
    cpu->ecx = 0xFFu;
    label_00057E18: cpu->eip = LIFT_CODE_TOKEN_VA(0x457E18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(0xFFu)) goto label_00057E2B;
    cpu->esi = 0xFFu;
    label_00057E2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x457E2Bu);
    g_sfera_client_main_scalar_runtime.state_01 = (uint32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    g_sfera_main_aux_runtime.color_component = (uint32_t)(cpu->edx);
    cpu->edi = 0xFFu;
    cpu->edi -= cpu->esi;
    cpu->edx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    g_sfera_recovered_static_runtime.animation_result_b = (uint32_t)(cpu->ecx);
    g_sfera_render_lookup_runtime.alpha_component = (uint32_t)(cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx &= 0xFFu;
    cpu->eax |= cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_recovered_static_runtime.render_state_09 = (uint32_t)(cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 12u, stop_address); return;
}
