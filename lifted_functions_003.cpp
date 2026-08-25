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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C5DDu)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x41C5DDu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C692u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x41C692u));
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
__declspec(noinline) void sfera_sub_0041C6C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[6]; double x87_p0, x87_p1, x87_p2, x87_p3;
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
    { double temporary = x87_p2; x87_p2 = x87_p1; x87_p1 = temporary; }
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
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left<lift_right)) goto label_0001C7BF; }
    cpu->fpu[0u] = cpu->fpu[0u]; 
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 0xCu);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); goto label_0001C7C1;
    label_0001C7BF:
    cpu->fpu[1u] = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); label_0001C7C1:
    x87_p0 = 1.0;
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left<lift_right)) goto label_0001C7DC; }
    cpu->fpu[1u] = cpu->fpu[0u]; 
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 0xCu);
    cpu->esp += 8u;
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001C7DC:
    cpu->fpu[0u] = cpu->fpu[0u]; 
    cpu->esp += 8u;
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 8u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C864u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x41C864u));
    cpu->edx = cpu->ebp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C86Fu)); sfera_sub_0041B5B0(cpu, LIFT_CODE_TOKEN_VA(0x41C86Fu));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0001CC77;
    x87_v0 = (double)*(float*)(cpu->ebp + 0x30u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C8EEu)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x41C8EEu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C949u)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x41C949u));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1CA00u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_RVA(0x1CA00u));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1CA73u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_RVA(0x1CA73u));
    label_0001CA73:
    cpu->esi = 0u;
    if (((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03) == cpu->esi) || ((int32_t)((uint32_t)(g_sfera_client_main_scalar_runtime.counter_03)) < (int32_t)(cpu->esi))) goto label_0001CAA6;
    label_0001CA80:
    if (*(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) != 1u) goto label_0001CA9D;
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    lift_push32(cpu, 0x4B8u);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1CA9Du)); sfera_sub_00460110(cpu, LIFT_CODE_TOKEN_RVA(0x1CA9Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CAE8u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x41CAE8u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CB6Du)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x41CB6Du));
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->esi <<= 6u;
    cpu->esi += *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = cpu->edi + 0x228u;
    x87_v0 = (double)*(float*)(cpu->esi + 0x30u);
    cpu->ecx = cpu->ebp + 0x30u;
    *(float*)(cpu->edx) = x87_v0; 
    *(float*)(cpu->edi + 0x22Cu) = (double)*(float*)(cpu->esi + 0x34u);
    *(float*)(cpu->edi + 0x230u) = (double)*(float*)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41CB9Bu)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x41CB9Bu));
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
__declspec(noinline) void sfera_sub_0041CDA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x150u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x164u;
    (void)0; /* source SEH registration eliminated */
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D0CAu)); sfera_sub_004815D0(cpu, LIFT_CODE_TOKEN_VA(0x41D0CAu));
    cpu->ecx = (uintptr_t)"xadd\\subobjs.dat";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D0D4u)); sfera_sub_00482170(cpu, LIFT_CODE_TOKEN_VA(0x41D0D4u));
    cpu->edx = (uintptr_t)"subobjs";
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D0E4u)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x41D0E4u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D163u)); sfera_sub_00481300(cpu, LIFT_CODE_TOKEN_VA(0x41D163u));
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"s";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D17Au)); sfera_sub_00481180(cpu, LIFT_CODE_TOKEN_VA(0x41D17Au));
    if (cpu->eax == 0u) goto label_0001D36E;
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"m";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D193u)); sfera_sub_00481180(cpu, LIFT_CODE_TOKEN_VA(0x41D193u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D237u)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x41D237u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D266u)); sfera_sub_004812A0(cpu, LIFT_CODE_TOKEN_VA(0x41D266u));
    if (cpu->eax == 0u) goto label_0001D36E;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi += cpu->ebp;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D281u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x41D281u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D33Fu)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x41D33Fu));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebp < (int32_t)1u) goto label_0001D36E;
    cpu->edi = 0u;
    cpu->ebx = cpu->esi + 0x74D4u;
    label_0001D350:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebp) goto label_0001D381;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edx = (uintptr_t)"womanhelmsmall";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D364u)); sfera_sub_00481200(cpu, LIFT_CODE_TOKEN_VA(0x41D364u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D386u)); sfera_sub_004815C0(cpu, LIFT_CODE_TOKEN_VA(0x41D386u));
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x164u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x15Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041D3C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D43Au)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x41D43Au));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D46Cu)); sfera_sub_0041C6C0(cpu, LIFT_CODE_TOKEN_VA(0x41D46Cu));
    *(float*)(cpu->ebp + 0xFFFFFFE8u) = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); { const double lift_left=(double)0.0010000000474974513f; const double lift_right=((double)*(float*)(cpu->ebp + 0xFFFFFFE8u)); if (!(lift_left>lift_right)) goto label_0001D48C; }
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D487u)); sfera_sub_0041C7F0(cpu, LIFT_CODE_TOKEN_VA(0x41D487u));
    goto label_0001E18E;
    label_0001D48C:
    x87_p0 = (double)*(float*)(cpu->ebp + 0x2Cu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D500u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x41D500u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D55Bu)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x41D55Bu));
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
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
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
    std::memmove(cpu->fpu + 3, cpu->fpu, 5u * sizeof(double)); cpu->fpu[0u] = x87_p2; cpu->fpu[1u] = x87_p1; cpu->fpu[2u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[2u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->fpu[1u]=cpu->fpu[0u]; std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if (lift_left==lift_right) goto label_0001D68D; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->fpu[0u] = cpu->fpu[0u]; 
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D68Bu)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x41D68Bu));
    cpu->fpu[0u] = 1.0;
    label_0001D68D:
    x87_p0 = (double)*(float*)(cpu->ebx + 0x148u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x4F46u));
    lift_cmp[0]=x87_p0==cpu->fpu[0u];  
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); if ((cpu->ecx & 0xFFu) == 0u) goto label_0001D731;
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x80u); lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41D9A6u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x41D9A6u));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1DA14u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_RVA(0x1DA14u));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1DE23u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_RVA(0x1DE23u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1DE60u)); sfera_sub_00460110(cpu, LIFT_CODE_TOKEN_RVA(0x1DE60u));
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
    { double temporary = x87_p3; x87_p3 = x87_p0; x87_p0 = temporary; }
    x87_p2 = x87_p2 + x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebp + 0x34u);
    x87_p4 = (double)*(float*)(cpu->ebp + 0xFFFFFFD4u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    { double temporary = x87_p4; x87_p4 = x87_p2; x87_p2 = temporary; }
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
    { double temporary = x87_p2; x87_p2 = x87_p1; x87_p1 = temporary; }
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
    { double temporary = x87_p4; x87_p4 = x87_p0; x87_p0 = temporary; }
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
    { double temporary = x87_p4; x87_p4 = x87_p0; x87_p0 = temporary; }
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
__declspec(noinline) void sfera_sub_0041E9A0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 0x11Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x124u);
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x37A4u) == 0u; sub_pred[2] = (int32_t)(*(uint32_t*)(cpu->esi + 0x37A4u)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    if ((sub_pred[0]) || (sub_pred[2])) goto label_0001EC4F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x414u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_0001E9E0:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37B4u) > (int32_t)0u) goto label_0001EC4C;
    lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"xupdate"); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edi + 0x40u;
    *(uint32_t*)(cpu->esi + 0x404u) = 0u;
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x41EA02u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0001EA89;
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_0001EA14:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EA14;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0001EAA6;
    label_0001EA23:
    lift_push32(cpu, 0x3Bu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_strchr_address32(), LIFT_CODE_TOKEN_VA(0x41EA26u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebx == 0u) goto label_0001EA86;
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41EA40u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + cpu->edi + 0x24u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41EA5Fu)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_VA(0x41EA5Fu));
    cpu->eax = cpu->ebx + 1u;
    cpu->edx = cpu->ebp;
    cpu->edx -= cpu->eax;
    label_0001EA66:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EA66;
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_0001EA75:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EA75;
    cpu->eax -= cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax != 0u) goto label_0001EA23;
    goto label_0001EAA6;
    label_0001EA86:
    lift_push32(cpu, cpu->ebp);
    goto label_0001EA9E;
    label_0001EA89:
    lift_push32(cpu, (uintptr_t)"sphere.exe"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->edi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41EA99u)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_VA(0x41EA99u));
    lift_push32(cpu, (uintptr_t)"sphereclient.exe");
    label_0001EA9E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1EAA6u)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x1EAA6u));
    label_0001EAA6:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x404u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x408u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_0001EC04;
    label_0001EAD0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x408u);
    cpu->eax += 8u;
    cpu->edx = cpu->esp + 0x28u;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_0001EAE0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EAE0;
    cpu->eax = cpu->esp + 0x28u;
    cpu->ebx = 0u;
    cpu->edx = cpu->eax + 1u;
    label_0001EAF3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EAF3;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0001EB2D;
    label_0001EB00:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esp + cpu->ebx + 0x28u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::tolower), LIFT_CODE_TOKEN_VA(0x41EB06u));
    *(uint8_t*)(cpu->esp + cpu->ebx + 0x2Cu) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x2Cu;
    cpu->esp += 4u;
    ++cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_0001EB20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EB20;
    cpu->eax -= cpu->edx;
    if (cpu->ebx < cpu->eax) goto label_0001EB00;
    label_0001EB2D:
    cpu->eax = cpu->esp + 0x28u;
    cpu->edx = cpu->eax + 1u;
    label_0001EB34:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EB34;
    cpu->eax -= cpu->edx;
    cpu->ecx = cpu->eax + 1u;
    cpu->edx = cpu->esp + 0x28u;
    if (cpu->ecx == 0u) goto label_0001EB6B;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    label_0001EB50:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebx ^= cpu->eax;
    cpu->ebx&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebx * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EB50;
    label_0001EB6B:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->ecx = 4u;
    cpu->edx = cpu->ebx + 0x108u;
    label_0001EB82:
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebp ^= cpu->eax;
    cpu->ebp&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebp * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EB82;
    cpu->ecx = 4u;
    cpu->edx = cpu->ebx + 0x10Cu;
    label_0001EBB0:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebx ^= cpu->eax;
    cpu->ebx&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebx * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EBB0;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40Cu);
    if (cpu->eax == 0u) goto label_0001EBDF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EBD6u));
    cpu->esp += 4u;
    label_0001EBDF:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x37B4u) == 0u; sub_pred[3] = (int32_t)(*(uint32_t*)(cpu->esi + 0x37B4u)) < (int32_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x408u);
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->eax;
    if ((!sub_pred[1]) && (!sub_pred[3])) goto label_0001EC04;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x408u) = cpu->ecx;
    if (cpu->ecx != 0u) goto label_0001EAD0;
    label_0001EC04:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40Cu);
    if (cpu->eax == 0u) goto label_0001EC18;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EC0Fu));
    cpu->esp += 4u;
    label_0001EC18:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x400u);
    *(uint32_t*)(cpu->edi + 0x80u) = cpu->edx;
    if (*(uint8_t*)(cpu->esi + 0x37B8u) == 0u) goto label_0001EC4C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->eax;
    cpu->edi += 0x84u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x37A4u)) goto label_0001E9E0;
    label_0001EC4C:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001EC4F:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x11Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x1F0B2u), LIFT_CODE_TOKEN_RVA(0x1F0B0u))) { return; }
    if (*(uint32_t*)(cpu->esp + 0xCu) != 0x103u) goto label_0001F0C5;
    lift_push32(cpu, 0x3E8u);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x1F0C3u), LIFT_CODE_TOKEN_RVA(0x1F0C1u))) { return; }
    goto label_0001F0A0;
    label_0001F0C5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F0D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0041E9A0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x41F0E5u));
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
__declspec(noinline) void sfera_sub_0041F110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->ebp) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_0001F1B3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->esi = cpu->edi;
    label_0001F140:
    if ((int32_t)*(uint32_t*)(cpu->esi) >= (int32_t)cpu->ebx) goto label_0001F156;
    ++cpu->edx;
    cpu->esi += 0x418u;
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_0001F140;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0001F156:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    if ((int32_t)*(uint32_t*)(cpu->eax + cpu->edi) > (int32_t)cpu->ebx) goto label_0001F1B0;
    *(uint32_t*)(cpu->ebp) = cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->edx + 1u;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edi) goto label_0001F18F;
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x418u);
    cpu->esi += *(uint32_t*)(cpu->ecx);
    label_0001F180:
    if ((int32_t)*(uint32_t*)(cpu->esi) > (int32_t)cpu->ebx) goto label_0001F18F;
    ++cpu->eax;
    cpu->esi += 0x418u;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_0001F180;
    label_0001F18F:
    cpu->eax -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->edx <= (int32_t)*(uint32_t*)(cpu->ecx + 4u)) goto label_0001F1B0;
    cpu->edx = 0x40u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1F1B0u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1F1B0u));
    label_0001F1B0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001F1B3:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F1C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax -= *(uint32_t*)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0041F1C0)); lift_push32(cpu, 0x418u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::qsort), LIFT_CODE_TOKEN_VA(0x41F1E1u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F1F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, 0x6Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x418u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F215u)); sfera_sub_0047EA90(cpu, LIFT_CODE_TOKEN_VA(0x41F215u));
    cpu->edx = 0u;
    x87_v0 = (double)1000000.0f;
    *(float*)(cpu->esi + 0x10u) = x87_v0;
    *(float*)(cpu->esi + 8u) = x87_v0; 
    x87_v0 = (double)-1000000.0f;
    *(float*)(cpu->esi + 0x14u) = x87_v0;
    *(float*)(cpu->esi + 0xCu) = x87_v0; 
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edx) goto label_0001F2A5;
    cpu->ecx = cpu->esi + 0x118u;
    label_0001F240:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFF00u); const double lift_left=(double)*(float*)(cpu->esi + 8u); if (!(lift_left>lift_right)) goto label_0001F25B; }
    *(float*)(cpu->esi + 8u) = (double)*(float*)(cpu->ecx + 0xFFFFFF00u);
    label_0001F25B:
    { const double lift_right=(double)*(float*)(cpu->ecx + 0xFFFFFF00u); const double lift_left=(double)*(float*)(cpu->esi + 0xCu); if (!(lift_left<lift_right)) goto label_0001F276; }
    *(float*)(cpu->esi + 0xCu) = (double)*(float*)(cpu->ecx + 0xFFFFFF00u);
    label_0001F276:
    { const double lift_right=(double)*(float*)(cpu->ecx); const double lift_left=(double)*(float*)(cpu->esi + 0x10u); if (!(lift_left>lift_right)) goto label_0001F289; }
    *(float*)(cpu->esi + 0x10u) = (double)*(float*)(cpu->ecx);
    label_0001F289:
    { const double lift_right=(double)*(float*)(cpu->ecx); const double lift_left=(double)*(float*)(cpu->esi + 0x14u); if (!(lift_left<lift_right)) goto label_0001F29C; }
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->ecx);
    label_0001F29C:
    ++cpu->edx;
    cpu->ecx += 4u;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_0001F240;
    label_0001F2A5:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F2B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xC8D4u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41F2BBu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->eax;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F2F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_0001F30E;
    lift_push32(cpu, 0xA6u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F308u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41F308u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_0001F30E:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC0u);
    if (cpu->ecx == 0u) goto label_0001F331;
    lift_push32(cpu, 0xA7u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F327u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41F327u));
    *(uint32_t*)(cpu->esi + 0xC0u) = 0u;
    label_0001F331:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    if (cpu->ecx == 0u) goto label_0001F354;
    lift_push32(cpu, 0xA8u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F34Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41F34Au));
    *(uint32_t*)(cpu->esi + 0xC4u) = 0u;
    label_0001F354:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F360(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"landscape\\contours.bin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F371u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x41F371u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->ebx + 4u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F37Fu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x41F37Fu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0xB2u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F397u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41F397u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F3ACu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x41F3ACu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_0042F180(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0041F3C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_0001F3DD;
    if ((int32_t)cpu->edi < 0) goto label_0001F3DD;
    if ((int32_t)cpu->ebx < (int32_t)0x2710u) goto label_0001F3EC;
    label_0001F3DD:
    cpu->edx = 0xC5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1F3ECu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1F3ECu));
    label_0001F3EC:
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x24u) = cpu->edx;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F420(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    bool lift_cmp[1];
    x87_v0 = 0.0;
    cpu->esp -= 0x30u;
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ebx);
    lift_cmp[0]=x87_v1>x87_v0;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    x87_v0 = x87_v1; 
    if (!lift_cmp[0]) goto label_0001F447;
    { const double lift_left=x87_v0; const double lift_right=200.0; if (lift_left<lift_right) goto label_0001F45C; }
    label_0001F447:
    cpu->edx = 0x28Au;
    x87_v0 = x87_v0; 
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F458u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x41F458u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x44u);
    label_0001F45C:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    x87_v0 = (x87_v0) * (x87_v0);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    if ((int32_t)cpu->edx <= (int32_t)cpu->ebp) goto label_0001F489;
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x38u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    label_0001F472:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->esi < (int32_t)cpu->edi) goto label_0001F480;
    if ((int32_t)cpu->esi > (int32_t)*(uint32_t*)(cpu->ebx + 0x3Cu)) goto label_0001F480;
    cpu->eax += *(uint32_t*)(cpu->ecx + 4u);
    label_0001F480:
    cpu->ecx += 0x418u;
    if ((--cpu->edx) != 0u) goto label_0001F472;
    label_0001F489:
    cpu->edi = cpu->eax * 4u;
    lift_push32(cpu, 0x296u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F4A9u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41F4A9u));
    lift_push32(cpu, 0x297u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F4BCu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41F4BCu));
    lift_push32(cpu, 0x298u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F4D1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41F4D1u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41F4D8u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 4u) <= (int32_t)cpu->ebp) goto label_0001F57C;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi = 0u;
    label_0001F4F1:
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->eax);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebx + 0x38u)) goto label_0001F564;
    if ((int32_t)cpu->ecx > (int32_t)*(uint32_t*)(cpu->ebx + 0x3Cu)) goto label_0001F564;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0x29Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = cpu->edi + cpu->eax + 0x18u;
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + (cpu->ebp * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F529u)); sfera_sub_0047EB20(cpu, LIFT_CODE_TOKEN_VA(0x41F529u));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, 0x29Fu);
    cpu->eax = cpu->edi + cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = cpu->eax + 0x118u;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ecx + (cpu->ebp * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F55Eu)); sfera_sub_0047EB20(cpu, LIFT_CODE_TOKEN_VA(0x41F55Eu));
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ebp += *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    label_0001F564:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->edi += 0x418u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebx + 4u)) goto label_0001F4F1;
    label_0001F57C:
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    x87_v1 = 0.0;
    label_0001F58A:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->ebp) == cpu->edi) goto label_0001F59D;
    label_0001F595:
    ++cpu->edi;
    if (*(uint32_t*)(cpu->ebp + (cpu->edi * 4u)) != 0u) goto label_0001F595;
    label_0001F59D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->edi < (int32_t)cpu->edx) goto label_0001F5C4;
    x87_v0 = x87_v1; 
    cpu->edx = 0x2AAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    x87_v0 = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F5B8u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x41F5B8u));
    x87_v0 = 0.0;
    x87_v1 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_0001F5C4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->ebp + (cpu->edi * 4u)) = 1u;
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edi * 4u));
    x87_v2 = (x87_v2) + (x87_v1);
    cpu->eax = cpu->edi + 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ecx + (cpu->edi * 4u));
    x87_v2 = (x87_v2) + (x87_v1);
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_0001F688;
    cpu->edx = cpu->ebp;
    cpu->edx -= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->edx -= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esi + (cpu->eax * 4u);
    cpu->edx -= cpu->eax;
    label_0001F610:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->eax + cpu->ecx) != 0u) goto label_0001F67E;
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->ecx)));
    *(float*)(cpu->esp + 0x3Cu) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax + (cpu->edi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->eax + cpu->ecx)));
    *(float*)(cpu->esp + 0x38u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x3Cu);
    x87_v3 = (x87_v3) * (x87_v3);
    x87_v4 = x87_v2;
    x87_v2 = x87_v2 * x87_v4; 
    x87_v2 = x87_v2 + x87_v3; 
    *(float*)(cpu->esp + 0x3Cu) = x87_v2; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x3Cu); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0001F67E; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + cpu->ecx) = 1u;
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) + (((double)*(float*)(cpu->eax + cpu->ecx))));
    label_0001F67E:
    cpu->ecx += 4u;
    if ((--cpu->edx) != 0u) goto label_0001F610;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    label_0001F688:
    *(float*)(cpu->esp + 0x3Cu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x3Cu); x87_v4 = x87_v3;
    x87_v2 = x87_v2 / x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    x87_v2 = (((double)*(float*)(cpu->esp + 0x14u))) / (x87_v2);
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    if ((int32_t)cpu->edx <= 0) goto label_0001F6E3;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x44u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->ebp;
    cpu->eax = cpu->ebp;
    cpu->edi -= cpu->ebp;
    cpu->ebp = cpu->edx;
    label_0001F6C4:
    if (*(uint32_t*)(cpu->eax) != 1u) goto label_0001F6D9;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(uint32_t*)(cpu->eax) = 2u;
    *(float*)(cpu->ecx + cpu->eax) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->edi + cpu->eax) = x87_v3;
    label_0001F6D9:
    cpu->eax += 4u;
    if ((--cpu->ebp) != 0u) goto label_0001F6C4;
    x87_v2 = x87_v3; 
    x87_v2 = x87_v2; 
    label_0001F6E3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0001F58A;
    cpu->ebp = 0u;
    x87_v0 = x87_v1; 
    cpu->edi = 0u;
    x87_v0 = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 4u) <= (int32_t)cpu->ebp) goto label_0001F7A6;
    label_0001F710:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebp);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebx + 0x38u)) goto label_0001F78E;
    if ((int32_t)cpu->ecx > (int32_t)*(uint32_t*)(cpu->ebx + 0x3Cu)) goto label_0001F78E;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0x2C8u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax + cpu->ebp + 0x18u;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x100u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + (cpu->edi * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F74Au)); sfera_sub_0047EB20(cpu, LIFT_CODE_TOKEN_VA(0x41F74Au));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, 0x2C9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ecx = cpu->eax + cpu->ebp + 0x118u;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x100u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edx + (cpu->edi * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F77Eu)); sfera_sub_0047EB20(cpu, LIFT_CODE_TOKEN_VA(0x41F77Eu));
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi += *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1F78Eu)); sfera_sub_0041F1F0(cpu, LIFT_CODE_TOKEN_RVA(0x1F78Eu));
    label_0001F78E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->ebp += 0x418u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebx + 4u)) goto label_0001F710;
    label_0001F7A6:
    lift_push32(cpu, 0x2CEu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F7B7u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41F7B7u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, 0x2CFu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F7CAu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41F7CAu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    *(uint32_t*)(cpu->esp + 4u) = 0x2D0u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    sfera_sub_004EB520(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0041F7F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    --cpu->edx;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_0001F818;
    cpu->eax = cpu->edi + 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_0001F820;
    label_0001F818:
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    label_0001F820:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    --cpu->ebx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ebx) goto label_0001F842;
    cpu->ebx = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    goto label_0001F84A;
    label_0001F842:
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    label_0001F84A:
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x106u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x106u);
    cpu->edi += cpu->esi;
    cpu->ebx = cpu->edx + cpu->eax;
    { const double lift_right=(double)*(float*)(cpu->ecx + (cpu->edi * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->ecx + (cpu->ebx * 4u) + 0x18u); if (lift_left!=lift_right) goto label_0001F8BE; }
    { const double lift_right=(double)*(float*)(cpu->ecx + (cpu->edi * 4u) + 0x118u); const double lift_left=(double)*(float*)(cpu->ecx + (cpu->ebx * 4u) + 0x118u); if (lift_left!=lift_right) goto label_0001F8BE; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = cpu->esi + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->ebp * 4u) + 0x18u);
    cpu->eax += cpu->edx;
    x87_v1 = (double)*(float*)(cpu->ecx + (cpu->eax * 4u) + 0x18u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left!=lift_right) goto label_0001F8BE; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->ebp * 4u) + 0x118u);
    cpu->eax += cpu->edx;
    x87_v1 = (double)*(float*)(cpu->ecx + (cpu->eax * 4u) + 0x118u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left==lift_right) goto label_0001F916; }
    label_0001F8BE:
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    { const double lift_right=(double)*(float*)(cpu->ecx + (cpu->edi * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->ecx + (cpu->edx * 4u) + 0x18u); if (lift_left!=lift_right) goto label_0001F922; }
    { const double lift_right=(double)*(float*)(cpu->ecx + (cpu->edi * 4u) + 0x118u); const double lift_left=(double)*(float*)(cpu->ecx + (cpu->edx * 4u) + 0x118u); if (lift_left!=lift_right) goto label_0001F922; }
    cpu->esi += *(uint32_t*)(cpu->esp + 0x18u);
    { const double lift_right=(double)*(float*)(cpu->ecx + (cpu->esi * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->ecx + (cpu->ebx * 4u) + 0x18u); if (lift_left!=lift_right) goto label_0001F922; }
    { const double lift_right=(double)*(float*)(cpu->ecx + (cpu->esi * 4u) + 0x118u); const double lift_left=(double)*(float*)(cpu->ecx + (cpu->ebx * 4u) + 0x118u); if (lift_left!=lift_right) goto label_0001F922; }
    label_0001F916:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0001F922:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F930(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = cpu->ecx;
    if (cpu->ebp == cpu->edi) goto label_0001F94E;
    if (*(uint32_t*)(cpu->esp + 0x18u) == cpu->edi) goto label_0001F94E;
    if (cpu->ebx != cpu->edi) goto label_0001F95D;
    label_0001F94E:
    cpu->edx = 0x35Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1F95Du)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1F95Du));
    label_0001F95D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC0u);
    if (cpu->ecx == cpu->edi) goto label_0001F97C;
    lift_push32(cpu, 0x35Du);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F976u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41F976u));
    *(uint32_t*)(cpu->esi + 0xC0u) = cpu->edi;
    label_0001F97C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    if (cpu->ecx == cpu->edi) goto label_0001F99B;
    lift_push32(cpu, 0x35Eu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F995u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41F995u));
    *(uint32_t*)(cpu->esi + 0xC4u) = cpu->edi;
    label_0001F99B:
    cpu->edi = cpu->ebx * 4u;
    lift_push32(cpu, 0x360u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F9B3u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41F9B3u));
    lift_push32(cpu, 0x361u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esi + 0xC0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F9CAu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41F9CAu));
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0xC4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41F9D9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41F9EBu));
    cpu->esp += 0x18u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0xC8u) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041FA00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC8u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->ecx <= 0) goto label_0001FA2C;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC0u);
    label_0001FA20:
    if (*(uint32_t*)(cpu->edx) == cpu->edi) goto label_0001FA9A;
    ++cpu->eax;
    cpu->edx += 4u;
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_0001FA20;
    label_0001FA2C:
    cpu->ecx = (uintptr_t)"===serverByType ====\ntypeN=";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FA36u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x41FA36u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FA3Du)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x41FA3Du));
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0xC8u) <= (int32_t)cpu->edi) goto label_0001FA7A;
    label_0001FA50:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC0u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FA5Eu)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x41FA5Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FA6Cu)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x41FA6Cu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FA71u)); sfera_sub_00451DC0(cpu, LIFT_CODE_TOKEN_VA(0x41FA71u));
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 0xC8u)) goto label_0001FA50;
    label_0001FA7A:
    cpu->ecx = (uintptr_t)"=======\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FA84u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x41FA84u));
    cpu->edx = 0x387u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FA93u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x41FA93u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001FA9A:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041FAB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x6400u);
    cpu->eax = cpu->edi + 0x64D0u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41FACBu));
    cpu->ecx = 0xFFFFFFFEu;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->eax = cpu->edi + 0xCCu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xA0u;
    label_0001FAF0:
    cpu->ebp = 0xFFFFFFFEu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xA0u;
    label_0001FB01:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x28u));
    if (*(uint8_t*)(cpu->eax) != (cpu->edx & 0xFFu)) goto label_0001FB7F;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((((cpu->ecx)&0x80000000u)!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebx = cpu->ecx + 4u;
    cpu->esi = cpu->eax + 0xFFFFFFFFu;
    cpu->esi&=cpu->ecx;
    cpu->edx = cpu->esi + (cpu->esi * 4u);
    cpu->edx <<= 5u;
    cpu->edi = cpu->edx + cpu->edi + 0x64D0u;
    label_0001FB30:
    cpu->eax = 0x9Fu;
    if ((int32_t)cpu->ebx > (int32_t)0x9Fu) goto label_0001FB3F;
    cpu->eax = cpu->ebx;
    label_0001FB3F:
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_0001FB77;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((((cpu->ebp)&0x80000000u)!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = cpu->ebp + 4u;
    --cpu->eax;
    cpu->eax &= cpu->ebp;
    label_0001FB50:
    cpu->ecx = 0x9Fu;
    if ((int32_t)cpu->edx > (int32_t)0x9Fu) goto label_0001FB5F;
    cpu->ecx = cpu->edx;
    label_0001FB5F:
    if ((int32_t)cpu->eax > (int32_t)cpu->ecx) goto label_0001FB6A;
    *(uint8_t*)(cpu->edi + cpu->eax) = 1u;
    ++cpu->eax;
    goto label_0001FB50;
    label_0001FB6A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->esi;
    cpu->edi += 0xA0u;
    goto label_0001FB30;
    label_0001FB77:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_0001FB7F:
    ++cpu->eax;
    ++cpu->ebp;
    --*(uint32_t*)(cpu->esp + 0x14u); sub_pred[0] = *(uint32_t*)(cpu->esp + 0x14u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (!sub_pred[0]) goto label_0001FB01;
    ++cpu->ecx;
    --*(uint32_t*)(cpu->esp + 0x1Cu); sub_pred[1] = *(uint32_t*)(cpu->esp + 0x1Cu) == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (!sub_pred[1]) goto label_0001FAF0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041FBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041FBC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->edi < 0) goto label_0001FBD1;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_0001FBE0;
    label_0001FBD1:
    cpu->edx = 0x3FFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1FBE0u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1FBE0u));
    label_0001FBE0:
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->eax += *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041FBF0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0x54u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x418u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41FC15u)); sfera_sub_0047EA90(cpu, LIFT_CODE_TOKEN_VA(0x41FC15u));
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=(double)*(float*)(cpu->esi + 8u); const double lift_right=x87_v0; if (lift_left>lift_right) goto label_0001FFD0; }
    { const double lift_left=(double)*(float*)(cpu->esi + 0xCu); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0001FFD0; }
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    { const double lift_left=(double)*(float*)(cpu->esi + 0x10u); const double lift_right=x87_v1; if (lift_left>lift_right) goto label_0001FFCE; }
    { const double lift_left=(double)*(float*)(cpu->esi + 0x14u); const double lift_right=x87_v1; if (lift_left<lift_right) goto label_0001FFCE; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    if ((int32_t)cpu->ebp < (int32_t)4u) goto label_0001FF0E;
    label_0001FC72:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebx + 0xFFFFFFFFu;
    if (cpu->ebx != 0u) goto label_0001FC7E;
    cpu->ecx = cpu->ebp + 0xFFFFFFFFu;
    label_0001FC7E:
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ebx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); if (lift_left==lift_right) goto label_0001FD14; }
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ebx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); if (!(lift_left<lift_right)) goto label_0001FCA8; }
    cpu->edx = cpu->ecx;
    cpu->ecx = cpu->ebx;
    label_0001FCA8:
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left>=lift_right) goto label_0001FD14; }
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0001FD14; }
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x118u)));
    x87_v3 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u)));
    x87_v2 = x87_v2 / x87_v3; 
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v3 = (((double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x118u))) - (x87_v3);
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v2 = x87_v2 * x87_v3; 
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0001FD14; }
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    label_0001FD14:
    cpu->edi = cpu->ebx + 1u;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->ebx;
    if (cpu->edi != 0u) goto label_0001FD22;
    cpu->edx = cpu->ebp + 0xFFFFFFFFu;
    label_0001FD22:
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); if (lift_left==lift_right) goto label_0001FDBA; }
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); if (!(lift_left<lift_right)) goto label_0001FD4E; }
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->edx = cpu->eax;
    label_0001FD4E:
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left>=lift_right) goto label_0001FDBA; }
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0001FDBA; }
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x118u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u)));
    x87_v3 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u)));
    x87_v2 = x87_v2 / x87_v3; 
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v3 = (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u))) - (x87_v3);
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v2 = x87_v2 * x87_v3; 
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0001FDBA; }
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    label_0001FDBA:
    cpu->edx = cpu->ebx + 2u;
    cpu->ecx = cpu->edx;
    if (cpu->edx != 0u) goto label_0001FDC6;
    cpu->edi = cpu->ebp + 0xFFFFFFFFu;
    label_0001FDC6:
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->edi * 4u) + 0x18u); if (lift_left==lift_right) goto label_0001FE5E; }
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->edi * 4u) + 0x18u); if (!(lift_left<lift_right)) goto label_0001FDF2; }
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edi;
    cpu->edi = cpu->eax;
    label_0001FDF2:
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left>=lift_right) goto label_0001FE5E; }
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->edi * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0001FE5E; }
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edi * 4u) + 0x118u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u)));
    x87_v3 = (double)*(float*)(cpu->esi + (cpu->edi * 4u) + 0x18u);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u)));
    x87_v2 = x87_v2 / x87_v3; 
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v3 = (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u))) - (x87_v3);
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v2 = x87_v2 * x87_v3; 
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0001FE5E; }
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    label_0001FE5E:
    cpu->ecx = cpu->ebx + 3u;
    if (cpu->ecx != 0u) goto label_0001FE68;
    cpu->edx = cpu->ebp + 0xFFFFFFFFu;
    label_0001FE68:
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); if (lift_left==lift_right) goto label_0001FF00; }
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); if (!(lift_left<lift_right)) goto label_0001FE94; }
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->edx = cpu->eax;
    label_0001FE94:
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left>=lift_right) goto label_0001FF00; }
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0001FF00; }
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x118u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u)));
    x87_v3 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u)));
    x87_v2 = x87_v2 / x87_v3; 
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v3 = (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u))) - (x87_v3);
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v2 = x87_v2 * x87_v3; 
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0001FF00; }
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    label_0001FF00:
    cpu->ebx += 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFFDu;
    if ((int32_t)cpu->ebx < (int32_t)cpu->eax) goto label_0001FC72;
    label_0001FF0E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ebx >= (int32_t)cpu->ebp) goto label_0001FFBE;
    label_0001FF1A:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebx + 0xFFFFFFFFu;
    if (cpu->ebx != 0u) goto label_0001FF26;
    cpu->ecx = cpu->ebp + 0xFFFFFFFFu;
    label_0001FF26:
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ebx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); if (lift_left==lift_right) goto label_0001FFB5; }
    { const double lift_right=(double)*(float*)(cpu->esi + (cpu->ebx * 4u) + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); if (!(lift_left<lift_right)) goto label_0001FF4C; }
    cpu->edx = cpu->ecx;
    cpu->ecx = cpu->ebx;
    label_0001FF4C:
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left>=lift_right) goto label_0001FFB5; }
    { const double lift_left=(double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0001FFB5; }
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x118u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x118u)));
    x87_v3 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x18u);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u)));
    x87_v2 = x87_v2 / x87_v3; 
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x18u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v3 = (((double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x118u))) - (x87_v3);
    *(float*)(cpu->esp + 0x1Cu) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v2 = x87_v2 * x87_v3; 
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v2; 
    { const double lift_left=(double)*(float*)(cpu->esp + 0x1Cu); const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0001FFB5; }
    ++cpu->edi;
    label_0001FFB5:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_0001FF1A;
    label_0001FFBE:
    cpu->eax = cpu->edi;
    x87_v0 = x87_v1; 
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax &= 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0001FFCE:
    x87_v0 = x87_v1; 
    label_0001FFD0:
    cpu->eax = 0u;
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041FFE0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    bool lift_cmp[1];
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0xCu))));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    x87_v0 = (x87_v0) / (100.0);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    if ((int32_t)cpu->edi >= 0) goto label_0002001A;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2001Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x2001Au));
    label_0002001A:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0002002E;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2002Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x2002Eu));
    label_0002002E:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    x87_v0 = (double)*(float*)(cpu->ecx + 0x34u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_00020053;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20053u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x20053u));
    label_00020053:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00020067;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20067u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x20067u));
    label_00020067:
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    x87_v0 = (double)*(float*)(cpu->eax + 0x38u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edi = cpu->ebp;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    cpu->edi += *(uint32_t*)(cpu->esi);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420095u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x420095u));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi + 4u;
    x87_v1 = 4000.0;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if ((int32_t)cpu->eax <= 0) goto label_00020184;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    cpu->ebp = cpu->esi + 0x40u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v2; 
    *(float*)(cpu->esp + 0x18u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    x87_v2 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u);
    goto label_000200EA;
    label_000200D0:
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v2 = 4000.0;
    x87_v3 = (double)*(float*)(cpu->esp + 0x20u);
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    label_000200EA:
    cpu->ecx = cpu->ebx + 0xFFFFFFFFu;
    if (cpu->ebx != 0u) goto label_000200F4;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    label_000200F4:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->edx != *(uint32_t*)(cpu->esi + 0x10u)) goto label_00020107;
    cpu->eax = 0xFF78C8AAu;
    if (*(uint32_t*)(cpu->esi + 0x14u) == cpu->ecx) goto label_0002010B;
    label_00020107:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    label_0002010B:
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->eax;
    x87_v4 = (double)*(float*)(cpu->edi + (cpu->ebx * 4u) + 0x18u);
    x87_v4 = (x87_v4) + (x87_v1);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u);
    x87_v4 = (x87_v4) * (x87_v0);
    lift_push32(cpu, 2u);
    x87_v4 = (x87_v4) - (x87_v2);
    *(float*)(cpu->ebp) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi + (cpu->ebx * 4u) + 0x118u);
    x87_v4 = (x87_v1) - (x87_v4);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v4 = (x87_v4) - (x87_v3);
    *(float*)(cpu->esi + 0x44u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi + (cpu->ecx * 4u) + 0x18u);
    x87_v4 = (x87_v4) + (x87_v1);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v2 = x87_v4 - x87_v2; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esi + 0x60u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edi + (cpu->ecx * 4u) + 0x118u);
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esi + 0x64u) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420161u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x420161u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->eax) goto label_000200D0;
    x87_v0 = 4000.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_00020184:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->ecx) <= (int32_t)cpu->eax) goto label_0002028A;
    x87_v2 = 2.0;
    cpu->ebp = cpu->edi + 0x118u;
    label_0002019E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->edx != *(uint32_t*)(cpu->esi + 0x10u)) goto label_000201B0;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x14u)) goto label_00020274;
    label_000201B0:
    x87_v3 = (double)*(float*)(cpu->ebp + 0xFFFFFF00u);
    cpu->ebx = cpu->esi + 0x40u;
    x87_v3 = (x87_v3) + (x87_v1);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    x87_v3 = (x87_v3) * (x87_v0);
    lift_push32(cpu, 2u);
    x87_v3 = (x87_v3) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))));
    *(float*)(cpu->esp + 0x34u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ebp);
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v0 = x87_v0 - x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) - (x87_v0);
    *(float*)(cpu->esp + 0x2Cu) = x87_v2; 
    *(float*)(cpu->ebx) = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x28u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) - (x87_v0);
    *(float*)(cpu->esp + 0x38u) = x87_v3; 
    *(float*)(cpu->esi + 0x44u) = (double)*(float*)(cpu->esp + 0x38u);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v2 = (x87_v2) + (x87_v0);
    *(float*)(cpu->esp + 0x28u) = x87_v2; 
    *(float*)(cpu->esi + 0x60u) = (double)*(float*)(cpu->esp + 0x28u);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    *(float*)(cpu->esi + 0x64u) = (double)*(float*)(cpu->esp + 0x34u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42022Du)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x42022Du));
    *(float*)(cpu->ebx) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, 0x20u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->esi + 0x44u) = x87_v0; 
    lift_push32(cpu, 1u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, 2u);
    *(float*)(cpu->esi + 0x60u) = x87_v0; 
    *(float*)(cpu->esi + 0x64u) = (double)*(float*)(cpu->esp + 0x34u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42025Au)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x42025Au));
    x87_v0 = 2.0;
    x87_v1 = 4000.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    label_00020274:
    ++cpu->eax;
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx)) goto label_0002019E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v2 = x87_v2; 
    label_0002028A:
    if (cpu->ebp != *(uint32_t*)(cpu->esi + 0x10u)) goto label_000203F9;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    x87_v2 = (double)*(float*)(cpu->edi + (cpu->eax * 4u) + 0x18u);
    cpu->ecx = 0x2710u;
    x87_v2 = (x87_v2) + (x87_v1);
    x87_v2 = (x87_v2) * (x87_v0);
    x87_v2 = (x87_v2) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u)))));
    *(float*)(cpu->esp + 0x18u) = x87_v2; 
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edi + (cpu->eax * 4u) + 0x118u)));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC8D0u);
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(float*)(cpu->esp + 0x24u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))))) * (0.10000000149011612));
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v0 = (x87_v0) + (1.0);
    x87_v0 = (x87_v0) * (100.0);
    x87_v0 = (x87_v0) + (50.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u); x87_v1 = x87_v0;
    cpu->ebx = cpu->esi + 0x40u;
    x87_v2 = 7.0;
    cpu->ecx = cpu->eax;
    x87_v1 = (x87_v1) - (x87_v2);
    cpu->eax |= 0xFFFFFF00u;
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    cpu->ecx&=0xFFu;
    cpu->eax <<= 8u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v2; 
    cpu->eax|=cpu->ecx;
    x87_v2 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x20u);
    *(float*)(cpu->ebx) = x87_v2; 
    cpu->eax <<= 8u;
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax |= cpu->ecx;
    x87_v2 = (x87_v2) - (x87_v1);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->eax;
    *(float*)(cpu->esp + 0x34u) = x87_v2; 
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->eax;
    x87_v2 = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, 2u);
    *(float*)(cpu->esi + 0x44u) = x87_v2;
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 + x87_v2; 
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    *(float*)(cpu->esi + 0x60u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esi + 0x64u) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42036Eu)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x42036Eu));
    *(float*)(cpu->ebx) = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x20u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx);
    x87_v0 = (x87_v0) + (7.0);
    lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    *(float*)(cpu->esi + 0x44u) = x87_v0;
    *(float*)(cpu->esi + 0x60u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esi + 0x64u) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4203A5u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4203A5u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->ebx) = x87_v0;
    *(float*)(cpu->esi + 0x44u) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, 0x20u);
    *(float*)(cpu->esi + 0x60u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    *(float*)(cpu->esi + 0x64u) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4203CEu)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4203CEu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->ebx) = x87_v0;
    lift_push32(cpu, 0x20u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->esi + 0x44u) = x87_v1; 
    lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    *(float*)(cpu->esi + 0x60u) = x87_v0; 
    *(float*)(cpu->esi + 0x64u) = (double)*(float*)(cpu->esp + 0x28u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4203F7u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4203F7u));
    goto label_000203FD;
    label_000203F9:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_000203FD:
    if (g_sfera_direct_input_runtime.keyboard_state[0x38] == 0u) goto label_00020413;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"%d");
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    goto label_00020420;
    label_00020413:
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d");
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    label_00020420:
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x420420u));
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->edi + 0xCu);
    x87_v1 = 4000.0;
    x87_v0 = (x87_v0) + (x87_v1);
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u); x87_v3 = x87_v2;
    x87_v0 = x87_v0 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v4 = x87_v3;
    x87_v0 = x87_v0 - x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi + 8u);
    x87_v4 = (x87_v4) + (x87_v1);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v4 = (x87_v4) - (x87_v3);
    x87_v0 = x87_v0 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    lift_cmp[0]=x87_v3>(30.0);
    x87_v3 = 0.0;
    if (!lift_cmp[0]) goto label_00020576;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 0x20u) = x87_v3;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    *(float*)(cpu->esp + 0x14u) = x87_v3;
    cpu->esi = 0u;
    if ((int32_t)(cpu->edx) < (int32_t)(4u)) goto label_000204FC;
    cpu->ecx = cpu->edx + 0xFFFFFFFCu;
    cpu->ecx >>= 2u;
    ++cpu->ecx;
    cpu->eax = cpu->edi + 0x1Cu;
    cpu->esi = cpu->ecx * 4u;
    label_00020492:
    x87_v4 = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    cpu->eax += 0x10u;
    --cpu->ecx;
    x87_v4 = (x87_v4) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x10u) = x87_v4; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x10u))) + (((double)*(float*)(cpu->eax + 0xFFFFFFF0u))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x10u))) + (((double)*(float*)(cpu->eax + 0xFFFFFFF4u))));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->esp + 0x10u))) + (((double)*(float*)(cpu->eax + 0xFFFFFFF8u))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->eax + 0xECu))) + (((double)*(float*)(cpu->esp + 0x14u))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x10u))) + (((double)*(float*)(cpu->eax + 0xF0u))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x10u))) + (((double)*(float*)(cpu->eax + 0xF4u))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x10u))) + (((double)*(float*)(cpu->eax + 0xF8u))));
    if (cpu->ecx != 0u) goto label_00020492;
    label_000204FC:
    if ((int32_t)cpu->esi >= (int32_t)cpu->edx) goto label_00020528;
    cpu->edi = cpu->edi + (cpu->esi * 4u) + 0x118u;
    cpu->edx -= cpu->esi;
    label_00020509:
    x87_v4 = (double)*(float*)(cpu->edi + 0xFFFFFF00u);
    cpu->edi += 4u;
    --cpu->edx;
    x87_v4 = (x87_v4) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_v4; 
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) + (((double)*(float*)(cpu->edi + 0xFFFFFFFCu))));
    if (cpu->edx != 0u) goto label_00020509;
    label_00020528:
    *(float*)(cpu->esp + 0x10u) = (double)(((int32_t)(*(uint32_t*)(cpu->ebx))));
    x87_v4 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 / x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v5 = (x87_v5) + (x87_v1);
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v0 = x87_v5 - x87_v0; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v4); 
    x87_v4 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = x87_v4 / x87_v0; 
    cpu->esi = cpu->eax + 0xFFFFFFF6u;
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = x87_v1 - x87_v3; 
    x87_v1 = x87_v1 * x87_v2; 
    x87_v1 = (x87_v1) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->eax -= 0xFu;
    goto label_000205A5;
    label_00020576:
    x87_v4 = (double)*(float*)(cpu->edi + 8u);
    x87_v4 = (x87_v4) + (((double)*(float*)(cpu->edi + 0xCu)));
    x87_v4 = (x87_v4) * (0.5);
    x87_v4 = (x87_v4) + (x87_v1);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v0 = x87_v4 - x87_v0; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    x87_v3 = (double)*(float*)(cpu->edi + 0x14u);
    x87_v1 = x87_v1 - x87_v3; 
    cpu->esi = cpu->eax + 0xFFFFFFF6u;
    x87_v1 = x87_v1 * x87_v2; 
    x87_v1 = (x87_v1) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->eax -= 0x17u;
    label_000205A5:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4205C0u)); sfera_sub_0044D190(cpu, LIFT_CODE_TOKEN_VA(0x4205C0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004205E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 8u) == 0xFFFFFFFFu) goto label_00020716;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    g_sfera_screen_clip_runtime.right = cpu->eax;
    g_sfera_screen_clip_runtime.bottom = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    g_sfera_screen_clip_runtime.left = cpu->ebx;
    g_sfera_screen_clip_runtime.top = cpu->ebx;
    *(float*)(cpu->esi + 0x48u) = x87_v0;
    x87_v1 = 1.0;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->ebx;
    *(float*)(cpu->esi + 0x4Cu) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x74u) = cpu->ebx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->esi + 0x58u) = x87_v1;
    cpu->eax = 0x96000000u;
    *(float*)(cpu->esi + 0x5Cu) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->eax;
    *(float*)(cpu->esi + 0x68u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->eax;
    *(float*)(cpu->esi + 0x78u) = x87_v1;
    cpu->edi = cpu->esi + 0x40u;
    *(float*)(cpu->esi + 0x7Cu) = x87_v1;
    lift_push32(cpu, cpu->ebx);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->esi + 0x6Cu) = x87_v1; 
    *(float*)(cpu->edi) = x87_v0;
    *(float*)(cpu->esi + 0x44u) = x87_v0;
    *(float*)(cpu->esi + 0x60u) = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    *(float*)(cpu->esi + 0x64u) = x87_v0;
    *(float*)(cpu->esi + 0x80u) = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    *(float*)(cpu->esi + 0x84u) = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    *(float*)(cpu->esi + 0xA0u) = x87_v0; 
    *(float*)(cpu->esi + 0xA4u) = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42068Fu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x42068Fu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42069Eu)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x42069Eu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4206B0u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4206B0u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4206BBu)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x4206BBu));
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ebx) goto label_000206FC;
    label_000206C2:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ebx + cpu->edx);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x18u)) goto label_000206D8;
    if ((int32_t)cpu->eax > (int32_t)*(uint32_t*)(cpu->esi + 0x1Cu)) goto label_000206D8;
    cpu->eax = 0xFFFF3232u;
    goto label_000206E7;
    label_000206D8:
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x20u)) goto label_000206F0;
    if ((int32_t)cpu->eax > (int32_t)*(uint32_t*)(cpu->esi + 0x24u)) goto label_000206F0;
    cpu->eax = 0xFF000064u;
    label_000206E7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x206F0u)); sfera_sub_0041FFE0(cpu, LIFT_CODE_TOKEN_RVA(0x206F0u));
    label_000206F0:
    ++cpu->edi;
    cpu->ebx += 0x418u;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_000206C2;
    label_000206FC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0xFFFFFFFFu) goto label_00020710;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20710u)); sfera_sub_0041FFE0(cpu, LIFT_CODE_TOKEN_RVA(0x20710u));
    label_00020710:
    ++*(uint32_t*)(cpu->esi + 0xC8D0u);
    label_00020716:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00420720(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x28u) != cpu->eax) goto label_00020739;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) != cpu->edx) goto label_00020739;
    cpu->ecx = 0u;
    goto label_0002073E;
    label_00020739:
    cpu->ecx = 1u;
    label_0002073E:
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    if (cpu->ecx == 0u) goto label_00020759;
    cpu->ecx = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20759u)); sfera_sub_0041F110(cpu, LIFT_CODE_TOKEN_RVA(0x20759u));
    label_00020759:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->eax != 0u) goto label_00020767;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00020767:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->edx <= (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00020780;
    cpu->edx = 0x1B8u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20780u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x20780u));
    label_00020780:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->eax == 0u) goto label_000207AA;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ecx + 0xFFFFFBE8u);
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esi + 0x28u)) goto label_000207AA;
    cpu->edx = 0x1B9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x207AAu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x207AAu));
    label_000207AA:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = cpu->eax + cpu->ecx + 0xFFFFFFFFu;
    --cpu->edx;
    if (cpu->eax == cpu->edx) goto label_000207DC;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ecx);
    if ((int32_t)cpu->edx > (int32_t)*(uint32_t*)(cpu->esi + 0x2Cu)) goto label_000207DC;
    cpu->edx = 0x1BBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x207DCu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x207DCu));
    label_000207DC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx + cpu->eax + 0xFFFFFFFFu;
    if ((int32_t)cpu->edi < (int32_t)cpu->eax) goto label_00020840;
    cpu->ebx = cpu->edi;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x418u);
    label_000207F4:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ebx + cpu->edx);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x28u)) goto label_00020803;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 0x2Cu)) goto label_00020812;
    label_00020803:
    cpu->edx = 0x1BFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20812u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x20812u));
    label_00020812:
    cpu->eax = *(uint32_t*)(cpu->esi);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420830u)); sfera_sub_0041FBF0(cpu, LIFT_CODE_TOKEN_VA(0x420830u));
    if (cpu->eax != 0u) goto label_00020849;
    --cpu->edi;
    cpu->ebx -= 0x418u;
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->esi + 0x30u)) goto label_000207F4;
    label_00020840:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00020849:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00420860(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[8]; double x87_v0;
    cpu->esp -= 0x5Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0x270Fu;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if (cpu->eax > 0x4E1Eu) goto label_00020899;
    if ((int32_t)cpu->ebx <= (int32_t)0xFFFFD8F0u) goto label_00020899;
    if ((int32_t)cpu->ebx < (int32_t)0x2710u) goto label_000208A8;
    label_00020899:
    cpu->edx = 0x1CCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x208A8u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x208A8u));
    label_000208A8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = 0u;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000208BC;
    cpu->edi = cpu->eax;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    cpu->edi += *(uint32_t*)(cpu->esi);
    label_000208BC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->ecx = cpu->edx + 0xFFFFFFFFu;
    if (cpu->ecx > 0xAu) goto label_00020ECD;
    switch (cpu->ecx) {
        case 0u: goto label_000209F9;
        case 1u: goto label_00020AB1;
        case 2u: goto label_00020AF0;
        case 3u: goto label_00020B2F;
        case 4u: goto label_00020BEC;
        case 5u: goto label_00020D2A;
        case 6u: goto label_00020D59;
        case 7u: goto label_00020DCB;
        case 8u: goto label_000208D3;
        case 9u: goto label_000208EC;
        case 10u: goto label_000209F1;
        default: lift_trap(cpu, 0x4208CCu, "resolved jump-table index out of range"); return;
    }
label_000208D3: ;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x14u) = 0u;
    goto label_00020EDB;
    label_000208EC:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->eax) goto label_00020980;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    (void)cpu;
    label_00020900:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)*(uint32_t*)(cpu->ecx + cpu->edx + 4u) >= (int32_t)3u) goto label_0002096A;
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx -= *(uint32_t*)(cpu->esp + 0x10u);
    --cpu->ebx;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x418u);
    lift_test[0]=cpu->ebx==0u; lift_test[4]=((cpu->ebx)&0x80000000u)!=0u;
    if (((cpu->ebx)&0x80000000u)==0u) goto label_00020930;
    cpu->edx = 0x1E3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42092Eu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x42092Eu));
    lift_test[0]=cpu->ebx==0u; lift_test[4]=((cpu->ebx)&0x80000000u)!=0u;
    label_00020930:
    if ((lift_test[0]) || (lift_test[4])) goto label_0002095B;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x1E5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->ecx + 0x418u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2095Bu)); sfera_sub_0047EAC0(cpu, LIFT_CODE_TOKEN_RVA(0x2095Bu));
    label_0002095B:
    --*(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) - (uint64_t)(0x418u) - (uint64_t)(0u);
    --*(uint32_t*)(cpu->esi + 4u);
    label_0002096A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x418u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00020900;
    label_00020980:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420997u)); sfera_sub_0041F110(cpu, LIFT_CODE_TOKEN_VA(0x420997u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x1EAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4209B1u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x4209B1u));
    cpu->ecx = (uintptr_t)"landscape\\contours.bin";
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4209BDu)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x4209BDu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esi + 4u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4209CBu)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4209CBu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4209DEu)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4209DEu));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4209E5u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x4209E5u));
    *(uint32_t*)(cpu->esi + 8u) = 0xFFFFFFFFu;
    goto label_00020EDB;
    label_000209F1:
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    goto label_00020EDB;
    label_000209F9:
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esi + 0x10u) = 0xFFFFFFFFu;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ebx) goto label_00020EDB;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_00020A11:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x18u)) goto label_00020A58;
    if ((int32_t)cpu->eax > (int32_t)*(uint32_t*)(cpu->esi + 0x1Cu)) goto label_00020A58;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x78u))));
    lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x80u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420A40u)); sfera_sub_0041FBF0(cpu, LIFT_CODE_TOKEN_VA(0x420A40u));
    if (cpu->eax == 0u) goto label_00020A58;
    *(uint32_t*)(cpu->esp + (cpu->ebx * 4u) + 0x18u) = cpu->ebp;
    ++cpu->ebx;
    if (cpu->ebx != 0x14u) goto label_00020A58;
    cpu->ecx = (uintptr_t)"internal error 87236589";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20A58u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x20A58u));
    label_00020A58:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x418u) + (uint64_t)(0u);
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00020A11;
    if (cpu->ebx == 0u) goto label_00020EDB;
    cpu->ecx = g_sfera_contours_runtime.round_robin_counter;
    cpu->eax = cpu->ecx;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ebx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x14u) = 0u;
    g_sfera_contours_runtime.round_robin_counter = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x18u);
    cpu->eax = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    if ((int32_t)cpu->eax < 0) goto label_00020A9D;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00020EDB;
    label_00020A9D:
    cpu->edx = 0x200u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420AACu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x420AACu));
    goto label_00020EDB;
    label_00020AB1:
    if (cpu->eax == 0xFFFFFFFFu) goto label_00020EDB;
    ++*(uint32_t*)(cpu->esi + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax != *(uint32_t*)(cpu->edi + 4u)) goto label_00020ACC;
    *(uint32_t*)(cpu->esi + 0x14u) = 0u;
    label_00020ACC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if ((int32_t)cpu->eax < 0) goto label_00020ADC;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00020EDB;
    label_00020ADC:
    cpu->edx = 0x208u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420AEBu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x420AEBu));
    goto label_00020EDB;
    label_00020AF0:
    if (cpu->eax == 0xFFFFFFFFu) goto label_00020EDB;
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    if (*(uint32_t*)(cpu->esi + 0x14u) != cpu->eax) goto label_00020B0B;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    label_00020B0B:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if ((int32_t)cpu->eax < 0) goto label_00020B1B;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00020EDB;
    label_00020B1B:
    cpu->edx = 0x210u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420B2Au)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x420B2Au));
    goto label_00020EDB;
    label_00020B2F:
    if (cpu->eax == 0xFFFFFFFFu) goto label_00020EDB;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->eax >= (int32_t)0x3Fu) goto label_00020EDB;
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ebp = (cpu->eax * 4u) + 0xFFFFFFFCu;
    lift_test[1]=cpu->ebp==0u; lift_test[5]=((cpu->ebp)&0x80000000u)!=0u;
    if (((cpu->ebp)&0x80000000u)==0u) goto label_00020B63;
    cpu->edx = 0x217u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420B61u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x420B61u));
    lift_test[1]=cpu->ebp==0u; lift_test[5]=((cpu->ebp)&0x80000000u)!=0u;
    label_00020B63:
    if ((lift_test[1]) || (lift_test[5])) goto label_00020BBB;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, 0x21Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi + (cpu->eax * 4u) + 0x1Cu;
    cpu->ecx = cpu->edi + (cpu->eax * 4u) + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420B8Du)); sfera_sub_0047EAC0(cpu, LIFT_CODE_TOKEN_VA(0x420B8Du));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, 0x21Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi + (cpu->eax * 4u) + 0x11Cu;
    cpu->ecx = cpu->edi + (cpu->eax * 4u) + 0x120u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20BBBu)); sfera_sub_0047EAC0(cpu, LIFT_CODE_TOKEN_RVA(0x20BBBu));
    label_00020BBB:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x74u))));
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->edi + (cpu->eax * 4u) + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x7Cu))));
    cpu->eax = 1u;
    *(float*)(cpu->edi + (cpu->ecx * 4u) + 0x11Cu) = x87_v0; 
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420BE7u)); sfera_sub_0041F1F0(cpu, LIFT_CODE_TOKEN_VA(0x420BE7u));
    goto label_00020EDB;
    label_00020BEC:
    if (cpu->eax == 0xFFFFFFFFu) goto label_00020EDB;
    cpu->ebp = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebp -= *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ebp = (cpu->ebp * 4u) + 0xFFFFFFFCu;
    lift_test[2]=cpu->ebp==0u; lift_test[6]=((cpu->ebp)&0x80000000u)!=0u;
    if (((cpu->ebp)&0x80000000u)==0u) goto label_00020C17;
    cpu->edx = 0x228u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420C15u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x420C15u));
    lift_test[2]=cpu->ebp==0u; lift_test[6]=((cpu->ebp)&0x80000000u)!=0u;
    label_00020C17:
    if ((lift_test[2]) || (lift_test[6])) goto label_00020C6F;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, 0x22Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi + (cpu->eax * 4u) + 0x1Cu;
    cpu->ecx = cpu->edi + (cpu->eax * 4u) + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420C41u)); sfera_sub_0047EAC0(cpu, LIFT_CODE_TOKEN_VA(0x420C41u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, 0x22Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi + (cpu->eax * 4u) + 0x11Cu;
    cpu->ecx = cpu->edi + (cpu->eax * 4u) + 0x118u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20C6Fu)); sfera_sub_0047EAC0(cpu, LIFT_CODE_TOKEN_RVA(0x20C6Fu));
    label_00020C6F:
    if ((--*(uint32_t*)(cpu->edi + 4u)) == 0u) goto label_00020C91;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420C7Cu)); sfera_sub_0041F1F0(cpu, LIFT_CODE_TOKEN_VA(0x420C7Cu));
    if ((int32_t)(--*(uint32_t*)(cpu->esi + 0x14u)) >= 0) goto label_00020EDB;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    --cpu->edx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    goto label_00020EDB;
    label_00020C91:
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x10u);
    --cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    lift_test[3]=cpu->edi==0u; lift_test[7]=((cpu->edi)&0x80000000u)!=0u;
    if (((cpu->edi)&0x80000000u)==0u) goto label_00020CB3;
    cpu->edx = 0x237u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420CB1u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x420CB1u));
    lift_test[3]=cpu->edi==0u; lift_test[7]=((cpu->edi)&0x80000000u)!=0u;
    label_00020CB3:
    if ((lift_test[3]) || (lift_test[7])) goto label_00020CE3;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x239u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ecx + 0x418u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20CE3u)); sfera_sub_0047EAC0(cpu, LIFT_CODE_TOKEN_RVA(0x20CE3u));
    label_00020CE3:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x23Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx -= 0x418u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420D03u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x420D03u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->eax = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420D25u)); sfera_sub_0041F110(cpu, LIFT_CODE_TOKEN_VA(0x420D25u));
    goto label_00020F15;
    label_00020D2A:
    if (cpu->eax == 0xFFFFFFFFu) goto label_00020EDB;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x74u))));
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->edi + (cpu->ecx * 4u) + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x7Cu))));
    cpu->ecx = cpu->esi;
    *(float*)(cpu->edi + (cpu->edx * 4u) + 0x118u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420D54u)); sfera_sub_0041F1F0(cpu, LIFT_CODE_TOKEN_VA(0x420D54u));
    goto label_00020EDB;
    label_00020D59:
    if (cpu->eax == 0xFFFFFFFFu) goto label_00020EDB;
    cpu->ebx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    *(uint32_t*)(cpu->edi + 4u) = 0x3E7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420D75u)); sfera_sub_0041F1D0(cpu, LIFT_CODE_TOKEN_VA(0x420D75u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420D8Cu)); sfera_sub_0041F110(cpu, LIFT_CODE_TOKEN_VA(0x420D8Cu));
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ebp) goto label_00020DAB;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->eax += 4u;
    label_00020D98:
    if (*(uint32_t*)(cpu->eax) == 0x3E7u) goto label_00020DB5;
    ++cpu->ebp;
    cpu->eax += 0x418u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00020D98;
    label_00020DAB:
    cpu->ecx = (uintptr_t)"internal error 672474878765683";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20DB5u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x20DB5u));
    label_00020DB5:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->ebp;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    *(uint32_t*)(cpu->ecx + cpu->edx + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebp;
    goto label_00020EDB;
    label_00020DCB:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    ++cpu->edx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x25Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420DE6u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x420DE6u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->ecx;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x418u);
    cpu->edi += cpu->eax;
    ++cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x420E01u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x80u))));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->esp += 0xCu;
    cpu->eax = cpu->edi + 0x318u;
    *(float*)(cpu->edi + 0x18u) = x87_v0; 
    cpu->ecx = 0x40u;
    *(float*)(cpu->edi + 0x118u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x78u))));
    label_00020E30:
    *(uint32_t*)(cpu->eax + 0xFFFFFF00u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax) = 0xFFFFFFFFu;
    cpu->eax += 4u;
    if ((--cpu->ecx) != 0u) goto label_00020E30;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420E4Eu)); sfera_sub_0041F1F0(cpu, LIFT_CODE_TOKEN_VA(0x420E4Eu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0041F1C0));
    *(uint32_t*)(cpu->edi + 4u) = 0x3E7u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, 0x418u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::qsort), LIFT_CODE_TOKEN_VA(0x420E66u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp += 0x10u;
    cpu->eax = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420E86u)); sfera_sub_0041F110(cpu, LIFT_CODE_TOKEN_VA(0x420E86u));
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->ebp) goto label_00020EA5;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->eax += 4u;
    label_00020E92:
    if (*(uint32_t*)(cpu->eax) == 0x3E7u) goto label_00020EAF;
    ++cpu->ebp;
    cpu->eax += 0x418u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00020E92;
    label_00020EA5:
    cpu->ecx = (uintptr_t)"internal error 68247987378235";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20EAFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x20EAFu));
    label_00020EAF:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->ebp;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    *(uint32_t*)(cpu->ecx + cpu->edx + 4u) = 1u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x14u) = 0u;
    goto label_00020EDB;
    label_00020ECD:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"process_contour_event: wrong type %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x420ED8u)); sfera_sub_0047E960(cpu, LIFT_CODE_TOKEN_VA(0x420ED8u));
    cpu->esp += 8u;
    label_00020EDB:
    if (cpu->edi == 0u) goto label_00020F15;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->eax <= 0) goto label_00020EEB;
    if ((int32_t)cpu->eax <= (int32_t)0x40u) goto label_00020EFA;
    label_00020EEB:
    cpu->edx = 0x277u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20EFAu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x20EFAu));
    label_00020EFA:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if ((int32_t)cpu->eax < 0) goto label_00020F06;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00020F15;
    label_00020F06:
    cpu->edx = 0x278u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20F15u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x20F15u));
    label_00020F15:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 0x38u)) goto label_00020F36;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 0x3Cu)) goto label_00020F36;
    x87_v0 = (double)100.0f;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x20F36u)); sfera_sub_0041F420(cpu, LIFT_CODE_TOKEN_RVA(0x20F36u));
    label_00020F36:
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0xC8D0u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00420F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 4u) <= (int32_t)cpu->edx) goto label_000210C4;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_00020FB0:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->eax);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebx + 0x38u)) goto label_000210A9;
    if ((int32_t)cpu->ecx > (int32_t)*(uint32_t*)(cpu->ebx + 0x3Cu)) goto label_000210A9;
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + cpu->eax + 4u) <= (int32_t)cpu->ebp) goto label_000210A9;
    cpu->ecx = cpu->esi + 0x318u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    label_00020FE0:
    *(uint32_t*)(cpu->ecx + cpu->eax + 0xFFFFFF00u) = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->ecx + cpu->eax) = 0xFFFFFFFFu;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 4u) <= (int32_t)cpu->edi) goto label_0002108D;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_00021005:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebx + 0x38u)) goto label_00021048;
    if ((int32_t)cpu->eax > (int32_t)*(uint32_t*)(cpu->ebx + 0x3Cu)) goto label_00021048;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_00021048;
    label_00021020:
    if (cpu->edx != cpu->edi) goto label_00021028;
    if (cpu->ebp == cpu->esi) goto label_0002103F;
    label_00021028:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421033u)); sfera_sub_0041F7F0(cpu, LIFT_CODE_TOKEN_VA(0x421033u));
    if (cpu->eax != 0u) goto label_0002105A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0002103F:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_00021020;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    label_00021048:
    ++cpu->edi;
    cpu->ecx += 0x418u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->ebx + 4u)) goto label_00021005;
    goto label_0002108D;
    label_0002105A:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + cpu->ecx + 0xFFFFFF00u) = cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x106u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->edi + cpu->esi;
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u) + 0x218u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u) + 0x318u) = cpu->ebp;
    cpu->edx = cpu->ecx;
    label_0002108D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->ebp;
    cpu->ecx += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + cpu->eax + 4u)) goto label_00020FE0;
    label_000210A9:
    ++cpu->edx;
    cpu->esi += 0x418u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->ebx + 4u)) goto label_00020FB0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000210C4:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004210D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0xC0u) == cpu->edi) goto label_000210EB;
    if (*(uint32_t*)(cpu->esi + 0xC4u) != cpu->edi) goto label_000210FA;
    label_000210EB:
    cpu->edx = 0x30Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x210FAu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x210FAu));
    label_000210FA:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421101u)); sfera_sub_00420F90(cpu, LIFT_CODE_TOKEN_VA(0x421101u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_00021241;
    cpu->ebx = 0u;
    cpu->ebp = 0x218u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    label_00021125:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->ebx + cpu->eax);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 0x38u)) goto label_00021207;
    if ((int32_t)cpu->ecx > (int32_t)*(uint32_t*)(cpu->esi + 0x3Cu)) goto label_00021207;
    if ((int32_t)*(uint32_t*)(cpu->ebx + cpu->eax + 4u) <= (int32_t)cpu->edi) goto label_00021207;
    label_00021150:
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ebp);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000211F1;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, 0x314u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421170u)); sfera_sub_0047EA60(cpu, LIFT_CODE_TOKEN_VA(0x421170u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421183u)); sfera_sub_0041FA00(cpu, LIFT_CODE_TOKEN_VA(0x421183u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ebx + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421194u)); sfera_sub_0041FA00(cpu, LIFT_CODE_TOKEN_VA(0x421194u));
    if (cpu->eax == *(uint32_t*)(cpu->esp + 0x2Cu)) goto label_000211F1;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x106u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    ++*(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx += cpu->edi;
    cpu->ebx = (cpu->ebx * 4u) + 0x318u;
    cpu->edx += *(uint32_t*)(cpu->ebx + cpu->eax);
    if (*(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x218u) == cpu->ecx) goto label_000211D0;
    cpu->ecx = (uintptr_t)"Wrong connection of server contours (case1)";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x211D0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x211D0u));
    label_000211D0:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x106u);
    cpu->edx += *(uint32_t*)(cpu->ebx + cpu->eax);
    if (*(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x318u) == cpu->edi) goto label_000211F1;
    cpu->ecx = (uintptr_t)"Wrong connection of server contours (case2)";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x211F1u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x211F1u));
    label_000211F1:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->edi;
    cpu->ebp += 4u;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->ebx + cpu->eax + 4u)) goto label_00021150;
    cpu->edi = 0u;
    label_00021207:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x106u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->ebp += 0x418u;
    cpu->ebx += 0x418u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00021125;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != cpu->edi) goto label_00021251;
    label_00021241:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    sfera_sub_0048B960(cpu, stop_address); return;
    label_00021251:
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00021264;
    cpu->edx = 0x335u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x21264u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x21264u));
    label_00021264:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->ebx = (int32_t)(cpu->ebx) >> 1u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, 0x338u);
    cpu->ecx <<= 4u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421287u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x421287u));
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_0002147B;
    cpu->edx = 0u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x218u;
    label_000212B0:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->eax);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 0x38u)) goto label_00021445;
    if ((int32_t)cpu->ecx > (int32_t)*(uint32_t*)(cpu->esi + 0x3Cu)) goto label_00021445;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edx + cpu->eax + 4u) <= (int32_t)cpu->ebx) goto label_00021445;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_000212E0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->eax);
    if (cpu->eax == 0xFFFFFFFFu) goto label_0002142F;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, 0x33Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421304u)); sfera_sub_0047EA60(cpu, LIFT_CODE_TOKEN_VA(0x421304u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421317u)); sfera_sub_0041FA00(cpu, LIFT_CODE_TOKEN_VA(0x421317u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42132Au)); sfera_sub_0041FA00(cpu, LIFT_CODE_TOKEN_VA(0x42132Au));
    if (cpu->eax == cpu->ebp) goto label_0002142B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->eax + 4u);
    --cpu->edx;
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_0002134A;
    cpu->eax = cpu->ebx + 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    goto label_00021352;
    label_0002134A:
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    label_00021352:
    lift_push32(cpu, 0x343u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = 0x40u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421368u)); sfera_sub_0047EA60(cpu, LIFT_CODE_TOKEN_VA(0x421368u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x344u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421380u)); sfera_sub_0047EA60(cpu, LIFT_CODE_TOKEN_VA(0x421380u));
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = cpu->ebx + cpu->ebp + 6u;
    x87_v0 = (double)*(float*)(cpu->edx + (cpu->ecx * 4u));
    cpu->ecx = cpu->ebx + cpu->ebp + 0x46u;
    *(float*)(cpu->eax + (cpu->edi * 4u)) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esi);
    x87_v0 = (double)*(float*)(cpu->edx + (cpu->ecx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->eax + (cpu->edi * 4u) + 4u) = x87_v0; 
    cpu->edx = cpu->ecx + cpu->ebp + 6u;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->edx * 4u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->eax + (cpu->edi * 4u) + 8u) = x87_v0; 
    cpu->ecx = cpu->edx + cpu->ebp + 0x46u;
    cpu->edx = *(uint32_t*)(cpu->esi);
    x87_v0 = (double)*(float*)(cpu->edx + (cpu->ecx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->eax + (cpu->edi * 4u) + 0xCu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->eax);
    lift_push32(cpu, 0x34Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edi += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4213E1u)); sfera_sub_0047EA60(cpu, LIFT_CODE_TOKEN_VA(0x4213E1u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->ebx + cpu->ebp;
    cpu->eax = (cpu->eax * 4u) + 0x318u;
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ecx);
    lift_push32(cpu, 0x34Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = 0x40u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421408u)); sfera_sub_0047EA60(cpu, LIFT_CODE_TOKEN_VA(0x421408u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x106u);
    cpu->ecx += *(uint32_t*)(cpu->edx + cpu->eax);
    *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0x218u) = 0xFFFFFFFFu;
    goto label_0002142F;
    label_0002142B:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    label_0002142F:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->edx + cpu->eax + 4u)) goto label_000212E0;
    label_00021445:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(0x418u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->ebp += 0x106u;
    cpu->edx += 0x418u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_000212B0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0002147B:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421484u)); sfera_sub_0048B960(cpu, LIFT_CODE_TOKEN_VA(0x421484u));
    lift_push32(cpu, 0x351u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421495u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x421495u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004214A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x38u);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->esi |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4214C9u)); sfera_sub_0041F110(cpu, LIFT_CODE_TOKEN_VA(0x4214C9u));
    cpu->ecx = cpu->ebp + 0xCCu;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFF079u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    goto label_000214E4;
    label_000214E0:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000214E4:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFF079u;
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    goto label_00021504;
    label_00021500:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_00021504:
    *(float*)(cpu->esp + 0x24u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    if (cpu->esi == 0xFFFFFFFFu) goto label_00021549;
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x418u);
    cpu->esi += *(uint32_t*)(cpu->ebp);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421534u)); sfera_sub_0041FBF0(cpu, LIFT_CODE_TOKEN_VA(0x421534u));
    if (cpu->eax == 0u) goto label_00021549;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x34u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->eax + cpu->ecx) = cpu->edx & 0xFFu;
    goto label_000215B7;
    label_00021549:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ebx = cpu->esi + cpu->edx;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_000215B7;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    label_00021560:
    cpu->eax = *(uint32_t*)(cpu->ebp);
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->ecx = cpu->ebp;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42157Fu)); sfera_sub_0041FBF0(cpu, LIFT_CODE_TOKEN_VA(0x42157Fu));
    if (cpu->eax != 0u) goto label_00021590;
    ++cpu->esi;
    cpu->edi += 0x418u;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_00021560;
    goto label_000215B7;
    label_00021590:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x418u);
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4215A8u)); sfera_sub_0041FA00(cpu, LIFT_CODE_TOKEN_VA(0x4215A8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint8_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFu;
    label_000215B7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += 0x32u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0xFB9u) goto label_00021500;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0xA0u) + (uint64_t)(0u);
    cpu->eax += 0x32u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0xFB9u) goto label_000214E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421600(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->edi < 0) goto label_00021611;
    if ((int32_t)cpu->edi <= (int32_t)0x64u) goto label_00021620;
    label_00021611:
    cpu->edx = 0x3D1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x21620u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x21620u));
    label_00021620:
    if (*(uint32_t*)(cpu->esi + 0xC0u) == 0u) goto label_00021632;
    if (*(uint32_t*)(cpu->esi + 0xC4u) != 0u) goto label_00021641;
    label_00021632:
    cpu->edx = 0x3D2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x21641u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x21641u));
    label_00021641:
    if (*(uint32_t*)(cpu->esi + 0x64CCu) != 0u) goto label_0002165B;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421651u)); sfera_sub_004214A0(cpu, LIFT_CODE_TOKEN_VA(0x421651u));
    *(uint32_t*)(cpu->esi + 0x64CCu) = 1u;
    label_0002165B:
    if (g_sfera_world_objects.contour_mode == cpu->edi) goto label_00021671;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42166Bu)); sfera_sub_0041FAB0(cpu, LIFT_CODE_TOKEN_VA(0x42166Bu));
    g_sfera_world_objects.contour_mode = cpu->edi;
    label_00021671:
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v1 = 4000.0;
    x87_v0 = (x87_v0) + (x87_v1);
    x87_v2 = 50.0;
    x87_v0 = (x87_v0) / (x87_v2);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->edi = cpu->eax;
    x87_v0 = x87_v1 / x87_v0; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    if (cpu->edi > 0x9Fu) goto label_000216BD;
    if (cpu->eax > 0x9Fu) goto label_000216BD;
    cpu->ecx = cpu->edi + (cpu->edi * 4u);
    cpu->ecx <<= 5u;
    cpu->ecx += cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->ecx + cpu->esi + 0x64D0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000216BD:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004216D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4216F4u)); sfera_sub_00420720(cpu, LIFT_CODE_TOKEN_VA(0x4216F4u));
    if (cpu->eax != 0xFFFFFFFFu) goto label_000216FF;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000216FF:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421707u)); sfera_sub_0041FA00(cpu, LIFT_CODE_TOKEN_VA(0x421707u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_00421750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax) = 0x14u;
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    *(uint32_t*)(cpu->eax + 8u) = 0u;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004217A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 1u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004217B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004217C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->eax = 1u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004217E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->eax = 1u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x80004001u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x80004001u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x80004001u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = address32(&__uuidof(IUnknown));
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi -= cpu->eax;
    label_00021864:
    cpu->edi = *(uint32_t*)(cpu->esi + cpu->eax);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_00021887;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if (cpu->ecx >= 4u) goto label_00021864;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00021887:
    cpu->eax = address32(&__uuidof(IOleClientSite));
    cpu->esi = cpu->edx;
    cpu->ecx = 0x10u;
    cpu->esi -= cpu->eax;
    label_00021895:
    cpu->edi = *(uint32_t*)(cpu->esi + cpu->eax);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_000218B8;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if (cpu->ecx >= 4u) goto label_00021895;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000218B8:
    cpu->eax = address32(&__uuidof(IOleInPlaceSite));
    cpu->esi = cpu->edx;
    cpu->ecx = 0x10u;
    cpu->esi -= cpu->eax;
    label_000218C6:
    cpu->edi = *(uint32_t*)(cpu->esi + cpu->eax);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_000218EC;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if (cpu->ecx >= 4u) goto label_000218C6;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += 4u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000218EC:
    cpu->eax = address32(&__uuidof(IDocHostUIHandler));
    cpu->ecx = 0x10u;
    cpu->edx -= cpu->eax;
    label_000218F8:
    cpu->esi = *(uint32_t*)(cpu->edx + cpu->eax);
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_0002191E;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if (cpu->ecx >= 4u) goto label_000218F8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += 0x10u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0002191E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->eax = 0x80004002u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x80004001u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->eax = 0x80004002u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx += 0xFFFFFFFCu;
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    sfera_sub_00421850(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00421980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004219B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax += 4u;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004219E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004219F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x80004001u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IOleInPlaceObject))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21A28u), LIFT_CODE_TOKEN_RVA(0x21A26u))) { return; }
    if (cpu->eax != 0u) goto label_00021A3E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21A3Eu), LIFT_CODE_TOKEN_RVA(0x21A3Cu))) { return; }
    label_00021A3E:
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x80004001u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x80004001u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (cpu->esi == 0u) goto label_00021AFD;
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421A9Du));
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21AB6u), LIFT_CODE_TOKEN_RVA(0x21AB4u))) { return; }
    if (cpu->eax != 0u) goto label_00021AFD;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x78u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21ACBu), LIFT_CODE_TOKEN_RVA(0x21AC9u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::WideCharToMultiByte), LIFT_CODE_TOKEN_VA(0x421AE0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SysFreeString), LIFT_CODE_TOKEN_VA(0x421AEBu));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21AFDu), LIFT_CODE_TOKEN_RVA(0x21AFBu))) { return; }
    label_00021AFD:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    cpu->ebx = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421C09u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21C22u), LIFT_CODE_TOKEN_RVA(0x21C20u))) { return; }
    if (cpu->eax != 0u) goto label_00021CE3;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::VariantInit), LIFT_CODE_TOKEN_VA(0x421C32u));
    cpu->ebp = native_function_address32(&::MultiByteToWideChar);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->edx = 8u;
    lift_push32(cpu, 0u);
    *(uint16_t*)(cpu->esp + 0x2Cu) = cpu->edx & 0xFFFFu;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x21C55u), LIFT_CODE_TOKEN_RVA(0x21C53u))) { return; }
    cpu->edi = cpu->eax;
    cpu->eax = cpu->edi + cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GlobalAlloc), LIFT_CODE_TOKEN_VA(0x421C5Du));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00021C8D;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x21C74u), LIFT_CODE_TOKEN_RVA(0x21C72u))) { return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::SysAllocString), LIFT_CODE_TOKEN_VA(0x421C75u));
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_VA(0x421C80u));
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != 0u) goto label_00021CA6;
    label_00021C8D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21C99u), LIFT_CODE_TOKEN_RVA(0x21C97u))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFAu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021CA6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xD0u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21CC2u), LIFT_CODE_TOKEN_RVA(0x21CC0u))) { return; }
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::VariantClear), LIFT_CODE_TOKEN_VA(0x421CC7u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21CD9u), LIFT_CODE_TOKEN_RVA(0x21CD7u))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021CE3:
    cpu->eax = 0xFFFFFFFBu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421CF7u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21D10u), LIFT_CODE_TOKEN_RVA(0x21D0Eu))) { return; }
    if (cpu->eax != 0u) goto label_00021D3E;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x68u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21D21u), LIFT_CODE_TOKEN_RVA(0x21D1Fu))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x70u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21D32u), LIFT_CODE_TOKEN_RVA(0x21D30u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21D3Eu), LIFT_CODE_TOKEN_RVA(0x21D3Cu))) { return; }
    label_00021D3E:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::GlobalAlloc), LIFT_CODE_TOKEN_VA(0x421D66u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_00021D86;
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021D86:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ebx + 4u;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ole_host_abi.storage_object_vtable); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, address32(&__uuidof(IOleObject))); lift_push32(cpu, address32(&__uuidof(WebBrowser)));
    *(uint32_t*)(cpu->esi) = (uintptr_t)&g_sfera_ole_host_abi.client_site_vtable[0];
    *(uint32_t*)(cpu->esi + 4u) = (uintptr_t)&g_sfera_ole_host_abi.inplace_site_vtable[0];
    *(uint32_t*)(cpu->esi + 8u) = (uintptr_t)&g_sfera_ole_host_abi.inplace_frame_vtable[0];
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x10u) = (uintptr_t)&g_sfera_ole_host_abi.doc_host_ui_handler_vtable[0];
    lift_native_call(cpu, native_function_address32(&::OleCreate), LIFT_CODE_TOKEN_VA(0x421DC1u));
    lift_push32(cpu, cpu->ebx);
    if (cpu->eax != 0u) goto label_00021EE8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebx) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x421DD9u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)L"My Host Name"); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21DF2u), LIFT_CODE_TOKEN_RVA(0x21DF0u))) { return; }
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetClientRect), LIFT_CODE_TOKEN_VA(0x421DF8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::OleSetContainedObject), LIFT_CODE_TOKEN_VA(0x421E05u));
    if (cpu->eax != 0u) goto label_00021EA7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x2Cu);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21E2Cu), LIFT_CODE_TOKEN_RVA(0x21E2Au))) { return; }
    if (cpu->eax != 0u) goto label_00021EA7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21E45u), LIFT_CODE_TOKEN_RVA(0x21E43u))) { return; }
    if (cpu->eax != 0u) goto label_00021EA7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x58u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21E57u), LIFT_CODE_TOKEN_RVA(0x21E55u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x60u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21E65u), LIFT_CODE_TOKEN_RVA(0x21E63u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x68u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21E76u), LIFT_CODE_TOKEN_RVA(0x21E74u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x70u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21E87u), LIFT_CODE_TOKEN_RVA(0x21E85u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21E93u), LIFT_CODE_TOKEN_RVA(0x21E91u))) { return; }
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021EA7:
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421EAAu));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00021ED1;
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ecx, LIFT_CODE_TOKEN_RVA(0x21EC2u), LIFT_CODE_TOKEN_RVA(0x21EC0u))) { return; }
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21ECAu), LIFT_CODE_TOKEN_RVA(0x21EC8u))) { return; }
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_RVA(0x21ECBu));
    label_00021ED1:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFDu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021EE8:
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_VA(0x421EE8u));
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFEu;
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->ecx;
    if ((--cpu->eax) == 0u) goto label_00021F86;
    if ((--cpu->eax) == 0u) goto label_00021F46;
    if ((cpu->eax -= 3u) == 0u) goto label_00021F2B;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    cpu->esp += 4u; lift_native_call(cpu, native_function_address32(&::DefWindowProcA), LIFT_CODE_TOKEN_VA(0x421F25u)); cpu->eip = stop_address; return;
    label_00021F2B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 16u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax & 0xFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421F41u)); sfera_sub_00421CF0(cpu, LIFT_CODE_TOKEN_VA(0x421F41u));
    cpu->eax = 0u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00021F46:
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421F4Eu));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00021F77;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ecx, LIFT_CODE_TOKEN_RVA(0x21F67u), LIFT_CODE_TOKEN_RVA(0x21F65u))) { return; }
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21F6Fu), LIFT_CODE_TOKEN_RVA(0x21F6Du))) { return; }
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_VA(0x421F70u));
    cpu->esi = lift_pop32(cpu);
    label_00021F77:
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00021F86:
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x421F8Fu)); sfera_sub_00421D50(cpu, LIFT_CODE_TOKEN_VA(0x421F8Fu));
    if (cpu->eax == 0u) goto label_00021F99;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00021F99:
    cpu->eax = 0u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx += 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    sfera_sub_00421850(cpu, stop_address); return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4220DEu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x4220DEu));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4220E7u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x4220E7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4220EEu)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x4220EEu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4221CEu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x4221CEu));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4221D7u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x4221D7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4221DEu)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x4221DEu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42220Cu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x42220Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ebx + cpu->ecx + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4004u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422229u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x422229u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422230u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x422230u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42276Eu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x42276Eu));
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422777u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x422777u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42277Eu)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x42277Eu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227CEu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x4227CEu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227DAu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4227DAu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227E1u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x4227E1u));
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
__declspec(noinline) void sfera_sub_00422910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    if (cpu->ecx == 0x20u) goto label_00022934;
    cpu->eax <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = ~((uint64_t)(cpu->eax));
    label_00022934:
    cpu->edx = 0x12u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422946u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x422946u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 0x1Fu;
    cpu->eax >>= 5u;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422963u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x422963u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax != 0u) goto label_00022977;
    cpu->ecx = (uintptr_t)"CDIB::Initialize(): failed to allocate memory block";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x22977u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x22977u));
    label_00022977:
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422999u)); sfera_sub_00422910(cpu, LIFT_CODE_TOKEN_VA(0x422999u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax += 0x1Fu;
    cpu->eax >>= 5u;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 8u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4229B4u));
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004229D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x23u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4229E2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4229E2u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4229EAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4229EAu));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004229F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 4u));
    cpu->edx += 0x1Fu;
    cpu->edx >>= 5u;
    cpu->edx *= *(uint32_t*)(cpu->esp + 8u);
    cpu->eax >>= 3u;
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->edx);
    cpu->eax &= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x60u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x80u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esp + 0x33u) = 1u;
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x422A6Au));
    cpu->ebx = cpu->eax;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_00022C8C;
    cpu->esi = native_function_address32(&::ReadFile);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xEu);
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x22A91u), LIFT_CODE_TOKEN_RVA(0x22A8Fu))) { return; }
    if (cpu->eax == 0u) goto label_00022C47;
    if (*(uint32_t*)(cpu->esp + 0x18u) != 0xEu) goto label_00022C47;
    cpu->edx = 0x4D42u;
    if (*(uint16_t*)(cpu->esp + 0x4Cu) != (cpu->edx & 0xFFFFu)) goto label_00022C47;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetFileSize), LIFT_CODE_TOKEN_VA(0x422AB6u));
    if (*(uint32_t*)(cpu->esp + 0x4Eu) != cpu->eax) goto label_00022C47;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ebp = 0x28u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x22ADAu), LIFT_CODE_TOKEN_RVA(0x22AD8u))) { return; }
    if (cpu->eax == 0u) goto label_00022C47;
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->ebp) goto label_00022C47;
    if (*(uint32_t*)(cpu->esp + 0x24u) != cpu->ebp) goto label_00022C47;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if ((int32_t)cpu->eax <= 0) goto label_00022C47;
    if (cpu->eax > 0x1000u) goto label_00022C47;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_00022C47;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if (cpu->eax > 0x1000u) goto label_00022C47;
    if (*(uint16_t*)(cpu->esp + 0x30u) != 1u) goto label_00022C47;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x32u));
    if ((cpu->eax & 0xFFFFu) == 0x18u) goto label_00022B4A;
    if ((cpu->eax & 0xFFFFu) != 0x20u) goto label_00022C47;
    label_00022B4A:
    if (*(uint32_t*)(cpu->esp + 0x34u) != cpu->edi) goto label_00022C47;
    cpu->edx = 0x78u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422B63u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x422B63u));
    lift_push32(cpu, 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422B6Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x422B6Au));
    cpu->ecx = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x68u) = 0u;
    if (cpu->ecx == 0u) goto label_00022B9D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    cpu->edx = *(uint16_t*)(cpu->esp + 0x32u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422B99u)); sfera_sub_00422980(cpu, LIFT_CODE_TOKEN_VA(0x422B99u));
    cpu->esi = cpu->eax;
    goto label_00022B9F;
    label_00022B9D:
    cpu->esi = 0u;
    label_00022B9F:
    *(uint32_t*)(cpu->esp + 0x68u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if (cpu->esi == 0u) goto label_00022C43;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if ((int32_t)cpu->edx >= 0) goto label_00022BBF;
    cpu->eax = 0u;
    goto label_00022BC2;
    label_00022BBF:
    cpu->eax = cpu->edx + 0xFFFFFFFFu;
    label_00022BC2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ecx);
    cpu->edi += 0x1Fu;
    cpu->edi >>= 5u;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->eax + (cpu->edi * 4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx = 0u;
    cpu->eax += 0x1Fu;
    cpu->eax >>= 5u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->edx)&0x80000000u)!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebp = 0u;
    cpu->ecx = cpu->ecx + cpu->ecx + 0xFFFFFFFFu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 8u) <= cpu->ebp) goto label_00022C3E;
    label_00022C02:
    lift_push32(cpu, 0u);
    cpu->eax += cpu->eax;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::ReadFile), LIFT_CODE_TOKEN_VA(0x422C10u));
    if (cpu->eax == 0u) goto label_00022C43;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 4u));
    cpu->eax += 0x1Fu;
    cpu->eax >>= 5u;
    cpu->ecx = cpu->eax * 4u;
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->ecx) goto label_00022C43;
    cpu->edi += *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->ebp;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 8u)) goto label_00022C02;
    label_00022C3E:
    *(uint8_t*)(cpu->esp + 0x17u) = 0u;
    label_00022C43:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00022C47:
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x422C48u));
    if (*(uint8_t*)(cpu->esp + 0x17u) == 0u) goto label_00022C8C;
    if (cpu->edi == 0u) goto label_00022C8C;
    cpu->edx = 0x96u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422C68u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x422C68u));
    cpu->edx = 0x23u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422C77u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x422C77u));
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422C7Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x422C7Fu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422C85u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x422C85u));
    cpu->esp += 8u;
    cpu->eax = 0u;
    goto label_00022C8E;
    label_00022C8C:
    cpu->eax = cpu->edi;
    label_00022C8E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422CB0(LiftCpu* cpu, uint32_t stop_address) { double x87_p0, x87_p1;
    cpu->esp -= 0x338u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    cpu->esi = 0u;
    label_00022CD6:
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x22CD8u), LIFT_CODE_TOKEN_RVA(0x22CD6u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + cpu->esi + 0x24u) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) / (32767.0)))) * (6.2831854820251465));
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x22CF2u), LIFT_CODE_TOKEN_RVA(0x22CF0u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->esi += 4u;
    x87_p0 = (x87_p0) / (32767.0);
    x87_p0 = (x87_p0) + (1.0);
    *(float*)(cpu->esp + cpu->esi + 0x1B0u) = x87_p0; 
    if ((int32_t)cpu->esi < (int32_t)0x190u) goto label_00022CD6;
    x87_p0 = (double)-1.0f;
    cpu->ebx = 0u;
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->ebp += 0x474u;
    label_00022D30:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->esi = 0u;
    x87_p0 = (x87_p0) * (0.006135923322290182);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    *(float*)(cpu->esp + 0x14u) = (double)(0.0);
    label_00022D50:
    cpu->edi = cpu->esi + 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    *(float*)(cpu->esp + 0x18u) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))))) * (((double)*(float*)(cpu->esp + 0x1Cu)))))) + (((double)*(float*)(cpu->esp + (cpu->esi * 4u) + 0x24u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + (cpu->esi * 4u) + 0x1B4u)));
    cpu->esi = cpu->edi;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    if ((int32_t)cpu->esi < (int32_t)0x64u) goto label_00022D50;
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->ebp) = x87_p0;
    x87_p0 = fabs(x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=cpu->fpu[0u]; if (!(lift_left<lift_right)) goto label_00022DBA; }
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); goto label_00022DBC;
    label_00022DBA:
    cpu->fpu[0u] = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); label_00022DBC:
    ++cpu->ebx;
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)0x400u) goto label_00022D30;
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_p1 = 1.0;
    cpu->edi = lift_pop32(cpu);
    x87_p0 = x87_p1 / x87_p0; 
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax += 0x478u;
    cpu->ecx = 0x80u;
    cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp);
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; label_00022DF0:
    x87_p0 = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    cpu->eax += 0x20u;
    --cpu->ecx;
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    *(float*)(cpu->eax + 0xFFFFFFDCu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax + 0xFFFFFFE0u);
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    *(float*)(cpu->eax + 0xFFFFFFE0u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax + 0xFFFFFFE4u);
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    *(float*)(cpu->eax + 0xFFFFFFE4u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax + 0xFFFFFFE8u);
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    *(float*)(cpu->eax + 0xFFFFFFE8u) = x87_p0; 
    x87_p0 = cpu->fpu[0u];
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->eax + 0xFFFFFFECu)));
    *(float*)(cpu->eax + 0xFFFFFFECu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax + 0xFFFFFFF0u);
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    *(float*)(cpu->eax + 0xFFFFFFF0u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax + 0xFFFFFFF4u);
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    *(float*)(cpu->eax + 0xFFFFFFF4u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->eax + 0xFFFFFFF8u);
    x87_p0 = (x87_p0) * (cpu->fpu[0u]);
    *(float*)(cpu->eax + 0xFFFFFFF8u) = x87_p0; 
    if (cpu->ecx != 0u) goto label_00022DF0;
    cpu->fpu[0u] = cpu->fpu[0u]; 
    cpu->esp += 0x338u;
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422E50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[5]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    cpu->esp -= 0x1C0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1C8u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if (cpu->eax == 0u) goto label_00023E5F;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 0x1D0u) == 0u;
    *(uint32_t*)(cpu->esp + 0x44u) = 0u;
    if (!sub_pred[0]) goto label_00022E8C;
    *(uint32_t*)(cpu->esp + 0x44u) = 1u;
    label_00022E8C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1D0u);
    x87_v0 = 5.0;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebp = 0u;
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x190u) == 0xFFFFFFFFu;
    cpu->edx = cpu->esi + 0x190u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if (sub_pred[1]) goto label_00022F19;
    x87_v1 = (double)*(float*)(cpu->edx + 0x18u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00022F19; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00022F19; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00022F19; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00022F19; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    cpu->edi = 1u;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    *(uint32_t*)(cpu->esp + 0x1A4u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_00022F19:
    cpu->edx = cpu->esi + 0x1C8u;
    if (*(uint32_t*)(cpu->esi + 0x1C8u) == 0xFFFFFFFFu) goto label_00022F87;
    x87_v1 = (double)*(float*)(cpu->edx + 0x18u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00022F87; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00022F87; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00022F87; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00022F87; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x1A4u) = cpu->edx;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_00022F87:
    cpu->edx = cpu->esi + 0x200u;
    if (*(uint32_t*)(cpu->esi + 0x200u) == 0xFFFFFFFFu) goto label_00022FF5;
    x87_v1 = (double)*(float*)(cpu->edx + 0x18u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00022FF5; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00022FF5; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00022FF5; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00022FF5; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x1A4u) = cpu->edx;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_00022FF5:
    cpu->edx = cpu->esi + 0x238u;
    if (*(uint32_t*)(cpu->esi + 0x238u) == 0xFFFFFFFFu) goto label_00023063;
    x87_v1 = (double)*(float*)(cpu->edx + 0x18u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023063; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023063; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023063; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023063; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x1A4u) = cpu->edx;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_00023063:
    cpu->edx = cpu->esi + 0x270u;
    if (*(uint32_t*)(cpu->esi + 0x270u) == 0xFFFFFFFFu) goto label_000230D3;
    x87_v1 = (double)*(float*)(cpu->edx + 0x18u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_000230D3; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_000230D3; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_000230D3; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v0 = x87_v2 - x87_v0; 
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_000230D5; }
    x87_v0 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x1A4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx)));
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(float*)(cpu->edx + 0xCu) = x87_v0; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    goto label_000230D5;
    label_000230D3:
    x87_v0 = x87_v0; 
    label_000230D5:
    x87_v0 = 8.0;
    cpu->edx = cpu->esi + 0x1474u;
    if (*(uint32_t*)(cpu->esi + 0x1474u) == cpu->ebp) goto label_0002314C;
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_0002314C; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_0002314C; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_0002314C; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x28u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_0002314C; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    cpu->ebp = 1u;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    *(uint32_t*)(cpu->esp + 0x1B8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_0002314C:
    cpu->edx = cpu->esi + 0x14A4u;
    if (*(uint32_t*)(cpu->esi + 0x14A4u) == 0u) goto label_000231BA;
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_000231BA; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_000231BA; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_000231BA; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x28u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_000231BA; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->ebp * 4u) + 0x1B8u) = cpu->edx;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_000231BA:
    cpu->edx = cpu->esi + 0x14D4u;
    if (*(uint32_t*)(cpu->esi + 0x14D4u) == 0u) goto label_00023228;
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023228; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023228; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023228; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x28u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023228; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->ebp * 4u) + 0x1B8u) = cpu->edx;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_00023228:
    cpu->edx = cpu->esi + 0x1504u;
    if (*(uint32_t*)(cpu->esi + 0x1504u) == 0u) goto label_00023296;
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023296; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023296; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023296; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x28u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023296; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->ebp * 4u) + 0x1B8u) = cpu->edx;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_00023296:
    cpu->edx = cpu->esi + 0x1534u;
    if (*(uint32_t*)(cpu->esi + 0x1534u) == 0u) goto label_00023304;
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023304; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023304; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023304; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x28u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023304; }
    x87_v1 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->ebp * 4u) + 0x1B8u) = cpu->edx;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ecx)));
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(float*)(cpu->edx + 0xCu) = x87_v1; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    label_00023304:
    cpu->edx = cpu->esi + 0x1564u;
    if (*(uint32_t*)(cpu->esi + 0x1564u) == 0u) goto label_00023374;
    x87_v1 = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023374; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v2 = (x87_v2) - (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left<lift_right)) goto label_00023374; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x20u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v2 = (x87_v2) + (x87_v0);
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (!(lift_left>lift_right)) goto label_00023374; }
    x87_v1 = (double)*(float*)(cpu->edx + 0x28u);
    x87_v2 = (double)*(float*)(cpu->ecx + 8u);
    x87_v0 = x87_v2 - x87_v0; 
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_00023376; }
    x87_v0 = (double)*(float*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + (cpu->ebp * 4u) + 0x1B8u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx)));
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(float*)(cpu->edx + 0xCu) = x87_v0; 
    *(float*)(cpu->edx + 0x10u) = ((((double)*(float*)(cpu->edx + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    goto label_00023376;
    label_00023374:
    x87_v0 = x87_v0; 
    label_00023376:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    if ((cpu->ecx == *(uint32_t*)(cpu->esi + 0x2B8u)) || ((int32_t)(cpu->ecx) < (int32_t)(*(uint32_t*)(cpu->esi + 0x2B8u)))) goto label_000233BA;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2B4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x2B8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4233ABu));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esi + 0x2B4u) = cpu->eax;
    label_000233BA:
    sub_pred[2] = *(uint32_t*)(cpu->ebx + 0x20u) == 0u; sub_pred[4] = (int32_t)(*(uint32_t*)(cpu->ebx + 0x20u)) < (int32_t)(0u);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1D0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2B4u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0u;
    if ((sub_pred[2]) || (sub_pred[4])) goto label_00023E5D;
    x87_v0 = 0.5;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    x87_v1 = 1.0;
    cpu->edx = cpu->eax;
    x87_v2 = 0.15000000596046448;
    cpu->edi = cpu->ebp + 8u;
    x87_v3 = 0.05999999865889549;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    x87_v4 = 0.800000011920929;
    cpu->ebx = cpu->edx + 0x14u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    label_00023419:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ebx + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->ebx + 0xFFFFFFFCu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ecx);
    cpu->ecx = 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    if ((cpu->eax & 0xFFFFu) != (cpu->ecx & 0xFFFFu)) goto label_00023455;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    goto label_00023E17;
    label_00023455:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint16_t*)(cpu->ecx + 4u) == 0u) goto label_0002347A;
    { const double lift_left=(double)0.0010000000474974513f; const double lift_right=((double)*(float*)(cpu->esp + 0x2Cu)); if (lift_left<lift_right) goto label_00023509; }
    goto label_00023637;
    label_0002347A:
    x87_v5 = 0.0;
    cpu->ecx = 0u;
    *(float*)(cpu->esp + 0x2Cu) = x87_v5; 
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x20u) <= (int32_t)cpu->ecx) goto label_000235E8;
    label_0002348C:
    cpu->edx = *(uint32_t*)(cpu->esp + (cpu->ecx * 4u) + 0x1A4u);
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->ebp))) - (((double)*(float*)(cpu->edx + 0xCu))));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->edi))) - (((double)*(float*)(cpu->edx + 0x10u))));
    x87_v5 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v6 = (x87_v6) * (x87_v6);
    x87_v7 = x87_v5;
    x87_v5 = x87_v5 * x87_v7; 
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->edx + 0x14u);
    { const double lift_left=x87_v6; const double lift_right=x87_v5;   if (lift_left<lift_right) goto label_000234ED; }
    { const double lift_left=(double)*(float*)(cpu->edx + 0x28u); const double lift_right=0.9990000128746033; if (lift_left>lift_right) goto label_000235DD; }
    { const double lift_right=(double)*(float*)(cpu->edx + 0x28u); const double lift_left=(double)*(float*)(cpu->esp + 0x2Cu); if (!(lift_left<lift_right)) goto label_000234ED; }
    *(float*)(cpu->esp + 0x2Cu) = (double)*(float*)(cpu->edx + 0x28u);
    label_000234ED:
    ++cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_0002348C;
    { const double lift_left=(double)0.0010000000474974513f; const double lift_right=((double)*(float*)(cpu->esp + 0x2Cu)); if (!(lift_left<lift_right)) goto label_000235E8; }
    label_00023509:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1D4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1CCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v5 = (double)*(float*)(cpu->eax + cpu->ecx + 0x18u);
    cpu->eax = cpu->eax + cpu->ecx + 0x18u;
    x87_v5 = (x87_v5) - (((double)*(float*)(cpu->ebp)));
    *(float*)(cpu->esp + 0xB4u) = x87_v5; 
    *(float*)(cpu->esp + 0xB8u) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->edi + 0xFFFFFFFCu))));
    *(float*)(cpu->esp + 0xBCu) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->edi))));
    x87_v5 = (double)*(float*)(cpu->esp + 0xB4u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->esp + 0x84u) = x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 0xB8u);
    x87_v6 = (x87_v6) * (x87_v5);
    *(float*)(cpu->esp + 0x88u) = x87_v6; 
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esp + 0xBCu)));
    *(float*)(cpu->esp + 0x8Cu) = x87_v5; 
    *(float*)(cpu->esp + 0x18Cu) = ((((double)*(float*)(cpu->ebp))) + (((double)*(float*)(cpu->esp + 0x84u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18Cu);
    *(float*)(cpu->esp + 0x190u) = ((((double)*(float*)(cpu->esp + 0x88u))) + (((double)*(float*)(cpu->edi + 0xFFFFFFFCu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x190u);
    *(float*)(cpu->esp + 0x194u) = ((((double)*(float*)(cpu->esp + 0x8Cu))) + (((double)*(float*)(cpu->edi))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x194u);
    x87_v5 = (double)*(float*)(cpu->ebx + 0xFFFFFFF8u);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->ebx + 0xFFFFFFF8u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->ebx + 0xFFFFFFFCu);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->ebx + 0xFFFFFFFCu) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->ebx);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->ebx) = x87_v5; 
    goto label_00023D43;
    label_000235DD:
    *(float*)(cpu->esp + 0x2Cu) = (double)(1.0);
    goto label_00023509;
    label_000235E8:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) <= (int32_t)cpu->ecx) goto label_00023642;
    label_000235F4:
    cpu->edx = *(uint32_t*)(cpu->esp + (cpu->ecx * 4u) + 0x1B8u);
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->ebp))) - (((double)*(float*)(cpu->edx + 0xCu))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->edi))) - (((double)*(float*)(cpu->edx + 0x10u))));
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v6 = (x87_v6) * (x87_v6);
    x87_v7 = x87_v5;
    x87_v5 = x87_v5 * x87_v7; 
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->edx + 0x18u);
    { const double lift_left=x87_v6; const double lift_right=x87_v5;   if (lift_left>lift_right) goto label_00023633; }
    ++cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x18u)) goto label_000235F4;
    goto label_00023642;
    label_00023633:
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    label_00023637:
    if (*(uint32_t*)(cpu->esp + 0x40u) != 0u) goto label_0002398A;
    label_00023642:
    cpu->eax = 0xFDE8u;
    if (*(uint16_t*)(cpu->esp + 0x44u) <= (cpu->eax & 0xFFFFu)) goto label_00023730;
    x87_v5 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esi + 0x470u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v5); 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->ecx + 2u);
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax &= 0x3FFu;
    x87_v5 = (double)*(float*)(cpu->esi + (cpu->eax * 4u) + 0x474u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1D4u);
    x87_v5 = (x87_v5) + (x87_v1);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1CCu);
    cpu->eax = cpu->ecx + cpu->edx + 0x18u;
    x87_v5 = (x87_v5) * (x87_v0);
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esi + 0x470u)));
    *(float*)(cpu->esp + 0x10u) = x87_v5; 
    *(float*)(cpu->esp + 0x9Cu) = ((((double)*(float*)(cpu->eax))) - (((double)*(float*)(cpu->ebp))));
    *(float*)(cpu->esp + 0xA0u) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->edi + 0xFFFFFFFCu))));
    *(float*)(cpu->esp + 0xA4u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->edi))));
    x87_v5 = (double)*(float*)(cpu->esp + 0x9Cu);
    x87_v6 = (double)*(float*)(cpu->esp + 0x10u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->esp + 0x12Cu) = x87_v6; 
    x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0xA0u)));
    *(float*)(cpu->esp + 0x130u) = x87_v6; 
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esp + 0xA4u)));
    *(float*)(cpu->esp + 0x134u) = x87_v5; 
    *(float*)(cpu->esp + 0x6Cu) = ((((double)*(float*)(cpu->ebp))) + (((double)*(float*)(cpu->esp + 0x12Cu))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(float*)(cpu->esp + 0x70u) = ((((double)*(float*)(cpu->edi + 0xFFFFFFFCu))) + (((double)*(float*)(cpu->esp + 0x130u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    *(float*)(cpu->esp + 0x74u) = ((((double)*(float*)(cpu->edi))) + (((double)*(float*)(cpu->esp + 0x134u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    goto label_00023D43;
    label_00023730:
    x87_v1 = x87_v4; 
    x87_v1 = x87_v3; 
    x87_v2 = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0x470u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->ecx + 2u);
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0x3FFu;
    cpu->eax += 0xFFFFFE00u;
    cpu->eax &= 0x3FFu;
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x474u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1D4u);
    x87_v2 = (x87_v2) * (x87_v1);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0x470u)));
    *(float*)(cpu->esp + 0x28u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + (cpu->eax * 4u) + 0x474u)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += *(uint32_t*)(cpu->ecx + 0x1CCu);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x470u)));
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xE4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0xE8u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 0x14u)));
    *(float*)(cpu->esp + 0xECu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->eax);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xCCu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->eax + 4u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0xD0u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 8u)));
    cpu->eax = *(uint16_t*)(cpu->esp + 0x44u);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(float*)(cpu->esp + 0xD4u) = x87_v0; 
    cpu->ebp = cpu->eax + (cpu->edx * 4u);
    *(float*)(cpu->esp + 0x174u) = ((((double)*(float*)(cpu->ecx))) - (((double)*(float*)(cpu->ebp))));
    *(float*)(cpu->esp + 0x178u) = ((((double)*(float*)(cpu->edi + 0xFFFFFFFCu))) - (((double)*(float*)(cpu->ebp + 4u))));
    *(float*)(cpu->esp + 0x17Cu) = ((((double)*(float*)(cpu->edi))) - (((double)*(float*)(cpu->ebp + 8u))));
    *(float*)(cpu->esp + 0x144u) = ((((double)*(float*)(cpu->esp + 0x174u))) + (((double)*(float*)(cpu->esp + 0xCCu))));
    *(float*)(cpu->esp + 0x148u) = ((((double)*(float*)(cpu->esp + 0x178u))) + (((double)*(float*)(cpu->esp + 0xD0u))));
    *(float*)(cpu->esp + 0x14Cu) = ((((double)*(float*)(cpu->esp + 0x17Cu))) + (((double)*(float*)(cpu->esp + 0xD4u))));
    *(float*)(cpu->esp + 0x50u) = ((((double)*(float*)(cpu->esp + 0x144u))) + (((double)*(float*)(cpu->esp + 0xE4u))));
    *(float*)(cpu->esp + 0x54u) = ((((double)*(float*)(cpu->esp + 0x148u))) + (((double)*(float*)(cpu->esp + 0xE8u))));
    *(float*)(cpu->esp + 0x58u) = ((((double)*(float*)(cpu->esp + 0x14Cu))) + (((double)*(float*)(cpu->esp + 0xECu))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x50u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x54u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x58u);
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
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v1 = 1.0;
    x87_v2 = x87_v1;
    x87_v0 = x87_v2 / x87_v0; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x50u)));
    *(float*)(cpu->esp + 0x198u) = x87_v2; 
    x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x54u)));
    *(float*)(cpu->esp + 0x19Cu) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x58u)));
    *(float*)(cpu->esp + 0x1A0u) = x87_v1; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->edx + 8u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x198u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0xFCu) = x87_v2; 
    x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x19Cu)));
    *(float*)(cpu->esp + 0x100u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x1A0u)));
    *(float*)(cpu->esp + 0x104u) = x87_v1; 
    *(float*)(cpu->esp + 0x15Cu) = ((((double)*(float*)(cpu->esp + 0xFCu))) + (((double)*(float*)(cpu->ebp))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x15Cu);
    *(float*)(cpu->esp + 0x160u) = ((((double)*(float*)(cpu->ebp + 4u))) + (((double)*(float*)(cpu->esp + 0x100u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x160u);
    *(float*)(cpu->esp + 0x164u) = ((((double)*(float*)(cpu->ebp + 8u))) + (((double)*(float*)(cpu->esp + 0x104u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x164u);
    goto label_00023D1D;
    label_0002398A:
    cpu->eax = 0xFDE8u;
    if (*(uint16_t*)(cpu->esp + 0x44u) <= (cpu->eax & 0xFFFFu)) goto label_00023A98;
    x87_v5 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esi + 0x470u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v5); 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->ecx + 2u);
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax &= 0x3FFu;
    x87_v5 = (double)*(float*)(cpu->esi + (cpu->eax * 4u) + 0x474u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1D4u);
    x87_v5 = (x87_v5) + (x87_v1);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1CCu);
    cpu->eax = cpu->ecx + cpu->edx + 0x18u;
    x87_v5 = (x87_v5) * (x87_v0);
    x87_v5 = (x87_v5) * (0.25);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esi + 0x470u)));
    *(float*)(cpu->esp + 0x10u) = x87_v5; 
    *(float*)(cpu->esp + 0x114u) = ((((double)*(float*)(cpu->eax))) - (((double)*(float*)(cpu->ebp))));
    *(float*)(cpu->esp + 0x118u) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->edi + 0xFFFFFFFCu))));
    *(float*)(cpu->esp + 0x11Cu) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->edi))));
    x87_v5 = (double)*(float*)(cpu->esp + 0x114u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x10u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->esp + 0x78u) = x87_v6; 
    x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x118u)));
    *(float*)(cpu->esp + 0x7Cu) = x87_v6; 
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esp + 0x11Cu)));
    *(float*)(cpu->esp + 0x80u) = x87_v5; 
    *(float*)(cpu->esp + 0x90u) = ((((double)*(float*)(cpu->ebp))) + (((double)*(float*)(cpu->esp + 0x78u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x90u);
    *(float*)(cpu->esp + 0x94u) = ((((double)*(float*)(cpu->edi + 0xFFFFFFFCu))) + (((double)*(float*)(cpu->esp + 0x7Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x94u);
    *(float*)(cpu->esp + 0x98u) = ((((double)*(float*)(cpu->edi))) + (((double)*(float*)(cpu->esp + 0x80u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x98u);
    x87_v5 = (double)*(float*)(cpu->ebx + 0xFFFFFFF8u);
    x87_v5 = (x87_v5) * (x87_v4);
    *(float*)(cpu->ebx + 0xFFFFFFF8u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->ebx + 0xFFFFFFFCu);
    x87_v5 = (x87_v5) * (x87_v4);
    *(float*)(cpu->ebx + 0xFFFFFFFCu) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->ebx);
    x87_v5 = (x87_v5) * (x87_v4);
    *(float*)(cpu->ebx) = x87_v5; 
    goto label_00023D43;
    label_00023A98:
    x87_v1 = x87_v4; 
    x87_v1 = x87_v3; 
    x87_v2 = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0x470u)));
    x87_v2 = (x87_v2) * (-3.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint16_t*)(cpu->ecx + 2u);
    cpu->ecx -= cpu->eax;
    cpu->edx = cpu->ecx;
    cpu->edx &= 0x3FFu;
    cpu->ecx += 0xFFFFFE00u;
    cpu->ecx &= 0x3FFu;
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x474u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    x87_v2 = (x87_v2) * (x87_v1);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0x470u)));
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esi + 0x468u)));
    *(float*)(cpu->esp + 0x28u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x474u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1D4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1CCu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x470u)));
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x24u);
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x46Cu)));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xF0u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0xF4u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 0x14u)));
    *(float*)(cpu->esp + 0xF8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->eax);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xC0u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->eax + 4u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0xC4u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 8u)));
    cpu->eax = *(uint16_t*)(cpu->esp + 0x44u);
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->ebp = cpu->ecx + (cpu->eax * 4u);
    *(float*)(cpu->esp + 0xC8u) = x87_v0; 
    *(float*)(cpu->esp + 0xA8u) = ((((double)*(float*)(cpu->edx))) - (((double)*(float*)(cpu->ebp))));
    *(float*)(cpu->esp + 0xACu) = ((((double)*(float*)(cpu->edi + 0xFFFFFFFCu))) - (((double)*(float*)(cpu->ebp + 4u))));
    *(float*)(cpu->esp + 0xB0u) = ((((double)*(float*)(cpu->edi))) - (((double)*(float*)(cpu->ebp + 8u))));
    *(float*)(cpu->esp + 0xD8u) = ((((double)*(float*)(cpu->esp + 0xA8u))) + (((double)*(float*)(cpu->esp + 0xC0u))));
    *(float*)(cpu->esp + 0xDCu) = ((((double)*(float*)(cpu->esp + 0xACu))) + (((double)*(float*)(cpu->esp + 0xC4u))));
    *(float*)(cpu->esp + 0xE0u) = ((((double)*(float*)(cpu->esp + 0xB0u))) + (((double)*(float*)(cpu->esp + 0xC8u))));
    *(float*)(cpu->esp + 0x60u) = ((((double)*(float*)(cpu->esp + 0xD8u))) + (((double)*(float*)(cpu->esp + 0xF0u))));
    *(float*)(cpu->esp + 0x64u) = ((((double)*(float*)(cpu->esp + 0xDCu))) + (((double)*(float*)(cpu->esp + 0xF4u))));
    *(float*)(cpu->esp + 0x68u) = ((((double)*(float*)(cpu->esp + 0xE0u))) + (((double)*(float*)(cpu->esp + 0xF8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x60u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x64u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x68u);
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
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v1 = 1.0;
    x87_v2 = x87_v1;
    x87_v0 = x87_v2 / x87_v0; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x60u)));
    *(float*)(cpu->esp + 0x108u) = x87_v2; 
    x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x64u)));
    *(float*)(cpu->esp + 0x10Cu) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x68u)));
    *(float*)(cpu->esp + 0x110u) = x87_v1; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->eax + 8u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x108u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x120u) = x87_v2; 
    x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x10Cu)));
    *(float*)(cpu->esp + 0x124u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x110u)));
    *(float*)(cpu->esp + 0x128u) = x87_v1; 
    *(float*)(cpu->esp + 0x138u) = ((((double)*(float*)(cpu->esp + 0x120u))) + (((double)*(float*)(cpu->ebp))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x138u);
    *(float*)(cpu->esp + 0x13Cu) = ((((double)*(float*)(cpu->ebp + 4u))) + (((double)*(float*)(cpu->esp + 0x124u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x13Cu);
    *(float*)(cpu->esp + 0x140u) = ((((double)*(float*)(cpu->ebp + 8u))) + (((double)*(float*)(cpu->esp + 0x128u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x140u);
    x87_v1 = (double)*(float*)(cpu->ebx + 0xFFFFFFF8u);
    x87_v2 = 0.75;
    x87_v1 = (x87_v1) * (x87_v2);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->ebx + 0xFFFFFFF8u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ebx + 0xFFFFFFFCu);
    x87_v2 = (x87_v2) * (x87_v1);
    *(float*)(cpu->ebx + 0xFFFFFFFCu) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->ebx)));
    *(float*)(cpu->ebx) = x87_v1; 
    label_00023D1D:
    x87_v1 = 0.800000011920929;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    x87_v2 = 0.05999999865889549;
    x87_v3 = 0.15000000596046448;
    x87_v4 = 0.5;
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    label_00023D43:
    sub_pred[3] = *(uint32_t*)(cpu->esp + 0x4Cu) == 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if (sub_pred[3]) goto label_00023D6B;
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    goto label_00023E17;
    label_00023D6B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    *(float*)(cpu->esp + 0x150u) = ((((double)*(float*)(cpu->esp + 0x30u))) - (((double)*(float*)(cpu->eax))));
    *(float*)(cpu->esp + 0x154u) = ((((double)*(float*)(cpu->esp + 0x34u))) - (((double)*(float*)(cpu->eax + 4u))));
    *(float*)(cpu->esp + 0x158u) = ((((double)*(float*)(cpu->esp + 0x38u))) - (((double)*(float*)(cpu->eax + 8u))));
    x87_v5 = (double)*(float*)(cpu->esp + 0x150u);
    x87_v5 = (x87_v5) * (x87_v2);
    *(float*)(cpu->esp + 0x168u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x154u);
    x87_v5 = (x87_v5) * (x87_v2);
    *(float*)(cpu->esp + 0x16Cu) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x158u);
    x87_v5 = (x87_v5) * (x87_v2);
    *(float*)(cpu->esp + 0x170u) = x87_v5; 
    *(float*)(cpu->esp + 0x180u) = ((((double)*(float*)(cpu->esp + 0x168u))) + (((double)*(float*)(cpu->eax))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x180u);
    *(float*)(cpu->esp + 0x184u) = ((((double)*(float*)(cpu->eax + 4u))) + (((double)*(float*)(cpu->esp + 0x16Cu))));
    x87_v5 = (double)*(float*)(cpu->esp + 0x170u);
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->eax + 8u)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x184u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    *(float*)(cpu->esp + 0x188u) = x87_v5; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x188u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    label_00023E17:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1D4u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x48u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x48u)) + (uint64_t)(0x18u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->ebp += 0x24u;
    cpu->edx += 0x18u;
    cpu->edi += 0x24u;
    cpu->ebx += 0x18u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ecx + 0x20u)) goto label_00023419;
    x87_v3 = x87_v4; 
    x87_v0 = x87_v3; 
    x87_v1 = x87_v2; 
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00023E5D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00023E5F:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1C0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00423E70(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0xE0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0x1C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp == 0u) goto label_000243AD;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 0x1D0u) == 0u;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    if (!sub_pred[0]) goto label_00023EA9;
    *(uint32_t*)(cpu->esp + 0x30u) = 1u;
    label_00023EA9:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    if ((cpu->ecx == *(uint32_t*)(cpu->esi + 0x2B8u)) || ((int32_t)(cpu->ecx) < (int32_t)(*(uint32_t*)(cpu->esi + 0x2B8u)))) goto label_00023EED;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2B4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x2B8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x423EDEu));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esi + 0x2B4u) = cpu->eax;
    label_00023EED:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1D0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2B4u);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x24u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x20u) <= (int32_t)cpu->ecx) goto label_000243AC;
    x87_v0 = 0.0;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(float*)(cpu->esp + 0x60u) = x87_v0;
    cpu->ecx = cpu->eax + 0xCu;
    x87_v1 = (double)-1.0f;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(float*)(cpu->esp + 0x64u) = x87_v1; 
    *(float*)(cpu->esp + 0x68u) = x87_v0; 
    x87_v0 = 1.0;
    x87_v1 = 0.5;
    x87_v2 = 0.05999999865889549;
    x87_v3 = 0.4000000059604645;
    label_00023F47:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    cpu->ecx = *(uint16_t*)(cpu->ebp);
    cpu->edx = 0xFFFFu;
    if ((cpu->ecx & 0xFFFFu) != (cpu->edx & 0xFFFFu)) goto label_00023F7E;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    goto label_00024370;
    label_00023F7E:
    cpu->edx = 0xFDE8u;
    if ((cpu->ecx & 0xFFFFu) <= (cpu->edx & 0xFFFFu)) goto label_00024057;
    x87_v4 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esi + 0x470u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v4); 
    cpu->ecx = *(uint16_t*)(cpu->ebp + 2u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1CCu);
    cpu->eax += cpu->ecx;
    cpu->eax &= 0x3FFu;
    x87_v4 = (double)*(float*)(cpu->esi + (cpu->eax * 4u) + 0x474u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v4 = (x87_v4) + (x87_v0);
    cpu->eax = cpu->edx + cpu->eax + 0x18u;
    x87_v4 = (x87_v4) * (x87_v1);
    x87_v4 = (x87_v4) * (0.15000000596046448);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esi + 0x470u)));
    *(float*)(cpu->esp + 0x20u) = x87_v4; 
    *(float*)(cpu->esp + 0x48u) = ((((double)*(float*)(cpu->eax))) - (((double)*(float*)(cpu->edi))));
    *(float*)(cpu->esp + 0x4Cu) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->edi + 4u))));
    *(float*)(cpu->esp + 0x50u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->edi + 8u))));
    x87_v4 = (double)*(float*)(cpu->esp + 0x48u);
    x87_v5 = (double)*(float*)(cpu->esp + 0x20u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0xA8u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x4Cu);
    x87_v5 = (x87_v5) * (x87_v4);
    *(float*)(cpu->esp + 0xACu) = x87_v5; 
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esp + 0x50u)));
    *(float*)(cpu->esp + 0xB0u) = x87_v4; 
    *(float*)(cpu->esp + 0x78u) = ((((double)*(float*)(cpu->edi))) + (((double)*(float*)(cpu->esp + 0xA8u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    *(float*)(cpu->esp + 0x7Cu) = ((((double)*(float*)(cpu->esp + 0xACu))) + (((double)*(float*)(cpu->edi + 4u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(float*)(cpu->esp + 0x80u) = ((((double)*(float*)(cpu->esp + 0xB0u))) + (((double)*(float*)(cpu->edi + 8u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    goto label_00024294;
    label_00024057:
    x87_v0 = x87_v3; 
    x87_v0 = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0x470u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    cpu->ecx = *(uint16_t*)(cpu->ebp + 2u);
    cpu->eax += cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->edx &= 0x3FFu;
    cpu->eax += 0xFFFFFE00u;
    cpu->eax &= 0x3FFu;
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x474u);
    x87_v2 = (x87_v2) * (x87_v0);
    x87_v2 = (x87_v2) * (x87_v1);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0x470u)));
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + (cpu->eax * 4u) + 0x474u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1CCu);
    x87_v0 = x87_v0 * x87_v2; 
    cpu->eax += *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (x87_v0) * (x87_v1);
    x87_v2 = (double)*(float*)(cpu->esi + 0x470u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x54u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x58u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 0x14u)));
    *(float*)(cpu->esp + 0x5Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->eax);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x90u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->eax + 4u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x94u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 8u)));
    cpu->eax = *(uint16_t*)(cpu->ebp);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    *(float*)(cpu->esp + 0x98u) = x87_v0; 
    cpu->ebx = cpu->eax + (cpu->edx * 4u);
    *(float*)(cpu->esp + 0xD8u) = ((((double)*(float*)(cpu->edi))) - (((double)*(float*)(cpu->ebx))));
    *(float*)(cpu->esp + 0xDCu) = ((((double)*(float*)(cpu->edi + 4u))) - (((double)*(float*)(cpu->ebx + 4u))));
    *(float*)(cpu->esp + 0xE0u) = ((((double)*(float*)(cpu->edi + 8u))) - (((double)*(float*)(cpu->ebx + 8u))));
    *(float*)(cpu->esp + 0xC0u) = ((((double)*(float*)(cpu->esp + 0xD8u))) + (((double)*(float*)(cpu->esp + 0x90u))));
    *(float*)(cpu->esp + 0xC4u) = ((((double)*(float*)(cpu->esp + 0xDCu))) + (((double)*(float*)(cpu->esp + 0x94u))));
    *(float*)(cpu->esp + 0xC8u) = ((((double)*(float*)(cpu->esp + 0xE0u))) + (((double)*(float*)(cpu->esp + 0x98u))));
    *(float*)(cpu->esp + 0x3Cu) = ((((double)*(float*)(cpu->esp + 0xC0u))) + (((double)*(float*)(cpu->esp + 0x54u))));
    *(float*)(cpu->esp + 0x40u) = ((((double)*(float*)(cpu->esp + 0xC4u))) + (((double)*(float*)(cpu->esp + 0x58u))));
    *(float*)(cpu->esp + 0x44u) = ((((double)*(float*)(cpu->esp + 0xC8u))) + (((double)*(float*)(cpu->esp + 0x5Cu))));
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
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = 1.0;
    x87_v2 = x87_v1;
    x87_v0 = x87_v2 / x87_v0; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x6Cu) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x40u);
    x87_v2 = (x87_v2) * (x87_v1);
    *(float*)(cpu->esp + 0x70u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0x74u) = x87_v1; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->ebp + 8u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x6Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x84u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x70u);
    x87_v2 = (x87_v2) * (x87_v1);
    *(float*)(cpu->esp + 0x88u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x74u)));
    *(float*)(cpu->esp + 0x8Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x9Cu) = ((((double)*(float*)(cpu->esp + 0x84u))) + (((double)*(float*)(cpu->ebx))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x9Cu);
    *(float*)(cpu->esp + 0xA0u) = ((((double)*(float*)(cpu->ebx + 4u))) + (((double)*(float*)(cpu->esp + 0x88u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xA0u);
    x87_v1 = (double)*(float*)(cpu->ebx + 8u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xF4u);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x8Cu)));
    *(float*)(cpu->esp + 0xA4u) = x87_v1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xA4u);
    x87_v1 = 0.4000000059604645;
    x87_v2 = 0.05999999865889549;
    x87_v3 = 0.5;
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    label_00024294:
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x34u) == 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    if (sub_pred[1]) goto label_000242BC;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    goto label_0002436C;
    label_000242BC:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0xB4u) = ((((double)*(float*)(cpu->esp + 0x24u))) - (((double)*(float*)(cpu->eax))));
    *(float*)(cpu->esp + 0xB8u) = ((((double)*(float*)(cpu->esp + 0x28u))) - (((double)*(float*)(cpu->eax + 4u))));
    *(float*)(cpu->esp + 0xBCu) = ((((double)*(float*)(cpu->esp + 0x2Cu))) - (((double)*(float*)(cpu->eax + 8u))));
    x87_v4 = (double)*(float*)(cpu->esp + 0xB4u);
    x87_v4 = (x87_v4) * (x87_v3);
    *(float*)(cpu->esp + 0xCCu) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0xB8u);
    x87_v4 = (x87_v4) * (x87_v3);
    *(float*)(cpu->esp + 0xD0u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0xBCu);
    x87_v4 = (x87_v4) * (x87_v3);
    *(float*)(cpu->esp + 0xD4u) = x87_v4; 
    *(float*)(cpu->esp + 0xE4u) = ((((double)*(float*)(cpu->esp + 0xCCu))) + (((double)*(float*)(cpu->eax))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xE4u);
    *(float*)(cpu->esp + 0xE8u) = ((((double)*(float*)(cpu->eax + 4u))) + (((double)*(float*)(cpu->esp + 0xD0u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xE8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0xD4u);
    x87_v4 = (x87_v4) + (((double)*(float*)(cpu->eax + 8u)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(float*)(cpu->esp + 0xECu) = x87_v4; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xECu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    label_0002436C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_00024370:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x18u) + (uint64_t)(0u);
    ++cpu->edx;
    cpu->eax += 0x18u;
    cpu->ecx += 0x18u;
    cpu->ebp += 0xCu;
    cpu->edi += 0x24u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->ebx + 0x20u)) goto label_00023F47;
    x87_v1 = x87_v3; 
    x87_v2 = x87_v2; 
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_000243AC:
    cpu->edi = lift_pop32(cpu);
    label_000243AD:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004243C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[17]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->edi + 0x464u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (x87_v0) + (x87_v0);
    cpu->ebp = native_function_address32(&::rand);
    cpu->esi = cpu->edi + 0x1478u;
    *(uint32_t*)(cpu->esp + 0x20u) = 6u;
    x87_v0 = (x87_v0) + (1.0);
    *(float*)(cpu->edi + 0x470u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->edi + 0x458u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 0x464u)));
    x87_v1 = 0.30000001192092896;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->edi + 0x468u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x460u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->edi + 0x464u)));
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->edi + 0x46Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v1 = 4.0;
    label_0002442F:
    sub_pred[5] = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) == 0u;
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esi))) - (((double)*(float*)(cpu->ebx))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esi + 4u))) - (((double)*(float*)(cpu->ebx + 8u))));
    if (sub_pred[5]) goto label_00024468;
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v3 = (x87_v3) * (x87_v3);
    x87_v4 = x87_v2;
    x87_v2 = x87_v2 * x87_v4; 
    x87_v2 = x87_v2 + x87_v3; 
    { const double lift_left=x87_v2; const double lift_right=2600.0;  if (!(lift_left>lift_right)) goto label_00024528; }
    label_00024468:
    x87_v1 = x87_v1; 
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = 1u;
    x87_v0 = x87_v0; 
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x24475u), LIFT_CODE_TOKEN_RVA(0x24473u))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esi + 0x28u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) / (32767.0)))) * (0.5)))) + (1.5));
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x24494u), LIFT_CODE_TOKEN_RVA(0x24492u))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_p0 = (x87_p0) / (32767.0);
    x87_p1 = 20.0;
    x87_p0 = (x87_p0) * (x87_p1);
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    x87_p1 = (x87_p1) + (x87_p1);
    x87_p0 = x87_p1 - x87_p0; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->edi + 0x458u);
    x87_p1 = 30.0;
    x87_p0 = (x87_p0) * (x87_p1);
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    x87_p1 = (((double)*(float*)(cpu->ebx))) - (x87_p1);
    x87_p2 = (double)*(float*)(cpu->edi + 0x460u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x14u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    { double temporary = x87_p3; x87_p3 = x87_p1; x87_p1 = temporary; }
    x87_p2 = x87_p3 - x87_p2; 
    *(float*)(cpu->esi) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebx + 8u);
    x87_p3 = (double)*(float*)(cpu->edi + 0x460u);
    x87_p0 = x87_p0 * x87_p3; 
    x87_p0 = x87_p2 - x87_p0; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->edi + 0x458u)));
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esi + 4u) = x87_p0; 
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x244F4u), LIFT_CODE_TOKEN_RVA(0x244F2u))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_p0 = (x87_p0) / (32767.0);
    x87_p1 = 4.0;
    x87_p0 = (x87_p0) * (x87_p1);
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    x87_p1 = (x87_p1) + (2.0);
    *(float*)(cpu->esp + 0x14u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esi + 0x10u) = x87_p1;
    x87_p1 = (x87_p1) * (x87_p1);
    *(float*)(cpu->esi + 0x14u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x24u);
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; label_00024528:
    x87_v2 = (double)*(float*)(cpu->edi + 0x458u);
    cpu->esi += 0x30u;
    --*(uint32_t*)(cpu->esp + 0x20u); sub_pred[6] = *(uint32_t*)(cpu->esp + 0x20u) == 0u;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi + 0x464u)));
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0xFFFFFFF8u)));
    x87_v2 = (x87_v2) * (x87_v0);
    x87_v2 = (x87_v2) * (x87_v1);
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esi + 0xFFFFFFD0u)));
    *(float*)(cpu->esi + 0xFFFFFFD0u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0x460u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi + 0x464u)));
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 0xFFFFFFF8u)));
    x87_v2 = (x87_v2) * (x87_v0);
    x87_v2 = (x87_v2) * (x87_v1);
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esi + 0xFFFFFFD4u)));
    *(float*)(cpu->esi + 0xFFFFFFD4u) = x87_v2; 
    *(float*)(cpu->esi + 0xFFFFFFE8u) = ((((double)*(float*)(cpu->esi + 0xFFFFFFD0u))) - (((double)*(float*)(cpu->esi + 0xFFFFFFE0u))));
    *(float*)(cpu->esi + 0xFFFFFFF0u) = ((((double)*(float*)(cpu->esi + 0xFFFFFFD0u))) + (((double)*(float*)(cpu->esi + 0xFFFFFFE0u))));
    *(float*)(cpu->esi + 0xFFFFFFECu) = ((((double)*(float*)(cpu->esi + 0xFFFFFFD4u))) - (((double)*(float*)(cpu->esi + 0xFFFFFFE0u))));
    *(float*)(cpu->esi + 0xFFFFFFF4u) = ((((double)*(float*)(cpu->esi + 0xFFFFFFD4u))) + (((double)*(float*)(cpu->esi + 0xFFFFFFE0u))));
    if (!sub_pred[6]) goto label_0002442F;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424594u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x424594u));
    cpu->esi |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->edi + 0x78u) == cpu->esi) goto label_000245BF;
    cpu->ecx = cpu->eax;
    sub_pred[0] = cpu->ecx < *(uint32_t*)(cpu->edi + 0xA8u); cpu->ecx -= *(uint32_t*)(cpu->edi + 0xA8u);
    cpu->ebx = cpu->edx;
    sub_pred[12] = (int64_t)((int32_t)(cpu->ebx)) < (int64_t)((int32_t)(*(uint32_t*)(cpu->edi + 0xACu))) + (sub_pred[0]); cpu->ebx -= *(uint32_t*)(cpu->edi + 0xACu) + (sub_pred[0]); sub_pred[7] = cpu->ebx == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)(cpu->ebx) < 0) goto label_000245BF;
    if ((!sub_pred[7]) && (!sub_pred[12])) goto label_000245BC;
    if (cpu->ecx <= 0x2710u) goto label_000245BF;
    label_000245BC:
    *(uint32_t*)(cpu->edi + 0x78u) = cpu->esi;
    label_000245BF:
    if (*(uint32_t*)(cpu->edi + 0xB0u) == cpu->esi) goto label_000245ED;
    cpu->ecx = cpu->eax;
    sub_pred[1] = cpu->ecx < *(uint32_t*)(cpu->edi + 0xE0u); cpu->ecx -= *(uint32_t*)(cpu->edi + 0xE0u);
    cpu->ebx = cpu->edx;
    sub_pred[13] = (int64_t)((int32_t)(cpu->ebx)) < (int64_t)((int32_t)(*(uint32_t*)(cpu->edi + 0xE4u))) + (sub_pred[1]); cpu->ebx -= *(uint32_t*)(cpu->edi + 0xE4u) + (sub_pred[1]); sub_pred[8] = cpu->ebx == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)(cpu->ebx) < 0) goto label_000245ED;
    if ((!sub_pred[8]) && (!sub_pred[13])) goto label_000245E7;
    if (cpu->ecx <= 0x2710u) goto label_000245ED;
    label_000245E7:
    *(uint32_t*)(cpu->edi + 0xB0u) = cpu->esi;
    label_000245ED:
    if (*(uint32_t*)(cpu->edi + 0xE8u) == cpu->esi) goto label_0002461B;
    cpu->ecx = cpu->eax;
    sub_pred[2] = cpu->ecx < *(uint32_t*)(cpu->edi + 0x118u); cpu->ecx -= *(uint32_t*)(cpu->edi + 0x118u);
    cpu->ebx = cpu->edx;
    sub_pred[14] = (int64_t)((int32_t)(cpu->ebx)) < (int64_t)((int32_t)(*(uint32_t*)(cpu->edi + 0x11Cu))) + (sub_pred[2]); cpu->ebx -= *(uint32_t*)(cpu->edi + 0x11Cu) + (sub_pred[2]); sub_pred[9] = cpu->ebx == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)(cpu->ebx) < 0) goto label_0002461B;
    if ((!sub_pred[9]) && (!sub_pred[14])) goto label_00024615;
    if (cpu->ecx <= 0x2710u) goto label_0002461B;
    label_00024615:
    *(uint32_t*)(cpu->edi + 0xE8u) = cpu->esi;
    label_0002461B:
    if (*(uint32_t*)(cpu->edi + 0x120u) == cpu->esi) goto label_00024649;
    cpu->ecx = cpu->eax;
    sub_pred[3] = cpu->ecx < *(uint32_t*)(cpu->edi + 0x150u); cpu->ecx -= *(uint32_t*)(cpu->edi + 0x150u);
    cpu->ebx = cpu->edx;
    sub_pred[15] = (int64_t)((int32_t)(cpu->ebx)) < (int64_t)((int32_t)(*(uint32_t*)(cpu->edi + 0x154u))) + (sub_pred[3]); cpu->ebx -= *(uint32_t*)(cpu->edi + 0x154u) + (sub_pred[3]); sub_pred[10] = cpu->ebx == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)(cpu->ebx) < 0) goto label_00024649;
    if ((!sub_pred[10]) && (!sub_pred[15])) goto label_00024643;
    if (cpu->ecx <= 0x2710u) goto label_00024649;
    label_00024643:
    *(uint32_t*)(cpu->edi + 0x120u) = cpu->esi;
    label_00024649:
    if (*(uint32_t*)(cpu->edi + 0x158u) == cpu->esi) goto label_00024672;
    sub_pred[4] = cpu->eax < *(uint32_t*)(cpu->edi + 0x188u); cpu->eax -= *(uint32_t*)(cpu->edi + 0x188u);
    sub_pred[16] = (int64_t)((int32_t)(cpu->edx)) < (int64_t)((int32_t)(*(uint32_t*)(cpu->edi + 0x18Cu))) + (sub_pred[4]); cpu->edx -= *(uint32_t*)(cpu->edi + 0x18Cu) + (sub_pred[4]); sub_pred[11] = cpu->edx == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if ((int32_t)(cpu->edx) < 0) goto label_00024672;
    if ((!sub_pred[11]) && (!sub_pred[16])) goto label_0002466C;
    if (cpu->eax <= 0x2710u) goto label_00024672;
    label_0002466C:
    *(uint32_t*)(cpu->edi + 0x158u) = cpu->esi;
    label_00024672:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00424680(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    *(float*)(cpu->ecx + 0x45Cu) = (double)(0.0);
    x87_v0 = (double)0.7070000171661377f;
    *(float*)(cpu->ecx + 0x458u) = x87_v0;
    *(float*)(cpu->ecx + 0x460u) = x87_v0; 
    *(float*)(cpu->ecx + 0x464u) = (double)0.4000000059604645f;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004246B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 0x2A8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 0x2ACu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 0x2B0u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004246E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_00024785;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->esi + 0x4Cu;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4246F2u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->esi + 0x78u;
    cpu->edx = 0u;
    cpu->ecx = cpu->eax;
    label_00024703:
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->ecx) == cpu->edi) goto label_00024733;
    ++cpu->edx;
    cpu->ecx += 0x38u;
    if ((int32_t)cpu->edx < (int32_t)5u) goto label_00024703;
    cpu->ecx = 0u;
    label_00024714:
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->eax) == 0xFFFFFFFFu) goto label_00024731;
    ++cpu->ecx;
    cpu->eax += 0x38u;
    if ((int32_t)cpu->ecx < (int32_t)5u) goto label_00024714;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x424725u));
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00024731:
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_00024733:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esi + 4u) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esi + 8u) = x87_v1;
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (x87_v3);
    *(float*)(cpu->esi + 0x14u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v3 = (x87_v3) - (x87_v2);
    *(float*)(cpu->esi + 0x18u) = x87_v3; 
    x87_v3 = x87_v2;
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi + 0x20u) = x87_v2; 
    x87_v2 = x87_v1;
    x87_v2 = (x87_v2) - (x87_v0);
    *(float*)(cpu->esi + 0x1Cu) = x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esi + 0x24u) = x87_v0; 
    *(float*)(cpu->esi + 0x28u) = (double)0.5f;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424776u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x424776u));
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x42477Du));
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00024785:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00424790(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->eax == 0u) goto label_000249B4;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 0x1D0u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (!sub_pred[0]) goto label_000247C6;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    label_000247C6:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    if ((cpu->ecx == *(uint32_t*)(cpu->esi + 0x2B8u)) || ((int32_t)(cpu->ecx) < (int32_t)(*(uint32_t*)(cpu->esi + 0x2B8u)))) goto label_0002480A;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2B4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x2B8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4247FBu));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esi + 0x2B4u) = cpu->eax;
    label_0002480A:
    x87_v0 = (double)*(float*)(cpu->esi + 0x470u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1D0u);
    x87_v0 = (x87_v0) * (0.699999988079071);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x2B4u);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    lift_push32(cpu, cpu->edi);
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x24u);
    x87_v1 = 0.05000000074505806;
    cpu->ebx = 0u;
    x87_v1 = (x87_v1) * (x87_v0);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v1 = 0.15000000596046448;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v1; 
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x20u) <= (int32_t)cpu->ebx) goto label_000249B0;
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v3 = (double)0.009999999776482582f;
    x87_v4 = 0.4000000059604645;
    label_0002486E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ecx + (cpu->ebx * 8u));
    x87_v5 = (double)*(float*)(cpu->esp + 0x20u);
    { const double lift_left=x87_v5; const double lift_right=x87_v3; if (!(lift_left<lift_right)) goto label_0002489B; }
    cpu->edx = *(uint32_t*)(cpu->edi);
    x87_v5 = x87_v5; 
    *(uint32_t*)(cpu->ebp) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    goto label_0002498C;
    label_0002489B:
    x87_v6 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v6 = (x87_v6) * (x87_v0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v6); 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint16_t*)(cpu->edx + (cpu->ebx * 8u) + 4u);
    cpu->eax += cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->edx &= 0x3FFu;
    cpu->ecx = cpu->eax + 0xC8u;
    cpu->ecx &= 0x3FFu;
    x87_v6 = (double)*(float*)(cpu->esi + (cpu->edx * 4u) + 0x474u);
    cpu->eax += 0x190u;
    x87_v6 = (x87_v6) * (x87_v1);
    cpu->eax &= 0x3FFu;
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x18u) == 0u;
    x87_v6 = (x87_v6) * (x87_v5);
    x87_v6 = (x87_v6) + (((double)*(float*)(cpu->edi)));
    *(float*)(cpu->esp + 0x24u) = x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esi + (cpu->ecx * 4u) + 0x474u);
    x87_v6 = (x87_v6) * (x87_v2);
    x87_v6 = (x87_v6) * (x87_v5);
    x87_v6 = (x87_v6) + (((double)*(float*)(cpu->edi + 4u)));
    *(float*)(cpu->esp + 0x28u) = x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esi + (cpu->eax * 4u) + 0x474u);
    x87_v6 = (x87_v6) * (x87_v1);
    x87_v5 = x87_v5 * x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->edi + 8u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v5; 
    if (sub_pred[1]) goto label_00024918;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    goto label_00024986;
    label_00024918:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esp + 0x24u))) - (((double)*(float*)(cpu->eax))));
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->esp + 0x28u))) - (((double)*(float*)(cpu->eax + 4u))));
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->esp + 0x2Cu))) - (((double)*(float*)(cpu->eax + 8u))));
    x87_v5 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v5 = (x87_v5) * (x87_v4);
    *(float*)(cpu->esp + 0x3Cu) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v5 = (x87_v5) * (x87_v4);
    *(float*)(cpu->esp + 0x40u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v5 = (x87_v5) * (x87_v4);
    *(float*)(cpu->esp + 0x44u) = x87_v5; 
    *(float*)(cpu->esp + 0x48u) = ((((double)*(float*)(cpu->esp + 0x3Cu))) + (((double)*(float*)(cpu->eax))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(float*)(cpu->esp + 0x4Cu) = ((((double)*(float*)(cpu->eax + 4u))) + (((double)*(float*)(cpu->esp + 0x40u))));
    x87_v5 = (double)*(float*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0x50u) = x87_v5; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    label_00024986:
    *(uint32_t*)(cpu->ebp) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    label_0002498C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x18u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ecx;
    ++cpu->ebx;
    cpu->edi += 0x24u;
    cpu->ebp += 0x18u;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->edx + 0x20u)) goto label_0002486E;
    x87_v1 = x87_v4; 
    x87_v2 = x87_v3; 
    x87_v0 = x87_v2; 
    x87_v1 = x87_v1; 
    label_000249B0:
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->ebp = lift_pop32(cpu);
    label_000249B4:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004249C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi) == cpu->edi) goto label_00024A30;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x388u) = cpu->edi;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->edi) goto label_00024A2F;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx += 4u;
    label_000249E1:
    if ((int32_t)cpu->edi <= 0) goto label_000249EC;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if (cpu->eax == *(uint32_t*)(cpu->ebx + 0xFFFFFFF4u)) goto label_00024A26;
    label_000249EC:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4249FAu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4249FAu));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1C4u);
    if (cpu->ecx == 2u) goto label_00024A0A;
    if (cpu->ecx != 3u) goto label_00024A1D;
    label_00024A0A:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x388u);
    *(uint32_t*)(cpu->esi + (cpu->edx * 4u) + 0x2C0u) = cpu->eax;
    ++*(uint32_t*)(cpu->esi + 0x388u);
    label_00024A1D:
    if (*(uint32_t*)(cpu->esi + 0x388u) == 0x32u) goto label_00024A2E;
    label_00024A26:
    ++cpu->edi;
    cpu->ebx += 0xCu;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebp) goto label_000249E1;
    label_00024A2E:
    cpu->ebx = lift_pop32(cpu);
    label_00024A2F:
    cpu->ebp = lift_pop32(cpu);
    label_00024A30:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00424A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetExitCodeThread);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0x103u;
    label_00024A51:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_00024A78;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x24A5Fu), LIFT_CODE_TOKEN_RVA(0x24A5Du))) { return; }
    if (cpu->eax != 0u) goto label_00024A72;
    cpu->edx = 0x21Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x24A72u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x24A72u));
    label_00024A72:
    if (*(uint32_t*)(cpu->esp + 0xCu) == cpu->ebx) goto label_00024A51;
    label_00024A78:
    cpu->edi = native_function_address32(&::EnterCriticalSection);
    cpu->ebx = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x24A84u), LIFT_CODE_TOKEN_RVA(0x24A82u))) { return; }
    if (*(uint32_t*)(cpu->esi + 0x1594u) != 1u) goto label_00024AA5;
    cpu->edx = cpu->esi + 4u;
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x24A93u), LIFT_CODE_TOKEN_RVA(0x24A91u))) { return; }
    cpu->esi += 0x1Cu;
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x24A99u), LIFT_CODE_TOKEN_RVA(0x24A97u))) { return; }
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x424A9Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00024AA5:
    cpu->eax = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x24AABu), LIFT_CODE_TOKEN_RVA(0x24AA9u))) { return; }
    cpu->esi += 4u;
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x24AB1u), LIFT_CODE_TOKEN_RVA(0x24AAFu))) { return; }
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x424AB2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00424AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + 0x2BCu) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00424AD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[5];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ebx + 0x4Cu;
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x424ADFu));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::LeaveCriticalSection);
    cpu->esi = cpu->ebx + 0x78u;
    cpu->edi = cpu->ebx + 0x190u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),280u); cpu->esi += 280u; cpu->edi += 280u; cpu->ecx = 0u;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x24AFEu), LIFT_CODE_TOKEN_RVA(0x24AFCu))) { return; }
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 0x6Cu) == 0u; sub_pred[3] = (int32_t)(*(uint32_t*)(cpu->ebx + 0x6Cu)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    if ((sub_pred[0]) || (sub_pred[3])) goto label_00024C15;
    label_00024B10:
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x6Cu) <= (int32_t)cpu->edi) goto label_00024C03;
    cpu->ebp = cpu->ebx + 0x34u;
    label_00024B20:
    cpu->esi = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24B29u), LIFT_CODE_TOKEN_RVA(0x24B27u))) { return; }
    *(uint32_t*)(cpu->ebx + 0x1594u)^=1u;
    if ((*(uint32_t*)(cpu->ebx + 0x1594u))!=0u) goto label_00024B38;
    cpu->eax = cpu->ebx + 4u;
    lift_push32(cpu, cpu->eax);
    goto label_00024B3C;
    label_00024B38:
    cpu->ecx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    label_00024B3C:
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24B3Eu), LIFT_CODE_TOKEN_RVA(0x24B3Cu))) { return; }
    cpu->esi = native_function_address32(&::LeaveCriticalSection);
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24B47u), LIFT_CODE_TOKEN_RVA(0x24B45u))) { return; }
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x6Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x24u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x68u);
    cpu->edx += cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x98u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->eax);
    if (cpu->eax == 0u) goto label_00024BDE;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x64u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424B90u)); sfera_sub_00422E50(cpu, LIFT_CODE_TOKEN_VA(0x424B90u));
    if (*(uint32_t*)(cpu->esi + 0x1D0u) != 0u) goto label_00024BB5;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x424BA6u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    label_00024BB5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2B4u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x424BD0u));
    cpu->esi = native_function_address32(&::LeaveCriticalSection);
    cpu->esp += 0xCu;
    label_00024BDE:
    if (*(uint32_t*)(cpu->ebx + 0x1594u) != 0u) goto label_00024BED;
    cpu->edx = cpu->ebx + 4u;
    lift_push32(cpu, cpu->edx);
    goto label_00024BF1;
    label_00024BED:
    cpu->eax = cpu->ebx + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    label_00024BF1:
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24BF3u), LIFT_CODE_TOKEN_RVA(0x24BF1u))) { return; }
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->ebx + 0x6Cu)) goto label_00024B20;
    cpu->ebp = native_function_address32(&::LeaveCriticalSection);
    label_00024C03:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebx + 0x6Cu)) goto label_00024B10;
    label_00024C15:
    cpu->esi = native_function_address32(&::EnterCriticalSection);
    cpu->edi = cpu->ebx + 0x34u;
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24C21u), LIFT_CODE_TOKEN_RVA(0x24C1Fu))) { return; }
    *(uint32_t*)(cpu->ebx + 0x1594u)^=1u;
    if ((*(uint32_t*)(cpu->ebx + 0x1594u))!=0u) goto label_00024C30;
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, cpu->ecx);
    goto label_00024C34;
    label_00024C30:
    cpu->edx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    label_00024C34:
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24C36u), LIFT_CODE_TOKEN_RVA(0x24C34u))) { return; }
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x24C39u), LIFT_CODE_TOKEN_RVA(0x24C37u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x388u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x2C0u;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->ebx + 0x38Cu;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x424C52u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x388u);
    cpu->esp += 0xCu;
    sub_pred[1] = *(uint32_t*)(cpu->ebx + 0x1594u) == 0u;
    *(uint32_t*)(cpu->ebx + 0x454u) = cpu->edx;
    if (!sub_pred[1]) goto label_00024C75;
    cpu->eax = cpu->ebx + 4u;
    lift_push32(cpu, cpu->eax);
    goto label_00024C79;
    label_00024C75:
    cpu->ecx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    label_00024C79:
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x24C7Bu), LIFT_CODE_TOKEN_RVA(0x24C79u))) { return; }
    sub_pred[2] = *(uint32_t*)(cpu->ebx + 0x454u) == 0u; sub_pred[4] = (int32_t)(*(uint32_t*)(cpu->ebx + 0x454u)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((sub_pred[2]) || (sub_pred[4])) goto label_00024D60;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    label_00024C94:
    cpu->esi = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24C9Du), LIFT_CODE_TOKEN_RVA(0x24C9Bu))) { return; }
    *(uint32_t*)(cpu->ebx + 0x1594u)^=1u;
    if ((*(uint32_t*)(cpu->ebx + 0x1594u))!=0u) goto label_00024CAC;
    cpu->edx = cpu->ebx + 4u;
    lift_push32(cpu, cpu->edx);
    goto label_00024CB0;
    label_00024CAC:
    cpu->eax = cpu->ebx + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    label_00024CB0:
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x24CB2u), LIFT_CODE_TOKEN_RVA(0x24CB0u))) { return; }
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x24CB5u), LIFT_CODE_TOKEN_RVA(0x24CB3u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    if (cpu->eax != 2u) goto label_00024CD0;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424CCEu)); sfera_sub_00423E70(cpu, LIFT_CODE_TOKEN_VA(0x424CCEu));
    goto label_00024CE9;
    label_00024CD0:
    if (cpu->eax != 3u) goto label_00024CDF;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424CDDu)); sfera_sub_00424790(cpu, LIFT_CODE_TOKEN_VA(0x424CDDu));
    goto label_00024CE9;
    label_00024CDF:
    cpu->ecx = (uintptr_t)"dyn_grass_loop: wrong mp->dg_type";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x24CE9u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x24CE9u));
    label_00024CE9:
    if (*(uint32_t*)(cpu->esi + 0x1D0u) != 0u) goto label_00024D0E;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x424CFFu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    label_00024D0E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x2B4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x424D29u));
    cpu->esp += 0xCu;
    if (*(uint32_t*)(cpu->ebx + 0x1594u) != 0u) goto label_00024D40;
    cpu->eax = cpu->ebx + 4u;
    lift_push32(cpu, cpu->eax);
    goto label_00024D44;
    label_00024D40:
    cpu->ecx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    label_00024D44:
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x24D46u), LIFT_CODE_TOKEN_RVA(0x24D44u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebx + 0x454u)) goto label_00024C94;
    label_00024D60:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00424D70(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    lift_push32(cpu, 0x33Au);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424D93u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x424D93u));
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x424DA3u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x28u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x33Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424DBDu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x424DBDu));
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x30u) <= (int32_t)cpu->edi) goto label_00024F69;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    label_00024DD4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax += *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->ecx = *(uint16_t*)(cpu->eax + 4u);
    cpu->edx = *(uint16_t*)(cpu->eax + 6u);
    cpu->esi = *(uint16_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x28u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x424DFAu));
    cpu->esp += 0xCu;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) <= (int32_t)0u) goto label_00024F52;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = 1u;
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    label_00024E37:
    if (*(uint8_t*)(cpu->ecx) != 0u) goto label_00024F3C;
    *(uint8_t*)(cpu->ecx) = 1u;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->edx + cpu->eax);
    cpu->edx += cpu->esi;
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->edx + cpu->eax + 2u);
    cpu->edx += cpu->esi;
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->edx + cpu->eax + 4u);
    cpu->edx += cpu->esi;
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    label_00024E80:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_00024F37;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->ecx;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    label_00024EA3:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->ecx + cpu->edx) != 0u) goto label_00024F1A;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint16_t*)(cpu->edx);
    cpu->edx += cpu->esi;
    if (*(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) == cpu->edi) goto label_00024EE1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint16_t*)(cpu->edx + 2u);
    cpu->edx += cpu->esi;
    if (*(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) == cpu->edi) goto label_00024EE1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint16_t*)(cpu->edx + 4u);
    cpu->edx += cpu->esi;
    if (*(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) != cpu->edi) goto label_00024F1A;
    label_00024EE1:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->ecx + cpu->edx) = 1u;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->edx + cpu->eax);
    cpu->edx += cpu->esi;
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->edx + cpu->eax + 2u);
    cpu->edx += cpu->esi;
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->edx + cpu->eax + 4u);
    cpu->edx += cpu->esi;
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    label_00024F1A:
    ++cpu->ecx;
    cpu->eax += 0xCu;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_00024EA3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (*(uint32_t*)(cpu->esp + 0x2Cu) != 0u) goto label_00024E80;
    label_00024F37:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->edi;
    label_00024F3C:
    cpu->eax += 0xCu;
    ++cpu->ecx;
    --*(uint32_t*)(cpu->esp + 0x30u); sub_pred[0] = *(uint32_t*)(cpu->esp + 0x30u) == 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (!sub_pred[0]) goto label_00024E37;
    label_00024F52:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x12u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebx + 0x30u)) goto label_00024DD4;
    label_00024F69:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0x363u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424F7Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x424F7Cu));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x366u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x424F95u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x424F95u));
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x1C8u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x424F9Du));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x20u) <= (int32_t)cpu->ecx) goto label_00025275;
    cpu->esi = 0u;
    cpu->edi += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    (void)cpu;
    label_00024FC0:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->esi + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x48u)));
    { const double lift_left=x87_v0; const double lift_right=0.0;  if (!(lift_left>lift_right)) goto label_00024FE6; }
    cpu->ecx = 0xFFFFu;
    *(uint16_t*)(cpu->edi + 0xFFFFFFFCu) = cpu->ecx & 0xFFFFu;
    goto label_00025259;
    label_00024FE6:
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->ecx * 4u));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_00025002;
    cpu->edx = 0x374u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x25002u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x25002u));
    label_00025002:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x20u) <= (int32_t)cpu->ecx) goto label_000250EC;
    cpu->edi = 0u;
    label_00025020:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->edx != *(uint32_t*)(cpu->ebp + (cpu->ecx * 4u))) goto label_000250CC;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->edi + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x48u)));
    { const double lift_left=x87_v0; const double lift_right=0.0;  if (!(lift_left>lift_right)) goto label_000250CC; }
    if (*(uint32_t*)(cpu->esp + 0x14u) != cpu->ecx) goto label_00025063;
    cpu->edx = 0x37Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42505Fu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x42505Fu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    label_00025063:
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x10u) == 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->eax + cpu->esi))) - (((double)*(float*)(cpu->eax + cpu->edi))));
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->eax + cpu->esi + 4u))) - (((double)*(float*)(cpu->eax + cpu->edi + 4u))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->eax + cpu->esi + 8u))) - (((double)*(float*)(cpu->eax + cpu->edi + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x30u);
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
    if (sub_pred[1]) goto label_000250C0;
    { const double lift_left=(double)*(float*)(cpu->esp + 0x18u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_000250CA; }
    label_000250C0:
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_000250CC;
    label_000250CA:
    x87_v0 = x87_v0; 
    label_000250CC:
    ++cpu->ecx;
    cpu->edi += 0x24u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebx + 0x20u)) goto label_00025020;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0xFFFFFFFFu) goto label_000251CB;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000250EC:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x20u) <= (int32_t)cpu->ecx) goto label_000251BA;
    cpu->edi = 0u;
    label_00025100:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x24u);
    x87_v0 = (double)*(float*)(cpu->edx + cpu->edi + 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x48u)));
    { const double lift_left=x87_v0; const double lift_right=0.0;  if (!(lift_left>lift_right)) goto label_0002519E; }
    if (*(uint32_t*)(cpu->esp + 0x14u) != cpu->ecx) goto label_00025135;
    cpu->edx = 0x38Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425131u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x425131u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    label_00025135:
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x10u) == 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->eax + cpu->esi))) - (((double)*(float*)(cpu->eax + cpu->edi))));
    *(float*)(cpu->esp + 0x3Cu) = ((((double)*(float*)(cpu->eax + cpu->esi + 4u))) - (((double)*(float*)(cpu->eax + cpu->edi + 4u))));
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->eax + cpu->esi + 8u))) - (((double)*(float*)(cpu->eax + cpu->edi + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    if (sub_pred[2]) goto label_00025192;
    { const double lift_left=(double)*(float*)(cpu->esp + 0x18u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0002519C; }
    label_00025192:
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_0002519E;
    label_0002519C:
    x87_v0 = x87_v0; 
    label_0002519E:
    ++cpu->ecx;
    cpu->edi += 0x24u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebx + 0x20u)) goto label_00025100;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0xFFFFFFFFu) goto label_000251CB;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000251BA:
    cpu->edx = 0x396u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4251C9u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_VA(0x4251C9u));
    goto label_000251CF;
    label_000251CB:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000251CF:
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->esi + 4u);
    cpu->edx = cpu->ecx + (cpu->ecx * 8u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + (cpu->edx * 4u) + 4u)));
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu); x87_v2 = x87_v1;
    x87_v0 = x87_v0 / x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x3Cu) = (fabs(((double)*(float*)(cpu->esp + 0x3Cu))));
    { const double lift_left=(double)*(float*)(cpu->esp + 0x3Cu); const double lift_right=((double)0.7070000171661377f); if (!(lift_left<lift_right)) goto label_00025224; }
    cpu->eax = 0xFFFEu;
    x87_v0 = x87_v0; 
    *(uint16_t*)(cpu->edi + 0xFFFFFFFCu) = cpu->eax & 0xFFFFu;
    goto label_0002522B;
    label_00025224:
    *(float*)(cpu->edi + 4u) = x87_v0; 
    *(uint16_t*)(cpu->edi + 0xFFFFFFFCu) = cpu->ecx & 0xFFFFu;
    label_0002522B:
    cpu->ecx = 0u;
    *(uint16_t*)(cpu->edi) = cpu->ecx & 0xFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x40u) == cpu->ecx) goto label_0002524F;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x2Cu));
    *(uint16_t*)(cpu->edi + 0xFFFFFFFEu) = cpu->edx & 0xFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->ecx) goto label_00025259;
    cpu->eax = 1u;
    *(uint16_t*)(cpu->edi) = cpu->eax & 0xFFFFu;
    goto label_00025259;
    label_0002524F:
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x42524Fu));
    *(uint16_t*)(cpu->edi + 0xFFFFFFFEu) = cpu->eax & 0xFFFFu;
    label_00025259:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->edi += 0xCu;
    cpu->esi += 0x24u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebx + 0x20u)) goto label_00024FC0;
    label_00025275:
    lift_push32(cpu, 0x3A9u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425286u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x425286u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425290(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x10u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    x87_v0 = (x87_v0) * (x87_v0);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x3B5u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4252BBu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4252BBu));
    x87_v0 = 0.0;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x20u);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ebp;
    if ((int32_t)cpu->ebx <= 0) goto label_00025305;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx = cpu->ebx;
    label_000252D5:
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    x87_v1 = (double)*(float*)(cpu->ecx);
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_000252FD; }
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    goto label_000252FF;
    label_000252FD:
    x87_v0 = x87_v0; 
    label_000252FF:
    cpu->ecx += 0x24u;
    if ((--cpu->edx) != 0u) goto label_000252D5;
    label_00025305:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x24u)));
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    { const double lift_left=(double)*(float*)(cpu->esi + 0x194u); const double lift_right=7.0; if (!(lift_left<lift_right)) goto label_00025343; }
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) * (0.4000000059604645));
    label_00025343:
    cpu->edi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_000253DE;
    cpu->ebx = 0u;
    (void)cpu;
    label_00025350:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->ebx + 8u);
    x87_v1 = (double)*(float*)(cpu->eax + cpu->ebx);
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x18u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0002537D; }
    x87_v0 = x87_v0; 
    x87_v0 = 0.0;
    goto label_00025392;
    label_0002537D:
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x24u)));
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x14u)));
    label_00025392:
    *(float*)(cpu->ebp + (cpu->edi * 8u)) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    x87_v0 = (double)*(float*)(cpu->ebx + cpu->ecx + 4u);
    cpu->eax = cpu->ebx + cpu->ecx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax)));
    ++cpu->edi;
    *(uint16_t*)(cpu->esp + 0x10u) = cpu->fpu_control;
    cpu->ebx += 0x24u;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 8u)));
    cpu->eax = *(uint16_t*)(cpu->esp + 0x10u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x28u)));
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x1Cu));
    *(uint16_t*)(cpu->ebp + (cpu->edi * 8u) + 0xFFFFFFFCu) = cpu->edx & 0xFFFFu;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 0x20u)) goto label_00025350;
    label_000253DE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004253F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1598u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4253FCu));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42540Bu)); sfera_sub_00422CB0(cpu, LIFT_CODE_TOKEN_VA(0x42540Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = native_function_address32(&::InitializeCriticalSection);
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 0x78u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x190u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xE8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x200u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x120u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x238u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x158u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x270u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->eax;
    cpu->eax = cpu->esi + 4u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x6Cu) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2546Eu), LIFT_CODE_TOKEN_RVA(0x2546Cu))) { return; }
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x25474u), LIFT_CODE_TOKEN_RVA(0x25472u))) { return; }
    cpu->edx = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2547Au), LIFT_CODE_TOKEN_RVA(0x25478u))) { return; }
    cpu->eax = cpu->esi + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x25480u), LIFT_CODE_TOKEN_RVA(0x2547Eu))) { return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425570(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetExitCodeThread);
    cpu->esi = cpu->ecx;
    label_00025580:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000255BE;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2558Eu), LIFT_CODE_TOKEN_RVA(0x2558Cu))) { return; }
    if (cpu->eax != 0u) goto label_000255A1;
    cpu->edx = 0x21Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x255A1u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x255A1u));
    label_000255A1:
    if (*(uint32_t*)(cpu->esp + 8u) == 0x103u) goto label_00025580;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000255BE;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x4255B2u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_000255BE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004255D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_p0, x87_p1;
    goto label_000255D0;
    label_00025490:
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000254C9;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x4254A2u));
    if (cpu->eax != 0u) goto label_000254BB;
    cpu->edx = 0x21Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x254BBu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x254BBu));
    label_000254BB:
    if (*(uint32_t*)(cpu->esp + 4u) == 0x103u) goto label_00025562;
    label_000254C9:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4254CFu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4254CFu));
    cpu->ecx = cpu->eax;
    sub_pred[0] = cpu->ecx < (uint32_t)(g_sfera_dyn_green_runtime.low); cpu->ecx -= g_sfera_dyn_green_runtime.low;
    cpu->edi = cpu->edx;
    cpu->edi -= g_sfera_dyn_green_runtime.high + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    x87_p0 = (double)(((int64_t)(*(uint64_t*)(cpu->esp + 8u))));
    g_sfera_dyn_green_runtime.low = cpu->eax;
    g_sfera_dyn_green_runtime.high = cpu->edx;
    x87_p0 = (x87_p0) / (2000.0);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    x87_p0 = (double)2.0f;
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu + 2, cpu->fpu, 6u * sizeof(double)); cpu->fpu[0u] = x87_p1; cpu->fpu[1u] = x87_p0; { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left>lift_right)) goto label_00025520; }
    cpu->fpu[0u] = cpu->fpu[0u]; 
    *(float*)(cpu->esp + 4u) = cpu->fpu[1u]; 
    cpu->fpu[1u] = (double)*(float*)(cpu->esp + 4u);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); goto label_00025522;
    label_00025520:
    cpu->fpu[1u] = cpu->fpu[0u]; 
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); label_00025522:
    x87_p0 = cpu->fpu[0u];
    lift_push32(cpu, cpu->ecx);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esi + 0x70u)));
    cpu->edx = cpu->esi + 0x2A8u;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esi + 0x70u) = x87_p0; 
    *(float*)(cpu->esp) = cpu->fpu[0u]; 
    lift_push32(cpu, cpu->edx);
    std::memmove(cpu->fpu, cpu->fpu + 1, 7u * sizeof(double)); lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42553Cu)); sfera_sub_004243C0(cpu, LIFT_CODE_TOKEN_VA(0x42553Cu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_00025549;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x25543u));
    label_00025549:
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00424AD0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x42555Au));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_00025562:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000255D0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::LeaveCriticalSection);
    cpu->eax = cpu->esi + 4u;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x255E0u), LIFT_CODE_TOKEN_RVA(0x255DEu))) { return; }
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x255E6u), LIFT_CODE_TOKEN_RVA(0x255E4u))) { return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_00025490;
}
__declspec(noinline) void sfera_sub_004255F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->edi + 0x1C4u) == 3u;
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if (sub_pred[0]) goto label_00025637;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ground_y"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42562Cu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x42562Cu));
    if (cpu->eax == 1u) goto label_00025637;
    *(float*)(cpu->esp + 0x18u) = (double)(0.0);
    label_00025637:
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->edi + 0x1C4u) != cpu->ebx) goto label_00025652;
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0u;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x25652u)); sfera_sub_00424D70(cpu, LIFT_CODE_TOKEN_RVA(0x25652u));
    label_00025652:
    cpu->edx = 1u;
    if (*(uint32_t*)(cpu->edi + 0x1C4u) != cpu->edx) goto label_0002566E;
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2566Eu)); sfera_sub_00424D70(cpu, LIFT_CODE_TOKEN_RVA(0x2566Eu));
    label_0002566E:
    if (*(uint32_t*)(cpu->edi + 0x1C4u) != 2u) goto label_00025870;
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0u;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42568Cu)); sfera_sub_00424D70(cpu, LIFT_CODE_TOKEN_VA(0x42568Cu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x30Eu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4256A5u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4256A5u));
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x3Cu) = x87_v0;
    *(uint32_t*)(cpu->edi + 0x1CCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C8u);
    *(float*)(cpu->esp + 0x40u) = x87_v0;
    x87_v1 = 1.0;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(float*)(cpu->esp + 0x44u) = x87_v1;
    *(float*)(cpu->esp + 0x48u) = x87_v1; 
    *(float*)(cpu->esp + 0x4Cu) = x87_v0;
    *(float*)(cpu->esp + 0x50u) = x87_v0; 
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x20u) <= (int32_t)cpu->ebx) goto label_00025870;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000256E0:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x24u);
    x87_v0 = (double)-0.15000000596046448f;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x1CCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebx);
    cpu->esi += cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ebx + 8u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(float*)(cpu->esi + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    cpu->edx = 0xFDE8u;
    if ((cpu->ecx & 0xFFFFu) >= (cpu->edx & 0xFFFFu)) goto label_00025852;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x24u);
    x87_v0 = (double)*(float*)(cpu->ebx + cpu->eax + 4u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 8u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + (cpu->ecx * 4u) + 4u)));
    cpu->ecx = cpu->eax + (cpu->ecx * 4u);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    cpu->edx = cpu->esp + 0x40u;
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->ebx + cpu->eax + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    x87_v0 = (double)*(float*)(cpu->ebx + cpu->eax);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx)));
    cpu->ecx = cpu->esp + 0x58u;
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    *(float*)(cpu->esp + 0x38u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x3Cu) = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425768u)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x425768u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    x87_v1 = (double)*(float*)(cpu->esi);
    x87_v2 = (double)*(float*)(cpu->esi + 8u);
    x87_v3 = (double)*(float*)(cpu->ecx + 8u);
    *(double*)(cpu->esp + 0x20u) = x87_v3;
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
    cpu->edx = cpu->esp + 0x48u;
    x87_v0 = (*(double*)(cpu->esp + 0x20u)) / (x87_v0);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x34u;
    cpu->ecx = cpu->esp + 0x64u;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi);
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esi + 4u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esi + 4u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 8u)));
    *(float*)(cpu->esi + 8u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4257E6u)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x4257E6u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esi + 0xCu);
    x87_v2 = (double)*(float*)(cpu->esi + 0x14u);
    x87_v3 = (double)*(float*)(cpu->ecx + 8u);
    *(double*)(cpu->esp + 0x20u) = x87_v3;
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
    *(float*)(cpu->esp + 0x10u) = ((*(double*)(cpu->esp + 0x20u)) / (((double)*(float*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0xCu)));
    *(float*)(cpu->esi + 0xCu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esi + 0x10u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esi + 0x10u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    label_00025852:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->ebx += 0x24u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 0x20u)) goto label_000256E0;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00025870:
    if (*(uint32_t*)(cpu->edi + 0x1C4u) != 3u) goto label_000258DC;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"deadRadius"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42588Du)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x42588Du));
    if (cpu->eax == 1u) goto label_0002589E;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"Parameter deadRadius not found for model ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2589Eu)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x2589Eu));
    label_0002589E:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"phaseMul"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4258B2u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x4258B2u));
    if (cpu->eax == 1u) goto label_000258C3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"Parameter phaseMul not found for model ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x258C3u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x258C3u));
    label_000258C3:
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x258DCu)); sfera_sub_00425290(cpu, LIFT_CODE_TOKEN_RVA(0x258DCu));
    label_000258DC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004258F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4258F9u)); sfera_sub_00425570(cpu, LIFT_CODE_TOKEN_VA(0x4258F9u));
    cpu->edi = native_function_address32(&::DeleteCriticalSection);
    cpu->eax = cpu->esi + 4u;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x25905u), LIFT_CODE_TOKEN_RVA(0x25903u))) { return; }
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2590Bu), LIFT_CODE_TOKEN_RVA(0x25909u))) { return; }
    cpu->edx = cpu->esi + 0x34u;
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x25911u), LIFT_CODE_TOKEN_RVA(0x2590Fu))) { return; }
    cpu->eax = cpu->esi + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x25917u), LIFT_CODE_TOKEN_RVA(0x25915u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2B4u);
    if (cpu->eax == 0u) goto label_00025935;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x425922u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x2B4u) = 0u;
    label_00025935:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x25992u), LIFT_CODE_TOKEN_RVA(0x25990u))) { return; }
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
__declspec(noinline) void sfera_sub_004259C0(LiftCpu* cpu, uint32_t stop_address) {
    *(float*)(cpu->edx) = (double)*(float*)(cpu->ecx);
    *(float*)(cpu->edx + 4u) = (double)*(float*)(cpu->ecx + 4u);
    *(float*)(cpu->edx + 8u) = (double)*(float*)(cpu->ecx + 8u);
    *(float*)(cpu->edx + 0xCu) = (double)*(float*)(cpu->ecx + 0xCu);
    *(float*)(cpu->edx + 0x10u) = (double)*(float*)(cpu->ecx + 4u);
    *(float*)(cpu->edx + 0x14u) = (double)*(float*)(cpu->ecx + 8u);
    *(float*)(cpu->edx + 0x18u) = (double)*(float*)(cpu->ecx + 0xCu);
    *(float*)(cpu->edx + 0x1Cu) = (double)*(float*)(cpu->ecx + 0x10u);
    *(float*)(cpu->edx + 0x20u) = (double)*(float*)(cpu->ecx + 8u);
    *(float*)(cpu->edx + 0x24u) = (double)*(float*)(cpu->ecx);
    *(float*)(cpu->edx + 0x28u) = (double)*(float*)(cpu->ecx + 0x10u);
    *(float*)(cpu->edx + 0x2Cu) = (double)*(float*)(cpu->ecx + 8u);
    *(float*)(cpu->edx + 0x30u) = (double)*(float*)(cpu->ecx);
    *(float*)(cpu->edx + 0x34u) = (double)*(float*)(cpu->ecx + 0x10u);
    *(float*)(cpu->edx + 0x38u) = (double)*(float*)(cpu->ecx + 0x14u);
    *(float*)(cpu->edx + 0x3Cu) = (double)*(float*)(cpu->ecx);
    *(float*)(cpu->edx + 0x40u) = (double)*(float*)(cpu->ecx + 4u);
    *(float*)(cpu->edx + 0x44u) = (double)*(float*)(cpu->ecx + 0x14u);
    *(float*)(cpu->edx + 0x48u) = (double)*(float*)(cpu->ecx + 0xCu);
    *(float*)(cpu->edx + 0x4Cu) = (double)*(float*)(cpu->ecx + 4u);
    *(float*)(cpu->edx + 0x50u) = (double)*(float*)(cpu->ecx + 0x14u);
    *(float*)(cpu->edx + 0x54u) = (double)*(float*)(cpu->ecx + 0xCu);
    *(float*)(cpu->edx + 0x58u) = (double)*(float*)(cpu->ecx + 0x10u);
    *(float*)(cpu->edx + 0x5Cu) = (double)*(float*)(cpu->ecx + 0x14u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425A50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.particle_resource_head;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == 0u) goto label_00025A8E;
    if (cpu->edi == 0u) goto label_00025A8E;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    label_00025A70:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x25A74u), LIFT_CODE_TOKEN_RVA(0x25A72u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00025A88;
    cpu->esi = *(uint32_t*)(cpu->esi + 0x54u);
    if (cpu->esi != 0u) goto label_00025A70;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00025A88:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00025A8E:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425AA0(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_effect_manager.particle_random_table != 0u) goto label_00025ACA;
    cpu->edx = 0x174u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425AB8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425AB8u));
    lift_push32(cpu, 0x20000u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425AC2u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x425AC2u));
    cpu->esp += 4u;
    g_sfera_effect_manager.particle_random_table = cpu->eax;
    label_00025ACA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::timeGetTime), LIFT_CODE_TOKEN_VA(0x425ACEu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x425AD5u));
    cpu->edi = g_sfera_effect_manager.particle_random_table;
    cpu->ebx = native_function_address32(&::rand);
    cpu->esp += 4u;
    cpu->ebp = 0x100u;
    (void)cpu;
    label_00025AF0:
    cpu->esi = 0u;
    label_00025AF2:
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x25AF4u), LIFT_CODE_TOKEN_RVA(0x25AF2u))) { return; }
    *(uint16_t*)(cpu->edi + (cpu->esi * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x100u) goto label_00025AF2;
    cpu->edi += 0x200u;
    if ((--cpu->ebp) != 0u) goto label_00025AF0;
    lift_native_call(cpu, native_function_address32(&::timeGetTime), LIFT_CODE_TOKEN_VA(0x425B0Au));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x425B11u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425B20(LiftCpu* cpu, uint32_t stop_address) { double x87_p0, x87_p1, x87_p2, x87_p3;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.viewer_position.x;
    cpu->edi = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425B3Eu)); sfera_sub_00455FD0(cpu, LIFT_CODE_TOKEN_VA(0x425B3Eu));
    if (cpu->esi == 0u) goto label_00025B58;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    goto label_00025B63;
    label_00025B58:
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x25B63u)); sfera_sub_00455E40(cpu, LIFT_CODE_TOKEN_RVA(0x25B63u));
    label_00025B63:
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.x))) - (((double)*(float*)(cpu->esp + 0x18u))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.y))) - (((double)*(float*)(cpu->esp + 0x1Cu))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.z))) - (((double)*(float*)(cpu->esp + 0x20u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_p2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    { double temporary = x87_p2; x87_p2 = x87_p1; x87_p1 = temporary; }
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 8u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 8u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    std::memmove(cpu->fpu + 1, cpu->fpu, 7u * sizeof(double)); cpu->fpu[0u] = x87_p0; cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_effect_manager.effect_definition_head;
    if (cpu->eax == 0u) goto label_00025BEC;
    label_00025BE0:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_00025BEE;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x20u);
    if (cpu->eax != 0u) goto label_00025BE0;
    label_00025BEC:
    cpu->eax = 0u;
    label_00025BEE:
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
__declspec(noinline) void sfera_sub_00425C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (*(uint32_t*)(cpu->ecx) != 0u) goto label_00025C14;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00025C14:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 0x30u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425C30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->esi == cpu->edi) goto label_00025CB0;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (cpu->edx == cpu->edi) goto label_00025CB0;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax == cpu->edi) goto label_00025CB0;
    if (cpu->edx != cpu->eax) goto label_00025C60;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00025C60:
    if (cpu->esi != cpu->edx) goto label_00025C7A;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x30u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00025C7A:
    if (cpu->esi != cpu->eax) goto label_00025C95;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x34u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00025C95:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    *(uint32_t*)(cpu->edx + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    label_00025CB0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425CF8u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x425CF8u));
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10Cu);
    if ((int32_t)cpu->eax >= 0) goto label_00025D08;
    label_00025D02:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00025D08:
    if (*(uint32_t*)(cpu->eax + 0x1Cu) == 0u) goto label_00025D02;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    reinterpret_cast<IEffectManager*>(static_cast<uintptr_t>(cpu->eax))->setParameter(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425D30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_definition_head;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x20u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x20u;
    cpu->ebx = cpu->ecx;
    if (sub_pred[0]) goto label_00025D69;
    cpu->ebp = native_function_address32(&::_stricmp);
    label_00025D50:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x25D57u), LIFT_CODE_TOKEN_RVA(0x25D55u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00025D71;
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->edi = cpu->esi + 0x20u;
    if (*(uint32_t*)(cpu->esi + 0x20u) != 0u) goto label_00025D50;
    label_00025D69:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00025D71:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425D80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_definition_head;
    lift_push32(cpu, cpu->edi);
    if (cpu->esi == 0u) goto label_00025DB9;
    label_00025D90:
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->edx = 0x596u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425DA4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425DA4u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    if (cpu->esi != 0u) goto label_00025D90;
    g_sfera_effect_manager.effect_definition_head = cpu->esi;
    label_00025DB9:
    cpu->esi = g_sfera_effect_manager.particle_resource_head;
    if (cpu->esi == 0u) goto label_00025DF1;
    label_00025DC3:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x54u);
    cpu->edx = 0x5A1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425DD5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425DD5u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425DDCu)); sfera_sub_004834C0(cpu, LIFT_CODE_TOKEN_VA(0x425DDCu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425DE2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x425DE2u));
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if (cpu->edi != 0u) goto label_00025DC3;
    g_sfera_effect_manager.particle_resource_head = cpu->edi;
    label_00025DF1:
    sub_pred[0] = (uint32_t)(g_sfera_effect_manager.particle_random_table) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00025E23;
    cpu->edx = 0x5A9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425E0Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425E0Bu));
    cpu->eax = g_sfera_effect_manager.particle_random_table;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425E16u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x425E16u));
    cpu->esp += 4u;
    g_sfera_effect_manager.particle_random_table = 0u;
    label_00025E23:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425E30(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = (double)-1.0f;
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    *(float*)(cpu->eax + 0x18u) = x87_v0;
    *(float*)(cpu->eax + 0x1Cu) = x87_v0; 
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->eax));
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 0x54u) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425E70(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->esi));
    if (sub_pred[0]) goto label_00025EA0;
    if (*(uint8_t*)(cpu->esi + 0xCu) != 0u) goto label_00025EA0;
    cpu->edx = 0x67Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425E94u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425E94u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425E9Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x425E9Du));
    cpu->esp += 4u;
    label_00025EA0:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425EB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->esi == 0u) goto label_00025F0C;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00025EC5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00025EC5;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00025F0C;
    cpu->edx = 0x68Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425EDFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425EDFu));
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00025EE4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00025EE4;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425EF4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x425EF4u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    label_00025F00:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00025F00;
    goto label_00025F13;
    label_00025F0C:
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    label_00025F13:
    if (cpu->ebx == 0u) goto label_00025F2F;
    cpu->edx = 0x690u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425F26u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425F26u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425F2Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x425F2Cu));
    cpu->esp += 4u;
    label_00025F2F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425F60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x6BEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x425F72u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x425F72u));
    if (cpu->esi == 0u) goto label_00025F81;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IEffectManager*>(cpu->esi)->destroyEffect(cpu);
    label_00025F81:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00425FA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = cpu->ecx;
    x87_v0 = (double)-1.0f;
    cpu->ecx = 0u;
    *(float*)(cpu->eax + 0x18u) = x87_v0;
    cpu->edx |= 0xFFFFFFFFu;
    *(float*)(cpu->eax + 0x1Cu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 0x54u) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->ecx;
    std::construct_at(reinterpret_cast<CScriptedEffect*>(cpu->eax));
    *(uint32_t*)(cpu->eax + 0x9Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xA0u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xB0u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x28u) = 1u;
    *(uint32_t*)(cpu->eax + 0xF8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xF4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xECu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xE8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xF0u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xBCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xB8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xB4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xA8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xACu) = 1u;
    *(uint32_t*)(cpu->eax + 0xA4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xC4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xC0u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xC8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xD0u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xD4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xD8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xDCu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xE0u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xE4u) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426080(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = *(uint32_t*)(cpu->esp + 4u) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (!sub_pred[0]) goto label_00026091;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00026091:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->esi + 0xB8u) <= cpu->ebx) goto label_000260DB;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->edi = 0u;
    label_000260B0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xE8u);
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->eax);
    if (cpu->eax == 0u) goto label_000260CC;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x260C5u), LIFT_CODE_TOKEN_RVA(0x260C3u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000260E5;
    label_000260CC:
    ++cpu->ebx;
    cpu->edi += 0x9Cu;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0xB8u)) goto label_000260B0;
    label_000260DB:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000260E5:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004260F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = *(uint32_t*)(cpu->esp + 4u) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (!sub_pred[0]) goto label_00026101;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00026101:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->esi + 0xC4u) <= cpu->ebx) goto label_0002614B;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->edi = 0u;
    label_00026120:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xF0u);
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->eax);
    if (cpu->eax == 0u) goto label_0002613C;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x26135u), LIFT_CODE_TOKEN_RVA(0x26133u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00026155;
    label_0002613C:
    ++cpu->ebx;
    cpu->edi += 0x19Cu;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0xC4u)) goto label_00026120;
    label_0002614B:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00026155:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 0xC4u)) goto label_00026171;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00026171:
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x19Cu);
    cpu->eax += *(uint32_t*)(cpu->ecx + 0xF0u);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 0xBCu)) goto label_00026191;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00026191:
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->eax += *(uint32_t*)(cpu->ecx + 0xECu);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004261A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xB0u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004261B0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_effect_manager.effects_enabled = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004261C0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xA0u);
    *(uint8_t*)(cpu->ebp + 0xDu) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0xD4u) == 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->edi;
    *(float*)(cpu->ebp + 0x1Cu) = (double)*(float*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    x87_v0 = (double)*(float*)(cpu->ebx + 0x18u);
    *(uint32_t*)(cpu->ebp + 0x38u) = cpu->edi;
    *(float*)(cpu->ebp + 0x18u) = x87_v0; 
    *(uint8_t*)(cpu->ebp + 0xFu) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xACu);
    *(uint32_t*)(cpu->ebp + 0xACu) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xA8u) = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xE4u) = cpu->edi;
    if (sub_pred[0]) goto label_00026277;
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x26227u), LIFT_CODE_TOKEN_RVA(0x26225u))) { return; }
    cpu->eax&=0x80000001u; lift_test[0]=cpu->eax==0u;
    if (((cpu->eax)&0x80000000u)==0u) goto label_00026233;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    ++cpu->eax; lift_test[0]=cpu->eax == 0u;
    label_00026233:
    if (!lift_test[0]) goto label_0002623F;
    *(uint32_t*)(cpu->ebp + 0xE4u) = 1u;
    label_0002623F:
    if (*(uint32_t*)(cpu->ebp + 0xE4u) != cpu->edi) goto label_0002625B;
    if (*(uint32_t*)(cpu->ebp + 0xD8u) <= cpu->edi) goto label_0002626F;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x26251u), LIFT_CODE_TOKEN_RVA(0x2624Fu))) { return; }
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->ebp + 0xD8u)); cpu->eax = n / d; cpu->edx = n % d; }
    goto label_00026271;
    label_0002625B:
    if (*(uint32_t*)(cpu->ebp + 0xE0u) <= cpu->edi) goto label_0002626F;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x26265u), LIFT_CODE_TOKEN_RVA(0x26263u))) { return; }
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->ebp + 0xE0u)); cpu->eax = n / d; cpu->edx = n % d; }
    goto label_00026271;
    label_0002626F:
    cpu->edx = 0u;
    label_00026271:
    *(uint32_t*)(cpu->ebp + 0xD0u) = cpu->edx;
    label_00026277:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xB4u);
    if (cpu->ecx == cpu->edi) goto label_0002628D;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xB4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2628Du)); sfera_sub_00496960(cpu, LIFT_CODE_TOKEN_RVA(0x2628Du));
    label_0002628D:
    cpu->edx = 0u;
    if (*(uint32_t*)(cpu->ebp + 0xBCu) <= cpu->edi) goto label_000262D3;
    cpu->eax = 0u;
    label_000262A0:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xECu);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xECu);
    cpu->esi += cpu->eax;
    cpu->edi += cpu->eax;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),100u); cpu->esi += 100u; cpu->edi += 100u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xECu);
    *(uint32_t*)(cpu->eax + cpu->ecx + 0x2Cu) = 1u;
    ++cpu->edx;
    cpu->eax += 0x64u;
    if (cpu->edx < *(uint32_t*)(cpu->ebp + 0xBCu)) goto label_000262A0;
    cpu->edi = 0u;
    label_000262D3:
    if (*(uint32_t*)(cpu->ebp + 0xB8u) <= cpu->edi) goto label_00026307;
    cpu->esi = 0u;
    label_000262E0:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xE8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xE8u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4262F6u)); sfera_sub_00483A80(cpu, LIFT_CODE_TOKEN_VA(0x4262F6u));
    ++cpu->edi;
    cpu->esi += 0x9Cu;
    if (cpu->edi < *(uint32_t*)(cpu->ebp + 0xB8u)) goto label_000262E0;
    cpu->edi = 0u;
    label_00026307:
    if (*(uint32_t*)(cpu->ebp + 0xC4u) <= 0u) goto label_00026337;
    cpu->esi = 0u;
    label_00026312:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xF0u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426328u)); sfera_sub_004844D0(cpu, LIFT_CODE_TOKEN_VA(0x426328u));
    ++cpu->edi;
    cpu->esi += 0x19Cu;
    if (cpu->edi < *(uint32_t*)(cpu->ebp + 0xC4u)) goto label_00026312;
    label_00026337:
    cpu->edx = 0u;
    if (*(uint32_t*)(cpu->ebp + 0xC8u) <= cpu->edx) goto label_0002642C;
    if (*(uint32_t*)(cpu->ebp + 0xCCu) <= cpu->edx) goto label_0002642C;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if (*(uint32_t*)(cpu->ebp + 0xC4u) <= cpu->edx) goto label_0002642C;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    label_00026370:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xF0u);
    cpu->edi += cpu->edx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (*(uint32_t*)(cpu->edx + cpu->ecx + 0x18Cu) <= cpu->eax) goto label_0002640D;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (*(uint32_t*)(cpu->edi + 0x18Cu) <= cpu->eax) goto label_0002640D;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000263A1:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xF0u);
    cpu->esi = *(uint32_t*)(cpu->edx + cpu->ecx + 0x188u);
    cpu->esi += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000263F7;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x19Cu);
    cpu->eax += cpu->ecx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_000263F3;
    cpu->ebx = 0u;
    (void)cpu;
    label_000263D0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4263DFu)); sfera_sub_004844D0(cpu, LIFT_CODE_TOKEN_VA(0x4263DFu));
    ++cpu->edi;
    cpu->ebx += 0x19Cu;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_000263D0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    label_000263F3:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_000263F7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x14u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->edi + 0x18Cu)) goto label_000263A1;
    label_0002640D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->eax;
    cpu->edx += 0x19Cu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if (cpu->eax < *(uint32_t*)(cpu->ebp + 0xC4u)) goto label_00026370;
    label_0002642C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (*(uint32_t*)(cpu->ecx + 0xC8u) == cpu->edi) goto label_00026631;
    if (*(uint32_t*)(cpu->ecx + 0xCCu) == cpu->edi) goto label_00026631;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0xF8u);
    if (cpu->ebx == cpu->edi) goto label_00026630;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xF4u);
    if (cpu->edx == cpu->edi) goto label_00026630;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    if (*(uint32_t*)(cpu->ecx + 0xC4u) <= cpu->edi) goto label_00026630;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    label_000264A0:
    cpu->esi = *(uint32_t*)(cpu->ecx + 0xF0u);
    cpu->esi += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18Cu);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    if (cpu->eax <= cpu->edi) goto label_00026611;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    label_000264D0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x188u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    if (cpu->ebp == 0xFFFFFFFFu) goto label_00026598;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x19Cu);
    cpu->ebp += *(uint32_t*)(cpu->ecx + 0xF0u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if ((*(uint32_t*)(cpu->eax + 4u) == cpu->edi) || ((int32_t)(*(uint32_t*)(cpu->eax + 4u)) < (int32_t)(cpu->edi))) goto label_00026598;
    label_00026510:
    cpu->edi = cpu->ebx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->ebp),412u); cpu->edi += 412u;
    *(uint32_t*)(cpu->ebx + 0x198u) = 1u;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x5Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax <<= 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x426537u));
    cpu->esi = native_function_address32(&::rand);
    cpu->esp += 0xCu;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x26547u), LIFT_CODE_TOKEN_RVA(0x26545u))) { return; }
    cpu->ecx = 0xFFu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->ebx + 0xD8u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x26557u), LIFT_CODE_TOKEN_RVA(0x26555u))) { return; }
    *(uint32_t*)(cpu->ebx + 0xDCu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2655Fu), LIFT_CODE_TOKEN_RVA(0x2655Du))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->ebx + 0xE0u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x5Cu);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx <<= 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->ebx += 0x19Cu;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)(cpu->eax) < (int32_t)(*(uint32_t*)(cpu->ecx + 4u))) goto label_00026510;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = 0u;
    label_00026598:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x14u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x18Cu)) goto label_000264D0;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x5Cu) <= cpu->edi) goto label_00026611;
    cpu->ebp = 0u;
    label_000265C0:
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->ebp + 0x4Cu);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000265FE;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x188u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    if (*(uint32_t*)(cpu->ecx + cpu->eax + 0x10u) == 0xFFFFFFFFu) goto label_000265FA;
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->eax + 8u);
    *(uint32_t*)(cpu->edi + cpu->ebp + 0x48u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x188u);
    *(uint32_t*)(cpu->ecx + cpu->eax + 8u) = (uint64_t)(*(uint32_t*)(cpu->ecx + cpu->eax + 8u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u);
    cpu->eax = cpu->ecx + cpu->eax + 8u;
    label_000265FA:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000265FE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->ebp += 0x50u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x5Cu)) goto label_000265C0;
    cpu->edi = 0u;
    label_00026611:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 0xC4u)) goto label_000264A0;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00026630:
    cpu->ebx = lift_pop32(cpu);
    label_00026631:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426640(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB4u);
    if (cpu->ecx == 0u) goto label_0002669D;
    if (*(uint32_t*)(cpu->esi + 0xA8u) != 0u) goto label_0002668B;
    { const double lift_right=(double)*(float*)(cpu->esp + 0xCu); const double lift_left=(double)*(float*)(cpu->ecx + 0xACu); if (!(lift_left<lift_right)) goto label_00026670; }
    cpu->eax = 1u;
    goto label_00026672;
    label_00026670:
    cpu->eax = 0u;
    label_00026672:
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42667Du)); sfera_sub_00496650(cpu, LIFT_CODE_TOKEN_VA(0x42667Du));
    *(uint32_t*)(cpu->esi + 0xA8u) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0002668B:
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2669Du)); sfera_sub_00496BD0(cpu, LIFT_CODE_TOKEN_RVA(0x2669Du));
    label_0002669D:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004266B0(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint32_t*)(cpu->ecx + 0xACu) == 0u) goto label_000266C5;
    if (*(uint32_t*)(cpu->esp + 4u) != 0u) goto label_000266C5;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000266C5:
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
