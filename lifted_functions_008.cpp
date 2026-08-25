#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_0044DE30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DE3Du)); sfera_sub_004D8DD0(cpu, LIFT_CODE_TOKEN_VA(0x44DE3Du));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DE4Au)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x44DE4Au));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DE59u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DE59u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DE68u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DE68u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DE77u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DE77u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x89u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DE89u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DE89u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DE98u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DE98u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DEA8u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x44DEA8u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DEBBu)); sfera_sub_004D9200(cpu, LIFT_CODE_TOKEN_VA(0x44DEBBu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DECEu)); sfera_sub_004D9250(cpu, LIFT_CODE_TOKEN_VA(0x44DECEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DEDFu)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x44DEDFu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DEF0u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x44DEF0u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044DF90(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    goto label_0004DF90;
    label_0004DF00:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF11u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x44DF11u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF22u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x44DF22u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x89u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF34u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DF34u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF43u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DF43u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF52u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DF52u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF61u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DF61u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 0x16u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF70u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DF70u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004DF90:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF96u)); sfera_sub_0044DE30(cpu, LIFT_CODE_TOKEN_VA(0x44DF96u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DFA5u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DFA5u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DFB4u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44DFB4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DFB9u)); sfera_sub_004B9620(cpu, LIFT_CODE_TOKEN_VA(0x44DFB9u));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    if (cpu->ecx == 0u) goto label_0004DFC8;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4DFC8u)); sfera_sub_004205E0(cpu, LIFT_CODE_TOKEN_RVA(0x4DFC8u));
    label_0004DFC8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DFCDu)); sfera_sub_0044D700(cpu, LIFT_CODE_TOKEN_VA(0x44DFCDu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DFD2u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x44DFD2u));
    cpu->eax -= g_sfera_frame_runtime.frame_anchor.low;
    ++g_sfera_frame_runtime.frame_sample_count;
    *(uint32_t*)(cpu->esp) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)0x3E8u) goto label_0004E017;
    x87_v0 = (double)(((int32_t)(g_sfera_frame_runtime.frame_sample_count)));
    g_sfera_frame_runtime.frame_sample_count = 0u;
    x87_v0 = (x87_v0) * (10000.0);
    x87_v0 = (x87_v0) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp)))));
    *(float*)((uintptr_t)&g_sfera_input_device_runtime.frame_interval.f32) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E00Cu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x44E00Cu));
    g_sfera_frame_runtime.frame_anchor.low = cpu->eax;
    g_sfera_frame_runtime.frame_anchor.high = cpu->edx;
    label_0004E017:
    cpu->esp += 4u;
    goto label_0004DF00;
}
__declspec(noinline) void sfera_sub_0044E020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    if (cpu->eax == 0u) goto label_0004E08E;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E033u), LIFT_CODE_TOKEN_RVA(0x4E031u))) { return; }
    if (cpu->eax == 0x88760868u) goto label_0004E08E;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E04Du), LIFT_CODE_TOKEN_RVA(0x4E04Bu))) { return; }
    if (cpu->eax != 1u) goto label_0004E08E;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E065u), LIFT_CODE_TOKEN_RVA(0x4E063u))) { return; }
    if (cpu->eax != 1u) goto label_0004E08E;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::Sleep);
    label_0004E071:
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x4E075u), LIFT_CODE_TOKEN_RVA(0x4E073u))) { return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E088u), LIFT_CODE_TOKEN_RVA(0x4E086u))) { return; }
    if (cpu->eax == 1u) goto label_0004E071;
    cpu->esi = lift_pop32(cpu);
    label_0004E08E:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E090(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v2 = (double)g_sfera_static_render_lookup_runtime.projection_scale; x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 8u); x87_v4 = x87_v3;
    x87_v1 = x87_v1 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x14u); x87_v5 = x87_v4;
    x87_v5 = (x87_v5) - (((double)(*(float*)(void*)&g_sfera_main_view_state_runtime.projection_scale)));
    x87_v6 = (double)*(float*)(cpu->esp + 0x18u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v1; x87_v1 = temporary; }
    x87_v5 = x87_v6 - x87_v5; 
    x87_v2 = x87_v2 + x87_v5; 
    x87_v5 = 0.00390625;
    x87_v2 = x87_v2 * x87_v5; 
    x87_v5 = (double)g_sfera_static_render_lookup_runtime.view_phase;
    x87_v2 = x87_v2 + x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->edi) = x87_v4; 
    cpu->edi = lift_pop32(cpu);
    x87_v4 = (double)g_sfera_static_render_lookup_runtime.projection_scale;
    x87_v0 = x87_v0 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)g_sfera_main_view_state_runtime.projection_scale; x87_v4 = x87_v3;
    x87_v2 = x87_v2 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = (x87_v0) * (0.00390625);
    x87_v0 = (x87_v0) + (((double)g_sfera_render_sample_runtime.phase.f32));
    *(float*)(cpu->esi) = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E140(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->edi);
    x87_v1 = (double)*(float*)(cpu->esp + 8u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi);
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v3 - x87_v2; 
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi)));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esi) = x87_v0; 
    *(float*)(cpu->edi) = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E1B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    bool lift_cmp[1];
    x87_v0 = (double)0.0010000000474974513f;
    lift_push32(cpu, cpu->esi);
    lift_cmp[0]=x87_v0<(((double)g_sfera_recovered_static_runtime.primary_frame_interval));
    lift_push32(cpu, cpu->edi);
    if (!lift_cmp[0]) goto label_0004E1D5;
    if (g_sfera_view_spatial_runtime.alternate_projection != 0u) goto label_0004E1D5;
    cpu->edi = 1u;
    goto label_0004E1D7;
    label_0004E1D5:
    cpu->edi = 0u;
    label_0004E1D7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E1DCu)); sfera_sub_0047F6B0(cpu, LIFT_CODE_TOKEN_VA(0x44E1DCu));
    cpu->esi = cpu->eax;
    if (cpu->edi == 0u) goto label_0004E210;
    if (g_sfera_frame_runtime.primary_toggle != 0u) goto label_0004E1FC;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E1F2u)); sfera_sub_0047F6C0(cpu, LIFT_CODE_TOKEN_VA(0x44E1F2u));
    g_sfera_frame_runtime.primary_toggle = 1u;
    label_0004E1FC:
    x87_v0 = (double)g_sfera_recovered_static_runtime.primary_frame_interval;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E20Du)); sfera_sub_0047FA20(cpu, LIFT_CODE_TOKEN_VA(0x44E20Du));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004E210:
    if (g_sfera_frame_runtime.primary_toggle != 1u) goto label_0004E22A;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E220u)); sfera_sub_0047F6E0(cpu, LIFT_CODE_TOKEN_VA(0x44E220u));
    g_sfera_frame_runtime.primary_toggle = 0u;
    label_0004E22A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E230(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    bool lift_cmp[1];
    x87_v0 = (double)0.0010000000474974513f;
    lift_push32(cpu, cpu->esi);
    lift_cmp[0]=x87_v0<(((double)g_sfera_recovered_static_runtime.secondary_frame_interval));
    lift_push32(cpu, cpu->edi);
    if (!lift_cmp[0]) goto label_0004E255;
    if (g_sfera_view_spatial_runtime.alternate_projection != 0u) goto label_0004E255;
    cpu->edi = 1u;
    goto label_0004E257;
    label_0004E255:
    cpu->edi = 0u;
    label_0004E257:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E25Cu)); sfera_sub_0047F6B0(cpu, LIFT_CODE_TOKEN_VA(0x44E25Cu));
    cpu->esi = cpu->eax;
    if (cpu->edi == 0u) goto label_0004E290;
    if (g_sfera_frame_runtime.secondary_toggle != 0u) goto label_0004E27C;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E272u)); sfera_sub_0047F730(cpu, LIFT_CODE_TOKEN_VA(0x44E272u));
    g_sfera_frame_runtime.secondary_toggle = 1u;
    label_0004E27C:
    x87_v0 = (double)g_sfera_recovered_static_runtime.secondary_frame_interval;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E28Du)); sfera_sub_0047F770(cpu, LIFT_CODE_TOKEN_VA(0x44E28Du));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004E290:
    if (g_sfera_frame_runtime.secondary_toggle != 1u) goto label_0004E2AA;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E2A0u)); sfera_sub_0047F750(cpu, LIFT_CODE_TOKEN_VA(0x44E2A0u));
    g_sfera_frame_runtime.secondary_toggle = 0u;
    label_0004E2AA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E2B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esi);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esi + 8u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->esi + 8u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)(cpu->eax + 0xCu) = (double)*(float*)(cpu->edi);
    *(float*)(cpu->eax + 0x1Cu) = (double)*(float*)(cpu->edi + 4u);
    *(float*)(cpu->eax + 0x2Cu) = (double)*(float*)(cpu->edi + 8u);
    x87_v0 = 0.0;
    *(float*)(cpu->eax + 0x30u) = x87_v0;
    *(float*)(cpu->eax + 0x34u) = x87_v0;
    *(float*)(cpu->eax + 0x38u) = x87_v0; 
    *(float*)(cpu->eax + 0x3Cu) = (double)(1.0);
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(double*)(cpu->esp + 0x10u) = x87_v2;
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 0xCu); x87_v7 = x87_v6;
    x87_v2 = x87_v2 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    x87_v2 = x87_v6 - x87_v2; 
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->eax) = x87_v5; 
    x87_v5 = x87_v4;
    x87_v5 = -x87_v5;
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + 4u) = x87_v6; 
    x87_v6 = x87_v2;
    x87_v0 = x87_v0 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    *(double*)(cpu->esp + 0x20u) = x87_v5;
    x87_v6 = x87_v1;
    x87_v6 = -x87_v6;
    x87_v6 = (x87_v6) * (x87_v3);
    x87_v7 = x87_v4;
    x87_v5 = x87_v5 * x87_v7; 
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    x87_v5 = x87_v6 - x87_v5; 
    *(float*)(cpu->eax + 8u) = x87_v5; 
    x87_v5 = x87_v4;
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v6 = x87_v3;
    x87_v6 = (x87_v6) * (*(double*)(cpu->esp + 8u));
    x87_v5 = x87_v5 + x87_v6; 
    *(float*)(cpu->eax + 0x10u) = x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->eax + 0x14u) = x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    x87_v4 = (x87_v4) * (*(double*)(cpu->esp + 0x18u));
    x87_v5 = x87_v1;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v3 = x87_v4 - x87_v3; 
    *(float*)(cpu->eax + 0x18u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->eax + 0x20u) = x87_v2; 
    *(float*)(cpu->eax + 0x24u) = (-((double)*(float*)(cpu->esp)));
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->eax + 0x28u) = x87_v0; 
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E400(LiftCpu* cpu, uint32_t stop_address) { double x87_p0, x87_p1;
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left<lift_right)) goto label_0004E428; }
    cpu->fpu[0u] = cpu->fpu[0u]; 
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 4u))) * (((double)*(float*)(cpu->esp + 8u))));
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0004E428:
    cpu->fpu[1u] = cpu->fpu[0u]; 
    cpu->fpu[0u] = 0.4000000059604645;
    { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left<lift_right)) goto label_0004E456; }
    cpu->fpu[1u] = cpu->fpu[0u]; 
    cpu->fpu[1u] = cpu->fpu[1u]; 
    *(float*)(cpu->esp + 4u) = (double)(1.0);
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 4u))) * (((double)*(float*)(cpu->esp + 8u))));
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0004E456:
    x87_p0 = 0.0;
    cpu->fpu[1u] = (cpu->fpu[1u]) - (x87_p0);
    cpu->fpu[0u] = cpu->fpu[0u] - x87_p0; 
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; 
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 4u))) * (((double)*(float*)(cpu->esp + 8u))));
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E480(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->edi=0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xAu;
    label_0004E493:
    cpu->esi = cpu->edi;
    cpu->esi <<= 5u;
    cpu->esi += (uint64_t)(sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::v));
    cpu->ebp = 0xCu;
    label_0004E4A3:
    x87_v0 = 255.0;
    x87_v1 = (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0]));
    x87_v2 = (double)1.059999942779541f;
    { const double lift_left=x87_v2; const double lift_right=x87_v1; x87_v1=x87_v2;  if (!(lift_left>lift_right)) goto label_0004E4CD; }
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    x87_v0 = (double)255.0f;
    goto label_0004E502;
    label_0004E4CD:
    x87_v2 = (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0]));
    x87_v3 = (double)1.4800000190734863f;
    { const double lift_left=x87_v3; const double lift_right=x87_v2; x87_v2=x87_v3;  if (!(lift_left<lift_right)) goto label_0004E4EF; }
    x87_v1 = x87_v2; 
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    x87_v0 = 0.0;
    goto label_0004E502;
    label_0004E4EF:
    x87_v3 = (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0]));
    x87_v3 = (x87_v3) - (x87_v1);
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v1 = x87_v3 - x87_v1; 
    x87_v1 = x87_v2 / x87_v1; 
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v0 = x87_v0 - x87_v1; 
    label_0004E502:
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x10u))) * (((double)*(float*)(cpu->esp + 0x2Cu))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = static_cast<int64_t>(std::nearbyint(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0]));
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_command_state_runtime.render_samples[0])) = cpu->eax;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0])))) * (((double)*(float*)(cpu->ebx + 0x14u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 0x1Cu) == 0u;
    *(float*)(cpu->esp + 0x18u) = (((((((double)*(float*)(cpu->esp + 0x18u))) / (((double)*(float*)(cpu->esp + 0x1Cu)))))) * (((double)*(float*)(cpu->ebx + 0x18u))));
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    if (sub_pred[0]) goto label_0004E58B;
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32);
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32);
    label_0004E58B:
    x87_v0 = (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.projection_samples[0]));
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    *(float*)(cpu->esi + 0xFFFFFFFCu) = ((((((((((double)*(float*)(cpu->esp + 0x24u))) * (((double)*(float*)(cpu->esp + 0x18u)))))) + (((double)*(float*)(cpu->esp + 0x10u)))))) + (0.5));
    x87_v0 = (double)*(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.projection_samples[0]));
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    ++cpu->edi;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x18u)));
    cpu->esi += 0x20u;
    --cpu->ebp;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    x87_v0 = (x87_v0) + (0.5);
    *(float*)(cpu->esi + 0xFFFFFFE0u) = x87_v0; 
    if (cpu->ebp != 0u) goto label_0004E4A3;
    if ((--*(uint32_t*)(cpu->esp + 0x20u)) != 0u) goto label_0004E493;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 9u;
    label_0004E600:
    cpu->ebx = 0xBu;
    label_0004E610:
    cpu->edi = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[1]));
    cpu->edx = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[0]));
    cpu->esi = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[12]));
    cpu->edx += cpu->edi;
    cpu->edx += cpu->esi;
    if ((int32_t)cpu->edx <= 0) goto label_0004E651;
    cpu->edx = cpu->ecx & 0xFFFFu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[0])) = cpu->edx & 0xFFFFu;
    cpu->ebp = cpu->edx + 1u;
    cpu->edx += 0xCu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[1])) = cpu->ebp & 0xFFFFu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[2])) = cpu->edx & 0xFFFFu;
    cpu->eax += 3u;
    label_0004E651:
    cpu->edi += cpu->esi;
    cpu->edi += *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[13]));
    if ((int32_t)cpu->edi <= 0) goto label_0004E685;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->esi = cpu->edx + 1u;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[0])) = cpu->esi & 0xFFFFu;
    cpu->esi = cpu->edx + 0xDu;
    cpu->edx += 0xCu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[1])) = cpu->esi & 0xFFFFu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[2])) = cpu->edx & 0xFFFFu;
    cpu->eax += 3u;
    label_0004E685:
    ++cpu->ecx;
    if ((--cpu->ebx) != 0u) goto label_0004E610;
    ++cpu->ecx;
    if ((--*(uint32_t*)(cpu->esp + 0x2Cu)) != 0u) goto label_0004E600;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E6A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0xCu;
    x87_v0 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->edx;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_font_runtime.renderer;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E6CDu)); sfera_sub_00495010(cpu, LIFT_CODE_TOKEN_VA(0x44E6CDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    x87_v0 = (double)*(float*)(cpu->edi + (cpu->ecx * 4u) + 0x28u);
    cpu->ecx = cpu->edi + (cpu->ecx * 4u) + 0x28u;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + (cpu->eax * 4u) + 0x28u)));
    cpu->eax = cpu->edi + (cpu->eax * 4u) + 0x28u;
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax);
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 4u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 4u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 4u)));
    *(float*)(cpu->esi + 4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 8u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 8u)));
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->esi + 8u) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044E720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x68u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = g_sfera_world_render_runtime.active_model;
    cpu->esi = cpu->ebp;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xACu);
    cpu->esi += *(uint32_t*)(cpu->ecx + 0x3Cu);
    cpu->eax = 2u;
    lift_push32(cpu, cpu->edi);
    if (*(uint8_t*)(cpu->esi + 0x20u) == (cpu->eax & 0xFFu)) goto label_0004EAB7;
    if (*(uint32_t*)(cpu->ecx + 0x38u) != cpu->eax) goto label_0004E77D;
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_03;
    cpu->eax = g_sfera_client_main_scalar_runtime.mode_01;
    cpu->edx = 1u;
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)((cpu->ebp * 8u) + ((uintptr_t)&g_sfera_render_lookup_runtime.entries[0].resource)) = cpu->eax;
    --cpu->edx;
    *(uint32_t*)((cpu->ebp * 8u) + ((uintptr_t)&g_sfera_render_lookup_runtime.entries[0].mask)) = cpu->edx;
    goto label_0004EAB7;
    label_0004E77D:
    lift_push32(cpu, cpu->ebx);
    cpu->edi = cpu->esp + 0x14u;
    cpu->ebx = cpu->esi + 0x24u;
    *(uint32_t*)(cpu->esp + 0x10u) = 8u;
    label_0004E790:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->edx;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E7ACu)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x44E7ACu));
    cpu->ebx += 0xCu;
    cpu->edi += 0xCu;
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_0004E790;
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44E7C8u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x44E7C8u));
    *(uint32_t*)((cpu->ebp * 8u) + ((uintptr_t)&g_sfera_render_lookup_runtime.entries[0].resource)) = cpu->eax;
    if (cpu->eax == 0u) goto label_0004EAB6;
    cpu->edx = (cpu->ebp * 8u) + ((uintptr_t)&g_sfera_render_lookup_runtime.entries[0].mask);
    cpu->ebp = g_sfera_client_main_scalar_runtime.counter_03;
    cpu->eax = 0u;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edx) = 0u;
    cpu->edi = 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->ebp < (int32_t)4u) goto label_0004EA1A;
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][0x30];
    label_0004E805:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFFCu); const double lift_left=(double)*(float*)(cpu->esi + 0x84u); if (lift_left>lift_right) goto label_0004E87E; }
    { const double lift_right=(double)*(float*)(cpu->ecx); const double lift_left=(double)*(float*)(cpu->esi + 0x88u); if (lift_left>lift_right) goto label_0004E87E; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 4u); const double lift_left=(double)*(float*)(cpu->esi + 0x8Cu); if (lift_left>lift_right) goto label_0004E87E; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFF0u); const double lift_left=(double)*(float*)(cpu->esi + 0x90u); if (lift_left<lift_right) goto label_0004E87E; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFF4u); const double lift_left=(double)*(float*)(cpu->esi + 0x94u); if (lift_left<lift_right) goto label_0004E87E; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFF8u); const double lift_left=(double)*(float*)(cpu->esi + 0x98u); if (lift_left<lift_right) goto label_0004E87E; }
    *(uint32_t*)(cpu->edx) = (uint64_t)(*(uint32_t*)(cpu->edx)) | (uint64_t)(cpu->edi);
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if (cpu->ebx == 7u) goto label_0004EAB6;
    label_0004E87E:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x38u); const double lift_left=(double)*(float*)(cpu->esi + 0x84u); if (lift_left>lift_right) goto label_0004E8F8; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x3Cu); const double lift_left=(double)*(float*)(cpu->esi + 0x88u); if (lift_left>lift_right) goto label_0004E8F8; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x40u); const double lift_left=(double)*(float*)(cpu->esi + 0x8Cu); if (lift_left>lift_right) goto label_0004E8F8; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x2Cu); const double lift_left=(double)*(float*)(cpu->esi + 0x90u); if (lift_left<lift_right) goto label_0004E8F8; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x30u); const double lift_left=(double)*(float*)(cpu->esi + 0x94u); if (lift_left<lift_right) goto label_0004E8F8; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x34u); const double lift_left=(double)*(float*)(cpu->esi + 0x98u); if (lift_left<lift_right) goto label_0004E8F8; }
    *(uint32_t*)(cpu->edx) = (uint64_t)(*(uint32_t*)(cpu->edx)) | (uint64_t)(cpu->edi);
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if (cpu->ebx == 7u) goto label_0004EAB6;
    label_0004E8F8:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x74u); const double lift_left=(double)*(float*)(cpu->esi + 0x84u); if (lift_left>lift_right) goto label_0004E972; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x78u); const double lift_left=(double)*(float*)(cpu->esi + 0x88u); if (lift_left>lift_right) goto label_0004E972; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x7Cu); const double lift_left=(double)*(float*)(cpu->esi + 0x8Cu); if (lift_left>lift_right) goto label_0004E972; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x68u); const double lift_left=(double)*(float*)(cpu->esi + 0x90u); if (lift_left<lift_right) goto label_0004E972; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x6Cu); const double lift_left=(double)*(float*)(cpu->esi + 0x94u); if (lift_left<lift_right) goto label_0004E972; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0x70u); const double lift_left=(double)*(float*)(cpu->esi + 0x98u); if (lift_left<lift_right) goto label_0004E972; }
    *(uint32_t*)(cpu->edx) = (uint64_t)(*(uint32_t*)(cpu->edx)) | (uint64_t)(cpu->edi);
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if (cpu->ebx == 7u) goto label_0004EAB6;
    label_0004E972:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xB0u); const double lift_left=(double)*(float*)(cpu->esi + 0x84u); if (lift_left>lift_right) goto label_0004E9FE; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xB4u); const double lift_left=(double)*(float*)(cpu->esi + 0x88u); if (lift_left>lift_right) goto label_0004E9FE; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xB8u); const double lift_left=(double)*(float*)(cpu->esi + 0x8Cu); if (lift_left>lift_right) goto label_0004E9FE; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xA4u); const double lift_left=(double)*(float*)(cpu->esi + 0x90u); if (lift_left<lift_right) goto label_0004E9FE; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xA8u); const double lift_left=(double)*(float*)(cpu->esi + 0x94u); if (lift_left<lift_right) goto label_0004E9FE; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xACu); const double lift_left=(double)*(float*)(cpu->esi + 0x98u); if (lift_left<lift_right) goto label_0004E9FE; }
    *(uint32_t*)(cpu->edx) = (uint64_t)(*(uint32_t*)(cpu->edx)) | (uint64_t)(cpu->edi);
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if (cpu->ebx == 7u) goto label_0004EAB6;
    label_0004E9FE:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->eax = cpu->ebp + 0xFFFFFFFDu;
    cpu->ecx += 0xF0u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) < (int32_t)cpu->eax) goto label_0004E805;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_0004EA1A:
    if ((int32_t)(cpu->eax) >= (int32_t)(cpu->ebp)) goto label_0004EAB6;
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    cpu->ecx -= cpu->eax;
    cpu->ecx = (cpu->ecx * 4u) + ((uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][0x30]);
    label_0004EA30:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFFCu); const double lift_left=(double)*(float*)(cpu->esi + 0x84u); if (lift_left>lift_right) goto label_0004EAA5; }
    { const double lift_right=(double)*(float*)(cpu->ecx); const double lift_left=(double)*(float*)(cpu->esi + 0x88u); if (lift_left>lift_right) goto label_0004EAA5; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 4u); const double lift_left=(double)*(float*)(cpu->esi + 0x8Cu); if (lift_left>lift_right) goto label_0004EAA5; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFF0u); const double lift_left=(double)*(float*)(cpu->esi + 0x90u); if (lift_left<lift_right) goto label_0004EAA5; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFF4u); const double lift_left=(double)*(float*)(cpu->esi + 0x94u); if (lift_left<lift_right) goto label_0004EAA5; }
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFFF8u); const double lift_left=(double)*(float*)(cpu->esi + 0x98u); if (lift_left<lift_right) goto label_0004EAA5; }
    *(uint32_t*)(cpu->edx) = (uint64_t)(*(uint32_t*)(cpu->edx)) | (uint64_t)(cpu->edi);
    ++cpu->ebx;
    cpu->edi += cpu->edi;
    if (cpu->ebx == 7u) goto label_0004EAB6;
    label_0004EAA5:
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += 0x3Cu;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) < (int32_t)cpu->ebp) goto label_0004EA30;
    label_0004EAB6:
    cpu->ebx = lift_pop32(cpu);
    label_0004EAB7:
    cpu->edi = 0u;
    if (*(uint8_t*)(cpu->esi + 0x21u) <= 0u) goto label_0004EAE0;
    (void)cpu;
    label_0004EAC0:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x22u);
    cpu->eax = g_sfera_world_render_runtime.active_model;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x4Cu);
    cpu->ecx += cpu->edx;
    cpu->ecx = *(uint8_t*)(cpu->ecx + cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44EAD7u)); sfera_sub_0044E720(cpu, LIFT_CODE_TOKEN_VA(0x44EAD7u));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x21u);
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)cpu->edx) goto label_0004EAC0;
    label_0004EAE0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x68u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044EB00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    bool lift_cmp[1];
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    x87_v1 = 0.20000000298023224;
    lift_push32(cpu, cpu->esi);
    lift_cmp[0]=x87_v1>=x87_v0;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    if (!lift_cmp[0]) goto label_0004EB30;
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    *(float*)(cpu->edi) = (double)(0.0);
    x87_v0 = 1.0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0004EB30:
    x87_v2 = 0.0;
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u);
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (lift_left>lift_right) goto label_0004EB4F; }
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    label_0004EB4F:
    x87_v4 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v4 = (x87_v4) + (x87_v1);
    *(float*)(cpu->esp + 0x14u) = x87_v4; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v0; if (!(lift_left<=lift_right)) goto label_0004EB7A; }
    x87_v0 = x87_v3; 
    x87_v1 = x87_v2; 
    x87_v0 = x87_v1; 
    *(float*)(cpu->edi) = (double)(1.0);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0004EB7A:
    x87_v2 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v2 - x87_v1; 
    x87_v1 = (x87_v1) / (0.019999999552965164);
    *(double*)(cpu->esp + 8u) = x87_v1;
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v0 = std::pow(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->edi) = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi) = ((((double)(1.0))) - (*(double*)(cpu->esp + 4u)));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044EBC0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x3Cu;
    x87_v0 = 1.0;
    lift_push32(cpu, cpu->esi);
    x87_v0 = (x87_v0) - (*(double*)(cpu->ebp + 0x10u));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(double*)(cpu->esp + 0x38u) = x87_v0;
    label_0004EBD9:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    x87_v0 = (x87_v0) / (255.0);
    x87_v1 = *(double*)(cpu->ebp + 8u);
    x87_v0 = std::pow(x87_v0, x87_v1); 
    x87_v0 = (x87_v0) * (*(double*)(cpu->esp + 0x38u));
    x87_v0 = (x87_v0) + (*(double*)(cpu->ebp + 0x10u));
    x87_v1 = 255.0;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0004EC25; }
    x87_v2 = 0.0;
    { const double lift_left=x87_v2; const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0004EC23; }
    x87_v1 = x87_v2; 
    x87_v0 = x87_v1; 
    goto label_0004EC34;
    label_0004EC23:
    x87_v2 = x87_v2; 
    label_0004EC25:
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0004EC32; }
    x87_v0 = x87_v1; 
    goto label_0004EC34;
    label_0004EC32:
    x87_v1 = x87_v1; 
    label_0004EC34:
    x87_v0 = (x87_v0) + (0.5);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = x87_v0;
    x87_v0 = std::floor(*(double*)(cpu->esp));
    *(uint16_t*)(cpu->esp + 0x38u) = cpu->fpu_control;
    ++cpu->esi;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x38u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    cpu->esp += 8u;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x34u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x34u));
    g_sfera_static_render_lookup_runtime.color_remap_a[cpu->esi - 1u] = cpu->eax & 0xFFu;
    g_sfera_static_render_lookup_runtime.color_remap_b[cpu->esi - 1u] = cpu->eax & 0xFFu;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x30u);
    g_sfera_static_render_lookup_runtime.color_remap_c[cpu->esi - 1u] = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x100u) goto label_0004EBD9;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044ECA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    if ((((*(uint8_t*)(void*)&g_sfera_frame_runtime.color_lookup_flags)) & (1u)) != 0u) goto label_0004ECEE;
    g_sfera_frame_runtime.color_lookup_flags = (uint64_t)(g_sfera_frame_runtime.color_lookup_flags) | (uint64_t)(1u);
    cpu->ecx = (uintptr_t)&g_sfera_frame_runtime.color_lookup_object[0];
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44ECE6u)); sfera_sub_00430BB0(cpu, LIFT_CODE_TOKEN_VA(0x44ECE6u));
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    label_0004ECEE:
    if (cpu->esi == 0u) goto label_0004ED56;
    if (g_sfera_view_spatial_runtime.alternate_projection == 1u) goto label_0004ED56;
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->ecx = (uintptr_t)&g_sfera_frame_runtime.color_lookup_object[0];
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x6496C8FFu;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44ED1Fu)); sfera_sub_004309F0(cpu, LIFT_CODE_TOKEN_VA(0x44ED1Fu));
    cpu->ecx = *(uint8_t*)(cpu->esp + cpu->eax + 8u);
    cpu->eax = 0xFFu;
    cpu->eax -= cpu->ecx;
    cpu->edx = 0xFFu;
    cpu->edx -= cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 8u;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0004ED56:
    cpu->eax = 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044ED70(LiftCpu* cpu, uint32_t stop_address) { double x87_p0;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { const double lift_left=(double)*(float*)(cpu->edi); const double lift_right=1e-06; if (!(lift_left>lift_right)) goto label_0004EDC2; }
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x4ED8Cu), LIFT_CODE_TOKEN_RVA(0x4ED8Au))) { return; }
    x87_p0 = (double)*(float*)(cpu->edi);
    x87_p0 = (x87_p0) * (255.0);
    cpu->esp -= 8u;
    cpu->esi = cpu->eax;
    x87_p0 = (x87_p0) + (0.5);
    *(double*)(cpu->esp) = x87_p0;
    x87_p0 = std::floor(*(double*)(cpu->esp));
    cpu->esp += 8u;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->esi;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->esi = 0xFFu;
    cpu->esi -= cpu->edx;
    cpu->esi <<= 16u;
    goto label_0004EDC7;
    label_0004EDC2:
    cpu->esi = 0xFF0000u;
    label_0004EDC7:
    { const double lift_left=(double)*(float*)(cpu->edi + 4u); const double lift_right=1e-06; if (!(lift_left>lift_right)) goto label_0004EE14; }
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x4EDDAu), LIFT_CODE_TOKEN_RVA(0x4EDD8u))) { return; }
    x87_p0 = (double)*(float*)(cpu->edi + 4u);
    x87_p0 = (x87_p0) * (255.0);
    cpu->esp -= 8u;
    cpu->ebp = cpu->eax;
    x87_p0 = (x87_p0) + (0.5);
    *(double*)(cpu->esp) = x87_p0;
    x87_p0 = std::floor(*(double*)(cpu->esp));
    cpu->esp += 8u;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->ebp;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax = 0xFFu;
    cpu->ebp = lift_pop32(cpu);
    cpu->eax -= cpu->edx;
    cpu->eax <<= 8u;
    cpu->esi |= cpu->eax;
    goto label_0004EE1A;
    label_0004EE14:
    cpu->esi |= 0xFF00u;
    label_0004EE1A:
    { const double lift_left=(double)*(float*)(cpu->edi + 8u); const double lift_right=1e-06; if (!(lift_left>lift_right)) goto label_0004EE64; }
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x4EE2Cu), LIFT_CODE_TOKEN_RVA(0x4EE2Au))) { return; }
    x87_p0 = (double)*(float*)(cpu->edi + 8u);
    x87_p0 = (x87_p0) * (255.0);
    cpu->esp -= 8u;
    cpu->ebx = cpu->eax;
    x87_p0 = (x87_p0) + (0.5);
    *(double*)(cpu->esp) = x87_p0;
    x87_p0 = std::floor(*(double*)(cpu->esp));
    cpu->esp += 8u;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->ebx;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax = 0xFFu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax -= cpu->edx;
    cpu->eax |= cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004EE64:
    cpu->esi |= 0xFFu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044EE70(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x50u;
    lift_push32(cpu, 0x44u);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x44EE8Fu));
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v1 = 255.0;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 8u;
    x87_v0 = (x87_v0) / (x87_v1);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u))));
    x87_v1 = (x87_v1) / (x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v0 = ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x58u))))) / (x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    x87_v1 = 0.0;
    *(float*)(cpu->esp + 0x2Cu) = x87_v1;
    *(float*)(cpu->esp + 0x30u) = x87_v1;
    *(float*)(cpu->esp + 0x34u) = x87_v1;
    *(float*)(cpu->esp + 0x4Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x38u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x24u) = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44EF03u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x44EF03u));
    cpu->esp += 0x50u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044EF20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x134u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (!sub_pred[0]) goto label_0004EF40;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44EF3Au)); sfera_sub_0044ED70(cpu, LIFT_CODE_TOKEN_VA(0x44EF3Au));
    *(uint32_t*)(cpu->esi + 0x134u) = cpu->eax;
    label_0004EF40:
    x87_v0 = (double)*(float*)(cpu->esi + 8u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x134u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->esp -= 8u;
    x87_v0 = (double)*(float*)(cpu->esi + 0x10u);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44EF6Du)); sfera_sub_0044ECA0(cpu, LIFT_CODE_TOKEN_VA(0x44EF6Du));
    cpu->ecx = cpu->ebx;
    cpu->ecx >>= 16u;
    cpu->ecx&=0xFFu;
    cpu->ecx *= cpu->eax;
    cpu->edx = cpu->ebx;
    cpu->edx >>= 8u;
    cpu->edx &= 0xFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx&=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->edx;
    cpu->edx = cpu->ebx & 0xFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx&=0xFFFFFF00u;
    cpu->edx >>= 8u;
    cpu->ecx |= cpu->edx;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->eax &= 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->edx = cpu->ecx;
    cpu->edx >>= 8u;
    cpu->edx&=0xFFu;
    cpu->ecx >>= 16u;
    cpu->ecx &= 0xFFu;
    sfera_sub_0044EE70(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0044EFE0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = g_sfera_render_buffer_capacities.vertex32;
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((int32_t)cpu->esi <= (int32_t)cpu->eax) goto label_0004F094;
    cpu->edi = cpu->ecx;
    if (cpu->ecx == cpu->ebx) goto label_0004F031;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F028u)); sfera_sub_004DA450(cpu, LIFT_CODE_TOKEN_VA(0x44F028u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F02Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44F02Eu));
    cpu->esp += 4u;
    label_0004F031:
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.vertex32 = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F04Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x44F04Au));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if (cpu->eax == cpu->ebx) goto label_0004F077;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex32;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x112u);
    cpu->ecx <<= 5u;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F075u)); sfera_sub_004DA720(cpu, LIFT_CODE_TOKEN_VA(0x44F075u));
    goto label_0004F079;
    label_0004F077:
    cpu->eax = 0u;
    label_0004F079:
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_render_buffer_capacities.vertex32;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    g_sfera_sky_runtime.draw_resource = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = cpu->ebx;
    label_0004F094:
    cpu->eax -= (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator);
    cpu->edx = cpu->esp + 0x10u;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if (!sub_pred[0]) goto label_0004F0C1;
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F0B9u)); sfera_sub_004D89E0(cpu, LIFT_CODE_TOKEN_VA(0x44F0B9u));
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = cpu->ebx;
    goto label_0004F0CF;
    label_0004F0C1:
    lift_push32(cpu, 0x1000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4F0CFu)); sfera_sub_004D89E0(cpu, LIFT_CODE_TOKEN_RVA(0x4F0CFu));
    label_0004F0CF:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    cpu->eax <<= 5u;
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F0F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    if ((int32_t)cpu->esi <= (int32_t)cpu->ecx) goto label_0004F1B0;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->edi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0004F147;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F13Eu)); sfera_sub_004DA490(cpu, LIFT_CODE_TOKEN_VA(0x44F13Eu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F144u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44F144u));
    cpu->esp += 4u;
    label_0004F147:
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.index_primary = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F160u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x44F160u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (cpu->eax == 0u) goto label_0004F18F;
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = cpu->ecx + cpu->ecx;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F18Du)); sfera_sub_004DA7D0(cpu, LIFT_CODE_TOKEN_VA(0x44F18Du));
    goto label_0004F191;
    label_0004F18F:
    cpu->eax = 0u;
    label_0004F191:
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = 0u;
    goto label_0004F1B5;
    label_0004F1B0:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    label_0004F1B5:
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07);
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_0004F1FC;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, 0x2000u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F1DCu)); sfera_sub_004D8A40(cpu, LIFT_CODE_TOKEN_VA(0x44F1DCu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = cpu->eax;
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004F1FC:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1000u);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F219u)); sfera_sub_004D8A40(cpu, LIFT_CODE_TOKEN_VA(0x44F219u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07;
    cpu->eax = cpu->ecx + (cpu->edx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F240(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = g_sfera_render_buffer_capacities.vertex28;
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    if ((int32_t)cpu->esi <= (int32_t)cpu->eax) goto label_0004F304;
    cpu->edi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0004F28E;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F285u)); sfera_sub_004DA450(cpu, LIFT_CODE_TOKEN_VA(0x44F285u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F28Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44F28Bu));
    cpu->esp += 4u;
    label_0004F28E:
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.vertex28 = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F2A7u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x44F2A7u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (cpu->eax == 0u) goto label_0004F2E3;
    cpu->edx = g_sfera_render_buffer_capacities.vertex28;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edx * 8u;
    cpu->ecx -= cpu->edx;
    lift_push32(cpu, 0x1C2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F2E1u)); sfera_sub_004DA720(cpu, LIFT_CODE_TOKEN_VA(0x44F2E1u));
    goto label_0004F2E5;
    label_0004F2E3:
    cpu->eax = 0u;
    label_0004F2E5:
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_render_buffer_capacities.vertex28;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    g_sfera_window_runtime.render_vertex_buffer = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = 0u;
    label_0004F304:
    cpu->eax -= (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04);
    cpu->edx = cpu->esp + 0xCu;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if (!sub_pred[0]) goto label_0004F334;
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F32Bu)); sfera_sub_004D89E0(cpu, LIFT_CODE_TOKEN_VA(0x44F32Bu));
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = cpu->eax;
    goto label_0004F349;
    label_0004F334:
    lift_push32(cpu, 0x1000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F344u)); sfera_sub_004D89E0(cpu, LIFT_CODE_TOKEN_VA(0x44F344u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    label_0004F349:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    if ((int32_t)cpu->esi <= (int32_t)cpu->ecx) goto label_0004F430;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0004F3C7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F3BEu)); sfera_sub_004DA490(cpu, LIFT_CODE_TOKEN_VA(0x44F3BEu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F3C4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44F3C4u));
    cpu->esp += 4u;
    label_0004F3C7:
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x18u);
    g_sfera_render_buffer_capacities.index_secondary = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F3E0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x44F3E0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (cpu->eax == 0u) goto label_0004F40F;
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = cpu->ecx + cpu->ecx;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F40Du)); sfera_sub_004DA7D0(cpu, LIFT_CODE_TOKEN_VA(0x44F40Du));
    goto label_0004F411;
    label_0004F40F:
    cpu->eax = 0u;
    label_0004F411:
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = 0u;
    goto label_0004F435;
    label_0004F430:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    label_0004F435:
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08);
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_0004F47C;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, 0x2000u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F45Cu)); sfera_sub_004D8A40(cpu, LIFT_CODE_TOKEN_VA(0x44F45Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = cpu->eax;
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004F47C:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1000u);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F499u)); sfera_sub_004D8A40(cpu, LIFT_CODE_TOKEN_VA(0x44F499u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = cpu->ecx + (cpu->edx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = cpu->ecx;
    label_0004F4C2:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0004F4C2;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx -= cpu->edx;
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    cpu->ebx = cpu->ecx;
    --cpu->edi;
    label_0004F4D6:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu)!=0u) goto label_0004F4D6;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->ebx); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F500(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x1A4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F51Cu)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x44F51Cu));
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    if (cpu->eax == 0u) goto label_0004F567;
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    --cpu->edi;
    label_0004F530:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0004F530;
    *(uint16_t*)(cpu->edi) = cpu->ebx & 0xFFFFu;
    cpu->ecx = cpu->eax;
    label_0004F540:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0004F540;
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0004F551:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0004F551;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->ecx = 0u;
    label_0004F567:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    --cpu->edi;
    label_0004F570:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0004F570;
    *(uint16_t*)(cpu->edi) = cpu->ebx & 0xFFFFu;
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    --cpu->edi;
    label_0004F581:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0004F581;
    cpu->edx = *(uint32_t*)(((uintptr_t)"logs\\Warnings00.log") + 8u);
    cpu->eax = *(uint32_t*)((uintptr_t)"logs\\Warnings00.log");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"logs\\Warnings00.log") + 4u);
    lift_push32(cpu, 0xECu);
    *(uint32_t*)(cpu->esp + 0xB8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xB0u) = cpu->eax;
    cpu->eax = *(uint32_t*)(((uintptr_t)"logs\\Warnings00.log") + 0xCu);
    *(uint32_t*)(cpu->esp + 0xB4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"logs\\Warnings00.log") + 0x10u);
    cpu->edx = cpu->esp + 0xC4u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    *(uint16_t*)(cpu->edi) = cpu->ebx & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0xC4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xC8u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x44F5DAu));
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + 0x30u;
    *(uint8_t*)(cpu->esp + 0xC5u) = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = cpu->esp + 0xB8u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esp + 0xCEu) = cpu->ecx & 0xFFu;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x44F623u));
    cpu->ebx = cpu->eax;
    cpu->esp += 0x14u;
    if (cpu->ebx == 0u) goto label_0004F726;
    sub_pred[0] = (uint32_t)(g_sfera_frame_runtime.warning_header_written) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::fprintf);
    if (!sub_pred[0]) goto label_0004F651;
    lift_push32(cpu, (uintptr_t)"*************************************************************************\n"); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x4F64Eu), LIFT_CODE_TOKEN_RVA(0x4F64Cu))) { return; }
    cpu->esp += 8u;
    label_0004F651:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x44F656u));
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x44F661u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y");
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x44F674u));
    cpu->ecx = cpu->esp + 0x94u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x44F682u));
    cpu->eax = cpu->esp + 0x34u;
    cpu->esp += 0x1Cu;
    --cpu->eax;
    label_0004F690:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0004F690;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x2020)) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"  ") + 2u));
    *(uint16_t*)(cpu->eax) = cpu->edx & 0xFFFFu;
    *(uint8_t*)(cpu->eax + 2u) = cpu->ecx & 0xFFu;
    cpu->eax = cpu->esp + 0x7Cu;
    cpu->edx = cpu->eax;
    label_0004F6B1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0004F6B1;
    cpu->edi = cpu->esp + 0x18u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_0004F6C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0004F6C0;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->ecx = 0u;
    cpu->edi = cpu->esp + 0x18u;
    --cpu->edi;
    label_0004F6E0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0004F6E0;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x4F6FAu), LIFT_CODE_TOKEN_RVA(0x4F6F8u))) { return; }
    lift_push32(cpu, (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0]); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x4F702u), LIFT_CODE_TOKEN_RVA(0x4F700u))) { return; }
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x44F703u));
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x44F70Au));
    cpu->esp += 0x18u;
    lift_push32(cpu, 0xFFFFFFFFu);
    g_sfera_frame_runtime.warning_header_written = 1u;
    lift_native_call(cpu, native_function_address32(&::MessageBeep), LIFT_CODE_TOKEN_VA(0x44F71Fu));
    cpu->ebp = lift_pop32(cpu);
    label_0004F726:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1A4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count) = 3u;
    g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0] = (double)*(float*)(cpu->ecx);
    g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0] = (double)*(float*)(cpu->ecx + 4u);
    g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0] = (double)*(float*)(cpu->ecx + 8u);
    g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[1] = (double)*(float*)(cpu->edx);
    g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[1] = (double)*(float*)(cpu->edx + 4u);
    g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[1] = (double)*(float*)(cpu->edx + 8u);
    g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[2] = (double)*(float*)(cpu->eax);
    g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[2] = (double)*(float*)(cpu->eax + 4u);
    g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[2] = (double)*(float*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F7A1u)); sfera_sub_0044C380(cpu, LIFT_CODE_TOKEN_VA(0x44F7A1u));
    if ((uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count) != 0u) goto label_0004F7AF;
    label_0004F7AA:
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004F7AF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F7B4u)); sfera_sub_0044C4C0(cpu, LIFT_CODE_TOKEN_VA(0x44F7B4u));
    if (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count == 0u) goto label_0004F7AA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F7C2u)); sfera_sub_0044C600(cpu, LIFT_CODE_TOKEN_VA(0x44F7C2u));
    if ((uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count) == 0u) goto label_0004F7AA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F7D0u)); sfera_sub_0044C740(cpu, LIFT_CODE_TOKEN_VA(0x44F7D0u));
    if (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count == 0u) goto label_0004F7AA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F7DEu)); sfera_sub_0044C880(cpu, LIFT_CODE_TOKEN_VA(0x44F7DEu));
    if ((uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count) == 0u) goto label_0004F7AA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44F7ECu)); sfera_sub_0044C9C0(cpu, LIFT_CODE_TOKEN_VA(0x44F7ECu));
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count) != cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F800(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    bool lift_cmp[1];
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->ecx);
    cpu->edx = 0u;
    x87_v0 = fabs(x87_v0);
    *(float*)(cpu->esp) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp);
    x87_v1 = 9.999999747378752e-05;
    lift_cmp[0]=x87_v1>x87_v0;
    x87_v0 = x87_v1; 
    x87_v1 = 0.0;
    if (!lift_cmp[0]) goto label_0004F827;
    *(float*)(cpu->ecx) = x87_v1;
    cpu->edx = 1u;
    label_0004F827:
    *(float*)(cpu->esp) = (fabs(((double)*(float*)(cpu->ecx + 4u))));
    { const double lift_left=(double)*(float*)(cpu->esp); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0004F83F; }
    *(float*)(cpu->ecx + 4u) = x87_v1;
    ++cpu->edx;
    label_0004F83F:
    *(float*)(cpu->esp) = (fabs(((double)*(float*)(cpu->ecx + 8u))));
    x87_v2 = (double)*(float*)(cpu->esp);
    { const double lift_left=x87_v2; const double lift_right=x87_v0;  x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_0004F863; }
    ++cpu->edx;
    *(float*)(cpu->ecx + 8u) = x87_v0; 
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edx == 3u);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004F863:
    cpu->eax = 0u;
    x87_v0 = x87_v0; 
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edx == 3u);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F870(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    cpu->ecx += 0x14u;
    cpu->edi = 7u;
    label_0004F8A0:
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->ecx + 0xFFFFFFF8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    { const double lift_left=(double)*(float*)(cpu->edx); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0004F8BA; }
    *(float*)(cpu->edx) = x87_v0; 
    goto label_0004F8CB;
    label_0004F8BA:
    { const double lift_left=(double)*(float*)(cpu->esi); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0004F8C9; }
    *(float*)(cpu->esi) = x87_v0; 
    goto label_0004F8CB;
    label_0004F8C9:
    x87_v0 = x87_v0; 
    label_0004F8CB:
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->ecx + 0xFFFFFFFCu);
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    { const double lift_left=(double)*(float*)(cpu->edx + 4u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0004F8E7; }
    *(float*)(cpu->edx + 4u) = x87_v0; 
    goto label_0004F8FA;
    label_0004F8E7:
    { const double lift_left=(double)*(float*)(cpu->esi + 4u); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0004F8F8; }
    *(float*)(cpu->esi + 4u) = x87_v0; 
    goto label_0004F8FA;
    label_0004F8F8:
    x87_v0 = x87_v0; 
    label_0004F8FA:
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    { const double lift_left=(double)*(float*)(cpu->edx + 8u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0004F915; }
    *(float*)(cpu->edx + 8u) = x87_v0; 
    goto label_0004F928;
    label_0004F915:
    { const double lift_left=(double)*(float*)(cpu->esi + 8u); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0004F926; }
    *(float*)(cpu->esi + 8u) = x87_v0; 
    goto label_0004F928;
    label_0004F926:
    x87_v0 = x87_v0; 
    label_0004F928:
    cpu->ecx += 0xCu;
    if ((--cpu->edi) != 0u) goto label_0004F8A0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F940(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    label_0004F950:
    cpu->eax = cpu->ecx + cpu->ebx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->edi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    cpu->esi = cpu->ecx;
    cpu->edx = cpu->ebx;
    label_0004F960:
    cpu->eax = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    ++cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_0004F960;
    --cpu->esi;
    label_0004F970:
    cpu->eax = *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    --cpu->edx;
    if ((int32_t)cpu->eax > (int32_t)cpu->edi) goto label_0004F970;
    ++cpu->edx;
    if ((int32_t)cpu->esi > (int32_t)cpu->edx) goto label_0004F9BF;
    cpu->ebp = *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    cpu->eax = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]));
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0])) = cpu->ebp;
    cpu->ebp = *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0])) = cpu->eax;
    cpu->eax = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0])) = cpu->ebp;
    *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0])) = cpu->eax;
    ++cpu->esi;
    --cpu->edx;
    if ((int32_t)cpu->esi <= (int32_t)cpu->edx) goto label_0004F960;
    label_0004F9BF:
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edx) goto label_0004F9C8;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4F9C8u)); sfera_sub_0044F940(cpu, LIFT_CODE_TOKEN_RVA(0x4F9C8u));
    label_0004F9C8:
    if ((int32_t)(cpu->esi) >= (int32_t)(cpu->ebx)) goto label_0004F9D0;
    cpu->ecx = cpu->esi;
    goto label_0004F950;
    label_0004F9D0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044F9E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044FA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->eax += cpu->ecx;
    cpu->eax = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    cpu->eax += *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044FA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    --cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])));
    cpu->eax += *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044FA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044FA70(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    cpu->esp -= 0x1Cu;
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebp);
    x87_v2 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ebp = 0u;
    label_0004FA89:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ebp == 0u) goto label_0004FA93;
    cpu->ebx = cpu->edx;
    label_0004FA93:
    cpu->edi = 0u;
    label_0004FA95:
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    x87_v3 = (double)*(float*)(cpu->ebx + (cpu->eax * 4u) + 4u);
    cpu->esi = cpu->ebx + (cpu->eax * 4u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = x87_v2;
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esi)));
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esi + 8u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    if (cpu->edi != 0u) goto label_0004FAC4;
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FAEC;
    label_0004FAC4:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x30u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0004FAD7; }
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FAEC;
    label_0004FAD7:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v3; if (!(lift_left<lift_right)) goto label_0004FAEA; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    goto label_0004FAEC;
    label_0004FAEA:
    x87_v3 = x87_v3; 
    label_0004FAEC:
    x87_v3 = (double)*(float*)(cpu->esi + 0x10u);
    cpu->ecx = cpu->edi + 1u;
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->esi + 0xCu);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esi + 0x14u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    if (cpu->ecx != 0u) goto label_0004FB18;
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FB40;
    label_0004FB18:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x30u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0004FB2B; }
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FB40;
    label_0004FB2B:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v3; if (!(lift_left<lift_right)) goto label_0004FB3E; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    goto label_0004FB40;
    label_0004FB3E:
    x87_v3 = x87_v3; 
    label_0004FB40:
    cpu->eax = cpu->edi + 2u;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    x87_v3 = (double)*(float*)(cpu->ebx + (cpu->ecx * 4u));
    x87_v3 = (x87_v3) * (x87_v2);
    x87_v4 = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_v4 = (x87_v4) * (x87_v1);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esi + 0x20u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    if (cpu->eax != 0u) goto label_0004FB6F;
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FB97;
    label_0004FB6F:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x30u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0004FB82; }
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FB97;
    label_0004FB82:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v3; if (!(lift_left<lift_right)) goto label_0004FB95; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    goto label_0004FB97;
    label_0004FB95:
    x87_v3 = x87_v3; 
    label_0004FB97:
    cpu->eax = cpu->edi + 3u;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    x87_v3 = (double)*(float*)(cpu->ebx + (cpu->ecx * 4u));
    x87_v3 = (x87_v3) * (x87_v2);
    x87_v4 = (double)*(float*)(cpu->esi + 0x28u);
    x87_v4 = (x87_v4) * (x87_v1);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esi + 0x2Cu);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    if (cpu->eax != 0u) goto label_0004FBC6;
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FBEE;
    label_0004FBC6:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x30u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0004FBD9; }
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    goto label_0004FBEE;
    label_0004FBD9:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v3; if (!(lift_left<lift_right)) goto label_0004FBEC; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    goto label_0004FBEE;
    label_0004FBEC:
    x87_v3 = x87_v3; 
    label_0004FBEE:
    cpu->edi += 4u;
    if ((int32_t)cpu->edi < (int32_t)8u) goto label_0004FA95;
    x87_v3 = (double)*(float*)(cpu->esp + 0x30u);
    ++cpu->ebp;
    *(float*)(cpu->esp + (cpu->ebp * 4u) + 0x20u) = x87_v3; 
    *(float*)(cpu->esp + (cpu->ebp * 4u) + 0x18u) = (double)*(float*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ebp < (int32_t)2u) goto label_0004FA89;
    x87_v0 = x87_v2; 
    cpu->edi = lift_pop32(cpu);
    x87_v1 = x87_v1; 
    cpu->esi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->ebp = lift_pop32(cpu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->ebx = lift_pop32(cpu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left>lift_right) goto label_0004FC4B; }
    { const double lift_right=(double)*(float*)(cpu->esp + 0x10u); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (lift_left>lift_right) goto label_0004FC4B; }
    cpu->eax = 1u;
    cpu->esp += 0x1Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0004FC4B:
    cpu->eax = 0u;
    cpu->esp += 0x1Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044FC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FC76u)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x44FC76u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x4FC85u), LIFT_CODE_TOKEN_RVA(0x4FC83u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044FCB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FCB8u)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x44FCB8u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FCC6u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x44FCC6u));
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0049A4B0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0044FCD0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esp + 0x10u) == cpu->edi) goto label_0004FF75;
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->edi) goto label_0004FF75;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FCFEu)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x44FCFEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FD0Bu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x44FD0Bu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FD12u)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_VA(0x44FD12u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->esi != 0xFFu) goto label_0004FD22;
    if (cpu->eax == cpu->edi) goto label_0004FD31;
    label_0004FD22:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4FD31u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_RVA(0x4FD31u));
    label_0004FD31:
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    x87_v1 = 1.0;
    *(float*)(cpu->esp + 0x20u) = x87_v1;
    x87_v2 = (double)0.0010000000474974513f;
    x87_v3 = (double)*(float*)(cpu->esp + 0x24u);
    { const double lift_left=x87_v3; const double lift_right=x87_v2; x87_v2=x87_v3;  if (!(lift_left>lift_right)) goto label_0004FD96; }
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.x);
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (lift_left>lift_right) goto label_0004FF6C; }
    x87_v4 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.y);
    { const double lift_left=x87_v4; const double lift_right=x87_v2; if (lift_left<lift_right) goto label_0004FF6A; }
    x87_v5 = x87_v4;
    x87_v6 = x87_v3;
    x87_v6 = (x87_v6) * (x87_v5);
    x87_v6 = (x87_v6) / (x87_v2);
    x87_v5 = x87_v5 - x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    x87_v3 = x87_v5 - x87_v3; 
    x87_v3 = x87_v4 / x87_v3; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v3; 
    x87_v3 = 1.0;
    x87_v2 = x87_v3 / x87_v2; 
    *(float*)(cpu->esp + 0x20u) = x87_v2; 
    goto label_0004FD98;
    label_0004FD96:
    x87_v2 = x87_v2; 
    label_0004FD98:
    x87_v2 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi <<= 24u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].z) = x87_v2;
    x87_v3 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    cpu->ecx |= 0xFFFFFFu;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].rhw) = x87_v3;
    g_sfera_scene_render_runtime.textured_quad[0].diffuse = cpu->ecx;
    g_sfera_scene_render_runtime.textured_quad[0].specular = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_0004FDDF;
    x87_v4 = (double)*(float*)(cpu->eax);
    cpu->eax += 8u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u) = x87_v4; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    label_0004FDDF:
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    g_sfera_scene_render_runtime.textured_quad[1].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].z) = x87_v3;
    g_sfera_scene_render_runtime.textured_quad[1].specular = cpu->edi;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].rhw) = x87_v3;
    if (cpu->eax == cpu->edi) goto label_0004FE13;
    x87_v4 = (double)*(float*)(cpu->eax);
    cpu->eax += 8u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u) = x87_v4; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    label_0004FE13:
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    g_sfera_scene_render_runtime.textured_quad[2].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].z) = x87_v3;
    g_sfera_scene_render_runtime.textured_quad[2].specular = cpu->edi;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].rhw) = x87_v3;
    if (cpu->eax == cpu->edi) goto label_0004FE47;
    x87_v4 = (double)*(float*)(cpu->eax);
    cpu->eax += 8u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u) = x87_v4; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    label_0004FE47:
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    g_sfera_scene_render_runtime.textured_quad[3].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].z) = x87_v3; 
    g_sfera_scene_render_runtime.textured_quad[3].specular = cpu->edi;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].rhw) = x87_v2; 
    if (cpu->eax == cpu->edi) goto label_0004FE7E;
    x87_v2 = (double)*(float*)(cpu->eax);
    cpu->eax += 4u;
    cpu->eax += 4u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u) = x87_v2; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    if (cpu->eax != 0u) goto label_0004FEB2;
    label_0004FE7E:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u) = x87_v1; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v) = x87_v0; 
    goto label_0004FEB6;
    label_0004FEB2:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_0004FEB6:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    x87_v1 = 0.5;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    x87_v0 = (x87_v0) - (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x) = x87_v1; 
    x87_v0 = ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))))) - (x87_v0);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); x87_v2 = x87_v1;
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x) = x87_v1; 
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].y) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].x) = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x);
    x87_v1 = (x87_v1) + ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y) = x87_v1; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].x) = x87_v0; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].y) = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FF2Du)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44FF2Du));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FF3Du)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x44FF3Du));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 0xEu); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FF57u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x44FF57u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FF62u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x44FF62u));
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_0004FF6A:
    x87_v2 = x87_v4; 
    label_0004FF6C:
    x87_v2 = x87_v3; 
    cpu->esi = lift_pop32(cpu);
    x87_v2 = x87_v2; 
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_0004FF75:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044FF80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esp + 0x10u) == cpu->edi) goto label_000501B9;
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->edi) goto label_000501B9;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FFAEu)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x44FFAEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FFBBu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x44FFBBu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44FFC2u)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_VA(0x44FFC2u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->esi != 0xFFu) goto label_0004FFD2;
    if (cpu->eax == cpu->edi) goto label_0004FFE1;
    label_0004FFD2:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4FFE1u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_RVA(0x4FFE1u));
    label_0004FFE1:
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x20u);
    x87_v0 = 0.0;
    cpu->eax = *(uint8_t*)(cpu->esp + 0x24u);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].z) = x87_v0;
    x87_v1 = 1.0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].rhw) = x87_v1;
    cpu->edx = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->esi <<= 8u;
    cpu->ecx|=cpu->esi;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->edx;
    g_sfera_scene_render_runtime.textured_quad[0].diffuse = cpu->ecx;
    g_sfera_scene_render_runtime.textured_quad[0].specular = cpu->edi;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->edi) goto label_00050038;
    x87_v2 = (double)*(float*)(cpu->eax);
    cpu->eax += 8u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u) = x87_v2; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    label_00050038:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    g_sfera_scene_render_runtime.textured_quad[1].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].z) = x87_v1;
    g_sfera_scene_render_runtime.textured_quad[1].specular = cpu->edi;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].rhw) = x87_v1;
    if (cpu->eax == cpu->edi) goto label_0005006C;
    x87_v2 = (double)*(float*)(cpu->eax);
    cpu->eax += 8u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u) = x87_v2; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    label_0005006C:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    g_sfera_scene_render_runtime.textured_quad[2].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].z) = x87_v1;
    g_sfera_scene_render_runtime.textured_quad[2].specular = cpu->edi;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].rhw) = x87_v1;
    if (cpu->eax == cpu->edi) goto label_000500A0;
    x87_v2 = (double)*(float*)(cpu->eax);
    cpu->eax += 8u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u) = x87_v2; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    label_000500A0:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    g_sfera_scene_render_runtime.textured_quad[3].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].z) = x87_v1;
    g_sfera_scene_render_runtime.textured_quad[3].specular = cpu->edi;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].rhw) = x87_v1;
    if (cpu->eax == cpu->edi) goto label_000500D9;
    x87_v2 = (double)*(float*)(cpu->eax);
    cpu->eax += 4u;
    cpu->eax += 4u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u) = x87_v2; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    if (cpu->eax != 0u) goto label_0005010D;
    label_000500D9:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u) = x87_v1; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v) = x87_v0; 
    goto label_00050111;
    label_0005010D:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00050111:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u))));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    x87_v1 = 0.5;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    x87_v0 = (x87_v0) - (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x) = x87_v1; 
    x87_v0 = ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))))) - (x87_v0);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); x87_v2 = x87_v1;
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x) = x87_v1; 
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].y) = x87_v1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].x) = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x);
    x87_v1 = (x87_v1) + ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y) = x87_v1; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].x) = x87_v0; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].y) = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450188u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x450188u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450198u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x450198u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4501AEu)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4501AEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x501B9u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_RVA(0x501B9u));
    label_000501B9:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x24u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004501C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)g_sfera_recovered_static_runtime.animation_phase;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (x87_v0) * (3.1415929794311523);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    x87_v0 = (x87_v0) + (x87_v0);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v2 = 0.019999999552965164;
    x87_v1 = (x87_v1) * (x87_v2);
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u); x87_v4 = x87_v3;
    x87_v5 = 0.0;
    x87_v4 = (x87_v4) * (x87_v5);
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 8u) = x87_v4; 
    x87_v2 = x87_v2 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esi))) + (((double)*(float*)(cpu->esp + 0x10u))));
    *(float*)(cpu->edi) = ((((double)*(float*)(cpu->edi))) + (((double)*(float*)(cpu->esp + 8u))));
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi) = (double)*(float*)(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00450260(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[5]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0xF4u;
    cpu->eax = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->eax + 4u) == cpu->ebx) goto label_000509E0;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    if (*(uint32_t*)(cpu->ecx + 4u) == cpu->ebx) goto label_000509E0;
    ++g_sfera_effect_manager.generation;
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4502A3u)); sfera_sub_00427550(cpu, LIFT_CODE_TOKEN_VA(0x4502A3u));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    if (cpu->eax == cpu->ebx) goto label_000509E0;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4502B7u)); sfera_sub_00425CD0(cpu, LIFT_CODE_TOKEN_VA(0x4502B7u));
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].y);
    x87_v0 = (x87_v0) * (0.44999998807907104);
    cpu->esi = cpu->eax;
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].x);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esi;
    x87_v1 = (x87_v1) * (0.3100000023841858);
    x87_v0 = x87_v0 + x87_v1; 
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].z);
    x87_v1 = (x87_v1) * (0.23999999463558197);
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->eax += 0x14u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->esi);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    cpu->edi = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi &= 1u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450335u)); sfera_sub_00425CE0(cpu, LIFT_CODE_TOKEN_VA(0x450335u));
    cpu->ebx = cpu->eax;
    cpu->esi = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450346u)); sfera_sub_00425CC0(cpu, LIFT_CODE_TOKEN_VA(0x450346u));
    *(uint32_t*)(cpu->ebx) = 0u;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edi;
    *(uint32_t*)(cpu->ebx + 0xCu) = cpu->ebp;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_00050365;
    cpu->ecx = 0x7530u;
    label_00050365:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45036Au)); sfera_sub_0044F240(cpu, LIFT_CODE_TOKEN_VA(0x45036Au));
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0xA8u) = x87_v0;
    *(float*)(cpu->esp + 0xA4u) = x87_v0;
    cpu->edx = cpu->esp + 0x70u;
    *(float*)(cpu->esp + 0xA0u) = x87_v0;
    lift_push32(cpu, cpu->edx);
    *(float*)(cpu->esp + 0xA0u) = x87_v0;
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0x9Cu) = x87_v0;
    cpu->ebp = cpu->eax;
    *(float*)(cpu->esp + 0x98u) = x87_v0;
    *(float*)(cpu->esp + 0x94u) = x87_v0;
    *(float*)(cpu->esp + 0x90u) = x87_v0;
    *(float*)(cpu->esp + 0x88u) = x87_v0;
    *(float*)(cpu->esp + 0x84u) = x87_v0;
    *(float*)(cpu->esp + 0x80u) = x87_v0;
    *(float*)(cpu->esp + 0x7Cu) = x87_v0; 
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0xB4u) = x87_v0;
    *(float*)(cpu->esp + 0xA0u) = x87_v0;
    *(float*)(cpu->esp + 0x8Cu) = x87_v0;
    *(float*)(cpu->esp + 0x78u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4503EFu)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x4503EFu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4503FEu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x4503FEu));
    sub_pred[3] = *(uint32_t*)(cpu->esp + 0x48u) <= 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = 0u;
    if (sub_pred[3]) goto label_000508A2;
    x87_v0 = 255.0;
    cpu->eax = cpu->esp + 0xC0u;
    x87_v1 = 1.0;
    cpu->eax &= 0xFFFFFFF0u;
    x87_v2 = 0.0;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->eax;
    goto label_0005042F;
    label_0005042B:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0005042F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->ecx * 2u));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x98u);
    cpu->eax &= 1u;
    if (cpu->edi != cpu->eax) goto label_0005045E;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->edx == *(uint32_t*)(cpu->ebx + 0x90u)) goto label_00050490;
    label_0005045E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->ecx;
    cpu->edx -= *(uint32_t*)(cpu->esi);
    cpu->esi += 0x10u;
    ++*(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0xFFFFFFF4u) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x90u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x90u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    label_00050490:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x94u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x5Cu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_000504AD;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFFu;
    label_000504AD:
    if (((*(uint8_t*)(cpu->ebx + 0x98u)) & (2u)) != 0u) goto label_000504DE;
    *(float*)(cpu->ebx + 0x70u) = x87_v2;
    *(float*)(cpu->ebx + 0x74u) = x87_v2;
    *(float*)(cpu->ebx + 0x7Cu) = x87_v2;
    *(float*)(cpu->ebx + 0x88u) = x87_v2;
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->ebx + 0x78u) = x87_v2;
    *(float*)(cpu->ebx + 0x80u) = x87_v2;
    *(float*)(cpu->ebx + 0x84u) = x87_v2;
    *(float*)(cpu->ebx + 0x8Cu) = x87_v2;
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    label_000504DE:
    cpu->eax = cpu->ebx;
    cpu->ecx = cpu->ebx + 0x74u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ecx;
    cpu->ebx += 0x30u;
    *(uint32_t*)(cpu->esp + 0x24u) = 4u;
    goto label_000504FC;
    label_000504F8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    label_000504FC:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->esp + 0xB0u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->edx;
    x87_v3 = (double)*(float*)(cpu->esp + 0x60u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = (uintptr_t)&g_sfera_model_transform_scratch_matrix;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB0u);
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edx;
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x64u))) - (((double)*(float*)(cpu->eax + 0x1Cu))));
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->eax + 0x18u)));
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x68u))) - (((double)*(float*)(cpu->eax + 0x2Cu))));
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->eax + 0x28u)));
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v4 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[0].y);
    { const double lift_left=x87_v4; const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0005058A; }
    x87_v3 = x87_v4; 
    cpu->eax = 0xFFu;
    x87_v3 = x87_v3; 
    goto label_000505B6;
    label_0005058A:
    x87_v5 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[0].z);
    { const double lift_left=x87_v5; const double lift_right=x87_v3; if (!(lift_left<lift_right)) goto label_000505A3; }
    x87_v5 = x87_v5; 
    cpu->eax = 0u;
    x87_v3 = x87_v4; 
    x87_v3 = x87_v3; 
    goto label_000505B6;
    label_000505A3:
    x87_v6 = x87_v5;
    x87_v3 = x87_v6 - x87_v3; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v5 = (x87_v5) * (x87_v0);
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    x87_v3 = x87_v3 / x87_v4; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    label_000505B6:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    *(float*)(cpu->ebp) = (double)*(float*)(cpu->edi);
    *(float*)(cpu->ebp + 4u) = (double)*(float*)(cpu->edi + 4u);
    *(float*)(cpu->ebp + 8u) = (double)*(float*)(cpu->edi + 8u);
    cpu->esi = *(uint32_t*)(cpu->ebx);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x38u));
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x80808081u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x80808081u * (int32_t)(cpu->esi))) >> 32u);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->ecx <<= 8u;
    cpu->esi &= 0xFFu;
    cpu->esi |= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x38u));
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x80808081u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    cpu->esi <<= 8u;
    cpu->ecx &= 0xFFu;
    cpu->esi |= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x38u));
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x80808081u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax&=0xFFu;
    cpu->esi <<= 8u;
    cpu->esi |= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    cpu->edi += 0xCu;
    x87_v3 = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    cpu->eax += 8u;
    *(float*)(cpu->ebp + 0x14u) = x87_v3; 
    cpu->ebp += 0x1Cu;
    x87_v3 = (double)*(float*)(cpu->eax + 0xFFFFFFF8u);
    cpu->ebx += 4u;
    --*(uint32_t*)(cpu->esp + 0x24u); sub_pred[1] = *(uint32_t*)(cpu->esp + 0x24u) == 0u;
    *(float*)(cpu->ebp + 0xFFFFFFFCu) = x87_v3; 
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    if (!sub_pred[1]) goto label_000504F8;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->ecx = cpu->edi + 1u;
    *(uint16_t*)(cpu->ebx + (cpu->eax * 2u) + 2u) = cpu->ecx & 0xFFFFu;
    cpu->ecx = cpu->edi + 2u;
    cpu->edx = cpu->edi + 3u;
    *(uint16_t*)(cpu->ebx + (cpu->eax * 2u)) = cpu->edi & 0xFFFFu;
    *(uint16_t*)(cpu->ebx + (cpu->eax * 2u) + 4u) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->ebx + (cpu->eax * 2u) + 6u) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->ebx + (cpu->eax * 2u) + 0xAu) = cpu->edi & 0xFFFFu;
    *(uint16_t*)(cpu->ebx + (cpu->eax * 2u) + 8u) = cpu->edx & 0xFFFFu;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    cpu->edi += 4u;
    cpu->eax += 6u;
    cpu->ecx += 0xFFFFFFF8u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((int32_t)cpu->edi > (int32_t)cpu->ecx) goto label_000506E4;
    if ((int32_t)cpu->eax <= (int32_t)0x752Au) goto label_00050881;
    label_000506E4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = x87_v2; 
    cpu->eax -= *(uint32_t*)(cpu->ecx);
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450708u)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x450708u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax += g_sfera_render_buffer_capacities.vertex28;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax <= 0) goto label_00050808;
    cpu->esi = cpu->ebp + 4u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    label_00050733:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esp + 0x30u) == cpu->eax) goto label_00050757;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0005074E;
    lift_push32(cpu, 6u);
    goto label_00050750;
    label_0005074E:
    lift_push32(cpu, 2u);
    label_00050750:
    lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x50757u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_RVA(0x50757u));
    label_00050757:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->eax) goto label_0005078B;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0005078B;
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450772u)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x450772u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450780u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x450780u));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450787u)); sfera_sub_0049A4B0(cpu, LIFT_CODE_TOKEN_VA(0x450787u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    label_0005078B:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->ecx <= 0) goto label_000507FB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450796u)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x450796u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + (cpu->edx * 2u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4507A3u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4507C0u)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x4507C0u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4507F3u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x4507F3u));
    cpu->edx = *(uint32_t*)(cpu->esi);
    g_sfera_client_config_runtime.state_08 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    label_000507FB:
    cpu->esi += 0x10u;
    if ((--*(uint32_t*)(cpu->esp + 0x24u)) != 0u) goto label_00050733;
    label_00050808:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = 0u;
    cpu->eax = cpu->esi + 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->ebp) = cpu->edx;
    if (cpu->eax >= *(uint32_t*)(cpu->esp + 0x48u)) goto label_00050852;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u) + 2u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->ecx &= 1u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    goto label_00050856;
    label_00050852:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00050856:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->ecx;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450873u)); sfera_sub_0044F240(cpu, LIFT_CODE_TOKEN_VA(0x450873u));
    x87_v0 = 255.0;
    x87_v1 = 1.0;
    cpu->ebp = cpu->eax;
    x87_v2 = 0.0;
    goto label_00050885;
    label_00050881:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    label_00050885:
    ++cpu->esi;
    sub_pred[0] = cpu->esi < *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (sub_pred[0]) goto label_0005042B;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    x87_v0 = x87_v2; 
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_000508A2:
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4508B7u)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x4508B7u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    cpu->ebp = cpu->eax;
    cpu->eax += g_sfera_render_buffer_capacities.vertex28;
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x1Cu) == 0u; sub_pred[4] = (int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) < (int32_t)(0u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = cpu->eax;
    if ((sub_pred[2]) || (sub_pred[4])) goto label_000509C3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax -= *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax <= 0) goto label_000509C3;
    cpu->esi = cpu->ebx + 4u;
    cpu->ebx = cpu->eax;
    label_000508F0:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esp + 0x30u) == cpu->eax) goto label_00050914;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0005090B;
    lift_push32(cpu, 6u);
    goto label_0005090D;
    label_0005090B:
    lift_push32(cpu, 2u);
    label_0005090D:
    lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x50914u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_RVA(0x50914u));
    label_00050914:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->eax) goto label_00050944;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00050944;
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45092Fu)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x45092Fu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45093Du)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x45093Du));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x50944u)); sfera_sub_0049A4B0(cpu, LIFT_CODE_TOKEN_RVA(0x50944u));
    label_00050944:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->ecx <= 0) goto label_000509B9;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45094Fu)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x45094Fu));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->edx = cpu->ecx + (cpu->edx * 2u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x450960u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45097Cu)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x45097Cu));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4509B1u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x4509B1u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    g_sfera_client_config_runtime.state_08 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000509B9:
    cpu->esi += 0x10u;
    if ((--cpu->ebx) != 0u) goto label_000508F0;
    label_000509C3:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4509CEu)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x4509CEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4509DDu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x4509DDu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000509E0:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xF4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00450A00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].x);
    *(uint16_t*)(cpu->esp + 2u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 2u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 4u);
    *(uint64_t*)(cpu->esp + 4u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 2u);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].y);
    *(uint16_t*)(cpu->esp + 2u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 2u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 4u);
    *(uint64_t*)(cpu->esp + 4u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx &= 0xFFu;
    cpu->ecx|=cpu->edx;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 2u);
    cpu->ecx <<= 8u;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].z);
    *(uint16_t*)(cpu->esp + 2u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 2u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 4u);
    *(uint64_t*)(cpu->esp + 4u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax &= 0xFFu;
    cpu->ecx |= cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 2u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x8Bu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450AA7u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x450AA7u));
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00450AB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x48u;
    lift_push32(cpu, 0x44u);
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x450AC7u));
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 4u) = x87_v0;
    cpu->ecx = cpu->esp;
    *(float*)(cpu->esp + 8u) = x87_v0;
    lift_push32(cpu, cpu->ecx);
    x87_v1 = (double)*(float*)(cpu->esp + 0x50u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = 0.0;
    *(float*)(cpu->esp + 0x24u) = x87_v1;
    *(float*)(cpu->esp + 0x28u) = x87_v1;
    *(float*)(cpu->esp + 0x2Cu) = x87_v1;
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450B12u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x450B12u));
    cpu->esp += 0x48u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00450B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x646E616Cu;
    lift_push32(cpu, cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->ecx;
    cpu->ecx = 0x70616373u;
    cpu->ebp = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x5C65)) & 0xFFFFu);
    (*(uint8_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[10]) = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx & 0xFFFFu;
    cpu->ecx = cpu->eax;
    label_00050B70:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00050B70;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050B81:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00050B81;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00050BA0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050BA0;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450BBEu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x450BBEu));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450BCAu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x450BCAu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450BD1u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x450BD1u));
    if (cpu->esi != 0xFFFFFFFFu) goto label_00050D97;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x72685F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx;
    cpu->ecx = cpu->eax;
    label_00050C10:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00050C10;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050C21:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00050C21;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00050C40:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050C40;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450C5Eu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x450C5Eu));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450C6Au)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x450C6Au));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0xFFFFFFFFu) goto label_00050D97;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x68705F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx;
    cpu->ecx = cpu->eax;
    label_00050CA7:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00050CA7;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050CB8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00050CB8;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00050CD4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050CD4;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450CF9u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x450CF9u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450D00u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x450D00u));
    if (cpu->esi != 0xFFFFFFFFu) goto label_00050D97;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x64725F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx;
    cpu->ecx = cpu->eax;
    label_00050D40:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00050D40;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050D51:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00050D51;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00050D70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050D70;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450D95u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x450D95u));
    cpu->esi = cpu->eax;
    label_00050D97:
    lift_push32(cpu, 4u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450DA2u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x450DA2u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450DAFu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x450DAFu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450DB6u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x450DB6u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00450DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->eax = (uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    label_00050DE2:
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x50u;
    label_00050DF0:
    if (*(uint8_t*)(cpu->ebp + 0x14u) != 0u) goto label_000510B2;
    if (*(uint8_t*)(cpu->ebp + 0x15u) != 0u) goto label_000510B2;
    cpu->edx = cpu->ebx;
    cpu->eax = cpu->ebp;
    cpu->edx -= cpu->ebp;
    label_00050E10:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050E10;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x5C65)) & 0xFFFFu);
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    (*(uint8_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[10]) = cpu->eax & 0xFFu;
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx & 0xFFFFu;
    cpu->ecx = cpu->eax;
    label_00050E50:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00050E50;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050E61:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00050E61;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00050E80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050E80;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450E9Eu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x450E9Eu));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450EAAu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x450EAAu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450EB1u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x450EB1u));
    if (cpu->esi != 0xFFFFFFFFu) goto label_00051077;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x72685F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx;
    cpu->ecx = cpu->eax;
    label_00050EF0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00050EF0;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050F01:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00050F01;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00050F20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050F20;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450F3Eu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x450F3Eu));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450F4Au)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x450F4Au));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0xFFFFFFFFu) goto label_00051077;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x68705F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx;
    cpu->ecx = cpu->eax;
    label_00050F87:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00050F87;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00050F98:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00050F98;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00050FB4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00050FB4;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450FD9u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x450FD9u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x450FE0u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x450FE0u));
    if (cpu->esi != 0xFFFFFFFFu) goto label_00051077;
    cpu->eax = 0x646E616Cu;
    cpu->ecx = 0x70616373u;
    cpu->edx = 0x64725F65u;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[0]) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x005C)) & 0xFFFFu);
    (*(uint16_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[12]) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[4]) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_landscape_probe_runtime.size_path[8]) = cpu->edx;
    cpu->ecx = cpu->eax;
    label_00051020:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00051020;
    cpu->edi = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00051031:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00051031;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    --cpu->eax;
    label_00051050:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00051050;
    cpu->ecx = 0x7A69732Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_probe_runtime.size_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451075u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x451075u));
    cpu->esi = cpu->eax;
    label_00051077:
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451084u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x451084u));
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451091u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x451091u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451098u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x451098u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x18u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Cu));
    cpu->eax = 0x14u;
    *(uint8_t*)(cpu->eax + cpu->ebx) = cpu->ecx & 0xFFu;
    cpu->eax = 0x15u;
    *(uint8_t*)(cpu->eax + cpu->ebx) = cpu->edx & 0xFFu;
    goto label_000510C6;
    label_000510B2:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x10u) = cpu->eax;
    *(uint16_t*)(cpu->ebx + 0x14u) = cpu->eax & 0xFFFFu;
    label_000510C6:
    cpu->ebp += 0x16u;
    cpu->ebx += 0x6E0u;
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_00050DF0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx += 0x16u;
    cpu->eax = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)cpu->ebp < (int32_t)((uintptr_t)&g_sfera_landscape_map_runtime.records[kLandscapeMapRecordCount])) goto label_00050DE2;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->edx + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->edx + (cpu->eax * 2u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u) + 0x8Cu);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->esi = cpu->ebx + 0x18u;
    *(uint32_t*)(cpu->esp + 0xCu) = 4u;
    cpu->edi = 0u;
    lift_push32(cpu, cpu->ebp);
    label_00051130:
    *(uint32_t*)(cpu->esp + 0x20u) = 4u;
    label_00051140:
    cpu->ebp = 9u;
    label_00051145:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == cpu->edi) goto label_0005115C;
    lift_push32(cpu, 0x4392u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45115Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45115Au));
    *(uint32_t*)(cpu->esi) = cpu->edi;
    label_0005115C:
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->edi) goto label_0005117A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->ecx == cpu->edi) goto label_0005117A;
    lift_push32(cpu, 0x4393u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451177u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451177u));
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edi;
    label_0005117A:
    cpu->esi += 0x30u;
    if ((--cpu->ebp) != 0u) goto label_00051145;
    if ((--*(uint32_t*)(cpu->esp + 0x20u)) != 0u) goto label_00051140;
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_00051130;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1B0Cu);
    cpu->ebp = lift_pop32(cpu);
    if (cpu->ecx == cpu->edi) goto label_000511AC;
    lift_push32(cpu, 0x4395u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4511A6u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4511A6u));
    *(uint32_t*)(cpu->ebx + 0x1B0Cu) = cpu->edi;
    label_000511AC:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1B10u);
    if (cpu->ecx == cpu->edi) goto label_000511CB;
    lift_push32(cpu, 0x4396u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4511C5u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4511C5u));
    *(uint32_t*)(cpu->ebx + 0x1B10u) = cpu->edi;
    label_000511CB:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1B14u);
    if (cpu->ecx == cpu->edi) goto label_000511EA;
    lift_push32(cpu, 0x4397u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4511E4u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4511E4u));
    *(uint32_t*)(cpu->ebx + 0x1B14u) = cpu->edi;
    label_000511EA:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1B18u);
    if (cpu->ecx == cpu->edi) goto label_00051209;
    lift_push32(cpu, 0x4398u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451203u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451203u));
    *(uint32_t*)(cpu->ebx + 0x1B18u) = cpu->edi;
    label_00051209:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1B1Cu);
    if (cpu->ecx == cpu->edi) goto label_00051228;
    lift_push32(cpu, 0x4399u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451222u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451222u));
    *(uint32_t*)(cpu->ebx + 0x1B1Cu) = cpu->edi;
    label_00051228:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    if (cpu->ecx == cpu->edi) goto label_00051241;
    lift_push32(cpu, 0x439Au);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45123Eu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45123Eu));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edi;
    label_00051241:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x68A0u);
    if (cpu->ecx == cpu->edi) goto label_00051260;
    lift_push32(cpu, 0x439Bu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45125Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45125Au));
    *(uint32_t*)(cpu->ebx + 0x68A0u) = cpu->edi;
    label_00051260:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x68A4u);
    if (cpu->ecx == cpu->edi) goto label_0005127F;
    lift_push32(cpu, 0x439Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451279u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451279u));
    *(uint32_t*)(cpu->ebx + 0x68A4u) = cpu->edi;
    label_0005127F:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x68A8u);
    if (cpu->ecx == cpu->edi) goto label_0005129E;
    lift_push32(cpu, 0x439Du);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451298u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451298u));
    *(uint32_t*)(cpu->ebx + 0x68A8u) = cpu->edi;
    label_0005129E:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x68ACu);
    if (cpu->ecx == cpu->edi) goto label_000512BD;
    lift_push32(cpu, 0x439Eu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4512B7u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4512B7u));
    *(uint32_t*)(cpu->ebx + 0x68ACu) = cpu->edi;
    label_000512BD:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x687Cu);
    if (cpu->ecx == cpu->edi) goto label_000512DC;
    lift_push32(cpu, 0x439Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4512D6u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4512D6u));
    *(uint32_t*)(cpu->ebx + 0x687Cu) = cpu->edi;
    label_000512DC:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x6880u);
    if (cpu->ecx == cpu->edi) goto label_000512FB;
    lift_push32(cpu, 0x43A0u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4512F5u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4512F5u));
    *(uint32_t*)(cpu->ebx + 0x6880u) = cpu->edi;
    label_000512FB:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x6884u);
    if (cpu->ecx == cpu->edi) goto label_0005131A;
    lift_push32(cpu, 0x43A1u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451314u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451314u));
    *(uint32_t*)(cpu->ebx + 0x6884u) = cpu->edi;
    label_0005131A:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x6888u);
    if (cpu->ecx == cpu->edi) goto label_00051339;
    lift_push32(cpu, 0x43A2u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451333u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451333u));
    *(uint32_t*)(cpu->ebx + 0x6888u) = cpu->edi;
    label_00051339:
    lift_push32(cpu, 0x43A3u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45134Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45134Au));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x3ACu);
    if (cpu->ecx == cpu->edi) goto label_00051373;
    lift_push32(cpu, 0x43A4u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45136Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45136Cu));
    *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x3ACu) = cpu->edi;
    label_00051373:
    *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x8Cu) = cpu->edi;
    --g_sfera_recovered_static_runtime.client_state_03;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = cpu->edx;
    cpu->eax = 0u;
    cpu->edx = 0u;
    lift_push32(cpu, (uintptr_t)"wb"); lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esp + 0x18u) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x19u) = 0x200u;
    *(uint16_t*)(cpu->esp + 0x1Du) = cpu->edx & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0x1Fu) = cpu->eax & 0xFFu;
    *(uint16_t*)(cpu->esp + 0x24u) = cpu->esi & 0xFFFFu;
    *(uint16_t*)(cpu->esp + 0x26u) = cpu->esi & 0xFFFFu;
    *(uint16_t*)(cpu->esp + 0x28u) = 0x2010u;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4513DCu));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp != 0u) goto label_000513FF;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000513FF:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fwrite);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, 0x12u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x51412u), LIFT_CODE_TOKEN_RVA(0x51410u))) { return; }
    cpu->esp += 0x10u;
    if ((int32_t)cpu->esi <= 0) goto label_00051433;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_00051420:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x51427u), LIFT_CODE_TOKEN_RVA(0x51425u))) { return; }
    cpu->esp += 0x10u;
    --*(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = cpu->edi + (cpu->esi * 2u);
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0u) goto label_00051420;
    label_00051433:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x451434u));
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451460(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    x87_v1 = x87_v0;
    cpu->edi = (cpu->edi & 0xFFFF0000u) | ((cpu->ecx & 0xFFFFu) & 0xFFFFu);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v2 = 400.0; x87_v3 = x87_v2;
    x87_v0 = x87_v0 / x87_v3; 
    x87_v3 = 1000.0;
    x87_v0 = (x87_v0) + (x87_v3);
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    cpu->eax -= 0x3E8u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v3 = (x87_v3) * (x87_v2);
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    cpu->eax <<= 8u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v2 = (x87_v2) / (x87_v1);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v2 = x87_v1;
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    x87_v4 = x87_v3;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v4); 
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v4 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v5 = x87_v1;
    x87_v3 = x87_v3 / x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    x87_v0 = x87_v0 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    cpu->eax -= 0x3E8u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v3 = (x87_v3) * (x87_v2);
    x87_v0 = x87_v0 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v0 = x87_v0 - x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v1 = (x87_v1) * (256.0);
    x87_v0 = x87_v1 / x87_v0; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    if ((int32_t)cpu->esi >= 0) goto label_0005151A;
    cpu->esi = 0u;
    goto label_00051527;
    label_0005151A:
    if ((int32_t)cpu->esi <= (int32_t)0xFFu) goto label_00051527;
    cpu->esi = 0xFFu;
    label_00051527:
    if ((int32_t)cpu->eax >= 0) goto label_0005152F;
    cpu->eax=0u;
    goto label_0005153B;
    label_0005152F:
    if ((cpu->eax == 0xFFu) || ((int32_t)(cpu->eax) < (int32_t)(0xFFu))) goto label_0005153B;
    cpu->eax = 0xFFu;
    label_0005153B:
    cpu->eax <<= 8u;
    cpu->eax += cpu->esi;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0])) = (uint64_t)(*(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0]))) ^ (uint64_t)((cpu->edi & 0xFFFFu));
    cpu->eax = (cpu->eax * 2u) + ((uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0]);
    lift_push32(cpu, (uintptr_t)&g_sfera_scene_build_runtime.landscape_debug_pixels[0]);
    cpu->edx = 0x100u;
    cpu->ecx = (uintptr_t)"lndbug.tga";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451563u)); sfera_sub_00451390(cpu, LIFT_CODE_TOKEN_VA(0x451563u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->edx + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451580(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    bool lift_cmp[1];
    x87_v0 = 1.0;
    cpu->esp -= 0xCu;
    x87_v1 = (double)g_sfera_recovered_static_runtime.transition_factor;
    lift_cmp[0]=x87_v1<=x87_v0;
    x87_v0 = x87_v1; 
    x87_v1 = 1.0;
    x87_v2 = 0.0;
    if (!lift_cmp[0]) goto label_000515B8;
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.direction_x.f32);
    x87_v3 = (x87_v3) * (x87_v0);
    *(float*)(cpu->esp) = x87_v3; 
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.direction_y.f32);
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v2; 
    goto label_0005165A;
    label_000515B8:
    x87_v0 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.direction_y.f32);
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.direction_x.f32);
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)g_sfera_recovered_static_runtime.transition_factor;
    x87_v1 = 1.0;
    x87_v0 = (x87_v0) - (x87_v1);
    x87_v2 = (double)*(float*)(cpu->esp + 4u); x87_v3 = x87_v2;
    x87_v3 = (0.00019999999494757503) - (x87_v3);
    x87_v0 = x87_v0 * x87_v3; 
    x87_v3 = x87_v2;
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp) = x87_v2; 
    x87_v2 = x87_v0;
    x87_v2 = fabs(x87_v2);
    *(float*)(cpu->esp + 4u) = x87_v2; 
    { const double lift_left=(double)*(float*)(cpu->esp + 4u); const double lift_right=((double)9.999999747378752e-06f); if (!(lift_left<lift_right)) goto label_00051632; }
    x87_v0 = x87_v1; 
    x87_v1 = 0.0;
    *(float*)(cpu->esp) = x87_v1;
    *(float*)(cpu->esp + 4u) = x87_v1;
    goto label_00051658;
    label_00051632:
    x87_v2 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.direction_x.f32);
    x87_v2 = (x87_v2) / (x87_v0);
    x87_v3 = (double)*(float*)(cpu->esp); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp) = x87_v3; 
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.direction_y.f32);
    x87_v0 = x87_v3 / x87_v0; 
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v1; 
    x87_v1 = 0.0;
    label_00051658:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_0005165A:
    x87_v2 = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32);
    x87_v3 = (double)*(float*)(cpu->esp); x87_v4 = x87_v3;
    x87_v2 = x87_v2 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32) = x87_v3; 
    x87_v3 = 1.0;
    x87_v4 = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32);
    { const double lift_left=x87_v4; const double lift_right=x87_v3; if (!(lift_left>=lift_right)) goto label_0005168E; }
    x87_v4 = (x87_v4) - (x87_v1);
    *(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32) = x87_v4; 
    x87_v4 = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32);
    label_0005168E:
    { const double lift_left=x87_v4; const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_000516A1; }
    x87_v4 = (x87_v4) + (x87_v1);
    *(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_y.f32) = x87_v4; 
    goto label_000516A3;
    label_000516A1:
    x87_v4 = x87_v4; 
    label_000516A3:
    x87_v4 = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32);
    x87_v5 = (double)*(float*)(cpu->esp + 4u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 + x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32) = x87_v5; 
    x87_v5 = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32);
    { const double lift_left=x87_v5; const double lift_right=x87_v3; x87_v3=x87_v5;  if (!(lift_left>=lift_right)) goto label_000516DC; }
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    x87_v4 = (x87_v4) - (x87_v1);
    *(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32) = x87_v4; 
    x87_v4 = (double)*(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32);
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    label_000516DC:
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    { const double lift_left=x87_v4; const double lift_right=x87_v3;  if (!(lift_left>lift_right)) goto label_000516F3; }
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)((uintptr_t)&g_sfera_landscape_render_runtime.view_offset_x.f32) = x87_v2; 
    goto label_000516F7;
    label_000516F3:
    x87_v3 = x87_v3; 
    x87_v1 = x87_v2; 
    label_000516F7:
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_world_render_runtime.world_spatial_index;
    if (cpu->esi == 0u) goto label_000517C4;
    if (g_sfera_main_render_runtime.grass_depth_mode != 2u) goto label_000517C4;
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = (double)9.999999747378752e-06f;
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_00051767; }
    x87_v0 = x87_v0; 
    cpu->esp -= 0xCu;
    x87_v0 = 0.0;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 8u) = x87_v0;
    *(float*)(cpu->esp + 4u) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451762u)); sfera_sub_00424680(cpu, LIFT_CODE_TOKEN_VA(0x451762u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00051767:
    x87_v1 = (double)*(float*)(cpu->esp + 4u);
    x87_v1 = -x87_v1;
    x87_v1 = (x87_v1) / (x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    x87_v1 = -x87_v1;
    x87_v1 = (x87_v1) / (x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    x87_v0 = (x87_v0) / (0.00198);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = 1.0;
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esp + 8u)); if (!(lift_left<lift_right)) goto label_0005179C; }
    *(float*)(cpu->esp + 8u) = x87_v0; 
    goto label_0005179E;
    label_0005179C:
    x87_v0 = x87_v0; 
    label_0005179E:
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4517BFu)); sfera_sub_00424680(cpu, LIFT_CODE_TOKEN_VA(0x4517BFu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000517C4:
    x87_v0 = x87_v1; 
    cpu->esi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004517D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25 == 0u) goto label_0005188C;
    if ((int32_t)g_sfera_recovered_static_runtime.view_transition_counter > (int32_t)0u) goto label_000517EF;
    x87_v0 = (double)0.0010000000474974513f;
    goto label_000517FB;
    label_000517EF:
    x87_v0 = (double)0.019999999552965164f;
    --g_sfera_recovered_static_runtime.view_transition_counter;
    label_000517FB:
    *(float*)(cpu->esp) = x87_v0; 
    x87_v0 = (double)20.0f;
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.frame_interval.f32);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_0005184B; }
    x87_v0 = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 - x87_v0; 
    x87_v0 = (x87_v0) * (((double)g_sfera_graphics_runtime.saved_fog_distance));
    g_sfera_graphics_runtime.saved_fog_distance = x87_v0; 
    { const double lift_left=(double)g_sfera_graphics_runtime.saved_fog_distance; const double lift_right=30.0; if (!(lift_left<lift_right)) goto label_0005188C; }
    g_sfera_graphics_runtime.saved_fog_distance = (double)30.0f;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005184B:
    { const double lift_left=x87_v0; const double lift_right=28.0;  if (!(lift_left>lift_right)) goto label_0005188C; }
    g_sfera_graphics_runtime.saved_fog_distance = (((((((double)*(float*)(cpu->esp))) + (1.0)))) * (((double)g_sfera_graphics_runtime.saved_fog_distance)));
    { const double lift_left=(double)g_sfera_graphics_runtime.saved_fog_distance; const double lift_right=200.0; if (!(lift_left>lift_right)) goto label_0005188C; }
    g_sfera_graphics_runtime.saved_fog_distance = (double)200.0f;
    label_0005188C:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4518A6u)); sfera_sub_004BB800(cpu, LIFT_CODE_TOKEN_VA(0x4518A6u));
    lift_push32(cpu, 0x180u); lift_push32(cpu, (uintptr_t)"loadcount.bin");
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x4518B0u));
    cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"loadcount.bin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4518C3u)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x4518C3u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uintptr_t)&g_sfera_main_view_state_runtime.view_accumulator;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4518D3u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4518D3u));
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0042F180(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004518E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp) = (double)(0.0);
    x87_v0 = 0.004999999888241291;
    x87_v1 = 0.000122499996908009;
    x87_v2 = 0.04899999985843895;
    x87_v3 = (double)*(float*)(cpu->esp);
    label_000518FD:
    x87_v4 = x87_v3;
    x87_v4 = -x87_v4;
    *(float*)(cpu->esp + 8u) = x87_v4; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esp) = (double)(0.0);
    x87_v4 = (double)*(float*)(cpu->esp);
    goto label_00051919;
    label_00051917:
    x87_v4 = x87_v5; 
    label_00051919:
    *(float*)(cpu->esp + 0xCu) = x87_v4;
    x87_v5 = (double)*(float*)(cpu->esp + 4u); x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (x87_v0);
    x87_v6 = (x87_v6) + (x87_v1);
    x87_v4 = x87_v4 + x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp) = x87_v5; 
    x87_v4 = (x87_v4) + (x87_v2);
    *(float*)(cpu->esp + 4u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v5 = (double)*(float*)(cpu->esp);
    { const double lift_left=x87_v5; const double lift_right=x87_v4; if (lift_left<lift_right) goto label_00051917; }
    x87_v5 = x87_v5; 
    x87_v4 = -x87_v4;
    x87_v4 = (x87_v4) * (10.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v4); 
    if (cpu->eax > 0x63u) goto label_00051963;
    *(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_physics_runtime.response_curve[0])) = (double)*(float*)(cpu->esp + 8u);
    label_00051963:
    x87_v3 = (x87_v3) + (0.009999999776482582);
    *(float*)(cpu->esp) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp);
    { const double lift_left=x87_v3; const double lift_right=14.0; if (lift_left<lift_right) goto label_000518FD; }
    x87_v0 = x87_v3; 
    x87_v1 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451990(LiftCpu* cpu, uint32_t stop_address) { double x87_p0;
    if ((int32_t)cpu->ecx < 0) goto label_000519A1;
    if (cpu->ecx >= 0x64u) goto label_000519A1;
    x87_p0 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_physics_runtime.response_curve[0]));
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000519A1:
    x87_p0 = 0.0;
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004519B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->ecx = g_sfera_window_runtime.input_runtime_object;
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4519CDu)); sfera_sub_00489830(cpu, LIFT_CODE_TOKEN_VA(0x4519CDu));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004519D0(LiftCpu* cpu, uint32_t stop_address) { double x87_p0, x87_p1;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    x87_p1 = 40.74365997314453;
    x87_p0 = (x87_p0) * (x87_p1);
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p1); 
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0xCu)));
    cpu->esi = cpu->eax;
    cpu->esi &= 0xFFu;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->eax &= 0xFFu;
    cpu->esi -= cpu->eax;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)cpu->eax < (int32_t)0x80u) goto label_00051A1A;
    cpu->ecx = 0x100u;
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    label_00051A1A:
    *(float*)(cpu->esp + 4u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u)))))) * (0.024543695894260174));
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx & 0xFFu;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03) = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451A40(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->eax);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp) = x87_v0; 
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->ecx + 4u))));
    *(float*)(cpu->esp + 8u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    x87_v0 = (double)*(float*)(cpu->edx);
    x87_v1 = (double)*(float*)(cpu->esp); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->edx + 4u)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 8u); x87_v4 = x87_v3;
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->edx + 8u)));
    x87_v0 = x87_v0 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u); x87_v4 = x87_v3;
    x87_v4 = fabs(x87_v4);
    *(float*)(cpu->esp + 0x18u) = x87_v4; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x18u); const double lift_right=((double)1.1754943508222875e-38f); if (!(lift_left<=lift_right)) goto label_00051ABC; }
    x87_v3 = x87_v3; 
    cpu->eax = 0u;
    x87_v1 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00051ABC:
    x87_v4 = (double)*(float*)(cpu->edx);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->ecx)));
    x87_v5 = (double)*(float*)(cpu->edx + 4u);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->ecx + 4u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->ecx + 8u);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->edx + 8u)));
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->esp + 0x18u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v4 = (x87_v4) + (((double)*(float*)(cpu->edx + 0xCu)));
    cpu->edx = 0xFFFFFFFEu;
    *(float*)(cpu->esp + 0x18u) = x87_v4; 
    x87_v4 = 0.0;
    x87_v5 = (double)*(float*)(cpu->esp + 0x18u);
    { const double lift_left=x87_v5; const double lift_right=x87_v4; if (lift_left<lift_right) goto label_00051AF8; }
    cpu->edx = 1u;
    label_00051AF8:
    x87_v5 = (x87_v5) / (x87_v3);
    *(float*)(cpu->esp + 0x18u) = x87_v5; 
    { const double lift_left=x87_v4; const double lift_right=x87_v3;   if (!(lift_left<lift_right)) goto label_00051B08; }
    ++cpu->edx;
    label_00051B08:
    x87_v3 = (double)*(float*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u); x87_v5 = x87_v4;
    x87_v1 = x87_v1 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    x87_v1 = x87_v4 - x87_v1; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->eax) = x87_v3; 
    x87_v3 = x87_v1;
    x87_v2 = x87_v2 * x87_v3; 
    x87_v2 = (((double)*(float*)(cpu->ecx + 4u))) - (x87_v2);
    *(float*)(cpu->eax + 4u) = x87_v2; 
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (((double)*(float*)(cpu->ecx + 8u))) - (x87_v0);
    *(float*)(cpu->eax + 8u) = x87_v0; 
    cpu->eax = cpu->edx;
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451B40(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    bool lift_cmp[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->edi);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (fabs(((double)*(float*)(cpu->esp + 0x18u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = (fabs(((double)*(float*)(cpu->edi + 4u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_00051B7E; }
    x87_v0 = (double)*(float*)(cpu->edi + 4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    label_00051B7E:
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->esi = 0u;
    x87_v0 = fabs(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x18u) = (fabs(((double)*(float*)(cpu->edi + 8u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    lift_cmp[0]=x87_v1>x87_v0;  
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (!lift_cmp[0]) goto label_00051C0D;
    if ((int32_t)cpu->eax <= 0) goto label_00051C00;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = 0.0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = (cpu->eax * 4u) + 0xFFFFFFFCu;
    label_00051BBD:
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ebx);
    x87_v1 = (double)*(float*)(cpu->eax + 4u);
    cpu->edx = cpu->esi * 4u;
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ebx);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx + 4u)));
    x87_v2 = (double)*(float*)(cpu->ebp);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->eax)));
    x87_v1 = x87_v1 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->eax)));
    x87_v3 = (double)*(float*)(cpu->ebp + 4u);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->eax + 4u)));
    x87_v2 = x87_v2 * x87_v3; 
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->edi + 8u)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (lift_left<lift_right) goto label_00051CD1; }
    ++cpu->esi;
    cpu->eax = cpu->edx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_00051BBD;
    x87_v0 = x87_v0; 
    label_00051C00:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00051C0D:
    if ((cpu->ecx & 0xFFu) == 0u) goto label_00051C72;
    if ((int32_t)cpu->eax <= 0) goto label_00051C00;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = 0.0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = (cpu->eax * 4u) + 0xFFFFFFFCu;
    label_00051C26:
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ebx);
    x87_v1 = (double)*(float*)(cpu->eax + 8u);
    cpu->edx = cpu->esi * 4u;
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ebx);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx + 8u)));
    x87_v2 = (double)*(float*)(cpu->ebp + 4u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->eax + 4u)));
    x87_v1 = x87_v1 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ecx + 4u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->eax + 4u)));
    x87_v3 = (double)*(float*)(cpu->ebp + 8u);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->eax + 8u)));
    x87_v2 = x87_v2 * x87_v3; 
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->edi)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (lift_left<lift_right) goto label_00051CD1; }
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_00051C26;
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00051C72:
    if ((int32_t)cpu->eax <= 0) goto label_00051C00;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = 0.0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = (cpu->eax * 4u) + 0xFFFFFFFCu;
    label_00051C87:
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ebx);
    cpu->edx = cpu->esi * 4u;
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ebx);
    x87_v1 = (double)*(float*)(cpu->ecx + 8u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 8u)));
    x87_v2 = (double)*(float*)(cpu->ebp);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->eax)));
    x87_v1 = x87_v1 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ebp + 8u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->eax + 8u)));
    x87_v3 = (double)*(float*)(cpu->eax);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->ecx)));
    x87_v2 = x87_v2 * x87_v3; 
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->edi + 4u)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (lift_left<lift_right) goto label_00051CD1; }
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_00051C87;
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00051CD1:
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00051D04;
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D04u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51D04u));
    label_00051D04:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00051D13;
    cpu->ecx = cpu->edi + 8u;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D13u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51D13u));
    label_00051D13:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi + (cpu->esi * 2u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00051D34;
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D34u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51D34u));
    label_00051D34:
    if ((int32_t)(cpu->esi) < (int32_t)(*(uint32_t*)(cpu->edi + 4u))) goto label_00051D43;
    cpu->ecx = cpu->edi + 8u;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D43u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51D43u));
    label_00051D43:
    cpu->eax = cpu->esi + (cpu->esi * 4u);
    cpu->eax <<= 4u;
    cpu->eax += *(uint32_t*)(cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->edi >= 0) goto label_00051D64;
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D64u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51D64u));
    label_00051D64:
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00051D73;
    cpu->ecx = cpu->esi + 8u;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D73u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51D73u));
    label_00051D73:
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x27188u);
    cpu->eax += *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451D90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00051DA4;
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51DA4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51DA4u));
    label_00051DA4:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00051DB3;
    cpu->ecx = cpu->edi + 8u;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51DB3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51DB3u));
    label_00051DB3:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi + (cpu->esi * 8u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451DC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451DC8u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x451DC8u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00051DF5;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x451DD4u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x451DDBu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x451DE2u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00051DF5:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451E00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    cpu->edi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_00051EA1;
    label_00051E15:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00051E29;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51E29u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x51E29u));
    label_00051E29:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_00051E37;
    ++cpu->esi;
    goto label_00051E15;
    label_00051E37:
    cpu->edx = 0xD71u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451E46u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x451E46u));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00051E5A;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51E5Au)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x51E5Au));
    label_00051E5A:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->eax == 0u) goto label_00051E76;
    g_sfera_main_command_state_runtime.object_reference_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count)) - 1u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451E73u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x451E73u));
    cpu->esp += 4u;
    label_00051E76:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00051E8A;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51E8Au)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x51E8Au));
    label_00051E8A:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = 0u;
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_00051E15;
    label_00051EA1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451EB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0x8Cu;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451ED5u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x451ED5u));
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x88u) = x87_v0;
    *(float*)(cpu->esp + 0x84u) = x87_v0;
    cpu->eax = cpu->esp + 0x50u;
    *(float*)(cpu->esp + 0x80u) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x80u) = x87_v0;
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0x7Cu) = x87_v0;
    *(float*)(cpu->esp + 0x78u) = x87_v0;
    *(float*)(cpu->esp + 0x74u) = x87_v0;
    *(float*)(cpu->esp + 0x70u) = x87_v0;
    *(float*)(cpu->esp + 0x68u) = x87_v0;
    *(float*)(cpu->esp + 0x64u) = x87_v0;
    *(float*)(cpu->esp + 0x60u) = x87_v0;
    *(float*)(cpu->esp + 0x5Cu) = x87_v0; 
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x94u) = x87_v0;
    *(float*)(cpu->esp + 0x80u) = x87_v0;
    *(float*)(cpu->esp + 0x6Cu) = x87_v0;
    *(float*)(cpu->esp + 0x58u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451F40u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x451F40u));
    cpu->esi = 0u;
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count <= (int32_t)cpu->esi) goto label_000526D9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = 0xFF000000u;
    label_00051F57:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00051F6B;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51F6Bu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x51F6Bu));
    label_00051F6B:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 0u) goto label_00051F7A;
    ++cpu->esi;
    goto label_00051F57;
    label_00051F7A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00051F8E;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51F8Eu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x51F8Eu));
    label_00051F8E:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edi = cpu->edx + (cpu->esi * 4u);
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00051FAB;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51FABu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x51FABu));
    label_00051FAB:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->ecx))) - (((double)*(float*)(cpu->eax + 0xCu))));
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->ecx + 4u))) - (((double)*(float*)(cpu->eax + 0x10u))));
    *(float*)(cpu->esp + 0x3Cu) = ((((double)*(float*)(cpu->ecx + 8u))) - (((double)*(float*)(cpu->eax + 0x14u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v1 = 0.0;
    x87_v2 = x87_v1;
    { const double lift_left=x87_v2; const double lift_right=x87_v0;  x87_v0=x87_v1;  if (lift_left!=lift_right) goto label_00052008; }
    { const double lift_right=(double)*(float*)(cpu->esp + 0x38u); const double lift_left=x87_v0; if (lift_left!=lift_right) goto label_00052008; }
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left==lift_right) goto label_000526C9; }
    goto label_0005200A;
    label_00052008:
    x87_v0 = x87_v0; 
    label_0005200A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005201E;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5201Eu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5201Eu));
    label_0005201E:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edi = cpu->edx + (cpu->esi * 4u);
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0005203E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5203Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5203Eu));
    label_0005203E:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edx + 8u)));
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052066;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52066u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52066u));
    label_00052066:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = cpu->eax + (cpu->esi * 4u);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00052085;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52085u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52085u));
    label_00052085:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_000520AE;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x520AEu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x520AEu));
    label_000520AE:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_000520CE;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x520CEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x520CEu));
    label_000520CE:
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx + 0x10u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x3Cu); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x28u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 0x18u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x24u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x34u); x87_v6 = x87_v5;
    x87_v2 = x87_v2 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v2 = x87_v5 - x87_v2; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v4; 
    x87_v1 = x87_v1 * x87_v3; 
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v1 - x87_v0; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u);
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
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu);
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
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x30u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = 0.0010000000474974513;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052216;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52216u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52216u));
    label_00052216:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0]) = ((((double)*(float*)(cpu->eax))) + (((double)*(float*)(cpu->esp + 0x40u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005223F;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5223Fu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5223Fu));
    label_0005223F:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x4]) = ((((double)*(float*)(cpu->edx + 4u))) + (((double)*(float*)(cpu->esp + 0x44u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052269;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52269u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52269u));
    label_00052269:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x8]) = ((((double)*(float*)(cpu->ecx + 8u))) + (((double)*(float*)(cpu->esp + 0x48u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052292;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52292u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52292u));
    label_00052292:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x1C]) = ((((double)*(float*)(cpu->eax))) - (((double)*(float*)(cpu->esp + 0x40u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_000522BB;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x522BBu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x522BBu));
    label_000522BB:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x20]) = ((((double)*(float*)(cpu->edx + 4u))) - (((double)*(float*)(cpu->esp + 0x44u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_000522E5;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x522E5u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x522E5u));
    label_000522E5:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x24]) = ((((double)*(float*)(cpu->ecx + 8u))) - (((double)*(float*)(cpu->esp + 0x48u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005230E;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5230Eu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5230Eu));
    label_0005230E:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edi = cpu->edx + (cpu->esi * 4u);
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0005232E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5232Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5232Eu));
    label_0005232E:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edx + 8u)));
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052357;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52357u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52357u));
    label_00052357:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = cpu->eax + (cpu->esi * 4u);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00052376;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52376u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52376u));
    label_00052376:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005239F;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5239Fu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5239Fu));
    label_0005239F:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = 1u;
    cpu->edi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_000523BF;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x523BFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x523BFu));
    label_000523BF:
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)*(float*)(cpu->edx + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx + 0x10u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x3Cu); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x28u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 0x18u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x24u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x34u); x87_v6 = x87_v5;
    x87_v2 = x87_v2 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v2 = x87_v5 - x87_v2; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v4; 
    x87_v1 = x87_v1 * x87_v3; 
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v1 - x87_v0; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u);
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
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu);
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
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x30u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = 0.0010000000474974513;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x4Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x50u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x54u) = x87_v0; 
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052507;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52507u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52507u));
    label_00052507:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x38]) = ((((double)*(float*)(cpu->eax + 0xCu))) - (((double)*(float*)(cpu->esp + 0x4Cu))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052531;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52531u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52531u));
    label_00052531:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x3C]) = ((((double)*(float*)(cpu->edx + 0x10u))) - (((double)*(float*)(cpu->esp + 0x50u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005255B;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5255Bu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5255Bu));
    label_0005255B:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x40]) = ((((double)*(float*)(cpu->ecx + 0x14u))) - (((double)*(float*)(cpu->esp + 0x54u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052584;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52584u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52584u));
    label_00052584:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x54]) = ((((double)*(float*)(cpu->eax + 0xCu))) + (((double)*(float*)(cpu->esp + 0x4Cu))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_000525AE;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x525AEu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x525AEu));
    label_000525AE:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x58]) = ((((double)*(float*)(cpu->edx + 0x10u))) + (((double)*(float*)(cpu->esp + 0x50u))));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_000525D8;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x525D8u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x525D8u));
    label_000525D8:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    x87_v0 = (double)*(float*)(cpu->ecx + 0x14u);
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x28]) = cpu->ebx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x54u)));
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0xC]) = cpu->ebx;
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x60]) = cpu->ebx;
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x44]) = cpu->ebx;
    *(float*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x5C]) = x87_v0; 
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052619;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52619u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52619u));
    label_00052619:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x10]) = cpu->ecx;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005263F;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5263Fu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5263Fu));
    label_0005263F:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x2C]) = cpu->ecx;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_00052665;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52665u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x52665u));
    label_00052665:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x48]) = cpu->ecx;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005268B;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5268Bu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5268Bu));
    label_0005268B:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    *(uint32_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0x64]) = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4526ADu)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x4526ADu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_collision_scratch_runtime.debug_vertices[0]); lift_push32(cpu, 6u); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x526C9u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_RVA(0x526C9u));
    label_000526C9:
    ++cpu->ebp;
    ++cpu->esi;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count) goto label_00051F57;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000526D9:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004526F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1B0Cu);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    g_sfera_recovered_static_runtime.client_state_01 = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)*(uint32_t*)(cpu->edi + 8u) <= (int32_t)cpu->ebx) goto label_00052810;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    label_00052740:
    cpu->ebp = 3u;
    label_00052745:
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->esi = *(uint16_t*)(cpu->ebx + cpu->edx);
    if ((int32_t)cpu->esi >= 0) goto label_0005275A;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5275Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5275Au));
    label_0005275A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.microtexture_handles.capacity) goto label_0005276E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5276Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5276Eu));
    label_0005276E:
    cpu->eax = g_sfera_landscape_runtime.microtexture_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0xFFFFFFFFu) goto label_000527E5;
    if ((int32_t)cpu->esi >= 0) goto label_00052787;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52787u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x52787u));
    label_00052787:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.microtexture_handles.capacity) goto label_0005279B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5279Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5279Bu));
    label_0005279B:
    cpu->ecx = g_sfera_recovered_static_runtime.client_state_01;
    cpu->edx = g_sfera_landscape_runtime.microtexture_handles.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_01;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    g_sfera_recovered_static_runtime.client_state_01 = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_000527C5;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x527C5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x527C5u));
    label_000527C5:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.surface_handles.capacity) goto label_000527D9;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x527D9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x527D9u));
    label_000527D9:
    cpu->eax = g_sfera_scene_array_runtime.surface_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = cpu->esi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_000527E5:
    cpu->ebx += 2u;
    if ((--cpu->ebp) != 0u) goto label_00052745;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->eax;
    cpu->ebx += 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 8u)) goto label_00052740;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00052810:
    cpu->ecx = g_sfera_recovered_static_runtime.client_state_01;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if ((int32_t)g_sfera_recovered_static_runtime.client_state_01 <= (int32_t)cpu->ebx) goto label_000528BF;
    (void)cpu;
    label_00052830:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0005284B;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5284Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5284Bu));
    label_0005284B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.surface_records.capacity) goto label_0005285F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5285Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5285Fu));
    label_0005285F:
    cpu->ecx = g_sfera_scene_array_runtime.surface_records.data;
    cpu->eax = cpu->esi + (cpu->esi * 4u);
    cpu->edi = cpu->ecx + (cpu->eax * 8u);
    if ((int32_t)cpu->ebx >= 0) goto label_00052879;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52879u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x52879u));
    label_00052879:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_scene_array_runtime.surface_handles.capacity) goto label_0005288D;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5288Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5288Du));
    label_0005288D:
    cpu->edx = g_sfera_scene_array_runtime.surface_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->ebx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->esi = cpu->edx + (cpu->eax * 8u);
    ++cpu->ebx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),40u); cpu->esi += 40u; cpu->edi += 40u; cpu->ecx = 0u;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_recovered_static_runtime.client_state_01) goto label_00052830;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000528BF:
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_02;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->edi + 8u) <= (int32_t)cpu->eax) goto label_00052983;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000528E0:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp = 3u;
    label_000528F0:
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_02;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_client_main_scalar_runtime.counter_02 = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0005290B;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5290Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5290Bu));
    label_0005290B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.surface_index_map.capacity) goto label_0005291F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5291Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5291Fu));
    label_0005291F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = g_sfera_scene_array_runtime.surface_index_map.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edi = cpu->edx + (cpu->esi * 2u);
    cpu->esi = *(uint16_t*)(cpu->ebx + cpu->ecx);
    if ((int32_t)cpu->esi >= 0) goto label_00052941;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52941u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x52941u));
    label_00052941:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.microtexture_handles.capacity) goto label_00052955;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52955u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52955u));
    label_00052955:
    cpu->edx = g_sfera_landscape_runtime.microtexture_handles.data;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx + (cpu->esi * 4u)));
    cpu->ebx += 2u;
    --cpu->ebp;
    *(uint16_t*)(cpu->edi) = cpu->eax & 0xFFFFu;
    if (cpu->ebp != 0u) goto label_000528F0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx + 8u)) goto label_000528E0;
    label_00052983:
    cpu->esi = 0u;
    if ((int32_t)g_sfera_recovered_static_runtime.client_state_01 <= (int32_t)cpu->esi) goto label_000529F2;
    label_00052990:
    if ((int32_t)cpu->esi >= 0) goto label_0005299E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5299Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5299Eu));
    label_0005299E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.surface_handles.capacity) goto label_000529B2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x529B2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x529B2u));
    label_000529B2:
    cpu->edx = g_sfera_scene_array_runtime.surface_handles.data;
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if ((int32_t)cpu->edi >= 0) goto label_000529C9;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x529C9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x529C9u));
    label_000529C9:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_landscape_runtime.microtexture_handles.capacity) goto label_000529DD;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x529DDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x529DDu));
    label_000529DD:
    cpu->eax = g_sfera_landscape_runtime.microtexture_handles.data;
    ++cpu->esi;
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = 0xFFFFFFFFu;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_recovered_static_runtime.client_state_01) goto label_00052990;
    label_000529F2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00452A00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebx + 0x1B0Cu) != cpu->esi) goto label_00052A29;
    lift_push32(cpu, 0x1367u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xB40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452A23u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452A23u));
    *(uint32_t*)(cpu->ebx + 0x1B0Cu) = cpu->eax;
    label_00052A29:
    if (*(uint32_t*)(cpu->ebx + 0x1B10u) != cpu->esi) goto label_00052A4B;
    lift_push32(cpu, 0x1369u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xB40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452A45u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452A45u));
    *(uint32_t*)(cpu->ebx + 0x1B10u) = cpu->eax;
    label_00052A4B:
    lift_push32(cpu, cpu->ebp);
    g_sfera_client_main_scalar_runtime.counter_02 = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state) = cpu->esi;
    cpu->esi = cpu->ebx + 0xCu;
    *(uint32_t*)(cpu->esp + 0xCu) = 4u;
    lift_push32(cpu, cpu->edi);
    label_00052A64:
    cpu->ebp = 4u;
    label_00052A70:
    cpu->edi = 9u;
    label_00052A75:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452A7Eu)); sfera_sub_004526F0(cpu, LIFT_CODE_TOKEN_VA(0x452A7Eu));
    cpu->esi += 0x30u;
    if ((--cpu->edi) != 0u) goto label_00052A75;
    if ((--cpu->ebp) != 0u) goto label_00052A70;
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_00052A64;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 0x1B14u) == cpu->ebp;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00052ABA;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x1374u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452AB4u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452AB4u));
    *(uint32_t*)(cpu->ebx + 0x1B14u) = cpu->eax;
    label_00052ABA:
    if (*(uint32_t*)(cpu->ebx + 0x1B18u) != 0u) goto label_00052AE0;
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_02;
    lift_push32(cpu, 0x1376u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452ADAu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452ADAu));
    *(uint32_t*)(cpu->ebx + 0x1B18u) = cpu->eax;
    label_00052AE0:
    if ((int32_t)g_sfera_scene_array_runtime.surface_records.capacity > (int32_t)0u) goto label_00052AF5;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52AF5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52AF5u));
    label_00052AF5:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state;
    cpu->ecx = g_sfera_scene_array_runtime.surface_records.data;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1B14u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x452B12u));
    cpu->esp += 0xCu;
    if ((int32_t)g_sfera_scene_array_runtime.surface_index_map.capacity > (int32_t)0u) goto label_00052B2F;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52B2Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52B2Fu));
    label_00052B2F:
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_02;
    cpu->edx = g_sfera_scene_array_runtime.surface_index_map.data;
    cpu->ecx = cpu->eax + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1B18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x452B46u));
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00452B60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    bool lift_cmp[4];
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, 0x139Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452B7Bu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452B7Bu));
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x452B88u));
    x87_v0 = (double)-0.009999999776482582f;
    x87_v1 = (double)0.009999999776482582f;
    cpu->ecx = 0u;
    x87_v2 = 99.98999786376953;
    cpu->esp += 0xCu;
    x87_v3 = 100.01000213623047;
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ecx) goto label_00052EA8;
    cpu->edi = 0u;
    goto label_00052BBB;
    label_00052BB9:
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    label_00052BBB:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    lift_cmp[0]=x87_v3<(((double)*(float*)(cpu->edx + cpu->edi)));
    cpu->edx += cpu->edi;
    if (!lift_cmp[0]) goto label_00052BF6;
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v3; const double lift_right=((double)*(float*)(cpu->edx)); if (!(lift_left>lift_right)) goto label_00052BF4; }
    { const double lift_left=(double)*(float*)(cpu->edx + 8u); const double lift_right=x87_v2; if (!(lift_left>lift_right)) goto label_00052BF4; }
    { const double lift_left=(double)*(float*)(cpu->edx + 8u); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00052BF4; }
    *(uint8_t*)(cpu->ecx + cpu->ebx) = 1u;
    ++cpu->ebp;
    label_00052BF4:
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    label_00052BF6:
    ++cpu->ecx;
    cpu->edi += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052BB9;
    x87_v3 = x87_v3; 
    label_00052C01:
    x87_v1 = x87_v2; 
    lift_push32(cpu, 0x13B1u);
    x87_v1 = x87_v1; 
    cpu->ecx = cpu->ebp + cpu->ebp;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    x87_v0 = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x688Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452C20u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452C20u));
    *(uint32_t*)(cpu->esi + 0x687Cu) = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->eax) goto label_00052C4D;
    cpu->ecx = 0u;
    (void)cpu;
    label_00052C30:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) != 1u) goto label_00052C47;
    *(uint8_t*)(cpu->eax + cpu->ebx) = 2u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x687Cu);
    *(uint16_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFFFu;
    cpu->ecx += 2u;
    label_00052C47:
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052C30;
    label_00052C4D:
    cpu->ecx = 0u;
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ecx) goto label_00052CAA;
    x87_v0 = 100.01000213623047;
    cpu->ebp = 0u;
    x87_v1 = 99.98999786376953;
    label_00052C64:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    x87_v2 = (double)*(float*)(cpu->edx + cpu->ebp);
    cpu->edx += cpu->ebp;
    { const double lift_left=x87_v2; const double lift_right=x87_v1;  if (!(lift_left>lift_right)) goto label_00052C9D; }
    { const double lift_left=(double)*(float*)(cpu->edx); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00052C9D; }
    { const double lift_left=(double)*(float*)(cpu->edx + 8u); const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_00052C9D; }
    { const double lift_left=(double)*(float*)(cpu->edx + 8u); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00052C9D; }
    *(uint8_t*)(cpu->ecx + cpu->ebx) = 1u;
    ++cpu->edi;
    label_00052C9D:
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052C64;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00052CAA:
    lift_push32(cpu, 0x13C9u);
    cpu->ecx = cpu->edi + cpu->edi;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esi + 0x6890u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452CC2u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452CC2u));
    *(uint32_t*)(cpu->esi + 0x6880u) = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->eax) goto label_00052CEE;
    cpu->ecx = 0u;
    label_00052CD1:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) != 1u) goto label_00052CE8;
    *(uint8_t*)(cpu->eax + cpu->ebx) = 2u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x6880u);
    *(uint16_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFFFu;
    cpu->ecx += 2u;
    label_00052CE8:
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052CD1;
    label_00052CEE:
    cpu->ecx = 0u;
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ecx) goto label_00052D4B;
    x87_v0 = (double)0.009999999776482582f;
    cpu->ebp = 0u;
    x87_v1 = (double)-0.009999999776482582f;
    label_00052D05:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_cmp[1]=x87_v1<(((double)*(float*)(cpu->edx + cpu->ebp)));
    cpu->edx += cpu->ebp;
    if (!lift_cmp[1]) goto label_00052D3E;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    lift_cmp[2]=x87_v1>(((double)*(float*)(cpu->edx)));
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    if (!lift_cmp[2]) goto label_00052D3E;
    { const double lift_left=x87_v1; const double lift_right=((double)*(float*)(cpu->edx + 8u)); if (!(lift_left<lift_right)) goto label_00052D3E; }
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    { const double lift_left=x87_v1; const double lift_right=((double)*(float*)(cpu->edx + 8u)); if (!(lift_left>lift_right)) goto label_00052D3C; }
    *(uint8_t*)(cpu->ecx + cpu->ebx) = 1u;
    ++cpu->edi;
    label_00052D3C:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_00052D3E:
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052D05;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00052D4B:
    lift_push32(cpu, 0x13E1u);
    cpu->ecx = cpu->edi + cpu->edi;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esi + 0x6894u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452D63u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452D63u));
    *(uint32_t*)(cpu->esi + 0x6884u) = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->eax) goto label_00052D8F;
    cpu->ecx = 0u;
    label_00052D72:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) != 1u) goto label_00052D89;
    *(uint8_t*)(cpu->eax + cpu->ebx) = 2u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x6884u);
    *(uint16_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFFFu;
    cpu->ecx += 2u;
    label_00052D89:
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052D72;
    label_00052D8F:
    cpu->ecx = 0u;
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ecx) goto label_00052DFC;
    x87_v0 = 100.01000213623047;
    cpu->ebp = 0u;
    x87_v1 = 99.98999786376953;
    x87_v2 = (double)0.009999999776482582f;
    x87_v3 = (double)-0.009999999776482582f;
    label_00052DB2:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    x87_v4 = (double)*(float*)(cpu->edx + cpu->ebp);
    cpu->edx += cpu->ebp;
    { const double lift_left=x87_v4; const double lift_right=x87_v1;  if (!(lift_left>lift_right)) goto label_00052DEB; }
    { const double lift_left=(double)*(float*)(cpu->edx); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00052DEB; }
    { const double lift_left=x87_v3; const double lift_right=((double)*(float*)(cpu->edx + 8u)); if (!(lift_left<lift_right)) goto label_00052DEB; }
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    { const double lift_left=x87_v3; const double lift_right=((double)*(float*)(cpu->edx + 8u)); if (!(lift_left>lift_right)) goto label_00052DE9; }
    *(uint8_t*)(cpu->ecx + cpu->ebx) = 1u;
    ++cpu->edi;
    label_00052DE9:
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    label_00052DEB:
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052DB2;
    x87_v3 = x87_v3; 
    x87_v2 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00052DFC:
    lift_push32(cpu, 0x13F9u);
    cpu->ecx = cpu->edi + cpu->edi;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esi + 0x6898u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x452E14u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x452E14u));
    *(uint32_t*)(cpu->esi + 0x6888u) = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->eax) goto label_00052E40;
    cpu->ecx = 0u;
    label_00052E23:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) != 1u) goto label_00052E3A;
    *(uint8_t*)(cpu->eax + cpu->ebx) = 2u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x6888u);
    *(uint16_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFFFu;
    cpu->ecx += 2u;
    label_00052E3A:
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052E23;
    label_00052E40:
    cpu->ecx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ecx) goto label_00052E8B;
    x87_v0 = 100.01000213623047;
    cpu->ebp = 0u;
    x87_v1 = 99.98999786376953;
    label_00052E55:
    if (*(uint8_t*)(cpu->ecx + cpu->ebx) == 2u) goto label_00052E7E;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    x87_v2 = (double)*(float*)(cpu->eax + cpu->ebp + 8u);
    cpu->edx = cpu->eax + cpu->ebp + 8u;
    { const double lift_left=x87_v2; const double lift_right=x87_v1;  if (!(lift_left>lift_right)) goto label_00052E7E; }
    { const double lift_left=(double)*(float*)(cpu->edx); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00052E7E; }
    *(uint8_t*)(cpu->ecx + cpu->ebx) = 1u;
    label_00052E7E:
    ++cpu->ecx;
    cpu->ebp += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052E55;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00052E8B:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_0005304D;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    goto label_00052EB4;
    label_00052EA8:
    x87_v0 = x87_v3; 
    goto label_00052C01;
    label_00052EB0:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00052EB4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (*(uint8_t*)(cpu->ebx + cpu->ecx + 0xFFFFFFFFu) != 1u) goto label_00053035;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->ecx;
    cpu->ebx = cpu->edi;
    *(uint8_t*)(cpu->edx + cpu->ebp + 0xFFFFFFFFu) = 2u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)cpu->edi >= 0) goto label_00052EE2;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52EE2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x52EE2u));
    label_00052EE2:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_00052EF6;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52EF6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52EF6u));
    label_00052EF6:
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->edi + cpu->edi;
    ++cpu->edi;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint16_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFFFu;
    if ((int32_t)(cpu->edi) >= 0) goto label_00052F19;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52F19u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x52F19u));
    label_00052F19:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_00052F2D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52F2Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52F2Du));
    label_00052F2D:
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    *(uint16_t*)(cpu->ecx + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)) = x87_v0; 
    *(uint32_t*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index)) = cpu->ebx;
    ++cpu->eax;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053035;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = cpu->edx + 0x28u;
    label_00052F70:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) != 1u) goto label_00053028;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx); if (lift_left!=lift_right) goto label_00053028; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 4u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 4u); if (lift_left!=lift_right) goto label_00053028; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 8u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 8u); if (lift_left!=lift_right) goto label_00053028; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->edx + cpu->ebp) = 2u;
    if ((int32_t)cpu->edi >= 0) goto label_00052FD0;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52FD0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x52FD0u));
    label_00052FD0:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_00052FE4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52FE4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x52FE4u));
    label_00052FE4:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    *(uint16_t*)(cpu->eax + (cpu->edi * 2u)) = cpu->ebp & 0xFFFFu;
    ++cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) >= (int32_t)0u) goto label_00052FFF;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x52FFFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x52FFFu));
    label_00052FFF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_00053017;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53017u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x53017u));
    label_00053017:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++*(uint16_t*)(cpu->ecx + cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00053028:
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052F70;
    label_00053035:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    --cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00052EB0;
    label_0005304D:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->ebp + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45305Bu)); sfera_sub_0044DB50(cpu, LIFT_CODE_TOKEN_VA(0x45305Bu));
    lift_push32(cpu, 0x1420u);
    cpu->ecx = cpu->edi + cpu->edi;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esi + 0x68B0u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453073u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x453073u));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x68A0u) = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_00053136;
    cpu->edx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    label_00053091:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if ((int32_t)cpu->edi >= 0) goto label_000530A5;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x530A5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x530A5u));
    label_000530A5:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000530B9;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x530B9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x530B9u));
    label_000530B9:
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->edi * 2u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68A0u);
    *(uint16_t*)(cpu->edx + (cpu->ebx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->ebx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_00053127;
    label_000530E0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ebp = cpu->ecx + cpu->edi + 1u;
    if ((int32_t)cpu->ebp >= 0) goto label_000530F8;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x530F8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x530F8u));
    label_000530F8:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_0005310C;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5310Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5310Cu));
    label_0005310C:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68A0u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax + (cpu->ebp * 2u)));
    *(uint16_t*)(cpu->edx + (cpu->ebx * 2u)) = cpu->ecx & 0xFFFFu;
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_000530E0;
    label_00053127:
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u);
    if ((--*(uint32_t*)(cpu->esp + 0x20u)) != 0u) goto label_00053091;
    label_00053136:
    cpu->edi = 0u;
    cpu->ecx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_00053187;
    x87_v0 = (double)0.009999999776482582f;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v1 = (double)-0.009999999776482582f;
    cpu->ebx = 0u;
    label_00053151:
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) == 2u) goto label_0005317A;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_cmp[3]=x87_v1<(((double)*(float*)(cpu->edx + cpu->ebx + 8u)));
    cpu->edx = cpu->edx + cpu->ebx + 8u;
    if (!lift_cmp[3]) goto label_0005317A;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    { const double lift_left=x87_v1; const double lift_right=((double)*(float*)(cpu->edx)); if (!(lift_left>lift_right)) goto label_00053178; }
    *(uint8_t*)(cpu->ecx + cpu->ebp) = 1u;
    label_00053178:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_0005317A:
    ++cpu->ecx;
    cpu->ebx += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053151;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00053187:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_0005333D;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    label_000531A0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (*(uint8_t*)(cpu->ecx + cpu->eax + 0xFFFFFFFFu) != 1u) goto label_00053325;
    cpu->ebp = cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->ebx = cpu->edi;
    *(uint8_t*)(cpu->edx + cpu->ebp + 0xFFFFFFFFu) = 2u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)cpu->edi >= 0) goto label_000531D0;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x531D0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x531D0u));
    label_000531D0:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000531E4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x531E4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x531E4u));
    label_000531E4:
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->edi + cpu->edi;
    ++cpu->edi;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint16_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFFFu;
    if ((int32_t)(cpu->edi) >= 0) goto label_00053207;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53207u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x53207u));
    label_00053207:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_0005321B;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5321Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5321Bu));
    label_0005321B:
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    *(uint16_t*)(cpu->ecx + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)) = x87_v0; 
    *(uint32_t*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index)) = cpu->ebx;
    ++cpu->eax;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053325;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = cpu->edx + 0x28u;
    label_00053260:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) != 1u) goto label_00053318;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx); if (lift_left!=lift_right) goto label_00053318; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 4u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 4u); if (lift_left!=lift_right) goto label_00053318; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 8u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 8u); if (lift_left!=lift_right) goto label_00053318; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->edx + cpu->ebp) = 2u;
    if ((int32_t)cpu->edi >= 0) goto label_000532C0;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x532C0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x532C0u));
    label_000532C0:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000532D4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x532D4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x532D4u));
    label_000532D4:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    *(uint16_t*)(cpu->eax + (cpu->edi * 2u)) = cpu->ebp & 0xFFFFu;
    ++cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) >= (int32_t)0u) goto label_000532EF;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x532EFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x532EFu));
    label_000532EF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_00053307;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53307u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x53307u));
    label_00053307:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++*(uint16_t*)(cpu->ecx + cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00053318:
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053260;
    label_00053325:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    --cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_000531A0;
    label_0005333D:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->ebp + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45334Bu)); sfera_sub_0044DB50(cpu, LIFT_CODE_TOKEN_VA(0x45334Bu));
    lift_push32(cpu, 0x1448u);
    cpu->ecx = cpu->edi + cpu->edi;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esi + 0x68B4u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453363u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x453363u));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x68A4u) = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_0005341D;
    *(uint32_t*)(cpu->esp + 0x24u) = (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    (void)cpu;
    label_00053380:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->edi >= 0) goto label_00053394;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53394u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x53394u));
    label_00053394:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000533A8;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x533A8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x533A8u));
    label_000533A8:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->edi * 2u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68A4u);
    *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->ebx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_0005340E;
    label_000533C6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ebp = cpu->eax + cpu->edi + 1u;
    if ((int32_t)cpu->ebp >= 0) goto label_000533DE;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x533DEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x533DEu));
    label_000533DE:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000533F2;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x533F2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x533F2u));
    label_000533F2:
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68A4u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx + (cpu->ebp * 2u)));
    *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_000533C6;
    label_0005340E:
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u);
    if ((--*(uint32_t*)(cpu->esp + 0x20u)) != 0u) goto label_00053380;
    label_0005341D:
    cpu->ecx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ecx) goto label_00053468;
    x87_v0 = (double)0.009999999776482582f;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v1 = (double)-0.009999999776482582f;
    cpu->edi = 0u;
    label_00053436:
    if (*(uint8_t*)(cpu->ecx + cpu->ebx) == 2u) goto label_0005345B;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    { const double lift_left=x87_v1; const double lift_right=((double)*(float*)(cpu->edx + cpu->edi)); if (!(lift_left<lift_right)) goto label_0005345B; }
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    { const double lift_left=x87_v1; const double lift_right=((double)*(float*)(cpu->edx + cpu->edi)); if (!(lift_left>lift_right)) goto label_00053459; }
    *(uint8_t*)(cpu->ecx + cpu->ebx) = 1u;
    label_00053459:
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_0005345B:
    ++cpu->ecx;
    cpu->edi += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053436;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00053468:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_00053621;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    label_00053483:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (*(uint8_t*)(cpu->ecx + cpu->eax + 0xFFFFFFFFu) != 1u) goto label_00053609;
    cpu->ebp = cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->ebx = cpu->edi;
    *(uint8_t*)(cpu->edx + cpu->ebp + 0xFFFFFFFFu) = 2u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)cpu->edi >= 0) goto label_000534B3;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x534B3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x534B3u));
    label_000534B3:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000534C7;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x534C7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x534C7u));
    label_000534C7:
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->edi + cpu->edi;
    ++cpu->edi;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint16_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFFFu;
    if ((int32_t)(cpu->edi) >= 0) goto label_000534EA;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x534EAu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x534EAu));
    label_000534EA:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000534FE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x534FEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x534FEu));
    label_000534FE:
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    *(uint16_t*)(cpu->ecx + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->edx + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)) = x87_v0; 
    *(uint32_t*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index)) = cpu->ebx;
    ++cpu->eax;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053609;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = cpu->edx + 0x28u;
    label_00053540:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) != 1u) goto label_000535FC;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx); if (lift_left!=lift_right) goto label_000535FC; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 4u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 4u); if (lift_left!=lift_right) goto label_000535FC; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 8u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 8u); if (lift_left!=lift_right) goto label_000535FC; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->edx + cpu->ebp) = 2u;
    if ((int32_t)cpu->edi >= 0) goto label_000535A4;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x535A4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x535A4u));
    label_000535A4:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000535B8;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x535B8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x535B8u));
    label_000535B8:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    *(uint16_t*)(cpu->eax + (cpu->edi * 2u)) = cpu->ebp & 0xFFFFu;
    ++cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) >= (int32_t)0u) goto label_000535D3;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x535D3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x535D3u));
    label_000535D3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000535EB;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x535EBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x535EBu));
    label_000535EB:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++*(uint16_t*)(cpu->ecx + cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    label_000535FC:
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053540;
    label_00053609:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    --cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053483;
    label_00053621:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->ebp + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45362Fu)); sfera_sub_0044DB50(cpu, LIFT_CODE_TOKEN_VA(0x45362Fu));
    lift_push32(cpu, 0x1470u);
    cpu->ecx = cpu->edi + cpu->edi;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esi + 0x68B8u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453647u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x453647u));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x68A8u) = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_00053706;
    cpu->edx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    label_00053665:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if ((int32_t)cpu->edi >= 0) goto label_00053679;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53679u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x53679u));
    label_00053679:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_0005368D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5368Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5368Du));
    label_0005368D:
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->edi * 2u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68A8u);
    *(uint16_t*)(cpu->edx + (cpu->ebx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->ebx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_000536F7;
    label_000536B0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ebp = cpu->ecx + cpu->edi + 1u;
    if ((int32_t)cpu->ebp >= 0) goto label_000536C8;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x536C8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x536C8u));
    label_000536C8:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000536DC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x536DCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x536DCu));
    label_000536DC:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68A8u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax + (cpu->ebp * 2u)));
    *(uint16_t*)(cpu->edx + (cpu->ebx * 2u)) = cpu->ecx & 0xFFFFu;
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_000536B0;
    label_000536F7:
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u);
    if ((--*(uint32_t*)(cpu->esp + 0x20u)) != 0u) goto label_00053665;
    label_00053706:
    cpu->edi = 0u;
    cpu->ecx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_00053753;
    x87_v0 = 100.01000213623047;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v1 = 99.98999786376953;
    cpu->ebx = 0u;
    label_00053721:
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) == 2u) goto label_00053746;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    { const double lift_left=(double)*(float*)(cpu->edx + cpu->ebx); const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_00053746; }
    { const double lift_left=(double)*(float*)(cpu->edx + cpu->ebx); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00053746; }
    *(uint8_t*)(cpu->ecx + cpu->ebp) = 1u;
    label_00053746:
    ++cpu->ecx;
    cpu->ebx += 0x28u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053721;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00053753:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_00053911;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    label_00053770:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (*(uint8_t*)(cpu->ecx + cpu->eax + 0xFFFFFFFFu) != 1u) goto label_000538F9;
    cpu->ebp = cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->ebx = cpu->edi;
    *(uint8_t*)(cpu->edx + cpu->ebp + 0xFFFFFFFFu) = 2u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)cpu->edi >= 0) goto label_000537A0;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x537A0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x537A0u));
    label_000537A0:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000537B4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x537B4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x537B4u));
    label_000537B4:
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->edi + cpu->edi;
    ++cpu->edi;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint16_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFFFu;
    if ((int32_t)(cpu->edi) >= 0) goto label_000537D7;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x537D7u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x537D7u));
    label_000537D7:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000537EB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x537EBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x537EBu));
    label_000537EB:
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    *(uint16_t*)(cpu->ecx + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->edx + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)) = x87_v0; 
    *(uint32_t*)((cpu->eax * 8u) + ((uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index)) = cpu->ebx;
    ++cpu->eax;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_000538F9;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = cpu->edx + 0x28u;
    label_00053830:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) != 1u) goto label_000538EC;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx); if (lift_left!=lift_right) goto label_000538EC; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 4u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 4u); if (lift_left!=lift_right) goto label_000538EC; }
    { const double lift_right=(double)*(float*)(cpu->edx + cpu->ecx + 8u); const double lift_left=(double)*(float*)(cpu->ebx + cpu->ecx + 8u); if (lift_left!=lift_right) goto label_000538EC; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->edx + cpu->ebp) = 2u;
    if ((int32_t)cpu->edi >= 0) goto label_00053894;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53894u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x53894u));
    label_00053894:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000538A8;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x538A8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x538A8u));
    label_000538A8:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    *(uint16_t*)(cpu->eax + (cpu->edi * 2u)) = cpu->ebp & 0xFFFFu;
    ++cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) >= (int32_t)0u) goto label_000538C3;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x538C3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x538C3u));
    label_000538C3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000538DB;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x538DBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x538DBu));
    label_000538DB:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++*(uint16_t*)(cpu->ecx + cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    label_000538EC:
    ++cpu->ebp;
    cpu->ebx += 0x28u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053830;
    label_000538F9:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x28u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    --cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00053770;
    label_00053911:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->ebp + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45391Fu)); sfera_sub_0044DB50(cpu, LIFT_CODE_TOKEN_VA(0x45391Fu));
    lift_push32(cpu, 0x1499u);
    cpu->ecx = cpu->edi + cpu->edi;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esi + 0x68BCu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453937u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x453937u));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x68ACu) = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_000539F7;
    *(uint32_t*)(cpu->esp + 0x24u) = (uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    label_00053953:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->edi >= 0) goto label_00053967;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53967u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x53967u));
    label_00053967:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_0005397B;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5397Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5397Bu));
    label_0005397B:
    cpu->eax = g_sfera_mesh_partition_indices.data;
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->edi * 2u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68ACu);
    *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->ebx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_000539E8;
    label_000539A0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ebp = cpu->eax + cpu->edi + 1u;
    if ((int32_t)cpu->ebp >= 0) goto label_000539B8;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x539B8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x539B8u));
    label_000539B8:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_mesh_partition_indices.capacity) goto label_000539CC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x539CCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x539CCu));
    label_000539CC:
    cpu->edx = g_sfera_mesh_partition_indices.data;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68ACu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx + (cpu->ebp * 2u)));
    *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->edi;
    ++cpu->ebx;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_000539A0;
    label_000539E8:
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(8u) + (uint64_t)(0u);
    if ((--*(uint32_t*)(cpu->esp + 0x20u)) != 0u) goto label_00053953;
    label_000539F7:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0x14A3u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453A0Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x453A0Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00453A20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x68B0u);
    cpu->ebp = 0u;
    lift_push32(cpu, 0x14CAu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453A4Fu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x453A4Fu));
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x68B0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x453A5Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 0x68B0u) <= (int32_t)cpu->ebp) goto label_00053BC5;
    label_00053A80:
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 0x68A0u);
    cpu->edx = *(uint16_t*)(cpu->eax + (cpu->ebp * 2u));
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->ebp * 2u) + 2u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    ++cpu->ebp;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = cpu->ecx + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->edx * 4u) + 0x68B0u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_00053B54;
    cpu->esi = *(uint32_t*)(cpu->edi + (cpu->edx * 4u) + 0x68A0u);
    label_00053AC2:
    cpu->edx = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u));
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u) + 2u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edx = cpu->edx + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->eax == 0u) goto label_00053B19;
    if (cpu->eax == 1u) goto label_00053B19;
    { const double lift_right=(double)*(float*)(cpu->ebx + 8u); const double lift_left=(double)*(float*)(cpu->edx + 8u); if (lift_left!=lift_right) goto label_00053B39; }
    { const double lift_right=(double)*(float*)(cpu->ebx + 4u); const double lift_left=(double)*(float*)(cpu->edx + 4u); if (lift_left!=lift_right) goto label_00053B39; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint8_t*)(cpu->ecx + cpu->edx) = 1u;
    goto label_00053BA3;
    label_00053B19:
    { const double lift_right=(double)*(float*)(cpu->ebx); const double lift_left=(double)*(float*)(cpu->edx); if (lift_left!=lift_right) goto label_00053B39; }
    { const double lift_right=(double)*(float*)(cpu->ebx + 4u); const double lift_left=(double)*(float*)(cpu->edx + 4u); if (lift_left==lift_right) goto label_00053C3B; }
    label_00053B39:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esp + 0x28u)) goto label_00053AC2;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_00053B54:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) + (((double)*(float*)(cpu->ebx + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    cpu->esp -= 8u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->ecx = 0xFFu;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    *(float*)(cpu->esp + 0x30u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))))) + (((double)*(float*)(cpu->ebx))));
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53BA3u)); sfera_sub_00451460(cpu, LIFT_CODE_TOKEN_RVA(0x53BA3u));
    label_00053BA3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x2Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 0x68B0u)) goto label_00053A80;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x38u);
    label_00053BC5:
    cpu->esi = 0u;
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x68B0u) <= (int32_t)cpu->esi) goto label_00053CD5;
    x87_v0 = 100.0;
    label_00053BDC:
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x68A0u);
    cpu->edx = *(uint16_t*)(cpu->eax + (cpu->esi * 2u));
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->esi * 2u) + 2u);
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint8_t*)(cpu->edx + cpu->ebp) != 0u) goto label_00053CC1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u);
    *(float*)(cpu->esp + 0x10u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u))));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    *(float*)(cpu->esp + 0x38u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u))));
    if (cpu->ecx != 3u) goto label_00053C50;
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (x87_v1) + (x87_v0);
    goto label_00053C5B;
    label_00053C3B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint8_t*)(cpu->eax + cpu->ecx) = 1u;
    goto label_00053BA3;
    label_00053C50:
    if (cpu->ecx != 2u) goto label_00053C5F;
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (x87_v1) - (x87_v0);
    label_00053C5B:
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    label_00053C5F:
    if (cpu->ebx != 0u) goto label_00053C6D;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    goto label_00053C7E;
    label_00053C6D:
    if (cpu->ebx != 1u) goto label_00053C7C;
    x87_v0 = (((double)*(float*)(cpu->esp + 0x38u))) - (x87_v0);
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    goto label_00053C7E;
    label_00053C7C:
    x87_v0 = x87_v0; 
    label_00053C7E:
    x87_v0 = (double)*(float*)(cpu->eax + 8u);
    cpu->esp -= 8u;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x40u)));
    cpu->ecx = 0xFF00u;
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x40u) = ((((double)*(float*)(cpu->eax))) + (((double)*(float*)(cpu->esp + 0x18u))));
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453CB7u)); sfera_sub_00451460(cpu, LIFT_CODE_TOKEN_VA(0x453CB7u));
    x87_v0 = 100.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    label_00053CC1:
    cpu->esi += *(uint32_t*)(cpu->esp + 0x2Cu);
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x68B0u)) goto label_00053BDC;
    x87_v0 = x87_v0; 
    label_00053CD5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x1509u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453CE8u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x453CE8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x18u) == cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00453D00(LiftCpu* cpu, uint32_t stop_address) { double x87_p0, x87_p1, x87_p2, x87_p3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xA8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xBCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0xD8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xD0u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0xDCu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0xE0u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    if (cpu->edx != 0u) goto label_00053D88;
    if (cpu->eax != 0u) goto label_00053D88;
    if (cpu->ecx == 0u) goto label_000543DF;
    label_00053D88:
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x78u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453D99u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x453D99u));
    lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x453DA2u));
    cpu->esp += 0xCu;
    cpu->ebp = 0x32u;
    cpu->ebx = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x50u) = 0x1Eu;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453DD8u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x453DD8u));
    cpu->edi = native_function_address32(&::strncpy);
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x53DE6u), LIFT_CODE_TOKEN_RVA(0x53DE4u))) { return; }
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esp + 0x6Bu) = 0u;
    *(uint32_t*)(cpu->esp + 0x7Cu) = 0x1556u;
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = cpu->ebp + 0xFFFFFFECu;
    *(uint32_t*)(cpu->esp + 0xC8u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453E10u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x453E10u));
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->edx + 0x14u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint16_t*)(cpu->edx + 0x1Cu) = cpu->ecx & 0xFFFFu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x88u) = 0x1Eu;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x94u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x453E92u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x453E92u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x9Cu;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x53E9Du), LIFT_CODE_TOKEN_RVA(0x53E9Bu))) { return; }
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esp + 0xA3u) = 0u;
    *(uint32_t*)(cpu->esp + 0xB4u) = 0x1557u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0xD4u);
    cpu->ebx = 0u;
    *(uint8_t*)(cpu->esp + 0xC4u) = 1u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)*(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x688Cu) <= (int32_t)cpu->ebx) goto label_00053F2D;
    label_00053ED1:
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_00053EE2;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53EE2u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x53EE2u));
    label_00053EE2:
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x687Cu);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u));
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax + (cpu->edx * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 4u)) = cpu->ecx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_00053F14;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53F14u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x53F14u));
    label_00053F14:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint8_t*)(cpu->eax + cpu->ebx) = 0u;
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x688Cu)) goto label_00053ED1;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    label_00053F2D:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->edi == 0u) goto label_00053FA1;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edi + (cpu->ebp * 4u) + 0x688Cu) <= (int32_t)cpu->esi) goto label_00053FA1;
    label_00053F44:
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_00053F55;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53F55u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x53F55u));
    label_00053F55:
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->ebp * 4u) + 0x687Cu);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u));
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = cpu->eax + (cpu->edx * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 4u)) = cpu->ecx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_00053F87;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53F87u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x53F87u));
    label_00053F87:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint8_t*)(cpu->eax + cpu->ebx) = 0u;
    ++cpu->esi;
    ++cpu->ebx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + (cpu->ebp * 4u) + 0x688Cu)) goto label_00053F44;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    label_00053FA1:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->edi == 0u) goto label_00054015;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edi + (cpu->ebp * 4u) + 0x688Cu) <= (int32_t)cpu->esi) goto label_00054015;
    label_00053FB8:
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_00053FC9;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53FC9u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x53FC9u));
    label_00053FC9:
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->ebp * 4u) + 0x687Cu);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u));
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = cpu->eax + (cpu->edx * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 4u)) = cpu->ecx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_00053FFB;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x53FFBu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x53FFBu));
    label_00053FFB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint8_t*)(cpu->eax + cpu->ebx) = 0u;
    ++cpu->esi;
    ++cpu->ebx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + (cpu->ebp * 4u) + 0x688Cu)) goto label_00053FB8;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    label_00054015:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ebp == 0u) goto label_0005408D;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebp + (cpu->edi * 4u) + 0x688Cu) <= (int32_t)cpu->esi) goto label_0005408D;
    label_00054030:
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_00054041;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54041u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x54041u));
    label_00054041:
    cpu->ecx = *(uint32_t*)(cpu->ebp + (cpu->edi * 4u) + 0x687Cu);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u));
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->eax + (cpu->edx * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 4u)) = cpu->ecx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_00054073;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54073u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x54073u));
    label_00054073:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint8_t*)(cpu->eax + cpu->ebx) = 0u;
    ++cpu->esi;
    ++cpu->ebx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->ebp + (cpu->edi * 4u) + 0x688Cu)) goto label_00054030;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    label_0005408D:
    cpu->edi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_00054371;
    label_00054097:
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_000540AE;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x540AEu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x540AEu));
    label_000540AE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    if (*(uint8_t*)(cpu->ecx + cpu->edi) == 2u) goto label_00054364;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_000540D6;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x540D6u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x540D6u));
    label_000540D6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint8_t*)(cpu->edx + cpu->edi) = 1u;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_000540F2;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x540F2u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x540F2u));
    label_000540F2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->esi = cpu->edi + 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_00054281;
    label_00054119:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_00054130;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54130u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x54130u));
    label_00054130:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) == 2u) goto label_00054274;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_00054152;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54152u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x54152u));
    label_00054152:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = cpu->edx + (cpu->esi * 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_0005416E;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5416Eu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5416Eu));
    label_0005416E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->edx = cpu->ecx + (cpu->edi * 4u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_0005418A;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5418Au)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5418Au));
    label_0005418A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->ecx = cpu->eax + (cpu->esi * 4u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_000541A6;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x541A6u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x541A6u));
    label_000541A6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->ebx = cpu->edx + (cpu->edi * 4u);
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_000541BE;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x541BEu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x541BEu));
    label_000541BE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->ebp = cpu->eax + (cpu->esi * 4u);
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_000541D6;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x541D6u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x541D6u));
    label_000541D6:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    x87_p0 = (double)*(float*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->eax + 4u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_p1 = (double)*(float*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->ecx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    x87_p0 = x87_p0 + x87_p1; 
    x87_p1 = (double)*(float*)(cpu->eax + 8u);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->ecx + 8u)));
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    { const double lift_left=0.0; const double lift_right=((double)*(float*)(cpu->esp + 0x14u)); if (lift_left>lift_right) goto label_00054274; }
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_00054230;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54230u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x54230u));
    label_00054230:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint8_t*)(cpu->edx + cpu->esi) = 1u;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_0005424C;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5424Cu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5424Cu));
    label_0005424C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->eax + 0x10u))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->eax + 0x14u))) + (((double)*(float*)(cpu->esp + 0x20u))));
    label_00054274:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_00054119;
    label_00054281:
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x20u);
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    { double temporary = x87_p2; x87_p2 = x87_p0; x87_p0 = temporary; }
    x87_p1 = x87_p1 + x87_p2; 
    x87_p2 = x87_p0;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->esi = cpu->edi;
    x87_p1 = 1.0;
    x87_p0 = x87_p1 / x87_p0; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = (x87_p1) * (x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_00054364;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    label_000542F0:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_00054307;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54307u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x54307u));
    label_00054307:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 1u) goto label_0005435F;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x84u)) goto label_0005432B;
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5432Bu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5432Bu));
    label_0005432B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint8_t*)(cpu->edx + cpu->esi) = 2u;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_00054347;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54347u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x54347u));
    label_00054347:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ebp;
    label_0005435F:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_000542F0;
    label_00054364:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_00054097;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00054371:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->eax == 0u) goto label_00054385;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint8_t*)(cpu->ecx + cpu->eax + 0x689Cu) = 1u;
    label_00054385:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->eax == 0u) goto label_00054399;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint8_t*)(cpu->edx + cpu->eax + 0x689Cu) = 1u;
    label_00054399:
    if (cpu->ebp == 0u) goto label_000543A9;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint8_t*)(cpu->eax + cpu->ebp + 0x689Cu) = 1u;
    label_000543A9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    *(uint8_t*)(cpu->esp + 0xC8u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4543C4u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4543C4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    *(uint32_t*)(cpu->esp + 0xC8u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x543DFu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x543DFu));
    label_000543DF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xBCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454410(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[2]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x38u;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->ebx + 0x1B20u;
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45444Cu)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x45444Cu));
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_000549A2;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_000549A2;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_000549A2;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_000549A2;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_000549A2;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_000549A2;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4544C7u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x4544C7u));
    if (cpu->eax == 0u) goto label_000549A2;
    cpu->edx = cpu->ebx + 0x1D78u;
    cpu->eax = cpu->ebx + 0xCu;
    cpu->ebp = cpu->ebx + 0x24F8u;
    cpu->ecx = cpu->ebx + 0x1B98u;
    g_sfera_landscape_patch_lookup_runtime.visible_count = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = 4u;
    label_00054510:
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454539u)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x454539u));
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_00054800;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_00054800;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_00054800;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_00054800;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_00054800;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_00054800;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4545B4u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x4545B4u));
    if (cpu->eax == 0u) goto label_00054800;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = 4u;
    label_000545E0:
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.x.u32;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.y.u32;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = g_sfera_view_spatial_runtime.world_anchor.z.u32;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454609u)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x454609u));
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_000547D5;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_000547D5;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_000547D5;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_000547D5;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_000547D5;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_000547D5;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454684u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x454684u));
    if (cpu->eax == 0u) goto label_000547D5;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 9u;
    label_000546A0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4546CBu)); sfera_sub_0044DC10(cpu, LIFT_CODE_TOKEN_VA(0x4546CBu));
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.max_x;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_x) goto label_000547C1;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.min_x;
    if ((int32_t)cpu->eax > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_x) goto label_000547C1;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.max_y;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_y) goto label_000547C1;
    cpu->edx = g_sfera_view_geometry_runtime.projected_bounds.min_y;
    if ((int32_t)cpu->edx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_y) goto label_000547C1;
    cpu->eax = g_sfera_view_geometry_runtime.projected_bounds.max_z;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.min_z) goto label_000547C1;
    cpu->ecx = g_sfera_view_geometry_runtime.projected_bounds.min_z;
    if ((int32_t)cpu->ecx > (int32_t)g_sfera_view_geometry_runtime.clipping_bounds.max_z) goto label_000547C1;
    lift_push32(cpu, 8u);
    cpu->edx = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454746u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x454746u));
    if (cpu->eax == 0u) goto label_000547C1;
    cpu->esi = g_sfera_landscape_patch_lookup_runtime.visible_count;
    if ((int32_t)cpu->esi >= 0) goto label_0005475E;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5475Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5475Eu));
    label_0005475E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_00054772;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54772u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54772u));
    label_00054772:
    cpu->edx = g_sfera_light_runtime.cell_indices.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->ebx;
    cpu->esi = g_sfera_landscape_patch_lookup_runtime.visible_count;
    if ((int32_t)cpu->esi >= 0) goto label_0005478F;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5478Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5478Fu));
    label_0005478F:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_light_runtime.cell_records.capacity))) goto label_000547A3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x547A3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x547A3u));
    label_000547A3:
    cpu->edi = cpu->esi + (cpu->esi * 2u);
    cpu->edi <<= 5u;
    cpu->edi += g_sfera_light_runtime.cell_records.data;
    cpu->esi = (uintptr_t)&g_sfera_view_projection_scratch_runtime;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),96u); cpu->esi += 96u; cpu->edi += 96u; cpu->ecx = 0u;
    ++g_sfera_landscape_patch_lookup_runtime.visible_count;
    label_000547C1:
    cpu->ebp += 0x78u;
    cpu->ebx += 0x30u;
    if ((--*(uint32_t*)(cpu->esp + 0x1Cu)) != 0u) goto label_000546A0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x38u);
    label_000547D5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x1B0u) + (uint64_t)(0u);
    cpu->ecx += 0x78u;
    cpu->ebp += 0x438u;
    --*(uint32_t*)(cpu->esp + 0x28u); sub_pred[0] = *(uint32_t*)(cpu->esp + 0x28u) == 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    if (!sub_pred[0]) goto label_000545E0;
    label_00054800:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x6C0u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x1E0u) + (uint64_t)(0u);
    cpu->ecx += 0x78u;
    cpu->ebp += 0x10E0u;
    --*(uint32_t*)(cpu->esp + 0x34u); sub_pred[1] = *(uint32_t*)(cpu->esp + 0x34u) == 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebp;
    if (!sub_pred[1]) goto label_00054510;
    cpu->eax = g_sfera_landscape_patch_lookup_runtime.visible_count;
    cpu->edi = 0u;
    if ((int32_t)cpu->eax <= (int32_t)cpu->edi) goto label_000549A2;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    label_00054846:
    if ((int32_t)cpu->edi >= 0) goto label_00054854;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54854u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x54854u));
    label_00054854:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_00054868;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54868u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54868u));
    label_00054868:
    cpu->eax = g_sfera_light_runtime.cell_indices.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1B1Cu);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u);
    cpu->ebp = cpu->ecx + (cpu->eax * 8u);
    lift_test[0]=((cpu->esi)&0x80000000u)!=0u;
    if (cpu->esi==0u) goto label_00054990;
    if (!lift_test[0]) goto label_0005489C;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5489Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5489Cu));
    label_0005489C:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_000548B0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x548B0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x548B0u));
    label_000548B0:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    x87_v0 = (double)0.0010000000474974513f;
    cpu->edx = cpu->esi + (cpu->esi * 2u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->eax + (cpu->edx * 8u) + 0x10u));  if (!(lift_left<lift_right)) goto label_00054990; }
    if ((int32_t)cpu->edi >= 0) goto label_000548DB;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x548DBu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x548DBu));
    label_000548DB:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_records.capacity) goto label_000548EF;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x548EFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x548EFu));
    label_000548EF:
    cpu->esi = g_sfera_light_runtime.cell_records.data;
    cpu->esi += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00054910;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54910u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54910u));
    label_00054910:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(float*)(cpu->esp + 0x3Cu) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->esi))));
    *(float*)(cpu->esp + 0x40u) = ((((double)*(float*)(cpu->eax + 0xCu))) - (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x44u) = ((((double)*(float*)(cpu->eax + 0x10u))) - (((double)*(float*)(cpu->esi + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x44u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    *(float*)(cpu->esp + 0x38u) = (double)*(float*)(cpu->esp + 0x38u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u);
    { const double lift_left=(double)g_sfera_main_input_state_runtime.motion_x; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0005498E; }
    g_sfera_main_input_state_runtime.motion_x = x87_v0; 
    *(float*)((uintptr_t)&g_sfera_window_runtime.distance_scratch.f32) = (double)*(float*)(cpu->ebp);
    goto label_00054990;
    label_0005498E:
    x87_v0 = x87_v0; 
    label_00054990:
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x60u) + (uint64_t)(0u);
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_landscape_patch_lookup_runtime.visible_count) goto label_00054846;
    label_000549A2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004549B0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if (sub_pred[0]) goto label_00054A08;
    cpu->edi = g_sfera_world_objects.controlled_object_handle;
    if (cpu->edi == 0xFFFFFFFFu) goto label_00054A08;
    if ((int32_t)cpu->edi >= 0) goto label_000549D6;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x549D6u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x549D6u));
    label_000549D6:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000549EA;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x549EAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x549EAu));
    label_000549EA:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054A08:
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00054A1F;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54A1Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54A1Fu));
    label_00054A1F:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454A40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 8u;
    sub_pred[1] = *(uint8_t*)(cpu->ecx) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    if (sub_pred[1]) goto label_00054B92;
    x87_v0 = 255.0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::specular);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->ebx);
    label_00054A63:
    x87_v1 = (double)*(float*)(cpu->edi + ((uintptr_t)&g_sfera_render_sample_runtime.samples[0]));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ebp);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v2 = (double)*(float*)(cpu->ebp + 4u);
    x87_v2 = (x87_v2) + (x87_v1);
    cpu->ebx = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->ebp + 8u)));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->ecx = 0xFFu;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->ecx) goto label_00054AA4;
    cpu->ebx = cpu->ecx;
    label_00054AA4:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) <= (int32_t)cpu->ecx) goto label_00054AAE;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_00054AAE:
    if ((cpu->eax == cpu->ecx) || ((int32_t)(cpu->eax) < (int32_t)(cpu->ecx))) goto label_00054AB4;
    cpu->eax = cpu->ecx;
    label_00054AB4:
    cpu->ecx = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_main_command_state_runtime.render_samples[0]));
    cpu->ecx <<= 8u;
    cpu->edx = cpu->ebx & 0xFFu;
    cpu->ecx|=cpu->edx;
    cpu->edx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->edx;
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->esi += 0x20u;
    cpu->edi += 4u;
    sub_pred[2] = (int32_t)(cpu->esi) < (int32_t)((uint32_t)((uint64_t)(sfera_screen_vertex_field_end_address(g_sfera_sky_screen_vertices, &SferaScreenVertex::specular))));
    if (sub_pred[2]) goto label_00054A63;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    x87_v0 = x87_v0; 
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454B00u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x454B00u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = (uintptr_t)"auto";
    cpu->eax = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    label_00054B10:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_00054B30;
    if ((cpu->edx & 0xFFu) == 0u) goto label_00054B2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_00054B30;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00054B10;
    label_00054B2C:
    cpu->eax = 0u;
    goto label_00054B35;
    label_00054B30:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_00054B35:
    if (cpu->eax==0u) goto label_00054B55;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454B40u)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x454B40u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454B4Eu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x454B4Eu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54B55u)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_RVA(0x54B55u));
    label_00054B55:
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))) >> 32u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0x65u);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, (uintptr_t)&g_sfera_sky_runtime.indices[0]);
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454B85u)); sfera_sub_004D8FE0(cpu, LIFT_CODE_TOKEN_VA(0x454B85u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454B90u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x454B90u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00054B92:
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454BA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if (*(uint8_t*)(cpu->edi) == 0u) goto label_00054DB4;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uintptr_t)&g_sfera_main_command_state_runtime.render_samples[1];
    cpu->eax = sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::diffuse);
    lift_push32(cpu, cpu->esi);
    label_00054BC0:
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xFFFFFFFCu);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    cpu->esi&=0xFFu;
    cpu->ebp = cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp|=cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->esi &= 0xFFu;
    cpu->ecx|=cpu->esi;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->esi;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    cpu->esi&=0xFFu;
    cpu->ebp = cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp|=cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->esi &= 0xFFu;
    cpu->ecx|=cpu->esi;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->esi;
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ebp;
    cpu->esi&=0xFFu;
    cpu->ebp = cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp|=cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx |= 0xFFFFFF00u;
    cpu->esi&=0xFFu;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->esi;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->esi;
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->ebp;
    cpu->esi&=0xFFu;
    cpu->ebp = cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp|=cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx |= 0xFFFFFF00u;
    cpu->esi&=0xFFu;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->esi;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->esi;
    cpu->esi |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x60u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xCu);
    *(uint32_t*)(cpu->eax + 0x64u) = cpu->ebp;
    cpu->esi -= cpu->ecx;
    cpu->esi&=0xFFu;
    cpu->ebp = cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp|=cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->esi &= 0xFFu;
    cpu->ecx|=cpu->esi;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->esi;
    *(uint32_t*)(cpu->eax + 0x80u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->ecx;
    cpu->esi&=0xFFu;
    *(uint32_t*)(cpu->eax + 0x84u) = cpu->ebp;
    cpu->ebp = cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp|=cpu->esi;
    cpu->ebp = cpu->ebp << 8u;
    cpu->ebp |= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->esi &= 0xFFu;
    cpu->ecx|=cpu->esi;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->esi;
    *(uint32_t*)(cpu->eax + 0xA4u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0xA0u) = cpu->ecx;
    cpu->edx += 0x18u;
    cpu->eax += 0xC0u;
    if ((int32_t)cpu->edx < (int32_t)((uintptr_t)&g_sfera_main_command_state_runtime.lighting_state)) goto label_00054BC0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454D3Du)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x454D3Du));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Du);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454D4Cu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x454D4Cu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454D53u)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x454D53u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454D61u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x454D61u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454D68u)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_VA(0x454D68u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(cpu->ebx))) >> 32u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0x65u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, (uintptr_t)&g_sfera_sky_runtime.indices[0]);
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454D96u)); sfera_sub_004D8FE0(cpu, LIFT_CODE_TOKEN_VA(0x454D96u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454DA5u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x454DA5u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_004D91E0(cpu, stop_address); return;
    label_00054DB4:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454DC0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi) != 0u) goto label_00054DED;
    cpu->ecx = cpu->esi + 0xACu;
    if (*(uint8_t*)(cpu->esi + 0xACu) != 0u) goto label_00054DED;
    *(uint8_t*)((uintptr_t)&g_sfera_startup_command_line_runtime.text[0x148]) = 0u;
    g_sfera_view_render_objects_runtime.reset_flag = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054DED:
    x87_v0 = (double)*(float*)(cpu->esi + 0x158u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454DFDu)); sfera_sub_0044E480(cpu, LIFT_CODE_TOKEN_VA(0x454DFDu));
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->esi + 0xACu;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454E0Cu)); sfera_sub_00454BA0(cpu, LIFT_CODE_TOKEN_VA(0x454E0Cu));
    if (*(uint8_t*)(cpu->esi) == 0u) goto label_00054E28;
    cpu->edx = cpu->esp + 8u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454E1Cu)); sfera_sub_0044E6A0(cpu, LIFT_CODE_TOKEN_VA(0x454E1Cu));
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54E28u)); sfera_sub_00454A40(cpu, LIFT_CODE_TOKEN_RVA(0x54E28u));
    label_00054E28:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454E30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00054E78;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054E4B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54E4Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54E4Bu));
    label_00054E4B:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00054E78;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054E6A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54E6Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54E6Au));
    label_00054E6A:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax += 8u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054E78:
    cpu->eax = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->eax;
    label_00054E85:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00054E85;
    cpu->edx = *(uint32_t*)((uintptr_t)"GetPos: wrong handle");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"GetPos: wrong handle") + 0x14u));
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint8_t*)(cpu->eax + 0x14u) = cpu->ecx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454EC7u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x454EC7u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454ED0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00054F18;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054EEB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54EEBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54EEBu));
    label_00054EEB:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00054F18;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054F0A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54F0Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54F0Au));
    label_00054F0A:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax += 0x14u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054F18:
    cpu->eax = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->eax;
    label_00054F25:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00054F25;
    cpu->edx = *(uint32_t*)((uintptr_t)"GetAngles: wrong handle");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 0x14u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454F67u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x454F67u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454F70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00054FB5;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054F8B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54F8Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54F8Bu));
    label_00054F8B:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00054FB5;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054FAA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54FAAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54FAAu));
    label_00054FAA:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054FB5:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00054FC3:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00054FC3;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetObjectPointer: wrong handle"),31u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x454FDFu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x454FDFu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454FF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    cpu->esp -= 0xD4u;
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esp + 0x34u) = x87_v0;
    cpu->esi = cpu->edx;
    *(float*)(cpu->esp + 0x38u) = x87_v0;
    cpu->ebx = cpu->esi;
    *(float*)(cpu->esp + 0x3Cu) = x87_v0;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0xACu);
    *(float*)(cpu->esp + 0x40u) = x87_v0;
    *(float*)(cpu->esp + 0x58u) = x87_v0;
    *(float*)(cpu->esp + 0x5Cu) = x87_v0;
    *(float*)(cpu->esp + 0x60u) = x87_v0;
    *(float*)(cpu->esp + 0x64u) = x87_v0; 
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_world_render_runtime.active_model;
    cpu->ebx += *(uint32_t*)(cpu->edi + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00055054;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45504Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x45504Eu));
    cpu->edi = g_sfera_world_render_runtime.active_model;
    label_00055054:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.model_matrices.capacity))) goto label_0005506E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455068u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x455068u));
    cpu->edi = g_sfera_world_render_runtime.active_model;
    label_0005506E:
    cpu->esi <<= 6u;
    cpu->esi += g_sfera_scene_array_runtime.model_matrices.data;
    sub_pred[0] = *(uint8_t*)(cpu->ebx + 0x25u) == 0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->esi;
    if (!sub_pred[0]) goto label_000550A4;
    cpu->eax = *(uint16_t*)(cpu->ebx + 0x26u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x54u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->esi = cpu->edx + (cpu->ecx * 4u);
    cpu->edi = cpu->esp + 0x2Cu;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u; cpu->ecx = 0u;
    goto label_00055358;
    label_000550A4:
    cpu->ecx = *(uint16_t*)(cpu->ebx + 0x26u);
    cpu->ecx += g_sfera_client_main_scalar_runtime.state_06;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x58u);
    cpu->eax = cpu->edx + (cpu->ecx * 2u);
    cpu->eax += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 2u));
    cpu->eax = *(uint16_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x54u);
    if ((cpu->ecx & 0xFFu) != 0xFFu) goto label_000550E2;
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->esi = cpu->ebp + (cpu->ecx * 4u);
    cpu->edi = cpu->esp + 0x30u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u; cpu->ecx = 0u;
    goto label_00055198;
    label_000550E2:
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->ebp + (cpu->edx * 4u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    cpu->ecx = cpu->esp + 0x40u;
    cpu->edx = cpu->esi + 0x28u;
    x87_v0 = (x87_v0) * (0.00390625);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45511Cu)); sfera_sub_0044BC70(cpu, LIFT_CODE_TOKEN_VA(0x45511Cu));
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi + 0x1Cu))) - (((double)*(float*)(cpu->esi))));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->esi + 0x20u))) - (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->esi + 0x24u))) - (((double)*(float*)(cpu->esi + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi))) + (((double)*(float*)(cpu->esp + 0x10u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x14u)));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x58u);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 8u)));
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    label_00055198:
    if (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled == 0u) goto label_00055357;
    if (*(uint8_t*)(cpu->ebx + 0x24u) != 0u) goto label_00055357;
    cpu->esi = cpu->esp + 0x30u;
    cpu->edi = cpu->esp + 0x70u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u;
    cpu->ecx = *(uint16_t*)(cpu->ebx + 0x26u);
    cpu->ecx += g_sfera_render_sample_runtime.material_base;
    cpu->eax = cpu->edx + (cpu->ecx * 2u);
    cpu->eax += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 2u));
    cpu->eax = *(uint16_t*)(cpu->eax);
    if ((cpu->ecx & 0xFFu) != 0xFFu) goto label_000551F5;
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->esi = cpu->ebp + (cpu->ecx * 4u);
    cpu->edi = cpu->esp + 0x54u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u; cpu->ecx = 0u;
    goto label_000552A8;
    label_000551F5:
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->ebp + (cpu->edx * 4u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    cpu->ecx = cpu->esp + 0x64u;
    cpu->edx = cpu->esi + 0x28u;
    x87_v0 = (x87_v0) * (0.00390625);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45522Fu)); sfera_sub_0044BC70(cpu, LIFT_CODE_TOKEN_VA(0x45522Fu));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esi + 0x1Cu))) - (((double)*(float*)(cpu->esi))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esi + 0x20u))) - (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->esi + 0x24u))) - (((double)*(float*)(cpu->esi + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esi))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 8u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ecx;
    label_000552A8:
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x84u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4552C7u)); sfera_sub_0044BC70(cpu, LIFT_CODE_TOKEN_VA(0x4552C7u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x70u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x58u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x74u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x5Cu);
    x87_v3 = (double)*(float*)(cpu->esp + 0x78u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v4 = (double)*(float*)((uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v4 = (x87_v4) * (x87_v3);
    *(float*)(cpu->esp + 0x20u) = x87_v4; 
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x24u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    label_00055357:
    cpu->ebp = lift_pop32(cpu);
    label_00055358:
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->edx = cpu->esp + 0x6Cu;
    *(float*)(cpu->esp + 0x90u) = x87_v0; 
    cpu->ecx = cpu->esp + 0x38u;
    *(float*)(cpu->esp + 0x94u) = (double)*(float*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 0x98u) = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455386u)); sfera_sub_0044BB80(cpu, LIFT_CODE_TOKEN_VA(0x455386u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x6Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(float*)(cpu->esp + 0x9Cu) = x87_v0; 
    cpu->ecx = cpu->esp + 0x9Cu;
    *(float*)(cpu->esp + 0xA0u) = (double)*(float*)(cpu->esp + 0x78u);
    *(float*)(cpu->esp + 0xA4u) = (double)*(float*)(cpu->esp + 0x84u);
    *(float*)(cpu->esp + 0xA8u) = (double)*(float*)(cpu->esp + 0x90u);
    *(float*)(cpu->esp + 0xACu) = (double)*(float*)(cpu->esp + 0x70u);
    *(float*)(cpu->esp + 0xB0u) = (double)*(float*)(cpu->esp + 0x7Cu);
    *(float*)(cpu->esp + 0xB4u) = (double)*(float*)(cpu->esp + 0x88u);
    *(float*)(cpu->esp + 0xB8u) = (double)*(float*)(cpu->esp + 0x94u);
    *(float*)(cpu->esp + 0xBCu) = (double)*(float*)(cpu->esp + 0x74u);
    *(float*)(cpu->esp + 0xC0u) = (double)*(float*)(cpu->esp + 0x80u);
    *(float*)(cpu->esp + 0xC4u) = (double)*(float*)(cpu->esp + 0x8Cu);
    *(float*)(cpu->esp + 0xC8u) = (double)*(float*)(cpu->esp + 0x98u);
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0xCCu) = x87_v0;
    *(float*)(cpu->esp + 0xD0u) = x87_v0;
    *(float*)(cpu->esp + 0xD4u) = x87_v0; 
    *(float*)(cpu->esp + 0xD8u) = (double)(1.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45544Fu)); sfera_sub_0044B920(cpu, LIFT_CODE_TOKEN_VA(0x45544Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->esi = cpu->esp + 0x9Cu;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    cpu->eax = *(uint8_t*)(cpu->ebx + 0x28u);
    if ((cpu->eax -= 0x64u) == 0u) goto label_000554C2;
    if ((--cpu->eax) == 0u) goto label_00055499;
    if ((--cpu->eax) != 0u) goto label_000554E9;
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.frame_102_position.x.f32) = (double)*(float*)(cpu->esp + 0xA8u);
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.frame_102_position.y.f32) = (double)*(float*)(cpu->esp + 0xB8u);
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.frame_102_position.z.f32) = (double)*(float*)(cpu->esp + 0xC8u);
    goto label_000554E9;
    label_00055499:
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.frame_101_position.x.f32) = (double)*(float*)(cpu->esp + 0xA8u);
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.frame_101_position.y.f32) = (double)*(float*)(cpu->esp + 0xB8u);
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.frame_101_position.z.f32) = (double)*(float*)(cpu->esp + 0xC8u);
    goto label_000554E9;
    label_000554C2:
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.transform_scratch.x.f32) = (double)*(float*)(cpu->esp + 0xA8u);
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.transform_scratch.y.f32) = (double)*(float*)(cpu->esp + 0xB8u);
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.transform_scratch.z.f32) = (double)*(float*)(cpu->esp + 0xC8u);
    label_000554E9:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x28u));
    if ((cpu->eax & 0xFFu) >= 5u) goto label_0005552C;
    cpu->edi = cpu->eax & 0xFFu;
    if ((int32_t)cpu->edi >= 0) goto label_00055501;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55501u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55501u));
    label_00055501:
    if ((int32_t)(cpu->edi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity))) goto label_00055515;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55515u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55515u));
    label_00055515:
    cpu->edi <<= 6u;
    cpu->edi += g_sfera_scene_array_runtime.character_matrices.data;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esp + 0x9Cu),64u); cpu->edi += 64u; cpu->ecx = 0u;
    label_0005552C:
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx + 0x21u) <= 0u) goto label_00055568;
    label_00055540:
    cpu->ecx = g_sfera_world_render_runtime.active_model;
    cpu->eax = *(uint8_t*)(cpu->ebx + 0x22u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x4Cu);
    cpu->edx += cpu->eax;
    cpu->edx = *(uint8_t*)(cpu->edx + cpu->esi);
    cpu->ecx = cpu->esp + 0x9Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45555Fu)); sfera_sub_00454FF0(cpu, LIFT_CODE_TOKEN_VA(0x45555Fu));
    cpu->eax = *(uint8_t*)(cpu->ebx + 0x21u);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_00055540;
    label_00055568:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455580(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    (void)cpu;
    label_000555A0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    cpu->ebx = cpu->eax;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax += cpu->eax;
    *(float*)(cpu->esp + 0xCu) = (fabs(((double)*(float*)(cpu->esi + (cpu->eax * 8u) + 0x40u))));
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    goto label_000555D3;
    label_000555CD:
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    label_000555D3:
    cpu->ecx = cpu->ebx + (cpu->ebx * 4u);
    cpu->ecx += cpu->ecx;
    cpu->ecx = cpu->esi + (cpu->ecx * 8u) + 0x3Cu;
    label_000555DC:
    cpu->eax = cpu->ecx;
    x87_v1 = (double)*(float*)(cpu->eax + 4u);
    ++cpu->ebx;
    x87_v1 = fabs(x87_v1);
    cpu->ecx += 0x50u;
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0xCu); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_000555DC; }
    cpu->eax = cpu->edx + (cpu->edx * 4u);
    --cpu->ebx;
    cpu->eax += cpu->eax;
    cpu->ecx = cpu->esi + (cpu->eax * 8u) + 0x3Cu;
    label_00055602:
    cpu->eax = cpu->ecx;
    x87_v1 = (double)*(float*)(cpu->eax + 4u);
    --cpu->edx;
    x87_v1 = fabs(x87_v1);
    cpu->ecx -= 0x50u;
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0xCu); const double lift_right=x87_v0; if (lift_left>lift_right) goto label_00055602; }
    ++cpu->edx;
    if ((cpu->ebx != cpu->edx) && ((int32_t)(cpu->ebx) >= (int32_t)(cpu->edx))) goto label_00055671;
    cpu->ecx = cpu->ebx + (cpu->ebx * 4u);
    cpu->ecx <<= 4u;
    cpu->esi += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    std::memmove((void*)(cpu->esp + 0x18u),(void*)(cpu->esi),80u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    cpu->eax = cpu->edx + (cpu->edx * 4u);
    cpu->eax += cpu->eax;
    cpu->esi = cpu->ecx + (cpu->eax * 8u);
    std::memmove((void*)(*(uint32_t*)(cpu->esp + 0xCu)),(void*)(cpu->esi),80u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_03;
    cpu->edi = cpu->ecx + (cpu->eax * 8u);
    ++cpu->ebx;
    --cpu->edx;
    cpu->esi = cpu->esp + 0x18u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),80u); cpu->esi += 80u; cpu->edi += 80u; cpu->ecx = 0u;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->edx) goto label_000555CD;
    label_00055671:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = x87_v0; 
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edx) goto label_00055680;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55680u)); sfera_sub_00455580(cpu, LIFT_CODE_TOKEN_RVA(0x55680u));
    label_00055680:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_00055691;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    goto label_000555A0;
    label_00055691:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004556B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    label_000556C0:
    if ((int32_t)cpu->ebx >= 0) goto label_000556CE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x556CEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x556CEu));
    label_000556CE:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_000556E2;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x556E2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x556E2u));
    label_000556E2:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebx * 4u)) == 0u) goto label_000556F0;
    ++cpu->ebx;
    goto label_000556C0;
    label_000556F0:
    lift_push32(cpu, 0x2E2Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x6E0Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455704u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x455704u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_00055714;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55714u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55714u));
    label_00055714:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00055728;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55728u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55728u));
    label_00055728:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u)) = cpu->esi;
    *(float*)(cpu->esi + 0x34u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->eax -= cpu->ebp;
    cpu->edx = 1u;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ecx;
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    cpu->ecx += cpu->edx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x6E08u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    *(uint32_t*)(cpu->esi + 0x6DA4u) = cpu->ecx;
    std::memset((void*)(cpu->esi + 0x44u),0xFF,(0x1B58u)*4u); cpu->ecx = 0u;
    g_sfera_main_command_state_runtime.window_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004557C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_000557D4;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x557D4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x557D4u));
    label_000557D4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_000557E8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x557E8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x557E8u));
    label_000557E8:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_000557FE;
    cpu->ecx = (uintptr_t)"internal error 75248635";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x557FEu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x557FEu));
    label_000557FE:
    if (*(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x44u) != 0xFFFFFFFFu) goto label_0005580F;
    cpu->ecx = (uintptr_t)"internal error 86557243";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5580Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5580Fu));
    label_0005580F:
    *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x44u) = 0xFFFFFFFFu;
    --*(uint32_t*)(cpu->esi + 0x40u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455820(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00055865;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005583B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5583Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5583Bu));
    label_0005583B:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00055865;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005585A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5585Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5585Au));
    label_0005585A:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00055865:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00055873:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00055873;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetWindowPointer: wrong handle"),31u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45588Fu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45588Fu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004558A0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    cpu->esp -= 0x54u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_00055BD8;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000558D8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x558D8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x558D8u));
    label_000558D8:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00055BD8;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000558FB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x558FBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x558FBu));
    label_000558FB:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455913u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x455913u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->esi = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->esi;
    if (*(uint32_t*)(cpu->eax + 0x6Cu) != 0u) goto label_0005593F;
    x87_v0 = (double)*(float*)(cpu->eax + 0x74u);
    goto label_00055945;
    label_0005593F:
    x87_v0 = (double)*(float*)(cpu->eax + 0x8Cu);
    label_00055945:
    sub_pred[0] = (uint32_t)(g_sfera_world_objects.object_handles.capacity) == 1u; sub_pred[2] = (int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) < (int32_t)(1u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    if ((!sub_pred[0]) && (!sub_pred[2])) goto label_00055965;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55965u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55965u));
    label_00055965:
    cpu->esi = g_sfera_world_objects.object_handles.data;
    if (((uint32_t)(g_sfera_world_objects.object_handles.capacity) != 1u) && ((int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) >= (int32_t)(1u))) goto label_00055983;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55983u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55983u));
    label_00055983:
    sub_pred[1] = (uint32_t)(g_sfera_world_objects.object_handles.capacity) == 1u; sub_pred[3] = (int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) < (int32_t)(1u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->ecx + 8u);
    *(float*)(cpu->esp + 0x24u) = (double)*(float*)(cpu->edx + 0x10u);
    *(float*)(cpu->esp + 8u) = ((((double)*(float*)(cpu->esp + 0x28u))) - (((double)*(float*)(cpu->esp + 0x1Cu))));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = 0.0;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v0 = (x87_v0) - (x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_v1 = (double)*(float*)(cpu->esp + 8u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (x87_v2);
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    *(float*)(cpu->esp + 0x14u) = ((0.10000000149011612) / (((double)*(float*)(cpu->esp + 0x14u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x38u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x40u) = ((((double)*(float*)(cpu->esp + 0x40u))) - (((double)*(float*)(cpu->esp + 0x34u))));
    *(float*)(cpu->esp + 0x44u) = ((((double)*(float*)(cpu->esp + 0x44u))) - (((double)*(float*)(cpu->esp + 0x38u))));
    *(float*)(cpu->esp + 0x48u) = ((((double)*(float*)(cpu->esp + 0x48u))) - (((double)*(float*)(cpu->esp + 0x3Cu))));
    if ((!sub_pred[1]) && (!sub_pred[3])) goto label_00055A56;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55A56u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55A56u));
    label_00055A56:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 0xCu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x2Cu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_00055AA6; }
    *(float*)(cpu->esp + 8u) = (-((double)*(float*)(cpu->esp + 0x34u)));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    x87_v1 = -x87_v1;
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    x87_v1 = -x87_v1;
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    label_00055AA6:
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u);
    cpu->edx = cpu->esp + 0x34u;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x28u)));
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x30u) = x87_v1; 
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->esp + 0x44u))) + (((double)*(float*)(cpu->esp + 0x38u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455ADAu)); sfera_sub_0042F7D0(cpu, LIFT_CODE_TOKEN_VA(0x455ADAu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->esi = cpu->eax;
    x87_v1 = 1.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left!=lift_right) goto label_00055B14; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00055B14:
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455B28u)); sfera_sub_0042F7D0(cpu, LIFT_CODE_TOKEN_VA(0x455B28u));
    if (cpu->esi != 1u) goto label_00055C00;
    if (cpu->eax != cpu->esi) goto label_00055C00;
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x4Cu); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x50u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0xCu) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x3Cu);
    x87_v3 = (double)*(float*)(cpu->esp + 0x54u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v4 = (x87_v4) * (x87_v3);
    *(float*)(cpu->esp + 0x44u) = x87_v4; 
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x48u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x40u);
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 8u) = x87_v2; 
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x44u)));
    cpu->eax = cpu->esi;
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + 8u) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00055BD8:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00055BE5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00055BE5;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"Project_TopCharToScreen: wrong handle"),38u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55C00u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x55C00u));
    label_00055C00:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x54u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455C20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00055C31;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55C31u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55C31u));
    label_00055C31:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00055C45;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55C45u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55C45u));
    label_00055C45:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->eax != 0u) goto label_00055C7B;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = cpu->eax & 0xFFu;
    --cpu->edi;
    label_00055C60:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00055C60;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"delete_sprite: wrong handle"),28u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    sfera_sub_0044F500(cpu, stop_address); return;
    label_00055C7B:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455C86u)); sfera_sub_004557C0(cpu, LIFT_CODE_TOKEN_VA(0x455C86u));
    if ((int32_t)cpu->esi >= 0) goto label_00055C94;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55C94u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55C94u));
    label_00055C94:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00055CA8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55CA8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55CA8u));
    label_00055CA8:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    lift_push32(cpu, 0x30CCu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455CC0u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x455CC0u));
    if ((int32_t)cpu->esi >= 0) goto label_00055CCE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55CCEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55CCEu));
    label_00055CCE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00055CE2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55CE2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55CE2u));
    label_00055CE2:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = 0u;
    g_sfera_main_view_state_runtime.projection_sample_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) - 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455D00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x3Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    x87_v0 = (double)*(float*)(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    cpu->eax = cpu->esp + 0x20u;
    x87_v0 = (double)*(float*)(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455D36u)); sfera_sub_00451A40(cpu, LIFT_CODE_TOKEN_VA(0x455D36u));
    if (cpu->eax == 1u) goto label_00055D45;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00055D45:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, 3u);
    cpu->eax = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->edx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    cpu->esi += 0x30u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455D6Cu)); sfera_sub_00451B40(cpu, LIFT_CODE_TOKEN_VA(0x455D6Cu));
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455D80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp >= 0) goto label_00055D92;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55D92u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55D92u));
    label_00055D92:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00055DA6;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55DA6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55DA6u));
    label_00055DA6:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->ebp * 4u));
    if (*(uint32_t*)(cpu->edi + 0x24u) == 0xF4240u) goto label_00055DF1;
    --g_sfera_world_load_runtime.live_object_count;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x24u);
    if ((int32_t)cpu->ebx > (int32_t)*(uint32_t*)(cpu->edi + 0x28u)) goto label_00055DF0;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    lift_push32(cpu, cpu->esi);
    label_00055DD0:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x2Cu);
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_00055DE9;
    label_00055DD7:
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455DE1u)); sfera_sub_00489BA0(cpu, LIFT_CODE_TOKEN_VA(0x455DE1u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    ++cpu->esi;
    if ((int32_t)cpu->esi <= (int32_t)cpu->eax) goto label_00055DD7;
    label_00055DE9:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx <= (int32_t)*(uint32_t*)(cpu->edi + 0x28u)) goto label_00055DD0;
    cpu->esi = lift_pop32(cpu);
    label_00055DF0:
    cpu->ebx = lift_pop32(cpu);
    label_00055DF1:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455E00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00055E11;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55E11u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55E11u));
    label_00055E11:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00055E2F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455E25u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x455E25u));
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00055E2F:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455E40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_00055E9A;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00055E5E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55E5Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55E5Eu));
    label_00055E5E:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00055E9A;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00055E7D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55E7Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55E7Du));
    label_00055E7D:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00055E9A:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00055EA8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00055EA8;
    cpu->esi = (uintptr_t)"GetObjectPos: wrong handle";
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),27u); cpu->esi += 27u; cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455EC4u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x455EC4u));
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00055EDC;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55EDCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55EDCu));
    label_00055EDC:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455F00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_00055F80;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00055F1F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55F1Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55F1Fu));
    label_00055F1F:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00055F80;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00055F3E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55F3Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55F3Eu));
    label_00055F3E:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00055F5B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55F5Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55F5Bu));
    label_00055F5B:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx += 0x14u;
    cpu->ecx += 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455F71u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x455F71u));
    x87_v0 = 0.0;
    *(float*)(cpu->ebx + 0xCu) = x87_v0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x1Cu) = x87_v0;
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x2Cu) = x87_v0; 
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00055F80:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00055F90:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00055F90;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetObjectOrient: wrong handle"),30u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455FABu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x455FABu));
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x455FB0u));
    x87_v0 = 1.0;
    cpu->esp += 0xCu;
    *(float*)(cpu->ebx + 0x3Cu) = x87_v0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x28u) = x87_v0;
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x14u) = x87_v0;
    *(float*)(cpu->ebx) = x87_v0; 
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = 1u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00055FEA;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55FEAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55FEAu));
    label_00055FEA:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00056030;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x456027u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x456027u));
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00056030:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_00056054;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56054u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56054u));
    label_00056054:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00056068;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56068u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56068u));
    label_00056068:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->eax = 0u;
    cpu->ecx = cpu->esi + 0x10Cu;
    label_00056078:
    if (*(uint32_t*)(cpu->ecx) == 0xFFFFFFFFu) goto label_0005608B;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)cpu->eax < (int32_t)0xAu) goto label_00056078;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005608B:
    *(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 0x10Cu) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004560A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_000560B4;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x560B4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x560B4u));
    label_000560B4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000560C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x560C8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x560C8u));
    label_000560C8:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_000560FB;
    cpu->eax = 0u;
    cpu->ecx = cpu->esi + 0x10Cu;
    label_000560E0:
    if (*(uint32_t*)(cpu->ecx) == cpu->edi) goto label_000560F0;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)cpu->eax < (int32_t)0xAu) goto label_000560E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000560F0:
    *(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 0x10Cu) = 0xFFFFFFFFu;
    label_000560FB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456100(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_00056110:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edi + cpu->edx;
    cpu->ebx = (uint32_t)((int32_t)cpu->ebx >> 1u);
    cpu->esi = cpu->edx;
    if ((int32_t)cpu->ebx >= 0) goto label_00056127;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56127u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56127u));
    label_00056127:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_0005613B;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5613Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5613Bu));
    label_0005613B:
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    *(float*)(cpu->esp + 0x14u) = (fabs(((double)*(float*)(cpu->ecx + 0x38u))));
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x14u);
    label_00056154:
    if ((int32_t)cpu->edi >= 0) goto label_00056162;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56162u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56162u));
    label_00056162:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_00056176;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56176u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56176u));
    label_00056176:
    cpu->edx = g_sfera_light_runtime.visible_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    x87_v0 = (double)*(float*)(cpu->eax + 0x38u);
    ++cpu->edi;
    x87_v0 = fabs(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    { const double lift_right=(double)*(float*)(cpu->esp + 0x18u); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (lift_left>lift_right) goto label_00056154; }
    --cpu->edi;
    label_000561A0:
    if ((int32_t)cpu->esi >= 0) goto label_000561AE;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x561AEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x561AEu));
    label_000561AE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_000561C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x561C2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x561C2u));
    label_000561C2:
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    x87_v0 = (double)*(float*)(cpu->edx + 0x38u);
    --cpu->esi;
    x87_v0 = fabs(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    { const double lift_right=(double)*(float*)(cpu->esp + 0x18u); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (lift_left<lift_right) goto label_000561A0; }
    ++cpu->esi;
    if ((int32_t)cpu->edi > (int32_t)cpu->esi) goto label_000562A5;
    if ((int32_t)cpu->edi >= 0) goto label_000561FD;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x561FDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x561FDu));
    label_000561FD:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_00056211;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56211u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56211u));
    label_00056211:
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    cpu->ebp = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if ((int32_t)cpu->esi >= 0) goto label_00056227;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56227u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56227u));
    label_00056227:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_0005623B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5623Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5623Bu));
    label_0005623B:
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    cpu->ebx = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)cpu->edi >= 0) goto label_00056252;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56252u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56252u));
    label_00056252:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_00056266;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56266u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56266u));
    label_00056266:
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005627E;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5627Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5627Eu));
    label_0005627E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_00056292;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56292u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56292u));
    label_00056292:
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->ebp;
    ++cpu->edi;
    --cpu->esi;
    if ((int32_t)cpu->edi <= (int32_t)cpu->esi) goto label_00056154;
    label_000562A5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_000562B4;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x562B4u)); sfera_sub_00456100(cpu, LIFT_CODE_TOKEN_RVA(0x562B4u));
    label_000562B4:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)(cpu->edi) >= (int32_t)(cpu->edx)) goto label_000562C5;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    goto label_00056110;
    label_000562C5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004562D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    bool lift_cmp[1];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    label_000562D4:
    if ((int32_t)cpu->esi >= 0) goto label_000562E2;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x562E2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x562E2u));
    label_000562E2:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_000562F6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x562F6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x562F6u));
    label_000562F6:
    cpu->eax = g_sfera_light_runtime.handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00056304;
    ++cpu->esi;
    goto label_000562D4;
    label_00056304:
    lift_push32(cpu, 0x397Du);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x456318u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x456318u));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_00056328;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56328u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56328u));
    label_00056328:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_0005633C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5633Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5633Cu));
    label_0005633C:
    cpu->ecx = g_sfera_light_runtime.handles.data;
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->edi;
    x87_v1 = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v2 = 0.0;
    *(uint32_t*)(cpu->edi) = cpu->edx;
    lift_cmp[0]=x87_v2!=x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->edx;
    cpu->eax = cpu->esi;
    if (lift_cmp[0]) goto label_00056390;
    x87_v0 = x87_v0; 
    x87_v0 = (double)10.0f;
    label_00056390:
    *(float*)(cpu->edi + 0x1Cu) = x87_v0; 
    ++g_sfera_recovered_static_runtime.client_state_02;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x24u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004563A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005641B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_000563BB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x563BBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x563BBu));
    label_000563BB:
    cpu->eax = g_sfera_light_runtime.handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005641B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_000563DA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x563DAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x563DAu));
    label_000563DA:
    cpu->ecx = g_sfera_light_runtime.handles.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    lift_push32(cpu, 0x398Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4563F2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4563F2u));
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_00056406;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56406u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56406u));
    label_00056406:
    cpu->edx = g_sfera_light_runtime.handles.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = 0u;
    --g_sfera_recovered_static_runtime.client_state_02;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005641B:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00056430:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00056430;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"DeleteLight: wrong handle"),26u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    sfera_sub_0044F500(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00456450(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_00056453:
    if ((int32_t)cpu->esi >= 0) goto label_00056461;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56461u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56461u));
    label_00056461:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00056475;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56475u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56475u));
    label_00056475:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = 0u;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x1Fu) goto label_00056453;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004564A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x9Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_000564C5:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = cpu->esi;
    cpu->esi += cpu->edx;
    cpu->esi = (uint32_t)((int32_t)cpu->esi >> 1u);
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_000564DD;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x564DDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x564DDu));
    label_000564DD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_000564F1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x564F1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x564F1u));
    label_000564F1:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x74u);
    cpu->eax += g_sfera_scene_array_runtime.scene_records.data;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_00056512;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45650Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x45650Eu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00056512:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_0005652A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x456526u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x456526u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_0005652A:
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    cpu->esi = *(uint32_t*)(cpu->esi + cpu->ecx + 0x10u);
    cpu->esi += *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_00056540:
    cpu->esi = cpu->edi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    label_00056545:
    if ((int32_t)cpu->edi >= 0) goto label_00056553;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56553u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56553u));
    label_00056553:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_00056567;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56567u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56567u));
    label_00056567:
    cpu->edx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->eax = cpu->esi + cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_00056582;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56582u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56582u));
    label_00056582:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_00056596;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56596u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56596u));
    label_00056596:
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += *(uint32_t*)(cpu->eax + 0xCu);
    if (cpu->edx >= *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_000565B3;
    ++cpu->edi;
    cpu->esi += 0x74u;
    goto label_00056545;
    label_000565B3:
    cpu->esi = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    label_000565C0:
    if ((int32_t)cpu->ebx >= 0) goto label_000565CE;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x565CEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x565CEu));
    label_000565CE:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_000565E2;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x565E2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x565E2u));
    label_000565E2:
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edx = cpu->esi + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((int32_t)cpu->ebx >= 0) goto label_000565FD;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x565FDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x565FDu));
    label_000565FD:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_00056611;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56611u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56611u));
    label_00056611:
    cpu->eax = g_sfera_scene_array_runtime.scene_records.data;
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->eax + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += *(uint32_t*)(cpu->edx + 0xCu);
    if (cpu->ecx <= *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0005662D;
    --cpu->ebx;
    cpu->esi -= 0x74u;
    goto label_000565C0;
    label_0005662D:
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_00056727;
    if ((int32_t)cpu->edi >= 0) goto label_00056643;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56643u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56643u));
    label_00056643:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_00056657;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56657u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56657u));
    label_00056657:
    cpu->eax = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x74u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->esi = cpu->edi + cpu->eax;
    cpu->edi = cpu->esp + 0x28u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),116u); cpu->esi += 116u; cpu->edi += 116u; cpu->ecx = 0u;
    if ((int32_t)cpu->ebx >= 0) goto label_0005667F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5667Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5667Fu));
    label_0005667F:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_00056693;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56693u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56693u));
    label_00056693:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x74u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->esi = cpu->eax + cpu->ecx;
    if ((int32_t)cpu->edi >= 0) goto label_000566B7;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x566B7u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x566B7u));
    label_000566B7:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_000566CB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x566CBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x566CBu));
    label_000566CB:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi += g_sfera_scene_array_runtime.scene_records.data;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),116u); cpu->esi += 116u; cpu->edi += 116u; cpu->ecx = 0u;
    if ((int32_t)cpu->ebx >= 0) goto label_000566EA;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x566EAu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x566EAu));
    label_000566EA:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_000566FE;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x566FEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x566FEu));
    label_000566FE:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi += g_sfera_scene_array_runtime.scene_records.data;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->esi = cpu->esp + 0x28u;
    --cpu->ebx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),116u); cpu->esi += 116u; cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_00056540;
    label_00056727:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ecx >= (int32_t)cpu->ebx) goto label_00056736;
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56736u)); sfera_sub_004564A0(cpu, LIFT_CODE_TOKEN_RVA(0x56736u));
    label_00056736:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_00056747;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    goto label_000564C5;
    label_00056747:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456760(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x10u;
    cpu->edx = 1u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0005677D;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5677Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5677Du));
    label_0005677D:
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_world_objects.object_handles.data;
    if ((int32_t)cpu->esi >= 0) goto label_00056792;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56792u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56792u));
    label_00056792:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000567A6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x567A6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x567A6u));
    label_000567A6:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->ecx + 8u))) - (((double)*(float*)(cpu->eax + 8u))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->ecx + 0xCu))) - (((double)*(float*)(cpu->eax + 0xCu))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->ecx + 0x10u))) - (((double)*(float*)(cpu->eax + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->edi = lift_pop32(cpu);
    x87_v0 = (x87_v0) - (45.0);
    x87_v0 = (x87_v0) / (15.0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = 0.0;
    x87_v1 = (double)*(float*)(cpu->esp + 4u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00056829; }
    x87_v1 = x87_v1; 
    *(float*)(cpu->esp + 4u) = x87_v0; 
    goto label_00056840;
    label_00056829:
    x87_v0 = x87_v1; 
    x87_v1 = 1.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_0005683E; }
    *(float*)(cpu->esp + 4u) = x87_v0; 
    goto label_00056840;
    label_0005683E:
    x87_v0 = x87_v0; 
    label_00056840:
    if ((int32_t)cpu->esi >= 0) goto label_0005684E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5684Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5684Eu));
    label_0005684E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00056862;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56862u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56862u));
    label_00056862:
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_v0 = (x87_v0) * (1.399999976158142);
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0xCu)));
    *(float*)(cpu->esi + 0xCu) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    (void)cpu;
    label_00056890:
    cpu->ebx = cpu->ecx + cpu->edx;
    cpu->ebx = (uint32_t)((int32_t)cpu->ebx >> 1u);
    cpu->edi = cpu->ecx;
    cpu->esi = cpu->edx;
    if ((int32_t)cpu->ebx >= 0) goto label_000568A5;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x568A5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x568A5u));
    label_000568A5:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_000568B9;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x568B9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x568B9u));
    label_000568B9:
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->eax = cpu->ebx + (cpu->ebx * 2u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u) + 4u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    goto label_000568D4;
    label_000568D0:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000568D4:
    cpu->ebx = cpu->edi + (cpu->edi * 2u);
    cpu->ebx += cpu->ebx;
    cpu->ebx += cpu->ebx;
    label_000568E0:
    if ((int32_t)cpu->edi >= 0) goto label_000568EE;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x568EEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x568EEu));
    label_000568EE:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_00056902;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56902u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56902u));
    label_00056902:
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->eax = *(uint32_t*)(cpu->ebx + cpu->edx + 4u);
    ++cpu->edi;
    cpu->ebx += 0xCu;
    if (cpu->eax < cpu->ebp) goto label_000568E0;
    cpu->ebx = cpu->esi + (cpu->esi * 2u);
    cpu->ebx += cpu->ebx;
    --cpu->edi;
    cpu->ebx += cpu->ebx;
    label_00056920:
    if ((int32_t)cpu->esi >= 0) goto label_0005692E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5692Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5692Eu));
    label_0005692E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_00056942;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56942u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56942u));
    label_00056942:
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->edx = *(uint32_t*)(cpu->ebx + cpu->ecx + 4u);
    --cpu->esi;
    cpu->ebx -= 0xCu;
    if (cpu->edx > cpu->ebp) goto label_00056920;
    ++cpu->esi;
    if ((int32_t)cpu->edi > (int32_t)cpu->esi) goto label_00056A62;
    if ((int32_t)cpu->edi >= 0) goto label_0005696B;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5696Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5696Bu));
    label_0005696B:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_0005697F;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5697Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5697Fu));
    label_0005697F:
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ebx = cpu->edi + (cpu->edi * 2u);
    cpu->ebx += cpu->ebx;
    cpu->ebx += cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebx + cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx + cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_000569B0;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x569B0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x569B0u));
    label_000569B0:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_000569C4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x569C4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x569C4u));
    label_000569C4:
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ebp = cpu->esi + (cpu->esi * 2u);
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    cpu->ecx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->edi >= 0) goto label_000569E9;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4569E5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x4569E5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000569E9:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_00056A01;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4569FDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x4569FDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00056A01:
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->eax = cpu->ebx + cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00056A28;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56A28u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56A28u));
    label_00056A28:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.object_positions.capacity) goto label_00056A3C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56A3Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56A3Cu));
    label_00056A3C:
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->ebp) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    ++cpu->edi;
    --cpu->esi;
    *(uint32_t*)(cpu->eax + cpu->ebp + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + cpu->ebp + 8u) = cpu->ecx;
    if ((int32_t)cpu->edi <= (int32_t)cpu->esi) goto label_000568D0;
    label_00056A62:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_00056A71;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56A71u)); sfera_sub_00456880(cpu, LIFT_CODE_TOKEN_RVA(0x56A71u));
    label_00056A71:
    if ((int32_t)(cpu->edi) >= (int32_t)(*(uint32_t*)(cpu->esp + 0x18u))) goto label_00056A86;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->ecx = cpu->edi;
    goto label_00056890;
    label_00056A86:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((int32_t)g_sfera_recovered_static_runtime.font_renderer_state <= (int32_t)cpu->ebx) goto label_00056C1A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->ebp = 0u;
    label_00056AB0:
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    label_00056AC0:
    if ((int32_t)cpu->ebp >= 0) goto label_00056ACE;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56ACEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56ACEu));
    label_00056ACE:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056AE2;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56AE2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56AE2u));
    label_00056AE2:
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->eax + cpu->ebp + 0x84u)) goto label_00056BFC;
    cpu->edi = 0u;
    label_00056B00:
    if ((int32_t)cpu->ebp >= 0) goto label_00056B0E;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56B0Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56B0Eu));
    label_00056B0E:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056B22;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56B22u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56B22u));
    label_00056B22:
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->edx + cpu->ebp + 0x88u)) goto label_00056BEE;
    if ((int32_t)cpu->ebp >= 0) goto label_00056B43;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56B43u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56B43u));
    label_00056B43:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056B57;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56B57u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56B57u));
    label_00056B57:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->edx = cpu->esi + cpu->edi;
    if (*(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x8Cu) == 0u) goto label_00056BE8;
    if ((int32_t)cpu->ebp >= 0) goto label_00056B7F;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56B7Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56B7Fu));
    label_00056B7F:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056B93;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56B93u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56B93u));
    label_00056B93:
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->esi += cpu->edi;
    --*(uint32_t*)(cpu->ecx + (cpu->esi * 4u) + 0x53Cu);
    cpu->eax = cpu->ecx + (cpu->esi * 4u) + 0x53Cu;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u) + 0x53Cu) != 0u) goto label_00056BE8;
    if ((int32_t)cpu->ebp >= 0) goto label_00056BC1;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56BC1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56BC1u));
    label_00056BC1:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056BD5;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56BD5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56BD5u));
    label_00056BD5:
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ecx + cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56BE8u)); sfera_sub_00451100(cpu, LIFT_CODE_TOKEN_RVA(0x56BE8u));
    label_00056BE8:
    ++cpu->edi;
    goto label_00056B00;
    label_00056BEE:
    ++*(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0xAu) + (uint64_t)(0u);
    goto label_00056AC0;
    label_00056BFC:
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x1B3u) + (uint64_t)(0u);
    ++cpu->ebx;
    cpu->ebp += 0x6CCu;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_recovered_static_runtime.font_renderer_state) goto label_00056AB0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00056C1A:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)g_sfera_recovered_static_runtime.font_renderer_state <= (int32_t)cpu->esi) goto label_00056D4F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->ebx = 0u;
    label_00056C40:
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    label_00056C46:
    if ((int32_t)cpu->ebx >= 0) goto label_00056C54;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56C54u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56C54u));
    label_00056C54:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056C68;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56C68u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56C68u));
    label_00056C68:
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->ebx + cpu->eax + 0x84u)) goto label_00056D31;
    cpu->edi = 0u;
    label_00056C80:
    if ((int32_t)cpu->ebx >= 0) goto label_00056C8E;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56C8Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56C8Eu));
    label_00056C8E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056CA2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56CA2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56CA2u));
    label_00056CA2:
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->ebx + cpu->ecx + 0x88u)) goto label_00056D26;
    if ((int32_t)cpu->ebx >= 0) goto label_00056CBF;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56CBFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56CBFu));
    label_00056CBF:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056CD3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56CD3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56CD3u));
    label_00056CD3:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->edx += cpu->edi;
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u) + 0x8Cu) == 0u) goto label_00056D20;
    if ((int32_t)cpu->ebx >= 0) goto label_00056CFB;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56CFBu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56CFBu));
    label_00056CFB:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00056D0F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56D0Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56D0Fu));
    label_00056D0F:
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = cpu->ebx + cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56D20u)); sfera_sub_00451100(cpu, LIFT_CODE_TOKEN_RVA(0x56D20u));
    label_00056D20:
    ++cpu->edi;
    goto label_00056C80;
    label_00056D26:
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0xAu) + (uint64_t)(0u);
    goto label_00056C46;
    label_00056D31:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x1B3u) + (uint64_t)(0u);
    ++cpu->esi;
    cpu->ebx += 0x6CCu;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_recovered_static_runtime.font_renderer_state) goto label_00056C40;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00056D4F:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456D60(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_00056D76;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56D76u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x56D76u));
    label_00056D76:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00056D8A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56D8Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56D8Au));
    label_00056D8A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x456DA1u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x456DA1u));
    cpu->ebx = native_function_address32(&::_stricmp);
    cpu->edi = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x48u);
    cpu->eax = *(uint16_t*)(cpu->edx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x88u);
    cpu->eax += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"default");
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x56DC5u), LIFT_CODE_TOKEN_RVA(0x56DC3u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00056DF4;
    label_00056DD0:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x48u);
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u) + 2u);
    ++cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x88u);
    cpu->edx += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"default");
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x56DEDu), LIFT_CODE_TOKEN_RVA(0x56DEBu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00056DD0;
    label_00056DF4:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x48u);
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->esi * 2u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x88u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    sub_pred[0] = (int32_t)(cpu->ebp) < (int32_t)(*(uint32_t*)(cpu->ecx + cpu->edx + 0x24u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456E20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x84u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 8u) <= (int32_t)cpu->edi) goto label_00056FF5;
    cpu->esi = 0u;
    label_00056E4F:
    sub_pred[0] = (uint32_t)(g_sfera_world_objects.object_handles.capacity) == 1u; sub_pred[1] = (int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) < (int32_t)(1u);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xCu);
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.x);
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->eax);
    x87_v2 = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->edx * 8u));
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->edx + 4u);
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x58u)));
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->edx;
    *(float*)(cpu->esp + 0x58u) = x87_v2; 
    x87_v2 = x87_v0;
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x60u)));
    *(float*)(cpu->esp + 0x60u) = x87_v2; 
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->eax + 2u);
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->edx * 8u));
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->edx + 4u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    x87_v2 = (x87_v2) + (x87_v1);
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x64u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x6Cu);
    x87_v2 = (x87_v2) + (x87_v0);
    *(float*)(cpu->esp + 0x6Cu) = x87_v2; 
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->eax + 4u);
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->ecx = cpu->ecx + (cpu->edx * 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x70u)));
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    *(float*)(cpu->esp + 0x70u) = x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x78u)));
    *(float*)(cpu->esp + 0x78u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x7Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->eax + 0x14u);
    x87_v0 = -x87_v0;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x58u)));
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ecx;
    x87_v1 = (double)*(float*)(cpu->esp + 0x5Cu);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->eax + 0x18u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x80u)));
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->edx;
    x87_v0 = x87_v0 - x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x60u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x84u)));
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0x88u) = x87_v0; 
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_00056F5C;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x56F5Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x56F5Cu));
    label_00056F5C:
    x87_v0 = (double)*(float*)(cpu->esp + 0x7Cu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x80u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x88u);
    lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.flare_clip_vector.x.u32);
    cpu->edx += 8u;
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x24u;
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x456FA6u)); sfera_sub_00451A40(cpu, LIFT_CODE_TOKEN_VA(0x456FA6u));
    if (cpu->eax != 1u) goto label_00056FDD;
    cpu->ecx = cpu->esp + 0x58u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x68u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    cpu->eax = cpu->esp + 0x74u;
    lift_push32(cpu, 3u);
    cpu->edx = cpu->esp + 0x30u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x456FD9u)); sfera_sub_00451B40(cpu, LIFT_CODE_TOKEN_VA(0x456FD9u));
    if (cpu->eax != 0u) goto label_00057013;
    label_00056FDD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->esi += 0x1Cu;
    cpu->edi += 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebx + 8u)) goto label_00056E4F;
    label_00056FF5:
    cpu->eax = 1u;
    label_00056FFA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x84u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00057013:
    cpu->eax = 0u;
    goto label_00056FFA;
}
__declspec(noinline) void sfera_sub_00457020(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_00057090;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_00057041;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x57041u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x57041u));
    label_00057041:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    x87_v0 = (double)300.0f;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->ecx + 0xCu));  if (!(lift_left<lift_right)) goto label_00057090; }
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_00057071;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x57071u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x57071u));
    label_00057071:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    { const double lift_left=(double)*(float*)(cpu->eax + 0xCu); const double lift_right=800.0; if (!(lift_left<lift_right)) goto label_00057090; }
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00057090:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004570A0(LiftCpu* cpu, uint32_t stop_address) { double x87_p0, x87_p1, x87_p2;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_000570B4;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x570B4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x570B4u));
    label_000570B4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000570C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x570C8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x570C8u));
    label_000570C8:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4570DFu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4570DFu));
    { const double lift_left=(double)5.0f; const double lift_right=((double)*(float*)(cpu->eax + 0x194u)); if (!(lift_left>lift_right)) goto label_00057100; }
    label_000570F2:
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00057100:
    x87_p0 = (double)*(float*)(cpu->esi + 0x14u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45711Eu)); sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x45711Eu));
    { const double lift_left=cpu->fpu[0u]; const double lift_right=((double)0.15707965195178986f); std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (lift_left<=lift_right) goto label_000570F2; }
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    x87_p1 = x87_p0;
    x87_p2 = 0.15707965195178986;
    x87_p1 = (x87_p1) + (x87_p2);
    { double temporary = x87_p2; x87_p2 = x87_p1; x87_p1 = temporary; }
    *(float*)(cpu->esp + 0xCu) = x87_p2; 
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45715Cu)); sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x45715Cu));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; 
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x10u);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457177u)); sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x457177u));
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu);
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (!(lift_left<lift_right)) goto label_000571B3; }
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    x87_p1 = 6.283185958862305;
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left<lift_right)) goto label_000571E4; }
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; 
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    std::memmove(cpu->fpu, cpu->fpu + 2, 6u * sizeof(double)); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000571B3:
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (!(lift_left<lift_right)) goto label_000571E6; }
    cpu->fpu[0u] = (cpu->fpu[0u]) + (6.283185958862305);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; 
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000571E4:
    cpu->fpu[0u] = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); label_000571E6:
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004571F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == cpu->edi) goto label_0005720B;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x57205u), LIFT_CODE_TOKEN_RVA(0x57203u))) { return; }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01) = cpu->edi;
    label_0005720B:
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    if (cpu->ecx == cpu->edi) goto label_00057225;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45721Cu)); sfera_sub_004DA450(cpu, LIFT_CODE_TOKEN_VA(0x45721Cu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457222u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x457222u));
    cpu->esp += 4u;
    label_00057225:
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    g_sfera_sky_runtime.draw_resource = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_00057245;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45723Cu)); sfera_sub_004DA450(cpu, LIFT_CODE_TOKEN_VA(0x45723Cu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457242u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x457242u));
    cpu->esp += 4u;
    label_00057245:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    g_sfera_window_runtime.render_vertex_buffer = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_00057265;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45725Cu)); sfera_sub_004DA490(cpu, LIFT_CODE_TOKEN_VA(0x45725Cu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457262u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x457262u));
    cpu->esp += 4u;
    label_00057265:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_00057285;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45727Cu)); sfera_sub_004DA490(cpu, LIFT_CODE_TOKEN_VA(0x45727Cu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457282u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x457282u));
    cpu->esp += 4u;
    label_00057285:
    cpu->ecx = g_sfera_render_sample_runtime.active_record;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_000572A5;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45729Cu)); sfera_sub_004DA4D0(cpu, LIFT_CODE_TOKEN_VA(0x45729Cu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4572A2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4572A2u));
    cpu->esp += 4u;
    label_000572A5:
    g_sfera_render_sample_runtime.active_record = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4572B0u)); sfera_sub_0049A1D0(cpu, LIFT_CODE_TOKEN_VA(0x4572B0u));
    cpu->esi = (uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource;
    label_000572B5:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == cpu->edi) goto label_000572C5;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x572C3u), LIFT_CODE_TOKEN_RVA(0x572C1u))) { return; }
    *(uint32_t*)(cpu->esi) = cpu->edi;
    label_000572C5:
    cpu->esi += 0x10u;
    if ((int32_t)cpu->esi < (int32_t)((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource + kTextureCacheEntryCount * (uint32_t)sizeof(SferaTextureCacheEntry))) goto label_000572B5;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4572D5u)); sfera_sub_00456C20(cpu, LIFT_CODE_TOKEN_VA(0x4572D5u));
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    if (cpu->ecx == cpu->edi) goto label_000572EF;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4572E6u)); sfera_sub_004DA450(cpu, LIFT_CODE_TOKEN_VA(0x4572E6u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4572ECu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4572ECu));
    cpu->esp += 4u;
    label_000572EF:
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    g_sfera_sky_runtime.draw_resource = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_0005730F;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457306u)); sfera_sub_004DA450(cpu, LIFT_CODE_TOKEN_VA(0x457306u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45730Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x45730Cu));
    cpu->esp += 4u;
    label_0005730F:
    g_sfera_window_runtime.render_vertex_buffer = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45731Au)); sfera_sub_004C3AD0(cpu, LIFT_CODE_TOKEN_VA(0x45731Au));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457325u)); sfera_sub_004D8360(cpu, LIFT_CODE_TOKEN_VA(0x457325u));
    if ((cpu->eax & 0xFFu) != 1u) goto label_00057349;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    if (cpu->ecx == cpu->edi) goto label_00057349;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45733Au)); sfera_sub_004DB000(cpu, LIFT_CODE_TOKEN_VA(0x45733Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457340u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x457340u));
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02) = cpu->edi;
    label_00057349:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if (cpu->ecx == cpu->edi) goto label_00057369;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45735Au)); sfera_sub_004DA670(cpu, LIFT_CODE_TOKEN_VA(0x45735Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457360u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x457360u));
    cpu->esp += 4u;
    g_sfera_graphics_runtime.d3d9_device = cpu->edi;
    label_00057369:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00457370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi != 0xFFFFFFFFu) goto label_00057384;
    cpu->ecx = (uintptr_t)"Wrong hand was used!";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457382u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x457382u));
    goto label_00057388;
    label_00057384:
    if ((int32_t)cpu->esi >= 0) goto label_00057392;
    label_00057388:
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x57392u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x57392u));
    label_00057392:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000573A6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x573A6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x573A6u));
    label_000573A6:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->edi != 0u) goto label_000573BD;
    cpu->ecx = (uintptr_t)"delete_text: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x573BDu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x573BDu));
    label_000573BD:
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4573C8u)); sfera_sub_004557C0(cpu, LIFT_CODE_TOKEN_VA(0x4573C8u));
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)cpu->esi >= 0) goto label_000573D7;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x573D7u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x573D7u));
    label_000573D7:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000573EB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x573EBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x573EBu));
    label_000573EB:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x990u);
    lift_push32(cpu, 0xC37u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457409u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x457409u));
    if ((int32_t)cpu->esi >= 0) goto label_00057417;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x57417u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x57417u));
    label_00057417:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005742B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5742Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5742Bu));
    label_0005742B:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    lift_push32(cpu, 0xC38u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457443u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x457443u));
    if ((int32_t)cpu->esi >= 0) goto label_00057451;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x57451u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x57451u));
    label_00057451:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005747A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457465u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x457465u));
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = 0u;
    g_sfera_main_view_state_runtime.projection_sample_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) - 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005747A:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = 0u;
    g_sfera_main_view_state_runtime.projection_sample_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) - 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00457490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_0005750C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    (void)cpu;
    label_000574A0:
    if ((int32_t)cpu->esi >= 0) goto label_000574AE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574AEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x574AEu));
    label_000574AE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000574C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574C2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x574C2u));
    label_000574C2:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_000574D0;
    ++cpu->esi;
    goto label_000574A0;
    label_000574D0:
    if ((int32_t)cpu->esi >= 0) goto label_000574DE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574DEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x574DEu));
    label_000574DE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000574F2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574F2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x574F2u));
    label_000574F2:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint32_t*)(cpu->edx) != 0u) goto label_00057507;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x57507u)); sfera_sub_00457370(cpu, LIFT_CODE_TOKEN_RVA(0x57507u));
    label_00057507:
    ++cpu->esi;
    if ((--cpu->edi) != 0u) goto label_000574A0;
    cpu->edi = lift_pop32(cpu);
    label_0005750C:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00457510(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x50u);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x457527u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457538u)); sfera_sub_004549B0(cpu, LIFT_CODE_TOKEN_VA(0x457538u));
    if ((cpu->ebx & 0xFFu) != 0u) goto label_0005755D;
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=1000.0; if (!(lift_left>lift_right)) goto label_0005755D; }
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_16 != 0u) goto label_0005755D;
    cpu->ebx = 1u;
    goto label_0005755F;
    label_0005755D:
    cpu->ebx = 0u;
    label_0005755F:
    *(uint8_t*)(cpu->esi + 0x30u) = cpu->ebx & 0xFFu;
    if (cpu->edi != 2u) goto label_0005756F;
    x87_v0 = 0.03490658950558778;
    goto label_000575BD;
    label_0005756F:
    x87_v0 = 0.6000000238418579;
    x87_v0 = std::tan(x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x24u) = ((((double)(((int32_t)(g_sfera_graphics_runtime.display_height))))) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width)))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v1 = (x87_v1) / (0.75);
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v0 = std::atan(x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v0 = (x87_v0) + (x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    label_000575BD:
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esi + 0x48u) = x87_v0;
    if (cpu->edi != 2u) goto label_000575D5;
    x87_v1 = (double)997.0f;
    goto label_000575DB;
    label_000575D5:
    x87_v1 = (double)0.10000000149011612f;
    label_000575DB:
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    *(float*)(cpu->esi + 0x40u) = (double)*(float*)(cpu->esp + 0x24u);
    x87_v1 = 0.0;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_00057698;
    x87_v0 = x87_v1; 
    cpu->eax = cpu->edi + 0xFFFFFFFEu;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xFFFFFC63u;
    cpu->eax += 0x3EDu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 0x20u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esi + 0x44u) = x87_v1;
    x87_v2 = 20.0;
    x87_v2 = (x87_v1) - (x87_v2);
    *(float*)(cpu->esi + 4u) = x87_v2; 
    *(float*)(cpu->esi + 8u) = x87_v1; 
    *(float*)(cpu->esi + 0x24u) = (double)59.0f;
    *(float*)(cpu->esi + 0x28u) = (double)37.0f;
    *(float*)(cpu->esi + 0x2Cu) = (double)12.0f;
    *(float*)(cpu->esi + 0x18u) = (double)19.0f;
    *(float*)(cpu->esi + 0x1Cu) = (double)47.0f;
    *(float*)(cpu->esi + 0x20u) = (double)71.0f;
    *(float*)(cpu->esi + 0xCu) = x87_v0;
    *(float*)(cpu->esi + 0x10u) = x87_v0;
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    x87_v0 = 14.0;
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u); x87_v1 = x87_v0;
    x87_v2 = 1.0;
    x87_v1 = x87_v2 / x87_v1; 
    *(float*)(cpu->esi + 0x34u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (-3.0) / (x87_v1);
    *(float*)(cpu->esi + 0x38u) = x87_v1; 
    x87_v0 = (2.0) / (x87_v0);
    *(float*)(cpu->esi + 0x3Cu) = x87_v0; 
    goto label_0005777E;
    label_00057698:
    x87_v1 = x87_v1; 
    x87_v0 = (x87_v0) * (0.5);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    *(float*)(cpu->esi + 0x44u) = ((((double)*(float*)(cpu->esp + 0x24u))) * (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y))));
    *(float*)(cpu->esi + 4u) = (double)150.0f;
    *(float*)(cpu->esi + 8u) = (double)200.0f;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4576D5u)); sfera_sub_00457020(cpu, LIFT_CODE_TOKEN_VA(0x4576D5u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_0005772C;
    cpu->ecx = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_main_aux_runtime.secondary_world_manager;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4576F0u)); sfera_sub_00495360(cpu, LIFT_CODE_TOKEN_VA(0x4576F0u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4576F5u)); sfera_sub_00457020(cpu, LIFT_CODE_TOKEN_VA(0x4576F5u));
    lift_test[0]=cpu->eax==0u;
    cpu->eax = g_sfera_main_aux_runtime.secondary_world_manager;
    if (!lift_test[0]) goto label_00057703;
    cpu->eax = g_sfera_font_runtime.renderer;
    label_00057703:
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = g_sfera_world_render_queue_runtime.entries[0];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    goto label_00057779;
    label_0005772C:
    cpu->eax = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_font_runtime.renderer;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45773Fu)); sfera_sub_00495360(cpu, LIFT_CODE_TOKEN_VA(0x45773Fu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457744u)); sfera_sub_00457020(cpu, LIFT_CODE_TOKEN_VA(0x457744u));
    lift_test[1]=cpu->eax==0u;
    cpu->eax = g_sfera_main_aux_runtime.secondary_world_manager;
    if (!lift_test[1]) goto label_00057752;
    cpu->eax = g_sfera_font_runtime.renderer;
    label_00057752:
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_recovered_static_runtime.scene_state_08;
    label_00057779:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5777Eu)); sfera_sub_0049E500(cpu, LIFT_CODE_TOKEN_RVA(0x5777Eu));
    label_0005777E:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 == 0u) goto label_000577AE;
    *(float*)(cpu->esi + 4u) = (double)1040.0f;
    x87_v0 = (double)1050.0f;
    *(float*)(cpu->esi + 8u) = x87_v0;
    *(float*)(cpu->esi + 0x40u) = (double)100.0f;
    *(float*)(cpu->esi + 0x44u) = x87_v0; 
    *(float*)(cpu->esi + 0x48u) = (double)0.20000000298023224f;
    label_000577AE:
    if (g_sfera_client_config_runtime.state_17 == 0u) goto label_000577D1;
    if (cpu->edi == 2u) goto label_000577D1;
    *(float*)(cpu->esi + 4u) = (double)180.0f;
    x87_v0 = (double)200.0f;
    *(float*)(cpu->esi + 8u) = x87_v0;
    *(float*)(cpu->esi + 0x44u) = x87_v0; 
    label_000577D1:
    { const double lift_right=(double)*(float*)(cpu->esi + 0x44u); const double lift_left=(double)*(float*)(cpu->esi + 8u); if (!(lift_left>lift_right)) goto label_0005782E; }
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esi + 0x44u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esi + 8u) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esi + 4u);
    x87_v2 = 20.0;
    x87_v1 = (x87_v1) + (x87_v2);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v2; const double lift_right=x87_v0;  if (!(lift_left>lift_right)) goto label_0005782A; }
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esi + 4u) = x87_v0;
    x87_v1 = 0.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>lift_right)) goto label_0005782C; }
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi + 4u) = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0005782A:
    x87_v0 = x87_v1; 
    label_0005782C:
    x87_v0 = x87_v0; 
    label_0005782E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00457840(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5;
    bool lift_cmp[1];
    cpu->esp -= 0x3Cu;
    sub_pred[0] = (uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) == 1u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    if (!sub_pred[0]) goto label_0005786C;
    cpu->eax = 0u;
    g_sfera_client_main_scalar_runtime.state_01 = cpu->eax;
    g_sfera_main_aux_runtime.color_component = cpu->eax;
    g_sfera_recovered_static_runtime.animation_result_b = cpu->eax;
    g_sfera_recovered_static_runtime.render_state_09 = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0005786C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x44u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_p0 = std::atan2(x87_p0, x87_p1); 
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x18u) = (-((double)*(float*)(cpu->esp + 4u)));
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x44u)));
    *(double*)(cpu->esp + 0x2Cu) = x87_p0;
     x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp + 0x34u) = ((*(double*)(cpu->esp + 0x2Cu)) - ((((((double)*(float*)(cpu->esp + 0x28u))) * (((double)*(float*)(cpu->esp + 0x4Cu)))))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x38u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p0 = std::atan2(x87_p0, x87_p1); 
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->esp + 0x28u))) + (1.5707964897155762));
    g_sfera_main_ui_state_runtime.scene_scale = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    g_sfera_main_command_state_runtime.sky_blend_factor = x87_p0;
    x87_p0 = (x87_p0) * (0.31830985316916194);
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x48u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x44u);
    x87_p0 = std::atan2(x87_p0, x87_p1); 
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 0x28u))) - (1.5707964897155762));
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (!(lift_left<lift_right)) goto label_00057958; }
    cpu->fpu[0u] = (cpu->fpu[0u]) + (6.283185958862305);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->esp + 4u);
    label_00057958:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.15915492658458097);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if ((cpu->ebx & 0xFFu) == 0u) goto label_0005798F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45796Bu)); sfera_sub_00457020(cpu, LIFT_CODE_TOKEN_VA(0x45796Bu));
    x87_p0 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, (uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0]); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_font_runtime.renderer;
    *(float*)(cpu->esp) = x87_p0; 
    if (cpu->eax == 0u) goto label_0005798A;
    cpu->ecx = g_sfera_main_aux_runtime.secondary_world_manager;
    label_0005798A:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5798Fu)); sfera_sub_00495090(cpu, LIFT_CODE_TOKEN_RVA(0x5798Fu));
    label_0005798F:
    x87_p0 = (double)*(float*)(cpu->esp + 4u); x87_p1 = x87_p0;
    x87_p2 = (double)g_sfera_sky_interpolation_runtime.primary_key_positions[0];
    lift_cmp[0]=x87_p2>x87_p1;
    x87_p1 = x87_p2; 
    x87_p2 = 1.0;
    std::memmove(cpu->fpu + 3, cpu->fpu, 5u * sizeof(double)); cpu->fpu[0u] = x87_p2; cpu->fpu[1u] = x87_p1; cpu->fpu[2u] = x87_p0; if (!lift_cmp[0]) goto label_000579C5;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_sky_interpolation_runtime.primary_key_positions[9]));
    cpu->eax = 9u;
    cpu->ecx=0u;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->esp + 0x14u); x87_p0 = cpu->fpu[0u];
    cpu->fpu[2u] = cpu->fpu[2u] + x87_p0; 
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); goto label_00057A32;
    label_000579C5:
    x87_p0 = cpu->fpu[2u];
    x87_p1 = (double)g_sfera_sky_interpolation_runtime.primary_key_positions[9];
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (!(lift_left<lift_right)) goto label_000579EB; }
    x87_p0 = cpu->fpu[0u];
    cpu->eax = 9u;
    cpu->fpu[3u] = cpu->fpu[3u] - x87_p0; 
    cpu->ecx=0u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; 
    cpu->fpu[2u] = cpu->fpu[1u] - cpu->fpu[2u]; 
    std::memmove(cpu->fpu, cpu->fpu + 2, 6u * sizeof(double)); goto label_00057A32;
    label_000579EB:
    cpu->fpu[0u] = cpu->fpu[0u]; 
    cpu->ecx = 1u;
    cpu->fpu[2u] = cpu->fpu[1u]; 
    cpu->fpu[2u] = cpu->fpu[2u]; 
    cpu->fpu[2u] = cpu->fpu[3u];
    std::memmove(cpu->fpu, cpu->fpu + 2, 6u * sizeof(double)); { const double lift_left=(double)g_sfera_sky_interpolation_runtime.primary_key_positions[1]; const double lift_right=cpu->fpu[0u]; if (!(lift_left<lift_right)) goto label_00057A18; }
    label_00057A07:
    x87_p0 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[1]));
    ++cpu->ecx;
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (lift_left<lift_right) goto label_00057A07; }
    label_00057A18:
    cpu->fpu[0u] = cpu->fpu[0u]; 
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    cpu->fpu[1u] = (cpu->fpu[1u]) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0]))));
    cpu->fpu[0u] = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0]));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0]))));
    label_00057A32:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; 
    cpu->ecx <<= 4u;
    cpu->ecx += (uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0];
    cpu->eax <<= 4u;
    cpu->eax += ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->ecx);
    cpu->fpu[1u] = (cpu->fpu[1u]) - (((double)*(float*)(cpu->eax)));
    cpu->fpu[0u] = (double)*(float*)(cpu->esp + 4u); x87_p0 = cpu->fpu[0u];
    cpu->fpu[1u] = cpu->fpu[1u] * x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax);
    cpu->fpu[1u] = cpu->fpu[1u] + x87_p0; 
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->ecx + 4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 4u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 4u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->ecx + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 8u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->ecx + 0xCu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xCu)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; 
    cpu->fpu[1u] = (cpu->fpu[1u]) + (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 0x48u);
    cpu->fpu[0u] = (double)*(float*)(cpu->esp + 0x44u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x4Cu);
    x87_p1 = cpu->fpu[0u];
    cpu->fpu[0u] = cpu->fpu[0u] * x87_p1; 
    x87_p1 = cpu->fpu[1u];
    cpu->fpu[1u] = cpu->fpu[1u] * x87_p1; 
    { double temporary = x87_p0; x87_p0 = cpu->fpu[0u]; cpu->fpu[0u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + x87_p0; 
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; 
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    cpu->fpu[1u] = std::sqrt(cpu->fpu[1u]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    cpu->fpu[0u] = 1.0;
    x87_p0 = cpu->fpu[0u];
    cpu->fpu[1u] = x87_p0 / cpu->fpu[1u]; 
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->esp + 0x48u);
    x87_p0 = -0.30000001192092896;
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    x87_p1 = (double)*(float*)(cpu->esp + 0x4Cu); x87_p2 = x87_p1;
    x87_p2 = fabs(x87_p2);
    *(float*)(cpu->esp + 4u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 4u);
    x87_p2 = (x87_p2) * (0.9539999961853027);
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p3 = x87_p2;
    x87_p0 = x87_p0 * x87_p3; 
    { double temporary = x87_p2; x87_p2 = x87_p0; x87_p0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 4u);
    x87_p2 = (x87_p2) * (x87_p2);
    *(float*)(cpu->esp + 4u) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.x);
    x87_p3 = (double)*(float*)(cpu->esp + 0x10u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 4u); x87_p5 = x87_p4;
    x87_p2 = x87_p2 * x87_p5; 
    { double temporary = x87_p4; x87_p4 = x87_p2; x87_p2 = temporary; }
    x87_p3 = x87_p3 + x87_p4; 
    *(float*)(cpu->esp + 0x10u) = x87_p3; 
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.y);
    x87_p4 = (double)*(float*)(cpu->esp + 0xCu); x87_p5 = x87_p4;
    x87_p3 = x87_p3 - x87_p5; 
    x87_p5 = x87_p2;
    x87_p3 = x87_p3 * x87_p5; 
    x87_p3 = x87_p3 + x87_p4; 
    *(float*)(cpu->esp + 0xCu) = x87_p3; 
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.z);
    x87_p4 = (double)*(float*)(cpu->esp + 8u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 - x87_p5; 
    x87_p5 = x87_p2;
    x87_p3 = x87_p3 * x87_p5; 
    x87_p3 = x87_p3 + x87_p4; 
    *(float*)(cpu->esp + 8u) = x87_p3; 
    x87_p3 = (double)g_sfera_sky_interpolation_runtime.primary_reference.w;
    x87_p4 = (double)*(float*)(cpu->esp + 0x14u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 - x87_p5; 
    { double temporary = x87_p4; x87_p4 = x87_p3; x87_p3 = temporary; }
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x14u) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    cpu->fpu[0u] = cpu->fpu[0u] * x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->esp + 0x44u)));
    cpu->fpu[0u] = cpu->fpu[0u] + x87_p2; 
    x87_p1 = (x87_p1) * (((double)g_sfera_view_spatial_runtime.position_offset.z.f32));
    cpu->fpu[0u] = cpu->fpu[0u] + x87_p1; 
    cpu->fpu[0u] = cpu->fpu[0u] * x87_p0; 
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; 
    cpu->fpu[0u] = 0.0;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left<lift_right)) goto label_00057BA0; }
    cpu->fpu[0u] = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); goto label_00057BD6;
    label_00057BA0:
    cpu->fpu[1u] = cpu->fpu[0u]; 
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[1u]);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); label_00057BD6:
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.environment_parameter.f32) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->esp + 0x18u); x87_p0 = cpu->fpu[0u];
    x87_p1 = (double)g_sfera_sky_interpolation_runtime.secondary_key_positions[0];
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (!(lift_left>lift_right)) goto label_00057C1A; }
    x87_p0 = (double)g_sfera_sky_interpolation_runtime.secondary_key_positions[5];
    cpu->eax = 5u;
    cpu->fpu[2u] = cpu->fpu[2u] - x87_p0; 
    cpu->ecx=0u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; 
    cpu->fpu[0u] = cpu->fpu[1u];
    x87_p0 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p1 = x87_p0;
    cpu->fpu[0u] = cpu->fpu[0u] + x87_p1; 
    cpu->fpu[2u] = cpu->fpu[2u] + x87_p0; 
    cpu->fpu[2u] = cpu->fpu[0u] / cpu->fpu[2u]; 
    { double temporary = cpu->fpu[1u]; cpu->fpu[1u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); goto label_00057C8F;
    label_00057C1A:
    x87_p0 = cpu->fpu[1u];
    x87_p1 = (double)g_sfera_sky_interpolation_runtime.secondary_key_positions[5];
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (!(lift_left<lift_right)) goto label_00057C44; }
    x87_p0 = cpu->fpu[2u];
    cpu->eax = 5u;
    x87_p0 = (x87_p0) - (cpu->fpu[0u]);
    cpu->ecx=0u;
    { double temporary = x87_p0; x87_p0 = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[3u] = cpu->fpu[3u] + x87_p0; 
    cpu->fpu[3u] = cpu->fpu[3u] - cpu->fpu[0u]; 
    cpu->fpu[3u] = cpu->fpu[1u] / cpu->fpu[3u]; 
    { double temporary = cpu->fpu[2u]; cpu->fpu[2u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    std::memmove(cpu->fpu, cpu->fpu + 2, 6u * sizeof(double)); goto label_00057C8F;
    label_00057C44:
    cpu->fpu[0u] = cpu->fpu[0u]; 
    cpu->ecx = 1u;
    cpu->fpu[1u] = cpu->fpu[1u]; 
    cpu->fpu[3u] = cpu->fpu[2u]; 
    cpu->fpu[2u] = cpu->fpu[3u];
    std::memmove(cpu->fpu, cpu->fpu + 2, 6u * sizeof(double)); { const double lift_left=(double)g_sfera_sky_interpolation_runtime.secondary_key_positions[1]; const double lift_right=cpu->fpu[0u]; if (!(lift_left<lift_right)) goto label_00057C71; }
    label_00057C60:
    x87_p0 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[1]));
    ++cpu->ecx;
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (lift_left<lift_right) goto label_00057C60; }
    label_00057C71:
    cpu->fpu[0u] = cpu->fpu[0u]; 
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    cpu->fpu[0u] = cpu->fpu[1u];
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0]))));
    x87_p0 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0]));
    x87_p0 = (x87_p0) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0]))));
    cpu->fpu[0u] = cpu->fpu[0u] / x87_p0; 
    label_00057C8F:
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; 
    cpu->ecx <<= 4u;
    cpu->ecx += (uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_samples[0];
    cpu->fpu[0u] = (double)*(float*)(cpu->ecx + 0xCu);
    cpu->eax <<= 4u;
    cpu->eax += ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_samples[0]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xCu)));
    cpu->esp -= 8u;
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu); x87_p1 = x87_p0;
    cpu->fpu[0u] = cpu->fpu[0u] * x87_p1; 
    x87_p1 = (double)*(float*)(cpu->eax + 0xCu);
    cpu->fpu[0u] = cpu->fpu[0u] + x87_p1; 
    { double temporary = x87_p0; x87_p0 = cpu->fpu[0u]; cpu->fpu[0u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esp + 0x20u))) / (255.0));
    x87_p0 = (double)*(float*)(cpu->ecx);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->eax)));
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->eax)));
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xCu); x87_p3 = x87_p2;
    x87_p0 = x87_p0 * x87_p3; 
    { double temporary = x87_p2; x87_p2 = x87_p0; x87_p0 = temporary; }
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->ecx + 4u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + 4u)));
    x87_p1 = (x87_p1) * (cpu->fpu[0u]);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + 4u)));
    *(float*)(cpu->esp + 0x34u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x14u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x14u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->ecx + 8u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + 8u)));
    cpu->fpu[0u] = cpu->fpu[0u] * x87_p1; 
    x87_p1 = (double)*(float*)(cpu->eax + 8u);
    cpu->fpu[0u] = cpu->fpu[0u] + x87_p1; 
    { double temporary = x87_p0; x87_p0 = cpu->fpu[0u]; cpu->fpu[0u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    cpu->fpu[0u] = cpu->fpu[0u] * x87_p1; 
    cpu->fpu[0u] = cpu->fpu[0u] + x87_p0; 
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x);
    *(float*)(cpu->esp) = cpu->fpu[1u]; 
    std::memmove(cpu->fpu, cpu->fpu + 2, 6u * sizeof(double)); lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457D56u)); sfera_sub_0044E400(cpu, LIFT_CODE_TOKEN_VA(0x457D56u));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].x);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u); x87_p1 = x87_p0;
    cpu->fpu[0u] = cpu->fpu[0u] - x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p2 = x87_p1;
    cpu->fpu[0u] = cpu->fpu[0u] * x87_p2; 
    { double temporary = x87_p1; x87_p1 = cpu->fpu[0u]; cpu->fpu[0u] = temporary; }
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].y);
    x87_p1 = (double)*(float*)(cpu->esp + 0xCu); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = cpu->fpu[0u];
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].z);
    x87_p1 = (double)*(float*)(cpu->esp + 8u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = cpu->fpu[0u];
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 8u) = x87_p0; 
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esp + 0x18u))) + (((double)*(float*)(cpu->esp + 0x14u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x2Cu);
    { double temporary = x87_p0; x87_p0 = cpu->fpu[0u]; cpu->fpu[0u] = temporary; }
    x87_p0 = (x87_p0) * (255.0);
    cpu->fpu[0u] = cpu->fpu[0u] + x87_p0; 
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; 
    cpu->fpu[0u] = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::nearbyint(cpu->fpu[0u]));
     cpu->fpu[0u] = (double)*(float*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esp + 0x20u) = static_cast<int64_t>(std::nearbyint(cpu->fpu[0u]));
     cpu->fpu[0u] = (double)*(float*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::nearbyint(cpu->fpu[0u]));
     cpu->fpu[0u] = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x28u) = static_cast<int64_t>(std::nearbyint(cpu->fpu[0u]));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_00057DF6;
    cpu->eax = 0xFFu;
    label_00057DF6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->edx <= (int32_t)0xFFu) goto label_00057E07;
    cpu->edx = 0xFFu;
    label_00057E07:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)cpu->ecx <= (int32_t)0xFFu) goto label_00057E18;
    cpu->ecx = 0xFFu;
    label_00057E18:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->esi <= (int32_t)0xFFu) goto label_00057E2B;
    cpu->esi = 0xFFu;
    label_00057E2B:
    g_sfera_client_main_scalar_runtime.state_01 = cpu->eax;
    cpu->eax&=0xFFu;
    cpu->eax <<= 8u;
    g_sfera_main_aux_runtime.color_component = cpu->edx;
    cpu->edi = 0xFFu;
    cpu->edi -= cpu->esi;
    cpu->edx &= 0xFFu;
    cpu->eax|=cpu->edx;
    g_sfera_recovered_static_runtime.animation_result_b = cpu->ecx;
    g_sfera_render_lookup_runtime.alpha_component = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax <<= 8u;
    cpu->ecx &= 0xFFu;
    cpu->eax |= cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_recovered_static_runtime.render_state_09 = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

} // namespace lifted
