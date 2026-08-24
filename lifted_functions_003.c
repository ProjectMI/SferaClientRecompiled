#include "lifted_functions.h"
#include "lifted_normalized_ops.h"
#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C5B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C5B0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFA0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C5DDu); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x144u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edx = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->edx + 0x4F40u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 0xA8u);
    cpu->ebx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 0xA8u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C613u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x178u));
    cpu->edx = lift_load32(cpu->esi + 0x17Cu);
    cpu->eax = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x174u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x170u);
    lift_store32(cpu->ebp + 0xFFFFFF9Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x180u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C64Au); lift_push32(cpu, r); sfera_sub_0041C220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0x34u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFF9Cu);
    cpu->edx = lift_load32(cpu->ebx + 0x38u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41C65Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41C663u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->ebp + 0xFFFFFFA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store32(cpu->ebp + 0xFFFFFFB0u, cpu->eax);
    lift_store_f32(cpu->ebp + 0xFFFFFFA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store32(cpu->ebp + 0xFFFFFFB4u, cpu->ecx);
    lift_store_f32(cpu->ebp + 0xFFFFFFACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFACu);
    lift_store32(cpu->ebp + 0xFFFFFFB8u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFBCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C692u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFB4u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFB8u);
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->edi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 8u, cpu->edx);
    cpu->eax = cpu->edi;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFF90u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C6C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C6C0u);
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0001C6DF;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C6DFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001C6DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C6DFu);
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0001C70D;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C70Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001C70D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C70Du);
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0001C738;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C738u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001C738: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C738u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x10u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C774u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x7534u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x7538u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x7534u))));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001C7BF;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    goto label_0001C7C1;
    label_0001C7BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C7BFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001C7C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C7C1u);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001C7DC;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_0001C7DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C7DCu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C7F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esp + 0xFFFFFF8Cu);
    cpu->esp -= 0x9Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 0x7Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0001C81B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C81Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0001C81B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C81Bu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0001C82F;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C82Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001C82F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C82Fu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u));
    lift_push32(cpu, 0x47Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C846u); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint8_t)(lift_load8(cpu->edi + 0x141u)) == (uint8_t)(0u)) goto label_0001CC77;
    cpu->ecx = (uint32_t)(cpu->ebp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C864u); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C86Fu); lift_push32(cpu, r); sfera_sub_0041B5B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001CC77;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x30u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->ebp + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x40u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->ebp + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x100u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x50u));
    lift_store_f32(cpu->ebp + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x60u));
    lift_store_f32(cpu->ebp + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x34u));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x44u));
    lift_store_f32(cpu->ebp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x54u));
    lift_store_f32(cpu->ebp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x64u));
    lift_store_f32(cpu->ebp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x38u));
    lift_store_f32(cpu->ebp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x48u));
    lift_store_f32(cpu->ebp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x58u));
    lift_store_f32(cpu->ebp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x68u));
    lift_store_f32(cpu->ebp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x3Cu));
    lift_store_f32(cpu->ebp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x4Cu));
    lift_store_f32(cpu->ebp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x5Cu));
    lift_store_f32(cpu->ebp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x6Cu));
    lift_store_f32(cpu->ebp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C8EEu); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebp + 0xFFFFFFD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_store_f32(cpu->ebp + 0xFFFFFFDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store_f32(cpu->ebp + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C949u); lift_push32(cpu, r); sfera_sub_004681A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C950u); lift_push32(cpu, r); sfera_sub_00468750(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C955u); lift_push32(cpu, r); sfera_sub_00450A00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x144u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->eax);
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x4F3Cu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0xA8u);
    cpu->ebx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0xA8u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C991u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x178u));
    cpu->edx = lift_load32(cpu->edi + 0x174u);
    cpu->eax = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x180u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x17Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x170u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C9C7u); lift_push32(cpu, r); sfera_sub_0041C220(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x148u));
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C9E0u); lift_push32(cpu, r); sfera_sub_0041BEE0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001CA00;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1CA00u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    label_0001CA00: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CA00u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001CA18;
    cpu->eax = 1u;
    goto label_0001CA1A;
    label_0001CA18: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CA18u);
    cpu->eax = 0u;
    label_0001CA1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CA1Au);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx += 0x330u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CA44u); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 8u;
    lift_x87_push(cpu, 1.0);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CA57u); lift_push32(cpu, r); sfera_sub_0041BEE0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001CA73;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1CA73u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    label_0001CA73: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CA73u);
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(g_sfera_client_main_scalar_runtime.counter_03), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001CAA6;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0001CA80: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CA80u);
    if ((uint32_t)(lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_active[0]))) != (uint32_t)(1u)) goto label_0001CA9D;
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    lift_push32(cpu, 0x4B8u);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1CA9Du); lift_push32(cpu, r); sfera_sub_00460110(cpu,r); if (cpu->eip != r) return; }
    label_0001CA9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CA9Du);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_client_main_scalar_runtime.counter_03), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001CA80;
    label_0001CAA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CAA6u);
    cpu->eax = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = lift_load32(cpu->ebx + 0x38u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CABAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CABFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->edi + 0x190u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->edi + 0x190u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0x30u);
    lift_store_f32(cpu->edi + 0x194u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->edi + 0x198u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CAE8u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x40u);
    cpu->eax = (uint32_t)(cpu->edi + 0x1A8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CAF3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CAF8u);
    lift_x87_push(cpu, 0.0);
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->ebp + 0x30u);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x1A8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CB12u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CB17u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_store_f32(cpu->edi + 0x1B4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x1C4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x1D4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebx + 0x30u);
    cpu->edx = lift_load32(cpu->ebx + 0x38u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CB3Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CB44u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->edi + 0x19Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->edi + 0x19Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0x30u);
    lift_store_f32(cpu->edi + 0x1A0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->edi + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CB6Du); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebx + 0x1Cu);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(6u), 32u);
    cpu->esi += lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = (uint32_t)(cpu->edi + 0x228u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0x30u);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->edi + 0x22Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->edi + 0x230u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CB9Bu); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x40u);
    cpu->ebx = (uint32_t)(cpu->edi + 0x1E8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CBA6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CBABu);
    lift_push32(cpu, 0x40u);
    cpu->eax = (uint32_t)(cpu->edi + 0x234u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CBB6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CBBBu);
    cpu->esp += 0x18u;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->ebp + 0x30u);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_store_f32(cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFECu));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFECu));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFECu));
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store_f32(cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFECu));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store_f32(cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFECu));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_store_f32(cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFECu));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CC3Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CC40u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->edi + 0x234u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41CC4Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CC51u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->edi + 0x1F4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x204u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x214u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x240u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x250u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x260u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001CC77: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CC77u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = (uint32_t)(cpu->ebp + 0x74u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041CC90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41CC90u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CCA1u); lift_push32(cpu, r); sfera_sub_0045A9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 4u) + 0x22u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi));
    cpu->ecx = lift_load32(cpu->eax + cpu->edi + 8u);
    cpu->ebx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    lift_push32(cpu, 0xDEu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CCE0u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->edi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41CCE9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CCEEu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx -= cpu->eax;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 2u));
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->eax -= cpu->ecx;
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 4u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    lift_store32(cpu->esi + 0x18u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x41CD20u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CD26u);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001CD64;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    (void)cpu;
    label_0001CD30: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CD30u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebp)) != (uint8_t)(0x5Fu)) goto label_0001CD5B;
    cpu->ebx = (int8_t)(lift_load8(cpu->eax + cpu->ebp + 1u));
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x30u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0001CD48;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(7u)) goto label_0001CD57;
    label_0001CD48: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CD48u);
    cpu->edx = 0xEDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1CD57u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001CD57: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CD57u);
    lift_store32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x1Cu, cpu->edi);
    label_0001CD5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CD5Bu);
    ++cpu->edi;
    cpu->ebp += 0x1Eu;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001CD30;
    cpu->ebp = lift_pop32(cpu);
    label_0001CD64: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CD64u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, 0xF4u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CD78u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CD96u); lift_push32(cpu, r); sfera_sub_0041C220(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041CDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41CDA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x150u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x164u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, 0x7540u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41CDE5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CDEAu);
    cpu->edi = lift_load32(cpu->esp + 0x184u);
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x64u)) goto label_0001CE08;
    cpu->edx = 0x10Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1CE08u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001CE08: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CE08u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esi + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CE43u); lift_push32(cpu, r); sfera_sub_0041B980(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xA8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"xadd\\man.skl");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CE54u); lift_push32(cpu, r); sfera_sub_0041CC90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0xE4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"xadd\\woman.skl");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CE67u); lift_push32(cpu, r); sfera_sub_0041CC90(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x114u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = 0x2260u;
    lift_store32(cpu->esi + 0x4F40u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CE81u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F40u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001D0B2;
    cpu->edx = (uint32_t)(cpu->esi + 0x120u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    label_0001CE9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CE9Fu);
    cpu->edi = lift_load32(cpu->esp + 0x174u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001CEB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CEB0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001CEB0;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0xC8u)) goto label_0001CECF;
    cpu->edx = 0x11Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1CECFu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001CECF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CECFu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->edx = cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0001CEE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CEE0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0001CEE0;
    lift_push32(cpu, (uintptr_t)"*.chr"); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CEF9u); lift_push32(cpu, r); sfera_sub_0047EBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x170u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CF10u); lift_push32(cpu, r); sfera_sub_0047ED30(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41CF11u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41CF17u);
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_store32(cpu->esp + 0x16Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CF34u); lift_push32(cpu, r); sfera_sub_0047ED10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0001D04A;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0001CF40: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CF40u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x38u)) & (0x10u)) != 0u) goto label_0001D025;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001CF52: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CF52u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001CF52;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(5u)) goto label_0001CF65;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x20u)) goto label_0001CF74;
    label_0001CF65: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CF65u);
    cpu->edx = 0x124u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1CF74u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001CF74: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CF74u);
    cpu->edi = cpu->ebp;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x2Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    cpu->edi += cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CF89u); lift_push32(cpu, r); sfera_sub_0047ED40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x16Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CF9Bu); lift_push32(cpu, r); sfera_sub_0047ED30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_0001CFA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41CFA0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001CFA0;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x16Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CFBEu); lift_push32(cpu, r); sfera_sub_0047EDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CFC5u); lift_push32(cpu, r); sfera_sub_0047EA20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0u;
    ++cpu->ebp;
    lift_store32(cpu->edi + 0x24u, cpu->eax);
    lift_store32(cpu->edi + 0x20u, cpu->ecx);
    lift_store32(cpu->edi + 0x28u, cpu->eax);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0xC8u)) goto label_0001D025;
    cpu->edx = lift_load32(cpu->esi + 0x4F48u);
    cpu->ecx = lift_load32(cpu->esi + 0x4F44u);
    cpu->edx += cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, 0x12Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41CFFDu); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x4F48u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, 0x2260u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esi + 0x4F44u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41D015u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41D01Au);
    lift_store32(cpu->esi + 0x4F48u, (uint64_t)(lift_load32(cpu->esi + 0x4F48u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->esp += 0xCu;
    cpu->ebp = 0u;
    label_0001D025: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D025u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41D02Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41D035u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001CF40;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41D041u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41D047u);
    cpu->esp += 4u;
    label_0001D04A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D04Au);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0xC8u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F40u))) goto label_0001CE9F;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0001D0B2;
    cpu->edx = lift_load32(cpu->esi + 0x4F48u);
    cpu->ecx = lift_load32(cpu->esi + 0x4F44u);
    cpu->edx += cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, 0x13Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D08Bu); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x4F48u);
    cpu->ecx = cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x2Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esi + 0x4F44u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41D0A4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41D0A9u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x4F48u, (uint64_t)(lift_load32(cpu->esi + 0x4F48u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    label_0001D0B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D0B2u);
    lift_push32(cpu, 0x13Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D0C3u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D0CAu); lift_push32(cpu, r); sfera_sub_004815D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"xadd\\subobjs.dat";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D0D4u); lift_push32(cpu, r); sfera_sub_00482170(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)"subobjs";
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D0E4u); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(1u)) goto label_0001D36E;
    label_0001D0F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D0F3u);
    cpu->ecx = cpu->edi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x54u);
    lift_push32(cpu, 0x147u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D107u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x148u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    cpu->ecx = 0x6800u;
    lift_store32(cpu->esi + 0x4F4Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D121u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x6800u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x4F50u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41D132u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41D137u);
    cpu->ebx = 0u;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0001D331;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    label_0001D150: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D150u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)"subobjs";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D163u); lift_push32(cpu, r); sfera_sub_00481300(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"s";
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D17Au); lift_push32(cpu, r); sfera_sub_00481180(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001D36E;
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)"m";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D193u); lift_push32(cpu, r); sfera_sub_00481180(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001D36E;
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi + 0x4F48u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0001D200;
    cpu->ebp = lift_load32(cpu->esi + 0x4F44u);
    label_0001D1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D1B0u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = cpu->ebp;
    label_0001D1B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D1B6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001D1D6;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0001D1D2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001D1D6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0001D1B6;
    label_0001D1D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D1D2u);
    cpu->eax = 0u;
    goto label_0001D1DB;
    label_0001D1D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D1D6u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0001D1DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D1DBu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001D1ED;
    ++cpu->ebx;
    cpu->ebp += 0x2Cu;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u))) goto label_0001D1B0;
    goto label_0001D1FA;
    label_0001D1ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D1EDu);
    cpu->eax = lift_load32(cpu->esi + 0x4F4Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ecx + cpu->eax, cpu->ebx);
    label_0001D1FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D1FAu);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi + 0x4F48u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0001D200: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D200u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001D210;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = (uint32_t)(uintptr_t)"char model not found. name=";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1D210u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0001D210: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D210u);
    cpu->edx = lift_load32(cpu->esi + 0x4F4Cu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x50u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edx + 4u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41D223u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41D228u);
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(uintptr_t)"t";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D237u); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(1u)) goto label_0001D36E;
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0001D2AB;
    goto label_0001D254;
    label_0001D250: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D250u);
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    label_0001D254: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D254u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(uintptr_t)"t";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D266u); lift_push32(cpu, r); sfera_sub_004812A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001D36E;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edi += cpu->ebp;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D281u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x4F4Cu);
    lift_store32(cpu->edi + cpu->ecx + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x4F4Cu);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->edx + 4u)) != (uint32_t)(0xFFFFFFFFu)) goto label_0001D2A6;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"texture for char model not found. name=";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1D2A6u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0001D2A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D2A6u);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0001D250;
    label_0001D2AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D2ABu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x6Du)) goto label_0001D2BD;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x77u)) goto label_0001D36E;
    label_0001D2BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D2BDu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_0001D36E;
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x7Au)) goto label_0001D36E;
    cpu->eax = cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    label_0001D2D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D2D7u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_0001D2D7;
    cpu->eax -= cpu->ebp;
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0001D36E;
    cpu->edx = (int8_t)((cpu->edx & 0xFFu));
    cpu->edx -= 0x61u;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)(0x6Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (int8_t)(lift_load8(cpu->ecx + 2u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x54u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x15u) + (uint64_t)(0u));
    --cpu->eax;
    cpu->eax &= 0x1A00u;
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x4F50u);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_0001D150;
    cpu->ebx = 0u;
    label_0001D331: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D331u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(uintptr_t)"womanhelmsmall";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D33Fu); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(1u)) goto label_0001D36E;
    cpu->edi = 0u;
    cpu->ebx = (uint32_t)(cpu->esi + 0x74D4u);
    cpu->edi = cpu->edi;
    label_0001D350: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D350u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001D381;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"womanhelmsmall";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D364u); lift_push32(cpu, r); sfera_sub_00481200(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001D36E;
    ++cpu->edi;
    cpu->ebx += 4u;
    goto label_0001D350;
    label_0001D36E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D36Eu);
    cpu->ecx = (uint32_t)(uintptr_t)"wrong format of subobjs.dat";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D378u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    goto label_0001D0F3;
    label_0001D381: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D381u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D386u); lift_push32(cpu, r); sfera_sub_004815C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x164u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x15Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041D3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41D3C0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esp + 0xFFFFFF90u);
    cpu->esp -= 0xB0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0x78u);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFD4u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0001D3F1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1D3F1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0001D3F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D3F1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0001D405;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1D405u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001D405: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D405u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, 0x3B2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D41Cu); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint8_t)(lift_load8(cpu->ebx + 0x141u)) == (uint8_t)(0u)) goto label_0001E18E;
    cpu->ecx = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x14u);
    cpu->ecx = (uint32_t)(cpu->ebx + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D43Au); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D445u); lift_push32(cpu, r); sfera_sub_0041B5B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001E18E;
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 0x7530u, (uint64_t)(lift_load32(cpu->esi + 0x7530u)) + 1u);
    { uint64_t l=(uint64_t)(g_sfera_graphics_runtime.lods_enabled), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store_f32(cpu->ebp + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001D48C;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D46Cu); lift_push32(cpu, r); sfera_sub_0041C6C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->ebp + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ebp + 0xFFFFFFE8u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001D48C;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D487u); lift_push32(cpu, r); sfera_sub_0041C7F0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001E18E;
    label_0001D48C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D48Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x2Cu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x3Cu));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->ebp + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x100u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x4Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x5Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x30u));
    lift_store_f32(cpu->ebp + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x40u));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x50u));
    lift_store_f32(cpu->ebp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x60u));
    lift_store_f32(cpu->ebp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x34u));
    lift_store_f32(cpu->ebp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x44u));
    lift_store_f32(cpu->ebp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x54u));
    lift_store_f32(cpu->ebp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x64u));
    lift_store_f32(cpu->ebp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x38u));
    lift_store_f32(cpu->ebp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x48u));
    lift_store_f32(cpu->ebp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x58u));
    lift_store_f32(cpu->ebp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x68u));
    lift_store_f32(cpu->ebp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D500u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebp + 0xFFFFFFC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_store_f32(cpu->ebp + 0xFFFFFFC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFC0u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store_f32(cpu->ebp + 0xFFFFFFC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFC4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D55Bu); lift_push32(cpu, r); sfera_sub_004681A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D564u); lift_push32(cpu, r); sfera_sub_00468750(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D569u); lift_push32(cpu, r); sfera_sub_00450A00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D582u); lift_push32(cpu, r); sfera_sub_00461FD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0x144u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    cpu->esi = cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = lift_load32(cpu->esi + 0x4F40u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0xA8u);
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0xA8u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    lift_store32(cpu->ebp + 0xFFFFFFD0u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D5BEu); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x178u));
    cpu->edx = lift_load32(cpu->ebx + 0x174u);
    cpu->eax = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x180u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x17Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x170u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D5F5u); lift_push32(cpu, r); sfera_sub_0041C220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x7Cu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ecx);
    cpu->edx = cpu->eax;
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)))));
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_x87_push(cpu, 255.0);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) / (lift_x87_get(cpu, 0u)));
    cpu->eax &= 0xFFu;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    lift_x87_set(cpu, 0u, ((double)(((int32_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u))))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE8u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D665u); lift_push32(cpu, r); sfera_sub_0041BE20(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D68D;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D68Bu); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    label_0001D68D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D68Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x4F46u)) & 0xFFu);
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0001D731;
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D6B1;
    cpu->eax = 1u;
    goto label_0001D6B3;
    label_0001D6B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D6B1u);
    cpu->eax = 0u;
    label_0001D6B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D6B3u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0x200u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D6E2u); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D6FA;
    cpu->eax = 1u;
    goto label_0001D6FC;
    label_0001D6FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D6FAu);
    cpu->eax = 0u;
    label_0001D6FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D6FCu);
    cpu->ecx = lift_load8(cpu->esi + 0x4F48u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 3u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x4F40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x4F46u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0x400u);
    goto label_0001D7BC;
    label_0001D731: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D731u);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D73D;
    cpu->eax = 1u;
    goto label_0001D73F;
    label_0001D73D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D73Du);
    cpu->eax = 0u;
    label_0001D73F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D73Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x4F47u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0x1500u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D772u); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D78A;
    cpu->eax = 1u;
    goto label_0001D78C;
    label_0001D78A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D78Au);
    cpu->eax = 0u;
    label_0001D78C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D78Cu);
    cpu->ecx = lift_load8(cpu->esi + 0x4F48u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 3u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x4F40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x4F47u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0xB00u);
    label_0001D7BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D7BCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D7C5u); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D7DD;
    cpu->eax = 1u;
    goto label_0001D7DF;
    label_0001D7DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D7DDu);
    cpu->eax = 0u;
    label_0001D7DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D7DFu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load8(cpu->esi + 0x4F4Au);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x4F40u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0x600u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D812u); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D82A;
    cpu->eax = 1u;
    goto label_0001D82C;
    label_0001D82A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D82Au);
    cpu->eax = 0u;
    label_0001D82C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D82Cu);
    cpu->edx = lift_load8(cpu->esi + 0x4F45u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0x1300u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D85Fu); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D877;
    cpu->eax = 1u;
    goto label_0001D879;
    label_0001D877: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D877u);
    cpu->eax = 0u;
    label_0001D879: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D879u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx = lift_load8(cpu->esi + 0x4F44u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x4F40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0x100u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D8ACu); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 2u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_0001D8C5;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 3u);
    label_0001D8C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D8C5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D8DD;
    cpu->eax = 1u;
    goto label_0001D8DF;
    label_0001D8DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D8DDu);
    cpu->eax = 0u;
    label_0001D8DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D8DFu);
    cpu->ecx = lift_load8(cpu->esi + 0x4F4Cu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x4F4Bu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x4F40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1A00u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0x500u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D91Au); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x4F4Fu)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0001D96F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D93C;
    cpu->eax = 1u;
    goto label_0001D93E;
    label_0001D93C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D93Cu);
    cpu->eax = 0u;
    label_0001D93E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D93Eu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x4F40u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A00u);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0x700u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1D96Fu); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    label_0001D96F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D96Fu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x4F4Fu)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0001D994;
    cpu->ecx = lift_load32(cpu->esi + 0x4F40u);
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D98Cu); lift_push32(cpu, r); sfera_sub_0041C070(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001DA14;
    label_0001D994: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D994u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x80u); lift_push32(cpu, 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41D9A6u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001D9BE;
    cpu->eax = 1u;
    goto label_0001D9C0;
    label_0001D9BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D9BEu);
    cpu->eax = 0u;
    label_0001D9C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41D9C0u);
    cpu->ecx = lift_load8(cpu->esi + 0x4F4Eu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x4F4Fu)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x4F40u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1Au); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0x10u);
    cpu->ecx = lift_load8(cpu->esi + 0x4F4Du);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DA05u); lift_push32(cpu, r); sfera_sub_0041BA00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1DA14u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    label_0001DA14: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DA14u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DA1Bu); lift_push32(cpu, r); sfera_sub_00451A30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    label_0001DA20: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DA20u);
    if ((uint32_t)(lift_load32(cpu->ebx + ((uint32_t)(cpu->esi) * 4u) + 0xF8u)) == (uint32_t)(0u)) goto label_0001DDDF;
    if ((uint32_t)(cpu->esi) != (uint32_t)(3u)) goto label_0001DA44;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_0001DDDF;
    goto label_0001DA52;
    label_0001DA44: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DA44u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0001DA52;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1DA52u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0001DA52: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DA52u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_scene_array_runtime.character_matrices.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001DA66;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1DA66u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001DA66: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DA66u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0x1Cu);
    cpu->edx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(6u), 32u);
    cpu->esi += lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->edx);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DA9F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DA9Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DA9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DA9Fu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DAB7;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DAB4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DAB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DAB7u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DAD1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DACEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DAD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DAD1u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DAE9;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DAE6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DAE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DAE9u);
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xCu));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->edx + cpu->ecx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DB17;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DB14u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DB17: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DB17u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DB2F;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DB2Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DB2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DB2Fu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DB49;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DB46u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DB49: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DB49u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DB61;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DB5Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DB61: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DB61u);
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x1Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->edx + cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DB8F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DB8Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DB8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DB8Fu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DBA7;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DBA4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DBA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DBA7u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DBC1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DBBEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DBC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DBC1u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DBD9;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DBD6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DBD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DBD9u);
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x2Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->edx + cpu->ecx + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DC07;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DC04u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DC07: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DC07u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DC1F;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DC1Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DC1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DC1Fu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DC39;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DC36u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DC39: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DC39u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DC51;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DC4Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DC51: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DC51u);
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 4u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32(cpu->edx + cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DC7F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DC7Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DC7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DC7Fu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DC97;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DC94u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DC97: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DC97u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DCB1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DCAEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DCB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DCB1u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DCC9;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DCC6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DCC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DCC9u);
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 8u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_store_f32(cpu->edx + cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DCF7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DCF4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DCF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DCF7u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DD0F;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DD0Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DD0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DD0Fu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DD29;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DD26u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DD29: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DD29u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DD41;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DD3Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DD41: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DD41u);
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x18u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_store_f32(cpu->edx + cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DD6F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DD6Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DD6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DD6Fu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DD87;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DD84u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DD87: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DD87u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->esi += g_sfera_scene_array_runtime.character_matrices.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001DDA1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DD9Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DDA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DDA1u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.character_matrices.capacity)) goto label_0001DDB6;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1DDB6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001DDB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DDB6u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += g_sfera_scene_array_runtime.character_matrices.data;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DDC5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41DDCAu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx = lift_load32(cpu->ebx + ((uint32_t)(cpu->eax) * 4u) + 0xF8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DDD9u); lift_push32(cpu, r); sfera_sub_00477020(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_0001DDDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DDDFu);
    ++cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(5u)) goto label_0001DA20;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DDF3u); lift_push32(cpu, r); sfera_sub_00451A30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DE07u); lift_push32(cpu, r); sfera_sub_0041BEE0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001DE23;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1DE23u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    label_0001DE23: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DE23u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFCCu));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->ebx;
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41DE39u); lift_push32(cpu, r); sfera_sub_00470B80(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(g_sfera_client_main_scalar_runtime.counter_03), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001DE69;
    label_0001DE43: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DE43u);
    if ((uint32_t)(lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_active[0]))) != (uint32_t)(1u)) goto label_0001DE60;
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    lift_push32(cpu, 0x43Du);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1DE60u); lift_push32(cpu, r); sfera_sub_00460110(cpu,r); if (cpu->eip != r) return; }
    label_0001DE60: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DE60u);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_client_main_scalar_runtime.counter_03), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001DE43;
    label_0001DE69: cpu->eip = LIFT_CODE_TOKEN_VA(0x41DE69u);
    cpu->eax = lift_load32(cpu->edi + 0x2Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = lift_load32(cpu->edi + 0x38u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DE7Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41DE82u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->ebx + 0x190u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    cpu->eax = (uint32_t)(cpu->ebx + 0x1A8u);
    lift_store_f32(cpu->ebx + 0x194u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->ebx + 0x198u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x190u));
    lift_store_f32(cpu->ebp + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x194u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x198u));
    lift_store_f32(cpu->ebp + 0xFFFFFFD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFD0u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFD4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x38u))));
    lift_store_f32(cpu->ebx + 0x190u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x48u))));
    lift_store_f32(cpu->ebx + 0x194u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x50u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x4Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x54u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x58u))));
    lift_store_f32(cpu->ebx + 0x198u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41DF2Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41DF2Fu);
    lift_x87_push(cpu, 0.0);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebx + 0x1A8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DF49u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41DF4Eu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ebx + 0x1B4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x1C4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x1D4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx = lift_load32(cpu->edi + 0x38u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41DF76u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41DF7Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->ebx + 0x19Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->ebx + 0x1A0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->ebx + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x19Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1A0u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1A4u));
    lift_store_f32(cpu->ebp + 0xFFFFFFD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFD0u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x2Cu))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFD4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x38u))));
    lift_store_f32(cpu->ebx + 0x19Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x48u))));
    lift_store_f32(cpu->ebx + 0x1A0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x50u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x4Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x54u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x58u))));
    lift_store_f32(cpu->ebx + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->edi + 0x1Cu);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(6u), 32u);
    cpu->esi += lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->ebx + 0x228u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->ebx + 0x22Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->ebx + 0x230u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x228u));
    lift_store_f32(cpu->ebp + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x22Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x230u));
    lift_store_f32(cpu->ebp + 0xFFFFFFD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFD0u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x2Cu))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFD4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x40u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->ebx + 0x1E8u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x38u))));
    lift_store_f32(cpu->ebx + 0x228u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x48u))));
    lift_store_f32(cpu->ebx + 0x22Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x50u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x4Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x54u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x58u))));
    lift_store_f32(cpu->ebx + 0x230u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41E0BDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E0C2u);
    lift_push32(cpu, 0x40u);
    cpu->eax = (uint32_t)(cpu->ebx + 0x234u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41E0CDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E0D2u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    cpu->esp += 0x18u;
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_store_f32(cpu->ebp + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFE4u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41E152u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E157u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x234u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41E163u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E168u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ebx + 0x1F4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x204u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x214u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x240u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x250u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x260u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001E18E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E18Eu);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = (uint32_t)(cpu->ebp + 0x70u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E1B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E1B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x410u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0001E1E0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x41E1C3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E1C9u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0001E1DA;
    cpu->edx = (uint32_t)(cpu->edi + 0x23u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CheckFiles.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1E1DAu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001E1DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E1DAu);
    lift_store32(cpu->esi + 0x410u, cpu->edi);
    label_0001E1E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E1E0u);
    lift_store32(cpu->esi + 0x404u, cpu->edi);
    lift_store32(cpu->esi + 0x40Cu, cpu->edi);
    lift_store32(cpu->esi + 0x37A4u, cpu->edi);
    lift_store32(cpu->esi + 0x37A8u, cpu->edi);
    lift_store32(cpu->esi + 0x37ACu, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x37B0u, 1u);
    lift_store32(cpu->esi + 0x37B4u, 0xFFFFFFFFu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E220u);
    cpu->eax = lift_load32(cpu->ecx + 0x37A4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x64u)) goto label_0001E231;
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
    label_0001E231: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E231u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x84u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx + 0x414u);
    label_0001E243: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E243u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    ++cpu->edx;
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0001E243;
    cpu->eax = lift_load32(cpu->ecx + 0x37A4u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x84u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx + 0x454u);
    label_0001E264: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E264u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    ++cpu->edx;
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0001E264;
    lift_store32(cpu->ecx + 0x37A4u, (uint64_t)(lift_load32(cpu->ecx + 0x37A4u)) + 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E280u);
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    label_0001E282: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E282u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_0001E290;
    cpu->eax ^= 0xEDB88320u;
    label_0001E290: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E290u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001E29D;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E29F;
    label_0001E29D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E29Du);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0001E29F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E29Fu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001E2AC;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2AE;
    label_0001E2AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2ACu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0001E2AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2AEu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001E2BB;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2BD;
    label_0001E2BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2BBu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0001E2BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2BDu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001E2CA;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2CC;
    label_0001E2CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2CAu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0001E2CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2CCu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001E2D9;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2DB;
    label_0001E2D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2D9u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0001E2DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2DBu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001E2E8;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2EA;
    label_0001E2E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2E8u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0001E2EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2EAu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001E2F7;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2F9;
    label_0001E2F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2F7u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0001E2F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E2F9u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u), cpu->eax);
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001E282;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E310u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0001E341;
    cpu->eax = lift_load32(cpu->ecx + 0x400u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    label_0001E324: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E324u);
    cpu->edi = (int8_t)(lift_load8(cpu->esi));
    cpu->edi ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_store32(cpu->ecx + 0x400u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001E324;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0001E341: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E341u);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E350u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0001E360: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E360u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001E360;
    cpu->eax -= cpu->esi;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(4u)) goto label_0001E374;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 4u, stop_address); return;
    label_0001E374: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E374u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edx + 0xFFFFFFFFu)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x6Cu)) goto label_0001E382;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x4Cu)) goto label_0001E3AD;
    label_0001E382: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E382u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edx + 0xFFFFFFFEu)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x64u)) goto label_0001E390;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x44u)) goto label_0001E3AD;
    label_0001E390: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E390u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edx + 0xFFFFFFFDu)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x6Du)) goto label_0001E39E;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x4Du)) goto label_0001E3AD;
    label_0001E39E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E39Eu);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->edx + 0xFFFFFFFCu)) != (uint8_t)(0x2Eu)) goto label_0001E3AD;
    cpu->eax = 1u;
    lift_return(cpu, 4u, stop_address); return;
    label_0001E3AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E3ADu);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E3C0u);
    cpu->eax = 0x10004u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41E3CAu); lift_push32(cpu, r); sfera_sub_004EEAF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10008u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + 0x400u, 0u);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x41E3F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E3FBu);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0001E409;
    cpu->eax = 0u;
    goto label_0001E464;
    label_0001E409: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E409u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x41E40Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E411u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x1001Cu);
    cpu->esp += 4u;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0001E423;
    cpu->edi = cpu->eax;
    label_0001E423: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E423u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x41E42Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E430u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0001E446;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E439u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E43Fu);
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_0001E463;
    label_0001E446: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E446u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41E453u); lift_push32(cpu, r); sfera_sub_0041E310(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E454u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E45Au);
    cpu->eax = lift_load32(cpu->ebx + 0x400u);
    cpu->esp += 4u;
    label_0001E463: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E463u);
    cpu->edi = lift_pop32(cpu);
    label_0001E464: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E464u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10004u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E480u);
    cpu->eax = 0x10004u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41E48Au); lift_push32(cpu, r); sfera_sub_004EEAF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10008u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    cpu->ebx = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x41E4ADu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E4B3u);
    cpu->ebp = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0xFFFFFFFFu)) goto label_0001E4C1;
    cpu->eax = 0u;
    goto label_0001E532;
    label_0001E4C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E4C1u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x41E4C3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E4C9u);
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(0x10000u)) goto label_0001E4DB;
    cpu->edi = 0x10000u;
    label_0001E4DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E4DBu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x41E4E2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E4E8u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0001E4FE;
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E4F1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E4F7u);
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_0001E531;
    label_0001E4FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E4FEu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0001E525;
    label_0001E510: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E510u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    cpu->ecx ^= cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->esi ^= lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u));
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001E510;
    label_0001E525: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E525u);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E526u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E52Cu);
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    label_0001E531: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E531u);
    cpu->edi = lift_pop32(cpu);
    label_0001E532: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E532u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10004u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E550u);
    cpu->esp -= 0x330u;
    cpu->eax = lift_load32(cpu->esp + 0x338u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x340u);
    cpu->esi = (uint32_t)(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->edi);
    cpu->esi -= cpu->ecx;
    label_0001E583: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E583u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0001E583;
    cpu->edx = cpu->eax;
    (void)cpu;
    label_0001E590: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E590u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001E590;
    cpu->edi = (uint32_t)(cpu->esp + 0x13Cu);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0001E5A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E5A1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001E5A1;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_movs8(cpu, 1u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x140u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41E5C6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E5CCu);
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_0001E673;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0001E5E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E5E0u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x14u)) & (0x10u)) != 0u) goto label_0001E65C;
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E5F1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E5F7u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001E65C;
    cpu->eax = lift_load32(cpu->esp + 0x344u);
    cpu->edx = (uint32_t)(cpu->esp + 0x23Cu);
    cpu->edx -= cpu->eax;
    cpu->edi = cpu->edi;
    label_0001E610: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E610u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001E610;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    cpu->edx = cpu->eax;
    label_0001E620: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E620u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001E620;
    cpu->edi = (uint32_t)(cpu->esp + 0x23Cu);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0001E631: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E631u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001E631;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x23Cu);
    lift_movs8(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41E65Au); lift_push32(cpu, r); sfera_sub_0041E480(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp += cpu->eax;
    label_0001E65C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E65Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41E662u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E668u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001E5E0;
    label_0001E673: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E673u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41E674u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E67Au);
    cpu->ecx = lift_load32(cpu->esp + 0x340u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x330u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E6A0u);
    cpu->esp -= 0x334u;
    cpu->eax = lift_load32(cpu->esp + 0x33Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x37B4u)) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0001E91A;
    cpu->ecx = lift_load32(cpu->esp + 0x340u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->esp + 0x23Cu);
    cpu->esi -= cpu->ecx;
    cpu->edi = cpu->edi;
    label_0001E6E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E6E0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0001E6E0;
    cpu->esi = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0001E6F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E6F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0001E6F0;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esp + 0x240u);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0001E702: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E702u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001E702;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_movs8(cpu, 1u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x244u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41E729u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E72Fu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store8(cpu->ebp + 0x37B8u, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0001E90E;
    label_0001E750: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E750u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x18u)) & (0x10u)) != 0u) goto label_0001E8F7;
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E765u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E76Bu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001E8F7;
    cpu->eax = lift_load32(cpu->esp + 0x348u);
    cpu->edx = (uint32_t)(cpu->esp + 0x140u);
    cpu->edx -= cpu->eax;
    label_0001E786: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E786u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0001E786;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->esi = cpu->eax;
    label_0001E796: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E796u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0001E796;
    cpu->edi = (uint32_t)(cpu->esp + 0x140u);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0001E7A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E7A7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001E7A7;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_push32(cpu, 0x110u);
    lift_movs8(cpu, 1u);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x41E7C2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E7C8u);
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0x408u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0001E98A;
    cpu->eax = (uint32_t)(cpu->esp + 0x140u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41E7E8u); lift_push32(cpu, r); sfera_sub_0041E350(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->ecx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ecx &= 0xFFFF0400u;
    cpu->ecx += 0x10000u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x144u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41E80Bu); lift_push32(cpu, r); sfera_sub_0041E3C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->ecx + 0x108u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0x408u);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->edx + 0x10Cu, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0x408u);
    lift_push32(cpu, 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41E83Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E841u);
    cpu->eax = lift_load32(cpu->ebp + 0x408u);
    lift_store8(cpu->eax + 0x106u, cpu->ebx & 0xFFu);
    cpu->ecx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->ecx + 4u, cpu->ebx);
    cpu->edx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->edx, cpu->ebx);
    cpu->esi = lift_load32(cpu->ebp + 0x404u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0001E879;
    cpu->eax = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->ebp + 0x404u, cpu->eax);
    goto label_0001E8C8;
    label_0001E879: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E879u);
    lift_store32(cpu->ebp + 0x40Cu, cpu->ebx);
    (void)cpu;
    label_0001E880: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E880u);
    cpu->ecx = lift_load32(cpu->ebp + 0x408u);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E88Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E894u);
    cpu->esp += 8u;
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_0001E933;
    lift_store32(cpu->ebp + 0x40Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0001E880;
    cpu->eax = lift_load32(cpu->ebp + 0x40Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x408u);
    cpu->eax = lift_load32(cpu->ebp + 0x40Cu);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_0001E8C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E8C8u);
    cpu->eax = lift_load32(cpu->ebp + 0x37A8u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0001E8EB;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_0001E8EB;
    lift_push32(cpu, 0x3E8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x41E8E1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E8E7u);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    label_0001E8EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E8EBu);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x37B4u)) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0001E90E;
    label_0001E8F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E8F7u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41E8FDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E903u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001E750;
    label_0001E90E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E90Eu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41E90Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41E915u);
    cpu->esp += 4u;
    label_0001E918: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E918u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0001E91A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E91Au);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x334u;
    lift_return(cpu, 8u, stop_address); return;
    label_0001E933: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E933u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->ebp + 0x404u))) goto label_0001E95D;
    cpu->eax = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->ecx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->ebp + 0x404u, cpu->edx);
    goto label_0001E8C8;
    label_0001E95D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E95Du);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x408u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->edx = lift_load32(cpu->ebp + 0x408u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0001E8C8;
    label_0001E98A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E98Au);
    lift_store8(cpu->ebp + 0x37B8u, cpu->ebx & 0xFFu);
    goto label_0001E918;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041E9A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41E9A0u);
    cpu->esp -= 0x11Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x124u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x37A4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001EC4F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x414u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi = cpu->edi;
    label_0001E9E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41E9E0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37B4u)) > (int32_t)(uint32_t)(0u)) goto label_0001EC4C;
    lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"xupdate"); lift_push32(cpu, cpu->edi);
    cpu->ebp = (uint32_t)(cpu->edi + 0x40u);
    lift_store32(cpu->esi + 0x404u, 0u);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x41EA02u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA08u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001EA89;
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EA14: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA14u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EA14;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001EAA6;
    label_0001EA23: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA23u);
    lift_push32(cpu, 0x3Bu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_strchr_address32(), LIFT_CODE_TOKEN_VA(0x41EA26u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA2Cu);
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0001EA86;
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41EA40u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA46u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + cpu->edi + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41EA5Fu); lift_push32(cpu, r); sfera_sub_0041E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->ebx + 1u);
    cpu->edx = cpu->ebp;
    cpu->edx -= cpu->eax;
    label_0001EA66: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA66u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EA66;
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EA75: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA75u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EA75;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EA23;
    goto label_0001EAA6;
    label_0001EA86: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA86u);
    lift_push32(cpu, cpu->ebp);
    goto label_0001EA9E;
    label_0001EA89: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA89u);
    lift_push32(cpu, (uintptr_t)"sphere.exe"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->edi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41EA99u); lift_push32(cpu, r); sfera_sub_0041E6A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"sphereclient.exe");
    label_0001EA9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EA9Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1EAA6u); lift_push32(cpu, r); sfera_sub_0041E6A0(cpu,r); if (cpu->eip != r) return; }
    label_0001EAA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EAA6u);
    cpu->eax = lift_load32(cpu->esi + 0x404u);
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 0x400u, cpu->ecx);
    lift_store32(cpu->esi + 0x40Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x408u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0001EC04;
    label_0001EAD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EAD0u);
    cpu->eax = lift_load32(cpu->esi + 0x408u);
    cpu->eax += 8u;
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_0001EAE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EAE0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EAE0;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    cpu->ebx = 0u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EAF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EAF3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EAF3;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001EB2D;
    cpu->edi = cpu->edi;
    label_0001EB00: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB00u);
    cpu->eax = (int8_t)(lift_load8(cpu->esp + cpu->ebx + 0x28u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::tolower), LIFT_CODE_TOKEN_VA(0x41EB06u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB0Cu);
    lift_store8(cpu->esp + cpu->ebx + 0x2Cu, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->esp += 4u;
    ++cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EB20: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB20u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EB20;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->eax)) goto label_0001EB00;
    label_0001EB2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB2Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EB34: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB34u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EB34;
    cpu->eax -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001EB6B;
    cpu->eax = lift_load32(cpu->esi + 0x400u);
    cpu->edi = cpu->edi;
    label_0001EB50: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB50u);
    cpu->ebx = (int8_t)(lift_load8(cpu->edx));
    cpu->ebx ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esi + 0x400u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EB50;
    label_0001EB6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB6Bu);
    cpu->ebx = lift_load32(cpu->esi + 0x408u);
    cpu->eax = lift_load32(cpu->esi + 0x400u);
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->ebx + 0x108u);
    label_0001EB82: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EB82u);
    cpu->ebp = (int8_t)(lift_load8(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(cpu->esi + ((uint32_t)(cpu->ebp) * 4u));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esi + 0x400u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EB82;
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->ebx + 0x10Cu);
    label_0001EBB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EBB0u);
    cpu->ebx = (int8_t)(lift_load8(cpu->edx));
    cpu->ebx ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esi + 0x400u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EBB0;
    cpu->eax = lift_load32(cpu->esi + 0x40Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001EBDF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EBD6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EBDCu);
    cpu->esp += 4u;
    label_0001EBDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EBDFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x37B4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 0x408u);
    lift_store32(cpu->esi + 0x40Cu, cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0001EC04;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0x408u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0001EAD0;
    label_0001EC04: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC04u);
    cpu->eax = lift_load32(cpu->esi + 0x40Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001EC18;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EC0Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC15u);
    cpu->esp += 4u;
    label_0001EC18: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC18u);
    cpu->edx = lift_load32(cpu->esi + 0x400u);
    lift_store32(cpu->edi + 0x80u, cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x37B8u)) == (uint8_t)(0u)) goto label_0001EC4C;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    cpu->edi += 0x84u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37A4u))) goto label_0001E9E0;
    label_0001EC4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC4Cu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001EC4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC4Fu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x11Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041EC70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC70u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx + 0x410u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0001EC80;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0001EC80: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC80u);
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x41EC85u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EC8Bu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp)), r=(uint64_t)(0x103u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041ECA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41ECA0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37B0u)) >= (int32_t)(uint32_t)(0u)) goto label_0001ECB5;
    label_0001ECAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ECADu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0001ECB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ECB5u);
    cpu->eax = lift_load32(cpu->esi + 0x410u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001ECAD;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x41ECC5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41ECCBu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0001ECDE;
    cpu->edx = 0x191u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CheckFiles.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1ECDEu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001ECDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ECDEu);
    if ((uint32_t)(lift_load32(cpu->esp + 4u)) != (uint32_t)(0x103u)) goto label_0001ECEF;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0001ECEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ECEFu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 0x37A4u);
    cpu->ecx = lift_load32(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_0001ED05;
    lift_store32(cpu->esi + 0x37A4u, cpu->ecx);
    label_0001ED05: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ED05u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37A4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0001ED35;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x494u);
    lift_push32(cpu, cpu->edi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0001ED20: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ED20u);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u), cpu->edi);
    ++cpu->eax;
    cpu->ecx += 0x84u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37A4u))) goto label_0001ED20;
    cpu->edi = lift_pop32(cpu);
    label_0001ED35: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ED35u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041ED40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41ED40u);
    cpu->esp -= 0x120u;
    cpu->eax = lift_load32(cpu->esp + 0x124u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x130u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37B0u)) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001ED7C;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0001F02A;
    label_0001ED7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ED7Cu);
    cpu->eax = lift_load32(cpu->esi + 0x37A4u);
    lift_store32(cpu->esi + 0x37A8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edx)) goto label_0001ED94;
    lift_store32(cpu->esi + 0x37A4u, cpu->edx);
    label_0001ED94: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ED94u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37A4u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001F028;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x414u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    label_0001EDC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EDC0u);
    cpu->ebx = (uint32_t)(cpu->edi + 0x40u);
    lift_store32(cpu->esi + 0x404u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37B4u)) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0001EFFA;
    lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"xupdate"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x41EDDDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EDE3u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001EE66;
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_0001EDF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EDF0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EDF0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001EE83;
    (void)cpu;
    label_0001EE00: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE00u);
    lift_push32(cpu, 0x3Bu); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_strchr_address32(), LIFT_CODE_TOKEN_VA(0x41EE03u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE09u);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0001EE63;
    cpu->edi = cpu->ebp;
    cpu->edi -= cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41EE1Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE23u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + cpu->edi + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41EE3Cu); lift_push32(cpu, r); sfera_sub_0041E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->ebp + 1u);
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->eax;
    label_0001EE43: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE43u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EE43;
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EE52: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE52u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EE52;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EE00;
    goto label_0001EE83;
    label_0001EE63: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE63u);
    lift_push32(cpu, cpu->ebx);
    goto label_0001EE7B;
    label_0001EE66: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE66u);
    lift_push32(cpu, (uintptr_t)"sphere.exe"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->edi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41EE76u); lift_push32(cpu, r); sfera_sub_0041E6A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"sphereclient.exe");
    label_0001EE7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE7Bu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1EE83u); lift_push32(cpu, r); sfera_sub_0041E6A0(cpu,r); if (cpu->eip != r) return; }
    label_0001EE83: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EE83u);
    cpu->eax = lift_load32(cpu->esi + 0x404u);
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 0x400u, cpu->ecx);
    lift_store32(cpu->esi + 0x40Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x408u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0001EFE4;
    label_0001EEB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EEB0u);
    cpu->eax = lift_load32(cpu->esi + 0x408u);
    cpu->eax += 8u;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_0001EEC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EEC0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EEC0;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ebx = 0u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EED3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EED3;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001EF0D;
    cpu->edi = cpu->edi;
    label_0001EEE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EEE0u);
    cpu->ecx = (int8_t)(lift_load8(cpu->esp + cpu->ebx + 0x2Cu));
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::tolower), LIFT_CODE_TOKEN_VA(0x41EEE6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EEECu);
    lift_store8(cpu->esp + cpu->ebx + 0x30u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    cpu->esp += 4u;
    ++cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EF00: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EF00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EF00;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->eax)) goto label_0001EEE0;
    label_0001EF0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EF0Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0001EF14: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EF14u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0001EF14;
    cpu->eax -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001EF4B;
    cpu->eax = lift_load32(cpu->esi + 0x400u);
    cpu->edi = cpu->edi;
    label_0001EF30: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EF30u);
    cpu->ebx = (int8_t)(lift_load8(cpu->edx));
    cpu->ebx ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esi + 0x400u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EF30;
    label_0001EF4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EF4Bu);
    cpu->ebx = lift_load32(cpu->esi + 0x408u);
    cpu->eax = lift_load32(cpu->esi + 0x400u);
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->ebx + 0x108u);
    label_0001EF62: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EF62u);
    cpu->ebp = (int8_t)(lift_load8(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(cpu->esi + ((uint32_t)(cpu->ebp) * 4u));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esi + 0x400u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EF62;
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->ebx + 0x10Cu);
    label_0001EF90: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EF90u);
    cpu->ebx = (int8_t)(lift_load8(cpu->edx));
    cpu->ebx ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esi + 0x400u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001EF90;
    cpu->eax = lift_load32(cpu->esi + 0x40Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001EFBF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EFB6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EFBCu);
    cpu->esp += 4u;
    label_0001EFBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EFBFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x37B4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 0x408u);
    lift_store32(cpu->esi + 0x40Cu, cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0001EFE4;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0x408u, cpu->edx);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0001EEB0;
    label_0001EFE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EFE4u);
    cpu->eax = lift_load32(cpu->esi + 0x40Cu);
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0001EFFA;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EFF1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41EFF7u);
    cpu->esp += 4u;
    label_0001EFFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41EFFAu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esi + 0x400u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u), cpu->ecx);
    ++cpu->eax;
    cpu->edi += 0x84u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x37A4u))) goto label_0001EDC0;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001F028: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F028u);
    cpu->eax = 0u;
    label_0001F02A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F02Au);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x120u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F050u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->ecx + 0x37B0u, cpu->eax);
    lift_store32(cpu->ecx + 0x37B4u, cpu->eax);
    lift_store32(cpu->ecx + 0x410u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F06Eu); lift_push32(cpu, r); sfera_sub_0041E280(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ecx;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F080u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::Sleep);
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::GetExitCodeThread);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->edi + 0x37B4u, 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0001F0A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F0A0u);
    cpu->eax = lift_load32(cpu->edi + 0x410u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001F0C5;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x1F0B2u), LIFT_CODE_TOKEN_RVA(0x1F0B0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F0B2u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xCu)) != (uint32_t)(0x103u)) goto label_0001F0C5;
    lift_push32(cpu, 0x3E8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x1F0C3u), LIFT_CODE_TOKEN_RVA(0x1F0C1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F0C3u);
    goto label_0001F0A0;
    label_0001F0C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F0C5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F0D0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0041E9A0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x41F0E5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41F0EBu);
    lift_store32(cpu->esi + 0x410u, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0001F0FD;
    cpu->eax = 2u;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0001F0FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F0FDu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetThreadPriority), LIFT_CODE_TOKEN_VA(0x41F100u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41F106u);
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F110u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->ebp, 0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0001F1B3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->esi = cpu->edi;
    cpu->edi = cpu->edi;
    label_0001F140: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F140u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi)) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0001F156;
    ++cpu->edx;
    cpu->esi += 0x418u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_0001F140;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0001F156: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F156u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + cpu->edi)) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0001F1B0;
    lift_store32(cpu->ebp, cpu->edx);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->edx + 1u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edi)) goto label_0001F18F;
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x418u);
    cpu->esi += lift_load32(cpu->ecx);
    cpu->edi = cpu->edi;
    label_0001F180: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F180u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi)) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0001F18F;
    ++cpu->eax;
    cpu->esi += 0x418u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_0001F180;
    label_0001F18F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F18Fu);
    cpu->eax -= cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_0001F1B0;
    cpu->edx = 0x40u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1F1B0u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001F1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F1B0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001F1B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F1B3u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F1C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F1C0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax -= lift_load32(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F1D0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0041F1C0)); lift_push32(cpu, 0x418u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::qsort), LIFT_CODE_TOKEN_VA(0x41F1E1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41F1E7u);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F1F0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, 0x6Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x418u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F215u); lift_push32(cpu, r); sfera_sub_0047EA90(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    lift_x87_push(cpu, (double)1000000.0f);
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)-1000000.0f);
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edx)) goto label_0001F2A5;
    cpu->ecx = (uint32_t)(cpu->esi + 0x118u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0001F240: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F240u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001F25B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001F25B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F25Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F276;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001F276: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F276u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001F289;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001F289: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F289u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F29C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001F29C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F29Cu);
    ++cpu->edx;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0001F240;
    label_0001F2A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F2A5u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F2B0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xC8D4u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41F2BBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41F2C0u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x3Cu, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F2F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F2F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001F30E;
    lift_push32(cpu, 0xA6u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F308u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, 0u);
    label_0001F30E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F30Eu);
    cpu->ecx = lift_load32(cpu->esi + 0xC0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001F331;
    lift_push32(cpu, 0xA7u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F327u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xC0u, 0u);
    label_0001F331: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F331u);
    cpu->ecx = lift_load32(cpu->esi + 0xC4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001F354;
    lift_push32(cpu, 0xA8u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F34Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xC4u, 0u);
    label_0001F354: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F354u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F360u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape\\contours.bin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F371u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->ebx + 4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F37Fu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0xB2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F397u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebx, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F3ACu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_0042F180(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F3C0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0001F3DD;
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_0001F3DD;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x2710u)) goto label_0001F3EC;
    label_0001F3DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F3DDu);
    cpu->edx = 0xC5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1F3ECu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001F3EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F3ECu);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, 0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F400u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->ecx + 0x24u, cpu->edx);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F420u);
    lift_x87_push(cpu, 0.0);
    cpu->esp -= 0x30u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_push32(cpu, cpu->ebx);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001F447;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 200.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001F45C;
    label_0001F447: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F447u);
    cpu->edx = 0x28Au;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F458u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    label_0001F45C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F45Cu);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    cpu->ebp = 0u;
    cpu->eax = 0u;
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001F489;
    cpu->edi = lift_load32(cpu->ebx + 0x38u);
    cpu->ecx = lift_load32(cpu->ebx);
    label_0001F472: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F472u);
    cpu->esi = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edi)) goto label_0001F480;
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x3Cu))) goto label_0001F480;
    cpu->eax += lift_load32(cpu->ecx + 4u);
    label_0001F480: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F480u);
    cpu->ecx += 0x418u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001F472;
    label_0001F489: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F489u);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, 0x296u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F4A9u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x297u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F4BCu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x298u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F4D1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41F4D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41F4DDu);
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001F57C;
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi = 0u;
    label_0001F4F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F4F1u);
    cpu->ecx = lift_load32(cpu->edi + cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x38u))) goto label_0001F564;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x3Cu))) goto label_0001F564;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 0x29Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = (uint32_t)(cpu->edi + cpu->eax + 0x18u);
    cpu->eax = lift_load32(cpu->edi + cpu->eax + 4u);
    lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ebp) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F529u); lift_push32(cpu, r); sfera_sub_0047EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, 0x29Fu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = (uint32_t)(cpu->eax + 0x118u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F55Eu); lift_push32(cpu, r); sfera_sub_0047EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ebp += lift_load32(cpu->edi + cpu->eax + 4u);
    label_0001F564: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F564u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->edi += 0x418u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u))) goto label_0001F4F1;
    label_0001F57C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F57Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->esp + 0x30u, 0u);
    lift_x87_push(cpu, 0.0);
    label_0001F58A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F58Au);
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->ebp)) == (uint32_t)(cpu->edi)) goto label_0001F59D;
    label_0001F595: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F595u);
    ++cpu->edi;
    if ((uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_0001F595;
    label_0001F59D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F59Du);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->edx)) goto label_0001F5C4;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = 0x2AAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F5B8u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0001F5C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F5C4u);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edi) * 4u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0001F688;
    cpu->edx = cpu->ebp;
    cpu->edx -= cpu->esi;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    cpu->edx -= cpu->esi;
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx -= cpu->eax;
    label_0001F610: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F610u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(lift_load32(cpu->eax + cpu->ecx)) != (uint32_t)(0u)) goto label_0001F67E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edi) * 4u)));
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->edi) * 4u)));
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F67E;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    lift_store32(cpu->eax + cpu->ecx, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001F67E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F67Eu);
    cpu->ecx += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001F610;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    label_0001F688: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F688u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x14u))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0001F6E3;
    cpu->edi = lift_load32(cpu->esp + 0x44u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->ebp;
    cpu->eax = cpu->ebp;
    cpu->edi -= cpu->ebp;
    cpu->ebp = cpu->edx;
    label_0001F6C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F6C4u);
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(1u)) goto label_0001F6D9;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax, 2u);
    lift_store_f32(cpu->ecx + cpu->eax, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edi + cpu->eax, lift_x87_get(cpu, 0u));
    label_0001F6D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F6D9u);
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001F6C4;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001F6E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F6E3u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0001F58A;
    cpu->ebp = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = 0u;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001F7A6;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0001F710: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F710u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->eax + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x38u))) goto label_0001F78E;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x3Cu))) goto label_0001F78E;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 0x2C8u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp + 0x18u);
    cpu->eax = lift_load32(cpu->eax + cpu->ebp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x100u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edi) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F74Au); lift_push32(cpu, r); sfera_sub_0047EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, 0x2C9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp + 0x118u);
    cpu->eax = lift_load32(cpu->eax + cpu->ebp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x100u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F77Eu); lift_push32(cpu, r); sfera_sub_0047EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi += lift_load32(cpu->eax + cpu->ebp + 4u);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1F78Eu); lift_push32(cpu, r); sfera_sub_0041F1F0(cpu,r); if (cpu->eip != r) return; }
    label_0001F78E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F78Eu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->ebp += 0x418u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u))) goto label_0001F710;
    label_0001F7A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F7A6u);
    lift_push32(cpu, 0x2CEu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F7B7u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, 0x2CFu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F7CAu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_store32(cpu->esp + 4u, 0x2D0u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    sfera_sub_004EB520(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F7F0u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->edx = lift_load32(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0001F818;
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    goto label_0001F820;
    label_0001F818: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F818u);
    lift_store32(cpu->esp + 0x18u, 0u);
    label_0001F820: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F820u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->ebx = lift_load32(cpu->eax + cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    --cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0001F842;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    goto label_0001F84A;
    label_0001F842: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F842u);
    lift_store32(cpu->esp + 0x14u, 0u);
    label_0001F84A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F84Au);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x106u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x106u);
    cpu->edi += cpu->esi;
    cpu->ebx = (uint32_t)(cpu->edx + cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F8BE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0x118u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u) + 0x118u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F8BE;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ebp = (uint32_t)(cpu->esi + cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u) + 0x18u));
    cpu->eax += cpu->edx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F8BE;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u) + 0x118u));
    cpu->eax += cpu->edx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x118u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001F916;
    label_0001F8BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F8BEu);
    cpu->edx += lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F922;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0x118u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0x118u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F922;
    cpu->esi += lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F922;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u) + 0x118u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u) + 0x118u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001F922;
    label_0001F916: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F916u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0001F922: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F922u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041F930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41F930u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edi)) goto label_0001F94E;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(cpu->edi)) goto label_0001F94E;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edi)) goto label_0001F95D;
    label_0001F94E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F94Eu);
    cpu->edx = 0x35Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1F95Du); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001F95D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F95Du);
    cpu->ecx = lift_load32(cpu->esi + 0xC0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0001F97C;
    lift_push32(cpu, 0x35Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F976u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xC0u, cpu->edi);
    label_0001F97C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F97Cu);
    cpu->ecx = lift_load32(cpu->esi + 0xC4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0001F99B;
    lift_push32(cpu, 0x35Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F995u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xC4u, cpu->edi);
    label_0001F99B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41F99Bu);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebx) * 4u));
    lift_push32(cpu, 0x360u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F9B3u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x361u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esi + 0xC0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41F9CAu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0xC4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xC0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41F9D9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41F9DEu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esi + 0xC4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41F9EBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41F9F0u);
    cpu->esp += 0x18u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0xC8u, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041FA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41FA00u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0xC8u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0001FA2C;
    cpu->edx = lift_load32(cpu->esi + 0xC0u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0001FA20: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FA20u);
    if ((uint32_t)(lift_load32(cpu->edx)) == (uint32_t)(cpu->edi)) goto label_0001FA9A;
    ++cpu->eax;
    cpu->edx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0001FA20;
    label_0001FA2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FA2Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"===serverByType ====\ntypeN=";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FA36u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FA3Du); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0xC8u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0001FA7A;
    label_0001FA50: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FA50u);
    cpu->edx = lift_load32(cpu->esi + 0xC0u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FA5Eu); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xC4u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FA6Cu); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FA71u); lift_push32(cpu, r); sfera_sub_00451DC0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xC8u))) goto label_0001FA50;
    label_0001FA7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FA7Au);
    cpu->ecx = (uint32_t)(uintptr_t)"=======\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FA84u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x387u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FA93u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0001FA9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FA9Au);
    cpu->ecx = lift_load32(cpu->esi + 0xC4u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041FAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41FAB0u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x6400u);
    cpu->eax = (uint32_t)(cpu->edi + 0x64D0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41FACBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41FAD0u);
    cpu->ecx = 0xFFFFFFFEu;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->edi + 0xCCu);
    lift_store32(cpu->esp + 0x1Cu, 0xA0u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0001FAF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FAF0u);
    cpu->ebp = 0xFFFFFFFEu;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0xA0u);
    label_0001FB01: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB01u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x28u)) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)((cpu->edx & 0xFFu))) goto label_0001FB7F;
    cpu->eax = 0u;
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebx = (uint32_t)(cpu->ecx + 4u);
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->edi = (uint32_t)(cpu->edx + cpu->edi + 0x64D0u);
    label_0001FB30: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB30u);
    cpu->eax = 0x9Fu;
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(0x9Fu)) goto label_0001FB3F;
    cpu->eax = cpu->ebx;
    label_0001FB3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB3Fu);
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->eax)) goto label_0001FB77;
    cpu->eax = 0u;
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = (uint32_t)(cpu->ebp + 4u);
    --cpu->eax;
    cpu->eax &= cpu->ebp;
    label_0001FB50: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB50u);
    cpu->ecx = 0x9Fu;
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(0x9Fu)) goto label_0001FB5F;
    cpu->ecx = cpu->edx;
    label_0001FB5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB5Fu);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->ecx)) goto label_0001FB6A;
    lift_store8(cpu->edi + cpu->eax, 1u);
    ++cpu->eax;
    goto label_0001FB50;
    label_0001FB6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB6Au);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    ++cpu->esi;
    cpu->edi += 0xA0u;
    goto label_0001FB30;
    label_0001FB77: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB77u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_0001FB7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FB7Fu);
    ++cpu->eax;
    ++cpu->ebp;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001FB01;
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x1Cu, v); }
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001FAF0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041FBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41FBB0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041FBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41FBC0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_0001FBD1;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0001FBE0;
    label_0001FBD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FBD1u);
    cpu->edx = 0x3FFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1FBE0u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001FBE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FBE0u);
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->eax += lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041FBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41FBF0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0x54u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x418u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41FC15u); lift_push32(cpu, r); sfera_sub_0047EA90(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0001FFD0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FFD0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0001FFCE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FFCE;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 4u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(4u)) goto label_0001FF0E;
    label_0001FC72: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FC72u);
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0001FC7E;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    label_0001FC7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FC7Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FD14;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001FCA8;
    cpu->edx = cpu->ecx;
    cpu->ecx = cpu->ebx;
    label_0001FCA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FCA8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0001FD14;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FD14;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x118u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x118u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001FD14;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    label_0001FD14: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FD14u);
    cpu->edi = (uint32_t)(cpu->ebx + 1u);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->ebx;
    if ((uint32_t)(cpu->edi) != 0u) goto label_0001FD22;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    label_0001FD22: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FD22u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FDBA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001FD4E;
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->edx = cpu->eax;
    label_0001FD4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FD4Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0001FDBA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FDBA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x118u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001FDBA;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    label_0001FDBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FDBAu);
    cpu->edx = (uint32_t)(cpu->ebx + 2u);
    cpu->ecx = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_0001FDC6;
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    label_0001FDC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FDC6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FE5E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001FDF2;
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edi;
    cpu->edi = cpu->eax;
    label_0001FDF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FDF2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0001FE5E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FE5E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x118u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001FE5E;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    label_0001FE5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FE5Eu);
    cpu->ecx = (uint32_t)(cpu->ebx + 3u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0001FE68;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    label_0001FE68: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FE68u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FF00;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001FE94;
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->edx = cpu->eax;
    label_0001FE94: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FE94u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0001FF00;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FF00;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x118u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001FF00;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    label_0001FF00: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FF00u);
    cpu->ebx += 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFDu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->eax)) goto label_0001FC72;
    label_0001FF0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FF0Eu);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001FFBE;
    label_0001FF1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FF1Au);
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0001FF26;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    label_0001FF26: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FF26u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FFB5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001FF4C;
    cpu->edx = cpu->ecx;
    cpu->ecx = cpu->ebx;
    label_0001FF4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FF4Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0001FFB5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001FFB5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x118u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x118u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001FFB5;
    ++cpu->edi;
    label_0001FFB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FFB5u);
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0001FF1A;
    label_0001FFBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FFBEu);
    cpu->eax = cpu->edi;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax &= 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0001FFCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FFCEu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001FFD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41FFD0u);
    cpu->eax = 0u;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041FFE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41FFE0u);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0xCu)))));
    cpu->ebp = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0002001A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2001Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0002001A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42001Au);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0002002E;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2002Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0002002E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42002Eu);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x34u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42003Eu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00020053;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20053u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00020053: cpu->eip = LIFT_CODE_TOKEN_VA(0x420053u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00020067;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20067u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00020067: cpu->eip = LIFT_CODE_TOKEN_VA(0x420067u);
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x38u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420078u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edi = cpu->ebp;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    cpu->edi += lift_load32(cpu->esi);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420095u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ecx = (uint32_t)(cpu->edi + 4u);
    lift_x87_push(cpu, 4000.0);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00020184;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    cpu->ebp = (uint32_t)(cpu->esi + 0x40u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    goto label_000200EA;
    label_000200D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4200D0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, 4000.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_000200EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4200EAu);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000200F4;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    label_000200F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4200F4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00020107;
    cpu->eax = 0xFF78C8AAu;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(cpu->ecx)) goto label_0002010B;
    label_00020107: cpu->eip = LIFT_CODE_TOKEN_VA(0x420107u);
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    label_0002010B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42010Bu);
    lift_store32(cpu->esi + 0x50u, cpu->eax);
    lift_store32(cpu->esi + 0x70u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_push32(cpu, 2u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x118u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 3u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u) + 0x118u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420161u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000200D0;
    lift_x87_push(cpu, 4000.0);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00020184: cpu->eip = LIFT_CODE_TOKEN_VA(0x420184u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0002028A;
    lift_x87_push(cpu, 2.0);
    cpu->ebp = (uint32_t)(cpu->edi + 0x118u);
    label_0002019E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42019Eu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000201B0;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_00020274;
    label_000201B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4201B0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFF00u));
    cpu->ebx = (uint32_t)(cpu->esi + 0x40u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_push32(cpu, 2u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x44u))))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42022Du); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_push32(cpu, cpu->ebx);
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, 2u);
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42025Au); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 2.0);
    lift_x87_push(cpu, 4000.0);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_00020274: cpu->eip = LIFT_CODE_TOKEN_VA(0x420274u);
    ++cpu->eax;
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ecx))) goto label_0002019E;
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002028A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42028Au);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000203F9;
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x18u));
    cpu->ecx = 0x2710u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x34u))))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x118u))));
    cpu->eax = lift_load32(cpu->esi + 0xC8D0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu))))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.10000000149011612));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4202E0u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (100.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (50.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4202FFu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ebx = (uint32_t)(cpu->esi + 0x40u);
    lift_x87_push(cpu, 7.0);
    cpu->ecx = cpu->eax;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    cpu->eax |= 0xFFFFFF00u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, 0x20u);
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax |= cpu->ecx;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    lift_store32(cpu->esi + 0x70u, cpu->eax);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x50u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_push32(cpu, 2u);
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42036Eu); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (7.0));
    lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4203A5u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x20u);
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4203CEu); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_push32(cpu, cpu->ebx);
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4203F7u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    goto label_000203FD;
    label_000203F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4203F9u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000203FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4203FDu);
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x38]) == (uint8_t)(0u)) goto label_00020413;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"%d");
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    goto label_00020420;
    label_00020413: cpu->eip = LIFT_CODE_TOKEN_VA(0x420413u);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d");
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    label_00020420: cpu->eip = LIFT_CODE_TOKEN_VA(0x420420u);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x420420u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x420426u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_x87_push(cpu, 4000.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 30.0);
    LIFT_X87_POP_STATUS_AX();
    lift_x87_push(cpu, 0.0);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00020576;
    cpu->ebx = lift_load32(cpu->esp + 0x30u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000204FC;
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFCu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    ++cpu->ecx;
    cpu->eax = (uint32_t)(cpu->edi + 0x1Cu);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx) * 4u));
    label_00020492: cpu->eip = LIFT_CODE_TOKEN_VA(0x420492u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    cpu->eax += 0x10u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF0u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF4u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF8u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xF0u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xF4u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xF8u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00020492;
    label_000204FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4204FCu);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_00020528;
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->esi) * 4u) + 0x118u);
    cpu->edx -= cpu->esi;
    label_00020509: cpu->eip = LIFT_CODE_TOKEN_VA(0x420509u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFF00u));
    cpu->edi += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xFFFFFFFCu))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00020509;
    label_00020528: cpu->eip = LIFT_CODE_TOKEN_VA(0x420528u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx)))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 5u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420551u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFFFFF6u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420571u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax -= 0xFu;
    goto label_000205A5;
    label_00020576: cpu->eip = LIFT_CODE_TOKEN_VA(0x420576u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42058Fu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFFFFF6u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4205A2u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax -= 0x17u;
    label_000205A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4205A5u);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4205C0u); lift_push32(cpu, r); sfera_sub_0044D190(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004205E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4205E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0xFFFFFFFFu)) goto label_00020716;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->ebx);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ebx);
    lift_store_f32(cpu->esi + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 0x54u, cpu->ebx);
    lift_store_f32(cpu->esi + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x74u, cpu->ebx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u));
    cpu->eax = 0x96000000u;
    lift_store_f32(cpu->esi + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x50u, cpu->eax);
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x70u, cpu->eax);
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u));
    cpu->edi = (uint32_t)(cpu->esi + 0x40u);
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ebx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_push32(cpu, cpu->ebx);
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_store_f32(cpu->esi + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_store_f32(cpu->esi + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42068Fu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42069Eu); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4206B0u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4206BBu); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000206FC;
    label_000206C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4206C2u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ebx + cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_000206D8;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1Cu))) goto label_000206D8;
    cpu->eax = 0xFFFF3232u;
    goto label_000206E7;
    label_000206D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4206D8u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x20u))) goto label_000206F0;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x24u))) goto label_000206F0;
    cpu->eax = 0xFF000064u;
    label_000206E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4206E7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x206F0u); lift_push32(cpu, r); sfera_sub_0041FFE0(cpu,r); if (cpu->eip != r) return; }
    label_000206F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4206F0u);
    ++cpu->edi;
    cpu->ebx += 0x418u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000206C2;
    label_000206FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4206FCu);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00020710;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20710u); lift_push32(cpu, r); sfera_sub_0041FFE0(cpu,r); if (cpu->eip != r) return; }
    label_00020710: cpu->eip = LIFT_CODE_TOKEN_VA(0x420710u);
    lift_store32(cpu->esi + 0xC8D0u, (uint64_t)(lift_load32(cpu->esi + 0xC8D0u)) + 1u);
    label_00020716: cpu->eip = LIFT_CODE_TOKEN_VA(0x420716u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00420720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x420720u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) != (uint32_t)(cpu->eax)) goto label_00020739;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) != (uint32_t)(cpu->edx)) goto label_00020739;
    cpu->ecx = 0u;
    goto label_0002073E;
    label_00020739: cpu->eip = LIFT_CODE_TOKEN_VA(0x420739u);
    cpu->ecx = 1u;
    label_0002073E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42073Eu);
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00020759;
    cpu->ecx = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20759u); lift_push32(cpu, r); sfera_sub_0041F110(cpu,r); if (cpu->eip != r) return; }
    label_00020759: cpu->eip = LIFT_CODE_TOKEN_VA(0x420759u);
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00020767;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00020767: cpu->eip = LIFT_CODE_TOKEN_VA(0x420767u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00020780;
    cpu->edx = 0x1B8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20780u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00020780: cpu->eip = LIFT_CODE_TOKEN_VA(0x420780u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000207AA;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->edx = lift_load32(cpu->eax + cpu->ecx + 0xFFFFFBE8u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x28u))) goto label_000207AA;
    cpu->edx = 0x1B9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x207AAu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_000207AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4207AAu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    --cpu->edx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000207DC;
    cpu->ecx = lift_load32(cpu->esi);
    ++cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->edx = lift_load32(cpu->eax + cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x2Cu))) goto label_000207DC;
    cpu->edx = 0x1BBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x207DCu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_000207DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4207DCu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->eax + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->eax)) goto label_00020840;
    cpu->ebx = cpu->edi;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x418u);
    label_000207F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4207F4u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ebx + cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x28u))) goto label_00020803;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x2Cu))) goto label_00020812;
    label_00020803: cpu->eip = LIFT_CODE_TOKEN_VA(0x420803u);
    cpu->edx = 0x1BFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20812u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00020812: cpu->eip = LIFT_CODE_TOKEN_VA(0x420812u);
    cpu->eax = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420830u); lift_push32(cpu, r); sfera_sub_0041FBF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00020849;
    --cpu->edi;
    cpu->ebx -= 0x418u;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x30u))) goto label_000207F4;
    label_00020840: cpu->eip = LIFT_CODE_TOKEN_VA(0x420840u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00020849: cpu->eip = LIFT_CODE_TOKEN_VA(0x420849u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    cpu->eax = lift_load32(cpu->edi + cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00420860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x420860u);
    cpu->esp -= 0x5Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0x270Fu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x4E1Eu)) goto label_00020899;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(0xFFFFD8F0u)) goto label_00020899;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x2710u)) goto label_000208A8;
    label_00020899: cpu->eip = LIFT_CODE_TOKEN_VA(0x420899u);
    cpu->edx = 0x1CCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x208A8u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_000208A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4208A8u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000208BC;
    cpu->edi = cpu->eax;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    cpu->edi += lift_load32(cpu->esi);
    label_000208BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4208BCu);
    cpu->edx = lift_load32(cpu->esp + 0x70u);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xAu)) goto label_00020ECD;
    switch ((uint32_t)(cpu->ecx)) {
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
    lift_store32(cpu->esi + 8u, cpu->ebp);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x14u, 0u);
    goto label_00020EDB;
    label_000208EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4208ECu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00020980;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    (void)cpu;
    label_00020900: cpu->eip = LIFT_CODE_TOKEN_VA(0x420900u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + cpu->edx + 4u)) >= (int32_t)(uint32_t)(3u)) goto label_0002096A;
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->ebx -= lift_load32(cpu->esp + 0x10u);
    --cpu->ebx;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x418u);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00020930;
    cpu->edx = 0x1E3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42092Eu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    label_00020930: cpu->eip = LIFT_CODE_TOKEN_VA(0x420930u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0002095B;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0x1E5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->ecx + 0x418u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2095Bu); lift_push32(cpu, r); sfera_sub_0047EAC0(cpu,r); if (cpu->eip != r) return; }
    label_0002095B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42095Bu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) - 1u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) - (uint64_t)(0x418u) - (uint64_t)(0u));
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - 1u);
    label_0002096A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42096Au);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x418u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00020900;
    label_00020980: cpu->eip = LIFT_CODE_TOKEN_VA(0x420980u);
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420997u); lift_push32(cpu, r); sfera_sub_0041F110(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x1EAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4209B1u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"landscape\\contours.bin";
    lift_store32(cpu->esi, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4209BDu); lift_push32(cpu, r); sfera_sub_0042EE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esi + 4u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4209CBu); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4209DEu); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4209E5u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, 0xFFFFFFFFu);
    goto label_00020EDB;
    label_000209F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4209F1u);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    goto label_00020EDB;
    label_000209F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4209F9u);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    lift_store32(cpu->esi + 0x10u, 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00020EDB;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    label_00020A11: cpu->eip = LIFT_CODE_TOKEN_VA(0x420A11u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00020A58;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1Cu))) goto label_00020A58;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x78u)))));
    lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x80u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420A40u); lift_push32(cpu, r); sfera_sub_0041FBF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00020A58;
    lift_store32(cpu->esp + ((uint32_t)(cpu->ebx) * 4u) + 0x18u, cpu->ebp);
    ++cpu->ebx;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x14u)) goto label_00020A58;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 87236589";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20A58u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00020A58: cpu->eip = LIFT_CODE_TOKEN_VA(0x420A58u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x418u) + (uint64_t)(0u));
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00020A11;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00020EDB;
    cpu->ecx = g_sfera_contours_runtime.round_robin_counter;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ebx, 32u, 1u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 0x14u, 0u);
    g_sfera_contours_runtime.round_robin_counter = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + ((uint32_t)(cpu->edx) * 4u) + 0x18u);
    cpu->eax = cpu->edx;
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00020A9D;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00020EDB;
    label_00020A9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x420A9Du);
    cpu->edx = 0x200u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420AACu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    goto label_00020EDB;
    label_00020AB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x420AB1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00020EDB;
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00020ACC;
    lift_store32(cpu->esi + 0x14u, 0u);
    label_00020ACC: cpu->eip = LIFT_CODE_TOKEN_VA(0x420ACCu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00020ADC;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00020EDB;
    label_00020ADC: cpu->eip = LIFT_CODE_TOKEN_VA(0x420ADCu);
    cpu->edx = 0x208u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420AEBu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    goto label_00020EDB;
    label_00020AF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x420AF0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00020EDB;
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) != (uint32_t)(cpu->eax)) goto label_00020B0B;
    cpu->eax = lift_load32(cpu->edi + 4u);
    --cpu->eax;
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    label_00020B0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x420B0Bu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00020B1B;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00020EDB;
    label_00020B1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x420B1Bu);
    cpu->edx = 0x210u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420B2Au); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    goto label_00020EDB;
    label_00020B2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x420B2Fu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00020EDB;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0x3Fu)) goto label_00020EDB;
    cpu->eax -= lift_load32(cpu->esi + 0x14u);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + 0xFFFFFFFCu);
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00020B63;
    cpu->edx = 0x217u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420B61u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    label_00020B63: cpu->eip = LIFT_CODE_TOKEN_VA(0x420B63u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00020BBB;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, 0x21Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420B8Du); lift_push32(cpu, r); sfera_sub_0047EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, 0x21Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x11Cu);
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x120u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20BBBu); lift_push32(cpu, r); sfera_sub_0047EAC0(cpu,r); if (cpu->eip != r) return; }
    label_00020BBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x420BBBu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x74u)))));
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x7Cu)))));
    cpu->eax = 1u;
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u) + 0x11Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420BE7u); lift_push32(cpu, r); sfera_sub_0041F1F0(cpu,r); if (cpu->eip != r) return; }
    goto label_00020EDB;
    label_00020BEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x420BECu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00020EDB;
    cpu->ebp = lift_load32(cpu->edi + 4u);
    cpu->ebp -= lift_load32(cpu->esi + 0x14u);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->ebp) * 4u) + 0xFFFFFFFCu);
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00020C17;
    cpu->edx = 0x228u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420C15u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    label_00020C17: cpu->eip = LIFT_CODE_TOKEN_VA(0x420C17u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00020C6F;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, 0x22Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420C41u); lift_push32(cpu, r); sfera_sub_0047EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, 0x22Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x11Cu);
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x118u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20C6Fu); lift_push32(cpu, r); sfera_sub_0047EAC0(cpu,r); if (cpu->eip != r) return; }
    label_00020C6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x420C6Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 4u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->edi + 4u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00020C91;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420C7Cu); lift_push32(cpu, r); sfera_sub_0041F1F0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x14u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00020EDB;
    cpu->edx = lift_load32(cpu->edi + 4u);
    --cpu->edx;
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    goto label_00020EDB;
    label_00020C91: cpu->eip = LIFT_CODE_TOKEN_VA(0x420C91u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->edi -= lift_load32(cpu->esi + 0x10u);
    --cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00020CB3;
    cpu->edx = 0x237u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420CB1u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    label_00020CB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x420CB3u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00020CE3;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x239u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp"); lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ecx + 0x418u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20CE3u); lift_push32(cpu, r); sfera_sub_0047EAC0(cpu,r); if (cpu->eip != r) return; }
    label_00020CE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x420CE3u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x23Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx -= 0x418u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420D03u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420D25u); lift_push32(cpu, r); sfera_sub_0041F110(cpu,r); if (cpu->eip != r) return; }
    goto label_00020F15;
    label_00020D2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x420D2Au);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00020EDB;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x74u)))));
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u) + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x7Cu)))));
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + 0x118u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420D54u); lift_push32(cpu, r); sfera_sub_0041F1F0(cpu,r); if (cpu->eip != r) return; }
    goto label_00020EDB;
    label_00020D59: cpu->eip = LIFT_CODE_TOKEN_VA(0x420D59u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00020EDB;
    cpu->ebx = lift_load32(cpu->edi + 4u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->edi, cpu->ebp);
    lift_store32(cpu->edi + 4u, 0x3E7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420D75u); lift_push32(cpu, r); sfera_sub_0041F1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420D8Cu); lift_push32(cpu, r); sfera_sub_0041F110(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00020DAB;
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax += 4u;
    label_00020D98: cpu->eip = LIFT_CODE_TOKEN_VA(0x420D98u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0x3E7u)) goto label_00020DB5;
    ++cpu->ebp;
    cpu->eax += 0x418u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00020D98;
    label_00020DAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x420DABu);
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 672474878765683";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20DB5u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00020DB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x420DB5u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = cpu->ebp;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_store32(cpu->ecx + cpu->edx + 4u, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->ebp);
    goto label_00020EDB;
    label_00020DCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x420DCBu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    ++cpu->edx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x25Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420DE6u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = cpu->ecx;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    lift_push32(cpu, 0x418u);
    cpu->edi += cpu->eax;
    ++cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x420E01u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x420E06u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x80u)))));
    lift_store32(cpu->edi, cpu->eax);
    cpu->esp += 0xCu;
    cpu->eax = (uint32_t)(cpu->edi + 0x318u);
    lift_store_f32(cpu->edi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0x40u;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x78u)))));
    lift_store_f32(cpu->edi + 0x118u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00020E30: cpu->eip = LIFT_CODE_TOKEN_VA(0x420E30u);
    lift_store32(cpu->eax + 0xFFFFFF00u, 0xFFFFFFFFu);
    lift_store32(cpu->eax, 0xFFFFFFFFu);
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00020E30;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420E4Eu); lift_push32(cpu, r); sfera_sub_0041F1F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0041F1C0));
    lift_store32(cpu->edi + 4u, 0x3E7u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, 0x418u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::qsort), LIFT_CODE_TOKEN_VA(0x420E66u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x420E6Cu);
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->esp += 0x10u;
    cpu->eax = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420E86u); lift_push32(cpu, r); sfera_sub_0041F110(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00020EA5;
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax += 4u;
    label_00020E92: cpu->eip = LIFT_CODE_TOKEN_VA(0x420E92u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0x3E7u)) goto label_00020EAF;
    ++cpu->ebp;
    cpu->eax += 0x418u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00020E92;
    label_00020EA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x420EA5u);
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 68247987378235";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20EAFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00020EAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x420EAFu);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = cpu->ebp;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x418u);
    lift_store32(cpu->ecx + cpu->edx + 4u, 1u);
    lift_store32(cpu->esi + 0x10u, cpu->ebp);
    lift_store32(cpu->esi + 0x14u, 0u);
    goto label_00020EDB;
    label_00020ECD: cpu->eip = LIFT_CODE_TOKEN_VA(0x420ECDu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"process_contour_event: wrong type %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x420ED8u); lift_push32(cpu, r); sfera_sub_0047E960(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00020EDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x420EDBu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00020F15;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00020EEB;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x40u)) goto label_00020EFA;
    label_00020EEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x420EEBu);
    cpu->edx = 0x277u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20EFAu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00020EFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x420EFAu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00020F06;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00020F15;
    label_00020F06: cpu->eip = LIFT_CODE_TOKEN_VA(0x420F06u);
    cpu->edx = 0x278u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20F15u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00020F15: cpu->eip = LIFT_CODE_TOKEN_VA(0x420F15u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 0x38u))) goto label_00020F36;
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 0x3Cu))) goto label_00020F36;
    lift_x87_push(cpu, (double)100.0f);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x20F36u); lift_push32(cpu, r); sfera_sub_0041F420(cpu,r); if (cpu->eip != r) return; }
    label_00020F36: cpu->eip = LIFT_CODE_TOKEN_VA(0x420F36u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0xC8D0u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00420F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x420F90u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->edx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u)) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000210C4;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    cpu->edi = cpu->edi;
    label_00020FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x420FB0u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x38u))) goto label_000210A9;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x3Cu))) goto label_000210A9;
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + cpu->eax + 4u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000210A9;
    cpu->ecx = (uint32_t)(cpu->esi + 0x318u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00020FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x420FE0u);
    lift_store32(cpu->ecx + cpu->eax + 0xFFFFFF00u, 0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi = 0u;
    lift_store32(cpu->ecx + cpu->eax, 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0002108D;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_00021005: cpu->eip = LIFT_CODE_TOKEN_VA(0x421005u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x38u))) goto label_00021048;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x3Cu))) goto label_00021048;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00021048;
    cpu->edi = cpu->edi;
    label_00021020: cpu->eip = LIFT_CODE_TOKEN_VA(0x421020u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->edi)) goto label_00021028;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->esi)) goto label_0002103F;
    label_00021028: cpu->eip = LIFT_CODE_TOKEN_VA(0x421028u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421033u); lift_push32(cpu, r); sfera_sub_0041F7F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002105A;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_0002103F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42103Fu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_00021020;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    label_00021048: cpu->eip = LIFT_CODE_TOKEN_VA(0x421048u);
    ++cpu->edi;
    cpu->ecx += 0x418u;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u))) goto label_00021005;
    goto label_0002108D;
    label_0002105A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42105Au);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + cpu->ecx + 0xFFFFFF00u, cpu->edi);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x106u);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax + cpu->ecx, cpu->esi);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->edi + cpu->esi);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0x218u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0x318u, cpu->ebp);
    cpu->edx = cpu->ecx;
    label_0002108D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42108Du);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->ebp;
    cpu->ecx += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + cpu->eax + 4u))) goto label_00020FE0;
    label_000210A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4210A9u);
    ++cpu->edx;
    cpu->esi += 0x418u;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 4u))) goto label_00020FB0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000210C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4210C4u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004210D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4210D0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0xC0u)) == (uint32_t)(cpu->edi)) goto label_000210EB;
    if ((uint32_t)(lift_load32(cpu->esi + 0xC4u)) != (uint32_t)(cpu->edi)) goto label_000210FA;
    label_000210EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4210EBu);
    cpu->edx = 0x30Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x210FAu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_000210FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4210FAu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421101u); lift_push32(cpu, r); sfera_sub_00420F90(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00021241;
    cpu->ebx = 0u;
    cpu->ebp = 0x218u;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    label_00021125: cpu->eip = LIFT_CODE_TOKEN_VA(0x421125u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->ebx + cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x38u))) goto label_00021207;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x3Cu))) goto label_00021207;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + cpu->eax + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00021207;
    label_00021150: cpu->eip = LIFT_CODE_TOKEN_VA(0x421150u);
    cpu->eax = lift_load32(cpu->eax + cpu->ebp);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000211F1;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, 0x314u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421170u); lift_push32(cpu, r); sfera_sub_0047EA60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421183u); lift_push32(cpu, r); sfera_sub_0041FA00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ebx + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421194u); lift_push32(cpu, r); sfera_sub_0041FA00(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x2Cu))) goto label_000211F1;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax + cpu->ebp);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x106u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + 1u);
    cpu->ebx += cpu->edi;
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->ebx) * 4u) + 0x318u);
    cpu->edx += lift_load32(cpu->ebx + cpu->eax);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x218u)) == (uint32_t)(cpu->ecx)) goto label_000211D0;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong connection of server contours (case1)";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x211D0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000211D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4211D0u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax + cpu->ebp);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x106u);
    cpu->edx += lift_load32(cpu->ebx + cpu->eax);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x318u)) == (uint32_t)(cpu->edi)) goto label_000211F1;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong connection of server contours (case2)";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x211F1u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000211F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4211F1u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    ++cpu->edi;
    cpu->ebp += 4u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + cpu->eax + 4u))) goto label_00021150;
    cpu->edi = 0u;
    label_00021207: cpu->eip = LIFT_CODE_TOKEN_VA(0x421207u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x106u) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->ebp += 0x418u;
    cpu->ebx += 0x418u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00021125;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edi)) goto label_00021251;
    label_00021241: cpu->eip = LIFT_CODE_TOKEN_VA(0x421241u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    sfera_sub_0048B960(cpu, stop_address); return;
    label_00021251: cpu->eip = LIFT_CODE_TOKEN_VA(0x421251u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00021264;
    cpu->edx = 0x335u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x21264u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00021264: cpu->eip = LIFT_CODE_TOKEN_VA(0x421264u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebx = cpu->eax;
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, 0x338u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421287u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0002147B;
    cpu->edx = 0u;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_store32(cpu->esp + 0x28u, 0x218u);
    cpu->edi = cpu->edi;
    label_000212B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4212B0u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edx + cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x38u))) goto label_00021445;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x3Cu))) goto label_00021445;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edx + cpu->eax + 4u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00021445;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_000212E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4212E0u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0002142F;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, 0x33Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421304u); lift_push32(cpu, r); sfera_sub_0047EA60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x418u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421317u); lift_push32(cpu, r); sfera_sub_0041FA00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42132Au); lift_push32(cpu, r); sfera_sub_0041FA00(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0002142B;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->ecx + cpu->eax + 4u);
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0002134A;
    cpu->eax = (uint32_t)(cpu->ebx + 1u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    goto label_00021352;
    label_0002134A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42134Au);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    label_00021352: cpu->eip = LIFT_CODE_TOKEN_VA(0x421352u);
    lift_push32(cpu, 0x343u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = 0x40u;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421368u); lift_push32(cpu, r); sfera_sub_0047EA60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x344u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = 0x40u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421380u); lift_push32(cpu, r); sfera_sub_0047EA60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->ebp + 6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u)));
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->ebp + 0x46u);
    lift_store_f32(cpu->eax + ((uint32_t)(cpu->edi) * 4u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u)));
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebp + 6u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u)));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->ebp + 0x46u);
    cpu->edx = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u)));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->ecx + cpu->eax);
    lift_push32(cpu, 0x34Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edi += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4213E1u); lift_push32(cpu, r); sfera_sub_0047EA60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebx + cpu->ebp);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + 0x318u);
    cpu->ecx = lift_load32(cpu->eax + cpu->ecx);
    lift_push32(cpu, 0x34Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp");
    cpu->edx = 0x40u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421408u); lift_push32(cpu, r); sfera_sub_0047EA60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->edx + cpu->eax);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x106u);
    cpu->ecx += lift_load32(cpu->edx + cpu->eax);
    lift_store32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 0x218u, 0xFFFFFFFFu);
    goto label_0002142F;
    label_0002142B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42142Bu);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    label_0002142F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42142Fu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(4u) + (uint64_t)(0u));
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->edx + cpu->eax + 4u))) goto label_000212E0;
    label_00021445: cpu->eip = LIFT_CODE_TOKEN_VA(0x421445u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(0x418u) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->ebp += 0x106u;
    cpu->edx += 0x418u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000212B0;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_0002147B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42147Bu);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421484u); lift_push32(cpu, r); sfera_sub_0048B960(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x351u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421495u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004214A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4214A0u);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edx = lift_load32(cpu->ebp + 0x3Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x38u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->esi |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4214C9u); lift_push32(cpu, r); sfera_sub_0041F110(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xCCu);
    lift_store32(cpu->esp + 0x20u, 0xFFFFF079u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    goto label_000214E4;
    label_000214E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4214E0u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000214E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4214E4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFF079u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00021504;
    label_00021500: cpu->eip = LIFT_CODE_TOKEN_VA(0x421500u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_00021504: cpu->eip = LIFT_CODE_TOKEN_VA(0x421504u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00021549;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x418u);
    cpu->esi += lift_load32(cpu->ebp);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421534u); lift_push32(cpu, r); sfera_sub_0041FBF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00021549;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x34u)) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->eax + cpu->ecx, cpu->edx & 0xFFu);
    goto label_000215B7;
    label_00021549: cpu->eip = LIFT_CODE_TOKEN_VA(0x421549u);
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ebx = (uint32_t)(cpu->esi + cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000215B7;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x418u);
    label_00021560: cpu->eip = LIFT_CODE_TOKEN_VA(0x421560u);
    cpu->eax = lift_load32(cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->ebp;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42157Fu); lift_push32(cpu, r); sfera_sub_0041FBF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021590;
    ++cpu->esi;
    cpu->edi += 0x418u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00021560;
    goto label_000215B7;
    label_00021590: cpu->eip = LIFT_CODE_TOKEN_VA(0x421590u);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x418u);
    cpu->edx = lift_load32(cpu->esi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4215A8u); lift_push32(cpu, r); sfera_sub_0041FA00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store8(cpu->ecx + cpu->edx, cpu->eax & 0xFFu);
    label_000215B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4215B7u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->eax += 0x32u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFB9u)) goto label_00021500;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0xA0u) + (uint64_t)(0u));
    cpu->eax += 0x32u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFB9u)) goto label_000214E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421600u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00021611;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(0x64u)) goto label_00021620;
    label_00021611: cpu->eip = LIFT_CODE_TOKEN_VA(0x421611u);
    cpu->edx = 0x3D1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x21620u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00021620: cpu->eip = LIFT_CODE_TOKEN_VA(0x421620u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xC0u)) == (uint32_t)(0u)) goto label_00021632;
    if ((uint32_t)(lift_load32(cpu->esi + 0xC4u)) != (uint32_t)(0u)) goto label_00021641;
    label_00021632: cpu->eip = LIFT_CODE_TOKEN_VA(0x421632u);
    cpu->edx = 0x3D2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Contours.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x21641u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00021641: cpu->eip = LIFT_CODE_TOKEN_VA(0x421641u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x64CCu)) != (uint32_t)(0u)) goto label_0002165B;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421651u); lift_push32(cpu, r); sfera_sub_004214A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x64CCu, 1u);
    label_0002165B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42165Bu);
    if ((uint32_t)(g_sfera_world_objects.contour_mode) == (uint32_t)(cpu->edi)) goto label_00021671;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42166Bu); lift_push32(cpu, r); sfera_sub_0041FAB0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_world_objects.contour_mode = (uint32_t)(cpu->edi);
    label_00021671: cpu->eip = LIFT_CODE_TOKEN_VA(0x421671u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 4000.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, 50.0);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42168Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    cpu->edi = cpu->eax;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421699u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) > (uint32_t)(0x9Fu)) goto label_000216BD;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x9Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000216BD;
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->ecx += cpu->eax;
    cpu->eax = lift_load8(cpu->ecx + cpu->esi + 0x64D0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000216BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4216BDu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004216D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4216D0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4216F4u); lift_push32(cpu, r); sfera_sub_00420720(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000216FF;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000216FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4216FFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421707u); lift_push32(cpu, r); sfera_sub_0041FA00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421710u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_execution_monitor_runtime;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421720u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0xDu)) == (uint8_t)(0u)) goto label_0002174A;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x42172Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421734u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    lift_store32(cpu->esi + 0x60u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x421743u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421749u);
    cpu->edi = lift_pop32(cpu);
    label_0002174A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42174Au);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421750u);
    cpu->eax = 0u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421760u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, 0x14u);
    lift_store32(cpu->eax + 4u, 4u);
    lift_store32(cpu->eax + 8u, 0u);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421780u);
    cpu->eax = 0u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421790u);
    cpu->eax = 0u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004217A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4217A0u);
    cpu->eax = 1u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004217B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4217B0u);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004217C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4217C0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, 0u);
    cpu->eax = 1u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004217E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4217E0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, 0u);
    cpu->eax = 1u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421800u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, 0u);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421820u);
    cpu->eax = 0x80004001u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421830u);
    cpu->eax = 0x80004001u;
    lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421840u);
    cpu->eax = 0x80004001u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421850u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = address32(&__uuidof(IUnknown));
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi -= cpu->eax;
    label_00021864: cpu->eip = LIFT_CODE_TOKEN_VA(0x421864u);
    cpu->edi = lift_load32(cpu->esi + cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_00021887;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(4u)) goto label_00021864;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00021887: cpu->eip = LIFT_CODE_TOKEN_VA(0x421887u);
    cpu->eax = address32(&__uuidof(IOleClientSite));
    cpu->esi = cpu->edx;
    cpu->ecx = 0x10u;
    cpu->esi -= cpu->eax;
    label_00021895: cpu->eip = LIFT_CODE_TOKEN_VA(0x421895u);
    cpu->edi = lift_load32(cpu->esi + cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000218B8;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(4u)) goto label_00021895;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000218B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4218B8u);
    cpu->eax = address32(&__uuidof(IOleInPlaceSite));
    cpu->esi = cpu->edx;
    cpu->ecx = 0x10u;
    cpu->esi -= cpu->eax;
    label_000218C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4218C6u);
    cpu->edi = lift_load32(cpu->esi + cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000218EC;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(4u)) goto label_000218C6;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax += 4u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000218EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4218ECu);
    cpu->eax = address32(&__uuidof(IDocHostUIHandler));
    cpu->ecx = 0x10u;
    cpu->edx -= cpu->eax;
    label_000218F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4218F8u);
    cpu->esi = lift_load32(cpu->edx + cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0002191E;
    cpu->ecx -= 4u;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(4u)) goto label_000218F8;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += 0x10u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0002191E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42191Eu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, 0u);
    cpu->eax = 0x80004002u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421940u);
    cpu->eax = 0x80004001u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421950u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, 0u);
    cpu->eax = 0x80004002u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421970u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx += 0xFFFFFFFCu;
    lift_store32(cpu->esp + 4u, cpu->edx);
    sfera_sub_00421850(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421980u);
    cpu->eax = 1u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421990u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004219B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4219B0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax += 4u;
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = 0u;
    lift_store32(cpu->eax, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    cpu->eax = 0u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004219E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4219E0u);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004219F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4219F0u);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421A00u);
    cpu->eax = 0x80004001u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421A10u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IOleInPlaceObject))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21A28u), LIFT_CODE_TOKEN_RVA(0x21A26u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421A28u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021A3E;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21A3Eu), LIFT_CODE_TOKEN_RVA(0x21A3Cu))) { return; }
    label_00021A3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x421A3Eu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421A50u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421A70u);
    cpu->eax = 0x80004001u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421A80u);
    cpu->eax = 0x80004001u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421A90u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00021AFD;
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421A9Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421AA3u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21AB6u), LIFT_CODE_TOKEN_RVA(0x21AB4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421AB6u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021AFD;
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x78u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21ACBu), LIFT_CODE_TOKEN_RVA(0x21AC9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421ACBu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::WideCharToMultiByte), LIFT_CODE_TOKEN_VA(0x421AE0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421AE6u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SysFreeString), LIFT_CODE_TOKEN_VA(0x421AEBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421AF1u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21AFDu), LIFT_CODE_TOKEN_RVA(0x21AFBu))) { return; }
    label_00021AFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x421AFDu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421C00u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    cpu->ebx = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421C09u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421C0Fu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21C22u), LIFT_CODE_TOKEN_RVA(0x21C20u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421C22u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021CE3;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::VariantInit), LIFT_CODE_TOKEN_VA(0x421C32u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421C38u);
    cpu->ebp = native_function_address32(&::MultiByteToWideChar);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->edx = 8u;
    lift_push32(cpu, 0u);
    lift_store16(cpu->esp + 0x2Cu, cpu->edx & 0xFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x21C55u), LIFT_CODE_TOKEN_RVA(0x21C53u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421C55u);
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GlobalAlloc), LIFT_CODE_TOKEN_VA(0x421C5Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421C63u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00021C8D;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x21C74u), LIFT_CODE_TOKEN_RVA(0x21C72u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421C74u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::SysAllocString), LIFT_CODE_TOKEN_VA(0x421C75u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421C7Bu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_VA(0x421C80u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421C86u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(0u)) goto label_00021CA6;
    label_00021C8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x421C8Du);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21C99u), LIFT_CODE_TOKEN_RVA(0x21C97u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421C99u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFAu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_00021CA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x421CA6u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xD0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21CC2u), LIFT_CODE_TOKEN_RVA(0x21CC0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421CC2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::VariantClear), LIFT_CODE_TOKEN_VA(0x421CC7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421CCDu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21CD9u), LIFT_CODE_TOKEN_RVA(0x21CD7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421CD9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_00021CE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x421CE3u);
    cpu->eax = 0xFFFFFFFBu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421CF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421CF7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421CFDu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21D10u), LIFT_CODE_TOKEN_RVA(0x21D0Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421D10u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021D3E;
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x68u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21D21u), LIFT_CODE_TOKEN_RVA(0x21D1Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421D21u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x70u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21D32u), LIFT_CODE_TOKEN_RVA(0x21D30u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421D32u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21D3Eu), LIFT_CODE_TOKEN_RVA(0x21D3Cu))) { return; }
    label_00021D3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x421D3Eu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421D50u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::GlobalAlloc), LIFT_CODE_TOKEN_VA(0x421D66u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421D6Cu);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00021D86;
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_00021D86: cpu->eip = LIFT_CODE_TOKEN_VA(0x421D86u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ebx + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ole_host_abi.storage_object_vtable); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, address32(&__uuidof(IOleObject))); lift_push32(cpu, address32(&__uuidof(WebBrowser)));
    lift_store32(cpu->esi, (uintptr_t)&g_sfera_ole_host_abi.client_site_vtable[0]);
    lift_store32(cpu->esi + 4u, (uintptr_t)&g_sfera_ole_host_abi.inplace_site_vtable[0]);
    lift_store32(cpu->esi + 8u, (uintptr_t)&g_sfera_ole_host_abi.inplace_frame_vtable[0]);
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    lift_store32(cpu->esi + 0x10u, (uintptr_t)&g_sfera_ole_host_abi.doc_host_ui_handler_vtable[0]);
    lift_native_call(cpu, native_function_address32(&::OleCreate), LIFT_CODE_TOKEN_VA(0x421DC1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421DC7u);
    lift_push32(cpu, cpu->ebx);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021EE8;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebx, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x421DD9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421DDFu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)L"My Host Name"); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x14u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21DF2u), LIFT_CODE_TOKEN_RVA(0x21DF0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421DF2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetClientRect), LIFT_CODE_TOKEN_VA(0x421DF8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421DFEu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::OleSetContainedObject), LIFT_CODE_TOKEN_VA(0x421E05u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421E0Bu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021EA7;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x2Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21E2Cu), LIFT_CODE_TOKEN_RVA(0x21E2Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421E2Cu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021EA7;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21E45u), LIFT_CODE_TOKEN_RVA(0x21E43u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421E45u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021EA7;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x58u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21E57u), LIFT_CODE_TOKEN_RVA(0x21E55u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421E57u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x60u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21E65u), LIFT_CODE_TOKEN_RVA(0x21E63u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421E65u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x68u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21E76u), LIFT_CODE_TOKEN_RVA(0x21E74u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421E76u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x70u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21E87u), LIFT_CODE_TOKEN_RVA(0x21E85u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421E87u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21E93u), LIFT_CODE_TOKEN_RVA(0x21E91u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421E93u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_00021EA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x421EA7u);
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421EAAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421EB0u);
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00021ED1;
    cpu->esi = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0x21EC2u), LIFT_CODE_TOKEN_RVA(0x21EC0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421EC2u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21ECAu), LIFT_CODE_TOKEN_RVA(0x21EC8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421ECAu);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_RVA(0x21ECBu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x21ED1u);
    label_00021ED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x421ED1u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFDu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_00021EE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x421EE8u);
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_VA(0x421EE8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421EEEu);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFEu;
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421F10u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00021F86;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00021F46;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00021F2B;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_native_call_return(cpu, (uint32_t)(native_function_address32(&::DefWindowProcA)), LIFT_CODE_TOKEN_VA(0x421F25u), stop_address); return;
    label_00021F2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x421F2Bu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x10u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = cpu->eax & 0xFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421F41u); lift_push32(cpu, r); sfera_sub_00421CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 16u, stop_address); return;
    label_00021F46: cpu->eip = LIFT_CODE_TOKEN_VA(0x421F46u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421F4Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421F54u);
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00021F77;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0x21F67u), LIFT_CODE_TOKEN_RVA(0x21F65u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421F67u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21F6Fu), LIFT_CODE_TOKEN_RVA(0x21F6Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421F6Fu);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GlobalFree), LIFT_CODE_TOKEN_VA(0x421F70u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421F76u);
    cpu->esi = lift_pop32(cpu);
    label_00021F77: cpu->eip = LIFT_CODE_TOKEN_VA(0x421F77u);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00021F86: cpu->eip = LIFT_CODE_TOKEN_VA(0x421F86u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x421F8Fu); lift_push32(cpu, r); sfera_sub_00421D50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00021F99;
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 16u, stop_address); return;
    label_00021F99: cpu->eip = LIFT_CODE_TOKEN_VA(0x421F99u);
    cpu->eax = 0u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00421FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421FB0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx += 0xFFFFFFF0u;
    lift_store32(cpu->esp + 4u, cpu->edx);
    sfera_sub_00421850(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422000u);
    cpu->esp -= 0x418u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x4000u)) != (uint32_t)(cpu->esi)) goto label_00022253;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x4014u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42202Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x422033u);
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42203Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x422043u);
    lift_store32(cpu->ebp + 0x4008u, 0xFFFFFFFFu);
    cpu->eax = 0x5C63626Du;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->esp += 0x18u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x1Cu, cpu->ecx & 0xFFu);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    cpu->ebx = (uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    label_00022075: cpu->eip = LIFT_CODE_TOKEN_VA(0x422075u);
    if ((uint8_t)(lift_load8(cpu->ebx)) == (uint8_t)(0u)) goto label_00022105;
    cpu->eax = 0u;
    label_00022080: cpu->eip = LIFT_CODE_TOKEN_VA(0x422080u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x24u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00022080;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->ebx;
    label_00022091: cpu->eip = LIFT_CODE_TOKEN_VA(0x422091u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00022091;
    cpu->edi = (uint32_t)(cpu->esp + 0x24u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_000220A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4220A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000220A0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000220C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4220C0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000220C0;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, cpu->ecx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4220DEu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4220E7u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4220EEu); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00022105;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    lift_store32(cpu->edx, cpu->eax);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_00022105: cpu->eip = LIFT_CODE_TOKEN_VA(0x422105u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->ebx += 0x8D8u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096]))) goto label_00022075;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00022251;
    lift_push32(cpu, 0x6Fu);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42213Du); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0x70u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    lift_store32(cpu->ebp + 0x4000u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422153u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_store32(cpu->ebp + 0x4004u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    label_00022166: cpu->eip = LIFT_CODE_TOKEN_VA(0x422166u);
    if ((uint8_t)(lift_load8(cpu->edx)) == (uint8_t)(0u)) goto label_0002223B;
    cpu->eax = 0u;
    label_00022171: cpu->eip = LIFT_CODE_TOKEN_VA(0x422171u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x24u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00022171;
    cpu->eax = cpu->edx;
    label_00022180: cpu->eip = LIFT_CODE_TOKEN_VA(0x422180u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00022180;
    cpu->edi = (uint32_t)(cpu->esp + 0x24u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_00022190: cpu->eip = LIFT_CODE_TOKEN_VA(0x422190u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00022190;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000221B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4221B0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000221B0;
    cpu->ecx = 0x6264612Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4221CEu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4221D7u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4221DEu); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00022237;
    cpu->ecx = lift_load32(cpu->ebp + 0x4000u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    lift_store32(cpu->ebx + cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x4000u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_store32(cpu->ebx + cpu->eax + 4u, cpu->edx);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42220Cu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x4000u);
    cpu->edx = lift_load32(cpu->ebx + cpu->ecx + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0x4004u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422229u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422230u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->ebx += 8u;
    label_00022237: cpu->eip = LIFT_CODE_TOKEN_VA(0x422237u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_0002223B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42223Bu);
    cpu->edx += 0x8D8u;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096]))) goto label_00022166;
    label_00022251: cpu->eip = LIFT_CODE_TOKEN_VA(0x422251u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00022253: cpu->eip = LIFT_CODE_TOKEN_VA(0x422253u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x418u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422270u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base))), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000223D2;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000223D2;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFFFu)), r=(uint64_t)(lift_load16(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000223D2;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    cpu->edx = (uint32_t)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset));
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    (void)cpu;
    label_000222C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4222C0u);
    cpu->eax = lift_load16(cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00022380;
    cpu->edx = lift_load32(cpu->esi + 0x4000u);
    cpu->edi = lift_load32(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->edi += lift_load32(cpu->ebp);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_00022380;
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00022300: cpu->eip = LIFT_CODE_TOKEN_VA(0x422300u);
    cpu->eax = lift_load32(cpu->esi + 0x4004u);
    cpu->esi = lift_load32(cpu->eax + cpu->ebp);
    cpu->ebx = lift_load32(cpu->eax + cpu->ebp + 4u);
    cpu->ebp += 8u;
    if ((uint32_t)(lift_load32(cpu->esi + cpu->edi)) == (uint32_t)(0xDEEDDEEDu)) goto label_00022344;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + cpu->edi, 0xDEEDDEEDu);
    cpu->eax = lift_load16(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_store32(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42233Du); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022344: cpu->eip = LIFT_CODE_TOKEN_VA(0x422344u);
    if ((uint8_t)(lift_load8(cpu->ebx + cpu->edi)) == (uint8_t)(0xDEu)) goto label_00022372;
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->ebx + cpu->edi, 0xDEu);
    cpu->ecx = lift_load16(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_store32(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42236Bu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022372: cpu->eip = LIFT_CODE_TOKEN_VA(0x422372u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x1Cu, v); }
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00022300;
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    label_00022380: cpu->eip = LIFT_CODE_TOKEN_VA(0x422380u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = (int16_t)(lift_load16(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->ecx += 2u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000222C0;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000223D2;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error)) == (uint32_t)(0u)) goto label_000223D2;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4223C0u); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"Memory Error! See at Warnings.log";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4223CAu); lift_push32(cpu, r); sfera_sub_0044C0A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x223CCu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x223D2u);
    label_000223D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4223D2u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004223E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4223E0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi + 0x4008u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000225DB;
    cpu->eax = lift_load32(cpu->edi + 0x400Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->eax) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFFu)) goto label_00022431;
    cpu->edx = 0xF5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x22431u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00022431: cpu->eip = LIFT_CODE_TOKEN_VA(0x422431u);
    cpu->edx = lift_load32(cpu->edi + 0x4000u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    cpu->edx = lift_load32(cpu->edi + 0x4010u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load32(cpu->edi + 0x400Cu);
    cpu->ebx = lift_load32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset));
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base))), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00022460: cpu->eip = LIFT_CODE_TOKEN_VA(0x422460u);
    cpu->eax = lift_load32(cpu->edi + 0x4004u);
    cpu->ebp = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    cpu->ecx += 2u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + cpu->ebp)), r=(uint64_t)(0xDEEDDEEDu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000224BB;
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + cpu->ebp, 0xDEEDDEEDu);
    cpu->eax = lift_load32(cpu->edi + 0x400Cu);
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->eax) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_store32(cpu->esp + 0x28u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4224B0u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4224BBu);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) == (uint8_t)(0xDEu)) goto label_000224F4;
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + cpu->ebx, 0xDEu);
    cpu->edx = lift_load32(cpu->edi + 0x400Cu);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0x2D4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_store32(cpu->esp + 0x28u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4224EDu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4224F4u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edi + 0x4010u, (uint64_t)(lift_load32(cpu->edi + 0x4010u)) + 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x4010u)) != (uint32_t)(cpu->edx)) goto label_000225A3;
    cpu->ecx = lift_load32(cpu->edi + 0x400Cu);
    cpu->edx = 0u;
    lift_store32(cpu->edi + 0x4010u, cpu->edx);
    label_00022520: cpu->eip = LIFT_CODE_TOKEN_VA(0x422520u);
    ++cpu->ecx;
    lift_store32(cpu->edi + 0x400Cu, cpu->ecx);
    cpu->eax = (int16_t)(lift_load16(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0002256A;
    cpu->eax = lift_load32(cpu->edi + 0x4008u);
    cpu->ecx = 0u;
    lift_store32(cpu->edi + 0x400Cu, cpu->edx);
    label_00022540: cpu->eip = LIFT_CODE_TOKEN_VA(0x422540u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_mbc_runtime->process_chain_last), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = g_sfera_mbc_runtime->process_chain_first;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00022550;
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    label_00022550: cpu->eip = LIFT_CODE_TOKEN_VA(0x422550u);
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    lift_store32(cpu->edi + 0x4008u, cpu->eax);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00022540;
    label_0002256A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42256Au);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u) + 0x2D4u);
    cpu->eax = lift_load32(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00022520;
    cpu->ecx = lift_load32(cpu->edi + 0x4000u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = lift_load32(cpu->edi + 0x400Cu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x324u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base))), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->ecx = cpu->eax;
    label_000225A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4225A3u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x24u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x24u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00022460;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000225DB;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error)) == (uint32_t)(0u)) goto label_000225DB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4225C9u); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"Memory Error! See at Warnings.log";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4225D3u); lift_push32(cpu, r); sfera_sub_0044C0A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x225D5u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x225DBu);
    label_000225DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4225DBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004225F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4225F0u);
    cpu->eax = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u))) == (uint32_t)(0xFFFFFFFFu)) goto label_00022611;
    cpu->eax = 0u;
    lift_store32(cpu->ecx + 0x4008u, cpu->eax);
    lift_store32(cpu->ecx + 0x400Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x4010u, cpu->eax);
    label_00022611: cpu->eip = LIFT_CODE_TOKEN_VA(0x422611u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422620u);
    lift_store32(cpu->ecx + 0x4008u, 0xFFFFFFFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422630u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx + 0x4008u))) goto label_0002265D;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u))) == (uint32_t)(0xFFFFFFFFu)) goto label_0002265D;
    cpu->eax = 0u;
    lift_store32(cpu->ecx + 0x4008u, cpu->eax);
    lift_store32(cpu->ecx + 0x400Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x4010u, cpu->eax);
    label_0002265D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42265Du);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422660u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u), 0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->ecx + 0x4008u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000226AF;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += lift_load32(cpu->ecx + 0x400Cu);
    cpu->eax = lift_load16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_000226AF;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u))) == (uint32_t)(0xFFFFFFFFu)) goto label_000226AF;
    cpu->eax = 0u;
    lift_store32(cpu->ecx + 0x4008u, cpu->eax);
    lift_store32(cpu->ecx + 0x400Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x4010u, cpu->eax);
    label_000226AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4226AFu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004226C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4226C0u);
    cpu->esp -= 0x414u;
    cpu->eax = 0x5C63626Du;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ebx = 0u;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x1Cu, cpu->ecx & 0xFFu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00022700: cpu->eip = LIFT_CODE_TOKEN_VA(0x422700u);
    if ((uint8_t)(lift_load8(cpu->edx)) == (uint8_t)(0u)) goto label_000228CC;
    if ((uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u))) == (uint32_t)(0xFFFFFFFFu)) goto label_000228CC;
    cpu->eax = 0u;
    label_00022716: cpu->eip = LIFT_CODE_TOKEN_VA(0x422716u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x18u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x20u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00022716;
    cpu->eax = cpu->edx;
    label_00022725: cpu->eip = LIFT_CODE_TOKEN_VA(0x422725u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00022725;
    cpu->edi = (uint32_t)(cpu->esp + 0x20u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00022733: cpu->eip = LIFT_CODE_TOKEN_VA(0x422733u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00022733;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_movs8(cpu, 1u);
    --cpu->eax;
    label_00022750: cpu->eip = LIFT_CODE_TOKEN_VA(0x422750u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00022750;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, cpu->ecx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42276Eu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422777u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42277Eu); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0002278F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42278Au); lift_push32(cpu, r); sfera_sub_00422660(cpu,r); if (cpu->eip != r) return; }
    goto label_000228CC;
    label_0002278F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42278Fu);
    cpu->edx = lift_load32(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 0x4000u);
    cpu->ecx = cpu->esi;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 8u)))) goto label_000227B0;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4227ABu); lift_push32(cpu, r); sfera_sub_00422660(cpu,r); if (cpu->eip != r) return; }
    goto label_000228CC;
    label_000227B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4227B0u);
    lift_push32(cpu, 0x19Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4227C1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4227CEu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4227DAu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4227E1u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = lift_load32(cpu->ebp + 0x4000u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->eax = lift_load32(cpu->ebp + 0x4004u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = cpu->ebx;
    if ((uint32_t)(cpu->esi) < (uint32_t)(4u)) goto label_00022817;
    label_00022803: cpu->eip = LIFT_CODE_TOKEN_VA(0x422803u);
    cpu->eax = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx))) goto label_0002281F;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(4u)) goto label_00022803;
    label_00022817: cpu->eip = LIFT_CODE_TOKEN_VA(0x422817u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000228B7;
    label_0002281F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42281Fu);
    cpu->eax = lift_load8(cpu->edx);
    cpu->edi = lift_load8(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002285E;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(1u)) goto label_000228B7;
    cpu->eax = lift_load8(cpu->edx + 1u);
    cpu->edi = lift_load8(cpu->ecx + 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002285E;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(2u)) goto label_000228B7;
    cpu->eax = lift_load8(cpu->edx + 2u);
    cpu->edi = lift_load8(cpu->ecx + 2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002285E;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(3u)) goto label_000228B7;
    cpu->eax = lift_load8(cpu->edx + 3u);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    label_0002285E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42285Eu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000228B7;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u), 0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->ebp + 0x4008u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000228B7;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += lift_load32(cpu->ebp + 0x400Cu);
    cpu->eax = lift_load16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_000228B7;
    cpu->ecx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if ((uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u))) == (uint32_t)(0xFFFFFFFFu)) goto label_000228B7;
    cpu->eax = 0u;
    lift_store32(cpu->ebp + 0x4008u, cpu->eax);
    lift_store32(cpu->ebp + 0x400Cu, cpu->eax);
    lift_store32(cpu->ebp + 0x4010u, cpu->eax);
    label_000228B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4228B7u);
    lift_push32(cpu, 0x1A1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4228C8u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_000228CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4228CCu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx += 0x8D8u;
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096]))) goto label_00022700;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422910u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00022934;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->eax = ~((uint64_t)(cpu->eax));
    label_00022934: cpu->eip = LIFT_CODE_TOKEN_VA(0x422934u);
    cpu->edx = 0x12u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422946u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 4u));
    cpu->edx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1Fu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422963u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00022977;
    cpu->ecx = (uint32_t)(uintptr_t)"CDIB::Initialize(): failed to allocate memory block";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x22977u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00022977: cpu->eip = LIFT_CODE_TOKEN_VA(0x422977u);
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422980u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422999u); lift_push32(cpu, r); sfera_sub_00422910(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 4u));
    cpu->ecx = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1Fu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4229B4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4229B9u);
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004229D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4229D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x23u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4229E2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4229EAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004229F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4229F0u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 4u));
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x1Fu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 8u)); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + cpu->edx);
    cpu->eax &= lift_load32(cpu->ecx + 0x10u);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422A20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x80u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0x33u, 1u);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x422A6Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x422A70u);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_00022C8C;
    cpu->esi = native_function_address32(&::ReadFile);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xEu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x22A91u), LIFT_CODE_TOKEN_RVA(0x22A8Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422A91u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00022C47;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(0xEu)) goto label_00022C47;
    cpu->edx = 0x4D42u;
    if ((uint16_t)(lift_load16(cpu->esp + 0x4Cu)) != (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00022C47;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetFileSize), LIFT_CODE_TOKEN_VA(0x422AB6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x422ABCu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x4Eu)) != (uint32_t)(cpu->eax)) goto label_00022C47;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ebp = 0x28u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x22ADAu), LIFT_CODE_TOKEN_RVA(0x22AD8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422ADAu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00022C47;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->ebp)) goto label_00022C47;
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) != (uint32_t)(cpu->ebp)) goto label_00022C47;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00022C47;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x1000u)) goto label_00022C47;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00022C47;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x1000u)) goto label_00022C47;
    if ((uint16_t)(lift_load16(cpu->esp + 0x30u)) != (uint16_t)(1u)) goto label_00022C47;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x32u)) & 0xFFFFu);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)(0x18u)) goto label_00022B4A;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != (uint16_t)(0x20u)) goto label_00022C47;
    label_00022B4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x422B4Au);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) != (uint32_t)(cpu->edi)) goto label_00022C47;
    cpu->edx = 0x78u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422B63u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422B6Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x68u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00022B9D;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    cpu->edx = lift_load16(cpu->esp + 0x32u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422B99u); lift_push32(cpu, r); sfera_sub_00422980(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_00022B9F;
    label_00022B9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x422B9Du);
    cpu->esi = 0u;
    label_00022B9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x422B9Fu);
    lift_store32(cpu->esp + 0x68u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00022C43;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00022BBF;
    cpu->eax = 0u;
    goto label_00022BC2;
    label_00022BBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x422BBFu);
    cpu->eax = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    label_00022BC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x422BC2u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x1Fu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(5u), 32u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1Fu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebp = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) <= (uint32_t)(cpu->ebp)) goto label_00022C3E;
    label_00022C02: cpu->eip = LIFT_CODE_TOKEN_VA(0x422C02u);
    lift_push32(cpu, 0u);
    cpu->eax += cpu->eax;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::ReadFile), LIFT_CODE_TOKEN_VA(0x422C10u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x422C16u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00022C43;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 4u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1Fu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->ecx)) goto label_00022C43;
    cpu->edi += lift_load32(cpu->esp + 0x20u);
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00022C02;
    label_00022C3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x422C3Eu);
    lift_store8(cpu->esp + 0x17u, 0u);
    label_00022C43: cpu->eip = LIFT_CODE_TOKEN_VA(0x422C43u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_00022C47: cpu->eip = LIFT_CODE_TOKEN_VA(0x422C47u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x422C48u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x422C4Eu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)(0u)) goto label_00022C8C;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00022C8C;
    cpu->edx = 0x96u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422C68u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x23u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DIB.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422C77u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422C7Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422C85u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->eax = 0u;
    goto label_00022C8E;
    label_00022C8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x422C8Cu);
    cpu->eax = cpu->edi;
    label_00022C8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x422C8Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422CB0u);
    cpu->esp -= 0x338u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    cpu->esi = 0u;
    label_00022CD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x422CD6u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x22CD8u), LIFT_CODE_TOKEN_RVA(0x22CD6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422CD8u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.2831854820251465));
    lift_store_f32(cpu->esp + cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x22CF2u), LIFT_CODE_TOKEN_RVA(0x22CF0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422CF2u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->esi += 4u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_store_f32(cpu->esp + cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x190u)) goto label_00022CD6;
    lift_x87_push(cpu, (double)-1.0f);
    cpu->ebx = 0u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ebp += 0x474u;
    cpu->edi = cpu->edi;
    label_00022D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x422D30u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->esi = 0u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.006135923322290182));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00022D50: cpu->eip = LIFT_CODE_TOKEN_VA(0x422D50u);
    cpu->edi = (uint32_t)(cpu->esi + 1u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x24u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x422D70u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x1B4u))));
    cpu->esi = cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x64u)) goto label_00022D50;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00022DBA;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00022DBC;
    label_00022DBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x422DBAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00022DBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x422DBCu);
    ++cpu->ebx;
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x400u)) goto label_00022D30;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, 1.0);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax += 0x478u;
    cpu->ecx = 0x80u;
    cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    label_00022DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x422DF0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    cpu->eax += 0x20u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFE0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFE4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0xFFFFFFECu))));
    lift_store_f32(cpu->eax + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00022DF0;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x338u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00422E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x422E50u);
    cpu->esp -= 0x1C0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1C8u);
    cpu->eax = lift_load32(cpu->ebx + 0x1C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00023E5F;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1D0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x44u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00022E8C;
    lift_store32(cpu->esp + 0x44u, 1u);
    label_00022E8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x422E8Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x1D0u);
    lift_x87_push(cpu, 5.0);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x190u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x190u);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00022F19;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00022F19;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00022F19;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00022F19;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00022F19;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    cpu->edi = 1u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    lift_store32(cpu->esp + 0x1A4u, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00022F19: cpu->eip = LIFT_CODE_TOKEN_VA(0x422F19u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1C8u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x1C8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00022F87;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00022F87;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00022F87;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00022F87;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00022F87;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x1A4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->edi;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00022F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x422F87u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x200u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00022FF5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00022FF5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00022FF5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00022FF5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00022FF5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x1A4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->edi;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00022FF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x422FF5u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x238u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x238u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00023063;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023063;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023063;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023063;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023063;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x1A4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->edi;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00023063: cpu->eip = LIFT_CODE_TOKEN_VA(0x423063u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x270u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x270u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000230D3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000230D3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000230D3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000230D3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000230D5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x1A4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->edi;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000230D5;
    label_000230D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4230D3u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000230D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4230D5u);
    lift_x87_push(cpu, 8.0);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1474u)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x1474u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002314C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002314C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002314C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002314C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002314C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    cpu->ebp = 1u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    lift_store32(cpu->esp + 0x1B8u, cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002314C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42314Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14A4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x14A4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000231BA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000231BA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000231BA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000231BA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000231BA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->ebp) * 4u) + 0x1B8u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000231BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4231BAu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14D4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x14D4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00023228;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023228;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023228;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023228;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023228;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->ebp) * 4u) + 0x1B8u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00023228: cpu->eip = LIFT_CODE_TOKEN_VA(0x423228u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1504u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x1504u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00023296;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023296;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023296;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023296;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023296;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->ebp) * 4u) + 0x1B8u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00023296: cpu->eip = LIFT_CODE_TOKEN_VA(0x423296u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1534u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x1534u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00023304;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023304;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023304;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023304;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023304;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->ebp) * 4u) + 0x1B8u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00023304: cpu->eip = LIFT_CODE_TOKEN_VA(0x423304u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1564u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x1564u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00023374;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023374;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00023374;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023374;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00023376;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->ebp) * 4u) + 0x1B8u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00023376;
    label_00023374: cpu->eip = LIFT_CODE_TOKEN_VA(0x423374u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00023376: cpu->eip = LIFT_CODE_TOKEN_VA(0x423376u);
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x2B8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000233BA;
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x2B4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x2B8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4233ABu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4233B1u);
    cpu->esp += 8u;
    lift_store32(cpu->esi + 0x2B4u, cpu->eax);
    label_000233BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4233BAu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->ebx + 0x24u);
    cpu->edx = lift_load32(cpu->ebx + 0x1D0u);
    cpu->eax = lift_load32(cpu->esi + 0x2B4u);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00023E5D;
    lift_x87_push(cpu, 0.5);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_x87_push(cpu, 1.0);
    cpu->edx = cpu->eax;
    lift_x87_push(cpu, 0.15000000596046448);
    cpu->edi = (uint32_t)(cpu->ebp + 8u);
    lift_x87_push(cpu, 0.05999999865889549);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_x87_push(cpu, 0.800000011920929);
    cpu->ebx = (uint32_t)(cpu->edx + 0x14u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    label_00023419: cpu->eip = LIFT_CODE_TOKEN_VA(0x423419u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->ebx + 0xFFFFFFF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->ebx + 0xFFFFFFFCu, cpu->ecx);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->eax = lift_load16(cpu->ecx);
    cpu->ecx = 0xFFFFu;
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != (uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00023455;
    cpu->eax = lift_load32(cpu->ebp);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 8u, cpu->eax);
    goto label_00023E17;
    label_00023455: cpu->eip = LIFT_CODE_TOKEN_VA(0x423455u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint16_t)(lift_load16(cpu->ecx + 4u)) == (uint16_t)(0u)) goto label_0002347A;
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x2Cu)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00023509;
    goto label_00023637;
    label_0002347A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42347Au);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = 0u;
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000235E8;
    label_0002348C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42348Cu);
    cpu->edx = lift_load32(cpu->esp + ((uint32_t)(cpu->ecx) * 4u) + 0x1A4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x10u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000234ED;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.9990000128746033);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000235DD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000234ED;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000234ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4234EDu);
    ++cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_0002348C;
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x2Cu)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000235E8;
    label_00023509: cpu->eip = LIFT_CODE_TOKEN_VA(0x423509u);
    cpu->edx = lift_load32(cpu->esp + 0x1D4u);
    cpu->eax = lift_load32(cpu->edx + 0x1CCu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx + 0x18u));
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0xFFFFFFFCu))));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xBCu))));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_store_f32(cpu->esp + 0x18Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xFFFFFFFCu))));
    lift_store_f32(cpu->esp + 0x190u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x190u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0x194u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x194u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->ebx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->ebx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00023D43;
    label_000235DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4235DDu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00023509;
    label_000235E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4235E8u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00023642;
    label_000235F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4235F4u);
    cpu->edx = lift_load32(cpu->esp + ((uint32_t)(cpu->ecx) * 4u) + 0x1B8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x10u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00023633;
    ++cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000235F4;
    goto label_00023642;
    label_00023633: cpu->eip = LIFT_CODE_TOKEN_VA(0x423633u);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    label_00023637: cpu->eip = LIFT_CODE_TOKEN_VA(0x423637u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x40u)) != (uint32_t)(0u)) goto label_0002398A;
    label_00023642: cpu->eip = LIFT_CODE_TOKEN_VA(0x423642u);
    cpu->eax = 0xFDE8u;
    if ((uint16_t)(lift_load16(cpu->esp + 0x44u)) <= (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00023730;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x423660u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->ecx + 2u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax &= 0x3FFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x474u));
    cpu->eax = lift_load32(cpu->esp + 0x1D4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    cpu->ecx = lift_load32(cpu->eax + 0x1CCu);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0xFFFFFFFCu))));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x9Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x12Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xA0u))));
    lift_store_f32(cpu->esp + 0x130u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xA4u))));
    lift_store_f32(cpu->esp + 0x134u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x12Cu))));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x130u))));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x134u))));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    goto label_00023D43;
    label_00023730: cpu->eip = LIFT_CODE_TOKEN_VA(0x423730u);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x423744u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->ecx + 2u);
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0x3FFu;
    cpu->eax += 0xFFFFFE00u;
    cpu->eax &= 0x3FFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x474u));
    cpu->ecx = lift_load32(cpu->esp + 0x1D4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x474u))));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax += lift_load32(cpu->ecx + 0x1CCu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->esp + 0xECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    cpu->eax = lift_load16(cpu->esp + 0x44u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->ecx + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0x174u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 4u))));
    lift_store_f32(cpu->esp + 0x178u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store_f32(cpu->esp + 0x17Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x174u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xCCu))));
    lift_store_f32(cpu->esp + 0x144u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x178u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xD0u))));
    lift_store_f32(cpu->esp + 0x148u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x17Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xD4u))));
    lift_store_f32(cpu->esp + 0x14Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x144u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xE4u))));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x148u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xE8u))));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xECu))));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4238BFu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32(cpu->esp + 0x198u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32(cpu->esp + 0x19Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store_f32(cpu->esp + 0x1A0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x198u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x19Cu))));
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1A0u))));
    lift_store_f32(cpu->esp + 0x104u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0x15Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x15Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x100u))));
    lift_store_f32(cpu->esp + 0x160u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x160u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x104u))));
    lift_store_f32(cpu->esp + 0x164u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x164u);
    goto label_00023D1D;
    label_0002398A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42398Au);
    cpu->eax = 0xFDE8u;
    if ((uint16_t)(lift_load16(cpu->esp + 0x44u)) <= (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00023A98;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4239A8u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->ecx + 2u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax &= 0x3FFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x474u));
    cpu->eax = lift_load32(cpu->esp + 0x1D4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    cpu->ecx = lift_load32(cpu->eax + 0x1CCu);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.25));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0x114u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0xFFFFFFFCu))));
    lift_store_f32(cpu->esp + 0x118u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0x11Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x114u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x118u))));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x11Cu))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x90u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x7Cu))));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x94u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x98u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00023D43;
    label_00023A98: cpu->eip = LIFT_CODE_TOKEN_VA(0x423A98u);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (-3.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x423AB2u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load16(cpu->ecx + 2u);
    cpu->ecx -= cpu->eax;
    cpu->edx = cpu->ecx;
    cpu->edx &= 0x3FFu;
    cpu->ecx += 0xFFFFFE00u;
    cpu->ecx &= 0x3FFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x474u));
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x468u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x474u))));
    cpu->ecx = lift_load32(cpu->esp + 0x1D4u);
    cpu->eax = lift_load32(cpu->ecx + 0x1CCu);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    cpu->ecx = lift_load32(cpu->ecx + 0x24u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x46Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    cpu->eax = lift_load16(cpu->esp + 0x44u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->ebp = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 4u))));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xC0u))));
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xC4u))));
    lift_store_f32(cpu->esp + 0xDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xC8u))));
    lift_store_f32(cpu->esp + 0xE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xD8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xF0u))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xDCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xF4u))));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xE0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xF8u))));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x423C3Bu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 0x108u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x64u))));
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x68u))));
    lift_store_f32(cpu->esp + 0x110u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x120u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10Cu))));
    lift_store_f32(cpu->esp + 0x124u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_store_f32(cpu->esp + 0x128u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x120u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0x138u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x138u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x124u))));
    lift_store_f32(cpu->esp + 0x13Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x13Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x128u))));
    lift_store_f32(cpu->esp + 0x140u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x140u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xFFFFFFF8u));
    lift_x87_push(cpu, 0.75);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx))));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00023D1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x423D1Du);
    lift_x87_push(cpu, 0.800000011920929);
    cpu->ebp = lift_load32(cpu->esp + 0x3Cu);
    lift_x87_push(cpu, 0.05999999865889549);
    lift_x87_push(cpu, 0.15000000596046448);
    lift_x87_push(cpu, 0.5);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00023D43: cpu->eip = LIFT_CODE_TOKEN_VA(0x423D43u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x4Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00023D6B;
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    lift_store32(cpu->edx + 8u, cpu->eax);
    goto label_00023E17;
    label_00023D6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x423D6Bu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0x150u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_store_f32(cpu->esp + 0x154u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->esp + 0x158u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x150u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x168u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x154u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x16Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x158u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x170u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x168u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0x180u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x180u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x16Cu))));
    lift_store_f32(cpu->esp + 0x184u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x170u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    cpu->eax = lift_load32(cpu->esp + 0x184u);
    lift_store32(cpu->edx, cpu->ecx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_store_f32(cpu->esp + 0x188u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x188u);
    lift_store32(cpu->edx + 8u, cpu->ecx);
    label_00023E17: cpu->eip = LIFT_CODE_TOKEN_VA(0x423E17u);
    cpu->eax = lift_load32(cpu->esp + 0x5Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x1D4u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x48u, (uint64_t)(lift_load32(cpu->esp + 0x48u)) + (uint64_t)(0x18u) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->ebp += 0x24u;
    cpu->edx += 0x18u;
    cpu->edi += 0x24u;
    cpu->ebx += 0x18u;
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x20u))) goto label_00023419;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00023E5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x423E5Du);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00023E5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x423E5Fu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1C0u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00423E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x423E70u);
    cpu->esp -= 0xE0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ebx + 0x1C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000243AD;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1D0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x30u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00023EA9;
    lift_store32(cpu->esp + 0x30u, 1u);
    label_00023EA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x423EA9u);
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x2B8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00023EED;
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x2B4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x2B8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x423EDEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x423EE4u);
    cpu->esp += 8u;
    lift_store32(cpu->esi + 0x2B4u, cpu->eax);
    label_00023EED: cpu->eip = LIFT_CODE_TOKEN_VA(0x423EEDu);
    cpu->edx = lift_load32(cpu->ebx + 0x1D0u);
    cpu->eax = lift_load32(cpu->esi + 0x2B4u);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx + 0x24u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000243AC;
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->eax + 0xCu);
    lift_x87_push(cpu, (double)-1.0f);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, 0.05999999865889549);
    lift_x87_push(cpu, 0.4000000059604645);
    label_00023F47: cpu->eip = LIFT_CODE_TOKEN_VA(0x423F47u);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->ecx = lift_load16(cpu->ebp);
    cpu->edx = 0xFFFFu;
    if ((uint16_t)((cpu->ecx & 0xFFFFu)) != (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00023F7E;
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    goto label_00024370;
    label_00023F7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x423F7Eu);
    cpu->edx = 0xFDE8u;
    if ((uint16_t)((cpu->ecx & 0xFFFFu)) <= (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00024057;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x423F9Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load16(cpu->ebp + 2u);
    cpu->edx = lift_load32(cpu->ebx + 0x1CCu);
    cpu->eax += cpu->ecx;
    cpu->eax &= 0x3FFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x474u));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    cpu->eax = (uint32_t)(cpu->edx + cpu->eax + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.15000000596046448));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 8u))));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xA8u))));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x7Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 8u))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    goto label_00024294;
    label_00024057: cpu->eip = LIFT_CODE_TOKEN_VA(0x424057u);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424069u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load16(cpu->ebp + 2u);
    cpu->eax += cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->edx &= 0x3FFu;
    cpu->eax += 0xFFFFFE00u;
    cpu->eax &= 0x3FFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x474u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x470u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x474u));
    cpu->eax = lift_load32(cpu->ebx + 0x1CCu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x470u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    cpu->eax = lift_load16(cpu->ebp);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebx))));
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebx + 4u))));
    lift_store_f32(cpu->esp + 0xDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebx + 8u))));
    lift_store_f32(cpu->esp + 0xE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xD8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x90u))));
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xDCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x94u))));
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xE0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x98u))));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x5Cu))));
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
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4241CAu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x74u))));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx))));
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x9Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xA0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 8u));
    cpu->ebx = lift_load32(cpu->esp + 0xF4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x8Cu))));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xA4u);
    lift_x87_push(cpu, 0.4000000059604645);
    lift_x87_push(cpu, 0.05999999865889549);
    lift_x87_push(cpu, 0.5);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_00024294: cpu->eip = LIFT_CODE_TOKEN_VA(0x424294u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000242BC;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    goto label_0002436C;
    label_000242BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4242BCu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xBCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0xE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xE4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xD0u))));
    lift_store_f32(cpu->esp + 0xE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xD4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store_f32(cpu->esp + 0xECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xECu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    label_0002436C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42436Cu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_00024370: cpu->eip = LIFT_CODE_TOKEN_VA(0x424370u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x18u) + (uint64_t)(0u));
    ++cpu->edx;
    cpu->eax += 0x18u;
    cpu->ecx += 0x18u;
    cpu->ebp += 0xCu;
    cpu->edi += 0x24u;
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u))) goto label_00023F47;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000243AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4243ACu);
    cpu->edi = lift_pop32(cpu);
    label_000243AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4243ADu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004243C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4243C0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x464u));
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    cpu->ebp = native_function_address32(&::rand);
    cpu->esi = (uint32_t)(cpu->edi + 0x1478u);
    lift_store32(cpu->esp + 0x20u, 6u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_store_f32(cpu->edi + 0x470u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x458u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x464u))));
    lift_x87_push(cpu, 0.30000001192092896);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edi + 0x468u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x460u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x464u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0x46Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_push(cpu, 4.0);
    label_0002442F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42442Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xFFFFFFFCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebx))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebx + 8u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00024468;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 2600.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00024528;
    label_00024468: cpu->eip = LIFT_CODE_TOKEN_VA(0x424468u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xFFFFFFFCu, 1u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x24475u), LIFT_CODE_TOKEN_RVA(0x24473u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424475u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.5));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x24494u), LIFT_CODE_TOKEN_RVA(0x24492u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424494u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_push(cpu, 20.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x458u));
    lift_x87_push(cpu, 30.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->ebx))) - (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x460u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x460u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x458u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x244F4u), LIFT_CODE_TOKEN_RVA(0x244F2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4244F4u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_push(cpu, 4.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (2.0));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00024528: cpu->eip = LIFT_CODE_TOKEN_VA(0x424528u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x458u));
    cpu->esi += 0x30u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x464u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xFFFFFFF8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xFFFFFFD0u))));
    lift_store_f32(cpu->esi + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x460u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x464u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xFFFFFFF8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xFFFFFFD4u))));
    lift_store_f32(cpu->esi + 0xFFFFFFD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFD0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xFFFFFFE0u))));
    lift_store_f32(cpu->esi + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFD0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xFFFFFFE0u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFD4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xFFFFFFE0u))));
    lift_store_f32(cpu->esi + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFD4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xFFFFFFE0u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002442F;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424594u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->esi |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->edi + 0x78u)) == (uint32_t)(cpu->esi)) goto label_000245BF;
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->edi + 0xA8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebx = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->edi + 0xACu)), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000245BF;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_000245BC;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0x2710u)) goto label_000245BF;
    label_000245BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4245BCu);
    lift_store32(cpu->edi + 0x78u, cpu->esi);
    label_000245BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4245BFu);
    if ((uint32_t)(lift_load32(cpu->edi + 0xB0u)) == (uint32_t)(cpu->esi)) goto label_000245ED;
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->edi + 0xE0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebx = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->edi + 0xE4u)), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000245ED;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_000245E7;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0x2710u)) goto label_000245ED;
    label_000245E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4245E7u);
    lift_store32(cpu->edi + 0xB0u, cpu->esi);
    label_000245ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4245EDu);
    if ((uint32_t)(lift_load32(cpu->edi + 0xE8u)) == (uint32_t)(cpu->esi)) goto label_0002461B;
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->edi + 0x118u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebx = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->edi + 0x11Cu)), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0002461B;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00024615;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0x2710u)) goto label_0002461B;
    label_00024615: cpu->eip = LIFT_CODE_TOKEN_VA(0x424615u);
    lift_store32(cpu->edi + 0xE8u, cpu->esi);
    label_0002461B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42461Bu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x120u)) == (uint32_t)(cpu->esi)) goto label_00024649;
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->edi + 0x150u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebx = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->edi + 0x154u)), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00024649;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00024643;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0x2710u)) goto label_00024649;
    label_00024643: cpu->eip = LIFT_CODE_TOKEN_VA(0x424643u);
    lift_store32(cpu->edi + 0x120u, cpu->esi);
    label_00024649: cpu->eip = LIFT_CODE_TOKEN_VA(0x424649u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x158u)) == (uint32_t)(cpu->esi)) goto label_00024672;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi + 0x188u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->edi + 0x18Cu)), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00024672;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0002466C;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x2710u)) goto label_00024672;
    label_0002466C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42466Cu);
    lift_store32(cpu->edi + 0x158u, cpu->esi);
    label_00024672: cpu->eip = LIFT_CODE_TOKEN_VA(0x424672u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00424680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424680u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ecx + 0x45Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.7070000171661377f);
    lift_store_f32(cpu->ecx + 0x458u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x460u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.4000000059604645f);
    lift_store_f32(cpu->ecx + 0x464u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004246B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4246B0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 0x2A8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 0x2ACu, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 0x2B0u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004246E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4246E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_00024785;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4246F2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4246F8u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->esi + 0x78u);
    cpu->edx = 0u;
    cpu->ecx = cpu->eax;
    label_00024703: cpu->eip = LIFT_CODE_TOKEN_VA(0x424703u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->edi)) goto label_00024733;
    ++cpu->edx;
    cpu->ecx += 0x38u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(5u)) goto label_00024703;
    cpu->ecx = 0u;
    label_00024714: cpu->eip = LIFT_CODE_TOKEN_VA(0x424714u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00024731;
    ++cpu->ecx;
    cpu->eax += 0x38u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(5u)) goto label_00024714;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x424725u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42472Bu);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00024731: cpu->eip = LIFT_CODE_TOKEN_VA(0x424731u);
    lift_store32(cpu->eax, cpu->edi);
    label_00024733: cpu->eip = LIFT_CODE_TOKEN_VA(0x424733u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.5f);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424776u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    lift_store32(cpu->esi + 0x34u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x42477Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424783u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00024785: cpu->eip = LIFT_CODE_TOKEN_VA(0x424785u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00424790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424790u);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->ebx + 0x1C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000249B4;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1D0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000247C6;
    lift_store32(cpu->esp + 0x10u, 1u);
    label_000247C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4247C6u);
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x2B8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0002480A;
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x2B4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x2B8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4247FBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424801u);
    cpu->esp += 8u;
    lift_store32(cpu->esi + 0x2B4u, cpu->eax);
    label_0002480A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42480Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x470u));
    cpu->edx = lift_load32(cpu->ebx + 0x1D0u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.699999988079071));
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 0x2B4u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->edi = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, 0.05000000074505806);
    cpu->ebx = 0u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.15000000596046448);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x20u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000249B0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)0.009999999776482582f);
    lift_x87_push(cpu, 0.4000000059604645);
    label_0002486E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42486Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->ebx) * 8u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002489B;
    cpu->edx = lift_load32(cpu->edi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    goto label_0002498C;
    label_0002489B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42489Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 6u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4248A5u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load16(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->eax += cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->edx &= 0x3FFu;
    cpu->ecx = (uint32_t)(cpu->eax + 0xC8u);
    cpu->ecx &= 0x3FFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x474u));
    cpu->eax += 0x190u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    cpu->eax &= 0x3FFu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x474u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x474u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 8u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00024918;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    goto label_00024986;
    label_00024918: cpu->eip = LIFT_CODE_TOKEN_VA(0x424918u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 4u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    label_00024986: cpu->eip = LIFT_CODE_TOKEN_VA(0x424986u);
    lift_store32(cpu->ebp, cpu->edx);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    label_0002498C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42498Cu);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x18u) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 8u, cpu->ecx);
    ++cpu->ebx;
    cpu->edi += 0x24u;
    cpu->ebp += 0x18u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 0x20u))) goto label_0002486E;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000249B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4249B0u);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu);
    label_000249B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4249B4u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004249C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4249C0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->edi)) goto label_00024A30;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x388u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00024A2F;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx += 4u;
    label_000249E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4249E1u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000249EC;
    cpu->eax = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0xFFFFFFF4u))) goto label_00024A26;
    label_000249EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4249ECu);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4249FAu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 0x1C4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(2u)) goto label_00024A0A;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(3u)) goto label_00024A1D;
    label_00024A0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A0Au);
    cpu->edx = lift_load32(cpu->esi + 0x388u);
    lift_store32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 0x2C0u, cpu->eax);
    lift_store32(cpu->esi + 0x388u, (uint64_t)(lift_load32(cpu->esi + 0x388u)) + 1u);
    label_00024A1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A1Du);
    if ((uint32_t)(lift_load32(cpu->esi + 0x388u)) == (uint32_t)(0x32u)) goto label_00024A2E;
    label_00024A26: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A26u);
    ++cpu->edi;
    cpu->ebx += 0xCu;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000249E1;
    label_00024A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A2Eu);
    cpu->ebx = lift_pop32(cpu);
    label_00024A2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A2Fu);
    cpu->ebp = lift_pop32(cpu);
    label_00024A30: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A30u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00424A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424A40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetExitCodeThread);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0x103u;
    label_00024A51: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A51u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00024A78;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x24A5Fu), LIFT_CODE_TOKEN_RVA(0x24A5Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424A5Fu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00024A72;
    cpu->edx = 0x21Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x24A72u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00024A72: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A72u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xCu)) == (uint32_t)(cpu->ebx)) goto label_00024A51;
    label_00024A78: cpu->eip = LIFT_CODE_TOKEN_VA(0x424A78u);
    cpu->edi = native_function_address32(&::EnterCriticalSection);
    cpu->ebx = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x24A84u), LIFT_CODE_TOKEN_RVA(0x24A82u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424A84u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1594u)) != (uint32_t)(1u)) goto label_00024AA5;
    cpu->edx = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x24A93u), LIFT_CODE_TOKEN_RVA(0x24A91u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424A93u);
    cpu->esi += 0x1Cu;
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x24A99u), LIFT_CODE_TOKEN_RVA(0x24A97u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424A99u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x424A9Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424AA0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00024AA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x424AA5u);
    cpu->eax = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x24AABu), LIFT_CODE_TOKEN_RVA(0x24AA9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424AABu);
    cpu->esi += 4u;
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x24AB1u), LIFT_CODE_TOKEN_RVA(0x24AAFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424AB1u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x424AB2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424AB8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00424AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424AC0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->ecx + 0x2BCu, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00424AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424AD0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = (uint32_t)(cpu->ebx + 0x4Cu);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x424ADFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424AE5u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::LeaveCriticalSection);
    cpu->esi = (uint32_t)(cpu->ebx + 0x78u);
    cpu->edi = (uint32_t)(cpu->ebx + 0x190u);
    cpu->ecx = 0x46u;
    lift_movs32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x24AFEu), LIFT_CODE_TOKEN_RVA(0x24AFCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424AFEu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x24u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00024C15;
    label_00024B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x424B10u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x6Cu)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00024C03;
    cpu->ebp = (uint32_t)(cpu->ebx + 0x34u);
    cpu->edi = cpu->edi;
    label_00024B20: cpu->eip = LIFT_CODE_TOKEN_VA(0x424B20u);
    cpu->esi = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24B29u), LIFT_CODE_TOKEN_RVA(0x24B27u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424B29u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1594u)), r=(uint64_t)(1u), v=l ^ r; lift_flags_logic(cpu,v,32u); lift_store32(cpu->ebx + 0x1594u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00024B38;
    cpu->eax = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    goto label_00024B3C;
    label_00024B38: cpu->eip = LIFT_CODE_TOKEN_VA(0x424B38u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    label_00024B3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x424B3Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24B3Eu), LIFT_CODE_TOKEN_RVA(0x24B3Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424B3Eu);
    cpu->esi = native_function_address32(&::LeaveCriticalSection);
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24B47u), LIFT_CODE_TOKEN_RVA(0x24B45u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424B47u);
    cpu->edx = lift_load32(cpu->ebx + 0x6Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x24u));
    cpu->eax = lift_load32(cpu->ebx + 0x68u);
    cpu->edx += cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x98u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00024BDE;
    cpu->ecx = lift_load32(cpu->ebx + 0x64u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424B90u); lift_push32(cpu, r); sfera_sub_00422E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D0u)) != (uint32_t)(0u)) goto label_00024BB5;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x424BA6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424BACu);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    label_00024BB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x424BB5u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->ebx + 0x2B4u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x424BD0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424BD5u);
    cpu->esi = native_function_address32(&::LeaveCriticalSection);
    cpu->esp += 0xCu;
    label_00024BDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x424BDEu);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1594u)) != (uint32_t)(0u)) goto label_00024BED;
    cpu->edx = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edx);
    goto label_00024BF1;
    label_00024BED: cpu->eip = LIFT_CODE_TOKEN_VA(0x424BEDu);
    cpu->eax = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    label_00024BF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x424BF1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24BF3u), LIFT_CODE_TOKEN_RVA(0x24BF1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424BF3u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x6Cu))) goto label_00024B20;
    cpu->ebp = native_function_address32(&::LeaveCriticalSection);
    label_00024C03: cpu->eip = LIFT_CODE_TOKEN_VA(0x424C03u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x6Cu))) goto label_00024B10;
    label_00024C15: cpu->eip = LIFT_CODE_TOKEN_VA(0x424C15u);
    cpu->esi = native_function_address32(&::EnterCriticalSection);
    cpu->edi = (uint32_t)(cpu->ebx + 0x34u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24C21u), LIFT_CODE_TOKEN_RVA(0x24C1Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424C21u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1594u)), r=(uint64_t)(1u), v=l ^ r; lift_flags_logic(cpu,v,32u); lift_store32(cpu->ebx + 0x1594u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00024C30;
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    goto label_00024C34;
    label_00024C30: cpu->eip = LIFT_CODE_TOKEN_VA(0x424C30u);
    cpu->edx = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    label_00024C34: cpu->eip = LIFT_CODE_TOKEN_VA(0x424C34u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24C36u), LIFT_CODE_TOKEN_RVA(0x24C34u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424C36u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x24C39u), LIFT_CODE_TOKEN_RVA(0x24C37u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424C39u);
    cpu->eax = lift_load32(cpu->ebx + 0x388u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x2C0u);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = (uint32_t)(cpu->ebx + 0x38Cu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x424C52u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424C57u);
    cpu->edx = lift_load32(cpu->ebx + 0x388u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1594u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->ebx + 0x454u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00024C75;
    cpu->eax = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    goto label_00024C79;
    label_00024C75: cpu->eip = LIFT_CODE_TOKEN_VA(0x424C75u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    label_00024C79: cpu->eip = LIFT_CODE_TOKEN_VA(0x424C79u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x24C7Bu), LIFT_CODE_TOKEN_RVA(0x24C79u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424C7Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x454u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00024D60;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    label_00024C94: cpu->eip = LIFT_CODE_TOKEN_VA(0x424C94u);
    cpu->esi = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24C9Du), LIFT_CODE_TOKEN_RVA(0x24C9Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424C9Du);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x1594u)), r=(uint64_t)(1u), v=l ^ r; lift_flags_logic(cpu,v,32u); lift_store32(cpu->ebx + 0x1594u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00024CAC;
    cpu->edx = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edx);
    goto label_00024CB0;
    label_00024CAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x424CACu);
    cpu->eax = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    label_00024CB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x424CB0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x24CB2u), LIFT_CODE_TOKEN_RVA(0x24CB0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424CB2u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x24CB5u), LIFT_CODE_TOKEN_RVA(0x24CB3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424CB5u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00024CD0;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424CCEu); lift_push32(cpu, r); sfera_sub_00423E70(cpu,r); if (cpu->eip != r) return; }
    goto label_00024CE9;
    label_00024CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x424CD0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_00024CDF;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424CDDu); lift_push32(cpu, r); sfera_sub_00424790(cpu,r); if (cpu->eip != r) return; }
    goto label_00024CE9;
    label_00024CDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x424CDFu);
    cpu->ecx = (uint32_t)(uintptr_t)"dyn_grass_loop: wrong mp->dg_type";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x24CE9u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00024CE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x424CE9u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D0u)) != (uint32_t)(0u)) goto label_00024D0E;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x424CFFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424D05u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    label_00024D0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x424D0Eu);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->ecx = lift_load32(cpu->ebx + 0x2B4u);
    cpu->edx = lift_load32(cpu->esi + 0x1D0u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x424D29u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424D2Eu);
    cpu->esp += 0xCu;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1594u)) != (uint32_t)(0u)) goto label_00024D40;
    cpu->eax = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    goto label_00024D44;
    label_00024D40: cpu->eip = LIFT_CODE_TOKEN_VA(0x424D40u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    label_00024D44: cpu->eip = LIFT_CODE_TOKEN_VA(0x424D44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x24D46u), LIFT_CODE_TOKEN_RVA(0x24D44u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424D46u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(4u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x454u))) goto label_00024C94;
    label_00024D60: cpu->eip = LIFT_CODE_TOKEN_VA(0x424D60u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00424D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x424D70u);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    lift_push32(cpu, 0x33Au);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424D93u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x424DA3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424DA8u);
    cpu->ecx = lift_load32(cpu->ebx + 0x28u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x33Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424DBDu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x30u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00024F69;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    label_00024DD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x424DD4u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->eax += lift_load32(cpu->ebx + 0x34u);
    cpu->ecx = lift_load16(cpu->eax + 4u);
    cpu->edx = lift_load16(cpu->eax + 6u);
    cpu->esi = lift_load16(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->ebx + 0x28u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x424DFAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424DFFu);
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) <= (int32_t)(uint32_t)(0u)) goto label_00024F52;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = 1u;
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    label_00024E37: cpu->eip = LIFT_CODE_TOKEN_VA(0x424E37u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0u)) goto label_00024F3C;
    lift_store8(cpu->ecx, 1u);
    cpu->edx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = lift_load16(cpu->edx + cpu->eax);
    cpu->edx += cpu->esi;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u), cpu->edi);
    cpu->edx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = lift_load16(cpu->edx + cpu->eax + 2u);
    cpu->edx += cpu->esi;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u), cpu->edi);
    cpu->edx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = lift_load16(cpu->edx + cpu->eax + 4u);
    cpu->edx += cpu->esi;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u), cpu->edi);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->edx += cpu->ecx;
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    label_00024E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x424E80u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00024F37;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->eax += cpu->ecx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    label_00024EA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x424EA3u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->edx)) != (uint8_t)(0u)) goto label_00024F1A;
    cpu->edx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx += cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load16(cpu->edx);
    cpu->edx += cpu->esi;
    if ((uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u))) == (uint32_t)(cpu->edi)) goto label_00024EE1;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load16(cpu->edx + 2u);
    cpu->edx += cpu->esi;
    if ((uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u))) == (uint32_t)(cpu->edi)) goto label_00024EE1;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load16(cpu->edx + 4u);
    cpu->edx += cpu->esi;
    if ((uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u))) != (uint32_t)(cpu->edi)) goto label_00024F1A;
    label_00024EE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x424EE1u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->ecx + cpu->edx, 1u);
    cpu->edx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = lift_load16(cpu->edx + cpu->eax);
    cpu->edx += cpu->esi;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u), cpu->edi);
    cpu->edx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = lift_load16(cpu->edx + cpu->eax + 2u);
    cpu->edx += cpu->esi;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u), cpu->edi);
    cpu->edx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = lift_load16(cpu->edx + cpu->eax + 4u);
    cpu->edx += cpu->esi;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u), cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, 1u);
    label_00024F1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x424F1Au);
    ++cpu->ecx;
    cpu->eax += 0xCu;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00024EA3;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00024E80;
    label_00024F37: cpu->eip = LIFT_CODE_TOKEN_VA(0x424F37u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    ++cpu->edi;
    label_00024F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x424F3Cu);
    cpu->eax += 0xCu;
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x30u, v); }
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00024E37;
    label_00024F52: cpu->eip = LIFT_CODE_TOKEN_VA(0x424F52u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x12u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x30u))) goto label_00024DD4;
    label_00024F69: cpu->eip = LIFT_CODE_TOKEN_VA(0x424F69u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0x363u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424F7Cu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x366u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x424F95u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->ebx + 0x1C8u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x424F9Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x424FA3u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00025275;
    cpu->esi = 0u;
    cpu->edi += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    (void)cpu;
    label_00024FC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x424FC0u);
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00024FE6;
    cpu->ecx = 0xFFFFu;
    lift_store16(cpu->edi + 0xFFFFFFFCu, cpu->ecx & 0xFFFFu);
    goto label_00025259;
    label_00024FE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x424FE6u);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00025002;
    cpu->edx = 0x374u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x25002u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_00025002: cpu->eip = LIFT_CODE_TOKEN_VA(0x425002u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x10u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000250EC;
    cpu->edi = 0u;
    label_00025020: cpu->eip = LIFT_CODE_TOKEN_VA(0x425020u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u)))) goto label_000250CC;
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000250CC;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) != (uint32_t)(cpu->ecx)) goto label_00025063;
    cpu->edx = 0x37Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42505Fu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    label_00025063: cpu->eip = LIFT_CODE_TOKEN_VA(0x425063u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->edi))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->edi + 8u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
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
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000250C0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000250CA;
    label_000250C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4250C0u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000250CC;
    label_000250CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4250CAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000250CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4250CCu);
    ++cpu->ecx;
    cpu->edi += 0x24u;
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u))) goto label_00025020;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) != (uint32_t)(0xFFFFFFFFu)) goto label_000251CB;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_000250EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4250ECu);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000251BA;
    cpu->edi = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00025100: cpu->eip = LIFT_CODE_TOKEN_VA(0x425100u);
    cpu->edx = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002519E;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) != (uint32_t)(cpu->ecx)) goto label_00025135;
    cpu->edx = 0x38Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425131u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    label_00025135: cpu->eip = LIFT_CODE_TOKEN_VA(0x425135u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->edi))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->edi + 8u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00025192;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002519C;
    label_00025192: cpu->eip = LIFT_CODE_TOKEN_VA(0x425192u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_0002519E;
    label_0002519C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42519Cu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002519E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42519Eu);
    ++cpu->ecx;
    cpu->edi += 0x24u;
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u))) goto label_00025100;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) != (uint32_t)(0xFFFFFFFFu)) goto label_000251CB;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_000251BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4251BAu);
    cpu->edx = 0x396u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4251C9u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    goto label_000251CF;
    label_000251CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4251CBu);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_000251CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4251CFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4251D8u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi + 4u));
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)0.7070000171661377f));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00025224;
    cpu->eax = 0xFFFEu;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store16(cpu->edi + 0xFFFFFFFCu, cpu->eax & 0xFFFFu);
    goto label_0002522B;
    label_00025224: cpu->eip = LIFT_CODE_TOKEN_VA(0x425224u);
    lift_store_f32(cpu->edi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store16(cpu->edi + 0xFFFFFFFCu, cpu->ecx & 0xFFFFu);
    label_0002522B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42522Bu);
    cpu->ecx = 0u;
    lift_store16(cpu->edi, cpu->ecx & 0xFFFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x40u)) == (uint32_t)(cpu->ecx)) goto label_0002524F;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x2Cu)) & 0xFFFFu);
    lift_store16(cpu->edi + 0xFFFFFFFEu, cpu->edx & 0xFFFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(cpu->ecx)) goto label_00025259;
    cpu->eax = 1u;
    lift_store16(cpu->edi, cpu->eax & 0xFFFFu);
    goto label_00025259;
    label_0002524F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42524Fu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x42524Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425255u);
    lift_store16(cpu->edi + 0xFFFFFFFEu, cpu->eax & 0xFFFFu);
    label_00025259: cpu->eip = LIFT_CODE_TOKEN_VA(0x425259u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->edi += 0xCu;
    cpu->esi += 0x24u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x20u))) goto label_00024FC0;
    label_00025275: cpu->eip = LIFT_CODE_TOKEN_VA(0x425275u);
    lift_push32(cpu, 0x3A9u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425286u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425290u);
    cpu->esp -= 0x10u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x3B5u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4252BBu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ebx = lift_load32(cpu->esi + 0x20u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esi + 0x1C8u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00025305;
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    cpu->edx = cpu->ebx;
    label_000252D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4252D5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000252FD;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000252FF;
    label_000252FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4252FDu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000252FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4252FFu);
    cpu->ecx += 0x24u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000252D5;
    label_00025305: cpu->eip = LIFT_CODE_TOKEN_VA(0x425305u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42530Eu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x194u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 7.0);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00025343;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.4000000059604645));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00025343: cpu->eip = LIFT_CODE_TOKEN_VA(0x425343u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000253DE;
    cpu->ebx = 0u;
    (void)cpu;
    label_00025350: cpu->eip = LIFT_CODE_TOKEN_VA(0x425350u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ebx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ebx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002537D;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    goto label_00025392;
    label_0002537D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42537Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425382u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    label_00025392: cpu->eip = LIFT_CODE_TOKEN_VA(0x425392u);
    lift_store_f32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->ecx + 4u));
    cpu->eax = (uint32_t)(cpu->ebx + cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax))));
    ++cpu->edi;
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->ebx += 0x24u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x1Cu)) & 0xFFFFu);
    lift_store16(cpu->ebp + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFFCu, cpu->edx & 0xFFFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x20u))) goto label_00025350;
    label_000253DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4253DEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004253F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4253F0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1598u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4253FCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425401u);
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42540Bu); lift_push32(cpu, r); sfera_sub_00422CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = native_function_address32(&::InitializeCriticalSection);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 0x78u, cpu->eax);
    lift_store32(cpu->esi + 0x190u, cpu->eax);
    lift_store32(cpu->esi + 0xB0u, cpu->eax);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    lift_store32(cpu->esi + 0xE8u, cpu->eax);
    lift_store32(cpu->esi + 0x200u, cpu->eax);
    lift_store32(cpu->esi + 0x120u, cpu->eax);
    lift_store32(cpu->esi + 0x238u, cpu->eax);
    lift_store32(cpu->esi + 0x158u, cpu->eax);
    lift_store32(cpu->esi + 0x270u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 0x64u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x68u, cpu->ecx);
    lift_store32(cpu->esi + 0x6Cu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2546Eu), LIFT_CODE_TOKEN_RVA(0x2546Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42546Eu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x25474u), LIFT_CODE_TOKEN_RVA(0x25472u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425474u);
    cpu->edx = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2547Au), LIFT_CODE_TOKEN_RVA(0x25478u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42547Au);
    cpu->eax = (uint32_t)(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x25480u), LIFT_CODE_TOKEN_RVA(0x2547Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425480u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425570u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetExitCodeThread);
    cpu->esi = cpu->ecx;
    label_00025580: cpu->eip = LIFT_CODE_TOKEN_VA(0x425580u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000255BE;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2558Eu), LIFT_CODE_TOKEN_RVA(0x2558Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42558Eu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000255A1;
    cpu->edx = 0x21Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x255A1u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_000255A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4255A1u);
    if ((uint32_t)(lift_load32(cpu->esp + 8u)) == (uint32_t)(0x103u)) goto label_00025580;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000255BE;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x4255B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4255B8u);
    lift_store32(cpu->esi, 0u);
    label_000255BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4255BEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004255D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000255D0;
    label_00025490: cpu->eip = LIFT_CODE_TOKEN_VA(0x425490u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000254C9;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x4254A2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4254A8u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000254BB;
    cpu->edx = 0x21Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x254BBu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_000254BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4254BBu);
    if ((uint32_t)(lift_load32(cpu->esp + 4u)) == (uint32_t)(0x103u)) goto label_00025562;
    label_000254C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4254C9u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4254CFu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_dyn_green_runtime.low), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edi = cpu->edx;
    cpu->edi = (uint64_t)(cpu->edi) - (uint64_t)(g_sfera_dyn_green_runtime.high) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 8u)))));
    g_sfera_dyn_green_runtime.low = (uint32_t)(cpu->eax);
    g_sfera_dyn_green_runtime.high = (uint32_t)(cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (2000.0));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)2.0f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00025520;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    goto label_00025522;
    label_00025520: cpu->eip = LIFT_CODE_TOKEN_VA(0x425520u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00025522: cpu->eip = LIFT_CODE_TOKEN_VA(0x425522u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x70u))));
    cpu->edx = (uint32_t)(cpu->esi + 0x2A8u);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42553Cu); lift_push32(cpu, r); sfera_sub_004243C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00025549;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x25543u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x25549u);
    label_00025549: cpu->eip = LIFT_CODE_TOKEN_VA(0x425549u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00424AD0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x42555Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425560u);
    lift_store32(cpu->esi, cpu->eax);
    label_00025562: cpu->eip = LIFT_CODE_TOKEN_VA(0x425562u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_000255D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4255D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::LeaveCriticalSection);
    cpu->eax = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x255E0u), LIFT_CODE_TOKEN_RVA(0x255DEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4255E0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x255E6u), LIFT_CODE_TOKEN_RVA(0x255E4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4255E6u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_00025490;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004255F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4255F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x1C4u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->edx;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00025637;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ground_y"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42562Cu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00025637;
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00025637: cpu->eip = LIFT_CODE_TOKEN_VA(0x425637u);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x1C4u)) != (uint32_t)(cpu->ebx)) goto label_00025652;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0u;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x25652u); lift_push32(cpu, r); sfera_sub_00424D70(cpu,r); if (cpu->eip != r) return; }
    label_00025652: cpu->eip = LIFT_CODE_TOKEN_VA(0x425652u);
    cpu->edx = 1u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x1C4u)) != (uint32_t)(cpu->edx)) goto label_0002566E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2566Eu); lift_push32(cpu, r); sfera_sub_00424D70(cpu,r); if (cpu->eip != r) return; }
    label_0002566E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42566Eu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1C4u)) != (uint32_t)(2u)) goto label_00025870;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0u;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42568Cu); lift_push32(cpu, r); sfera_sub_00424D70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x30Eu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DynGreen.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4256A5u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->edi + 0x1CCu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x1C8u);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x20u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00025870;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->edi = cpu->edi;
    label_000256E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4256E0u);
    cpu->eax = lift_load32(cpu->edi + 0x24u);
    lift_x87_push(cpu, (double)-0.15000000596046448f);
    cpu->esi = lift_load32(cpu->edi + 0x1CCu);
    cpu->ecx = lift_load32(cpu->eax + cpu->ebx);
    cpu->esi += cpu->ebx;
    lift_store32(cpu->esi + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + cpu->ebx + 8u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load16(cpu->ecx);
    cpu->edx = 0xFDE8u;
    if ((uint16_t)((cpu->ecx & 0xFFFFu)) >= (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00025852;
    cpu->eax = lift_load32(cpu->edi + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->eax + 4u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 4u))));
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425768u); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4257A8u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x20u)) / (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4257E6u); lift_push32(cpu, r); sfera_sub_0044C1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425828u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x20u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00025852: cpu->eip = LIFT_CODE_TOKEN_VA(0x425852u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->ebx += 0x24u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x20u))) goto label_000256E0;
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    label_00025870: cpu->eip = LIFT_CODE_TOKEN_VA(0x425870u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1C4u)) != (uint32_t)(3u)) goto label_000258DC;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"deadRadius"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42588Du); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_0002589E;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"Parameter deadRadius not found for model ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2589Eu); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0002589E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42589Eu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"phaseMul"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4258B2u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000258C3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"Parameter phaseMul not found for model ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x258C3u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_000258C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4258C3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->edi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x258DCu); lift_push32(cpu, r); sfera_sub_00425290(cpu,r); if (cpu->eip != r) return; }
    label_000258DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4258DCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004258F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4258F0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4258F9u); lift_push32(cpu, r); sfera_sub_00425570(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = native_function_address32(&::DeleteCriticalSection);
    cpu->eax = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x25905u), LIFT_CODE_TOKEN_RVA(0x25903u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425905u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2590Bu), LIFT_CODE_TOKEN_RVA(0x25909u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42590Bu);
    cpu->edx = (uint32_t)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x25911u), LIFT_CODE_TOKEN_RVA(0x2590Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425911u);
    cpu->eax = (uint32_t)(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x25917u), LIFT_CODE_TOKEN_RVA(0x25915u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425917u);
    cpu->eax = lift_load32(cpu->esi + 0x2B4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00025935;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x425922u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425928u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x2B4u, 0u);
    label_00025935: cpu->eip = LIFT_CODE_TOKEN_VA(0x425935u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425940u);
    sfera_sub_00496F00(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425950u);
    cpu->esp -= 0x144u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x42596Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425972u);
    cpu->esi = cpu->eax;
    cpu->edi = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00025997;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::FindNextFileA);
    label_00025982: cpu->eip = LIFT_CODE_TOKEN_VA(0x425982u);
    if ((uint8_t)((lift_load8(cpu->esp + 0xCu)) & (0x10u)) != 0u) goto label_0002598A;
    ++cpu->edi;
    label_0002598A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42598Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x25992u), LIFT_CODE_TOKEN_RVA(0x25990u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425992u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00025982;
    cpu->ebp = lift_pop32(cpu);
    label_00025997: cpu->eip = LIFT_CODE_TOKEN_VA(0x425997u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x425998u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42599Eu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x144u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004259C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4259C0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->edx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->edx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_store_f32(cpu->edx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->edx + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->edx + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_store_f32(cpu->edx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->edx + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->edx + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_store_f32(cpu->edx + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store_f32(cpu->edx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->edx + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->edx + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store_f32(cpu->edx + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->edx + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->edx + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store_f32(cpu->edx + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->edx + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_store_f32(cpu->edx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store_f32(cpu->edx + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425A50u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.particle_resource_head;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00025A8E;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00025A8E;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00025A70: cpu->eip = LIFT_CODE_TOKEN_VA(0x425A70u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x25A74u), LIFT_CODE_TOKEN_RVA(0x25A72u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425A74u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00025A88;
    cpu->esi = lift_load32(cpu->esi + 0x54u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00025A70;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00025A88: cpu->eip = LIFT_CODE_TOKEN_VA(0x425A88u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00025A8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x425A8Eu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425AA0u);
    if ((uint32_t)(g_sfera_effect_manager.particle_random_table) != (uint32_t)(0u)) goto label_00025ACA;
    cpu->edx = 0x174u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425AB8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20000u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425AC2u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_effect_manager.particle_random_table = (uint32_t)(cpu->eax);
    label_00025ACA: cpu->eip = LIFT_CODE_TOKEN_VA(0x425ACAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::timeGetTime), LIFT_CODE_TOKEN_VA(0x425ACEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425AD4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x425AD5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425ADBu);
    cpu->edi = g_sfera_effect_manager.particle_random_table;
    cpu->ebx = native_function_address32(&::rand);
    cpu->esp += 4u;
    cpu->ebp = 0x100u;
    (void)cpu;
    label_00025AF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x425AF0u);
    cpu->esi = 0u;
    label_00025AF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x425AF2u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x25AF4u), LIFT_CODE_TOKEN_RVA(0x25AF2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425AF4u);
    lift_store16(cpu->edi + ((uint32_t)(cpu->esi) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x100u)) goto label_00025AF2;
    cpu->edi += 0x200u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00025AF0;
    lift_native_call(cpu, native_function_address32(&::timeGetTime), LIFT_CODE_TOKEN_VA(0x425B0Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425B10u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x425B11u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x425B17u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425B20u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.x;
    cpu->edi = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425B3Eu); lift_push32(cpu, r); sfera_sub_00455FD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_00025B58;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    goto label_00025B63;
    label_00025B58: cpu->eip = LIFT_CODE_TOKEN_VA(0x425B58u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x25B63u); lift_push32(cpu, r); sfera_sub_00455E40(cpu,r); if (cpu->eip != r) return; }
    label_00025B63: cpu->eip = LIFT_CODE_TOKEN_VA(0x425B63u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x20u))));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425BB6u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425BD0u);
    cpu->eax = g_sfera_effect_manager.effect_definition_head;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00025BEC;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00025BE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x425BE0u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_00025BEE;
    cpu->eax = lift_load32(cpu->eax + 0x20u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00025BE0;
    label_00025BEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x425BECu);
    cpu->eax = 0u;
    label_00025BEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x425BEEu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425BF0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(1u)) goto label_00025BF8;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_00025BF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x425BF8u);
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425C00u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00025C14;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 0x38u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
    label_00025C14: cpu->eip = LIFT_CODE_TOKEN_VA(0x425C14u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 0x30u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x34u, cpu->edx);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 0x38u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425C30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00025CB0;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_00025CB0;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00025CB0;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_00025C60;
    lift_store32(cpu->ecx, cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00025C60: cpu->eip = LIFT_CODE_TOKEN_VA(0x425C60u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edx)) goto label_00025C7A;
    cpu->edx = lift_load32(cpu->edx + 0x30u);
    lift_store32(cpu->ecx, cpu->edx);
    lift_store32(cpu->edx + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00025C7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x425C7Au);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_00025C95;
    cpu->eax = lift_load32(cpu->eax + 0x34u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00025C95: cpu->eip = LIFT_CODE_TOKEN_VA(0x425C95u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->eax + 0x34u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    lift_store32(cpu->edx + 0x30u, cpu->eax);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    label_00025CB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x425CB0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425CC0u);
    cpu->eax = g_sfera_effect_manager.render_index_buffer;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425CD0u);
    cpu->eax = g_sfera_effect_manager.render_sort_indices;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425CE0u);
    cpu->eax = g_sfera_effect_manager.render_batch_buffer;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425CF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425CF8u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 0x10Cu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00025D08;
    label_00025D02: cpu->eip = LIFT_CODE_TOKEN_VA(0x425D02u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00025D08: cpu->eip = LIFT_CODE_TOKEN_VA(0x425D08u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) == (uint32_t)(0u)) goto label_00025D02;
    cpu->eax = lift_load32(cpu->eax + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    reinterpret_cast<IEffectManager*>(static_cast<uintptr_t>(cpu->eax))->setParameter(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425D20u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425D30u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_definition_head;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x20u);
    cpu->ebx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00025D69;
    cpu->ebp = native_function_address32(&::_stricmp);
    label_00025D50: cpu->eip = LIFT_CODE_TOKEN_VA(0x425D50u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x25D57u), LIFT_CODE_TOKEN_RVA(0x25D55u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425D57u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00025D71;
    cpu->esi = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00025D50;
    label_00025D69: cpu->eip = LIFT_CODE_TOKEN_VA(0x425D69u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00025D71: cpu->eip = LIFT_CODE_TOKEN_VA(0x425D71u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425D80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_definition_head;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00025DB9;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00025D90: cpu->eip = LIFT_CODE_TOKEN_VA(0x425D90u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 0x20u);
    cpu->edx = 0x596u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425DA4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425DAFu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00025D90;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->esi);
    label_00025DB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x425DB9u);
    cpu->esi = g_sfera_effect_manager.particle_resource_head;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00025DF1;
    label_00025DC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x425DC3u);
    cpu->edi = lift_load32(cpu->esi + 0x54u);
    cpu->edx = 0x5A1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425DD5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425DDCu); lift_push32(cpu, r); sfera_sub_004834C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425DE2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00025DC3;
    g_sfera_effect_manager.particle_resource_head = (uint32_t)(cpu->edi);
    label_00025DF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x425DF1u);
    { uint64_t l=(uint64_t)(g_sfera_effect_manager.particle_random_table), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00025E23;
    cpu->edx = 0x5A9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425E0Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_effect_manager.particle_random_table;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425E16u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_effect_manager.particle_random_table = (uint32_t)(0u);
    label_00025E23: cpu->eip = LIFT_CODE_TOKEN_VA(0x425E23u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425E30u);
    lift_x87_push(cpu, (double)-1.0f);
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->eax));
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax + 0x20u, cpu->ecx);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    lift_store32(cpu->eax + 0x28u, cpu->ecx);
    lift_store32(cpu->eax + 0x38u, cpu->ecx);
    lift_store8(cpu->eax + 0x54u, cpu->ecx & 0xFFu);
    lift_store32(cpu->eax + 0x58u, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425E70u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00025EA0;
    if ((uint8_t)(lift_load8(cpu->esi + 0xCu)) != (uint8_t)(0u)) goto label_00025EA0;
    cpu->edx = 0x67Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425E94u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425E9Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00025EA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x425EA0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425EB0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00025F0C;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00025EC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x425EC5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00025EC5;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00025F0C;
    cpu->edx = 0x68Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425EDFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00025EE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x425EE4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00025EE4;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425EF4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    cpu->edi = cpu->edi;
    label_00025F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x425F00u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00025F00;
    goto label_00025F13;
    label_00025F0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x425F0Cu);
    lift_store32(cpu->edi + 4u, 0u);
    label_00025F13: cpu->eip = LIFT_CODE_TOKEN_VA(0x425F13u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00025F2F;
    cpu->edx = 0x690u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425F26u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425F2Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00025F2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x425F2Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425F40u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425F60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x6BEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x425F72u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_00025F81;

    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IEffectManager*>(cpu->esi)->destroyEffect(cpu);
    label_00025F81: cpu->eip = LIFT_CODE_TOKEN_VA(0x425F81u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425F90u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00425FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x425FA0u);
    cpu->eax = cpu->ecx;
    lift_x87_push(cpu, (double)-1.0f);
    cpu->ecx = 0u;
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u));
    cpu->edx |= 0xFFFFFFFFu;
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax + 0x20u, cpu->ecx);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    lift_store32(cpu->eax + 0x38u, cpu->ecx);
    lift_store8(cpu->eax + 0x54u, cpu->ecx & 0xFFu);
    lift_store32(cpu->eax + 0x58u, cpu->ecx);
    std::construct_at(reinterpret_cast<CScriptedEffect*>(cpu->eax));
    lift_store32(cpu->eax + 0x9Cu, cpu->ecx);
    lift_store32(cpu->eax + 0xA0u, cpu->ecx);
    lift_store32(cpu->eax + 0xB0u, cpu->ecx);
    lift_store32(cpu->eax + 0x28u, 1u);
    lift_store32(cpu->eax + 0xF8u, cpu->ecx);
    lift_store32(cpu->eax + 0xF4u, cpu->ecx);
    lift_store32(cpu->eax + 0xECu, cpu->ecx);
    lift_store32(cpu->eax + 0xE8u, cpu->ecx);
    lift_store32(cpu->eax + 0xF0u, cpu->ecx);
    lift_store32(cpu->eax + 0xBCu, cpu->ecx);
    lift_store32(cpu->eax + 0xB8u, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 0xB4u, cpu->ecx);
    lift_store32(cpu->eax + 0xA8u, cpu->ecx);
    lift_store32(cpu->eax + 0xACu, 1u);
    lift_store32(cpu->eax + 0xA4u, cpu->ecx);
    lift_store32(cpu->eax + 0xC4u, cpu->ecx);
    lift_store32(cpu->eax + 0xC0u, cpu->ecx);
    lift_store32(cpu->eax + 0xC8u, cpu->ecx);
    lift_store32(cpu->eax + 0xCCu, cpu->ecx);
    lift_store32(cpu->eax + 0xD0u, cpu->ecx);
    lift_store32(cpu->eax + 0xD4u, cpu->edx);
    lift_store32(cpu->eax + 0xD8u, cpu->ecx);
    lift_store32(cpu->eax + 0xDCu, cpu->edx);
    lift_store32(cpu->eax + 0xE0u, cpu->ecx);
    lift_store32(cpu->eax + 0xE4u, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426080u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026091;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00026091: cpu->eip = LIFT_CODE_TOKEN_VA(0x426091u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB8u)) <= (uint32_t)(cpu->ebx)) goto label_000260DB;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->edi = 0u;
    label_000260B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4260B0u);
    cpu->eax = lift_load32(cpu->esi + 0xE8u);
    cpu->eax = lift_load32(cpu->edi + cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000260CC;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x260C5u), LIFT_CODE_TOKEN_RVA(0x260C3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4260C5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000260E5;
    label_000260CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4260CCu);
    ++cpu->ebx;
    cpu->edi += 0x9Cu;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0xB8u))) goto label_000260B0;
    label_000260DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4260DBu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000260E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4260E5u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004260F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4260F0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026101;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00026101: cpu->eip = LIFT_CODE_TOKEN_VA(0x426101u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0xC4u)) <= (uint32_t)(cpu->ebx)) goto label_0002614B;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->edi = 0u;
    label_00026120: cpu->eip = LIFT_CODE_TOKEN_VA(0x426120u);
    cpu->eax = lift_load32(cpu->esi + 0xF0u);
    cpu->eax = lift_load32(cpu->edi + cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002613C;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x26135u), LIFT_CODE_TOKEN_RVA(0x26133u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426135u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00026155;
    label_0002613C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42613Cu);
    ++cpu->ebx;
    cpu->edi += 0x19Cu;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0xC4u))) goto label_00026120;
    label_0002614B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42614Bu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00026155: cpu->eip = LIFT_CODE_TOKEN_VA(0x426155u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426160u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 0xC4u))) goto label_00026171;
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_00026171: cpu->eip = LIFT_CODE_TOKEN_VA(0x426171u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x19Cu);
    cpu->eax += lift_load32(cpu->ecx + 0xF0u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426180u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 0xBCu))) goto label_00026191;
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_00026191: cpu->eip = LIFT_CODE_TOKEN_VA(0x426191u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->eax += lift_load32(cpu->ecx + 0xECu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004261A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4261A0u);
    cpu->eax = lift_load32(cpu->ecx + 0xB0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004261B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4261B0u);
    g_sfera_effect_manager.effects_enabled = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004261C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4261C0u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ebx = lift_load32(cpu->ebp + 0xA0u);
    lift_store8(cpu->ebp + 0xDu, 0u);
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->ebp + 0x10u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xD4u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->ebp + 0x14u, cpu->ecx);
    lift_store32(cpu->ebp + 0x20u, cpu->edi);
    lift_store32(cpu->ebp + 0x24u, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1Cu));
    lift_store_f32(cpu->ebp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x18u));
    lift_store32(cpu->ebp + 0x38u, cpu->edi);
    lift_store_f32(cpu->ebp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ebp + 0xFu, 0u);
    cpu->edx = lift_load32(cpu->ebx + 0xACu);
    lift_store32(cpu->ebp + 0xACu, cpu->edx);
    lift_store32(cpu->ebp + 0xA8u, cpu->edi);
    lift_store32(cpu->ebp + 0xE4u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00026277;
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x26227u), LIFT_CODE_TOKEN_RVA(0x26225u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426227u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000001u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00026233;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    label_00026233: cpu->eip = LIFT_CODE_TOKEN_VA(0x426233u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002623F;
    lift_store32(cpu->ebp + 0xE4u, 1u);
    label_0002623F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42623Fu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xE4u)) != (uint32_t)(cpu->edi)) goto label_0002625B;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xD8u)) <= (uint32_t)(cpu->edi)) goto label_0002626F;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x26251u), LIFT_CODE_TOKEN_RVA(0x2624Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426251u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->ebp + 0xD8u), 32u, 0u);
    goto label_00026271;
    label_0002625B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42625Bu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xE0u)) <= (uint32_t)(cpu->edi)) goto label_0002626F;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x26265u), LIFT_CODE_TOKEN_RVA(0x26263u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426265u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->ebp + 0xE0u), 32u, 0u);
    goto label_00026271;
    label_0002626F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42626Fu);
    cpu->edx = 0u;
    label_00026271: cpu->eip = LIFT_CODE_TOKEN_VA(0x426271u);
    lift_store32(cpu->ebp + 0xD0u, cpu->edx);
    label_00026277: cpu->eip = LIFT_CODE_TOKEN_VA(0x426277u);
    cpu->ecx = lift_load32(cpu->ebp + 0xB4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0002628D;
    cpu->eax = lift_load32(cpu->ebx + 0xB4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2628Du); lift_push32(cpu, r); sfera_sub_00496960(cpu,r); if (cpu->eip != r) return; }
    label_0002628D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42628Du);
    cpu->edx = 0u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xBCu)) <= (uint32_t)(cpu->edi)) goto label_000262D3;
    cpu->eax = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000262A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4262A0u);
    cpu->esi = lift_load32(cpu->ebx + 0xECu);
    cpu->edi = lift_load32(cpu->ebp + 0xECu);
    cpu->esi += cpu->eax;
    cpu->edi += cpu->eax;
    cpu->ecx = 0x19u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xECu);
    lift_store32(cpu->eax + cpu->ecx + 0x2Cu, 1u);
    ++cpu->edx;
    cpu->eax += 0x64u;
    if ((uint32_t)(cpu->edx) < (uint32_t)(lift_load32(cpu->ebp + 0xBCu))) goto label_000262A0;
    cpu->edi = 0u;
    label_000262D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4262D3u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xB8u)) <= (uint32_t)(cpu->edi)) goto label_00026307;
    cpu->esi = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000262E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4262E0u);
    cpu->edx = lift_load32(cpu->ebx + 0xE8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xE8u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4262F6u); lift_push32(cpu, r); sfera_sub_00483A80(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    cpu->esi += 0x9Cu;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->ebp + 0xB8u))) goto label_000262E0;
    cpu->edi = 0u;
    label_00026307: cpu->eip = LIFT_CODE_TOKEN_VA(0x426307u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xC4u)) <= (uint32_t)(0u)) goto label_00026337;
    cpu->esi = 0u;
    label_00026312: cpu->eip = LIFT_CODE_TOKEN_VA(0x426312u);
    cpu->eax = lift_load32(cpu->ebx + 0xF0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xF0u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426328u); lift_push32(cpu, r); sfera_sub_004844D0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    cpu->esi += 0x19Cu;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->ebp + 0xC4u))) goto label_00026312;
    label_00026337: cpu->eip = LIFT_CODE_TOKEN_VA(0x426337u);
    cpu->edx = 0u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xC8u)) <= (uint32_t)(cpu->edx)) goto label_0002642C;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xCCu)) <= (uint32_t)(cpu->edx)) goto label_0002642C;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xC4u)) <= (uint32_t)(cpu->edx)) goto label_0002642C;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    label_00026370: cpu->eip = LIFT_CODE_TOKEN_VA(0x426370u);
    cpu->edi = lift_load32(cpu->ebp + 0xF0u);
    cpu->ecx = lift_load32(cpu->ebx + 0xF0u);
    cpu->edi += cpu->edx;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->edx + cpu->ecx + 0x18Cu)) <= (uint32_t)(cpu->eax)) goto label_0002640D;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->edi + 0x18Cu)) <= (uint32_t)(cpu->eax)) goto label_0002640D;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000263A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4263A1u);
    cpu->ecx = lift_load32(cpu->ebx + 0xF0u);
    cpu->esi = lift_load32(cpu->edx + cpu->ecx + 0x188u);
    cpu->esi += lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000263F7;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x19Cu);
    cpu->eax += cpu->ecx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_000263F3;
    cpu->ebx = 0u;
    (void)cpu;
    label_000263D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4263D0u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4263DFu); lift_push32(cpu, r); sfera_sub_004844D0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    cpu->ebx += 0x19Cu;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000263D0;
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    label_000263F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4263F3u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_000263F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4263F7u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x14u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edi + 0x18Cu))) goto label_000263A1;
    label_0002640D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42640Du);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->eax;
    cpu->edx += 0x19Cu;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ebp + 0xC4u))) goto label_00026370;
    label_0002642C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42642Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426440u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xC8u)) == (uint32_t)(cpu->edi)) goto label_00026631;
    if ((uint32_t)(lift_load32(cpu->ecx + 0xCCu)) == (uint32_t)(cpu->edi)) goto label_00026631;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + 0xF8u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edi)) goto label_00026630;
    cpu->edx = lift_load32(cpu->ecx + 0xF4u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_00026630;
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xC4u)) <= (uint32_t)(cpu->edi)) goto label_00026630;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000264A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4264A0u);
    cpu->esi = lift_load32(cpu->ecx + 0xF0u);
    cpu->esi += lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esi + 0x18Cu);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->edi)) goto label_00026611;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_000264D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4264D0u);
    cpu->eax = lift_load32(cpu->esi + 0x188u);
    cpu->eax += lift_load32(cpu->esp + 0x18u);
    cpu->ebp = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_00026598;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x19Cu);
    cpu->ebp += lift_load32(cpu->ecx + 0xF0u);
    lift_store32(cpu->eax + 8u, cpu->ebx);
    lift_store32(cpu->eax + 0xCu, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 4u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00026598;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00026510: cpu->eip = LIFT_CODE_TOKEN_VA(0x426510u);
    cpu->ecx = 0x67u;
    cpu->esi = cpu->ebp;
    cpu->edi = cpu->ebx;
    lift_movs32(cpu, 1u);
    lift_store32(cpu->ebx + 0x198u, 1u);
    lift_store32(cpu->ebx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x5Cu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x426537u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42653Cu);
    cpu->esi = native_function_address32(&::rand);
    cpu->esp += 0xCu;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x26547u), LIFT_CODE_TOKEN_RVA(0x26545u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426547u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFFu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->ebx + 0xD8u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x26557u), LIFT_CODE_TOKEN_RVA(0x26555u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426557u);
    lift_store32(cpu->ebx + 0xDCu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2655Fu), LIFT_CODE_TOKEN_RVA(0x2655Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42655Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->ebx + 0xE0u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x5Cu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->ebx += 0x19Cu;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ecx + 4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00026510;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    cpu->edi = 0u;
    label_00026598: cpu->eip = LIFT_CODE_TOKEN_VA(0x426598u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x14u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x18Cu))) goto label_000264D0;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x5Cu)) <= (uint32_t)(cpu->edi)) goto label_00026611;
    cpu->ebp = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000265C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4265C0u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edi + cpu->ebp + 0x4Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000265FE;
    cpu->ecx = lift_load32(cpu->esi + 0x188u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    if ((uint32_t)(lift_load32(cpu->ecx + cpu->eax + 0x10u)) == (uint32_t)(0xFFFFFFFFu)) goto label_000265FA;
    cpu->ecx = lift_load32(cpu->ecx + cpu->eax + 8u);
    lift_store32(cpu->edi + cpu->ebp + 0x48u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x188u);
    lift_store32(cpu->ecx + cpu->eax + 8u, (uint64_t)(lift_load32(cpu->ecx + cpu->eax + 8u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u));
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 8u);
    label_000265FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4265FAu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_000265FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4265FEu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->ebp += 0x50u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x5Cu))) goto label_000265C0;
    cpu->edi = 0u;
    label_00026611: cpu->eip = LIFT_CODE_TOKEN_VA(0x426611u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 0xC4u))) goto label_000264A0;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00026630: cpu->eip = LIFT_CODE_TOKEN_VA(0x426630u);
    cpu->ebx = lift_pop32(cpu);
    label_00026631: cpu->eip = LIFT_CODE_TOKEN_VA(0x426631u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426640u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0xB4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002669D;
    if ((uint32_t)(lift_load32(cpu->esi + 0xA8u)) != (uint32_t)(0u)) goto label_0002668B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xACu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00026670;
    cpu->eax = 1u;
    goto label_00026672;
    label_00026670: cpu->eip = LIFT_CODE_TOKEN_VA(0x426670u);
    cpu->eax = 0u;
    label_00026672: cpu->eip = LIFT_CODE_TOKEN_VA(0x426672u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42667Du); lift_push32(cpu, r); sfera_sub_00496650(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xA8u, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0002668B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42668Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2669Du); lift_push32(cpu, r); sfera_sub_00496BD0(cpu,r); if (cpu->eip != r) return; }
    label_0002669D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42669Du);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004266B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4266B0u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xACu)) == (uint32_t)(0u)) goto label_000266C5;
    if ((uint32_t)(lift_load32(cpu->esp + 4u)) != (uint32_t)(0u)) goto label_000266C5;
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_000266C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4266C5u);
    cpu->eax = 1u;
    lift_return(cpu, 4u, stop_address); return;
}
