#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_0044DE30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetVertexShader(SferaAbi::pointer<IDirect3DVertexShader9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))), "SetVertexShader")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetPixelShader(SferaAbi::pointer<IDirect3DPixelShader9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))), "SetPixelShader")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0x89u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x1C4u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetFVF(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), "SetFVF")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, 0u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setColorOperation(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<D3DTEXTUREOP>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)); cpu->esp += 16u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, 0u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaOperation(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<D3DTEXTUREOP>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)); cpu->esp += 16u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 3u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetSamplerState(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<D3DSAMPLERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), "SetSamplerState")); cpu->esp += 12u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetSamplerState(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<D3DSAMPLERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), "SetSamplerState")); cpu->esp += 12u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0044DF90(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    goto label_0004DF90;
    label_0004DF00:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetSamplerState(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<D3DSAMPLERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), "SetSamplerState")); cpu->esp += 12u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetSamplerState(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<D3DSAMPLERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), "SetSamplerState")); cpu->esp += 12u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x89u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 7u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 2u); lift_push32(cpu, 0x16u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004DF90:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DF96u)); sfera_sub_0044DE30(cpu, LIFT_CODE_TOKEN_VA(0x44DF96u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    g_sfera_interface.draw();
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    if (cpu->ecx == 0u) goto label_0004DFC8;
    ([&] { auto* contours = SferaAbi::pointer<Contours>(cpu->ecx); const auto window_id = contours->editorWindowId(); std::int32_t origin_x = 0, origin_y = 0; if (window_id >= 0) { const auto* slot = g_sfera_interface_runtime.windows.element<std::uint32_t>(static_cast<std::size_t>(window_id)); if (slot == nullptr || *slot == 0u) throw std::out_of_range("Contours: invalid editor window"); origin_x = static_cast<std::int32_t>(*SferaAbi::pointer<const float>(*slot + 0x34u)); origin_y = static_cast<std::int32_t>(*SferaAbi::pointer<const float>(*slot + 0x38u)); } contours->drawEditor(origin_x, origin_y); }());
    label_0004DFC8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DFCDu)); sfera_sub_0044D700(cpu, LIFT_CODE_TOKEN_VA(0x44DFCDu));
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->eax -= g_sfera_frame_runtime.frame_anchor.low;
    ++g_sfera_frame_runtime.frame_sample_count;
    *(uint32_t*)(cpu->esp) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)0x3E8u) goto label_0004E017;
    x87_v0 = (double)(((int32_t)(g_sfera_frame_runtime.frame_sample_count)));
    g_sfera_frame_runtime.frame_sample_count = 0u;
    x87_v0 = (x87_v0) * (10000.0);
    x87_v0 = (x87_v0) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp)))));
    *(float*)((uintptr_t)&g_sfera_input_device_runtime.frame_interval.f32) = x87_v0; 
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    g_sfera_frame_runtime.frame_anchor.low = cpu->eax;
    g_sfera_frame_runtime.frame_anchor.high = cpu->edx;
    label_0004E017:
    cpu->esp += 4u;
    goto label_0004DF00;
}
__declspec(noinline) void sfera_sub_0044E020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->sync_query);
    if (cpu->eax == 0u) goto label_0004E08E;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E031u));
    if (cpu->eax == 0x88760868u) goto label_0004E08E;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->sync_query);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E04Bu));
    if (cpu->eax != 1u) goto label_0004E08E;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->sync_query);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E063u));
    if (cpu->eax != 1u) goto label_0004E08E;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::Sleep);
    label_0004E071:

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0u);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->sync_query);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x4E086u));
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

__declspec(noinline) double sfera_sub_0044E400(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8;
 double x87_p0, x87_p1;
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
     value_6 = x87_p1; value_7 = x87_p0; if (!((value_6)<(value_7))) goto label_0004E428;
    *(float*)(cpu->esp + 4u) = value_7; 
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 4u))) * (((double)*(float*)(cpu->esp + 8u))));
    value_8 = (double)*(float*)(cpu->esp + 4u);
     cpu->esp += 0xCu; cpu->eip = stop_address; return value_8;
label_0004E428:
    value_0 = 0.4000000059604645;
    if (!((value_0)<(value_6))) goto label_0004E456;
    *(float*)(cpu->esp + 4u) = (double)(1.0);
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 4u))) * (((double)*(float*)(cpu->esp + 8u))));
    value_1 = (double)*(float*)(cpu->esp + 4u);
     cpu->esp += 0xCu; cpu->eip = stop_address; return value_1;
label_0004E456:
    x87_p0 = 0.0;
    value_2 = (value_6) - (x87_p0);
    value_3 = value_0 - x87_p0; 
    value_4 = value_2 / value_3; 
    *(float*)(cpu->esp + 4u) = value_4; 
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 4u))) * (((double)*(float*)(cpu->esp + 8u))));
    value_5 = (double)*(float*)(cpu->esp + 4u);
     cpu->esp += 0xCu; cpu->eip = stop_address; return value_5;
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
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    cpu->ebx += 0xCu;
    cpu->edi += 0xCu;
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_0004E790;
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    cpu->eax = static_cast<std::uint32_t>((static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) <= 0 ? 0 : SferaAbi::pointer<const SferaFrustumF>(cpu->ecx)->classifyPoints(std::span<const SferaVec3F>(SferaAbi::pointer<const SferaVec3F>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
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
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0].bounds_max.y;
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
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[cpu->eax].bounds_max.y;
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
    ++cpu->esi;
    cpu->eax = 0xE7Fu;
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esp + 0x34u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x34u));
    g_sfera_static_render_lookup_runtime.color_remap_a[cpu->esi - 1u] = cpu->eax & 0xFFu;
    g_sfera_static_render_lookup_runtime.color_remap_b[cpu->esi - 1u] = cpu->eax & 0xFFu;
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
    cpu->esi = cpu->ecx;
    if ((((*(uint8_t*)(void*)&g_sfera_frame_runtime.color_lookup_flags)) & (1u)) != 0u) goto label_0004ECEE;
    g_sfera_frame_runtime.color_lookup_flags = (uint64_t)(g_sfera_frame_runtime.color_lookup_flags) | (uint64_t)(1u);
    cpu->ecx = (uintptr_t)&g_sfera_frame_runtime.color_lookup_object;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->eax = SferaAbi::address(SferaAbi::pointer<GrassMapMngr>(cpu->ecx)->reset());
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    label_0004ECEE:
    if (cpu->esi == 0u) goto label_0004ED56;
    if (g_sfera_view_spatial_runtime.alternate_projection == 1u) goto label_0004ED56;
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->ecx = (uintptr_t)&g_sfera_frame_runtime.color_lookup_object;
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x6496C8FFu;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<GrassMapMngr>(cpu->ecx)->plantingType(*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u)));  cpu->esp += 8u;
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
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0004ED56:
    cpu->eax = 0xFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
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
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetMaterial(SferaAbi::pointer<const D3DMATERIAL9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))), "SetMaterial")); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(SphereRender::Material::randomColor(*SferaAbi::pointer<const std::array<float, 3>>(cpu->ecx)));
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
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x4F64Cu));
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
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x4F6F8u));
    lift_push32(cpu, (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0]); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x4F700u));
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

__declspec(noinline) void sfera_sub_0044FC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x44u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x4FC83u));
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
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(cpu->ecx));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(cpu->ecx)); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->esi != 0xFFu) goto label_0004FD22;
    if (cpu->eax == cpu->edi) goto label_0004FD31;
    label_0004FD22:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
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
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x1C4u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetFVF(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), "SetFVF")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 0xEu); lift_push32(cpu, 6u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->drawVertices(static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), SferaAbi::pointer<const std::uint16_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)); cpu->esp += 28u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
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
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->esi != 0xFFu) goto label_0004FFD2;
    if (cpu->eax == cpu->edi) goto label_0004FFE1;
    label_0004FFD2:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
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
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x1C4u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetFVF(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), "SetFVF")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x20u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->DrawPrimitiveUP(static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)), "DrawPrimitiveUP")); cpu->esp += 16u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
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
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices28.buffer.get());
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->eax)->native_buffer) == cpu->ebx) goto label_000509E0;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.buffer.get());
    if (SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->ecx)->native_buffer) == cpu->ebx) goto label_000509E0;
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
    cpu->ecx = g_sfera_graphics_runtime.d3d_runtime->vertices28.capacity;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_00050365;
    cpu->ecx = 0x7530u;
    label_00050365:
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices28.lock(static_cast<std::int32_t>(cpu->ecx)));
    x87_v0 = 0.0;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
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
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
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
    cpu->ecx = g_sfera_graphics_runtime.d3d_runtime->vertices28.capacity;
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
    cpu->edx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices28.buffer.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->edx)->native_buffer);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "VertexBuffer::Unlock")); cpu->esp += 4u;
    cpu->eax = g_sfera_graphics_runtime.d3d_runtime->vertices28.position;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax += g_sfera_graphics_runtime.d3d_runtime->vertices28.capacity;
    (g_sfera_graphics_runtime.d3d_runtime->vertices28.position) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax <= 0) goto label_00050808;
    cpu->esi = cpu->ebp + 4u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    label_00050733:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esp + 0x30u) == cpu->eax) goto label_00050757;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0005074E;
    lift_push32(cpu, 6u);
    goto label_00050750;
    label_0005074E:
    lift_push32(cpu, 2u);
    label_00050750:
    lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    label_00050757:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->eax) goto label_0005078B;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0005078B;
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->ebp;
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(cpu->ecx));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->ebp;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(cpu->ecx));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    label_0005078B:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->ecx <= 0) goto label_000507FB;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.lock(static_cast<std::int32_t>(cpu->ecx)));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + (cpu->edx * 2u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4507A3u));
    cpu->edx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.buffer.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->edx)->native_buffer);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "IndexBuffer::Unlock")); cpu->esp += 4u;
    cpu->ecx = g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.buffer.get());
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->eax)->native_buffer);
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices28.buffer.get());
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->eax)->native_buffer);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 4u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->drawBuffer(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 32u)); cpu->esp += 36u;
    cpu->edx = *(uint32_t*)(cpu->esi);
    g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position = (uint64_t)((g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
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
    cpu->ecx = g_sfera_graphics_runtime.d3d_runtime->vertices28.capacity;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices28.lock(static_cast<std::int32_t>(cpu->ecx)));
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
    cpu->edx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices28.buffer.get());
    cpu->eax = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->edx)->native_buffer);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "VertexBuffer::Unlock")); cpu->esp += 4u;
    cpu->eax = g_sfera_graphics_runtime.d3d_runtime->vertices28.position;
    cpu->ebp = cpu->eax;
    cpu->eax += g_sfera_graphics_runtime.d3d_runtime->vertices28.capacity;
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x1Cu) == 0u; sub_pred[4] = (int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) < (int32_t)(0u);
    (g_sfera_graphics_runtime.d3d_runtime->vertices28.position) = cpu->eax;
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0005090B;
    lift_push32(cpu, 6u);
    goto label_0005090D;
    label_0005090B:
    lift_push32(cpu, 2u);
    label_0005090D:
    lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    label_00050914:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->eax) goto label_00050944;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00050944;
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->edi;
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(cpu->ecx));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(cpu->ecx));
    label_00050944:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->ecx <= 0) goto label_000509B9;
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.lock(static_cast<std::int32_t>(cpu->ecx)));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->edx = cpu->ecx + (cpu->edx * 2u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x450960u));
    cpu->eax = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.buffer.get());
    cpu->ecx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->eax)->native_buffer);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->Unlock(), "IndexBuffer::Unlock")); cpu->esp += 4u;
    cpu->edx = g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->indices_secondary.buffer.get());
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->edx);
    cpu->edx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceIB>(cpu->ecx)->native_buffer);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime->vertices28.buffer.get());
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = SferaAbi::address(SferaAbi::pointer<UnmanagedResourceVB>(cpu->ecx)->native_buffer);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->drawBuffer(SferaAbi::pointer<IDirect3DVertexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), SferaAbi::pointer<IDirect3DIndexBuffer9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 32u)); cpu->esp += 36u;
    cpu->eax = *(uint32_t*)(cpu->esi);
    g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position = (uint64_t)((g_sfera_graphics_runtime.d3d_runtime->indices_secondary.position)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000509B9:
    cpu->esi += 0x10u;
    if ((--cpu->ebx) != 0u) goto label_000508F0;
    label_000509C3:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000509E0:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xF4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00450A00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].x);
    *(uint64_t*)(cpu->esp + 4u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].y);
    *(uint64_t*)(cpu->esp + 4u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx &= 0xFFu;
    cpu->ecx|=cpu->edx;
    cpu->ecx <<= 8u;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[2].z);
    *(uint64_t*)(cpu->esp + 4u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax &= 0xFFu;
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x8Bu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}






__declspec(noinline) void sfera_sub_00451570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->edx + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    cpu->esp += 8u; cpu->eip = stop_address; return;
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
    g_sfera_interface.showLoadingScreen((cpu->ecx & 255u) != 0u, static_cast<std::int32_t>(cpu->edx), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), (*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) & 255u) != 0u); cpu->esp += 8u;
    lift_push32(cpu, 0x180u); lift_push32(cpu, (uintptr_t)"loadcount.bin");
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x4518B0u));
    cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"loadcount.bin";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.create(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uintptr_t)&g_sfera_main_view_state_runtime.view_accumulator;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<const void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
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
__declspec(noinline) double sfera_sub_004519D0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
 double x87_p0, x87_p1;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    x87_p1 = 40.74365997314453;
    x87_p0 = (x87_p0) * (x87_p1);
    std::swap(x87_p1, x87_p0);
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
     value_0 = x87_p0; cpu->esp += 0xCu; cpu->eip = stop_address; return value_0;
}
__declspec(noinline) void sfera_sub_00451A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx & 0xFFu;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03) = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    x87_v0 = x87_v0; 
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
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
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    label_00054B55:
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))) >> 32u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0x65u);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, (uintptr_t)&g_sfera_sky_runtime.indices[0]);
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->DrawIndexedPrimitiveUP(static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u)), static_cast<D3DFORMAT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u)), "DrawIndexedPrimitiveUP")); cpu->esp += 32u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
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
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 3u); lift_push32(cpu, 1u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Du);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = cpu->edi;
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(cpu->ebx))) >> 32u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0x65u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, (uintptr_t)&g_sfera_sky_runtime.indices[0]);
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->DrawIndexedPrimitiveUP(static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u)), static_cast<D3DFORMAT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u)), "DrawIndexedPrimitiveUP")); cpu->esp += 32u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE)); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    *SferaAbi::pointer<SferaQuaternionF>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = SferaAbi::pointer<const SferaQuaternionF>(cpu->ecx)->interpolated(*SferaAbi::pointer<const SferaQuaternionF>(cpu->edx), *SferaAbi::pointer<const float>(cpu->esp + 4u)); cpu->esp += 8u;
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
    *SferaAbi::pointer<SferaQuaternionF>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = SferaAbi::pointer<const SferaQuaternionF>(cpu->ecx)->interpolated(*SferaAbi::pointer<const SferaQuaternionF>(cpu->edx), *SferaAbi::pointer<const float>(cpu->esp + 4u)); cpu->esp += 8u;
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
    *SferaAbi::pointer<SferaQuaternionF>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = SferaAbi::pointer<const SferaQuaternionF>(cpu->ecx)->interpolated(*SferaAbi::pointer<const SferaQuaternionF>(cpu->edx), *SferaAbi::pointer<const float>(cpu->esp + 4u)); cpu->esp += 8u;
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
    *SferaAbi::pointer<SferaMatrix3x3F>(cpu->edx) = SferaAbi::pointer<const SferaQuaternionF>(cpu->ecx)->rotationMatrix();
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
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(cpu->ecx); *destination = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->edx)->multiplied(*destination); cpu->eax = cpu->ecx; };
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
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
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
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    {
        const auto* model = SferaAbi::pointer<const SphereRender::Model>(cpu->eax);
        sub_pred[0] = false;
        for (std::uint32_t materialIndex = 0; model != nullptr && materialIndex < model->material_count; ++materialIndex) {
            const auto* material = g_sfera_materials.at(model->material_indices[materialIndex]);
            if (material == nullptr) throw std::out_of_range("Model material index");
            if (::_stricmp(material->name.c_str(), "default") == 0) continue;
            sub_pred[0] = static_cast<std::int32_t>(cpu->ebp) < static_cast<std::int32_t>(material->textures.size());
            break;
        }
    }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004570A0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10;
 double x87_p0, x87_p1, x87_p2;
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
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (!(((double)5.0f)>(((double)*(float*)(cpu->eax + 0x194u))))) goto label_00057100;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45711Eu)); value_8 = sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x45711Eu));
    if ((value_8)<=(((double)0.15707965195178986f))) goto label_000570F2;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    x87_p1 = x87_p0;
    x87_p2 = 0.15707965195178986;
    x87_p1 = (x87_p1) + (x87_p2);
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0xCu) = x87_p2; 
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45715Cu)); value_9 = sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x45715Cu));
    *(float*)(cpu->esp + 0xCu) = value_9; 
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x10u);
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457177u)); value_10 = sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x457177u));
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu);
     value_1 = x87_p0; if (!((value_1)<(value_10))) goto label_000571B3;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    x87_p1 = 6.283185958862305;
     value_2 = x87_p1; value_3 = x87_p0; if (!((value_2)<(value_3))) goto label_000571E4;
    value_4 = value_3 - value_2; 
    *(float*)(cpu->esp + 4u) = value_4; 
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
     cpu->esp += 8u; cpu->eip = stop_address; return;
label_000571B3:
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
     value_5 = x87_p1; value_6 = x87_p0; { const double lift_left=value_5; const double lift_right=value_6;   if (!(lift_left<lift_right)) { value_0 = value_5; goto label_000571E6; } }
    value_7 = (value_5) + (6.283185958862305);
    *(float*)(cpu->esp + 4u) = value_7; 
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
     cpu->esp += 8u; cpu->eip = stop_address; return;
label_000571E4:
      value_0 = value_3;
label_000571E6:
    *(float*)(cpu->esi + 0x14u) = value_0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
     cpu->esp += 8u; cpu->eip = stop_address; return;
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
    WorldGuiControls::destroyText(cpu->ecx);
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
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::Vegetation::alternatePatterns());
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_0005772C;
    cpu->ecx = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_main_aux_runtime.secondary_world_manager;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4576F0u)); sfera_sub_00495360(cpu, LIFT_CODE_TOKEN_VA(0x4576F0u));
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::Vegetation::alternatePatterns());
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
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::Vegetation::alternatePatterns());
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
__declspec(noinline) void sfera_sub_00457840(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26, value_27, value_28, value_29, value_30, value_31, value_32, value_33, value_34, value_35, value_36, value_37, value_38, value_39, value_40, value_41, value_42, value_43, value_44, value_45, value_46, value_47, value_48, value_49, value_50, value_51, value_52, value_53, value_54, value_55, value_56, value_57, value_58, value_59, value_60, value_61, value_62, value_63, value_64, value_65, value_66, value_67, value_68, value_69, value_70, value_71, value_72, value_73, value_74, value_75, value_76, value_77, value_78, value_79, value_80, value_81, value_82, value_83, value_84, value_85, value_86, value_87, value_88, value_89, value_90, value_91, value_92, value_93, value_94, value_95, value_96, value_97, value_98, value_99, value_100, value_101, value_102, value_103, value_104, value_105, value_106, value_107, value_108, value_109, value_110, value_111;
 bool sub_pred[1]; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5;
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
     value_88 = x87_p1; value_89 = x87_p0; { const double lift_left=value_88; const double lift_right=value_89;   if (!(lift_left<lift_right)) { value_4 = value_88; goto label_00057958; } }
    value_90 = (value_88) + (6.283185958862305);
    *(float*)(cpu->esp + 4u) = value_90; 
    value_91 = (double)*(float*)(cpu->esp + 4u); value_4 = value_91;
label_00057958:
    value_92 = (value_4) * (0.15915492658458097);
    *(float*)(cpu->esp + 4u) = value_92; 
     if ((cpu->ebx & 0xFFu) == 0u) goto label_0005798F;
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::Vegetation::alternatePatterns());
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
     value_93 = x87_p2; value_94 = x87_p1; value_95 = x87_p0; if (!lift_cmp[0]) goto label_000579C5;
    value_96 = (value_93) - (((double)g_sfera_sky_interpolation_runtime.primary_key_positions[9]));
    cpu->eax = 9u;
    cpu->ecx=0u;
    *(float*)(cpu->esp + 0x14u) = value_96; 
    value_97 = (double)*(float*)(cpu->esp + 0x14u); x87_p0 = value_97;
    value_98 = value_95 + x87_p0; 
    value_99 = value_94 + value_97; 
     value_0 = value_99; value_1 = value_98; goto label_00057A32;
label_000579C5:
    x87_p0 = value_95;
    x87_p1 = (double)g_sfera_sky_interpolation_runtime.primary_key_positions[9];
     value_100 = x87_p1; value_101 = x87_p0; if (!((value_100)<(value_101))) goto label_000579EB;
    x87_p0 = value_100;
    cpu->eax = 9u;
    value_102 = value_95 - x87_p0; 
    cpu->ecx=0u;
    value_103 = value_93 + value_94; 
    value_104 = value_103 - value_100; 
     value_0 = value_104; value_1 = value_102; goto label_00057A32;
label_000579EB:
    cpu->ecx = 1u;
     if (!(((double)g_sfera_sky_interpolation_runtime.primary_key_positions[1])<(value_95))) goto label_00057A18;
label_00057A07:
    x87_p0 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[1]));
    ++cpu->ecx;
     value_5 = x87_p0; if ((value_5)<(value_95)) goto label_00057A07;
label_00057A18:
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    value_6 = (value_95) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0]))));
    value_7 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0]));
    value_8 = (value_7) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_key_positions[0])))); value_0 = value_8; value_1 = value_6;
label_00057A32:
    value_9 = value_1 / value_0; 
    cpu->ecx <<= 4u;
    cpu->ecx += (uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0];
    cpu->eax <<= 4u;
    cpu->eax += ((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_samples[0]);
    *(float*)(cpu->esp + 4u) = value_9; 
    value_10 = (double)*(float*)(cpu->ecx);
    value_11 = (value_10) - (((double)*(float*)(cpu->eax)));
    value_12 = (double)*(float*)(cpu->esp + 4u); x87_p0 = value_12;
    value_13 = value_11 * x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax);
    value_14 = value_13 + x87_p0; 
    *(float*)(cpu->esp + 0x10u) = value_14; 
    value_15 = (double)*(float*)(cpu->ecx + 4u);
    value_16 = (value_15) - (((double)*(float*)(cpu->eax + 4u)));
    value_17 = (value_16) * (value_12);
    value_18 = (value_17) + (((double)*(float*)(cpu->eax + 4u)));
    *(float*)(cpu->esp + 0xCu) = value_18; 
    value_19 = (double)*(float*)(cpu->ecx + 8u);
    value_20 = (value_19) - (((double)*(float*)(cpu->eax + 8u)));
    value_21 = (value_20) * (value_12);
    value_22 = (value_21) + (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->esp + 8u) = value_22; 
    value_23 = (double)*(float*)(cpu->ecx + 0xCu);
    value_24 = (value_23) - (((double)*(float*)(cpu->eax + 0xCu)));
    value_25 = value_12 * value_24; 
    value_26 = (value_25) + (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x14u) = value_26; 
    value_27 = (double)*(float*)(cpu->esp + 0x48u);
    value_28 = (double)*(float*)(cpu->esp + 0x44u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x4Cu);
    x87_p1 = value_28;
    value_29 = value_28 * x87_p1; 
    x87_p1 = value_27;
    value_30 = value_27 * x87_p1; 
    value_105 = x87_p0; x87_p0 = value_29;
    value_31 = value_30 + x87_p0; 
    value_32 = (value_105) * (value_105);
    value_33 = value_31 + value_32; 
    *(float*)(cpu->esp + 4u) = value_33; 
    value_34 = (double)*(float*)(cpu->esp + 4u);
    value_35 = std::sqrt(value_34);
    *(float*)(cpu->esp + 4u) = value_35; 
    value_36 = (double)*(float*)(cpu->esp + 4u);
    value_37 = 1.0;
    x87_p0 = value_37;
    value_38 = x87_p0 / value_36; 
    *(float*)(cpu->esp + 0x2Cu) = value_38; 
    value_39 = (double)*(float*)(cpu->esp + 0x48u);
    x87_p0 = -0.30000001192092896;
    x87_p0 = (x87_p0) * (value_39);
    x87_p1 = (double)*(float*)(cpu->esp + 0x4Cu); x87_p2 = x87_p1;
    x87_p2 = fabs(x87_p2);
    *(float*)(cpu->esp + 4u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 4u);
    x87_p2 = (x87_p2) * (0.9539999961853027);
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p3 = x87_p2;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 4u);
    x87_p2 = (x87_p2) * (x87_p2);
    *(float*)(cpu->esp + 4u) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_sky_interpolation_runtime.primary_reference.x);
    x87_p3 = (double)*(float*)(cpu->esp + 0x10u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 4u); x87_p5 = x87_p4;
    x87_p2 = x87_p2 * x87_p5; 
    std::swap(x87_p4, x87_p2);
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
    std::swap(x87_p4, x87_p3);
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x14u) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    value_40 = value_39 * x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->esp + 0x44u)));
    value_41 = value_40 + x87_p2; 
    x87_p1 = (x87_p1) * (((double)g_sfera_view_spatial_runtime.position_offset.z.f32));
    value_42 = value_41 + x87_p1; 
    value_43 = value_42 * x87_p0; 
    *(float*)(cpu->esp + 4u) = value_43; 
    value_44 = 0.0;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
     value_45 = x87_p0; if (!((value_45)<(value_44))) goto label_00057BA0;
     value_2 = value_44; goto label_00057BD6;
label_00057BA0:
    value_46 = (value_45) * (value_45);
    *(float*)(cpu->esp + 4u) = value_46; 
    value_47 = (double)*(float*)(cpu->esp + 4u);
    value_48 = (value_47) * (value_47);
    *(float*)(cpu->esp + 4u) = value_48; 
    value_49 = (double)*(float*)(cpu->esp + 4u);
    value_50 = (value_49) * (value_49);
    *(float*)(cpu->esp + 4u) = value_50; 
    value_51 = (double)*(float*)(cpu->esp + 4u);
    value_52 = (value_51) * (value_51);
    *(float*)(cpu->esp + 4u) = value_52; 
    value_53 = (double)*(float*)(cpu->esp + 4u);
    value_54 = (value_53) * (value_53);
    *(float*)(cpu->esp + 4u) = value_54; 
    value_55 = (double)*(float*)(cpu->esp + 4u);
    value_56 = (value_55) * (value_55);
      value_2 = value_56;
label_00057BD6:
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.environment_parameter.f32) = value_2; 
    value_57 = (double)*(float*)(cpu->esp + 0x18u); x87_p0 = value_57;
    x87_p1 = (double)g_sfera_sky_interpolation_runtime.secondary_key_positions[0];
     value_58 = x87_p1; value_59 = x87_p0; if (!((value_58)>(value_59))) goto label_00057C1A;
    x87_p0 = (double)g_sfera_sky_interpolation_runtime.secondary_key_positions[5];
    cpu->eax = 5u;
    value_60 = value_37 - x87_p0; 
    cpu->ecx=0u;
    *(float*)(cpu->esp + 0x2Cu) = value_60; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p1 = x87_p0;
    value_61 = value_57 + x87_p1; 
    value_62 = value_58 + x87_p0; 
    value_63 = value_61 / value_62; 
     value_3 = value_63; goto label_00057C8F;
label_00057C1A:
    x87_p0 = value_57;
    x87_p1 = (double)g_sfera_sky_interpolation_runtime.secondary_key_positions[5];
     value_64 = x87_p1; value_65 = x87_p0; if (!((value_64)<(value_65))) goto label_00057C44;
    x87_p0 = value_57;
    cpu->eax = 5u;
    x87_p0 = (x87_p0) - (value_64);
    cpu->ecx=0u;
    value_106 = x87_p0; x87_p0 = value_58;
    value_66 = value_37 + x87_p0; 
    value_67 = value_66 - value_64; 
    value_68 = value_106 / value_67; 
     value_3 = value_68; goto label_00057C8F;
label_00057C44:
    cpu->ecx = 1u;
     if (!(((double)g_sfera_sky_interpolation_runtime.secondary_key_positions[1])<(value_57))) goto label_00057C71;
label_00057C60:
    x87_p0 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[1]));
    ++cpu->ecx;
     value_69 = x87_p0; if ((value_69)<(value_57)) goto label_00057C60;
label_00057C71:
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    value_70 = (value_57) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0]))));
    x87_p0 = (double)*(float*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0]));
    x87_p0 = (x87_p0) - (((double)*(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_key_positions[0]))));
    value_71 = value_70 / x87_p0;  value_3 = value_71;
label_00057C8F:
    *(float*)(cpu->esp + 4u) = value_3; 
    cpu->ecx <<= 4u;
    cpu->ecx += (uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_samples[0];
    value_72 = (double)*(float*)(cpu->ecx + 0xCu);
    cpu->eax <<= 4u;
    cpu->eax += ((uintptr_t)&g_sfera_sky_interpolation_runtime.secondary_samples[0]);
    value_73 = (value_72) - (((double)*(float*)(cpu->eax + 0xCu)));
    cpu->esp -= 8u;
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu); x87_p1 = x87_p0;
    value_74 = value_73 * x87_p1; 
    x87_p1 = (double)*(float*)(cpu->eax + 0xCu);
    value_75 = value_74 + x87_p1; 
    value_107 = x87_p0; x87_p0 = value_75;
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esp + 0x20u))) / (255.0));
    x87_p0 = (double)*(float*)(cpu->ecx);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->eax)));
    x87_p0 = (x87_p0) * (value_107);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->eax)));
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xCu); x87_p3 = x87_p2;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p0);
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->ecx + 4u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + 4u)));
    x87_p1 = (x87_p1) * (value_107);
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
    value_76 = value_107 * x87_p1; 
    x87_p1 = (double)*(float*)(cpu->eax + 8u);
    value_77 = value_76 + x87_p1; 
    value_108 = x87_p0; x87_p0 = value_77;
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    std::swap(x87_p1, x87_p0);
    value_78 = value_108 * x87_p1; 
    value_79 = value_78 + x87_p0; 
    *(float*)(cpu->esp + 0x10u) = value_79; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x);
    *(float*)(cpu->esp) = value_57; 
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457D56u)); value_111 = sfera_sub_0044E400(cpu, LIFT_CODE_TOKEN_VA(0x457D56u));
    *(float*)(cpu->esp + 0x2Cu) = value_111; 
    value_80 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].x);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u); x87_p1 = x87_p0;
    value_81 = value_80 - x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p2 = x87_p1;
    value_82 = value_81 * x87_p2; 
    value_109 = x87_p1; x87_p1 = value_82;
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].y);
    x87_p1 = (double)*(float*)(cpu->esp + 0xCu); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = value_109;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].z);
    x87_p1 = (double)*(float*)(cpu->esp + 8u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = value_109;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 8u) = x87_p0; 
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esp + 0x18u))) + (((double)*(float*)(cpu->esp + 0x14u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x2Cu);
    value_110 = x87_p0; x87_p0 = value_109;
    x87_p0 = (x87_p0) * (255.0);
    value_83 = value_110 + x87_p0; 
    *(float*)(cpu->esp + 0x14u) = value_83; 
    value_84 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::nearbyint(value_84));
     value_85 = (double)*(float*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esp + 0x20u) = static_cast<int64_t>(std::nearbyint(value_85));
     value_86 = (double)*(float*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::nearbyint(value_86));
     value_87 = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x28u) = static_cast<int64_t>(std::nearbyint(value_87));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
     if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_00057DF6;
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
