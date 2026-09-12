#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_0041C5B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = cpu->ecx;
    cpu->eax = cpu->ebp + 0xFFFFFFBCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x14u;
    cpu->ecx = cpu->esi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA0u) = cpu->ebx;
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); *destination = SferaMatrix4x4F::fromEuler(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->edx)); cpu->eax = SferaAbi::address(destination); }; cpu->esp += 4u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x144u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edx + 0x4F40u);
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + (cpu->ecx * 4u) + 0xA8u);
    cpu->ebx = cpu->ebx + (cpu->ecx * 4u) + 0xA8u;
    cpu->eax <<= 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C613u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x41C613u));
    x87_v0 = (double)*(float*)(cpu->esi + 0x178u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x17Cu);
    cpu->eax = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x174u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x170u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF9Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x180u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C64Au)); sfera_sub_0041C220(cpu, LIFT_CODE_TOKEN_VA(0x41C64Au));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFF9Cu);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x38u);
    cpu->eax <<= 6u;
    cpu->esi = cpu->eax + cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41C65Eu));
    *(float*)(cpu->ebp + 0xFFFFFFA4u) = (double)*(float*)(cpu->esi + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFA4u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB0u) = cpu->eax;
    *(float*)(cpu->ebp + 0xFFFFFFA8u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x38u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB4u) = cpu->ecx;
    *(float*)(cpu->ebp + 0xFFFFFFACu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFACu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u) = cpu->edx;
    cpu->edx = cpu->ebp + 0xFFFFFFB0u;
    cpu->ecx = cpu->ebp + 0xFFFFFFBCu;
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFB0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFB4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->edx;
    cpu->eax = cpu->edi;
    cpu->esp = cpu->ebp + 0xFFFFFF90u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) double sfera_sub_0041C6C0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5;
 bool sub_pred[6]; double x87_p0, x87_p1, x87_p2, x87_p3;
    cpu->esp -= 8u;
    sub_pred[0] = (uint32_t)(g_sfera_world_objects.object_handles.capacity) == 1u; sub_pred[3] = (int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) < (int32_t)(1u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((!sub_pred[0]) && (!sub_pred[3])) goto label_0001C6DF;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C6DFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1C6DFu));
label_0001C6DF:
    sub_pred[1] = (uint32_t)(g_sfera_world_objects.object_handles.capacity) == 1u; sub_pred[4] = (int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) < (int32_t)(1u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    x87_p0 = (double)*(float*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->ecx + 8u)));
    *(float*)(cpu->esp + 8u) = x87_p0; 
    if ((!sub_pred[1]) && (!sub_pred[4])) goto label_0001C70D;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C70Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1C70Du));
label_0001C70D:
    sub_pred[2] = (uint32_t)(g_sfera_world_objects.object_handles.capacity) == 1u; sub_pred[5] = (int32_t)((uint32_t)(g_sfera_world_objects.object_handles.capacity)) < (int32_t)(1u);
    x87_p0 = (double)*(float*)(cpu->esi + 0xCu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    if ((!sub_pred[2]) && (!sub_pred[5])) goto label_0001C738;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C738u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1C738u));
label_0001C738:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    x87_p0 = (double)*(float*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->edx + 0x10u)));
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p1 = (double)*(float*)(cpu->esp + 8u);
    x87_p2 = (double)*(float*)(cpu->esp + 0xCu);
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->edi + 0x7534u)));
    x87_p1 = (double)*(float*)(cpu->edi + 0x7538u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->edi + 0x7534u)));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    x87_p0 = x87_p0 / x87_p1; 
    x87_p1 = 1.0;
    x87_p2 = 0.0;
    x87_p2 = (x87_p1) - (x87_p2);
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p1 - x87_p0; 
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 0xCu);
     value_1 = x87_p1; value_2 = x87_p0; if (!((value_1)<(value_2))) goto label_0001C7BF;
    *(float*)(cpu->esp + 0xCu) = value_2; 
    value_3 = (double)*(float*)(cpu->esp + 0xCu);
     value_0 = value_3; goto label_0001C7C1;
label_0001C7BF:
      value_0 = value_1;
label_0001C7C1:
    x87_p0 = 1.0;
     value_4 = x87_p0; if (!((value_4)<(value_0))) goto label_0001C7DC;
    *(float*)(cpu->esp + 0xCu) = value_4; 
    value_5 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->esp += 8u;
     cpu->esp += 8u; cpu->eip = stop_address; return value_5;
label_0001C7DC:
    cpu->esp += 8u;
     cpu->esp += 8u; cpu->eip = stop_address; return value_0;
}
__declspec(noinline) void sfera_sub_0041C7F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp + 0xFFFFFF8Cu;
    cpu->esp -= 0x9Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x7Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ebx >= 0) goto label_0001C81B;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C81Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x1C81Bu));
    label_0001C81B:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0001C82F;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C82Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1C82Fu));
    label_0001C82F:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    lift_push32(cpu, 0x47Du);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C846u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x41C846u));
    cpu->edi = cpu->eax;
    if (*(uint8_t*)(cpu->edi + 0x141u) == 0u) goto label_0001CC77;
    cpu->ecx = cpu->ebp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x14u;
    cpu->ecx = cpu->edi + 8u;
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); *destination = SferaMatrix4x4F::fromEuler(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->edx)); cpu->eax = SferaAbi::address(destination); }; cpu->esp += 4u;
    cpu->edx = cpu->ebp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C86Fu)); sfera_sub_0041B5B0(cpu, LIFT_CODE_TOKEN_VA(0x41C86Fu));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0001CC77;
    x87_v0 = (double)*(float*)(cpu->ebp + 0x30u);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->ebp + 0xFFFFFFF0u) = x87_v0; 
    cpu->eax = cpu->ebp + 0xFFFFFFF0u;
    x87_v0 = (double)*(float*)(cpu->ebp + 0x40u);
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->ebp + 0xFFFFFFF4u) = x87_v0; 
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->ebp + 0xFFFFFFF8u) = (double)*(float*)(cpu->ebp + 0x50u);
    *(float*)(cpu->ebp + 0xFFFFFFFCu) = (double)*(float*)(cpu->ebp + 0x60u);
    *(float*)(cpu->ebp) = (double)*(float*)(cpu->ebp + 0x34u);
    *(float*)(cpu->ebp + 4u) = (double)*(float*)(cpu->ebp + 0x44u);
    *(float*)(cpu->ebp + 8u) = (double)*(float*)(cpu->ebp + 0x54u);
    *(float*)(cpu->ebp + 0xCu) = (double)*(float*)(cpu->ebp + 0x64u);
    *(float*)(cpu->ebp + 0x10u) = (double)*(float*)(cpu->ebp + 0x38u);
    *(float*)(cpu->ebp + 0x14u) = (double)*(float*)(cpu->ebp + 0x48u);
    *(float*)(cpu->ebp + 0x18u) = (double)*(float*)(cpu->ebp + 0x58u);
    *(float*)(cpu->ebp + 0x1Cu) = (double)*(float*)(cpu->ebp + 0x68u);
    *(float*)(cpu->ebp + 0x20u) = (double)*(float*)(cpu->ebp + 0x3Cu);
    *(float*)(cpu->ebp + 0x24u) = (double)*(float*)(cpu->ebp + 0x4Cu);
    *(float*)(cpu->ebp + 0x28u) = (double)*(float*)(cpu->ebp + 0x5Cu);
    *(float*)(cpu->ebp + 0x2Cu) = (double)*(float*)(cpu->ebp + 0x6Cu);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    x87_v0 = -x87_v0;
    *(float*)(cpu->ebp + 0xFFFFFFD8u) = x87_v0; 
    cpu->esp -= 0xCu;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = -x87_v0;
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    *(float*)(cpu->ebp + 0xFFFFFFDCu) = x87_v0; 
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    x87_v0 = -x87_v0;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(float*)(cpu->ebp + 0xFFFFFFE0u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    g_sfera_light_runtime.setDirectionalLight(SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const float>(cpu->esp + 20u)});  cpu->esp += 24u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C950u)); sfera_sub_00468750(cpu, LIFT_CODE_TOKEN_VA(0x41C950u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C955u)); sfera_sub_00450A00(cpu, LIFT_CODE_TOKEN_VA(0x41C955u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x144u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = cpu->eax + cpu->eax;
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->ecx;
    cpu->eax += 0x4F3Cu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->edx * 4u) + 0xA8u);
    cpu->ebx = cpu->esi + (cpu->edx * 4u) + 0xA8u;
    cpu->eax <<= 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C991u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x41C991u));
    x87_v0 = (double)*(float*)(cpu->edi + 0x178u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x174u);
    cpu->eax = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x180u);
    *(float*)(cpu->esp) = x87_v0; 
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x17Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x170u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C9C7u)); sfera_sub_0041C220(cpu, LIFT_CODE_TOKEN_VA(0x41C9C7u));
    x87_v0 = 0.0;
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->edi + 0x148u);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C9E0u)); sfera_sub_0041BEE0(cpu, LIFT_CODE_TOKEN_VA(0x41C9E0u));
    { const double lift_right=(double)*(float*)(cpu->edi + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001CA00; }
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    label_0001CA00:
    { const double lift_right=(double)*(float*)(cpu->edi + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001CA18; }
    cpu->eax = 1u;
    goto label_0001CA1A;
    label_0001CA18:
    cpu->eax = 0u;
    label_0001CA1A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx += 0x330u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CA44u)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41CA44u));
    cpu->esp -= 8u;
    x87_v0 = 1.0;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 4u) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CA57u)); sfera_sub_0041BEE0(cpu, LIFT_CODE_TOKEN_VA(0x41CA57u));
    { const double lift_right=(double)*(float*)(cpu->edi + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001CA73; }
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
    label_0001CA73:
    cpu->esi = 0u;
    if (((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03) == cpu->esi) || ((int32_t)((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03)) < (int32_t)(cpu->esi))) goto label_0001CAA6;
    label_0001CA80:
    if (*(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) != 1u) goto label_0001CA9D;
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    lift_push32(cpu, 0x4B8u);
    cpu->edx = 0u;
    g_sfera_light_runtime.setActive(cpu->ecx, cpu->edx == 1u, *SferaAbi::pointer<const std::uint32_t>(cpu->esp));  cpu->esp += 4u;
    label_0001CA9D:
    ++cpu->esi;
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03))) goto label_0001CA80;
    label_0001CAA6:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x38u);
    cpu->eax <<= 6u;
    cpu->esi = cpu->eax + cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CABAu));
    *(float*)(cpu->edi + 0x190u) = (double)*(float*)(cpu->esi + 0x30u);
    cpu->edx = cpu->edi + 0x190u;
    x87_v0 = (double)*(float*)(cpu->esi + 0x34u);
    cpu->ecx = cpu->ebp + 0x30u;
    *(float*)(cpu->edi + 0x194u) = x87_v0; 
    *(float*)(cpu->edi + 0x198u) = (double)*(float*)(cpu->esi + 0x38u);
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    lift_push32(cpu, 0x40u);
    cpu->eax = cpu->edi + 0x1A8u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CAF3u));
    x87_v0 = 0.0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esi + 0x30u) = x87_v0;
    lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esi + 0x34u) = x87_v0;
    cpu->edx = cpu->ebp + 0x30u;
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x1A8u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CB12u));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    *(float*)(cpu->edi + 0x1B4u) = x87_v0;
    *(float*)(cpu->edi + 0x1C4u) = x87_v0;
    *(float*)(cpu->edi + 0x1D4u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x38u);
    cpu->eax <<= 6u;
    cpu->esi = cpu->eax + cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CB3Fu));
    *(float*)(cpu->edi + 0x19Cu) = (double)*(float*)(cpu->esi + 0x30u);
    cpu->edx = cpu->edi + 0x19Cu;
    x87_v0 = (double)*(float*)(cpu->esi + 0x34u);
    cpu->ecx = cpu->ebp + 0x30u;
    *(float*)(cpu->edi + 0x1A0u) = x87_v0; 
    *(float*)(cpu->edi + 0x1A4u) = (double)*(float*)(cpu->esi + 0x38u);
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->esi <<= 6u;
    cpu->esi += *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = cpu->edi + 0x228u;
    x87_v0 = (double)*(float*)(cpu->esi + 0x30u);
    cpu->ecx = cpu->ebp + 0x30u;
    *(float*)(cpu->edx) = x87_v0; 
    *(float*)(cpu->edi + 0x22Cu) = (double)*(float*)(cpu->esi + 0x34u);
    *(float*)(cpu->edi + 0x230u) = (double)*(float*)(cpu->esi + 0x38u);
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    lift_push32(cpu, 0x40u);
    cpu->ebx = cpu->edi + 0x1E8u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CBA6u));
    lift_push32(cpu, 0x40u);
    cpu->eax = cpu->edi + 0x234u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CBB6u));
    cpu->esp += 0x18u;
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esi + 0x30u) = x87_v0;
    cpu->eax = cpu->ebp + 0x30u;
    *(float*)(cpu->esi + 0x34u) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->ebp + 0xFFFFFFECu) = (double)*(float*)(cpu->esi + 0xCu);
    *(float*)(cpu->esi + 0xCu) = (double)*(float*)(cpu->esi + 0x30u);
    *(float*)(cpu->esi + 0x30u) = (double)*(float*)(cpu->ebp + 0xFFFFFFECu);
    *(float*)(cpu->ebp + 0xFFFFFFECu) = (double)*(float*)(cpu->esi + 0x1Cu);
    *(float*)(cpu->esi + 0x1Cu) = (double)*(float*)(cpu->esi + 0x34u);
    *(float*)(cpu->esi + 0x34u) = (double)*(float*)(cpu->ebp + 0xFFFFFFECu);
    *(float*)(cpu->ebp + 0xFFFFFFECu) = (double)*(float*)(cpu->esi + 0x2Cu);
    *(float*)(cpu->esi + 0x2Cu) = (double)*(float*)(cpu->esi + 0x38u);
    *(float*)(cpu->esi + 0x38u) = (double)*(float*)(cpu->ebp + 0xFFFFFFECu);
    *(float*)(cpu->ebp + 0xFFFFFFECu) = (double)*(float*)(cpu->esi + 4u);
    *(float*)(cpu->esi + 4u) = (double)*(float*)(cpu->esi + 0x10u);
    *(float*)(cpu->esi + 0x10u) = (double)*(float*)(cpu->ebp + 0xFFFFFFECu);
    *(float*)(cpu->ebp + 0xFFFFFFECu) = (double)*(float*)(cpu->esi + 8u);
    *(float*)(cpu->esi + 8u) = (double)*(float*)(cpu->esi + 0x20u);
    *(float*)(cpu->esi + 0x20u) = (double)*(float*)(cpu->ebp + 0xFFFFFFECu);
    *(float*)(cpu->ebp + 0xFFFFFFECu) = (double)*(float*)(cpu->esi + 0x18u);
    *(float*)(cpu->esi + 0x18u) = (double)*(float*)(cpu->esi + 0x24u);
    *(float*)(cpu->esi + 0x24u) = (double)*(float*)(cpu->ebp + 0xFFFFFFECu);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CC3Bu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->edi + 0x234u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CC4Cu));
    x87_v0 = 0.0;
    *(float*)(cpu->edi + 0x1F4u) = x87_v0;
    *(float*)(cpu->edi + 0x204u) = x87_v0;
    *(float*)(cpu->edi + 0x214u) = x87_v0;
    *(float*)(cpu->edi + 0x240u) = x87_v0;
    *(float*)(cpu->edi + 0x250u) = x87_v0;
    *(float*)(cpu->edi + 0x260u) = x87_v0; 
    label_0001CC77:
    cpu->esp = cpu->ebp + 0xFFFFFFCCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp + 0x74u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041CC90(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CCA1u)); sfera_sub_0045A9C0(cpu, LIFT_CODE_TOKEN_VA(0x41CCA1u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = (cpu->ecx * 4u) + 0x22u;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi));
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->edi + 8u);
    cpu->ebx = cpu->eax + (cpu->ecx * 4u) + 4u;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ecx;
    lift_push32(cpu, 0xDEu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CCE0u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41CCE0u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->edi + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41CCE9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->ecx + (cpu->eax * 4u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->eax;
    cpu->edx = cpu->ecx + (cpu->edx * 2u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->edx + (cpu->eax * 4u) + 4u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x41CD20u));
    cpu->edi = 0u;
    if ((*(uint32_t*)(cpu->esi) == cpu->edi) || ((int32_t)(*(uint32_t*)(cpu->esi)) < (int32_t)(cpu->edi))) goto label_0001CD64;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    (void)cpu;
    label_0001CD30:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (*(uint8_t*)(cpu->eax + cpu->ebp) != 0x5Fu) goto label_0001CD5B;
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ebp + 1u));
    if ((int32_t)(cpu->ebx -= 0x30u) < 0) goto label_0001CD48;
    if (cpu->ebx < 7u) goto label_0001CD57;
    label_0001CD48:
    cpu->edx = 0xEDu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1CD57u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1CD57u));
    label_0001CD57:
    *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x1Cu) = cpu->edi;
    label_0001CD5B:
    ++cpu->edi;
    cpu->ebp += 0x1Eu;
    if ((int32_t)(cpu->edi) < (int32_t)(*(uint32_t*)(cpu->esi))) goto label_0001CD30;
    cpu->ebp = lift_pop32(cpu);
    label_0001CD64:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, 0xF4u);
    cpu->ecx <<= 6u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CD78u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41CD78u));
    x87_v0 = 0.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CD96u)); sfera_sub_0041C220(cpu, LIFT_CODE_TOKEN_VA(0x41CD96u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041CDA0(LiftCpu* cpu, uint32_t stop_address) {
    std::optional<SphereRender::ConfigDocument> configuration_document; bool sub_pred[3]; double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x150u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x164u;
    lift_push32(cpu, 0x7540u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CDE5u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x184u);
    cpu->esp += 0xCu;
    if ((int32_t)cpu->edi < (int32_t)0x64u) goto label_0001CE08;
    cpu->edx = 0x10Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1CE08u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1CE08u));
    label_0001CE08:
    x87_v0 = 0.0;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esi + 0x40u) = x87_v0;
    *(float*)(cpu->esi + 0x3Cu) = x87_v0;
    *(float*)(cpu->esi + 0x38u) = x87_v0;
    *(float*)(cpu->esi + 0x34u) = x87_v0;
    *(float*)(cpu->esi + 0x2Cu) = x87_v0;
    *(float*)(cpu->esi + 0x28u) = x87_v0;
    *(float*)(cpu->esi + 0x24u) = x87_v0;
    *(float*)(cpu->esi + 0x20u) = x87_v0;
    *(float*)(cpu->esi + 0x18u) = x87_v0;
    *(float*)(cpu->esi + 0x14u) = x87_v0;
    *(float*)(cpu->esi + 0x10u) = x87_v0;
    *(float*)(cpu->esi + 0xCu) = x87_v0; 
    x87_v0 = 1.0;
    *(float*)(cpu->esi + 0x44u) = x87_v0;
    *(float*)(cpu->esi + 0x30u) = x87_v0;
    *(float*)(cpu->esi + 0x1Cu) = x87_v0;
    *(float*)(cpu->esi + 8u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CE43u)); sfera_sub_0041B980(cpu, LIFT_CODE_TOKEN_VA(0x41CE43u));
    cpu->eax = cpu->esi + 0xA8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"xadd\\man.skl");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CE54u)); sfera_sub_0041CC90(cpu, LIFT_CODE_TOKEN_VA(0x41CE54u));
    cpu->ecx = cpu->esi + 0xE4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"xadd\\woman.skl");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CE67u)); sfera_sub_0041CC90(cpu, LIFT_CODE_TOKEN_VA(0x41CE67u));
    lift_push32(cpu, 0x114u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = 0x2260u;
    *(uint32_t*)(cpu->esi + 0x4F40u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CE81u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41CE81u));
    cpu->ebp = 0u;
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x4F40u) <= (int32_t)cpu->ebp) goto label_0001D0B2;
    cpu->edx = cpu->esi + 0x120u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    label_0001CE9F:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x174u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->eax * 4u));
    cpu->edx = cpu->eax + 1u;
    label_0001CEB0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001CEB0;
    cpu->eax -= cpu->edx;
    if (cpu->eax < 0xC8u) goto label_0001CECF;
    cpu->edx = 0x11Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1CECFu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1CECFu));
    label_0001CECF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->ecx * 4u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->edi;
    label_0001CEE0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0001CEE0;
    lift_push32(cpu, (uintptr_t)"*.chr"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CEF9u)); sfera_sub_0047EBB0(cpu, LIFT_CODE_TOKEN_VA(0x41CEF9u));
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x170u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CF10u)); sfera_sub_0047ED30(cpu, LIFT_CODE_TOKEN_VA(0x41CF10u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41CF11u));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x16Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CF34u)); sfera_sub_0047ED10(cpu, LIFT_CODE_TOKEN_VA(0x41CF34u));
    if (cpu->edi == 0xFFFFFFFFu) goto label_0001D04A;
    label_0001CF40:
    if (((*(uint8_t*)(cpu->esp + 0x38u)) & (0x10u)) != 0u) goto label_0001D025;
    cpu->eax = cpu->esp + 0x5Cu;
    cpu->edx = cpu->eax + 1u;
    label_0001CF52:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001CF52;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)5u) goto label_0001CF65;
    if ((int32_t)cpu->eax < (int32_t)0x20u) goto label_0001CF74;
    label_0001CF65:
    cpu->edx = 0x124u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1CF74u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1CF74u));
    label_0001CF74:
    cpu->edi = cpu->ebp;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x2Cu);
    cpu->eax = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->edi += cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CF89u)); sfera_sub_0047ED40(cpu, LIFT_CODE_TOKEN_VA(0x41CF89u));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x16Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CF9Bu)); sfera_sub_0047ED30(cpu, LIFT_CODE_TOKEN_VA(0x41CF9Bu));
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_0001CFA0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001CFA0;
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x16Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CFBEu)); sfera_sub_0047EDB0(cpu, LIFT_CODE_TOKEN_VA(0x41CFBEu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CFC5u)); sfera_sub_0047EA20(cpu, LIFT_CODE_TOKEN_VA(0x41CFC5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = 0u;
    ++cpu->ebp;
    *(uint32_t*)(cpu->edi + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x28u) = cpu->eax;
    if (cpu->ebp != 0xC8u) goto label_0001D025;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F48u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F44u);
    cpu->edx += cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, 0x12Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CFFDu)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x41CFFDu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F48u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, 0x2260u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esi + 0x4F44u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41D015u));
    *(uint32_t*)(cpu->esi + 0x4F48u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x4F48u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->esp += 0xCu;
    cpu->ebp = 0u;
    label_0001D025:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41D02Fu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001CF40;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41D041u));
    cpu->esp += 4u;
    label_0001D04A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0xC8u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x4F40u)) goto label_0001CE9F;
    if (cpu->ebp == 0u) goto label_0001D0B2;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F48u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F44u);
    cpu->edx += cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, 0x13Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D08Bu)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x41D08Bu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F48u);
    cpu->ecx = cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esi + 0x4F44u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41D0A4u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x4F48u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x4F48u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    label_0001D0B2:
    lift_push32(cpu, 0x13Eu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D0C3u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41D0C3u));
    cpu->ecx = 0u;
    SphereRender::ConfigDocument::setStorageMode(cpu->ecx == 0u ? SphereRender::ConfigDocument::StorageMode::Plain : cpu->ecx == 1u ? SphereRender::ConfigDocument::StorageMode::Encoded : SphereRender::ConfigDocument::StorageMode::Preserve);
    cpu->ecx = (uintptr_t)"xadd\\subobjs.dat";
    configuration_document.emplace(SphereRender::ConfigDocument::open(SferaAbi::pointer<const char>(cpu->ecx))); cpu->eax = SferaAbi::address(&*configuration_document);
    cpu->edx = (uintptr_t)"subobjs";
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)1u) goto label_0001D36E;
    label_0001D0F3:
    cpu->ecx = cpu->edi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x54u);
    lift_push32(cpu, 0x147u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D107u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41D107u));
    lift_push32(cpu, 0x148u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = 0x6800u;
    *(uint32_t*)(cpu->esi + 0x4F4Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D121u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41D121u));
    lift_push32(cpu, 0x6800u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x4F50u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41D132u));
    cpu->ebx = 0u;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)cpu->edi <= (int32_t)cpu->ebx) goto label_0001D331;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    label_0001D150:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"subobjs";
    cpu->eax = SferaAbi::address(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->objectAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"s";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    { const char* value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->text(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value != nullptr ? 1u : 0u; if (value != nullptr) *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = SferaAbi::address(value); }; cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0001D36E;
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"m";
    cpu->ecx = cpu->edi;
    { const char* value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->text(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value != nullptr ? 1u : 0u; if (value != nullptr) *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = SferaAbi::address(value); }; cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0001D36E;
    cpu->ebx = 0u;
    sub_pred[1] = cpu->ebx == *(uint32_t*)(cpu->esi + 0x4F48u);
    if ((int32_t)(cpu->ebx) >= (int32_t)(*(uint32_t*)(cpu->esi + 0x4F48u))) goto label_0001D200;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x4F44u);
    label_0001D1B0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = cpu->ebp;
    label_0001D1B6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0001D1D6;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0001D1D2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0001D1D6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0001D1B6;
    label_0001D1D2:
    cpu->eax = 0u;
    goto label_0001D1DB;
    label_0001D1D6:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_0001D1DB:
    if (cpu->eax == 0u) goto label_0001D1ED;
    ++cpu->ebx;
    cpu->ebp += 0x2Cu;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esi + 0x4F48u)) goto label_0001D1B0;
    goto label_0001D1FA;
    label_0001D1ED:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4F4Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ecx + cpu->eax) = cpu->ebx;
    label_0001D1FA:
    sub_pred[1] = cpu->ebx == *(uint32_t*)(cpu->esi + 0x4F48u);
    label_0001D200:
    if (!sub_pred[1]) goto label_0001D210;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = (uintptr_t)"char model not found. name=";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1D210u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x1D210u));
    label_0001D210:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F4Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x50u);
    cpu->ecx = cpu->eax + cpu->edx + 4u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41D223u));
    cpu->esp += 0xCu;
    cpu->edx = (uintptr_t)"t";
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx < (int32_t)1u) goto label_0001D36E;
    cpu->ebp = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0001D2AB;
    goto label_0001D254;
    label_0001D250:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    label_0001D254:
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uintptr_t)"t";
    cpu->ecx = cpu->edi;
    { const char* value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->textAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value != nullptr ? 1u : 0u; if (value != nullptr) *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = SferaAbi::address(value); }; cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001D36E;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi += cpu->ebp;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F4Cu);
    *(uint32_t*)(cpu->edi + cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F4Cu);
    if (*(uint32_t*)(cpu->edi + cpu->edx + 4u) != 0xFFFFFFFFu) goto label_0001D2A6;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = (uintptr_t)"texture for char model not found. name=";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1D2A6u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x1D2A6u));
    label_0001D2A6:
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->ebx) goto label_0001D250;
    label_0001D2AB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->eax & 0xFFu) == 0x6Du) goto label_0001D2BD;
    if ((cpu->eax & 0xFFu) != 0x77u) goto label_0001D36E;
    label_0001D2BD:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    if ((int8_t)(cpu->edx & 0xFFu) < (int8_t)0x61u) goto label_0001D36E;
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x7Au) goto label_0001D36E;
    cpu->eax = cpu->ecx;
    cpu->ebp = cpu->eax + 1u;
    label_0001D2D7:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_0001D2D7;
    cpu->eax -= cpu->ebp;
    if (cpu->eax != 3u) goto label_0001D36E;
    cpu->edx = (int8_t)((cpu->edx & 0xFFu));
    cpu->edx -= 0x61u;
    cpu->eax=0u;
    cpu->edx <<= 8u;
    sub_pred[2] = *(uint8_t*)(cpu->ecx) == 0x6Du;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->ecx + 2u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (sub_pred[2]);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x54u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x15u) + (uint64_t)(0u);
    --cpu->eax;
    cpu->eax &= 0x1A00u;
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F50u);
    *(uint16_t*)(cpu->ecx + (cpu->edx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esp + 0x24u)) goto label_0001D150;
    cpu->ebx = 0u;
    label_0001D331:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = (uintptr_t)"womanhelmsmall";
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebp < (int32_t)1u) goto label_0001D36E;
    cpu->edi = 0u;
    cpu->ebx = cpu->esi + 0x74D4u;
    label_0001D350:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebp) goto label_0001D381;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edx = (uintptr_t)"womanhelmsmall";
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->integerAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001D36E;
    ++cpu->edi;
    cpu->ebx += 4u;
    goto label_0001D350;
    label_0001D36E:
    cpu->ecx = (uintptr_t)"wrong format of subobjs.dat";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D378u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x41D378u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    goto label_0001D0F3;
    label_0001D381:
    configuration_document.reset();
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x15Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041D3C0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5;
 bool sub_pred[2]; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5;
    bool lift_cmp[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp + 0xFFFFFF90u;
    cpu->esp -= 0xB0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x78u);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->edi;
    if ((int32_t)cpu->edi >= 0) goto label_0001D3F1;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1D3F1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x1D3F1u));
label_0001D3F1:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0001D405;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1D405u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1D405u));
label_0001D405:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    lift_push32(cpu, 0x3B2u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D41Cu)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x41D41Cu));
    cpu->ebx = cpu->eax;
    if (*(uint8_t*)(cpu->ebx + 0x141u) == 0u) goto label_0001E18E;
    cpu->ecx = cpu->ebp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx + 0x14u;
    cpu->ecx = cpu->ebx + 8u;
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); *destination = SferaMatrix4x4F::fromEuler(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->edx)); cpu->eax = SferaAbi::address(destination); }; cpu->esp += 4u;
    cpu->edx = cpu->ebp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D445u)); sfera_sub_0041B5B0(cpu, LIFT_CODE_TOKEN_VA(0x41D445u));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0001E18E;
    x87_p0 = 1.0;
    ++*(uint32_t*)(cpu->esi + 0x7530u);
    sub_pred[0] = (uint32_t)(g_sfera_graphics_runtime.lods_enabled) == 0u;
    *(float*)(cpu->ebp + 0xFFFFFFE8u) = x87_p0; 
    if (sub_pred[0]) goto label_0001D48C;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D46Cu)); value_5 = sfera_sub_0041C6C0(cpu, LIFT_CODE_TOKEN_VA(0x41D46Cu));
    *(float*)(cpu->ebp + 0xFFFFFFE8u) = value_5; 
     if (!(((double)0.0010000000474974513f)>(((double)*(float*)(cpu->ebp + 0xFFFFFFE8u))))) goto label_0001D48C;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D487u)); sfera_sub_0041C7F0(cpu, LIFT_CODE_TOKEN_VA(0x41D487u));
    goto label_0001E18E;
label_0001D48C:
    x87_p0 = (double)*(float*)(cpu->ebp + 0x2Cu);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->ebp + 0xFFFFFFECu) = x87_p0; 
    cpu->eax = cpu->ebp + 0xFFFFFFECu;
    x87_p0 = (double)*(float*)(cpu->ebp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->ebp + 0xFFFFFFF0u) = x87_p0; 
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->ebp + 0xFFFFFFF4u) = (double)*(float*)(cpu->ebp + 0x4Cu);
    *(float*)(cpu->ebp + 0xFFFFFFF8u) = (double)*(float*)(cpu->ebp + 0x5Cu);
    *(float*)(cpu->ebp + 0xFFFFFFFCu) = (double)*(float*)(cpu->ebp + 0x30u);
    *(float*)(cpu->ebp) = (double)*(float*)(cpu->ebp + 0x40u);
    *(float*)(cpu->ebp + 4u) = (double)*(float*)(cpu->ebp + 0x50u);
    *(float*)(cpu->ebp + 8u) = (double)*(float*)(cpu->ebp + 0x60u);
    *(float*)(cpu->ebp + 0xCu) = (double)*(float*)(cpu->ebp + 0x34u);
    *(float*)(cpu->ebp + 0x10u) = (double)*(float*)(cpu->ebp + 0x44u);
    *(float*)(cpu->ebp + 0x14u) = (double)*(float*)(cpu->ebp + 0x54u);
    *(float*)(cpu->ebp + 0x18u) = (double)*(float*)(cpu->ebp + 0x64u);
    *(float*)(cpu->ebp + 0x1Cu) = (double)*(float*)(cpu->ebp + 0x38u);
    *(float*)(cpu->ebp + 0x20u) = (double)*(float*)(cpu->ebp + 0x48u);
    *(float*)(cpu->ebp + 0x24u) = (double)*(float*)(cpu->ebp + 0x58u);
    *(float*)(cpu->ebp + 0x28u) = (double)*(float*)(cpu->ebp + 0x68u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    x87_p0 = -x87_p0;
    *(float*)(cpu->ebp + 0xFFFFFFC0u) = x87_p0; 
    cpu->esp -= 0xCu;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_p0 = -x87_p0;
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    *(float*)(cpu->ebp + 0xFFFFFFC4u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    x87_p0 = -x87_p0;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(float*)(cpu->ebp + 0xFFFFFFC8u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    g_sfera_light_runtime.setDirectionalLight(SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}, SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp + 12u), *SferaAbi::pointer<const float>(cpu->esp + 16u), *SferaAbi::pointer<const float>(cpu->esp + 20u)});  cpu->esp += 24u;
    cpu->esi = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D564u)); sfera_sub_00468750(cpu, LIFT_CODE_TOKEN_VA(0x41D564u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D569u)); sfera_sub_00450A00(cpu, LIFT_CODE_TOKEN_VA(0x41D569u));
    x87_p0 = 1.0;
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0;
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D582u)); sfera_sub_00461FD0(cpu, LIFT_CODE_TOKEN_VA(0x41D582u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x144u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->esi = cpu->edi;
    cpu->esi -= cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->edx * 4u) + 0xA8u);
    cpu->edi = cpu->edi + (cpu->edx * 4u) + 0xA8u;
    cpu->eax <<= 6u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D5BEu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x41D5BEu));
    x87_p0 = (double)*(float*)(cpu->ebx + 0x178u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x174u);
    cpu->eax = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x180u);
    *(float*)(cpu->esp) = x87_p0; 
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x17Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x170u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D5F5u)); sfera_sub_0041C220(cpu, LIFT_CODE_TOKEN_VA(0x41D5F5u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x7Cu);
    cpu->ecx = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->esp -= 0x14u;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u))));
    cpu->edx >>= 8u;
    x87_p1 = 255.0;
    cpu->edx&=0xFFu;
    cpu->eax >>= 16u;
    x87_p0 = (x87_p0) / (x87_p1);
    cpu->eax &= 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = x87_p1; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u))));
    x87_p1 = (x87_p1) / (x87_p0);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = x87_p1; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    x87_p0 = ((double)(((int32_t)(*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u))))) / (x87_p0);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = x87_p0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE8u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->ebx + 0x148u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D665u)); sfera_sub_0041BE20(cpu, LIFT_CODE_TOKEN_VA(0x41D665u));
    x87_p0 = (double)*(float*)(cpu->ebx + 0x148u);
    x87_p1 = 1.0;
    x87_p2 = x87_p1;
     value_1 = x87_p2; value_2 = x87_p1; value_3 = x87_p0; { const double lift_left=value_1; const double lift_right=value_3;    if (lift_left==lift_right) { value_0 = value_2; goto label_0001D68D; } }
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    value_4 = 1.0; value_0 = value_4;
label_0001D68D:
    x87_p0 = (double)*(float*)(cpu->ebx + 0x148u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x4F46u));
    lift_cmp[0]=x87_p0==value_0;  
     if ((cpu->ecx & 0xFFu) == 0u) goto label_0001D731;
    if (lift_cmp[0]) goto label_0001D6B1;
    cpu->eax = 1u;
    goto label_0001D6B3;
label_0001D6B1:
    cpu->eax = 0u;
label_0001D6B3:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax + cpu->ecx + 0x200u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D6E2u)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41D6E2u));
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D6FA; }
    cpu->eax = 1u;
    goto label_0001D6FC;
label_0001D6FA:
    cpu->eax = 0u;
label_0001D6FC:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F48u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 3u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x4F46u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ecx + cpu->edx + 0x400u;
    goto label_0001D7BC;
label_0001D731:
    if (lift_cmp[0]) goto label_0001D73D;
    cpu->eax = 1u;
    goto label_0001D73F;
label_0001D73D:
    cpu->eax = 0u;
label_0001D73F:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F47u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax + cpu->ecx + 0x1500u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D772u)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41D772u));
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D78A; }
    cpu->eax = 1u;
    goto label_0001D78C;
label_0001D78A:
    cpu->eax = 0u;
label_0001D78C:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F48u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 3u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x4F47u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ecx + cpu->edx + 0xB00u;
label_0001D7BC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D7C5u)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41D7C5u));
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D7DD; }
    cpu->eax = 1u;
    goto label_0001D7DF;
label_0001D7DD:
    cpu->eax = 0u;
label_0001D7DF:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x4F4Au);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax + cpu->ecx + 0x600u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D812u)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41D812u));
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D82A; }
    cpu->eax = 1u;
    goto label_0001D82C;
label_0001D82A:
    cpu->eax = 0u;
label_0001D82C:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x4F45u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx + cpu->eax + 0x1300u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D85Fu)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41D85Fu));
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D877; }
    cpu->eax = 1u;
    goto label_0001D879;
label_0001D877:
    cpu->eax = 0u;
label_0001D879:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F44u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ecx + cpu->edx + 0x100u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D8ACu)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41D8ACu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 2u;
    if (cpu->ecx == g_sfera_world_objects.controlled_object_handle) goto label_0001D8C5;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 3u;
label_0001D8C5:
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D8DD; }
    cpu->eax = 1u;
    goto label_0001D8DF;
label_0001D8DD:
    cpu->eax = 0u;
label_0001D8DF:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F4Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F4Bu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ecx + cpu->edx + 0x500u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D91Au)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41D91Au));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x4F4Fu));
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0001D96F;
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D93C; }
    cpu->eax = 1u;
    goto label_0001D93E;
label_0001D93C:
    cpu->eax = 0u;
label_0001D93E:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax + cpu->ecx + 0x700u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1D96Fu)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_RVA(0x1D96Fu));
label_0001D96F:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x4F4Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0001D994;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D98Cu)); sfera_sub_0041C070(cpu, LIFT_CODE_TOKEN_VA(0x41D98Cu));
    if (cpu->eax == 0u) goto label_0001DA14;
label_0001D994:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x80u); lift_push32(cpu, 0x18u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001D9BE; }
    cpu->eax = 1u;
    goto label_0001D9C0;
label_0001D9BE:
    cpu->eax = 0u;
label_0001D9C0:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F4Eu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx = 0u;
    sub_pred[1] = *(uint8_t*)(cpu->esi + 0x4F4Fu) == (uint8_t)(cpu->ecx);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4F40u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (sub_pred[1]);
    cpu->edx *= 0x1Au;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ecx + cpu->edx + 0x10u;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4F4Du);
    cpu->eax <<= 8u;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DA05u)); sfera_sub_0041BA00(cpu, LIFT_CODE_TOKEN_VA(0x41DA05u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x18u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
label_0001DA14:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DA1Bu)); sfera_sub_00451A30(cpu, LIFT_CODE_TOKEN_VA(0x41DA1Bu));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
label_0001DA20:
    if (*(uint32_t*)(cpu->ebx + (cpu->esi * 4u) + 0xF8u) == 0u) goto label_0001DDDF;
    if (cpu->esi != 3u) goto label_0001DA44;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    if (cpu->edx == g_sfera_world_objects.controlled_object_handle) goto label_0001DDDF;
    goto label_0001DA52;
label_0001DA44:
    if ((int32_t)cpu->esi >= 0) goto label_0001DA52;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1DA52u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x1DA52u));
label_0001DA52:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity))) goto label_0001DA66;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1DA66u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1DA66u));
label_0001DA66:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->eax * 4u) + 0x1Cu);
    cpu->edx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 6u;
    cpu->esi <<= 6u;
    cpu->esi += *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ecx;
    cpu->edi = cpu->ecx + cpu->edx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    if ((int32_t)cpu->eax >= 0) goto label_0001DA9F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DA9Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DA9Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DA9F:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DAB7;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DAB4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DAB4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DAB7:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)cpu->eax >= 0) goto label_0001DAD1;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DACEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DACEu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DAD1:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DAE9;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DAE6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DAE6u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DAE9:
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->edx + cpu->ecx + 0xCu);
    *(float*)(cpu->edx + cpu->ecx + 0xCu) = (double)*(float*)(cpu->esi + 0x30u);
    *(float*)(cpu->esi + 0x30u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)cpu->eax >= 0) goto label_0001DB17;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DB14u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DB14u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DB17:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DB2F;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DB2Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DB2Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DB2F:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)cpu->eax >= 0) goto label_0001DB49;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DB46u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DB46u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DB49:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DB61;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DB5Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DB5Eu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DB61:
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x1Cu);
    *(float*)(cpu->edx + cpu->ecx + 0x1Cu) = (double)*(float*)(cpu->esi + 0x34u);
    *(float*)(cpu->esi + 0x34u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)cpu->eax >= 0) goto label_0001DB8F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DB8Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DB8Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DB8F:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DBA7;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DBA4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DBA4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DBA7:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)cpu->eax >= 0) goto label_0001DBC1;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DBBEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DBBEu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DBC1:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DBD9;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DBD6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DBD6u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DBD9:
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x2Cu);
    *(float*)(cpu->edx + cpu->ecx + 0x2Cu) = (double)*(float*)(cpu->esi + 0x38u);
    *(float*)(cpu->esi + 0x38u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)cpu->eax >= 0) goto label_0001DC07;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DC04u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DC04u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DC07:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DC1F;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DC1Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DC1Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DC1F:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)cpu->eax >= 0) goto label_0001DC39;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DC36u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DC36u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DC39:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DC51;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DC4Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DC4Eu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DC51:
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->edx + cpu->ecx + 4u);
    *(float*)(cpu->edx + cpu->ecx + 4u) = (double)*(float*)(cpu->esi + 0x10u);
    *(float*)(cpu->esi + 0x10u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)cpu->eax >= 0) goto label_0001DC7F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DC7Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DC7Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DC7F:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DC97;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DC94u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DC94u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DC97:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)cpu->eax >= 0) goto label_0001DCB1;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DCAEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DCAEu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DCB1:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DCC9;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DCC6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DCC6u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DCC9:
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->edx + cpu->ecx + 8u);
    *(float*)(cpu->edx + cpu->ecx + 8u) = (double)*(float*)(cpu->esi + 0x20u);
    *(float*)(cpu->esi + 0x20u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)cpu->eax >= 0) goto label_0001DCF7;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DCF4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DCF4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DCF7:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DD0F;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DD0Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DD0Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DD0F:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)cpu->eax >= 0) goto label_0001DD29;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DD26u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DD26u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DD29:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DD41;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DD3Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DD3Eu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DD41:
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x18u);
    *(float*)(cpu->edx + cpu->ecx + 0x18u) = (double)*(float*)(cpu->esi + 0x24u);
    *(float*)(cpu->esi + 0x24u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)cpu->eax >= 0) goto label_0001DD6F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DD6Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DD6Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DD6F:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DD87;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DD84u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x41DD84u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DD87:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)cpu->eax >= 0) goto label_0001DDA1;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DD9Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x41DD9Eu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DDA1:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.character_matrices.capacity) goto label_0001DDB6;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1DDB6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1DDB6u));
label_0001DDB6:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += g_sfera_scene_array_runtime.character_matrices.data;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DDC5u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + (cpu->eax * 4u) + 0xF8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DDD9u)); sfera_sub_00477020(cpu, LIFT_CODE_TOKEN_VA(0x41DDD9u));
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
label_0001DDDF:
    ++cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)5u) goto label_0001DA20;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DDF3u)); sfera_sub_00451A30(cpu, LIFT_CODE_TOKEN_VA(0x41DDF3u));
    x87_p0 = 1.0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0;
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DE07u)); sfera_sub_0041BEE0(cpu, LIFT_CODE_TOKEN_VA(0x41DE07u));
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x148u); const double lift_left=1.0; if (lift_left==lift_right) goto label_0001DE23; }
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
label_0001DE23:
    x87_p0 = (double)*(float*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0; 
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp) = (double)(1.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41DE39u)); sfera_sub_00470B80(cpu, LIFT_CODE_TOKEN_VA(0x41DE39u));
    cpu->esi = 0u;
    if (((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03) == cpu->esi) || ((int32_t)((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03)) < (int32_t)(cpu->esi))) goto label_0001DE69;
label_0001DE43:
    if (*(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) != 1u) goto label_0001DE60;
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    lift_push32(cpu, 0x43Du);
    cpu->edx = 0u;
    g_sfera_light_runtime.setActive(cpu->ecx, cpu->edx == 1u, *SferaAbi::pointer<const std::uint32_t>(cpu->esp));  cpu->esp += 4u;
label_0001DE60:
    ++cpu->esi;
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03))) goto label_0001DE43;
label_0001DE69:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x38u);
    cpu->eax <<= 6u;
    cpu->esi = cpu->eax + cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DE7Du));
    *(float*)(cpu->ebx + 0x190u) = (double)*(float*)(cpu->esi + 0x30u);
    lift_push32(cpu, 0x40u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x34u);
    cpu->eax = cpu->ebx + 0x1A8u;
    *(float*)(cpu->ebx + 0x194u) = x87_p0; 
    lift_push32(cpu, 0u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->ebx + 0x198u) = x87_p0; 
    *(float*)(cpu->ebp + 0xFFFFFFD0u) = (double)*(float*)(cpu->ebx + 0x190u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->ebx + 0x194u);
    *(float*)(cpu->ebp + 0xFFFFFFD4u) = (double)*(float*)(cpu->ebx + 0x198u);
    x87_p0 = (double)*(float*)(cpu->ebp + 0x30u);
    x87_p1 = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebp + 0x2Cu);
    x87_p3 = (double)*(float*)(cpu->ebp + 0xFFFFFFD0u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    std::swap(x87_p3, x87_p0);
    x87_p2 = x87_p2 + x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x34u);
    x87_p4 = (double)*(float*)(cpu->ebp + 0xFFFFFFD4u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    std::swap(x87_p4, x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebp + 0x38u)));
    *(float*)(cpu->ebx + 0x190u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x40u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p4 = (double)*(float*)(cpu->ebp + 0x3Cu);
    x87_p4 = (x87_p4) * (x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p4 = (double)*(float*)(cpu->ebp + 0x44u);
    x87_p4 = (x87_p4) * (x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebp + 0x48u)));
    *(float*)(cpu->ebx + 0x194u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x50u);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x4Cu);
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->ebp + 0x54u)));
    x87_p0 = x87_p0 + x87_p1; 
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->ebp + 0x58u)));
    *(float*)(cpu->ebx + 0x198u) = x87_p0; 
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41DF2Au));
    x87_p0 = 0.0;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esi + 0x30u) = x87_p0;
    cpu->eax = cpu->ebp + 0x2Cu;
    *(float*)(cpu->esi + 0x34u) = x87_p0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esi + 0x38u) = x87_p0; 
    cpu->eax = cpu->ebx + 0x1A8u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DF49u));
    x87_p0 = 0.0;
    *(float*)(cpu->ebx + 0x1B4u) = x87_p0;
    *(float*)(cpu->ebx + 0x1C4u) = x87_p0;
    *(float*)(cpu->ebx + 0x1D4u) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x38u);
    cpu->eax <<= 6u;
    cpu->esi = cpu->eax + cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DF76u));
    *(float*)(cpu->ebx + 0x19Cu) = (double)*(float*)(cpu->esi + 0x30u);
    *(float*)(cpu->ebx + 0x1A0u) = (double)*(float*)(cpu->esi + 0x34u);
    *(float*)(cpu->ebx + 0x1A4u) = (double)*(float*)(cpu->esi + 0x38u);
    *(float*)(cpu->ebp + 0xFFFFFFD0u) = (double)*(float*)(cpu->ebx + 0x19Cu);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->ebx + 0x1A0u);
    *(float*)(cpu->ebp + 0xFFFFFFD4u) = (double)*(float*)(cpu->ebx + 0x1A4u);
    x87_p0 = (double)*(float*)(cpu->ebp + 0x30u);
    x87_p1 = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebp + 0xFFFFFFD0u); x87_p3 = x87_p2;
    x87_p3 = (x87_p3) * (((double)*(float*)(cpu->ebp + 0x2Cu)));
    x87_p0 = x87_p0 + x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x34u);
    x87_p4 = (double)*(float*)(cpu->ebp + 0xFFFFFFD4u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    std::swap(x87_p4, x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebp + 0x38u)));
    *(float*)(cpu->ebx + 0x19Cu) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x40u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p4 = (double)*(float*)(cpu->ebp + 0x3Cu);
    x87_p4 = (x87_p4) * (x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p4 = (double)*(float*)(cpu->ebp + 0x44u);
    x87_p4 = (x87_p4) * (x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebp + 0x48u)));
    *(float*)(cpu->ebx + 0x1A0u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x50u);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->ebp + 0x4Cu)));
    x87_p1 = x87_p1 + x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebp + 0x54u);
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->ebp + 0x58u)));
    *(float*)(cpu->ebx + 0x1A4u) = x87_p0; 
    cpu->esi = *(uint32_t*)(cpu->edi + 0x1Cu);
    cpu->esi <<= 6u;
    cpu->esi += *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(float*)(cpu->ebx + 0x228u) = (double)*(float*)(cpu->esi + 0x30u);
    *(float*)(cpu->ebx + 0x22Cu) = (double)*(float*)(cpu->esi + 0x34u);
    *(float*)(cpu->ebx + 0x230u) = (double)*(float*)(cpu->esi + 0x38u);
    *(float*)(cpu->ebp + 0xFFFFFFD0u) = (double)*(float*)(cpu->ebx + 0x228u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->ebx + 0x22Cu);
    *(float*)(cpu->ebp + 0xFFFFFFD4u) = (double)*(float*)(cpu->ebx + 0x230u);
    x87_p0 = (double)*(float*)(cpu->ebp + 0x30u);
    x87_p1 = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebp + 0xFFFFFFD0u); x87_p3 = x87_p2;
    x87_p3 = (x87_p3) * (((double)*(float*)(cpu->ebp + 0x2Cu)));
    x87_p0 = x87_p0 + x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x34u);
    x87_p4 = (double)*(float*)(cpu->ebp + 0xFFFFFFD4u); x87_p5 = x87_p4;
    lift_push32(cpu, 0x40u);
    x87_p3 = x87_p3 * x87_p5; 
    cpu->edi = cpu->ebx + 0x1E8u;
    std::swap(x87_p4, x87_p0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebp + 0x38u)));
    *(float*)(cpu->ebx + 0x228u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x40u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p4 = (double)*(float*)(cpu->ebp + 0x3Cu);
    x87_p4 = (x87_p4) * (x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p4 = (double)*(float*)(cpu->ebp + 0x44u);
    x87_p4 = (x87_p4) * (x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebp + 0x48u)));
    *(float*)(cpu->ebx + 0x22Cu) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x50u);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->ebp + 0x4Cu)));
    x87_p1 = x87_p1 + x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebp + 0x54u);
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->ebp + 0x58u)));
    *(float*)(cpu->ebx + 0x230u) = x87_p0; 
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41E0BDu));
    lift_push32(cpu, 0x40u);
    cpu->eax = cpu->ebx + 0x234u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41E0CDu));
    x87_p0 = 0.0;
    *(float*)(cpu->esi + 0x30u) = x87_p0;
    cpu->esp += 0x18u;
    *(float*)(cpu->esi + 0x34u) = x87_p0;
    lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esi + 0x38u) = x87_p0; 
    cpu->eax = cpu->ebp + 0x2Cu;
    x87_p0 = (double)*(float*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = x87_p0; 
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->esi + 0xCu) = (double)*(float*)(cpu->esi + 0x30u);
    *(float*)(cpu->esi + 0x30u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->esi + 0x1Cu);
    *(float*)(cpu->esi + 0x1Cu) = (double)*(float*)(cpu->esi + 0x34u);
    *(float*)(cpu->esi + 0x34u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->esi + 0x2Cu);
    *(float*)(cpu->esi + 0x2Cu) = (double)*(float*)(cpu->esi + 0x38u);
    *(float*)(cpu->esi + 0x38u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->esi + 4u);
    *(float*)(cpu->esi + 4u) = (double)*(float*)(cpu->esi + 0x10u);
    *(float*)(cpu->esi + 0x10u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->esi + 8u);
    *(float*)(cpu->esi + 8u) = (double)*(float*)(cpu->esi + 0x20u);
    *(float*)(cpu->esi + 0x20u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    *(float*)(cpu->ebp + 0xFFFFFFE4u) = (double)*(float*)(cpu->esi + 0x18u);
    *(float*)(cpu->esi + 0x18u) = (double)*(float*)(cpu->esi + 0x24u);
    *(float*)(cpu->esi + 0x24u) = (double)*(float*)(cpu->ebp + 0xFFFFFFE4u);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41E152u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->ebx + 0x234u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41E163u));
    x87_p0 = 0.0;
    *(float*)(cpu->ebx + 0x1F4u) = x87_p0;
    *(float*)(cpu->ebx + 0x204u) = x87_p0;
    *(float*)(cpu->ebx + 0x214u) = x87_p0;
    *(float*)(cpu->ebx + 0x240u) = x87_p0;
    *(float*)(cpu->ebx + 0x250u) = x87_p0;
    *(float*)(cpu->ebx + 0x260u) = x87_p0; 
label_0001E18E:
    cpu->esp = cpu->ebp + 0xFFFFFFB4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp + 0x70u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E1B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x410u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == cpu->edi) goto label_0001E1E0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x41E1C3u));
    if (cpu->eax != 0u) goto label_0001E1DA;
    cpu->edx = cpu->edi + 0x23u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CheckFiles.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1E1DAu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1E1DAu));
    label_0001E1DA:
    *(uint32_t*)(cpu->esi + 0x410u) = cpu->edi;
    label_0001E1E0:
    *(uint32_t*)(cpu->esi + 0x404u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x37A4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x37A8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x37ACu) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x37B0u) = 1u;
    *(uint32_t*)(cpu->esi + 0x37B4u) = 0xFFFFFFFFu;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x37A4u);
    if ((int32_t)cpu->eax < (int32_t)0x64u) goto label_0001E231;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001E231:
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x84u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + cpu->ecx + 0x414u;
    label_0001E243:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    ++cpu->edx;
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0001E243;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x37A4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x84u);
    cpu->esi = cpu->eax + cpu->ecx + 0x454u;
    label_0001E264:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    ++cpu->edx;
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0001E264;
    ++*(uint32_t*)(cpu->ecx + 0x37A4u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx=0u;
    label_0001E282:
    cpu->eax = cpu->edx;
    cpu->eax >>= 1u;
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_0001E290;
    cpu->eax ^= 0xEDB88320u;
    label_0001E290:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E29D;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E29F;
    label_0001E29D:
    cpu->eax >>= 1u;
    label_0001E29F:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2AC;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2AE;
    label_0001E2AC:
    cpu->eax >>= 1u;
    label_0001E2AE:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2BB;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2BD;
    label_0001E2BB:
    cpu->eax >>= 1u;
    label_0001E2BD:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2CA;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2CC;
    label_0001E2CA:
    cpu->eax >>= 1u;
    label_0001E2CC:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2D9;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2DB;
    label_0001E2D9:
    cpu->eax >>= 1u;
    label_0001E2DB:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2E8;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2EA;
    label_0001E2E8:
    cpu->eax >>= 1u;
    label_0001E2EA:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2F7;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2F9;
    label_0001E2F7:
    cpu->eax >>= 1u;
    label_0001E2F9:
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = cpu->eax;
    ++cpu->edx;
    if ((int32_t)(cpu->edx) < (int32_t)(0x100u)) goto label_0001E282;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->edx == 0u) goto label_0001E341;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x400u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    label_0001E324:
    cpu->edi = (int8_t)(*(uint8_t*)(cpu->esi));
    cpu->edi ^= cpu->eax;
    cpu->edi&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    ++cpu->esi;
    --cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x400u) = cpu->eax;
    if (cpu->edx != 0u) goto label_0001E324;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0001E341:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_0001E360:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E360;
    cpu->eax -= cpu->esi;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)cpu->eax > (int32_t)4u) goto label_0001E374;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001E374:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFFu));
    if ((cpu->ecx & 0xFFu) == 0x6Cu) goto label_0001E382;
    if ((cpu->ecx & 0xFFu) != 0x4Cu) goto label_0001E3AD;
    label_0001E382:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFEu));
    if ((cpu->ecx & 0xFFu) == 0x64u) goto label_0001E390;
    if ((cpu->ecx & 0xFFu) != 0x44u) goto label_0001E3AD;
    label_0001E390:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFDu));
    if ((cpu->ecx & 0xFFu) == 0x6Du) goto label_0001E39E;
    if ((cpu->ecx & 0xFFu) != 0x4Du) goto label_0001E3AD;
    label_0001E39E:
    if (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFCu) != 0x2Eu) goto label_0001E3AD;
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001E3AD:
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x10004u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E3CAu)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x41E3CAu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10008u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 0x400u) = 0u;
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x41E3F5u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi != 0xFFFFFFFFu) goto label_0001E409;
    cpu->eax = 0u;
    goto label_0001E464;
    label_0001E409:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x41E40Bu));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1001Cu);
    cpu->esp += 4u;
    if ((int32_t)cpu->edi <= (int32_t)cpu->eax) goto label_0001E423;
    cpu->edi = cpu->eax;
    label_0001E423:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x41E42Au));
    cpu->esp += 0xCu;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0001E446;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E439u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_0001E463;
    label_0001E446:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E453u)); sfera_sub_0041E310(cpu, LIFT_CODE_TOKEN_VA(0x41E453u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E454u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x400u);
    cpu->esp += 4u;
    label_0001E463:
    cpu->edi = lift_pop32(cpu);
    label_0001E464:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10004u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x10004u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E48Au)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x41E48Au));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10008u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    cpu->ebx = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x41E4ADu));
    cpu->ebp = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->ebp != 0xFFFFFFFFu) goto label_0001E4C1;
    cpu->eax = 0u;
    goto label_0001E532;
    label_0001E4C1:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x41E4C3u));
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    if ((int32_t)cpu->edi <= (int32_t)0x10000u) goto label_0001E4DB;
    cpu->edi = 0x10000u;
    label_0001E4DB:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x41E4E2u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0001E4FE;
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E4F1u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_0001E531;
    label_0001E4FE:
    cpu->eax = cpu->esp + 0x10u;
    if (cpu->edi == 0u) goto label_0001E525;
    label_0001E510:
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->ecx ^= cpu->esi;
    cpu->ecx&=0xFFu;
    cpu->esi = (int32_t)(cpu->esi) >> 8u;
    cpu->esi ^= *(uint32_t*)(cpu->ebx + (cpu->ecx * 4u));
    ++cpu->eax;
    if ((--cpu->edi) != 0u) goto label_0001E510;
    label_0001E525:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E526u));
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    label_0001E531:
    cpu->edi = lift_pop32(cpu);
    label_0001E532:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10004u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x330u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x338u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x340u);
    cpu->esi = cpu->esp + 0x138u;
    lift_push32(cpu, cpu->edi);
    cpu->esi -= cpu->ecx;
    label_0001E583:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0001E583;
    cpu->edx = cpu->eax;
    (void)cpu;
    label_0001E590:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E590;
    cpu->edi = cpu->esp + 0x13Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0001E5A1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0001E5A1;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x140u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41E5C6u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    cpu->ebp = 0u;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_0001E673;
    label_0001E5E0:
    if (((*(uint8_t*)(cpu->esp + 0x14u)) & (0x10u)) != 0u) goto label_0001E65C;
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E5F1u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E65C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x344u);
    cpu->edx = cpu->esp + 0x23Cu;
    cpu->edx -= cpu->eax;
    label_0001E610:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E610;
    cpu->eax = cpu->esp + 0x38u;
    cpu->edx = cpu->eax;
    label_0001E620:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E620;
    cpu->edi = cpu->esp + 0x23Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0001E631:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0001E631;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x23Cu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E65Au)); sfera_sub_0041E480(cpu, LIFT_CODE_TOKEN_VA(0x41E65Au));
    cpu->ebp += cpu->eax;
    label_0001E65C:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41E662u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E5E0;
    label_0001E673:
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41E674u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x340u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x330u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x334u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x33Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x37B4u) > (int32_t)cpu->ebx) goto label_0001E91A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x340u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->esp + 0x23Cu;
    cpu->esi -= cpu->ecx;
    label_0001E6E0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E6E0;
    cpu->esi = cpu->eax;
    label_0001E6F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E6F0;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esp + 0x240u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0001E702:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((uint8_t)(cpu->ecx) != (uint8_t)(cpu->ebx)) goto label_0001E702;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x244u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41E729u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0x37B8u) = 1u;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0001E90E;
    label_0001E750:
    if (((*(uint8_t*)(cpu->esp + 0x18u)) & (0x10u)) != 0u) goto label_0001E8F7;
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E765u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E8F7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x348u);
    cpu->edx = cpu->esp + 0x140u;
    cpu->edx -= cpu->eax;
    label_0001E786:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E786;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->esi = cpu->eax;
    label_0001E796:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E796;
    cpu->edi = cpu->esp + 0x140u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0001E7A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((uint8_t)(cpu->ecx) != (uint8_t)(cpu->ebx)) goto label_0001E7A7;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    lift_push32(cpu, 0x110u);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x41E7C2u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0x408u) = cpu->eax;
    if (cpu->eax == cpu->ebx) goto label_0001E98A;
    cpu->eax = cpu->esp + 0x140u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E7E8u)); sfera_sub_0041E350(cpu, LIFT_CODE_TOKEN_VA(0x41E7E8u));
    cpu->ecx = cpu->eax & 0xFFu;
    cpu->ecx = -cpu->ecx;
    cpu->ecx = (cpu->ecx != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ecx &= 0xFFFF0400u;
    cpu->ecx += 0x10000u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x144u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E80Bu)); sfera_sub_0041E3C0(cpu, LIFT_CODE_TOKEN_VA(0x41E80Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ecx + 0x108u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->edx + 0x10Cu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    lift_push32(cpu, 0xFFu);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41E83Bu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint8_t*)(cpu->eax + 0x106u) = cpu->ebx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x404u);
    cpu->esp += 0xCu;
    if (cpu->esi != cpu->ebx) goto label_0001E879;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ebp + 0x404u) = cpu->eax;
    goto label_0001E8C8;
    label_0001E879:
    *(uint32_t*)(cpu->ebp + 0x40Cu) = cpu->ebx;
    (void)cpu;
    label_0001E880:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E88Eu));
    cpu->esp += 8u;
    if ((int32_t)cpu->eax > 0) goto label_0001E933;
    *(uint32_t*)(cpu->ebp + 0x40Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->ebx) goto label_0001E880;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x40Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x40Cu);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_0001E8C8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x37A8u);
    ++*(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_0001E8EB;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) < (int32_t)cpu->eax) goto label_0001E8EB;
    lift_push32(cpu, 0x3E8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x41E8E1u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0001E8EB:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x37B4u) > (int32_t)cpu->ebx) goto label_0001E90E;
    label_0001E8F7:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41E8FDu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E750;
    label_0001E90E:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41E90Fu));
    cpu->esp += 4u;
    label_0001E918:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0001E91A:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x334u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001E933:
    if (cpu->esi != *(uint32_t*)(cpu->ebp + 0x404u)) goto label_0001E95D;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ebp + 0x404u) = cpu->edx;
    goto label_0001E8C8;
    label_0001E95D:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0001E8C8;
    label_0001E98A:
    *(uint8_t*)(cpu->ebp + 0x37B8u) = cpu->ebx & 0xFFu;
    goto label_0001E918;
}
__declspec(noinline) void sfera_sub_0041EC70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x410u);
    if (cpu->eax != 0u) goto label_0001EC80;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001EC80:
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x41EC85u));
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp) != 0x103u);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041ECA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37B0u) >= (int32_t)0u) goto label_0001ECB5;
    label_0001ECAD:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001ECB5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x410u);
    if (cpu->eax == 0u) goto label_0001ECAD;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x41ECC5u));
    if (cpu->eax != 0u) goto label_0001ECDE;
    cpu->edx = 0x191u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CheckFiles.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1ECDEu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1ECDEu));
    label_0001ECDE:
    if (*(uint32_t*)(cpu->esp + 4u) != 0x103u) goto label_0001ECEF;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001ECEF:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x37A4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_0001ED05;
    *(uint32_t*)(cpu->esi + 0x37A4u) = cpu->ecx;
    label_0001ED05:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37A4u) <= (int32_t)cpu->eax) goto label_0001ED35;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = cpu->esi + 0x494u;
    lift_push32(cpu, cpu->edi);
    label_0001ED20:
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = cpu->edi;
    ++cpu->eax;
    cpu->ecx += 0x84u;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x37A4u)) goto label_0001ED20;
    cpu->edi = lift_pop32(cpu);
    label_0001ED35:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041ED40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x120u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x124u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x130u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37B0u) >= (int32_t)cpu->ebp) goto label_0001ED7C;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0001F02A;
    label_0001ED7C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x37A4u);
    *(uint32_t*)(cpu->esi + 0x37A8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->eax <= (int32_t)cpu->edx) goto label_0001ED94;
    *(uint32_t*)(cpu->esi + 0x37A4u) = cpu->edx;
    label_0001ED94:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37A4u) <= (int32_t)cpu->ebp) goto label_0001F028;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x414u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_0001EDC0:
    cpu->ebx = cpu->edi + 0x40u;
    *(uint32_t*)(cpu->esi + 0x404u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37B4u) > (int32_t)cpu->ebp) goto label_0001EFFA;
    lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"xupdate"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x41EDDDu));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0001EE66;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0001EDF0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EDF0;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0001EE83;
    (void)cpu;
    label_0001EE00:
    lift_push32(cpu, 0x3Bu); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_strchr_address32(), LIFT_CODE_TOKEN_VA(0x41EE03u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp == 0u) goto label_0001EE63;
    cpu->edi = cpu->ebp;
    cpu->edi -= cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41EE1Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + cpu->edi + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41EE3Cu)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_VA(0x41EE3Cu));
    cpu->eax = cpu->ebp + 1u;
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->eax;
    label_0001EE43:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EE43;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_0001EE52:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EE52;
    cpu->eax -= cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax != 0u) goto label_0001EE00;
    goto label_0001EE83;
    label_0001EE63:
    lift_push32(cpu, cpu->ebx);
    goto label_0001EE7B;
    label_0001EE66:
    lift_push32(cpu, (uintptr_t)"sphere.exe"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->edi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41EE76u)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_VA(0x41EE76u));
    lift_push32(cpu, (uintptr_t)"sphereclient.exe");
    label_0001EE7B:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1EE83u)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x1EE83u));
    label_0001EE83:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x404u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x408u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_0001EFE4;
    label_0001EEB0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x408u);
    cpu->eax += 8u;
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_0001EEC0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EEC0;
    cpu->eax = cpu->esp + 0x2Cu;
    cpu->ebx = 0u;
    cpu->edx = cpu->eax + 1u;
    label_0001EED3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EED3;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0001EF0D;
    label_0001EEE0:
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->esp + cpu->ebx + 0x2Cu));
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::tolower), LIFT_CODE_TOKEN_VA(0x41EEE6u));
    *(uint8_t*)(cpu->esp + cpu->ebx + 0x30u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x30u;
    cpu->esp += 4u;
    ++cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_0001EF00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EF00;
    cpu->eax -= cpu->edx;
    if (cpu->ebx < cpu->eax) goto label_0001EEE0;
    label_0001EF0D:
    cpu->eax = cpu->esp + 0x2Cu;
    cpu->edx = cpu->eax + 1u;
    label_0001EF14:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EF14;
    cpu->eax -= cpu->edx;
    cpu->ecx = cpu->eax + 1u;
    cpu->edx = cpu->esp + 0x2Cu;
    if (cpu->ecx == 0u) goto label_0001EF4B;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    label_0001EF30:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebx ^= cpu->eax;
    cpu->ebx&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebx * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EF30;
    label_0001EF4B:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->ecx = 4u;
    cpu->edx = cpu->ebx + 0x108u;
    label_0001EF62:
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebp ^= cpu->eax;
    cpu->ebp&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebp * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EF62;
    cpu->ecx = 4u;
    cpu->edx = cpu->ebx + 0x10Cu;
    label_0001EF90:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebx ^= cpu->eax;
    cpu->ebx&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebx * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EF90;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40Cu);
    if (cpu->eax == 0u) goto label_0001EFBF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EFB6u));
    cpu->esp += 4u;
    label_0001EFBF:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x37B4u) == 0u; sub_pred[1] = (int32_t)(*(uint32_t*)(cpu->esi + 0x37B4u)) < (int32_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x408u);
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->eax;
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_0001EFE4;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x408u) = cpu->edx;
    if (cpu->edx != 0u) goto label_0001EEB0;
    label_0001EFE4:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40Cu);
    cpu->ebp = 0u;
    if (cpu->eax == cpu->ebp) goto label_0001EFFA;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EFF1u));
    cpu->esp += 4u;
    label_0001EFFA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = cpu->ecx;
    ++cpu->eax;
    cpu->edi += 0x84u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x37A4u)) goto label_0001EDC0;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001F028:
    cpu->eax = 0u;
    label_0001F02A:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x120u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x37B0u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x37B4u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x410u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F06Eu)); sfera_sub_0041E280(cpu, LIFT_CODE_TOKEN_VA(0x41F06Eu));
    cpu->eax = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::Sleep);
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::GetExitCodeThread);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x37B4u) = 1u;
    label_0001F0A0:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x410u);
    if (cpu->eax == 0u) goto label_0001F0C5;
    cpu->ecx = cpu->esp + 0xCu;

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetExitCodeThread)))(cpu->eax, cpu->ecx);
    if (*(uint32_t*)(cpu->esp + 0xCu) != 0x103u) goto label_0001F0C5;

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x3E8u);
    goto label_0001F0A0;
    label_0001F0C5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F0D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 4u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_check_files_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->esi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->eax)))));
    *(uint32_t*)(cpu->esi + 0x410u) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax != 0u) goto label_0001F0FD;
    cpu->eax = 2u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001F0FD:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetThreadPriority), LIFT_CODE_TOKEN_VA(0x41F100u));
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

























__declspec(noinline) void sfera_sub_00421710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_execution_monitor_runtime;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0xDu) == 0u) goto label_0002174A;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x44u;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x42172Eu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x421743u));
    cpu->edi = lift_pop32(cpu);
    label_0002174A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x418u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebp + 0x4000u) != cpu->esi) goto label_00022253;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x4014u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42202Eu));
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42203Eu));
    *(uint32_t*)(cpu->ebp + 0x4008u) = 0xFFFFFFFFu;
    cpu->eax = 0x5C63626Du;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->esp += 0x18u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    cpu->ebx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    label_00022075:
    if (*(uint8_t*)(cpu->ebx) == 0u) goto label_00022105;
    cpu->eax = 0u;
    label_00022080:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x24u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022080;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->ebx;
    label_00022091:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022091;
    cpu->edi = cpu->esp + 0x24u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_000220A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000220A0;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x24u;
    --cpu->eax;
    label_000220C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000220C0;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((int32_t)cpu->esi <= 0) goto label_00022105;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_00022105:
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->ebx += 0x8D8u;
    if ((int32_t)cpu->ebx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022075;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_00022251;
    lift_push32(cpu, 0x6Fu);
    cpu->ecx = cpu->eax * 8u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42213Du)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x42213Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x70u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    *(uint32_t*)(cpu->ebp + 0x4000u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422153u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x422153u));
    cpu->edx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    *(uint32_t*)(cpu->ebp + 0x4004u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    label_00022166:
    if (*(uint8_t*)(cpu->edx) == 0u) goto label_0002223B;
    cpu->eax = 0u;
    label_00022171:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x24u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022171;
    cpu->eax = cpu->edx;
    label_00022180:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022180;
    cpu->edi = cpu->esp + 0x24u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00022190:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00022190;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x24u;
    --cpu->eax;
    label_000221B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000221B0;
    cpu->ecx = 0x6264612Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((cpu->esi==0u) || (((cpu->esi)&0x80000000u)!=0u)) goto label_00022237;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esi;
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebx + cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx >>= 2u;
    *(uint32_t*)(cpu->ebx + cpu->eax + 4u) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ebx + cpu->ecx + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4004u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->ebx += 8u;
    label_00022237:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0002223B:
    cpu->edx += 0x8D8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022166;
    label_00022251:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00022253:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (*(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) == cpu->eax) goto label_000223D2;
    if (*(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag)) == 3u) goto label_000223D2;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int16_t)((uint16_t)(cpu->eax)) >= (int16_t)(*(uint16_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)))) goto label_000223D2;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids);
    cpu->edx = cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    (void)cpu;
    label_000222C0:
    cpu->eax = *(uint16_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->eax * 4u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00022380;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4000u);
    cpu->edi = *(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi += *(uint32_t*)(cpu->ebp);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if ((int32_t)cpu->edx <= 0) goto label_00022380;
    cpu->ebp = cpu->eax * 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    label_00022300:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4004u);
    cpu->esi = *(uint32_t*)(cpu->eax + cpu->ebp);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    cpu->ebp += 8u;
    if (*(uint32_t*)(cpu->esi + cpu->edi) == 0xDEEDDEEDu) goto label_00022344;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + cpu->edi) = 0xDEEDDEEDu;
    cpu->eax = *(uint16_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42233Du)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x42233Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022344:
    if (*(uint8_t*)(cpu->ebx + cpu->edi) == 0xDEu) goto label_00022372;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->ebx + cpu->edi) = 0xDEu;
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42236Bu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x42236Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022372:
    --*(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != 0u) goto label_00022300;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00022380:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = (int16_t)(*(uint16_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->ecx += 2u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000222C0;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x18u) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000223D2;
    if (*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error == 0u) goto label_000223D2;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4223C0u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x4223C0u));
    cpu->ecx = (uintptr_t)"Memory Error! See at Warnings.log";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4223CAu)); sfera_sub_0044C0A0(cpu, LIFT_CODE_TOKEN_VA(0x4223CAu));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x223CCu));
    label_000223D2:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004223E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x4008u);
    if (cpu->esi == 0xFFFFFFFFu) goto label_000225DB;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->eax * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->edi + (cpu->ecx * 4u));
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_00022431;
    cpu->edx = 0xF5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x22431u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x22431u));
    label_00022431:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4000u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4010u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = cpu->eax + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->edx * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset));
    cpu->ebx += *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    label_00022460:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x4004u);
    cpu->ebp = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 4u);
    cpu->ecx += 2u;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + cpu->ebp) == 0xDEEDDEEDu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (sub_pred[0]) goto label_000224BB;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + cpu->ebp) = 0xDEEDDEEDu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->eax * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4224B0u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x4224B0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224BB:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) == 0xDEu) goto label_000224F4;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + cpu->ebx) = 0xDEu;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0x2D4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4224EDu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x4224EDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224F4:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    ++*(uint32_t*)(cpu->edi + 0x4010u);
    if (*(uint32_t*)(cpu->edi + 0x4010u) != cpu->edx) goto label_000225A3;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->edi + 0x4010u) = cpu->edx;
    label_00022520:
    ++cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x400Cu) = cpu->ecx;
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    if (cpu->ecx != cpu->eax) goto label_0002256A;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x4008u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->edi + 0x400Cu) = cpu->edx;
    label_00022540:
    sub_pred[1] = cpu->eax == (uint32_t)(g_sfera_mbc_runtime->process_chain_last);
    cpu->eax = g_sfera_mbc_runtime->process_chain_first;
    if (sub_pred[1]) goto label_00022550;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    label_00022550:
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    *(uint32_t*)(cpu->edi + 0x4008u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag)) == 3u) goto label_00022540;
    label_0002256A:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u) + 0x2D4u);
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->eax * 4u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00022520;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 0x324u);
    cpu->ebx += *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ecx = cpu->eax;
    label_000225A3:
    if ((--*(uint32_t*)(cpu->esp + 0x24u)) != 0u) goto label_00022460;
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x14u) == 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[2]) goto label_000225DB;
    if (*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error == 0u) goto label_000225DB;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4225C9u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x4225C9u));
    cpu->ecx = (uintptr_t)"Memory Error! See at Warnings.log";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4225D3u)); sfera_sub_0044C0A0(cpu, LIFT_CODE_TOKEN_VA(0x4225D3u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x225D5u));
    label_000225DB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004225F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) == 0xFFFFFFFFu) goto label_00022611;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_00022611:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422620(LiftCpu* cpu, uint32_t stop_address) {
    *(uint32_t*)(cpu->ecx + 0x4008u) = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->ecx + 0x4008u)) goto label_0002265D;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) == 0xFFFFFFFFu) goto label_0002265D;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_0002265D:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x4008u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000226AF;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += *(uint32_t*)(cpu->ecx + 0x400Cu);
    cpu->eax = *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if (cpu->edx != cpu->eax) goto label_000226AF;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) == 0xFFFFFFFFu) goto label_000226AF;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_000226AF:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004226C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x414u;
    cpu->eax = 0x5C63626Du;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ebx = 0u;
    cpu->edx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    label_00022700:
    if (*(uint8_t*)(cpu->edx) == 0u) goto label_000228CC;
    if (*(uint32_t*)(cpu->ebp + (cpu->ebx * 4u)) == 0xFFFFFFFFu) goto label_000228CC;
    cpu->eax = 0u;
    label_00022716:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x18u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x20u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022716;
    cpu->eax = cpu->edx;
    label_00022725:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022725;
    cpu->edi = cpu->esp + 0x20u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00022733:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00022733;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x20u;
    --cpu->eax;
    label_00022750:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022750;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((cpu->esi!=0u) && (((cpu->esi)&0x80000000u)==0u)) goto label_0002278F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42278Au)); sfera_sub_00422660(cpu, LIFT_CODE_TOKEN_VA(0x42278Au));
    goto label_000228CC;
    label_0002278F:
    cpu->edx = *(uint32_t*)(cpu->ebp + (cpu->ebx * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->ecx = cpu->esi;
    cpu->ecx >>= 3u;
    if (cpu->ecx == *(uint32_t*)(cpu->eax + (cpu->edx * 8u))) goto label_000227B0;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227ABu)); sfera_sub_00422660(cpu, LIFT_CODE_TOKEN_VA(0x4227ABu));
    goto label_000228CC;
    label_000227B0:
    lift_push32(cpu, 0x19Au);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4227C1u));
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x20u;
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->edx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4004u);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    cpu->edx = cpu->ebx;
    if (cpu->esi < 4u) goto label_00022817;
    label_00022803:
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_0002281F;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if (cpu->esi >= 4u) goto label_00022803;
    label_00022817:
    if (cpu->esi == 0u) goto label_000228B7;
    label_0002281F:
    cpu->eax = *(uint8_t*)(cpu->edx);
    cpu->edi = *(uint8_t*)(cpu->ecx);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 1u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 1u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 1u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 2u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 2u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 2u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 3u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 3u);
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->eax -= cpu->ecx;
    label_0002285E:
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->eax|=1u;
    if (cpu->eax==0u) goto label_000228B7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4008u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000228B7;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0x400Cu);
    cpu->eax = *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if (cpu->edx != cpu->eax) goto label_000228B7;
    cpu->ecx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ebp + (cpu->ecx * 4u)) == 0xFFFFFFFFu) goto label_000228B7;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ebp + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x4010u) = cpu->eax;
    label_000228B7:
    lift_push32(cpu, 0x1A1u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4228C8u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4228C8u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000228CC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += 0x8D8u;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022700;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}



















__declspec(noinline) void sfera_sub_00425940(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_00496F00(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00425950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x144u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x42596Cu));
    cpu->esi = cpu->eax;
    cpu->edi = 0u;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00025997;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::FindNextFileA);
    label_00025982:
    if (((*(uint8_t*)(cpu->esp + 0xCu)) & (0x10u)) != 0u) goto label_0002598A;
    ++cpu->edi;
    label_0002598A:
    cpu->ecx = cpu->esp + 0xCu;

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::FindNextFileA)))(cpu->esi, cpu->ecx);
    if (cpu->eax != 0u) goto label_00025982;
    cpu->ebp = lift_pop32(cpu);
    label_00025997:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x425998u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x144u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00425BF0(LiftCpu* cpu, uint32_t stop_address) {
    if ((int32_t)cpu->ecx >= (int32_t)1u) goto label_00025BF8;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00025BF8:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_effect_manager.render_index_buffer;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_effect_manager.render_sort_indices;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_effect_manager.render_batch_buffer;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425CF0(LiftCpu* cpu, uint32_t stop_address) {
    const auto* parameters = reinterpret_cast<const SferaEffectParameter*>(static_cast<uintptr_t>(cpu->edx)); cpu->eax = g_sfera_effect_manager.setEffectParameters(cpu->ecx, parameters, *(uint32_t*)(cpu->esp + 4u)) ? 1u : 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425D30(LiftCpu* cpu, uint32_t stop_address) {
    const char* script_name = reinterpret_cast<const char*>(static_cast<uintptr_t>(cpu->ecx));
    cpu->eax = static_cast<uint32_t>(g_sfera_effect_manager.findDefinitionId(script_name));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004261B0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_effect_manager.effects_enabled = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
} // namespace lifted
